#include "GameObject.h"

std::vector<GameObject *> GameObject::vec;

GameObject *GameObject::addGameObject(GameObject *obj)
{
    vec.push_back(obj);
    return obj;
}

void GameObject::destroyGameObject(GameObject *obj)
{
    auto id = std::find(vec.begin(), vec.end(), obj);
    vec.erase(id);
    delete obj;
}

void GameObject::destroyGameObjects()
{
    for (int i = 0; i < vec.size(); i++)
    {
        delete vec.at(i);
    }

    vec.clear();
    std::cout << "All active objects destroyed" << std::endl;
}

std::vector<GameObject *> &GameObject::ActiveGameObjects()
{
    return vec;
}

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
