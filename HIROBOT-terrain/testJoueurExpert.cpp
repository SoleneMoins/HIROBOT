#include"doctest.h"
#include "position.h"
#include"joueur.h"
#include<iostream>
#include"joueurExpert.h"

TEST_CASE("la class joueur expert est correcte")
{
    SUBCASE("la construction est correcte")
    {
         position*p=new position{1,3};
           std::string nom="Hirobot";
           int score=10;
          joueur j{p,nom,score};
           REQUIRE_EQ(j.nomJoueur(),nom);
           REQUIRE_EQ(j.score(),score);
           REQUIRE_EQ(j.positionElement()->numLigne(),1);
           REQUIRE_EQ(j.positionElement()->numColonne(),3);
    }
}
