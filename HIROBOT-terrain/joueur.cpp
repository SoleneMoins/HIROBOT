#include"joueur.h"

joueur::joueur():element{nullptr},d_nom{},d_score{0},d_dureeVie{0}
{}

joueur::joueur(position*p,const std::string&nom, int score):element{p},d_nom{nom},d_score{score},d_dureeVie{2}
{}

int joueur::score()const{
    return d_score;

}
void joueur::sauverJoueur(std::ostream &ost) const{
    ost<<"("<<d_nom<<","<<positionElement()<<","<<d_score<<","<<d_dureeVie<<")";
}
void joueur::LireDepuis(std::istream&ist){
    char c;
    ist>>c>>d_nom>>c;
    positionElement()->LireDepuis(ist);
    ist>>c>>d_score>>c>>d_dureeVie>>c;

}
void joueur::calculScore(){
    d_score = d_dureeVie;
}

void joueur::augmenterDureeVie(){
    d_dureeVie++;
}
std::istream&operator>>(std::istream&ist,joueur&j){
j.LireDepuis(ist);
return ist;
}
std::ostream& operator<<(std::ostream&ost, joueur& j){
    j.sauverJoueur(ost);
    return ost;
}

/* bool joueur::estDansDebris(const debris&d)
{
      if(positionElement()->numLigne()==d.positionDebris().numLigne()&&
         positionElement()->numColonne()==d.positionDebris().numColonne() )
      {
          diminuerDureeDeVie();
          return true;
      }
      else
      {
          return false;
      }

}
bool joueur::isDead()const
{
    return (d_dureeVie==0);

}

std::string joueur::nomJoueur()const{
return d_nom;
}


void joueur:: deplacer(int direction)
{
switch (direction)
   {
    case 1:
        deplacerElementHaut();
        augmenterScore();
        break;
    case -1:
        deplacerElementBas();
        augmenterScore();
        break;
    case 2:
        deplacerElementDroite();
        augmenterScore();
        break;
    case -2:
         deplacerElementGauche();
         augmenterScore();
         break;
    case 3:
           deplaceHautDroite();
           augmenterScore();
           break;
    case -3:
           deplaceHautGauche();
           augmenterScore();
           break;
    case 4:
           deplaceBasDroit();
           augmenterScore();
           break;
    case -4:
        deplaceBasGauche();
        augmenterScore();
        break;
    default:
        break;
       // return;
   }

}

void joueur::deplaceHautDroite()
{
   deplacerElementHaut();
   deplacerElementDroite();
}

void joueur::deplaceHautGauche()
{
    deplacerElementHaut();
    deplacerElementGauche();
}

void joueur::deplaceBasDroit()
{
  deplacerElementBas();
  deplacerElementDroite();

}

void joueur::deplaceBasGauche()
{
   deplacerElementBas();
    deplacerElementGauche();
}


 void joueur::sauver(std::ostream&ost)const{

    ost<<"("<<d_nom<<","<<positionElement()<<","<<d_score<<","<<d_dureeVie<<")";
}
void diminuerDureeDeVie()
{
    if(d_dureeVie>=1)
      d_dureeVie--;
}
void joueur::calculScore(){
    d_score = d_dureeVie; //si ils sont egaux, pourquoi garder les deux?
}

*/
