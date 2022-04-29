#ifndef __VECTOR2_H__
#define __VECTOR2_H__

#include <Arduino.h>
#include <stdint.h>

struct Vector2
{
    int16_t x;
    int16_t y;

    Vector2();
    Vector2(int16_t x, int16_t y);
    Vector2(int16_t xy);


    int16_t magnitude();
    int16_t sqrMagnitude();
    Vector2 normalized();


    #pragma region Operators
    bool operator==(Vector2 &other);
    bool operator!=(Vector2 &other);

    void operator++();
    void operator--();

    operator String() const;


    Vector2 operator+(Vector2 &other);
    void operator+=(Vector2 &other);

    Vector2 operator-(Vector2 &other);
    void operator-=(Vector2 &other);

    Vector2 operator*(Vector2 &other);
    void operator*=(Vector2 &other);

    Vector2 operator/(Vector2 &other);
    void operator/=(Vector2 &other);


    Vector2 operator+(int16_t other);
    void operator+=(int16_t other);

    Vector2 operator-(int16_t other);
    void operator-=(int16_t other);

    Vector2 operator*(int16_t other);
    void operator*=(int16_t other);

    Vector2 operator/(int16_t other);
    void operator/=(int16_t other);
    #pragma endregion
};

#endif