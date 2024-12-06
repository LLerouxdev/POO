#include "Affichage.h"

Affichage::Affichage(int largeur, int hauteur, int tailleCellule) {
    this->tailleCellule = tailleCellule; // déclare la variable qui est égale au paramètre du constructeur
    int windowLargeur = largeur * tailleCellule;
    int windowHauteur = hauteur * tailleCellule;

    window.create(sf::VideoMode(windowLargeur, windowHauteur), "Jeu de la Vie", sf::Style::Resize | sf::Style::Close);
    window.setVerticalSyncEnabled(false);
}

void Affichage::afficherGrille(const Grid& grille){
    window.clear();
    sf::RectangleShape cellule(sf::Vector2f(tailleCellule - 1.0f, tailleCellule - 1.0f));
    for (int x = 0; x < grille.getLignes(); ++x) {
        for (int y = 0; y < grille.getColonnes(); ++y) {
            if (grille.getEtatCellule(x, y)) {
                cellule.setPosition(y * tailleCellule, x * tailleCellule);
                window.draw(cellule);
            }
        }
    }
    window.display();

}

bool Affichage::windowOpen() const {
    return window.isOpen();
}

void Affichage::gererWindow(){
    sf::Event event;
    while(window.pollEvent(event)){
        if(event.type == sf::Event::Closed){
            window.close();
        }
    }
}
