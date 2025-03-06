#include <iostream>
#include "List.h"
#include "Data.h"

void eqExample(const Data &ld1, const Data &ld2)
{
  std::cout << "eqExample: " << ld1 << " == " << ld2 << " => " << ld1.isSame(ld2) << std::endl;
}

int main()
{
  std::cout << std::boolalpha;
  List a;
  a.insert(IntData(10), List::Begin);
  a.insert(FloatData(11), List::End);
  a.insert(StringData("Hello"), List::Begin);
  a.insert(IntData(7)).insert(FloatData(0.3)).insert(StringData("WhereAmI"));
  a.print();
  std::cout << "\n";
  List b(a);
  b.insert(IntData(99));
  std::cout << "Lista a " << a << std::endl;
  std::cout << "Lista b " << b << std::endl;

  eqExample(IntData(1), IntData(1));
  eqExample(IntData(1), StringData("1"));

  bool found = a.find(IntData(7));
  std::cout << "found in a: " << found << std::endl;
  found = a.find(StringData("Kasia"));
  std::cout << "found in a: " << found << std::endl;

  a << b << b;
  std::cout << "Lista a " << a << std::endl;
  std::cout << "Lista b " << b << std::endl;
}
/* wynik
["Hello", 10, 11, 7, 0.3, "WhereAmI"]
Lista a ["Hello", 10, 11, 7, 0.3, "WhereAmI"]
Lista b ["Hello", 10, 11, 7, 0.3, "WhereAmI", 99]
eqExample: 1 == 1 => true
eqExample: 1 == "1" => false
found in a: true
found in a: false
Lista a ["Hello", 10, 11, 7, 0.3, "WhereAmI", "Hello", 10, 11, 7, 0.3, "WhereAmI", 99]
Lista b []
*/
