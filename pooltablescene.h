/**
 * \file  pooltablescene.h
 * \brief Класс стола на котором будет происходить игра
*/

#ifndef POOLTABLESCENE_H
#define POOLTABLESCENE_H

#include <QPainter>
#include <QWidget>
#include <QKeyEvent>
#include <QEvent>
#include <QVector2D>

#include "rectf.h"

#include "platform.h"

/*! \breif Реализация сцены стола, где будет происходить основные действия*/
class PoolTableScene : public QWidget
{
public:
    //! Конструктор
    explicit PoolTableScene(const RectF& bounds);

    //! Перерасчет позиции мяча
    void updateCurrentPosBall(const float& x, const float& y);
    //! Обновление данных при соударении со стенками
    void ballHitWall(const float &deltaSeconds);
    //! Обновление данных при соударении с плафтормой
    void ballHitPlatform(const float &deltaSeconds);


    //! Перерисовка объектов
    void redraw(QPainter& painter);
    //! Перемещение платформы
    void movePlatform(const int& x);


private:   
    QVector2D _ballPosition;
    QVector2D _ballSpeed;

    const QVector2D _ballSize;
    const RectF _bounds;

    Platform _platform;
};

#endif // POOLTABLESCENE_H
