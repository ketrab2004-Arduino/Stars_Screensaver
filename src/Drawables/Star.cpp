#include "Drawables/Star.h"

namespace Drawables
{

Star::Star(): Drawable() // extend the drawable() constructor
{
    direction = 0;
}

Star::Star(Vector2 pos, uint8_t dir): Drawable(pos) // extend the drawable(pos) constructor
{
    direction = dir;
}

Star::Star(int16_t x, int16_t y, uint8_t dir): Drawable(x, y) // extend the drawable(x, y) constructor
{
    direction = dir;
}


void Star::draw(Adafruit_ILI9341 &tft)
{
    uint8_t dist = distance(tft);
    tft.drawPixel(pos.x, pos.y, tft.color565(dist, dist, dist)); // draw white star
}
void Star::undraw(Adafruit_ILI9341 &tft)
{
    tft.drawPixel(pos.x, pos.y, ILI9341_BLACK); // fill star with black (background colour)
}
void Star::doStep(unsigned long delta, Adafruit_ILI9341 &tft)
{
    float speed = map( // map distance to speed
        distance(tft),
        0, 255, // from range
        STAR_MIN_SPEED, STAR_MAX_SPEED // to range
    ) * 0.00000787401f; // convert back to float (0.001f divided by 127 (because getSin and getCos are * 127))
    
    pos += Vector2( // move star by direction * delta * speed
        speed * getSin(direction) * delta,
        speed * getCos(direction) * delta
    );

    if (pos.x < 0 || pos.x > tft.width() || // if new pos is outside the screen
        pos.y < 0 || pos.y > tft.height()) {
        pos = Vector2(tft.width() >> 1, tft.height() >> 1); // reset to center (width and height are divided by 2)
        direction = randomDirection(); // generate new random direction
    }
}


uint8_t Star::distance(Adafruit_ILI9341 &tft)
{
    int16_t maxDist = (tft.width() + tft.height()) >> 2; // average of width and height, divide by 2 again to get the "radius"

    return min(
        (
            (int32_t)( // cast to int32_t because 128 << 8 = 32768, 32767 is the limit for int16_t
                // subtract to get the difference
                pos - Vector2( tft.width() >> 1, tft.height() >> 1 ) // Vector2 at the center
            ).magnitude()
            << 8 // multiply by 256 (2^8)
        ) / maxDist, // divide to transform to 0-255 range

        (int16_t)255 // cap at 255 (with min() above)
    );
}

uint8_t Star::randomDirection()
{
    // direction should be between 0 and 255 (0-360°)
    return random(0, 255);
}

} // namespace Drawables
