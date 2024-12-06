#include "Grid.h"
#include <iostream>

Grid::Grid(){
    this->lignes = 0;
    this->colonnes = 0;
}
Grid::Grid(int lignes, int colonnes){
    this->grid = std::vector<std::vector<Cell>>(lignes, std::vector<Cell>(colonnes));
    this->lignes = lignes;
    this->colonnes = colonnes;
}

int Grid::compterVoisinsVivants(int x, int y) const {
    int compte = 0;
    //parcourt autour de la cellule
    for(int k = -1; k <= 1; ++k){ 
        for(int h = -1; h <= 1; ++h){
            if(k == 0 && h == 0) continue; //ignorer la cellule elle-même
            int vx = (x + k + lignes) % lignes;  //position voisine en x avec wrap-around
            int vy = (y + h + colonnes) % colonnes; // Position voisine en y avec wrap-around
            if(vx >= 0 && vx < lignes && vy >= 0 && vy < colonnes && grid[vx][vy].getVie()){ //vx est borné entre 0 et la taille de la ligne et vy est borné entre 0 et la taille de la colonne, on vérifie si l'état de la voisine est vivante
                ++compte; //incrérmente le compteur pour chaque voisin de la cellule 
            }
        } 
    }
    return compte;
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
    auto newEtatGrille = grid;
    for(int x = 0 ; x < lignes; ++x){
        for(int y = 0; y < colonnes; ++y){
            int voisinVivant = compterVoisinsVivants(x, y);
            if(grid[x][y].getVie()){
                newEtatGrille[x][y].setEtat(voisinVivant == 2 || voisinVivant == 3);
            } else {
                newEtatGrille[x][y].setEtat(voisinVivant == 3);
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

//Gestion d'erreur !
// Verifie si la grille est stable (pas de changement entre les états) 
bool Grid::estStable(const std::vector<std::vector<Cell>>& etatPrecedent) const { 
    for(int i = 0 ; i < lignes; ++i){
        for(int j = 0; j < colonnes; ++j){
            if(grid[i][j].getVie() != etatPrecedent[i][j].getVie()){
                return false;
            }
        }
    }
    return true;
}

// retourne la grille sous forme d'un tableau 2D
 std::vector<std::vector<Cell>> Grid::getEtat() const {
    return grid;
 }

int Grid::getLignes() const {
    return lignes;
}
int Grid::getColonnes() const {
    return colonnes;
}