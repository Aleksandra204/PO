#ifndef GAMEOBJECT_H
#define GAMEOBJECT_H

#include <iostream>

class GameObject{
protected:
    enum Cplx
    {
        LOWEST,
        MID,
        HIGHEST
    };

public:
    virtual ~GameObject() = default;
    //Wirtualny destruktor

    virtual void printComplexity() const = 0;
    //Wirtualna metoda wymuszajaca na klasach dziedziczacych jej implementacje, wypisuje odpowiedni output w zaleznosci od wartosci Cplx

    virtual void interact() const = 0;
    //Wirtualna metoda wymuszajaca na klasach dziedziczacych jej implementacje, wypisuje odpowiedni output w zaleznosi od klasy

    virtual Cplx complexity() const = 0;
    //Wirtualna metoda wymuszajaca na klasach dziedziczacych jej implementacje, zwraca wartosc Cplx danego obiektu
};

class CompareCplx{
public:
    bool operator()(const GameObject *obj1, const GameObject *obj2){
        return static_cast<int>(obj1->complexity()) > static_cast<int>(obj2->complexity());
    }
    //Funktor sluzacy do porownywania wartosci zwracanej przez complexity() dwoch obiektow dziedziczacych po GameObject, jesli obiekt 1 ma wieksza wartosc complexity od obiektu 2 to zwracane jest true
};

#endif