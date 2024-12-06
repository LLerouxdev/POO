# Jeu de la Vie
Ce projet implémente le célèbre Jeu de la Vie de John Conway en utilisant une architecture MVC (Model-View-Controller) en C++. Le jeu est interactif et propose deux modes d'exécution : mode console et mode graphique.

# Fonctionnalités
Mode Console : Affichage des itérations du jeu dans le terminal.
Mode Graphique : Affichage interactif en utilisant la bibliothèque SFML.
Chargement de la grille initiale depuis un fichier texte.
Mise à jour des cellules selon les règles du jeu de la vie.
Gestion de la stabilité de la grille.
# Architecture
Le projet suit une architecture MVC :

Modèle (Grid, Cell) : Gère les données et les règles du jeu.
Vue (Affichage) : Affiche graphiquement ou textuellement l'état du jeu.
Contrôleur (Jeu) : Orchestration entre le modèle et la vue.
# Pré-requis
## Bibliothèques nécessaires
SFML (Simple and Fast Multimedia Library)
Pour installer SFML sous Linux :

```sudo apt-get install libsfml-dev```
# Compilation et exécution
## Compilation
Un fichier Makefile est inclus pour simplifier la compilation. Exécutez simplement :

```make```
## Lancer le jeu
Après compilation, utilisez :

./Jeu
Puis indiquez le chemin du fichier contenant l’état initial des cellules en paramètre : 
Exemple : fichier_input.txt
Après avoir indiqué le chemin du fichier,entrez le nombre d'itérations à effectuer : 
Exemple : 100
Pour finir choissisez le mode (Graphique, Console) : 
1) Mode Console
2) Mode Graphique

# Fichiers du projet
main.cpp : Point d'entrée du programme.
Jeu.cpp/.h : Classe principale du contrôleur.
Grid.cpp/.h : Gestion de la grille et des cellules.
Cell.cpp/.h : Gestion individuelle des cellules.
Affichage.cpp/.h : Gestion de l'affichage graphique avec SFML.
fichier_input.txt : Exemple de fichier d'entrée contenant une configuration de grille.
# Règles du Jeu de la Vie
Une cellule vivante avec 2 ou 3 voisins vivants reste vivante.
Une cellule morte avec exactement 3 voisins vivants devient vivante.
Dans tous les autres cas, la cellule meurt ou reste morte.
# Exemple de grille (fichier d'entrée)
Le fichier d'entrée commence par deux entiers indiquant le nombre de lignes et de colonnes, suivis par la grille elle-même (1 pour vivant, 0 pour mort).

5 5
0 1 0 0 0
1 1 1 0 0
0 0 1 0 0
0 0 0 0 0
0 0 0 0 0
Co
