import 'dart:async';
import 'Trackinformation.dart';
import 'package:flutter/material.dart';

class PlaylistScreen extends StatefulWidget {
  static List<dynamic> favorites = [];
  static final favoritesController = StreamController<List<dynamic>>.broadcast();

  static Stream<List<dynamic>> get favoritesStream => favoritesController.stream;

  static void addToFavorites(dynamic track) {
    if (!favorites.map((track) => track['id']).contains(track['id'])) {
      favorites.add(track);
    }
    favoritesController.sink.add(favorites);
  }

  static void removeFromFavorites(dynamic track) {
    if (favorites.map((track) => track['id']).contains(track['id'])) {
      favorites.remove(track);
    }
    favoritesController.sink.add(favorites);
  }

  static List<dynamic> listFavorites() {
    return favorites;
  }

  @override
  _PlaylistScreenState createState() => _PlaylistScreenState();
}

class _PlaylistScreenState extends State<PlaylistScreen> {
  @override
  Widget build(BuildContext context) {
    return Scaffold(
      appBar: AppBar(title: Text('Playlist Preferiti')),
      body:
          PlaylistScreen.favorites.isEmpty
              ? Center(child: Text('Nessuna canzone nei preferiti'))
              : ListView.builder(
                itemCount: PlaylistScreen.favorites.length,
                itemBuilder: (context, index) {
                  final track = PlaylistScreen.favorites[index];
                  return ListTile(
                    onTap: () {
                      Trackinformation.showTrackDetails(track, context);
                    },
                    leading: Image.network(
                      track['image'],
                      width: 50,
                      height: 50,
                      fit: BoxFit.cover,
                    ),
                    title: Text(track['name']),
                    subtitle: Text(track['artist_name']),
                  );
                },
              ),
    );
  }
}
