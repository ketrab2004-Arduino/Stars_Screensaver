#ifndef __DRAWABLES_START_H__
#define __DRAWABLES_START_H__

#include <stdint.h>
#include <Drawable.h>
#include <Vector2.h>

class Star: public Drawable
{
protected:
    float direction; // float for sinf and cosf

public:
    using Drawable::Drawable; // use Drawable's constructors

    void draw();
    void undraw();
};

#endif