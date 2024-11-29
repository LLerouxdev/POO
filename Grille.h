#ifndef GRILLE_H
#define GRILLE_H

#include <vector>
#include "Cellule.h"

class Grille {
private:
    int lignes, colonnes;
    std::vector<std::vector<Cellule>> cellules;

    int compterVoisinsVivants(int x, int y) const;

public:
    Grille(int lignes, int colonnes);
    void definirEtatCellule(int x, int y, bool etat);
    bool obtenirEtatCellule(int x, int y) const; // Ajout de cette méthode
    void actualiser();
    void afficher() const;
    bool estStable(const std::vector<std::vector<Cellule>>& etatPrecedent) const;
    std::vector<std::vector<Cellule>> obtenirEtat() const;
    int obtenirLignes() const;
    int obtenirColonnes() const;
};

#endif
