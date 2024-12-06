#include "Cell.h"

Cell::Cell(){
    this->vivante = false;
}
//implémentation du constructeur paramétré
Cell::Cell(bool etat){ 
    this->vivante = etat;
}

// implémentation du getter qui retourne la variable vivante
bool Cell::getVie() const {
    return vivante;
}

// implémentation du setter pour définir l'état de la cellule en bool
void Cell::setEtat(bool etat){
    this->vivante = etat;
}
