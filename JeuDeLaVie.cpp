#include "JeuDeLaVie.h"
#include <iostream>
#include <fstream>
#include <thread>
#include <chrono>

// Constructeur
JeuDeLaVie::JeuDeLaVie(const std::string& fichier, int iterations)
    : grille(chargerGrilleDepuisFichier(fichier)), maxIterations(iterations) {}

// Charger la grille à partir d'un fichier
Grille JeuDeLaVie::chargerGrilleDepuisFichier(const std::string& fichier) {
    std::ifstream fichierEntree(fichier);
    if (!fichierEntree.is_open()) {
        throw std::runtime_error("Impossible d'ouvrir le fichier !");
    }

    int lignes, colonnes;
    fichierEntree >> lignes >> colonnes; // Lire les dimensions
    Grille g(lignes, colonnes);

    for (int i = 0; i < lignes; ++i) {
        for (int j = 0; j < colonnes; ++j) {
            bool etat;
            fichierEntree >> etat; // Lire l'état de chaque cellule
            g.definirEtatCellule(i, j, etat);
        }
    }

    fichierEntree.close();
    return g;
}

// Lancer le jeu en mode console
void JeuDeLaVie::lancerModeConsole() {
    auto etatPrecedent = grille.obtenirEtat(); // Sauvegarde de l'état précédent

    for (int iteration = 0; iteration < maxIterations; ++iteration) {
        // Afficher l'itération courante
        system("clear"); // Utilisez "cls" sous Windows
        std::cout << "Iteration " << iteration + 1 << ":" << std::endl;
        grille.afficher();

        // Attendre un moment pour visualiser chaque itération
        std::this_thread::sleep_for(std::chrono::milliseconds(500));

        // Actualiser la grille
        grille.actualiser();

        // Vérifier si la grille est stable
        if (grille.estStable(etatPrecedent)) {
            std::cout << "La grille s'est stabilisée. Fin de l'exécution..." << std::endl;
            break;
        }

        // Mettre à jour l'état précédent
        etatPrecedent = grille.obtenirEtat();
    }
}

// Lancer le jeu en mode graphique
void JeuDeLaVie::lancerModeGraphique(int tailleCellule) {
    Affichage affichage(grille.obtenirLignes(), grille.obtenirColonnes(), tailleCellule);
    int iteration = 0;

    while (affichage.estOuverte() && iteration < maxIterations) {
        affichage.gererEvenements();
        affichage.afficherGrille(grille);
        grille.actualiser();
        std::this_thread::sleep_for(std::chrono::milliseconds(100));
        ++iteration;
    }
}
