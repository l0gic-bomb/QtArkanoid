#include "rectf.h"

RectF::RectF(const float& x,const float& y,
             const float& width, const float& height) :
    _origin(x, y),
    _size(width, height)
{
}

float RectF::leftEdge() const
{
    return _origin._x;
}

float RectF::rightEdge() const
{
    return _origin._x + _size._x;
}

float RectF::topEdge() const
{
    return _origin._y;
}

float RectF::bottomEdge() const
{
    return _origin._y + _size._y;
}
