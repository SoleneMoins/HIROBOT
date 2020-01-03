#ifndef ROBOT_H
#define ROBOT_H
#include "joueur.h"

class robot : public element {
public :
	robot();
    robot(position*p);
    virtual ~robot();
    virtual void deplacerRobot(const joueur&j) = 0;
    virtual int type()const=0;
    void affichePosition()const;
    void sauverPosition(std::ostream&ost);
    bool CollisionRobot(const robot&r);
    bool CollisionJoueur(const joueur&j);
    bool CollisionDebris(const debris&d);


};
std::ostream& operator<<(std::ostream&ost, robot&r);
#endif // ROBOT_H
