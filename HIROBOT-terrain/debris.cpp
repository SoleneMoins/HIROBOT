#include"debris.h"

debris::debris(const position&p):d_positionDebris{p} {}
int debris::d_niveauDanger=1;

position debris::positionDebris()const
{
    return d_positionDebris;
}
