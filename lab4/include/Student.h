#ifndef STUDENT_H
#define STUDENT_H

#include "Person.h"

class Student : virtual public Person
{
protected:
    int id;

public:
    Student() = default;
    // konstruktor domyslny

    Student(std::string name2, int id2);
    // konstruktor przyjmuje wartosci dla name i id i przypisuje je odpowiednim polom w klasie

    std::ostream &Print(std::ostream &out) const override;
    // nadpisana metoda z klasy Person, powoduje wydrukowanie odpowiedniego outputu

    ~Student();
    // destruktor, wypisuje na ekran odpowiedni napis
};

#endif