#include <QApplication>
#include "mainwindow.h"

using namespace std;
int main(int argc, char * argv[])
{
   terrain t;
   QApplication app{argc,argv};
   mainwindow f(t);
   f.show();
   app.exec();


}
