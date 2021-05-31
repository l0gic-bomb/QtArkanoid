#include "menu.h"
#include "ui_menu.h"

#include <QApplication>

Menu::Menu() : ui(new Ui::Menu)
{
    ui->setupUi(this);
    window = new RasterWindow();

    connect(ui->btnStart, &QPushButton::clicked, [this](){window->show();});
    connect(ui->btnExit, &QPushButton::clicked, [](){qApp->exit();});
}

Menu::~Menu() {
    delete window;
    delete ui;
}


