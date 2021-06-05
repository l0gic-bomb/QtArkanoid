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
    //! Конструктор
    explicit Menu();
    //! Деструктор
    ~Menu();

private slots:
    void slShowWindow();     //!<
    void slChangeSettings(); //!<

private:
    Ui::Menu *ui;
    RasterWindow *window;
};

#endif // MENU_H
