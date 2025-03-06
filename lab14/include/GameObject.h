#ifndef GAMEOBJECT_H
#define GAMEOBJECT_H

#include <iostream>
#include <algorithm>
#include <vector>

class GameObject
{
private:
    // static inline std::vector<GameObject *> vec;

protected:
    std::string name;

public:

    virtual ~GameObject() = default;
    //wirtualny destruktor

    virtual void action() const = 0;
    //wirtualna metoda, ktora wymusza jej implementacje w klasach pochodnych

    std::string Name();
    //metoda ktora zwraca name danego obiektu
};

class Updatable
{
public:
    void update();
    //metoda ktora powoduje wypisanie na ekranie odpowiedniego
};

class Renderable : virtual public Updatable
{
public:
    void render();
    //metoda ktora powoduje wypisanie na ekranie odpowiedniego
};

class Collidable : virtual public Updatable
{
public:
    void collide();
    //metoda ktora powoduje wypisanie na ekranie odpowiedniego
};

#endif