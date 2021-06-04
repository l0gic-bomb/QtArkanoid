#ifndef BRICKS_H
#define BRICKS_H

#include <QRect>

/*! /brief  */
class Bricks
{
public:
    //! Конструктор по умолчанию
    Bricks(const int& x, const int& y);

    //! Проверка разрушено или нет
    bool isDestroyed();
    //! Устанавливаем разрушенность
    void setDestroyes(const bool& state);
    //! Устанавливаем размеры кирпичика
    void setRect(const QRect& rect);
    //! Берем размеры кирпичика
    QRect getRect();

private:
    bool destroyed;
    QRect currentRect;


};

#endif // BRICKS_H
