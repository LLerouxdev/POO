#include "Grille.h"
#include <iostream>

Grille::Grille(int lignes, int colonnes) : lignes(lignes), colonnes(colonnes) {
    cellules = std::vector<std::vector<Cellule>>(lignes, std::vector<Cellule>(colonnes));
}

void Grille::definirEtatCellule(int x, int y, bool etat) {
    cellules[x][y].definirEtat(etat);
}

bool Grille::obtenirEtatCellule(int x, int y) const {
    return cellules[x][y].estVivante(); // Renvoie l'état de la cellule
}

int Grille::compterVoisinsVivants(int x, int y) const {
    int compte = 0;
    for (int dx = -1; dx <= 1; ++dx) {
        for (int dy = -1; dy <= 1; ++dy) {
            if (dx == 0 && dy == 0) continue; // Ignorer la cellule elle-même
            int nx = x + dx;
            int ny = y + dy;
            if (nx >= 0 && nx < lignes && ny >= 0 && ny < colonnes && cellules[nx][ny].estVivante()) {
                ++compte;
            }
        }
    }
    return compte;
}

void Grille::actualiser() {
    auto nouvelEtat = cellules;

    for (int x = 0; x < lignes; ++x) {
        for (int y = 0; y < colonnes; ++y) {
            int voisinsVivants = compterVoisinsVivants(x, y);
            if (cellules[x][y].estVivante()) {
                nouvelEtat[x][y].definirEtat(voisinsVivants == 2 || voisinsVivants == 3);
            } else {
                nouvelEtat[x][y].definirEtat(voisinsVivants == 3);
            }
        }
    }

    cellules = nouvelEtat;
}

void Grille::afficher() const {
    for (const auto& ligne : cellules) {
        for (const auto& cellule : ligne) {
            std::cout << (cellule.estVivante() ? "1 " : "0 ");
        }
        std::cout << std::endl;
    }
}

bool Grille::estStable(const std::vector<std::vector<Cellule>>& etatPrecedent) const {
    for (int i = 0; i < lignes; ++i) {
        for (int j = 0; j < colonnes; ++j) {
            if (cellules[i][j].estVivante() != etatPrecedent[i][j].estVivante()) {
                return false;
            }
        }
    }
    return true;
}

std::vector<std::vector<Cellule>> Grille::obtenirEtat() const {
    return cellules;
}

int Grille::obtenirLignes() const {
    return lignes;
}

int Grille::obtenirColonnes() const {
    return colonnes;
}
