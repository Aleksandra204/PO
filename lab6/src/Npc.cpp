#include "Npc.h"

void NPC::printComplexity() const{
    std::cout << "NPC complexity: ";
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

void NPC::interact() const{
    std::cout << "NPC talks!" << std::endl;
}

GameObject::Cplx NPC::complexity() const{
    return Cplx::LOWEST;
}