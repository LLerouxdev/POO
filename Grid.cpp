#include "Grid.h"
#include <iostream>

// Constructeur par défaut : initialise une grille vide
Grid::Grid(){
    this->lignes = 0;
    this->colonnes = 0;
}
// Constructeur paramétré : initialise une grille avec un nombre donné de lignes et de colonnes
Grid::Grid(int lignes, int colonnes){
    this->grid = std::vector<std::vector<Cell>>(lignes, std::vector<Cell>(colonnes)); // Initialise une grille 2D avec des cellules mortes
    this->lignes = lignes;
    this->colonnes = colonnes;
}

// Compte le nombre de voisins vivants autour d'une cellule donnée
int Grid::compterVoisinsVivants(int x, int y) const {
    int compte = 0;
    // Parcourt les voisins de la cellule en incluant les bords grâce au "wrap-around"
    for(int k = -1; k <= 1; ++k){ 
        for(int h = -1; h <= 1; ++h){
            if(k == 0 && h == 0) continue; //ignorer la cellule elle-même
            int vx = (x + k + lignes) % lignes;//position voisine en x 
            int vy = (y + h + colonnes) % colonnes; // Position voisine en y
            if(vx >= 0 && vx < lignes && vy >= 0 && vy < colonnes && grid[vx][vy].getVie()){ //vx est borné entre 0 et la taille de la ligne et vy est borné entre 0 et la taille de la colonne, on vérifie si l'état de la voisine est vivante
                ++compte; //incrérmente le compteur pour chaque voisin de la cellule 
            }
        } 
    }
    return compte;
}

bool Grid::validerGrille() const {
    for (int x = 0; x < lignes; ++x) {
        for (int y = 0; y < colonnes; ++y) {
            int voisinsVivants = compterVoisinsVivants(x, y);
            bool etatActuel = getEtatCellule(x, y);

            // Vérifier les règles du Jeu de la Vie
            if (etatActuel) {
                if (voisinsVivants != 2 && voisinsVivants != 3) {
                    return false; // Une cellule vivante ne respecte pas les règles
                }
            } else {
                if (voisinsVivants == 3) {
                    return true; // Une cellule morte respecte la règle de naissance
                }
            }
        }
    }
    return true;
}

// défini l'état d'une cellule à une position (x, y)
void Grid::setEtatCellule(int x, int y, bool etat){
    this-> grid[x][y].setEtat(etat);
}

//récupére l'état d'une cellule 
bool Grid::getEtatCellule(int x, int y) const {
    return grid[x][y].getVie(); // retourne vrai si la cellule est vivante sinon faux
}

// actualiser la grille à chaque itération
void Grid::actualiser(){
    auto newEtatGrille = grid; // Copie l'état actuel de la grille
    for(int x = 0 ; x < lignes; ++x){
        for(int y = 0; y < colonnes; ++y){
            int voisinVivant = compterVoisinsVivants(x, y);
            if(grid[x][y].getVie()){ // Si la cellule est vivante
                newEtatGrille[x][y].setEtat(voisinVivant == 2 || voisinVivant == 3); // Règle de survie
            } else { // Si la cellule est morte
                newEtatGrille[x][y].setEtat(voisinVivant == 3); // Règle de reproduction
            }  
        }
    }
    grid = newEtatGrille; //met à jour létat de la grille
}

// Affichage des cellules dans la grille
void Grid::afficher() const {
    for(const auto& ligne : grid){ //parcourt toutes les lignes de la grille
        for(const auto& cellule : ligne){ //parcourt toutes les cellules de la lignes
            std::cout << (cellule.getVie() ? "1" : "0");
        } 
        std::cout << std::endl;
    }
}

// Retourne l'état actuel de la grille sous forme d'un tableau 2D
 std::vector<std::vector<Cell>> Grid::getEtat() const {
    return grid;
 }

// Retourne le nombre de lignes de la grille
int Grid::getLignes() const {
    return lignes;
}
// Retourne le nombre de colonnes de la grille
int Grid::getColonnes() const {
    return colonnes;
}
