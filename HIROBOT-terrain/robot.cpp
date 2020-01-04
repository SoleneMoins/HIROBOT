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

void robot::sauverPosition(std::ostream&ost){

    ost<<*positionElement();

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


