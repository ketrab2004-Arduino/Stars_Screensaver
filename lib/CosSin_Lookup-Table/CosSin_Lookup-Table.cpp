#include "CosSin_Lookup-Table.h"

const int8_t getSin(uint8_t mappedDegrees)
{
    // make sure it's within 0-255
    mappedDegrees %= 256;

    if (mappedDegrees < 64) {
        return lookupTable[mappedDegrees];

    } else if (mappedDegrees < 128) {
        return lookupTable[64 - mappedDegrees];

    } else if (mappedDegrees < 192) {
        return -lookupTable[mappedDegrees];

    } else {
        return -lookupTable[64 - mappedDegrees];
    }

    // // sin split in half (so above and below 0 are the same)
    // uint8_t halved = mappedDegrees % 129;

    // // get the index of the sin value (1/4 of mappedDegrees)
    // uint8_t index = halved % 65;

    // // if above half, invert index (so instead of going up, it goes down)
    // if (halved > 64) index = 63 - index;

    // // get the sin value
    // int8_t sin = lookupTable[index];

    // // if mappedDegrees is past half, invert index (so instead of going above 0, it goes below)
    // return mappedDegrees < 128 ? sin : -sin;
}

const int8_t getCos(uint8_t mappedDegrees)
{
    // add 64 to get cos (+1 because it isn't completely mirrored (or something idk))
    return getSin(mappedDegrees + 65);
}
