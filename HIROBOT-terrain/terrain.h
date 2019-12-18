#ifndef TERRAIN_H
#define TERRAIN_H


#include "joueur.h"
#include "robot1g.h"
#include "robot2g.h"
#include "debris.h"
#include "time.h"
#include <iostream>
#include <fstream>
#include <vector>


class terrain
{
    friend class grille;
    public:
     terrain(); // terrain vide
     terrain(int nbdebris, int nbrobotfirstG, int nbrobotsecondG, int nbligne, int nbcolonne, joueur j);

     int nbColonne()const;
     int nbLigne()const;
     int nbDebris()const;
     int nbRobot1G()const;
     int nbRobot2G()const;
     joueur Joueur();

     position* positionJoueur();

     void lireTerrain(const std::string&nomFichier); // charge un terrain
     void sauverTerrain(const std::string&nomFichier); // sauvegarde le terrain
     void changerTailleGrille(int nbligne, int nbcolonne); // change la taille de la grille
     void changerNb(); // change le nombre de débris et de robot

     void InitialisationGrille(int nbdebris, int nbRobot1G, int nbRobot2G); // initialise la grille de manière aléatoire
     void deplacementRobot();


     bool JoueurAPerdu();
     bool JoueurAGagne();
     bool terrainOk();

     void supprimerValeurTableau(std::vector <robot*>r,int i);


     void collisionRobotEtDebris();


     void collisionRobotEtRobot();


     void affichePositionJoueur();


    private :

     joueur d_joueur;
     int d_nbligne;
     int d_nbcolonne;
     std::vector<robot*> d_robot;
     std::vector<debris*> d_debris;








};

#endif // TERRAIN_H
