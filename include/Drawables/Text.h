#ifndef __DRAWABLES_TEXT_H__
#define __DRAWABLES_TEXT_H__

#include <stdint.h>
#include <Adafruit_ILI9341.h>
#include <Drawables/Drawable.h>
#include <Vector2.h>

namespace Drawables
{

class Text: public Drawable
{
protected:
    const char *text;

public:
    Text();
    Text(Vector2 pos, const char *text);
    Text(int16_t x, int16_t y, const char *text);

    void draw(Adafruit_ILI9341 *tft);
    void undraw(Adafruit_ILI9341 *tft);
    void doStep(unsigned long delta, Adafruit_ILI9341 *tft);

    void setText(const char *text);
};

} // namespace Drawables

#endif