#include "Jeu.h"
#include <iostream>
#include <string>
#include <cassert>

// Fonction de test unitaire
void testUnitaire() {
    Grid grille(5, 5);

    // Initialiser la grille
    grille.setEtatCellule(1, 1, true);
    grille.setEtatCellule(1, 2, true);
    grille.setEtatCellule(1, 3, true);

    // Vérifier l'état avant actualisation
    assert(grille.getEtatCellule(1, 1) == true);
    assert(grille.getEtatCellule(1, 2) == true);
    assert(grille.getEtatCellule(1, 3) == true);

    // Actualiser la grille
    grille.actualiser();

    // Vérifier l'état après actualisation
    assert(grille.getEtatCellule(1, 2) == true); // La cellule centrale doit survivre
    assert(grille.getEtatCellule(0, 2) == true); // Une cellule morte doit devenir vivante
    assert(grille.getEtatCellule(2, 2) == true); // Une cellule morte doit devenir vivante

    std::cout << "Tous les tests unitaires ont réussi !" << std::endl;
}

int main() {
    std::string cheminFichier; // Variable pour stocker le chemin du fichier
    int nombreIterations;     // Variable pour stocker le nombre d'itérations

    // Demander à l'utilisateur le chemin du fichier
    std::cout << "Entrez le nom du fichier contenant l'état initial (ex : fichier_input.txt) : ";
    std::cin >> cheminFichier;

    // Demander à l'utilisateur le nombre d'itérations
    std::cout << "Entrez le nombre d'itérations à effectuer : ";
    std::cin >> nombreIterations;

    try {
        // Initialisation du jeu avec les paramètres fournis
        Jeu jeu(cheminFichier, nombreIterations);

        // Demander à l'utilisateur de choisir le mode
        std::cout << "Choisissez un mode :\n";
        std::cout << "1. Mode console\n";
        std::cout << "2. Mode graphique\n";
        int choix;
        std::cin >> choix;

        if (choix == 1) {
            // Lancer le mode console
            std::cout << "Lancement du jeu en mode console..." << std::endl;
            jeu.ModeConsole(cheminFichier);
        } else if (choix == 2) {
            std::cout << "Durée entre chaque itérations (en ms) :\n";
            int time;
            std::cin >> time;
            // Lancer le mode graphique avec une taille de cellules fixe
            const int tailleCellule = 20; // Taille par défaut des cellules
            std::cout << "Lancement du jeu en mode graphique..." << std::endl;
            jeu.ModeGraphique(tailleCellule, time);
        } else {
            std::cerr << "Choix invalide. Veuillez relancer le programme." << std::endl;
            return 1;
        }

    } catch (const std::exception& e) {
        // Gestion des erreurs
        std::cerr << "Erreur : " << e.what() << std::endl;
        return 1;
    }

    return 0; // Fin du programme
}
