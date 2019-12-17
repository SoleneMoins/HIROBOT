#ifndef ELEMENT_H
#define ELEMENT_H
#include "position.h"

class element
{
public:
    element(position*p);
    virtual~element();
    position* positionElement()const;
    virtual void sauver(std::ostream&ost)const=0;//tous les personnage seront sauver mais on ne sait pas comment
     virtual void deplacer(int direction)=0;//pour gerer les differentes directions suivants les element
    void deplacerElement(position*p);
    void deplacerElementGauche();
    void deplacerElementDroite();
    void deplacerElementBas();
    void deplacerElementHaut();

private:
    position* d_pos;


};

#endif // ELEMENT_H
