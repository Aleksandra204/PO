#ifndef GAMEOBJECT_H
#define GAMEOBJECT_H

#include <vector>
#include <iostream>

class Renderable{};
class Collidable{};

class GameObject {
    private:
        static std::vector<GameObject*> Objects;

    public:
        GameObject() = default;

        virtual ~GameObject() {}

        virtual void action() = 0;

        static GameObject* addGameObject(GameObject* obj) {
            Objects.push_back(obj);
            return obj;
        }

        static void destroyGameObjects(){
            for (auto* obj : Objects) {
                delete obj;
        }
            Objects.clear();
        }

        static std::vector<GameObject*>& ActiveGameObjects(){
            return Objects;
        }
};

#endif
