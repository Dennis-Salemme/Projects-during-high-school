import 'package:flutter/material.dart';
import 'dart:convert';
import 'package:http/http.dart' as http;
import 'Trackinformation.dart';

class SearchBarScreen extends StatefulWidget{
  final String searchname;
  const SearchBarScreen({Key? Key, required this.searchname}) : super(key: Key);

  @override
  SearchBarState createState() => SearchBarState();
}

class SearchBarState extends State<SearchBarScreen> {
  List<dynamic> _tracks = [];
  bool _isLoading = true;
  String _searchQuery = '';

  @override
  void initState() {
    super.initState();
    fetchsearchTracks(widget.searchname);
  }

  Future<void> fetchsearchTracks(final searchname) async {
    final clientId = '5cb56c18';
    final url =
        'https://api.jamendo.com/v3.0/tracks/?client_id=$clientId&namesearch=$searchname&format=json';
    try {
      final response = await http.get(Uri.parse(url));
      if (response.statusCode == 200) {
        final data = json.decode(response.body);
        setState(() {
          _tracks = data['results'];
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


  @override
  Widget build(BuildContext context) {
    return Scaffold(
      appBar: AppBar(title: Text('Search')),
      body: 
      Column(
        crossAxisAlignment: CrossAxisAlignment.start,
        children: [
          Padding(
            padding: const EdgeInsets.all(8.0),
            child: Text(
              'Results',
              style: TextStyle(fontSize: 18, fontWeight: FontWeight.bold),
            ),
          ),
          Expanded(
            child: ListView.builder(
              itemCount: _tracks.length,
              itemBuilder: (context, index) {
                final track = _tracks[index];
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
              }
            ),
          )
        ]
      ),
    );
  }
}