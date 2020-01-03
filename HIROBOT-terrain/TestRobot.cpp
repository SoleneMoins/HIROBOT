#include "robot.h"
#include "doctest.h"
#include "robot2g.h"

TEST_CASE("la construction du robot par defaut  est correcte")
      {
        robot r{};
        REQUIRE_EQ(j.positionElement()->numLigne(),0);
        REQUIRE_EQ(j.positionElement()->numColonne(),0);
      }

TEST_CASE("la construction du joueur est correcte")
      {
           position*p=new position{2,4};
          joueur j{p,nom,score};
           REQUIRE_EQ(j.positionElement()->numLigne(),2);
           REQUIRE_EQ(j.positionElement()->numColonne(),4);
      }
TEST_CASE   ("La collison d'un robot est correct"){

    position positionRobot{1,4};
    robot r{positionRobot};

    SUBCASE(" Avec un robot"){

     position positionRobot2{1,4};
     robot r2 {positionRobot2};
     REQUIRE_EQ(r.CollisionRobot(r2),true);
    }
    SUBCASE ("Avec un joueur "){

        position positionJoueur{1,4};
        joueur j {positionJoueur};
        REQUIRE_EQ(r.CollisionJoueur(j),true);
    }
    SUBCASE ("Avec un debris "){

        position positionDebris{1,4};
        debris d {positionDebris};
        REQUIRE_EQ(r.CollisionDebris(d),true);
    }
}


