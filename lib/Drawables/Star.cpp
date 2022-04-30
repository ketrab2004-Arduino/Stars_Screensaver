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
    float speed = .25f;
    pos += Vector2( // move star by direction * delta * speed
        sinf(direction) * delta * speed,
        cosf(direction) * delta * speed
    );

    if (pos.x < 0 || pos.x > tft.width() || // if new pos is outside the screen
        pos.y < 0 || pos.y > tft.height()) {
        pos = Vector2(tft.width() >> 1, tft.height() >> 1); // reset to center (width and height are divided by 2)
        direction = randomDirection(); // generate new random direction
    }
}


float Star::randomDirection()
{
    // direction should be between 0 and 2*PI (1 TAU)
    // random() returns a long, so *1000 and /1000 to get a float
    return random(0, PI * 2000) * 0.001f;
}
