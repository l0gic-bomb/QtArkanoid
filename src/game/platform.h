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
    Platform(const QVector2D& pos, const QVector2D& size, const QVector2D& speed);

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
    float getBottomSide() const;
    //! Возврат правой стороны
    float getLeftSide() const;
    //! Возврат левой сторны
    float getRightSide() const;

    // Скорость платформы
    //! Установка скорости по Y
    void setYVeclocity(const float& posY);
    //! Установка скорости по X
    void setXVeclocity(const float& posX);
    //! Возврат скорости по X
    float getXVeclocity() const;
    //! Возврат скорости по Y
    float getYVeclocity() const;

    // Размер платформы
    //! Установка размеров
    void setSize(const float& posX, const float& posY);
    //! Возврат размеров
    QSizeF getSize() const;
    //! Возврат квадрата
    QRectF getRect() const;

    //! Перемещение плафтформы
    void movePlatform(const int& x);

private:
    QVector2D _velocity;
    QRectF    _platform;
};

#endif // PLATFORM_H
