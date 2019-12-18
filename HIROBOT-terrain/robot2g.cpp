#include "robot2g.h"


robot2G::robot2G():robot{nullptr}
{}


robot2G::robot2G(position*p):robot{p}
{}

int robot2G::type()const{
    return 1;
}


void robot2G::deplacerRobot(const joueur&j){

    if(positionElement()->numLigne()<j.positionElement()->numLigne()){
        deplacerElementBas();
    }

    if(positionElement()->numLigne()>j.positionElement()->numLigne()){
        deplacerElementHaut();
    }

    if(positionElement()->numColonne()<j.positionElement()->numColonne()){
        deplacerElementDroite();
    }

    if(positionElement()->numColonne()>j.positionElement()->numColonne()){
        deplacerElementGauche();
    }

}
