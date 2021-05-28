#include "vector2f.h"
#include <cmath>

Vector2f::Vector2f(const float& x, const float& y) : _x(x), _y(y)
{
}

float Vector2f::length() const
{
    return std::hypot(_x, _y);
}

Vector2f Vector2f::operator+(const Vector2f &other) const
{
    Vector2f tmpVec { _x + other._x, _y + other._y};
    return tmpVec;
}

Vector2f& Vector2f::operator+=(const Vector2f &other)
{
    _x += other._x;
    _y += other._y;
    return *this;
}

Vector2f operator*(const Vector2f &vec, const float &scale)
{
    Vector2f tmpVec {scale * vec._x, scale * vec._y};
    return tmpVec;
}

Vector2f operator*(const float &scale, const Vector2f &vect)
{
    Vector2f tmpVec = vect * scale;
    return tmpVec;
}
