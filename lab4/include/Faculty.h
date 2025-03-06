#ifndef FACULTY_H
#define FACULTY_H

#include "Person.h"

class Faculty : virtual public Person
{
protected:
    std::string spec;

public:
    Faculty() = default;
    // konstruktor domyslny

    Faculty(std::string name2, std::string spec2);
    // konstruktor przyjmuje wartosci dla name i spec i przypisuje je odpowiednim polom w klasie

    std::ostream &Print(std::ostream &out) const override;
    // nadpisana metoda z klasy Person, powoduje wydrukowanie odpowiedniego outputu

    ~Faculty();
    // destruktor, wypisuje na ekran odpowiedni napis
};

#endif