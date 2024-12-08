#ifndef GRID_H
#define GRID_H

#include <vector>
#include "Cell.h"

class Grid {
private:
    int lignes;
    int colonnes;
    std::vector<std::vector<Cell>> grid;  // Tableau 2D représentant les cellules de la grille

    // Méthode pour compter le nombre de voisins vivants d'une cellule donnée
    int compterVoisinsVivants(int x, int y) const;

public:
    Grid();// Constructeur par défault

    Grid(int lignes, int colonnes);  // Constructeur : initialise la grille
    
    // Méthode pour valider si l'état de la grille respecte les règles du jeu
    bool validerGrille() const;

    // Set l'état d'une cellule à (x, y)
    void setEtatCellule(int x, int y, bool etat);
    
    // Get l'état d'une cellule (vivante ou morte)
    bool getEtatCellule(int x, int y) const;

    // Actualise l'état de la grille selon les règles du jeu
    void actualiser();
    
    // Affiche l'état actuel de la grille dans la console
    void afficher() const;

    // Retourne l'état complet de la grille
    std::vector<std::vector<Cell>> getEtat() const;

    // Get le nombre de lignes et de colonnes
    int getLignes() const;
    int getColonnes() const;
};

#endif
