#include "element.h"

element::element(position*p):d_pos{p}
{}


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

void element::deplacerElementHautGauche(){
    deplacerElementHaut();
    deplacerElementGauche();
}

void element::deplacerElementHautDroite(){
    deplacerElementHaut();
    deplacerElementDroite();
}

void element::deplacerElementBasGauche(){
    deplacerElementBas();
    deplacerElementGauche();
}

void element::deplacerElementBasDroite(){
    deplacerElementBas();
    deplacerElementDroite();
}

bool element::peutSeDeplacer(int nbLignes, int nbColonnes, int typeDeplacement){
    switch (typeDeplacement) {
    //Si l'élément veut aller vers le haut du terrain
    case 0:
        return d_pos->numLigne() != 0;
    //Si l'élément veut aller vers le bas du terrain
    case 1:
        return d_pos->numLigne() != nbLignes - 1;
    //Si l'élément veut aller vers la gauche du terrain
    case 2:
        return d_pos->numColonne() != 0;
    //Si l'élément veut aller vers la droite du terrain
    case 3:
        return d_pos->numColonne() != nbColonnes - 1;
    default:
        break;
    }

}

bool element::collision(element elem){
    return d_pos->numLigne() == elem.d_pos->numLigne() && d_pos->numColonne() == elem.d_pos->numColonne();
}
