#ifndef __DRAWABLE_H__
#define __DRAWABLE_H__

#include <Vector2.h>

class Drawable // abstract
{
protected:
    Vector2 pos;

public:
    virtual void draw() = 0; // = 0 means that this method has to be implemented in the derived class
    virtual void undraw() = 0;

    virtual void doStep(); // no = 0 because this method is optional
};

#endif