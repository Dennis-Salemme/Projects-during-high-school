import 'dart:math';
import 'package:flutter/material.dart';
import 'dart:convert';
import 'package:http/http.dart' as http;
import 'Trackinformation.dart';
import 'SearchBar.dart';

class HomeScreen extends StatefulWidget {
  @override
  _HomeScreenState createState() => _HomeScreenState();
}

class _HomeScreenState extends State<HomeScreen> {
  List<dynamic> _tracksindie = [];
  List<dynamic> _tracksclassical = [];
  List<dynamic> _tracksworld = [];
  List<dynamic> _trackssoundtrack = [];
  bool _isLoading = true;
  String _searchQuery = '';

  @override
  void initState() {
    super.initState();
    fetchIndieTracks();
    fetchclassicalTracks();
    fetchworldTracks();
    fetchsoundtrackTracks();
  }

  Future<void> fetchIndieTracks() async {
    final clientId = '5cb56c18';
    final url =
        'https://api.jamendo.com/v3.0/tracks/?client_id=$clientId&tags=indie&limit=20';
    try {
      final response = await http.get(Uri.parse(url));
      if (response.statusCode == 200) {
        final data = json.decode(response.body);
        setState(() {
          _tracksindie = data['results'];
          _isLoading = false;
        });
      }
    } catch (e) {
      print('Errore nel recupero delle tracce indie: $e');
      setState(() {
        _isLoading = false;
      });
    }
  }

  Future<void> fetchclassicalTracks() async {
    final clientId = '5cb56c18';
    final url =
        'https://api.jamendo.com/v3.0/tracks/?client_id=$clientId&tags=classical&limit=20';
    try {
      final response = await http.get(Uri.parse(url));
      if (response.statusCode == 200) {
        final data = json.decode(response.body);
        setState(() {
          _tracksclassical = data['results'];
          _isLoading = false;
        });
      }
    } catch (e) {
      print('Errore nel recupero delle tracce indie: $e');
      setState(() {
        _isLoading = false;
      });
    }
  }

  Future<void> fetchworldTracks() async {
    final clientId = '5cb56c18';
    final url =
        'https://api.jamendo.com/v3.0/tracks/?client_id=$clientId&tags=world&limit=20';
    try {
      final response = await http.get(Uri.parse(url));
      if (response.statusCode == 200) {
        final data = json.decode(response.body);
        setState(() {
          _tracksworld = data['results'];
          _isLoading = false;
        });
      }
    } catch (e) {
      print('Errore nel recupero delle tracce indie: $e');
      setState(() {
        _isLoading = false;
      });
    }
  }

  Future<void> fetchsoundtrackTracks() async {
    final clientId = '5cb56c18';
    final url =
        'https://api.jamendo.com/v3.0/tracks/?client_id=$clientId&tags=soundtrack&limit=20';
    try {
      final response = await http.get(Uri.parse(url));
      if (response.statusCode == 200) {
        final data = json.decode(response.body);
        setState(() {
          _trackssoundtrack = data['results'];
          _isLoading = false;
        });
      }
    } catch (e) {
      print('Errore nel recupero delle tracce indie: $e');
      setState(() {
        _isLoading = false;
      });
    }
  }

  Widget seetracksgenres(String nametext, List<dynamic> tracksgenres) {
    final ScrollController horizontal = ScrollController();
    return Column(
      children: [
        Padding(
          padding: const EdgeInsets.all(8.0),
          child: Text(
            nametext,
            style: TextStyle(fontSize: 18, fontWeight: FontWeight.bold),
          ),
        ),
        SingleChildScrollView(
          child: Scrollbar(
            controller: horizontal,
            thumbVisibility: true,
            trackVisibility: true,
            child: SingleChildScrollView(
              controller: horizontal,
              scrollDirection: Axis.horizontal,
              child: SizedBox(
                height: 165,
                child: ListView.builder(
                  scrollDirection: Axis.horizontal,
                  shrinkWrap: true,
                  itemCount: tracksgenres.length,
                  itemBuilder: (context, index) {
                    final track = tracksgenres[index];
                    return Padding(
                      padding: EdgeInsets.all(8.0),
                      child: Column(
                        children: [
                          GestureDetector(
                            onTap: () {
                              Trackinformation.showTrackDetails(track, context);
                            },
                            child: Image.network(
                              track['image'],
                              width: 100,
                              height: 100,
                              fit: BoxFit.cover,
                            ),
                          ),
                          SizedBox(height: 5),
                          Text(
                            track['name'],
                            style: TextStyle(
                              fontSize: 14,
                              fontWeight: FontWeight.bold,
                            ),
                          ),
                          Text(
                            track['artist_name'],
                            style: TextStyle(fontSize: 12),
                          ),
                        ],
                      ),
                    );
                  },
                ),
              ),
            ),
          ),
        ),
      ],
    );
  }

  final ScrollController vertical = ScrollController();

  @override
  Widget build(BuildContext context) {
    return Scaffold(
      appBar: AppBar(
        title: Text('Jamendo Music'),
        bottom: PreferredSize(
          preferredSize: Size.fromHeight(60.0),
          child: Padding(
            padding: const EdgeInsets.all(8.0),
            child: TextField(
              onSubmitted: (value) {
                Navigator.push(
                  context,
                  MaterialPageRoute(
                    builder: (context) => SearchBarScreen(searchname: value),
                  ),
                );
              },
              decoration: InputDecoration(
                hintText: 'Cerca canzoni...',
                border: OutlineInputBorder(
                  borderRadius: BorderRadius.circular(8.0),
                ),
                suffixIcon: Icon(Icons.search),
              ),
              onChanged: (value) {
                setState(() {
                  _searchQuery = value;
                });
              },
            ),
          ),
        ),
      ),
      body: Scrollbar(
        controller: vertical,
        thumbVisibility: true,
        trackVisibility: true,
        child: SingleChildScrollView(
          controller: vertical,
          scrollDirection: Axis.vertical,
          child: Column(
            crossAxisAlignment: CrossAxisAlignment.start,
            children: [
              Padding(
                padding: const EdgeInsets.all(8.0),
                child: Text(
                  'Generi',
                  style: TextStyle(fontSize: 18, fontWeight: FontWeight.bold),
                ),
              ),
              seetracksgenres('Indie Hits', _tracksindie),
              seetracksgenres('Classical Hits', _tracksclassical),
              seetracksgenres('World Hits', _tracksworld),
              seetracksgenres('Soundtrack', _trackssoundtrack),
            ],
          ),
        ),
      ),
    );
  }
}
