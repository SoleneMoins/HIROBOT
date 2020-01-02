#ifndef ELEMENT_H
#define ELEMENT_H
#include "position.h"

class element
{
public:
    element(position*p);
    ~element();
    position* positionElement()const;
    void deplacerElement(position*p);
    void deplacerElementGauche();
    void deplacerElementDroite();
    void deplacerElementBas();
    void deplacerElementHaut();

private:
    position* d_pos;


};

#endif // ELEMENT_H
