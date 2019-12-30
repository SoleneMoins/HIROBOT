#ifndef ELEMENT_H
#define ELEMENT_H
#include "position.h"

class element
{
public:
    element(position*p);
    position* positionElement()const;
    void deplacerElement(position*p);
    void deplacerElementGauche();
    void deplacerElementDroite();
    void deplacerElementBas();
    void deplacerElementHaut();
    void deplacerElementHautGauche();
    void deplacerElementHautDroite();
    void deplacerElementBasGauche();
    void deplacerElementBasDroite();
    bool peutSeDeplacer(int nbLignes, int nbColonnes, int typeDeplacement);
    bool collision(element elem);
private:
    position* d_pos;


};

#endif // ELEMENT_H
