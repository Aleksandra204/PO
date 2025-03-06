#ifndef PLAYERCHARACTER_H
#define PLAYERCHARACTER_H

#include "GameObject.h"
#include "Renderable.h"
#include <iostream>

class PlayerCharacter : public GameObject, public Renderable {
public:
    void attack() const override {
        std::cout << "PlayerCharacter attacking!\n";
    }

    void draw() const override {
        std::cout << "PlayerCharacter drawing!\n";
    }

    ~PlayerCharacter() override = default;
};

namespace gutils {

void handleGameObject(GameObject* gameObject) {
    if (auto* pc = dynamic_cast<PlayerCharacter*>(gameObject)) {
        std::cout << "Rendering GameObject\n";
        pc->attack();
    }
}

void handleRenderable(Renderable* renderable) {
    if (auto* pc = dynamic_cast<PlayerCharacter*>(renderable)) {
        std::cout << "Drawing Renderable\n";
        pc->attack();
    }
}
}


#endif
