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
    joueur();//pas utile? sino cela voudrait dire que le joueur est mort avant de se deplacer
    joueur(position*p,const std::string&nom);
    int score()const;
    int dureeVie()const;
    void augmenterScore();
    void augmenterDureeVie();
    void diminuerDureeDeVie();
     void deplaceHautDroite();
    void deplaceHautGauche();
    void deplaceBasDroit();
    void deplaceBasGauche();//pour une meilleur optimisation sinon on sera obligé de dupliquer le code pour ses deplacements
    /*void calculScore();
    */
    virtual void sauver(std::ostream&ost)const override;
    virtual void deplacer(int direction)override;
    std::string nomJoueur()const;
    void LireDepuis(std::istream&ist);
    bool isDead()const;//pour controler la vie du joueur en sachant s'il est mort ou pas genre sa duree de vie =0
    //le joueur isDead s'il tombe deux fois dans un debris ou ecrase une seule fois un robot
    bool estDansDebris(const debris&d);
private :
    std::string d_nom;
    int d_score;
    int d_dureeVie;
    //un joueur devrait tomber dans un  debris sans que le jeu s'arrete
                    //dans ce cas dans la class debris on  verifiera si le oueur est dans le debris si oui alors on
                    //decremente la durée de vie du joueur
                    //si duree de vie est egale ç ero le jeu se termine
};
std::istream&operator>>(std::istream&ist,joueur&j);



#endif // JOUEUR_H
























//#endif // JOUEUR_H
