#include"joueur.h"

joueur::joueur():element{nullptr},d_nom{},d_score{0},d_dureeVie{0}
{}

joueur::joueur(position*p,const std::string&nom, int score):element{p},d_nom{nom},d_score{score},d_dureeVie{0}
{}

int joueur::score()const{
    return d_score;

}
void joueur::sauverJoueur(std::ostream &ost) const{
    ost<<"("<<d_nom<<","<<positionElement()<<","<<d_score<<","<<d_dureeVie<<")";
}
void joueur::LireDepuis(std::istream&ist){
    char c;
    ist>>c>>d_nom>>c;
    positionElement()->LireDepuis(ist);
    ist>>c>>d_score>>c>>d_dureeVie>>c;

}
void joueur::calculScore(){
    d_score = d_dureeVie;
}

void joueur::augmenterDureeVie(){
    d_dureeVie++;
}


std::istream&operator>>(std::istream&ist,joueur&j){
j.LireDepuis(ist);
return ist;
}

std::ostream& operator<<(std::ostream&ost, joueur& j){
    j.sauverJoueur(ost);
    return ost;
}


