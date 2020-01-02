#include "element.h"

element::element(position*p):d_pos{p}
{}

element::~element(){delete d_pos;}

position* element::positionElement() const{
    return d_pos;
}


void element::deplacerElement(position*p){
    d_pos = p;
}

void element::deplacerElementGauche(){
    d_pos->changerPosition(d_pos->numColonne()-1,d_pos->numLigne());
}


void element::deplacerElementDroite(){
     d_pos->changerPosition(d_pos->numColonne()+1,d_pos->numLigne());
}


void element::deplacerElementBas(){
     d_pos->changerPosition(d_pos->numColonne(),d_pos->numLigne()+1);
}


void element::deplacerElementHaut(){
     d_pos->changerPosition(d_pos->numColonne(),d_pos->numLigne()-1);
}


