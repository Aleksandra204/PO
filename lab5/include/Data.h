#ifndef DATA_H
#define DATA_H

#include <iostream>

class Data
{
public:
    virtual ~Data() {}
    // destruktor wirtualny

    virtual Data *clone() const = 0;
    // wirtualna metoda wymuszajaca implementacje klonowania obiektu

    virtual void print_data() = 0;
    // wirtualna metoda wymuszajaca implementacje mechanizmu wypisywania konkretnego outputu

    virtual bool isSame(const Data &) const = 0;
    // wirtualna metoda wymuszajaca implementacje porownywania dwoch obiektow

    friend std::ostream &operator<<(std::ostream &, const Data &);
    // funkcja pozwalajaca wypisac wartosc obiektu klas dziediczacych po Data
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

    bool isSame(const Data &obj) const override;
    // nadpisana metoda konwertuje obj do typu IntData a nastepnia sprawdza czy wartosc number jest zgodna z wartoscia number obiektu przekazanego jako argument

    // ~IntData();
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

    bool isSame(const Data &obj) const override;
    // nadpisana metoda konwertuje obj do typu StringData a nastepnia sprawdza czy wartosc text jest zgodna z wartoscia text obiektu przekazanego jako argument

    // ~StringData();
    // destruktor, powoduje wypisanie odpowiedniego komunikatu
};

class FloatData : public Data
{
private:
    float number_f;

public:
    FloatData(float x);
    // konstruktor, inicjalizuje wartosc number_f na podana

    Data *clone() const override;
    // nadpisana metoda zwracajaca nowy obiekt klasy FloatData ze skopiowana zawartoscia

    void print_data() override;
    // nadpisana metoda powoduje wypisanie zawartosci pola number_f

    bool isSame(const Data &obj) const override;
    // nadpisana metoda konwertuje obj do typu FloatData a nastepnia sprawdza czy wartosc number_f jest zgodna z wartoscia number_f obiektu przekazanego jako argument

    // ~FloatData();
    // destruktor, powoduje wypisanie odpowiedniego komunikatu
};

std::ostream &operator<<(std::ostream &out, const Data &obj);

#endif