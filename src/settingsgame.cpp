/**
 * \file  settingsgame.h
 * \brief Класс настроек игры.
*/

#include "settingsgame.h"
#include "ui_settingsgame.h"

SettingsGame::SettingsGame(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::SettingsGame)
{
    ui->setupUi(this);
}

SettingsGame::~SettingsGame()
{
    delete ui;
}
