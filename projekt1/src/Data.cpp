#include "Data.h"

// IntData
IntData::IntData(int x) : number(x) {}

Data *IntData::clone() const
{
    return new IntData(number);
}

void IntData::print_data()
{
    std::cout << number;
}

IntData::~IntData()
{
    std::cout << "~IntData" << std::endl;
}

// StringData
StringData::StringData(std::string text2) : text(text2) {}

Data *StringData::clone() const
{
    return new StringData(text);
}

void StringData::print_data()
{
    std::cout << "\"" << text << "\"";
}

StringData::~StringData()
{
    std::cout << "~StringData" << std::endl;
}