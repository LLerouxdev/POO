#ifndef AFFICHAGE_H
#define AFFICHAGE_H

#include <SFML/Graphics.hpp>
#include "Grille.h"

class Affichage {
private:
    int tailleCellule;
    sf::RenderWindow fenetre;

public:
    Affichage(int largeur, int hauteur, int tailleCellule);
    void afficherGrille(const Grille& grille);
    bool estOuverte() const;
    void gererEvenements();
};

#endif
