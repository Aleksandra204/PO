#ifndef GRADE_H
#define GRADE_H

#include "Person.h"
#include "Student.h"
#include "Faculty.h"

class Grade : virtual public Faculty, virtual public Student
{
protected:
    float value;

public:
    Grade() = default;
    // konstruktor domyslny

    Grade(std::string name2, int id2, std::string spec2, float value2);
    // konstruktor przyjmuje wartosci dla name, id, spec i value i przypisuje je odpowiednim polom w klasie

    std::ostream &Print(std::ostream &out) const override;
    // nadpisana metoda z klasy Person, powoduje wydrukowanie odpowiedniego outputu

    ~Grade();
    // destruktor, wypisuje na ekran odpowiedni napis
};

#endif