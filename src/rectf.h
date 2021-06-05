/**
 * \file  rectf.h
 * \brief Класс формы окна на котором будет происходить игра.
*/

#ifndef RECTF_H
#define RECTF_H

#include <QVector2D>

/*! \brief Класс формы окна на котором будет происходить игра */
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
    QVector2D _origin;
    QVector2D _size;
};

#endif // RECTF_H
