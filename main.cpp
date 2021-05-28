#include <QApplication>
#include "rasterwindow.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    RasterWindow window;
    window.show();
    window.setAnimating(true);

    return a.exec();
}