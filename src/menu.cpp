#include "menu.h"
#include "ui_menu.h"

#include <QDebug>
#include <QApplication>

Menu::Menu() : ui(new Ui::Menu)
{
    ui->setupUi(this);
    window = nullptr;

    connect(ui->btnStart,    &QPushButton::clicked, this, &Menu::slShowWindow);
    connect(ui->btnExit,     &QPushButton::clicked, [](){qApp->exit();});
    connect(ui->btnSettings, &QPushButton::clicked, this, &Menu::slChangeSettings);
}

Menu::~Menu() {
    if (window != nullptr)
        delete window;
    delete ui;
}

void Menu::slShowWindow()
{
    std::function<void()> newWindow = [this](){
        window = new RasterWindow();
        window->show();
    };

    if (window != nullptr) {
        delete window;
        newWindow();
    } else
        newWindow();
}

void Menu::slChangeSettings()
{
    qDebug() << "work";
}


