#ifndef JEU_H
#define JEU_H

#include "Grid.h"
#include "Affichage.h"
#include <string>

class Jeu {
    private:
    Grid grille; // représente la grille du jeu
    int maxIteration;

    Grid chargerGrilleDepuisFichier(const std::string& fichier);

    public:
   // Constructeur : initialise le jeu avec un fichier et un nombre d'itérations
    Jeu(const std::string& fichier, int iterations);

    // Test unitaire pour vérifié si les règles du jeu sont respectées
    void testUnitaireValidite();
    
    // Lance le jeu en mode console (sans interface graphique)
    void ModeConsole(const std::string& fichier);
    
    // Lance le jeu en mode graphique (avec une fenêtre SFML)
    void ModeGraphique(int tailleCellule, int temps);
};

#endif
