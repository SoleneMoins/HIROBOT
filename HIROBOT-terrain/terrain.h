#ifndef TERRAIN_H
#define TERRAIN_H


#include "joueur.h"
#include "joueurExpert.h"
#include "robot1g.h"
#include "robot2g.h"
#include "debris.h"
#include "time.h"
#include <iostream>
#include <fstream>
#include <vector>

/**
  classe representant un terrain
*/
class terrain
{
    friend class grille;
    public:

    ///Constructeur par défaut: joueur vide, nombre de ligne à 0, nombre de colonne à 0
     terrain();

    /**
         Constructeur avec le nombre de robots, de débris, la taille de la grille et le joueur
         @param nbdebris nombre de debris
         @param nbrobotfirstG nombre de robot de première génération
         @param nbrobotsecondG nombre de robot de la seconde génération
         @param nbligne nombre de ligne du terrain
         @param nbcolonne nombre de colonne du terrain
         @param j le joueur du terrain

     */
     terrain(int nbdebris, int nbrobotfirstG, int nbrobotsecondG, int nbligne, int nbcolonne, joueur& j);

     ///@return le nombre de colonne du terrain
     int nbColonne()const;

     ///@return le nombre de ligne du terrain
     int nbLigne()const;

     ///@return le nombre de debris du terrain
     int nbDebris()const;

     ///@return le nombre de robot1G du terrain
     int nbRobot1G()const;

     ///@return le nombre de robot2G du terrain
     int nbRobot2G()const;

     ///@return le joueur du terrain
     joueur Joueur();

     ///@return la position du joueur
     position* positionJoueur();

     /**
       Supprime la valeur à la place i d'un tableau de robot
       @param r vecteur de robot
       @param i place de la valeur à supprimer
     */
     void supprimerValeurTableauRobot(std::vector <robot*>r,int i);

     /**
       Supprime la valeur i d'un tableau d'entier
       @param V vecteur d'entier
       @param i la valeur à supprimer
     */
     void suppValeurTab(std::vector<int>&V,int i);

     /**
       Charger un terrain à partir d'un fichier
       @param nomFichier nom du fichier
     */
     void lireTerrain(const std::string&nomFichier);

     /**
       Sauvegarder un terrain dans un fichier
       @param nomFichier nom du fichier
     */
     void sauverTerrain(const std::string&nomFichier);

     /**
       Change la taille du terrain
       @param nbligne nouveau nombre de ligne
       @param nbcolonne nouveau nombre de colonne
     */
     void changerTailleGrille(int nbligne, int nbcolonne);

     /**
       Réinitilise les vecteurs de débris et de robots
     */
     void changerNb();

     /**
       Initialise la grille de manière aléatoire
       @param nbdebris nombre de débris
       @param nbRobot1G nombre de robot1G
       @param nbRobot2G nombre de robot2G
     */
     void InitialisationGrille(int nbdebris, int nbRobot1G, int nbRobot2G);

     /**
       Déplace les robots
     */
     void deplacementRobot();

     /**
       Test si le joueur a perdu
     */
     bool JoueurAPerdu();

     /**
       Test si le joueur a gagné
     */
     bool JoueurAGagne();

     /**
       Vérifie que le terrain peut être construit
     */
     bool terrainOk();

     /**
       Renvoie le score du joueur
     */
     int scoreJoueur();

     /**
       Augmente durée vie joueur
     */
     void dureeVie();

     /**
       Test si il y a collision entre un robot et un débris
     */
     void collisionRobotEtDebris();

     /**
       Test si il y a collision entre un robot et un autre robot
     */
     void collisionRobotEtRobot();


     void affichePositionJoueur();


    private :
     /// le joueur
     joueur d_joueur;
     /// le nombre de ligne
     int d_nbligne;
     /// le nombre de colonne
     int d_nbcolonne;
     /// le vecteur de robots
     std::vector<robot*> d_robot;
     /// le vecteur de débris
     std::vector<debris*> d_debris;








};

#endif // TERRAIN_H
