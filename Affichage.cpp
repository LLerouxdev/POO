#include "Affichage.h"

// Constructeur : initialise la fenêtre d'affichage
Affichage::Affichage(int largeur, int hauteur, int tailleCellule) {
    this->tailleCellule = tailleCellule; // Initialise la taille de chaque cellule
    int windowLargeur = largeur * tailleCellule; // Calcule la largeur de la fenêtre
    int windowHauteur = hauteur * tailleCellule; // Calcule la hauteur de la fenêtre

    // Crée une fenêtre graphique avec les dimensions calculées
    window.create(sf::VideoMode(windowLargeur, windowHauteur), "Jeu de la Vie", sf::Style::Resize | sf::Style::Close);
    window.setVerticalSyncEnabled(false); // Désactive la synchronisation verticale
}

// Affiche la grille actuelle dans la fenêtre
void Affichage::afficherGrille(const Grid& grille){
    window.clear(); // Efface l'affichage précédent
    sf::RectangleShape cellule(sf::Vector2f(tailleCellule - 1.0f, tailleCellule - 1.0f)); // Définit la taille des cellules
    for (int x = 0; x < grille.getLignes(); ++x) {
        for (int y = 0; y < grille.getColonnes(); ++y) {
            if (grille.getEtatCellule(x, y)) { // Vérifie si la cellule est vivante
                cellule.setPosition(y * tailleCellule, x * tailleCellule); // Positionne la cellule
                window.draw(cellule); // Dessine la cellule dans la fenêtre
            }
        }
    }
    window.display(); // Actualise l'affichage

}

// Vérifie si la fenêtre est ouverte
bool Affichage::windowOpen() const {
    return window.isOpen(); // Retourne true si la fenêtre n'est pas fermée
}

// Gère les événements de la fenêtre (fermeture, redimensionnement, etc.)
void Affichage::gererWindow(){
    sf::Event event; // Variable pour stocker les événements
    while(window.pollEvent(event)){
        if(event.type == sf::Event::Closed){ // Vérifie si l'utilisateur a fermé la fenêtre
            window.close(); // Ferme la fenêtre
        }
    }
}
