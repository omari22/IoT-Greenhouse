# Projet IoT - Greenhouse Monitoring

Ce projet utilise un capteur de température et d'humidité pour surveiller les conditions dans une serre. Les données sont transmises via LoRaWAN et affichées sur un dashboard.

## Installation

1. Télécharger le code Arduino et téléverser sur la carte.
2. Importer le flux Node-RED pour afficher les données.
3. Configurer les paramètres LoRaWAN (réseau et serveur).

## Dépendances

- Bibliothèque `SI7021` pour la lecture de température et d'humidité.
- Node-RED pour le traitement des données.

## Fonctionnalités

- Surveillance en temps réel de la température et de l'humidité.
- Transmission des données via LoRaWAN.
- Affichage des données sur un dashboard.

## Fonctionnalités futures

- Système d'alerte en cas de dépassement de seuil.
- Automatisation des actions (ventilation, irrigation).