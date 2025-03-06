#ifndef GAMEOBJECTSTORE_H
#define GAMEOBJECTSTORE_H

#include "GameObject.h"

class GameObjectStore{
private:
    static std::vector<GameObject *> vec;

    GameObjectStore() = default;

public:
    static GameObjectStore& instance();

    GameObject *addGameObject(GameObject *obj);
    //metoda ktora dodaje nowy obiekt do vectora vec

    template<typename T>
    GameObject *add(std::string name);
    //metoda ktora dodaje nowy obiekt do vectora vec

    void destroyGameObject(GameObject *obj);
    //metoda ktora usuwa podany obiekt z vectora vec

    void destroyGameObjects();
    //metoda ktora zwalnia pamiec i czysci caly vector vec

    std::vector<GameObject *> &getActiveGameObjects();
    //metoda ktora zwraca wektor vec

    GameObjectStore(GameObjectStore&) = delete;
    GameObjectStore& operator=(GameObjectStore&) = delete;
};


#endif