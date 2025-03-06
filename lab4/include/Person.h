#ifndef PERSON_H
#define PERSON_H

#include <iostream>

class Person
{
    friend std::ostream &operator<<(std::ostream &out, const Person &person);
    // przecizenie operatora << powoduje przypisanie odpowiedzniego outputu

protected:
    std::string name;

public:
    Person() = default;
    // konstruktor domyslny

    Person(std::string name2);
    // konstruktor przyjmuje wartosci dla name i przypisuje je odpowiedniemu polu w klasie

    virtual std::ostream &Print(std::ostream &out) const;
    // powoduje wydrukowanie odpowiedniego outputu

    virtual ~Person();
    // destruktor, wypisuje na ekran odpowiedni napis
};

#endif