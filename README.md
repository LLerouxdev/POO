# **Jeu de la Vie**

Ce projet implémente le célèbre Jeu de la Vie de John Conway, un automate cellulaire développé dans les années 1970. Il permet de simuler l'évolution d'une population de cellules sur une grille.  
Le projet suit une architecture MVC (Model-View-Controller) et propose deux modes d'interaction :
- **Mode console** : Simple et léger, adapté pour suivre les évolutions itératives.
- **Mode graphique** : Plus interactif et intuitif, basé sur la bibliothèque SFML.

---

## **Contexte du projet**

Le **Jeu de la Vie** est un automate cellulaire conçu par le mathématicien **John Horton Conway**. Il repose sur des règles simples, mais génère souvent des motifs étonnamment complexes, simulant des comportements tels que la stabilité, l'oscillation, ou même l'extinction de populations.

Ce projet a un objectif de comprendre la POO et l'utilisation des classes, en explorant plusieurs concepts :
- Programmation orientée objet en C++.
- Conception logicielle via une architecture MVC.
- Utilisation de bibliothèques graphiques externes.
- Implémentation et simulation d’automates cellulaires.

---

## **Fonctionnalités**

- **Mode Console** : Affichage des itérations dans le terminal et création d'un dossier contenant chaque itération préalablement définie par l'utilisateur.
- **Mode Graphique** : Visualisation avec la bibliothèque SFML et configuration de la durée entre chaque itération.
- **Chargement d’une grille initiale** depuis un fichier texte contenant la dimension (nombre de lignes, nombre de colonnes) ainsi que les états sur chaque cellule (morte (0) ou vivante (1)).



---

## **Architecture**

Le projet suit une architecture **MVC** pour une séparation claire des responsabilités :

1. **Modèle** (Grid, Cell)  
   Gère les données et applique les règles du jeu de la vie.
   
2. **Vue** (Affichage)  
   Responsabilité d'afficher graphiquement ou textuellement l'état du jeu.

3. **Contrôleur** (Jeu)  
   Orchestration entre le modèle et la vue pour maintenir la logique de l'application.

---

## **Règles du Jeu de la Vie**

- Une **cellule vivante** :
  - **Reste vivante** si elle a 2 ou 3 voisins vivants.
  - **Meurt** dans tous les autres cas (sous-population ou surpopulation).

- Une **cellule morte** :
  - **Devient vivante** si elle a exactement 3 voisins vivants.
  - **Reste morte** sinon.

---

## **Pré-requis**

### **Bibliothèques nécessaires**
- **SFML** (*Simple and Fast Multimedia Library*)  
  Pour l’installer sous Linux :  
  ```bash
  sudo apt-get install libsfml-dev
  ```
  ---
## **Compilation et exécution**

### **Bibliothèques nécessaires**
- Un fichier **Makefile** a été créé pour simplifier la compilation. Exécutez simplement avec la commande :  
  ```bash
  make
  ```
  ---
## **Fichiers du Projet**
- main.cpp : Point d'entrée du programme. 
- Jeu.cpp/.h : Classe principale du contrôleur.
- Grid.cpp/.h : Gestion de la grille et des cellules.
- Cell.cpp/.h : Gestion individuelle des cellules.
- Affichage.cpp/.h : Gestion de l'affichage graphique avec SFML. fichier_input.txt : Exemple de fichier d'entrée contenant une configuration de grille.


