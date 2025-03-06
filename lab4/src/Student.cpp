#include "Student.h"

Student::Student(std::string name2, int id2) : Person(name2), id(id2) {}

std::ostream &Student::Print(std::ostream &out) const
{
    Person::Print(out);
    out << ", id (student): " << id;
    return out;
}

Student::~Student()
{
    std::cout << "~" << id << " (student)" << std::endl;
}