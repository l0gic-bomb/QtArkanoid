#ifndef SETTINGSGAME_H
#define SETTINGSGAME_H

#include <QDialog>

namespace Ui {
class SettingsGame;
}

class SettingsGame : public QDialog
{
    Q_OBJECT

public:
    explicit SettingsGame(QWidget *parent = nullptr);
    ~SettingsGame();

private:
    Ui::SettingsGame *ui;
};

#endif // SETTINGSGAME_H
