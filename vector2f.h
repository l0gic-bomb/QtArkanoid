/**
 * \file  vector2f.h
 * \brief Класс задания координат в двухмерном пространстве
*/

#ifndef VECTOR2F_H
#define VECTOR2F_H

/*! \brief  Класс задания координат в двухмерном пространстве */
class Vector2f
{
public:
    //! Конструктор
    explicit Vector2f(const float& x, const float& y);
    //! Возвращает расстояние между точками, гипотенуза
    float length() const;

    Vector2f  operator+(const Vector2f& other) const;
    Vector2f& operator+=(const Vector2f& other);

public:
    float _x = 0;
    float _y = 0;
};

inline Vector2f operator*(const Vector2f& vec, const float& scale);
inline Vector2f operator*(const float& scale, const Vector2f& vect);

#endif // VECTOR2F_H
