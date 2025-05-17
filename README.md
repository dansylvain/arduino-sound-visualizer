# arduino-sound-visualizer
Real-time sound visualizer using Python and Arduino. Captures audio volume in Python and displays it on LEDs via Arduino.

<p align="center">
  <img src="img/arduino-sound-visualizer.jpg" width="70%"/>
</p>

### 🎧 Visualiser le son avec Arduino : un ruban de LEDs contrôlé par le volume
Et si le bruit ambiant devenait lumière ?
Ce vendredi, j’ai réalisé un atelier mêlant Python, électronique et un peu de magie lumineuse. L’idée ? Transformer le volume sonore capté par un micro en une visualisation temps réel à l’aide de LEDs contrôlées par un Arduino. Voici un retour structuré sur ce petit projet qui m’a fait toucher du doigt la puissance de la communication entre Python et un microcontrôleur.

### 🎯 Objectif : capter le volume sonore et l’afficher avec des LEDs
L’objectif de l’atelier était simple mais stimulant :

1. Utiliser un micro pour capter le son environnant.

2. Calculer son volume en temps réel à l’aide d’un script Python.

3. Transmettre cette donnée via USB à un Arduino.

4. Allumer un nombre de LEDs proportionnel au volume perçu.

J’ai aussi ajouté un bouton poussoir permettant de changer le comportement des LEDs à la volée, entre différents “modes” d’affichage.

### 🔧 Matériel et fonctionnement du montage
Matériel utilisé :

- Micro intégré au PC

- Résistance 10kΩ

- Bouton poussoir

- 6 LEDs

- Arduino Uno

- Breadboard + câbles Dupont

**Fonctionnement** :
Le micro capte le son ambiant. En Python, j’ai utilisé les bibliothèques sounddevice et numpy pour calculer en continu le volume sonore (RMS). Ce volume est ensuite envoyé à l’Arduino via la liaison série (USB), où il est converti en valeur analogique simulée.

Côté Arduino, le programme lit cette valeur et agit sur les LEDs selon le mode sélectionné. Voici les modes implémentés :

- **Mode 0** : LEDs éteintes

- **Mode 1** : bargraph selon le potentiomètre (test)

- **Mode 2** : clignotement de toutes les LEDs

- **Mode 3** : chenillard avant-arrière, vitesse contrôlée par potentiomètre

- **Mode 4** : bargraph dynamique basé sur le volume sonore envoyé par Python

Un simple appui sur le bouton change le mode.

### 🧠 Ce que j’ai appris
Cet atelier m’a permis de creuser plusieurs notions concrètes et transversales :

- Lire et traiter un signal audio en Python en temps réel

- Transmettre proprement des données via la liaison série

- Simuler une lecture analogique sur Arduino à partir de valeurs reçues

- Organiser un sketch en plusieurs comportements réactifs grâce à une machine à états

- Débugger des conflits de port série (minicom vs IDE Arduino)

J’ai aussi pris conscience de l’importance de bien séparer les responsabilités : Python se charge du traitement, Arduino de l'affichage.

### 🚀 Et ensuite ?
Plusieurs pistes m’attendent pour enrichir ce projet :

- Ajouter une interface graphique Python pour visualiser le son (matplotlib ou PyQt)

- Utiliser un véritable capteur de volume analogique, type module KY-038

- Faire évoluer les modes pour y intégrer des effets plus complexes ou musicaux

- Envoyer des commandes spécifiques depuis Python (changement de mode, animation déclenchée, etc.)

## ✍️ Conclusion
Ce projet est une belle porte d’entrée pour tous ceux qui veulent relier le monde logiciel (Python) à l’électronique physique (Arduino). En quelques heures, on obtient un système réactif, visuel et surtout... vivant. La suite ? Faire danser les LEDs sur la musique, bien sûr.
