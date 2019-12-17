#include"joueurExpert.h"
joueurExpert::joueurExpert(position*p,const std::string&nom):joueur{p,nom} {}


void joueurExpert::deplacer(int direction)
{
    switch (direction)
   {
    case 1:
      deplacerElementHaut();
        break;
    case -1:
        deplacerElementBas();
        break;
    case 2:
       deplacerElementDroite();
        break;
    case -2:
         deplacerElementGauche();
         break;
    default:
        break;
   }
}
