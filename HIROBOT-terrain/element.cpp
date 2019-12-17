#include "element.h"

element::~element()
{
    delete d_pos;
}
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

std::ostream&operator<<(std::ostream&ost,const element&elem)
{
    elem.sauver(ost);
    return ost;
}

