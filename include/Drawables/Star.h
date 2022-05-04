#ifndef __DRAWABLES_STAR_H__
#define __DRAWABLES_STAR_H__

#include <stdint.h>
#include <Adafruit_ILI9341.h>
#include <Drawables/Drawable.h>
#include <Vector2.h>
#include "settings.h"

namespace Drawables
{

class Star: public Drawable
{
protected:
    uint8_t direction; // uint8_t 0-255 (0-360°)

public:
    Star();
    Star(Vector2 pos, uint8_t dir);
    Star(int16_t x, int16_t y, uint8_t dir);

    void draw(Adafruit_ILI9341 &tft);
    void undraw(Adafruit_ILI9341 &tft);
    void doStep(unsigned long delta, Adafruit_ILI9341 &tft);

    uint8_t distance(Adafruit_ILI9341 &tft);
    static uint8_t randomDirection();
};

} // namespace Drawables

#endif