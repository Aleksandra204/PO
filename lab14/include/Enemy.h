#ifndef ENEMY_H
#define ENEMY_H

#include "GameObject.h"

class Enemy : public GameObject, public Renderable, public Collidable
{
public:
    Enemy();
    //konstruktor domyslny, ustawia name z klasy GameObject na "Unnamed Enemy"

    Enemy(std::string name2);
    //konstruktor, ustawia name z klasy GameObject na podane

    void action() const override;
    //nadpisana metoda z klasy GameObject, powoduje wywolanie odpowiednich metod z klas Renderable, Collidable i Updatable
};

#endif