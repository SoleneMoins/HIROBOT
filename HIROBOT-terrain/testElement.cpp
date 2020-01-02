#include"doctest.h"
#include"element.h"
#include<iostream>

TEST_CASE("l'Element est correcte")
{
    SUBCASE("la construction est correcte")
    {
         position*p=new position{1,3};//ou une addresse directement sans le new
         element el{p};
         REQUIRE_EQ(el.positionElement()->numLigne(),1);
         REQUIRE_EQ(el.positionElement()->numColonne(),3);
    }
    SUBCASE("le deplacement de l'element est correcte")
    {
         position*p=new position{1,3};//ou une addresse directement sans le new
         element el{p};
         position*p2=new position{8,10};
         el.deplacerElement(p2);
         REQUIRE_EQ(el.positionElement()->numLigne(),8);
         REQUIRE_EQ(el.positionElement()->numColonne(),10);
         /*delete p;
         delete p2; je suis pas trop sur s'il faut le faire ou pas*/
    }
    SUBCASE("le deplacement a gauche est correcte")
    {
        position*p2=new position{8,10};
         element el{p2};
         el.deplacerElementGauche();
         REQUIRE_EQ(el.positionElement()->numLigne(),8);
         REQUIRE_EQ(el.positionElement()->numColonne(),10-1);
    }
     SUBCASE("le changement de position de l'element est correcte")
    {
         position*p2=new position{8,10};
         element el{p2};
         int col=5;
         int ligne=3;
         el.positionElement()->changerPosition(int col,int ligne);
         REQUIRE_EQ(el.positionElement()->numLigne(),3);
         REQUIRE_EQ(el.positionElement()->numColonne(),5);
    }
    SUBCASE("le deplacement a droite est correcte")
    {
         position*p2=new position{8,10};
         element el{p2};
         el.deplacerElementDroite();
         REQUIRE_EQ(el.positionElement()->numLigne(),8);
         REQUIRE_EQ(el.positionElement()->numColonne(),10+1);
    }
    SUBCASE("le deplacement en haut est correcte")
    {
        position*p2=new position{8,10};
         element el{p2};
         el.deplacerElementHaut();
         REQUIRE_EQ(el.positionElement()->numLigne(),8-1);
         REQUIRE_EQ(el.positionElement()->numColonne(),10);
    }
    SUBCASE("le deplacement en bas est correcte")
    {
        position*p2=new position{8,10};
         element el{p2};
         el.deplacerElementBas();
         REQUIRE_EQ(el.positionElement()->numLigne(),8+1);
         REQUIRE_EQ(el.positionElement()->numColonne(),10);

    }

}
