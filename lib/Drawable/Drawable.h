#ifndef __DRAWABLE_H__
#define __DRAWABLE_H__

class Drawable // abstract
{
public:
    virtual void draw() = 0; // = 0 means that this function has to be implemented in the derived class
    virtual void undraw() = 0;

    virtual void doStep(); // no = 0 because this function is optional
};

#endif