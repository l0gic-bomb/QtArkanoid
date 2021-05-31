#ifndef MENU_H
#define MENU_H

#include <QDialog>

#include "rasterwindow.h"

namespace Ui {
class Menu;
}

class Menu : public QDialog
{
    Q_OBJECT

public:
    explicit Menu();
    ~Menu();


private:
    Ui::Menu *ui;
    RasterWindow *window;
};

#endif // MENU_H
