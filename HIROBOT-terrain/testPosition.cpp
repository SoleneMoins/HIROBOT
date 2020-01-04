#include"doctest.h"
#include "position.h"
#include<sstream>
#include<iostream>
TEST_CASE("test de la class position ")
{
   int coordX=5;
   int coordY=2;
  SUBCASE("la construction de la position est correcte")
     {
         position p{coordX,coordY};
         REQUIRE_EQ(p.numLigne(),coordX);
         REQUIRE_EQ(p.numColonne(),coordY);

     }
  SUBCASE("la construction par defaut est correct")
     {
         position p1{};
         REQUIRE_EQ(p1.numLigne(),0);
         REQUIRE_EQ(p1.numColonne(),0);
     }
  SUBCASE("coordonné X est correcte")
     {
          position p{coordX,coordY};
          REQUIRE_EQ(p.numLigne(),5);
     }
  SUBCASE("coordonnée Y est correcte")
     {
          position p{coordX,coordY};
          REQUIRE_EQ(p.numColonne(),2)
     }
  SUBCASE("le changement de position est correcte")
     {
         position p{coordX,coordY};
         position pDestination{1,3};
         p.changerPosition(pDestination.numColonne(),pDestination.numLigne());
         REQUIRE_EQ(p.numColonne(),pDestination.numColonne());
         REQUIRE_EQ(p.numLigne(),pDestination.numLigne());
     }
  SUBCASE("la lecture de la position est correct")
     {
         position p{};
         std::string formatLecture="[5;2]";
         std::istringstream lecteur(formatLecture);
         lecteur>>p;//je prends les info dans formatlecture et je les mets dans p;
         //ou p.sauverPosition(lecteur) a la place de lecteur>>p;
         REQUIRE_EQ(p.numligne(),5);
         REQUIRE_EQ(p.numCoonne(),2);
     }
  SUBCASE("la sauvegarde est corecte")
     {
          position p{coordX,coordY};
          std::string formatAttendu="[5;2]";
          /*string contenu;
          std::ostringstream ost{contenu};
         ost<<p;
          REQUIRE_EQ(formatAttendu==contenu);*/
          std::ostringstream ost{};
          ost<<p;
          std::string contenuSauver=ost.str();//je recupere ce que je viens d'afficher sur le fleau(le point bien construit)
          REQUIRE_EQ(contenuSauver==formatAttendu);//ce sera bon car pd l'affichage je vais aussi afficher les crochets


     }

}

