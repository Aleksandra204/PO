#include "Calculator.h"

Calculator::Calculator() : x(0){}

int Calculator::operator()(){
    return x;
}

std::ostream& operator<<(std::ostream& out, const Calculator& obj){
    return out << obj.x;
}

Calculator& Calculator::operator=(int value){
    x = value;
    return *this;
}

int Calculator::operator++(){
    ++x;
    return x;
}

int Calculator::operator++(int){
    int temp = x;
    ++x;
    return temp;
}

int Calculator::operator--(){
    --x;
    return x;
}

Calculator Calculator::operator*(int value){
    x = x * value;
    return *this;
}

Calculator operator*(int value, Calculator& obj){
    obj.x = value * obj.x;
    return obj;
}

int Calculator::operator()(std::function<int(int)> fun){
    return fun(x);
}

int Calculator::operator()(std::function<int(int, int)> fun, int value){
    return fun(x, value);
}