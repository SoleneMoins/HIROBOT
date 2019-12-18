#ifndef DEBRIS_H
#define DEBRIS_H
#include<iostream>
#include"element.h"

class debris:public element
{
public:
    debris();
    debris(position*p);
};


#endif // DEBRIS_H
