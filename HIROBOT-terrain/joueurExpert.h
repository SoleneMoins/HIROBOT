#ifndef JOUEUREXPERT_H
#define JOUEUREXPERT_H
#include"joueur.h"
#include<iostream>
class position;

class joueurExpert:public joueur{
public:
    joueurExpert(position*p,const std::string&nom, int score);
    void deplaceHautDroite()=delete;
    void deplaceHautGauche()=delete;
    void deplaceBasDroit()=delete;
    void deplaceBasGauche()=delete;








};




#endif // JOUEUREXPERT_H
