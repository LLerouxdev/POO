#include "Cell.h"

// Constructeur par défaut : initialise la cellule comme morte
Cell::Cell(){
    this->vivante = false; // Par défaut, la cellule est morte
}
// Constructeur paramétré : initialise la cellule avec un état donné
Cell::Cell(bool etat){ 
    this->vivante = etat; // Initialise l'état de la cellule
}

// implémentation du getter qui retourne la variable vivante
bool Cell::getVie() const {
    return vivante;
}


// implémentation du setter pour définir l'état de la cellule en bool
void Cell::setEtat(bool etat){
    this->vivante = etat;
}
