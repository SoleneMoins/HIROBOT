#include "doctest.h"
#include "robot1g.h"

 TEST_CASE("Test de deplacements robot version 1")
 {
     position *positionRobot= new position{2,2};
     robot1G r{positionRobot};
     joueur j {};

    SUBCASE("Deplacer un robot à droite est correct"){
      position *positionJoueur= new position{2,3};
      joueur j{positionJoueur,"",0};
      r.deplacerRobot(j);
      REQUIRE_EQ(r.positionElement(),j.positionElement());
    }

    SUBCASE("Deplacer un robot à gauche est correct"){

      position *positionJoueur= new position{2,1};
      joueur j{positionJoueur,"",0};
      r.deplacerRobot(j);
      REQUIRE_EQ(r.positionElement(),j.positionElement());
    }

    SUBCASE("Deplacer un robot en haut est correct"){

      position *positionJoueur= new position{3,2};
      joueur j{positionJoueur,"",0};
      r.deplacerRobot(j);
      REQUIRE_EQ(r.positionElement(),j.positionElement());
    }

    SUBCASE("Deplacer un robot en bas est correct"){

      position *positionJoueur= new position{1,2};
      joueur j{positionJoueur,"",0};
      r.deplacerRobot(j);
      REQUIRE_EQ(r.positionElement(),j.positionElement());
    }
 }
