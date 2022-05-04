#ifndef __SIN_LOOKUP_TABLE_H__
#define __SIN_LOOKUP_TABLE_H__

#include <stdint.h>

/**
 * generated using the following js:
```
let text = `static const int8_t lookupTable[${256/4}] = {\n`;
const values = [];

// map 0-360 degrees to 0-255
// divide by 4, because sin is a repeating shape
for (let i = 0; i < 256/4; i++) {
    values[i] = Math.round( // round to int
            Math.sin(i / 255 * Math.PI * 2) // get sin of mapped i value
        * 127 // map -1-1 sin to -127-127 (not exactly -128-127 but good enough)
        );
}

text += values.join(','); // join array into an string, with , inbetween the values
console.log(text + "\n};");
```
*/
static const int8_t lookupTable[64] = {
    0,3,6,9,12,16,19,22,25,28,31,34,37,40,43,46,49,52,54,57,60,63,66,68,71,73,76,78,81,83,86,88,90,92,94,96,98,100,102,104,106,108,109,111,112,114,115,116,118,119,120,121,122,123,123,124,125,125,126,126,126,127,127,127
};


static const int8_t getSin(uint8_t mappedDegrees)
{
    // make sure it's within 0-255
    mappedDegrees %= 256;

    // sin split in half (so above and below 0 are the same)
    uint8_t halved = mappedDegrees % 128;
    
    // get the index of the sin value (1/4 of mappedDegrees)
    uint8_t index = halved % 64;

    // if above half, invert index (so instead of going up, it goes down)
    if (halved > 64) index = 64 - index;

    // get the sin value
    int8_t sin = lookupTable[index];

    // if mappedDegrees is past half, invert index (so instead of going above 0, it goes below)
    return mappedDegrees < 128 ? sin : -sin;
}

static const int8_t getCos(uint8_t mappedDegrees)
{
    // add 64 to get cos (+1 because it isn't completely mirrored (or something idk))
    return getSin(mappedDegrees + 65);
}

#endif