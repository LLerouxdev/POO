#include "Affichage.h"

// Constructeur : fixe la taille de la fenêtre
Affichage::Affichage(int largeur, int hauteur, int tailleCellule)
    : tailleCellule(tailleCellule) {
    // Taille fixe de la fenêtre
    int windowWidth = largeur * tailleCellule;
    int windowHeight = hauteur * tailleCellule;

    // Créer la fenêtre avec des dimensions fixes et redimensionnable
    fenetre.create(sf::VideoMode(windowWidth, windowHeight), "Jeu de la Vie", sf::Style::Resize | sf::Style::Close);
}

// Affiche la grille dans la fenêtre graphique
void Affichage::afficherGrille(const Grille& grille) {
    fenetre.clear();
    sf::RectangleShape cellule(sf::Vector2f(tailleCellule - 1.0f, tailleCellule - 1.0f)); // Les cellules sont légèrement plus petites pour éviter les bordures

    for (int x = 0; x < grille.obtenirLignes(); ++x) {
        for (int y = 0; y < grille.obtenirColonnes(); ++y) {
            if (grille.obtenirEtatCellule(x, y)) {
                cellule.setPosition(y * tailleCellule, x * tailleCellule); // Positionner la cellule
                fenetre.draw(cellule);
            }
        }
    }

    fenetre.display(); // Mettre à jour l'affichage
}

// Vérifie si la fenêtre est encore ouverte
bool Affichage::estOuverte() const {
    return fenetre.isOpen();
}

// Gère les événements de la fenêtre (fermeture, redimensionnement, etc.)
void Affichage::gererEvenements() {
    sf::Event event;
    while (fenetre.pollEvent(event)) {
        if (event.type == sf::Event::Closed) {
            fenetre.close(); // Ferme la fenêtre si demandé
        }
    }
}
