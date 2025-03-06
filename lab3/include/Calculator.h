#ifndef CALCULATOR_H
#define CALCULATOR_H

#include <functional>
#include <iostream>

class Calculator {
    friend Calculator operator*(int value, Calculator& obj);
    //funkcja pozwalajaca obliczyc x * value

    friend std::ostream& operator<<(std::ostream& os, const Calculator& obj);
    //funkcja pozwalajaca wypisywac na ekran obiekt typu Calculator wypisuje wartosc x

    private:
        int x;
    public:
        Calculator();
        //Konstruktor domyslny inicjalizuje wartosc x na 0

        int operator()();
        //przeciazenie operatora () zwraca wartosc x

        Calculator& operator=(int value);
        //przeciazenie operatora = pozwala na przypisanie wartosci do x

        int operator++();
        //przeciazenie operatora preinkrementacji zwieksza wartosc x o 1

        int operator++(int);
        //przeciazenie operatora postinkrementacji zwieksza wartosc x o 1

        int operator--();
        //przeciazenie operatora predekrementacji zwieksza wartosc x o 1

        Calculator operator*(int value);
        //przeciazenie operatora * pozwala na pomnozenie x * value

        int operator()(std::function<int(int)> fun);
        //przeciazenie operatora () zwraca wartosc x wywolujac na nim przekazana funkcje fun
        
        int operator()(std::function<int(int, int)> fun, int value);
        //przeciazenie operatora () zwraca wartosc x wywolujac na nim przekazana funkcje fun
};

#endif