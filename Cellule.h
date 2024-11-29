#ifndef CELLULE_H
#define CELLULE_H

class Cellule {
private:
    bool vivante;

public:
    Cellule(bool etat = false);
    bool estVivante() const;
    void definirEtat(bool etat);
};

#endif
