#include <iostream>
#include "List.h"
#include "Data.h"

int main()
{
  List a;
  a.insert(IntData(10), List::Begin);
  a.insert(IntData(11), List::End);
  a.insert(StringData("Hello"), List::Begin);
  a.insert(StringData("Kasia"), List::End);
  a.insert(IntData(7)).insert(StringData("WhereAmI"));

  a.print();

  List b = a;
  b.insert(IntData(99));
  std::cout << "Lista a" << std::endl;
  a.print();
  std::cout << "Lista b" << std::endl;
  b.print();
}
/* wynik:
~IntData()
~IntData()
~StringData()
~StringData()
~StringData()
~IntData()
["Hello", 10, 11, "Kasia", 7, "WhereAmI"]
~IntData()
Lista a
["Hello", 10, 11, "Kasia", 7, "WhereAmI"]
Lista b
["Hello", 10, 11, "Kasia", 7, "WhereAmI", 99]
~IntData()
~StringData()
~IntData()
~StringData()
~IntData()
~IntData()
~StringData()
~StringData()
~IntData()
~StringData()
~IntData()
~IntData()
~StringData()
 */
