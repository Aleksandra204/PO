#include "GameObject.h"

std::string GameObject::Name(){
    return name;
}

/////////////////////////////////////////////////
void Updatable::update()
{
    std::cout << "Updating object" << std::endl;
}

void Collidable::collide()
{
    std::cout << "Handling collision" << std::endl;
}

void Renderable::render()
{
    std::cout << "Rendering object" << std::endl;
}
