#include "Player.h"

void Player::printComplexity() const{
    std::cout << "Player complexity: ";
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

void Player::interact() const{
    std::cout << "Player moves!" << std::endl;
}

GameObject::Cplx Player::complexity() const{
    return Cplx::HIGHEST;
}