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

#include "rectf.h"
#include "vector2f.h"

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


    //! Перерисовка картинок
    void redraw(QPainter& painter);
    //! Перемещение платформы
    void movePlatform(const int& x);

    Platform _platform;
private:
    Vector2f _ballPosition;
    Vector2f _ballSpeed;

    const Vector2f _ballSize;
    const RectF _bounds;
};

#endif // POOLTABLESCENE_H
