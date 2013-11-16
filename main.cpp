// layout/main.cpp

#include <QApplication>
#include "RavrProgQt.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    RavrProgQt dlg;
    dlg.show();

    return a.exec();
}



