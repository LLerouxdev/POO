#include "Jeu.h"
#include <iostream>

int main(int argc, char * argv[]) { 
    //vérifie si les arguments sont suffisant pour lancer le programme
    if(argc < 3){
        std::cout << "Usage :" << argv[0] << "<fichier_input> <iterations> [--graphique]" << std::endl;
        return 1; //retourne une erreur si les arguments sont manquants
    }
    //récupére le nom du fichier et le nombre d'itération
    std::string fichier = argv[1];
    int iterations = std::stoi(argv[2]);
    // détermine si le mode graphique est activé
    bool modeGraph = (argc == 4 && std::string(argv[3]) == "--graphique");

    try{
        Jeu jeu(fichier, iterations);
        //lance le jeu soit en mode console soit en mode graphique
        if(modeGraph){
            jeu.ModeGraphique(10); //taille des cellules = 10
        }
        else {
            jeu.ModeConsole(fichier);
        }
    }

    catch(const std::exception& e){
        // si une erreur survient, affiche le message d'erreur
        std::cerr << "Erreur :" << e.what() << std::endl;
        return 1; //retourne une erreur
    }

    return 0; // Terminer l'exécution
}

