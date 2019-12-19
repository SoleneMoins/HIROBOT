#include "robot1g.h"
#include  <cmath>
robot1G::robot1G():robot{nullptr}
{}

robot1G::robot1G(position*p):robot{p}
{}

int robot1G::type()const{
    return 0;
}

void robot1G::deplacerRobot(const joueur&j){

    int distanceColonne,distanceLigne,distanceAbsolueColonne,distanceAbsolueLigne;
    distanceColonne = positionElement()->numColonne()-j.positionElement()->numColonne();
    distanceLigne = positionElement()->numLigne()-j.positionElement()->numLigne();
    distanceAbsolueColonne = fabs(positionElement()->numColonne()-j.positionElement()->numColonne());
    distanceAbsolueLigne = fabs(positionElement()->numLigne()-j.positionElement()->numLigne());
    if (distanceAbsolueColonne>distanceLigne)
        {
            if (distanceLigne>0)
                {
                    deplacerElementHaut();

                }
            else
            {

                deplacerElementBas();
            }
        }
    else
    {
            if (distanceColonne>0)
                {

                    deplacerElementGauche();
                }
            else
            {

                   deplacerElementDroite();
            }
    }

}


