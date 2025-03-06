#include "Grade.h"

Grade::Grade(std::string name2, int id2, std::string spec2, float value2) : Person(name2), Student(name2, id2), Faculty(name2, spec2), value(value2) {}

std::ostream &Grade::Print(std::ostream &out) const
{
    out << "As a Student: ";
    Student::Print(out);
    out << "\nAs a Faculty: ";
    Faculty::Print(out);
    out << "\nGrade value (grade): " << value;
    return out;
}

Grade::~Grade()
{
    std::cout << "~" << value << " (grade)" << std::endl;
}