#include "Jeu.h"
#include <iostream>
#include <string>

int main() {
    std::string cheminFichier; // Nom du fichier contenant l'état initial de la grille
    int nombreIterations;     // Nombre d'itérations à exécuter dans le jeu

    // Menu principal : proposer des options à l'utilisateur
    std::cout << "Choisissez une action :\n";
    std::cout << "1. Lancer le jeu\n"; // Lancer le jeu en mode console
    std::cout << "2. Lancer le test unitaire pour valider la grille après une itération\n"; // Lancer un test unitaire
    int choix;
    std::cin >> choix; // Lecture du choix de l'utilisateur

    if (choix == 1) {
        // Mode jeu normal
        std::cout << "Entrez le nom du fichier contenant l'état initial : ";
        std::cin >> cheminFichier; // Demander le chemin du fichier d'entrée

        std::cout << "Entrez le nombre d'itérations à effectuer : ";
        std::cin >> nombreIterations; // Demander le nombre d'itérations

        try {
            // Création d'une instance de la classe Jeu avec les paramètres fournis
            Jeu jeu(cheminFichier, nombreIterations);

            // Lancer le jeu en mode console
            jeu.ModeConsole(cheminFichier);
        } catch (const std::exception& e) {
            // Gérer les erreurs (par exemple, fichier introuvable ou invalide)
            std::cerr << "Erreur : " << e.what() << std::endl;
        }

    } else if (choix == 2) {
        // Mode test unitaire
        std::cout << "Entrez le nom du fichier pour le test unitaire : ";
        std::cin >> cheminFichier; // Demander le fichier contenant la grille pour le test

        try {
            // Création d'une instance de la classe Jeu pour une seule itération
            Jeu jeu(cheminFichier, 1); // Une seule itération est suffisante pour le test

            // Exécuter le test unitaire pour valider la grille après une itération
            jeu.testUnitaireValidite();
        } catch (const std::exception& e) {
            // Gérer les erreurs rencontrées lors du test unitaire
            std::cerr << "Erreur : " << e.what() << std::endl;
        }

    } else {
        // Gestion des choix invalides
        std::cout << "Choix invalide ! Veuillez relancer le programme." << std::endl;
    }

    return 0; // Fin du programme
}
