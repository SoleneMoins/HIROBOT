#ifndef POSITION_H
#define POSITION_H

#include <iostream>


class position{
public:
    position();
    position(int ligne,int colonne);
    int numColonne()const;
    int numLigne()const;
    void changerPosition(int col,int ligne);
    void sauverPosition(std::ostream&ost);
    void LireDepuis(std::istream&ist);
    void afficherPosition(std::ostream&ost);
    void DeplacerVers(int lig,int col);

private:
    int d_numLigne;
    int d_numColonne;

};

std::ostream& operator<<(std::ostream&ost, position&p);
std::istream&operator>>(std::istream&ist,position&p);
#endif // POSITION_H
