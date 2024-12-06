#include "Jeu.h"
#include <iostream>
#include <fstream>
#include <thread>
#include <chrono>
#include <filesystem>

namespace fs = std::filesystem;
// Constructeur paramétré
Jeu::Jeu(const std::string& fichier, int iterations) {
    this->maxIteration = iterations;
    this->grille = chargerGrilleDepuisFichier(fichier);
}

Grid Jeu::chargerGrilleDepuisFichier(const std::string& fichier){
    std::ifstream fichierEntree(fichier); 
    if(!fichierEntree.is_open()){ //Gestion d'erreur
        throw std::runtime_error("Impossible d'ouvrir le Fichier !");
    }

    int lignes;
    int colonnes;
    fichierEntree >> lignes >> colonnes; // On lit les dimensions de la grille avec les lignes et les colonnes
    Grid grid(lignes, colonnes); // On créer une Grille qui sera constitué de lignes et de colonnes

    for(int i = 0; i < lignes; ++i){
        for(int j = 0; j < colonnes; ++j){
            bool etat;
            fichierEntree >> etat;
            grid.setEtatCellule(i, j , etat); // On défini l'état de chaque cellule
        }
    }

    fichierEntree.close(); // Ferme le fichier après la lecture 
    return grid;
}

// Lancer le jeu en mode console : affiche et met à jour la grille dans le terminal
void Jeu::ModeConsole(const std::string& fichier) {
    // Récupérer le nom du dossier de sortie à partir du fichier d'entrée
    std::string baseNomFichier = fichier.substr(0, fichier.find_last_of('.'));
    std::string dossierSortie = baseNomFichier + "_out";

    // Créer le dossier s'il n'existe pas
    if (!fs::exists(dossierSortie)) {
        try {
            fs::create_directory(dossierSortie);
        } catch (const std::exception& e) {
            std::cerr << "Erreur lors de la création du dossier : " << e.what() << std::endl;
            return;
        }
    }

    for (int iteration = 0; iteration < maxIteration; ++iteration) {
        // Chemin du fichier de sortie pour cette itération
        std::string nomFichierSortie = dossierSortie + "/iteration_" + std::to_string(iteration + 1) + ".txt";

        // Ouvrir le fichier en écriture
        std::ofstream fichierSortie(nomFichierSortie);
        if (!fichierSortie.is_open()) {
            std::cerr << "Erreur lors de l'ouverture du fichier de sortie : " << nomFichierSortie << std::endl;
            return;
        }

        // Écrire l'état de la grille dans le fichier
        for (int i = 0; i < grille.getLignes(); ++i) {
            for (int j = 0; j < grille.getColonnes(); ++j) {
                fichierSortie << (grille.getEtatCellule(i, j) ? "1" : "0") << " ";
            }
            fichierSortie << "\n";
        }
        fichierSortie.close();

        // Afficher la grille dans la console
        system("clear");
        std::cout << "Iteration " << iteration + 1 << ":" << std::endl;
        grille.afficher();
        grille.actualiser();
        std::this_thread::sleep_for(std::chrono::milliseconds(500));
    }
}
//Lance le jeu en mode graphique avec SFML
void Jeu::ModeGraphique(int tailleCellule){
    Affichage affichage(grille.getLignes(), grille.getColonnes(), tailleCellule);
    int iteration = 0;

    //Boucle principale de l'affichage tant que la fenêtre est ouverte et qu'il reste des itérations
    while(affichage.windowOpen() && iteration < maxIteration){ 
        affichage.gererWindow(); //gère les événements de l'utilisateur (fermeture)
        affichage.afficherGrille(grille); // affiche la grille dans la fenêtre
        grille.actualiser(); //actualise l'état des cellules
        std::this_thread::sleep_for(std::chrono::milliseconds(100)); //petite pause pour visualiser les changements
        ++iteration; //incrémente itération pour passer à celle d'après
    }

}
