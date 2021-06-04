#include "platform.h"

Platform::Platform(const QVector2D &pos, const QVector2D &size, const QVector2D &speed)
    : _velocity(speed),
      _platform(QPoint(pos.x(), pos.y()), QSizeF(size.x(), size.y()))
{
}

// Координаты
void Platform::setYPos(const float &posY)
{
    _platform.setY(posY);
}

void Platform::setXPos(const float &posX)
{
    _platform.moveTopLeft(QPointF(posX,_platform.y()));
}

float Platform::getXPos() const
{  
    return _platform.x();
}

float Platform::getYPos() const
{
    return _platform.y();
}

// Стороны
float Platform::getTopSide() const
{
    return _platform.top();
}

float Platform::getBottomSide() const
{
    return _platform.bottom();
}

float Platform::getLeftSide() const
{
    return _platform.left();
}

float Platform::getRightSide() const
{
    return _platform.right();
}

// Скорость
void Platform::setYVeclocity(const float &posY)
{
    _velocity.setY(posY);
}

void Platform::setXVeclocity(const float &posX)
{
    _velocity.setX(posX);
}

float Platform::getXVeclocity() const
{
    return _velocity.x();
}

float Platform::getYVeclocity() const
{
    return _velocity.y();
}

// Размеры квадрата
void Platform::setSize(const float &posX, const float &posY)
{
    _platform.setSize(QSizeF(posX, posY));
}

QSizeF Platform::getSize() const
{
    return _platform.size();
}

QRectF Platform::getRect() const
{
    return _platform;
}

void Platform::movePlatform(const int &x)
{
    _platform.moveTopLeft(QPointF(_platform.x() + x, _platform.y()));
}







