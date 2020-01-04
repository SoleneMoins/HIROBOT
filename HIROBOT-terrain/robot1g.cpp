#include "robot1g.h"
#include  <cmath>

/** Construction d'un robot par defaut c'est a dire que sa position est [0;0] */
robot1G::robot1G():robot{nullptr}
{}

/**Construction du robot a l'aide d'une position */
robot1G::robot1G(position*p):robot{p}
{}

/** Retourne le type du robot
 @return la valeur du type de robot qui est 0
 */
int robot1G::type()const{
    return 0;
}

/**Deplace le robot en fonction de la position du joueur
 @param[in] j-le joueur
*/
void robot1G::deplacerRobot(const joueur&j){

    int distanceColonne,distanceLigne,distanceAbsolueColonne,distanceAbsolueLigne;

    distanceColonne = positionElement()->numColonne()-j.positionElement()->numColonne();
    distanceLigne = positionElement()->numLigne()-j.positionElement()->numLigne();

    distanceAbsolueColonne = fabs(positionElement()->numColonne()-j.positionElement()->numColonne());
    distanceAbsolueLigne = fabs(positionElement()->numLigne()-j.positionElement()->numLigne());

    if (distanceAbsolueColonne == 0 || distanceAbsolueLigne >= distanceAbsolueColonne){

            if (distanceLigne>0)
                {
                    deplacerElementHaut();

                }
            else
            {

                deplacerElementBas();
            }
        }
    if (distanceAbsolueLigne == 0 || distanceAbsolueLigne < distanceAbsolueColonne)
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


