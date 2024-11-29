#include "Cellule.h"

Cellule::Cellule(bool etat) : vivante(etat) {}

bool Cellule::estVivante() const {
    return vivante;
}

void Cellule::definirEtat(bool etat) {
    vivante = etat;
}
