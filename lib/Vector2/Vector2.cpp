#include "Vector2.h"

#pragma region Constructors
Vector2::Vector2()
{
    x = 0, y = 0;
};
Vector2::Vector2(int16_t x, int16_t y)
{
    this->x = x;
    this->y = y;
};
Vector2::Vector2(int16_t xy)
{
    x = xy, y = xy;
};
#pragma endregion

#pragma region Operators
Vector2 Vector2::operator+(Vector2& other)
{
    return Vector2(x + other.x, y + other.y);
}
Vector2 Vector2::operator-(Vector2& other)
{
    return Vector2(x - other.x, y - other.y);
}
Vector2 Vector2::operator*(Vector2& other)
{
    return Vector2(x * other.x, y * other.y);
}
Vector2 Vector2::operator/(Vector2& other)
{
    return Vector2(x / other.x, y / other.y);
}
#pragma endregion
