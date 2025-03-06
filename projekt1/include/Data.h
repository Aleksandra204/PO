#ifndef DATA_H
#define DATA_H

#include <iostream>

class Data
{
public:
    virtual ~Data() {}
    // destruktor wirtualny

    virtual Data *clone() const = 0;
    // wirtualna metoda wymuszajaca jej implementacje klonowania obiektu

    virtual void print_data() = 0;
    // wirtualna metoda wymuszajaca jej implementacje mechanizmu wypisywania konkretnego outputu
};

class IntData : public Data
{
private:
    int number;

public:
    IntData(int x);
    // konstruktor, inicjalizuje wartosc number na podana

    Data *clone() const override;
    // nadpisana metoda zwracajaca nowy obiekt klasy IntData ze skopiowana zawartoscia

    void print_data() override;
    // nadpisana metoda powoduje wypisanie zawartosci pola number

    ~IntData();
    // destruktor, powoduje wypisanie odpowiedniego komunikatu
};

class StringData : public Data
{
private:
    std::string text;

public:
    StringData(std::string text2);
    // konstruktor, inicjalizuje wartosc text na podana

    Data *clone() const override;
    // nadpisana metoda zwracajaca nowy obiekt klasy StringData ze skopiowana zawartoscia

    void print_data() override;
    // nadpisana metoda powoduje wypisanie zawartosci pola text

    ~StringData();
    // destruktor, powoduje wypisanie odpowiedniego komunikatu
};

#endif