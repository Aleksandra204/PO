#ifndef PLAYER_H
#define PLAYER_H

#include "GameObject.h"

class Player : public GameObject{
public:
    Cplx complexity() const override;
    //Nadpisana metoda, zwraca wartosc typu enumerowanego w tym przypadku HIGHEST

    void printComplexity() const override;
    //Nadpisana metoda, w zaleznosci od tego co zwroci metoda complexity() wypisuje na ekran LOWEST, MID lub HIGHEST

    void interact() const override;
    //Nadpisana metoda, wypisuje odpowiedni output
};

#endif