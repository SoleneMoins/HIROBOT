#include "robot2g.h"

/** Construction d'un robot par defaut c'est a dire que sa position est [0;0] */
robot2G::robot2G():robot{nullptr}
{}

/**Construction du robot a l'aide d'une position */
robot2G::robot2G(position*p):robot{p}
{}

/** Retourne le type du robot
 @return la valeur du type de robot qui est 1
 */
int robot2G::type()const{
    return 1;
}

/**Deplace le robot en fonction de la position du joueur
 @param[in] j-le joueur
*/
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
