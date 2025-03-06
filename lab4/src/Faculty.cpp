#include "Faculty.h"

Faculty::Faculty(std::string name2, std::string spec2) : Person(name2), spec(spec2) {}

std::ostream &Faculty::Print(std::ostream &out) const
{
    Person::Print(out);
    out << ", spec (faculty): " << spec;
    return out;
}

Faculty::~Faculty()
{
    std::cout << "~" << spec << " (faculty)" << std::endl;
}