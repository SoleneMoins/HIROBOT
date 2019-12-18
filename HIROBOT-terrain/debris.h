#ifndef DEBRIS_H
#define DEBRIS_H
#include<iostream>
#include"position.h"
#include"element.h"
class debris{
public:
    debris(const position&p); //le niveua du danger permet de faire disparaitre le robot et/ou le joueur
    position positionDebris()const;
private:
    position d_positionDebris;
  static int d_niveauDanger;

};


#endif // DEBRIS_H
