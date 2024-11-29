#include "JeuDeLaVie.h"
#include <iostream>

int main(int argc, char* argv[]) {
    if (argc < 3) {
        std::cout << "Usage : " << argv[0] << " <fichier_entree> <iterations> [--graphique]" << std::endl;
        return 1;
    }

    std::string fichier = argv[1];
    int iterations = std::stoi(argv[2]);
    bool modeGraphique = (argc == 4 && std::string(argv[3]) == "--graphique");

    try {
        JeuDeLaVie jeu(fichier, iterations);
        if (modeGraphique) {
            jeu.lancerModeGraphique(10); // Taille des cellules = 10
        } else {
            jeu.lancerModeConsole();
        }
    } catch (const std::exception& e) {
        std::cerr << "Erreur : " << e.what() << std::endl;
        return 1;
    }

    return 0;
}
