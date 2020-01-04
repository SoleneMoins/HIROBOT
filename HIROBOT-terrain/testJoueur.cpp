#include"joueur.h"
#include"doctest.h"
#include"element.h"
#include<iostream>
#include"joueur.h"
TEST_CASE("le test du joueur est correcte")
{
    SUBCASE("la construction du joueur par defaut  est correcte")
      {
        joueur j{};
        REQUIRE_EQ(j.score(),0);
        REQUIRE_EQ(j.nomJoueur(),"");
        REQUIRE_EQ(j.positionElement()->numLigne(),0);
        REQUIRE_EQ(j.positionElement()->numColonne(),0);
      }
    SUBCASE("la construction du joueur est correcte")
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
   SUBCASE("le score du joueur est correcte")
      {
          position*p=new position{1,3};
           std::string nom="Hirobot";
           int score=10;
          joueur j{p,nom,score};
          REQUIRE_EQ(j.score(),10);
      }
   SUBCASE("L'augmentation de la durée de vie est correct")
      {
           position*p=new position{1,3};
           std::string nom="Hirobot";
           int score=10;
          joueur j{p,nom,score};
          j.augmenterDureeVie();
          REQUIRE_EQ(j.dureeVie(),1);

      }
   SUBCASE("le nom du joueur est correcte")
      {
           position*p=new position{1,3};
           std::string nom="Hirobot";
           int score=10;
          joueur j{p,nom,score};
          REQUIRE(j.nomJoueur(),nom);
      }
   SUBCASE("la durée de vie est correcte")
      {
           position*p=new position{1,3};
           std::string nom="Hirobot";
           int score=10;
          joueur j{p,nom,score};
          REQUIRE_EQ(j.dureeVie(),0);

      }
   SUBCASE("la position du joueur est correcte")
      {
           position*p=new position{1,3};
           std::string nom="Hirobot";
           int score=10;
          joueur j{p,nom,score};
          REQUIRE_EQ(j.positionElement()->numLigne(),1);
         REQUIRE_EQ(j.positionElement()->numColonne(),3);
      }
   SUBCASE("la savegarde du joueur est corecte")
      {
          std::string formatAttendu="(Hirobot,[1;3],10,0)";
           position*p=new position{1,3};
           std::string nom="Hirobot";
           int score=10;
          joueur j{p,nom,score};
          std::ostringstream ost{};
          ost<<j;
          std::string contenuSauver=ost.str();
          REQUIRE_EQ(contenuSauver==formatAttendu);

      }
   SUBCASE("la lecture du joueur est correcte")
      {
          std::string formatAttendu="(Hirobot,[1;3],10,0)";
          position*p=new position{1,3};
           std::string nom="Hirobot";
           int score=10;
          joueur j{p,nom,score};
          std::istringstream lecteur(formatLecture);
          lecteur>>j;
          REQUIRE_EQ(j.nomJoueur(),nom);
          REQUIRE_EQ(j.score(),score);
         REQUIRE_EQ(j.positionElement()->numLigne(),1);
         REQUIRE_EQ(j.positionElement()->numColonne(),3);
      }
}
