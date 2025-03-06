#include <iostream>
#include <functional>
#include "Calculator.h"

int addValue(int x, int y) {
    return x + y;
}
int doubleValue(int x) {
    return 2 * x;
}

int main() {
    Calculator calc;

    std::cout << "Wartosc kalkulatora: " << calc() << std::endl;

    calc = 12;
    std::cout << "calc++: " << calc++ << std::endl;
    std::cout << "Wartosc kalkulatora: " << calc() << std::endl;
    std::cout << "--calc: " << --calc << std::endl;
    std::cout << "calc * 2: " << calc * 2 << std::endl;
    std::cout << "2 * calc: " << 2 * calc << std::endl;

    std::function<int(int)> doubleFunc = doubleValue;
    std::cout << "Podwojona wartosc: " << calc(doubleFunc) << std::endl;

    std::cout << "Dodana wartosc: " << calc(addValue, 32) << std::endl;

    return 0;
}

/* wynik
Wartosc kalkulatora: 0
calc++: 12
Wartosc kalkulatora: 13
--calc: 12
calc * 2: 24
2 * calc: 48
Podwojona wartosc: 96
Dodana wartosc: 80
 */
