#include "robot.h"

robot::robot():element{nullptr}
{}
robot::robot(position*p):element{p};

robot::~robot(){}

void robot::affichePosition()const{

    std::cout<<positionElement()->numLigne()<<";"<<positionElement()->numColonne()<<std::endl;
}


