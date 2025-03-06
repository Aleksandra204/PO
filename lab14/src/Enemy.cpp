#include "Enemy.h"

Enemy::Enemy(){
    GameObject::name = "Unnamed Enemy";
}

Enemy::Enemy(std::string name2){
    GameObject::name = name2;
}

void Enemy::action() const
{
    auto casted = dynamic_cast<const Renderable &>(*this);
    casted.render();

    auto casted_2 = dynamic_cast<const Collidable &>(*this);
    casted_2.collide();
    casted.update();
}
