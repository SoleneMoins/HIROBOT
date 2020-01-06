#ifndef DEBRIS_H
#define DEBRIS_H
#include<iostream>
#include"element.h"

class debris:public element
{
public:
    debris();
    debris(position*p);
    void deplacerElement(position*p)=delete;
    void deplacerElementGauche()=delete;
    void deplacerElementDroite()=delete;
    void deplacerElementBas()=delete;
    void deplacerElementHaut()=delete;
    void deplacerElementHautGauche()=delete;
    void deplacerElementHautDroite()=delete;
    void deplacerElementBasGauche()=delete;
    void deplacerElementBasDroite()=delete;
};


#endif // DEBRIS_H
