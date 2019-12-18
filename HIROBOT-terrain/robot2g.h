#ifndef ROBOT2G_H
#define ROBOT2G_H
#include "robot.h"

class robot2G:public robot
{
public:
    robot2G();
    robot2G(position*p);
    virtual void deplacerRobot(const joueur&j)override;
    virtual int type()const override;
};

#endif // ROBOT2G_H
