#include "Enemy.h"

Enemy::Enemy(){
    GameObject::name = "Unnamed Enemy";
}

Enemy::Enemy(std::string name2){
    GameObject::name = name2;
}

void Enemy::action() const
{
    std::cout << "Performing enemy-specific action for " << GameObject::name << std::endl;

    auto casted = dynamic_cast<const Renderable &>(*this);
    casted.render();

    auto casted_2 = dynamic_cast<const Collidable &>(*this);
    casted_2.collide();

    auto casted_3 = dynamic_cast<const Updatable &>(*this);
    casted_3.update();
}
