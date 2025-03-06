#ifndef ACTION_H
#define ACTION_H

#include "GameObject.h"
#include "Enemy.h"
#include "Player.h"

namespace GameObjectAction {
template <typename T>
    void execute(T* obj){
        std::cout << "Executing action for a generic type: \"" << obj->Name() << "\""<< std::endl;
    }
//Szablon funkcji, wypisuje odpowiedni output na ekranie w zaleznosci od typu przekazywanego obiektu

template <>
    void execute<Enemy>(Enemy* obj){
        std::cout << "Executing action specifically for Enemy: \"" << obj->Name() << "\""<< std::endl;
        obj->action();
    }
//Specyfikacja szablonu funkcji execute dla Enemy powoduje wywolanie metody action na przekazanym obiekcie

template <>
    void execute<Player>(Player* obj){
        std::cout << "Executing action specifically for Player: \"" << obj->Name() << "\""<< std::endl;
        obj->action();
    }
//Specyfikacja szablonu funkcji execute dla Player powoduje wywolanie metody action na przekazanym obiekcie

};
#endif