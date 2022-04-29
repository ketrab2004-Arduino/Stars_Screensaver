#include "Vector2.h"

#pragma region Constructors
Vector2::Vector2() { x = 0, y = 0; }
Vector2::Vector2(int16_t x, int16_t y) { this->x = x, this->y = y; }
Vector2::Vector2(int16_t xy) { x = xy, y = xy; }
#pragma endregion

#pragma region Operators
Vector2::operator String() const { return "(", String(x) + ", " + String(y) + ")"; }

// Comparison
bool Vector2::operator==(Vector2 &other) { return x == other.x && y == other.y; }
bool Vector2::operator!=(Vector2 &other) { return x != other.x || y != other.y; }
// Increment/Decrement
void Vector2::operator++() { x++, y++; }
void Vector2::operator--() { x--, y--; }

#pragma region arithmetic (Vector2)
Vector2 Vector2::operator+(Vector2 &other) { return Vector2(x + other.x, y + other.y); }
void Vector2::operator+=(Vector2 &other) { x += other.x, y += other.y; }

Vector2 Vector2::operator-(Vector2 &other) { return Vector2(x - other.x, y - other.y); }
void Vector2::operator-=(Vector2 &other) { x -= other.x, y -= other.y; }

Vector2 Vector2::operator*(Vector2 &other) { return Vector2(x * other.x, y * other.y); }
void Vector2::operator*=(Vector2 &other) { x *= other.x, y *= other.y; }

Vector2 Vector2::operator/(Vector2 &other) { return Vector2(x / other.x, y / other.y); }
void Vector2::operator/=(Vector2 &other) { x /= other.x, y /= other.y; }
#pragma endregion

#pragma region arithmetic (int16_t)
Vector2 Vector2::operator+(int16_t other) { return Vector2(x + other, y + other); }
void Vector2::operator+=(int16_t other) { x += other, y += other; }

Vector2 Vector2::operator-(int16_t other) { return Vector2(x - other, y - other); }
void Vector2::operator-=(int16_t other) { x -= other, y -= other; }

Vector2 Vector2::operator*(int16_t other) { return Vector2(x * other, y * other); }
void Vector2::operator*=(int16_t other) { x *= other, y *= other; }

Vector2 Vector2::operator/(int16_t other) { return Vector2(x / other, y / other); }
void Vector2::operator/=(int16_t other) { x /= other, y /= other; }
#pragma endregion

#pragma endregion
