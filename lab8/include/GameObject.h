#ifndef GAMEOBJECT_H
#define GAMEOBJECT_H

#include <iostream>
#include <algorithm>
#include <vector>

class GameObject
{
private:
    // static inline std::vector<GameObject *> vec;
    static std::vector<GameObject *> vec;
protected:
    std::string name;

public:
    static GameObject *addGameObject(GameObject *obj);
    //statyczna metoda ktora dodaje nowy obiekt do vectora vec

    static void destroyGameObject(GameObject *obj);
    //statyczna metoda ktora usuwa podany obiekt z vectora vec

    static void destroyGameObjects();
    //statyczna metoda ktora zwalnia pamiec i czysci caly vector vec

    static std::vector<GameObject *> &ActiveGameObjects();
    //statyczna metoda ktora zwraca wektor vec

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