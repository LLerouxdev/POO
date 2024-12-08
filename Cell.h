#ifndef CELL_H
#define CELL_H

class Cell {
private:
    bool vivante;  // L'état de la cellule (true = vivante, false = morte)

public:
    Cell(); // Constructeur par défault
    // Constructeur paramétré: initialise l'état de la cellule (par défaut morte)
    Cell(bool etat);

    // Get : retourne true si la cellule est vivante, false si morte
    bool getVie() const;

    // Set : modifie l'état de la cellule
    void setEtat(bool etat);
};

#endif
