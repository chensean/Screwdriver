#include "qtgui/screwdrivermainwindow.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    ScrewdriverMainWindow w;
    w.show();

    return a.exec();
}
