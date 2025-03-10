#ifndef RENDERABLE_H
#define RENDERABLE_H

class Renderable
{
public:
    virtual void draw() const = 0;
    virtual ~Renderable() = default;
};

#endif
