#include "Star.h"

Star::Star(): Drawable() // extend the drawable() constructor
{
    direction = 0;
}

Star::Star(Vector2 pos, float dir): Drawable(pos) // extend the drawable(pos) constructor
{
    direction = dir;
}

Star::Star(int16_t x, int16_t y, float dir): Drawable(x, y) // extend the drawable(x, y) constructor
{
    direction = dir;
}


void Star::draw()
{
}
void Star::undraw()
{
}
void Star::doStep()
{
}
