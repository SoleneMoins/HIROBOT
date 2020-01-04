#include "terrain.h"


terrain::terrain():d_joueur{},d_nbligne{0},d_nbcolonne{0}
{}

terrain::terrain(int nbdebris,int nbrobotfirstG, int nbrobotsecondG, int nbligne, int nbcolonne, joueur j):d_joueur{j},d_nbligne{nbligne},d_nbcolonne{nbcolonne}
{

    if(terrainOk()){

         InitialisationGrille(nbdebris,nbrobotfirstG,nbrobotsecondG);

    }
}

void terrain::sauverTerrain(const std::string& nomFichier){

   std::ofstream f (nomFichier, std::ofstream::out);
    f << d_joueur << ","<< d_debris.size() << ","<< nbRobot1G() << ","<< nbRobot2G() << "," << d_nbligne << "," << d_nbcolonne;

    for(auto r:d_robot){
        f<<r;
    }

    for(auto d:d_debris){
        f<<d;
    }

    f.close();




}

int terrain::nbColonne()const{
    return d_nbcolonne;
}

int terrain::nbLigne()const{
    return d_nbligne;
}

int terrain::nbDebris()const{
     return static_cast<int>(d_debris.size());

}

int terrain::nbRobot1G()const{
    int compt=0;
        for(auto r:d_robot){
            if(r->type()==0){
                compt++;
            }
        }
        return compt;
}

int terrain::nbRobot2G()const{
    int compt=0;
        for(auto r:d_robot){
            if(r->type()==1){
                compt++;
            }
        }
        return compt;
}



joueur terrain::Joueur(){
    return d_joueur;
}



void terrain::lireTerrain(const std::string&nomFichier)
{
        std::ifstream f(nomFichier);
        char c;
        int nb_debris;
        int nb1G;
        int nb2G;
        f >> d_joueur >> c >> nb_debris >> c >> nb1G >> c >> nb2G >> c >> d_nbligne >> c >> d_nbcolonne;
        InitialisationGrille(nb_debris,nb1G,nb2G);
}

position* terrain::positionJoueur(){
    return d_joueur.positionElement();
}

void terrain::changerTailleGrille (int nbligne, int nbcolonne){

 d_nbligne = nbligne;
 d_nbcolonne = nbcolonne;

}

void terrain::changerNb(){

    d_robot.clear();
    d_debris.clear();
}

void terrain::deplacementRobot(){

    for(int i=0;i<static_cast<int>(d_robot.size());++i){
            d_robot[static_cast<unsigned>(i)]->deplacerRobot(d_joueur);
            d_robot[static_cast<unsigned>(i)]->affichePosition();//Test

        }

    collisionRobotEtRobot();
    collisionRobotEtDebris();


}

void terrain::supprimerValeurTableauRobot(std::vector <robot*>r,int i){

    for(int g=i;g<static_cast<int>(r.size()-1);++g){
         std::swap(r[static_cast<unsigned>(g)],r[static_cast<unsigned>(g+1)]);
    }
     r.pop_back();
}


void terrain::suppValeurTab(std::vector<int>&V,int i){

    for(int j = 0;j<V.size();j++){
        if(V[j]==i){
            for(int d=j;d<V.size()-1;d++){
                std::swap(V[d],V[d+1]);
            }
            V.pop_back();
        }
    }
}


//Problème avec une valeur à 0 quand il la génère en premier, à corriger
void terrain::InitialisationGrille(int nbdebris, int nbRobot1G, int nbRobot2G){

    changerNb();
    std::vector<int> V(14);
    V = { 0,0,0,0,0,0,1,0,2,0,3,0,4,0 };

    int compteurJoueur = 0, compteurRobot1G = 0, compteurRobot2G = 0, compteurDebris = 0, compteurZero = 0;

    srand(time(NULL));

    for(int i=0;i<d_nbligne;++i){
        for(int j=0;j<d_nbcolonne;++j){

            int indice = rand()%static_cast<int>(V.size());
            int nbalea = V[static_cast<unsigned>(indice)];


            if(nbalea==0){++compteurZero;}
            if(nbalea==1){
                d_joueur.deplacerElement(new position{j,i});
                ++compteurJoueur;}
            if(nbalea==2){
                d_robot.push_back(new robot1G(new position{j,i}));
                ++compteurRobot1G;}
            if(nbalea==3){
                d_robot.push_back(new robot2G(new position{j,i}));
                ++compteurRobot2G;}
            if(nbalea==4){
                d_debris.push_back(new debris(new position{j,i}));
                ++compteurDebris;}


            if(compteurZero==(d_nbligne*d_nbcolonne)-(nbdebris+nbRobot1G+nbRobot2G+1)){

                int v = 10;
                while(v>0){

                   suppValeurTab(V,0);
                   --v;
                 }
                 compteurZero += 1;
            }


            if(compteurRobot1G==nbRobot1G){

                 suppValeurTab(V,2);
                 compteurRobot1G = nbRobot1G+1;
            }
            if(compteurRobot2G==nbRobot2G){

                 suppValeurTab(V,3);
                 compteurRobot2G += 1;

            }

            if(compteurDebris==nbdebris){

                 suppValeurTab(V,4);
                 compteurDebris += nbdebris+1;
            }

            if(compteurJoueur==1){

                 suppValeurTab(V,1);
                 compteurJoueur += 2;

            }

        }
    }

    sauverTerrain(":/sauvegarde/Sauvegarde/sauv.txt");


}





bool terrain::JoueurAPerdu(){

    for(auto r1:d_robot){
                if(r1->collision(d_joueur)){
                    return true;
                }
            }


        for(auto d:d_debris){
            if(d->collision(d_joueur)){
                return true;
            }
        }

        return false;

}




bool terrain::terrainOk(){

    if(d_nbligne*d_nbcolonne>nbDebris()+static_cast<int>(d_robot.size())+1){
            return true;
        }else{
            return false;
        }


}

bool terrain::JoueurAGagne(){
    return(d_robot.size()==0);
}



void terrain::collisionRobotEtDebris(){

    for(int i=0;i<static_cast<int>(d_robot.size());++i){
        for(int j=0;j<static_cast<int>(d_debris.size());++j){
            if(d_robot[static_cast<unsigned>(i)]->collision(*d_debris[static_cast<unsigned>(j)])){

                std::cout<<"robot detruit"<<std::endl; //Test

               // supprimerValeurTableauRobot(d_robot,i);


              for(int g=i;g<static_cast<int>(d_robot.size()-1);++g){
                    d_robot[static_cast<unsigned>(g)]=d_robot[static_cast<unsigned>(g+1)];
                }
                d_robot.pop_back();

            }
        }
    }

}


void terrain::collisionRobotEtRobot(){

    for(int i=0;i<static_cast<int>(d_robot.size());++i){
        for(int j=i+1;j<static_cast<int>(d_robot.size());++j){
            if(d_robot[static_cast<unsigned>(i)]->collision(*d_robot[static_cast<unsigned>(j)])){

                std::cout<<"collision 2 robots"<<std::endl; //Test
                position*p=d_robot[static_cast<unsigned>(i)]->positionElement();

               // supprimerValeurTableau(d_robot,i);
               // supprimerValeurTableau(d_robot,j);

                for(int g=i;g<static_cast<int>(d_robot.size()-1);++g){
                    d_robot[static_cast<unsigned>(g)]=d_robot[static_cast<unsigned>(g+1)];
                }
                d_robot.pop_back();

                for(int g=j;g<static_cast<int>(d_robot.size()-1);++g){
                    d_robot[static_cast<unsigned>(g)]=d_robot[static_cast<unsigned>(g+1)];
                }
                d_robot.pop_back();

                d_debris.push_back(new debris(p));

            }
        }
    }

}




//Fonction test

void terrain::affichePositionJoueur(){

    std::cout<<d_joueur<<std::endl;

}


