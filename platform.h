/**
 * \file  platfrom.h
 * \brief Класс плафтормы. Задание и изменение параметров плафтормы
*/

#ifndef PLATFORM_H
#define PLATFORM_H

#include <QVector2D>
#include <QRectF>

/*! \brief Класс для изменения данных плафтормы */
class Platform
{
public:
    Platform(const QVector2D& pos, const QVector2D& size, const QVector2D& speed );

    void move();

    // Координаты плафтормы
    //! Установка координаты Y
    void setYPos(const float& posY);
    //! Установка координаты X
    void setXPos(const float& posX);
    //! Возврат координаты X
    float getXPos() const;
    //! Возврат координаты Y
    float getYPos() const;

    // Стороны плафтормы
    //! Возврат верхней стороны
    float getTopSide() const;
    //! Возврат нижней сторны
    //! Возврат правой стороны
    //! Возврат левой сторны

    // Скорость платформы

    //! Установка скорости по Y
    void setYVeclocity(const float& posY);
    //! Установка скорости по X
    void setXVeclocity(const float& posX);
    //! Возврат скорости по X
    float getXVeclocity();
    //! Возврат скорости по Y
    float getYVeclocity();

    // Размер плаформы

    //! Установка координаты Y
    void setYSize(const float& posY);
    //! Установка координаты X
    void setXSize(const float& posX);
    //! Возврат координаты X
    float getXSize();
    //! Возврат координаты Y
    float getYSize();


private:
    QVector2D _sizePlatform;
    QVector2D _velocity;

    QRectF _platform;

    static const int INITIAL_X = 200;
    static const int INITIAL_Y = 360;
};

#endif // PLATFORM_H
