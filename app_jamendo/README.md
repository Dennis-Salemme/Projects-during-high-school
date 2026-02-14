# app_jamendo

A new Flutter project.

## Getting Started

This project is a starting point for a Flutter application.

A few resources to get you started if this is your first Flutter project:

- [Lab: Write your first Flutter app](https://docs.flutter.dev/get-started/codelab)
- [Cookbook: Useful Flutter samples](https://docs.flutter.dev/cookbook)

For help getting started with Flutter development, view the
[online documentation](https://docs.flutter.dev/), which offers tutorials,
samples, guidance on mobile development, and a full API reference.

Un'applicazione mobile sviluppata in Flutter che permette di cercare, ascoltare e gestire brani musicali utilizzando le API pubbliche di Jamendo.

Questo progetto è nato come esperimento pratico per approfondire la gestione delle chiamate HTTP asincrone, il parsing di dati JSON e la gestione degli stream audio su dispositivi mobili.

## Funzionalità Principali
Ricerca in Tempo Reale: Interrogazione dell'API di Jamendo per trovare brani per artista o titolo.
Player Audio: Funzionalità complete di Play, Pausa e Stop.
Controllo Velocità (Playback Rate): Possibilità di accelerare o rallentare la riproduzione (manipolazione del flusso audio).
Gestione Preferiti: Sistema per salvare localmente le tracce preferite.

## Tecnologie e Sfide Tecniche
Il focus del progetto non è stato solo la grafica, ma la logica backend-frontend:
Language: Dart (Flutter Framework).
Networking: Utilizzo del pacchetto http per gestire richieste GET asincrone verso l'endpoint di Jamendo.
Data Handling: Deserializzazione dei dati JSON complessi restituiti dall'API in modelli utilizzabili dall'app.
Audio Management: Implementazione di un controller audio per gestire lo stato della riproduzione (buffering, playing, paused) e la modifica dinamica della velocità.