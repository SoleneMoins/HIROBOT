#include "doctest.h"
#include "robot2g.h"

 TEST_CASE("Test de deplacements robot version 2")
 {
     position *positionRobot= new position{2,2};
     robot2G r{positionRobot};
     joueur j {};

    SUBCASE("Deplacer un robot en diagognale inferieure gauche est correct"){
      position *positionJoueur= new position{1,1};
      joueur j{positionJoueur,"",0};
      r.deplacerRobot(j);
      REQUIRE_EQ(r.positionElement(),j.positionElement());
    }

    SUBCASE("Deplacer un robot en diagognale inferieure droite est correct"){
      position *positionJoueur= new position{1,3};
      joueur j{positionJoueur,"",0};
      r.deplacerRobot(j);
      REQUIRE_EQ(r.positionElement(),j.positionElement());
    }

    SUBCASE("Deplacer un robot en diagognale superieure gauche est correct"){
      position *positionJoueur= new position{1,3};
      joueur j{positionJoueur,"",0};
      r.deplacerRobot(j);
      REQUIRE_EQ(r.positionElement(),j.positionElement());
    }

    SUBCASE("Deplacer un robot en  diagognale superieure droite est correct"){
      position *positionJoueur= new position{3,3};
      joueur j{positionJoueur,"",0};
      r.deplacerRobot(j);
      REQUIRE_EQ(r.positionElement(),j.positionElement());
    }
 }
