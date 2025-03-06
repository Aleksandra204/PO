#include "Enemy.h"

void Enemy::printComplexity() const{
    std::cout << "Enemy complexity: ";
        switch (complexity())
        {
        case LOWEST:
            std::cout << "LOWEST" << std::endl;;
            break;
        case MID:
            std::cout << "MID" << std::endl;;
            break;
        case HIGHEST:
            std::cout << "HIGHEST" << std::endl;;
            break;
        }
}

void Enemy::interact() const{
    std::cout << "Enemy attacks!" << std::endl;
}

GameObject::Cplx Enemy::complexity() const{
    return Cplx::MID;
}