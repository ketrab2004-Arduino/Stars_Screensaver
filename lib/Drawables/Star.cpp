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


void Star::draw(Adafruit_ILI9341 &tft)
{
    tft.writePixel(pos.x, pos.y, ILI9341_WHITE); // draw white star
}
void Star::undraw(Adafruit_ILI9341 &tft)
{
    tft.writePixel(pos.x, pos.y, ILI9341_BLACK); // fill star with black (background colour)
}
void Star::doStep(unsigned long delta, Adafruit_ILI9341 &tft)
{
}
