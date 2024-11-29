#ifndef JEUDELAVIE_H
#define JEUDELAVIE_H

#include <string>
#include "Grille.h"
#include "Affichage.h"

class JeuDeLaVie {
private:
    Grille grille;
    int maxIterations;

    Grille chargerGrilleDepuisFichier(const std::string& fichier);

public:
    JeuDeLaVie(const std::string& fichier, int iterations);
    void lancerModeConsole();
    void lancerModeGraphique(int tailleCellule);
};

#endif
