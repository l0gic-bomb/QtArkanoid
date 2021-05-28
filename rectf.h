/**
 * \file  rectf.h
 * \brief Класс для квадрата на котором будет происходить игра.
*/

#ifndef RECTF_H
#define RECTF_H

#include "vector2f.h"

/*! \brief Класс для изменения данных плафтормы */
class RectF
{    
public:
    //! Конструктор
    explicit RectF(const float& x,const float& y,
                   const float& width, const float& height);

    //! Возвращение значения левой стенки
    float leftEdge() const;
    //! Возвращение значения правой стенки
    float rightEdge() const;
    //! Возвращение значения верхней стенки
    float topEdge() const;
    //! Возвращение значения нижней стенки
    float bottomEdge() const;

private:
    Vector2f _origin;
    Vector2f _size;
};

#endif // RECTF_H
