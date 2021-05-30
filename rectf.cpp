/**
 * \file  rectf.h
 * \brief Класс формы окна на котором будет происходить игра.
*/

#include "rectf.h"

RectF::RectF(const float& x,const float& y,
             const float& width, const float& height) :
    _origin(x, y),
    _size(width, height)
{
}

float RectF::leftEdge() const
{
    return _origin.x();
}

float RectF::rightEdge() const
{
    return _origin.x() + _size.x();
}

float RectF::topEdge() const
{
    return _origin.y();
}

float RectF::bottomEdge() const
{
    return _origin.y() + _size.y();
}
