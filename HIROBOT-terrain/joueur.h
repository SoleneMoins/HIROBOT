#ifndef JOUEUR_H
#define JOUEUR_H
#include <iostream>
//#include"position.h"
#include "element.h"
#include"debris.h"
class position;
class joueur: public element
{
public:
    joueur();
    joueur(position*p,const std::string&nom, int score);
    int score()const;
    void calculScore();
    void augmenterDureeVie();
    void sauverJoueur(std::ostream&ost)const;
    void LireDepuis(std::istream&ist);

    //Pour une optimisation sinon on sera obligé de dupliquer le code pour ses deplacements en diagonale
    /* void deplaceHautDroite();
     void deplaceHautGauche();
     void deplaceBasDroit();
     void deplaceBasGauche(); */

    //Pour le joueur expert on aura besoin  de modifier ces méthodes donc elles sont virtuelles
    /* virtual void sauver(std::ostream&ost)const override;
     virtual void deplacer(int direction)override;
     std::string nomJoueur()const;*/

    /* TODO : Améliorations du calcul du score
      void diminuerDureeDeVie();
      bool isDead()const;//pour controler la vie du joueur en sachant s'il est mort ou pas genre sa duree de vie =0
    //le joueur isDead s'il tombe deux fois dans un debris ou un robot l'écrase.
    bool estDansDebris(const debris&d);
    */

private :
    std::string d_nom;
    int d_score;
    int d_dureeVie;
};

std::ostream& operator<<(std::ostream&ost, joueur& j);
std::istream&operator>>(std::istream&ist,joueur&j);

#endif // JOUEUR_H
























//#endif // JOUEUR_H
