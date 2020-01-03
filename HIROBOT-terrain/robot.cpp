#include "robot.h"

/** Construction d'un robot par defaut c'est a dire que sa position est [0;0] */
robot::robot():element{nullptr}
{}

/**Construction du robot a l'aide d'une position */
robot::robot(position*p):element{p}
{}

/**Destruction du robot */
robot::~robot(){}

/**Affiche la position du robot*/
void robot::affichePosition()const{

    std::cout<<positionElement()->numLigne()<<";"<<positionElement()->numColonne()<<std::endl;
}

/**Verifie s'il y a collision avec le robot
    @param[in] r-le robot
    @return si les positions des robots sont les memes
*/

bool robot:: CollisionRobot(robot&r){
    return  positionElement()==r.positionElement();
}

/**Verifie s'il y a collision avec le joueur
    @param[in] j-le joueur
    @return si les positions du robot et du joueur sont les memes
*/

bool robot :: CollisionJoueur(joueur&j){
    return  positionElement()==j.positionElement();
}

/**Verifie s'il y a collision avec le debris
    @param[in] d-le debris
    @return si les positions du robot et du debris sont les memes
*/

bool robot ::CollisionDebris(debris&d){
    return  positionElement()==d.positionElement();
}

/**Affiche la position du robot
    @param[in] ost-le flot d'entree
    @param[in] r-le robot
    @return le flot
*/
std::ostream& operator<<(std::ostream&ost, robot&r){
    r.sauverPosition(ost);
    return ost;
}


