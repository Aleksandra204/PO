#ifndef ENEMY_H
#define ENEMY_H

#include "GameObject.h"

class Enemy : public GameObject, virtual Renderable, virtual Collidable{
public:
    Enemy() = default;
    void action() override {
        std::cout << "Performing enemy-specific action...\n";
    }
};

#endif