#include "platform.h"

Platform::Platform(const QVector2D &pos, const QVector2D &size, const QVector2D &speed)
    : _sizePlatform(size),
      _velocity(speed),
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
    _platform.setX(posX);
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


// скорость
void Platform::setYVeclocity(const float &posY)
{
    _velocity.setY(posY);
}

void Platform::setXVeclocity(const float &posX)
{
    _velocity.setX(posX);
}

float Platform::getXVeclocity()
{
    return _velocity.x();
}

float Platform::getYVeclocity()
{
    return _velocity.y();
}

//размер
void Platform::setYSize(const float &posY)
{
    _sizePlatform.setY(posY);
}

void Platform::setXSize(const float &posX)
{
    _sizePlatform.setX(posX);
}

float Platform::getXSize()
{
    return _sizePlatform.x();
}

float Platform::getYSize()
{
    return _sizePlatform.y();
}






