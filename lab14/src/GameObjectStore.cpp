#include "GameObjectStore.h"

std::vector<GameObject *> GameObjectStore::vec;

GameObjectStore& GameObjectStore::instance()
{
    static GameObjectStore instance;
    return instance;
}

GameObject *GameObjectStore::add(std::string name){}

GameObject *GameObjectStore::add<Enemy>(std::string name){
    Enemy *obj = new Enemy(name);
    vec.push_back(obj);
    return obj;
}

GameObject *GameObjectStore::addGameObject(GameObject *obj)
{
    vec.push_back(obj);
    return obj;
}

void GameObjectStore::destroyGameObject(GameObject *obj)
{
    auto id = std::find(vec.begin(), vec.end(), obj);
    vec.erase(id);
    delete obj;
}

void GameObjectStore::destroyGameObjects()
{
    for (int i = 0; i < vec.size(); i++)
    {
        delete vec.at(i);
    }

    vec.clear();
    std::cout << "All active objects destroyed" << std::endl;
}

std::vector<GameObject *> &GameObjectStore::getActiveGameObjects()
{
    return vec;
}