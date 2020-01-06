#include "robot1g.h"
#include  <cmath>

/** Construction d'un robot par defaut c'est a dire que sa position est [0;0] */
robot1G::robot1G():robot{nullptr}
{}

/**Construction du robot à l'aide d'une position */
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
    // Si le robot est dans la même colonne que le joueur ou que la distance est plus courte verticalement on se déplace sur l'axe vertical
    if (distanceAbsolueColonne == 0 || distanceAbsolueLigne >= distanceAbsolueColonne){

        if (distanceLigne>0){
            deplacerElementHaut();
        }
        else {
            deplacerElementBas();
        }

    }
    // Si le robot est dans la même ligne que le joueur ou que la distance est plus courte horizontalement on se déplace sur l'axe horizontal
    if (distanceAbsolueLigne == 0 || distanceAbsolueLigne < distanceAbsolueColonne){

        if (distanceColonne>0) {
            deplacerElementGauche();
        }
        else {
            deplacerElementDroite();
        }

    }

}


