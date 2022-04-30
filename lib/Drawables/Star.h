#ifndef __DRAWABLES_START_H__
#define __DRAWABLES_START_H__

#include <stdint.h>
#include <Adafruit_ILI9341.h>
#include <Drawable.h>
#include <Vector2.h>

class Star: public Drawable
{
protected:
    float direction; // float for sinf and cosf

public:
    // using Drawable::Drawable; // use Drawable's constructors
    Star();
    Star(Vector2 pos, float dir);
    Star(int16_t x, int16_t y, float dir);

    void draw(Adafruit_ILI9341 *tft);
    void undraw(Adafruit_ILI9341 *tft);
    void doStep(unsigned long delta, Adafruit_ILI9341 *tft);

    static float randomDirection();
};

#endif