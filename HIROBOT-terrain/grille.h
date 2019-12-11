#ifndef GRILLE_H
#define GRILLE_H


#include <QWidget>
#include <QHBoxLayout>
#include <QPushButton>
#include <QLabel>
#include <QPainter>
#include <QPaintEvent>
#include <QPen>
#include <QImage>
#include <QMessageBox>


#include "terrain.h"
#include <iostream>
#include <vector>

using namespace std;

class grille:public QWidget{

    Q_OBJECT
public :
    grille(terrain&t,QWidget *parent=nullptr);


private :
    terrain d_terrain;


    void vueCreer();
   // void vueAfficheTerrain();
   void paintEvent(QPaintEvent *e);



};

#endif // GRILLE_H
