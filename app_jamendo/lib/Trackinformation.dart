import 'package:flutter/material.dart';
import 'PlaylistScreen.dart';
import 'package:just_audio/just_audio.dart';
import 'package:audio_video_progress_bar/audio_video_progress_bar.dart';

class Trackinformation {
  static final player = AudioPlayer();

  static Future<void> setupAudioPlayer(dynamic track) async {
    player.playbackEventStream.listen(
      (event) {},
      onError: (Object e, StackTrace stacktrace) {
        print("A stream error occured: $e");
      },
    );
    try {
      player.setAudioSource(AudioSource.uri(Uri.parse(track['audio'])));
    } catch (e) {
      print("Error loading audio source $e");
    }
  }

  static Widget playBackControlButton() {
    return StreamBuilder<PlayerState>(
      stream: player.playerStateStream,
      builder: (context, snapshot) {
        final processingState = snapshot.data?.processingState;
        final playing = snapshot.data?.playing;
        if (processingState == ProcessingState.loading ||
            processingState == ProcessingState.buffering) {
          return Container(
            margin: const EdgeInsets.all(8.0),
            width: 64,
            height: 64,
            child: const CircularProgressIndicator(),
          );
        } else if (playing != true) {
          return IconButton(
            icon: const Icon(Icons.play_arrow),
            iconSize: 64,
            onPressed: player.play,
          );
        } else if (processingState != ProcessingState.completed) {
          return IconButton(
            icon: const Icon(Icons.pause),
            iconSize: 64,
            onPressed: player.pause,
          );
        } else {
          return IconButton(
            icon: const Icon(Icons.replay),
            iconSize: 64,
            onPressed: () => player.seek(Duration.zero),
          );
        }
      },
    );
  }

  static Widget progressBar() {
    return StreamBuilder<Duration?>(
      stream: player.positionStream,
      builder: (context, snapshot) {
        return ProgressBar(
          progress: snapshot.data ?? Duration.zero,
          buffered: player.bufferedPosition,
          total: player.duration ?? Duration.zero,
          onSeek: (duration) {
            player.seek(duration);
          },
        );
      },
    );
  }

  static Widget controlButtons() {
    return Column(
      mainAxisSize: MainAxisSize.min,
      children: [
        StreamBuilder(
          stream: player.speedStream,
          builder: (context, snapshot) {
            return Row(
              children: [
                const Icon(Icons.speed),
                Slider(
                  min: 1,
                  max: 3,
                  value: snapshot.data ?? 1,
                  divisions: 3,
                  onChanged: (value) async {
                    await player.setSpeed(value);
                  },
                ),
              ],
            );
          },
        ),
        StreamBuilder(
          stream: player.volumeStream,
          builder: (context, snapshot) {
            return Row(
              children: [
                const Icon(Icons.volume_up),
                Slider(
                  min: 0,
                  max: 3,
                  value: snapshot.data ?? 1,
                  divisions: 4,
                  onChanged: (value) async {
                    await player.setVolume(value);
                  },
                ),
              ],
            );
          },
        ),
      ],
    );
  }

  static Widget controlfavorites(dynamic track) {
    return StreamBuilder<List<dynamic>>(
      stream: PlaylistScreen.favoritesStream,
      builder: (context, snapshot) {
        List<dynamic> list = PlaylistScreen.favorites;
        //final isFavorite = list.contains(track);
        final isFavorite = list.map((track) => track['id']).contains(track['id']);

        //isFavorite = snapshot.hasData && snapshot.data!.contains(track);
        return IconButton(
          icon: Icon(
            isFavorite ? Icons.favorite : Icons.favorite_border,
            color: isFavorite ? Colors.red : Colors.black,
          ),
          onPressed: () {
            isFavorite
                ? PlaylistScreen.removeFromFavorites(track)
                : PlaylistScreen.addToFavorites(track);
          },
        );
      },
    );
  }

  static void showTrackDetails(dynamic track, BuildContext context) {
    setupAudioPlayer(track);
    showModalBottomSheet(
      context: context,
      isScrollControlled: true,
      builder: (context) {
        return Container(
          height: MediaQuery.of(context).size.height * 0.5,
          padding: EdgeInsets.all(16),
          child: Column(
            crossAxisAlignment: CrossAxisAlignment.start,
            children: [
              Row(
                mainAxisAlignment: MainAxisAlignment.spaceBetween,
                children: [
                  Text(
                    track['name'],
                    style: TextStyle(fontSize: 20, fontWeight: FontWeight.bold),
                  ),
                  controlfavorites(track),
                ],
              ),
              Text(
                'Artista: ${track['artist_name']}',
                style: TextStyle(fontSize: 16),
              ),
              SizedBox(height: 10),
              Image.network(
                track['image'],
                width: 100,
                height: 100,
                fit: BoxFit.cover,
              ),
              SizedBox(height: 10),
              progressBar(),
              Row(children: [controlButtons(), playBackControlButton()]),
            ],
          ),
        );
      },
    );
  }
}
