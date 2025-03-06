#ifndef PLAYER_H
#define PLAYER_H

#include "GameObject.h"

class Player : public GameObject, virtual Renderable, virtual Collidable {
public:
    Player() = default;
    void action() override {
        std::cout << "Performing player-specific action...\n";
    }
};

#endif
