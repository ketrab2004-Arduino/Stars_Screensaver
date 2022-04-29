#include <Arduino.h>

#include <Adafruit_GFX.h>
#include <Adafruit_ILI9341.h>

#include <settings.h>
#include <Extra_Debug.h>

Adafruit_ILI9341 tft(TFT_CS, TFT_DC);

void setup() {
    debugBegin(9600);
    tft.begin();

    // fill the screen with black space
    tft.fillRect(0, 0, tft.width(), tft.height(), ILI9341_BLACK);
}

void loop() {
    
}