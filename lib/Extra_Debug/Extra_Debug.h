#ifndef __EXTRA_DEBUG__
#define __EXTRA_DEBUG__

#include <settings.h>

// if DEBUG is 0, then all debug functions will not be part of compilation
#if DEBUG
    #define debugBegin(x)   Serial.begin(x)

    #define debugF(x)       Serial.print(F(x))
    #define debuglnF(x)     Serial.println(F(x))

    #define debug(x)        Serial.print(x)
    #define debugln(x)      Serial.println(x)
#else
    #define debugBegin(x)

    #define debugF(x)
    #define debuglnF(x)

    #define debug(x)
    #define debugln(x)
#endif

#define debugVar(s,x)       debugF(s); debugln(x)
#define debugNewline()      debuglnF("");

#endif