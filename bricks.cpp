#include "bricks.h"

Bricks::Bricks(const int& x, const int& y)
{
    destroyed = false;
    currentRect.setSize(QSize(50, 10));
    currentRect.translate(x, y);
}

bool Bricks::isDestroyed()
{
    return destroyed;
}

void Bricks::setDestroyes(const bool &state)
{
    destroyed = state;
}

void Bricks::setRect(const QRect &rect)
{
    currentRect = rect;
}

QRect Bricks::getRect()
{
    return currentRect;
}
