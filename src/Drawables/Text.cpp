#include "Drawables/Text.h"

namespace Drawables
{

Text::Text(): Drawable() // extend the drawable() constructor
{
    text = nullptr;
}

Text::Text(Vector2 pos, const char *text): Drawable(pos) // extend the drawable(pos) constructor
{
    this->text = text;
}

Text::Text(int16_t x, int16_t y, const char *text): Drawable(x, y) // extend the drawable(x, y) constructor
{
    this->text = text;
}


void Text::draw(Adafruit_ILI9341 *tft)
{
    tft->setTextColor(ILI9341_WHITE);
    tft->setCursor(pos.x, pos.y);
    tft->print(text);
}

void Text::undraw(Adafruit_ILI9341 *tft)
{
    tft->setTextColor(ILI9341_BLACK);
    tft->setCursor(pos.x, pos.y);
    tft->print(text);
}

void Text::doStep(unsigned long delta, Adafruit_ILI9341 *tft)
{} // do nothing


void Text::setText(const char *text)
{
    this->text = text;
}

} // namespace Drawables
