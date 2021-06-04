/**
 * \file  settingsgame.h
 * \brief Класс настроек игры.
*/
#ifndef SETTINGSGAME_H
#define SETTINGSGAME_H

#include <QDialog>

namespace Ui {
class SettingsGame;
}

/*! /brief Класс настроек игры */
class SettingsGame : public QDialog
{
    Q_OBJECT

public:
    //! Конструктор
    explicit SettingsGame(QWidget *parent = nullptr);
    //! Деструктор
    ~SettingsGame();

private:
    Ui::SettingsGame *ui;
};

#endif // SETTINGSGAME_H
