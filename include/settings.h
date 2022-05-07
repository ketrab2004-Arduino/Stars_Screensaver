#ifndef __SETTINGS_H__
#define __SETTINGS_H__

#define DEBUG 1

#define TFT_CS 10
#define TFT_DC 9
#define TFT_BL 5
// #define SD_CS  4

#define TFT_BRIGHTNESS 255

#define STAR_COUNT 32
#define STAR_MIN_SPEED 200 // pixels per second
#define STAR_MAX_SPEED 400

#define SHOW_FPS 1

#if SHOW_FPS // only when fps is shown
    #define SHOW_MINMAX_FPS 0
#endif

#endif