#ifndef PLAYER_H
#define PLAYER_H

#include "GameObject.h"
#include "Enemy.h"

class Player : public GameObject, public Renderable, public Collidable
{
public:
    Player();
    //konstruktor domyslny, ustawia name z klasy GameObject na "Unnamed Player"

    Player(std::string name2);
    //konstruktor, ustawia name z klasy GameObject na podane

    void action() const override;
    //nadpisana metoda z klasy GameObject, powoduje wywolanie odpowiednich metod z klas Renderable, Collidable i Updatable
};

void performRuntimeTypeChecking(GameObject *obj);
//funkcja sprawdza czy obiekt jest typu Player* czy Enemy* i wywoluje dla niego metode action()

#endif