#include "Person.h"

Person::Person(std::string name2) : name(name2) {}

std::ostream &operator<<(std::ostream &out, const Person &person)
{
    return person.Print(out);
}

std::ostream &Person::Print(std::ostream &out) const
{
    return out << "name (person): " << name;
}

Person::~Person()
{
    std::cout << "~" << name << " (person)" << std::endl;
}