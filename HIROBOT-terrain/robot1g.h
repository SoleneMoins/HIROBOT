#ifndef ROBOT1G_H
#define ROBOT1G_H
#include "robot.h"

class robot1G:public robot
{
public:
    robot1G();
    robot1G(position*p);
    virtual void deplacerRobot(const joueur&j) override;
    virtual int type()const override;
};

#endif // ROBOT1G_H
