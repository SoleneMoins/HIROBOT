#ifndef JOUEUR_H
#define JOUEUR_H
#include <iostream>
#include "element.h"

class joueur: public element
{
public:
    joueur();
    joueur(position*p,const std::string&nom, int score);
    int score()const;
    void calculScore();
    std::string nomJoueur()const;
    int dureeVie()const;
    int nbRobotsDetruits()const;
    void Reinitialiser();

    void augmenterDureeVie();
    void augmenterNbRobotsDetruits();

    void sauverJoueur(std::ostream&ost)const;
    void LireDepuis(std::istream&ist);


private :
    std::string d_nom;
    int d_score;
    int d_dureeVie;
    int d_robotDetruit;
};

std::ostream& operator<<(std::ostream&ost, joueur& j);
std::istream&operator>>(std::istream&ist,joueur&j);

#endif // JOUEUR_H
























//#endif // JOUEUR_H
