#ifndef GAMEOBJECT_H
#define GAMEOBJECT_H

class GameObject
{
public:
    virtual void attack() const = 0;
    virtual ~GameObject() = default;
};

#endif
