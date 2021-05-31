#include <QApplication>
#include "menu.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    Menu window;
    window.show();

    return a.exec();
}
