#include "Drawable.h"

Drawable::Drawable()
{
    pos = Vector2();
}

Drawable::Drawable(Vector2 pos)
{
    this->pos = pos;
}

Drawable::Drawable(int16_t x, int16_t y)
{
    pos = Vector2(x, y);
}
