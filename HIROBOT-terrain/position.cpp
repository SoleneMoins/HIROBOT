#include "position.h"

#include "position.h"

position::position():d_numLigne{0},d_numColonne{0} {}

position::position(int ligne,int colonne):d_numLigne{ligne},d_numColonne{colonne} {}

int position::numColonne()const {return d_numColonne;}

int position::numLigne()const {return d_numLigne;}

void position::changerPosition(int col,int ligne){

    d_numColonne=col;
    d_numLigne=ligne;


}

void position::sauverPosition(std::ostream&ost){
    ost<<"["<<d_numLigne<<","<<d_numColonne<<"]";
}

void position::afficherPosition(std::ostream&ost){
    ost<<d_numLigne<<";"<<d_numColonne<<std::endl;
}
void position::LireDepuis(std::istream&ist){
char ac;
ist>>ac>>d_numColonne>>ac;
ist>>d_numLigne>>ac;
}
std::istream&operator>>(std::istream&ist,position&p){
p.LireDepuis(ist);
return ist;

}
std::ostream& operator<<(std::ostream&ost, position&p){
p.sauverPosition(ost);
return ost;
}











