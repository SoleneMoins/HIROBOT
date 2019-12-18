#include "grille.h"
#include "joueur.h"
#include <QApplication>
#include "mainwindow.h"

int main(int argc, char *argv[])
{

   terrain t;


   QApplication app{argc,argv};
    mainwindow f(t);
    f.show();
    app.exec();
}
