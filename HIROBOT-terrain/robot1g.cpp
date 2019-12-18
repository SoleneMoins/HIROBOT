#include "robot1g.h"

robot1G::robot1G():robot{nullptr}
{}

robot1G::robot1G(position*p):robot{p}
{}

int robot1G::type()const{
    return 0;
}

void robot1G::deplacerRobot(const joueur&j){


    if(positionElement()->numLigne()!=j.positionElement()->numLigne() && positionElement()->numColonne()!=j.positionElement()->numColonne() ){

            if(positionElement()->numLigne()<j.positionElement()->numLigne() && positionElement()->numColonne()<j.positionElement()->numColonne()){

                if(j.positionElement()->numLigne()-positionElement()->numLigne()<j.positionElement()->numColonne()-positionElement()->numColonne()){
                    deplacerElementBas();
                }else{
                    deplacerElementDroite();
                }
            }

            if(positionElement()->numLigne()<j.positionElement()->numLigne() && positionElement()->numColonne()>j.positionElement()->numColonne()){

                if(j.positionElement()->numLigne()-positionElement()->numLigne()<positionElement()->numColonne()-j.positionElement()->numColonne()){
                    deplacerElementBas();
                }else{
                    deplacerElementGauche();
                }
            }

            if(positionElement()->numLigne()>j.positionElement()->numLigne() && positionElement()->numColonne()>j.positionElement()->numColonne()){

                if(positionElement()->numLigne()-j.positionElement()->numLigne()<positionElement()->numColonne()-j.positionElement()->numColonne()){
                    deplacerElementHaut();
                }else{
                    deplacerElementGauche();
                }
            }

            if(positionElement()->numLigne()>j.positionElement()->numLigne() && positionElement()->numColonne()<j.positionElement()->numColonne()){

                if(positionElement()->numLigne()-j.positionElement()->numLigne()<j.positionElement()->numColonne()-positionElement()->numColonne()){
                    deplacerElementHaut();
                }else{
                    deplacerElementDroite();
                }
            }
    }else{

            if(positionElement()->numLigne()>j.positionElement()->numLigne()){
                deplacerElementHaut();
            }

            if(positionElement()->numLigne()<j.positionElement()->numLigne()){
                deplacerElementBas();
            }

            if(positionElement()->numColonne()<j.positionElement()->numColonne()){
                deplacerElementDroite();
            }

            if(positionElement()->numColonne()>j.positionElement()->numColonne()){
                deplacerElementGauche();
            }


    }



}

