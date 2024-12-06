#ifndef AFFICHAGE_H
#define AFFICHAGE_H

#include <SFML/Graphics.hpp>
#include "Grid.h"

class Affichage {
private:
    int tailleCellule;  // Taille de chaque cellule à afficher (en pixels)
    sf::RenderWindow window;  // Fenêtre graphique pour afficher la grille

public:
    // Constructeur : initialise la fenêtre avec les dimensions de la grille et la taille des cellules
    Affichage(int largeur, int hauteur, int tailleCellule);

    // Affiche la grille dans la fenêtre graphique
    void afficherGrille(const Grid& grille);

    // Vérifie si la fenêtre est encore ouverte
    bool windowOpen() const;

    // Gère la fenêtre (fermeture, redimensionnement, etc.)
    void gererWindow();
};

#endif
