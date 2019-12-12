#ifndef TERRAIN_H
#define TERRAIN_H


#include "joueur.h"
#include "time.h"
#include <iostream>
#include <fstream>
#include <vector>


class terrain
{
    friend class fenetre;
    public:
     terrain(); // terrain vide
     terrain(int nbdebris, int nbrobotfirstG, int nbrobotsecondG, int nbligne, int nbcolonne, joueur j);

     int nbColonne()const;
     int nbLigne()const;
     int nbDebris()const;
     int nbRobot1G()const;
     int nbRobot2G()const;
     joueur Joueur();
     std::vector<std::vector<int>> grille()const;
     position* positionJoueur();

     void lireTerrain(const std::string&nomFichier); // charge un terrain
     void sauverTerrain(const std::string&nomFichier); // sauvegarde le terrain
     void changerTailleGrille(int nbligne, int nbcolonne); // change la taille de la grille
     void changerNb(int nbdebris,int nbRobot1G,int nbRobot2G); // change le nombre de débris et de robot
     void changerPosJoueur(position*p); //Met à jour la position du joueur dans la grille
     void InitialisationGrille(int nbdebris, int nbRobot1G, int nbRobot2G); // initialise la grille de manière aléatoire
     void ChangerJoueur(joueur&j);
     bool JoueurAPerdu();
     bool terrainOk();


     void afficheGrille(); // fonction test
     void affichePositionJoueur(); //fonction test affichage


    private :
     int d_nbdebris;
     joueur d_joueur;
     int d_nbrobotFirstG;
     int d_nbrobotSecondG;
     int d_nbligne;
     int d_nbcolonne;



     std::vector<std::vector<int>> d_grille; // 0 = vide, 1 = joueur, 2 = robot1G, 3 = robot2G, 4 = debris





};

#endif // TERRAIN_H
