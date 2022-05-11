#include <Arduino.h>

#include <Adafruit_GFX.h>
#include <Adafruit_ILI9341.h>

#include <settings.h>
#include <Extra_Debug.h>

#include <Drawables/Drawable.h>
#include <Drawables/Star.h>

using namespace Drawables;

Adafruit_ILI9341 tft(TFT_CS, TFT_DC);
Drawable *drawables[STAR_COUNT];


#if SHOW_FPS
    #include <Drawables/Text.h>

    unsigned long lastFpsUpdate = 0;

    String fpsString = "--";
    Text fpsText(5, 5, fpsString.c_str());

    #if SHOW_MINMAX_FPS
        #include <limits.h>

        unsigned long maxFps = 0;
        unsigned long minFps = ULONG_MAX; // unsigned, so -1 is below the minimum, so it will be the maximum

        String minFpsString = "--";
        Text minFpsText(5, 15, minFpsString.c_str());

        String maxFpsString = "--";
        Text maxFpsText(Vector2(5, 25), maxFpsString.c_str()); // Vector2, because otherwise there is an `undefined reference to `vtable for Drawables::Drawable'` error
    #endif
#endif


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
            (int16_t)random(0, tft.width()),
            (int16_t)random(0, tft.height()),
            Star::randomDirection()
        );
    }

    // fill the screen with black space
    tft.fillRect(0, 0, tft.width(), tft.height(), ILI9341_BLACK);
}


void loop() {
    unsigned long delta = millis() - lastMillis;
    lastMillis = millis();


    #if SHOW_FPS
    if (millis() - lastFpsUpdate > FPS_UPDATE_INTERVAL) {
        lastFpsUpdate = millis();

        fpsText.undraw(tft);

        #if SHOW_MINMAX_FPS
            minFpsText.undraw(tft);
            maxFpsText.undraw(tft);
        #endif

        unsigned long fps = 1000 / delta;

        #if SHOW_MINMAX_FPS
            // only check for larger or less fps if 1.5 seconds have passed since the beginning of the program
            if (lastMillis > 1500) {
                if (fps > maxFps) { // set max if fps is higher
                    maxFps = fps;
                    maxFpsString = String(fps);
                    maxFpsText.setText(maxFpsString.c_str());
                }
                if (fps < minFps) { // set min if fps is lower
                    minFps = fps;
                    minFpsString = String(fps);
                    minFpsText.setText(minFpsString.c_str());
                }
            }
        #endif

        fpsString = String(fps);
        fpsText.setText(fpsString.c_str());

        // Text's doStep method is empty
        // fpsText.doStep(delta, tftPtr);

        fpsText.draw(tft);

        #if SHOW_MINMAX_FPS
            minFpsText.draw(tft);
            maxFpsText.draw(tft);
        #endif
    } // end fps interval if
    #endif


    for (size_t i = 0; i < STAR_COUNT; i++) {
        // undraw last step
        drawables[i]->undraw(tft);

        // calculate next step
        drawables[i]->doStep(delta, tft);

        // draw next step
        drawables[i]->draw(tft);
    }
}
