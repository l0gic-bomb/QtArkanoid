#ifndef GAMESCENE_H
#define GAMESCENE_H

#include <QPainter>
#include <QWidget>
#include <QKeyEvent>
#include <QVector2D>

#include "rectf.h"
#include "bricks.h"

#include "platform.h"

const int NUMBER_BRICKS = 30;

class GameScene : public QWidget
{
public:
    //! Конструктор
    explicit GameScene(const RectF& bounds);
    //! Деструктор
    ~GameScene();

    //! Перерасчет позиции мяча
    void updateCurrentPosBall(const float& x, const float& y);

    //! Обновление данных при соударении
    void ballHitLet(const float& deltaSeconds);
    //! Обновление данных при соударении со стенками
    void ballHitWall();
    //! Обновление данных при соударении с плафтормой
    void ballHitPlatform();
    //! Обновление данных при соударении с кирпичами
    void ballHitBricks();

    //! Перерисовка объектов
    void redraw(QPainter& painter);
    //! Перемещение платформы
    void movePlatform(const int& x);

    //! Отображение результата игры
    void finishGame(QPainter *painter, const QString& message);

private:
    QVector2D _ballPosition;
    QVector2D _ballSpeed;

    const QVector2D _ballSize;
    const RectF     _boundsScene;

    Bricks   *bricks[NUMBER_BRICKS];
    Platform *_platform;

    //! States Game
    bool _gameWin;
    bool _gameLose;
};

#endif // GAMESCENE_H
