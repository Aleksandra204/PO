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

// IntData::~IntData()
// {
//     std::cout << "~IntData" << std::endl;
// }

bool IntData::isSame(const Data &obj) const
{
    try
    {
        auto &obj_casted = dynamic_cast<const IntData &>(obj);
        return (number == obj_casted.number);
    }
    catch (const std::bad_cast &)
    {
        return false;
    }
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

// StringData::~StringData()
// {
//     std::cout << "~StringData" << std::endl;
// }

bool StringData::isSame(const Data &obj) const
{
    try
    {
        auto &obj_casted = dynamic_cast<const StringData &>(obj);
        return (text == obj_casted.text);
    }
    catch (const std::bad_cast &)
    {
        return false;
    }
}

// FloatData
FloatData::FloatData(float x) : number_f(x) {}

Data *FloatData::clone() const
{
    return new FloatData(number_f);
}

void FloatData::print_data()
{
    std::cout << number_f;
}

// FloatData::~FloatData()
// {
//     std::cout << "~FloatData" << std::endl;
// }

bool FloatData::isSame(const Data &obj) const
{
    try
    {
        auto &obj_casted = dynamic_cast<const FloatData &>(obj);
        return (number_f == obj_casted.number_f);
    }
    catch (const std::bad_cast &)
    {
        return false;
    }
}

std::ostream &operator<<(std::ostream &out, const Data &obj)
{
    const_cast<Data &>(obj).print_data();
    return out;
}