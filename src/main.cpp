#include <Arduino.h>

#include <Adafruit_GFX.h>
#include <Adafruit_ILI9341.h>

#include <settings.h>
#include <Extra_Debug.h>

#include <Drawables/Drawable.h>
#include <Drawables/Star.h>

using namespace Drawables;

Adafruit_ILI9341 tft(TFT_CS, TFT_DC);
Adafruit_ILI9341 *tftPtr = &tft;

Drawable *drawables[STAR_COUNT];

unsigned long lastMillis = millis();

void setup() {
    debugBegin(9600);
    tft.begin();

    // set tft brightness
    pinMode(TFT_BL, OUTPUT);
    analogWrite(TFT_BL, TFT_BRIGHTNESS);

    // if analog input pin 0 is unconnected, random analog
    // noise will cause the call to randomSeed() to generate
    // different seed numbers each time the sketch runs.
    // randomSeed() will then shuffle the random function.
    // https://www.arduino.cc/reference/en/language/functions/random-numbers/random/
    randomSeed(analogRead(0));

    // initialize stars
    for (size_t i = 0; i < STAR_COUNT; i++) {
        drawables[i] = new Star( // replace each null pointer with a Star*
            // (int16_t)random(0, tft.width()),
            // (int16_t)random(0, tft.height()),
            // Star::randomDirection()
        );
    }

    // fill the screen with black space
    tft.fillRect(0, 0, tft.width(), tft.height(), ILI9341_BLACK);
}

void loop() {
    unsigned long delta = millis() - lastMillis;
    lastMillis = millis();

    // prepare for writing
    tft.startWrite();

    for (size_t i = 0; i < STAR_COUNT; i++) {
        // undraw last step
        drawables[i]->undraw(tftPtr);

        // calculate next step
        drawables[i]->doStep(delta, tftPtr);

        // draw next step
        drawables[i]->draw(tftPtr);
    }

    // end writing
    tft.endWrite();
}
