#ifndef JOUEUREXPERT_H
#define JOUEUREXPERT_H
#include"joueur.h"
#include<iostream>
class position;

class joueurExpert:public joueur{
public:
    joueurExpert();
    joueurExpert(position*p,const std::string&nom, int score);
    void deplaceElementHautDroite()=delete;
    void deplaceElementHautGauche()=delete;
    void deplaceElementBasDroit()=delete;
    void deplaceElementBasGauche()=delete;








};




#endif // JOUEUREXPERT_H
