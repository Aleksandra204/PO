#include "Player.h"

Player::Player(){
    GameObject::name = "Unnamed Player";
}

Player::Player(std::string name2){
    GameObject::name = name2;
}

void Player::action() const
{
    auto casted = dynamic_cast<const Renderable &>(*this);
    casted.render();
    casted.update();
}

/////////////////////////////////////////////////
void performRuntimeTypeChecking(GameObject *obj)
{
    if (dynamic_cast<const Player *>(obj) != nullptr)
    {
        std::cout << "Player object is renderable collidable" << std::endl;
    }
    else if (dynamic_cast<const Enemy *>(obj) != nullptr)
    {
        std::cout << "Enemy object is renderable collidable updatable" << std::endl;
    }
    else
    {
        return;
    }
}