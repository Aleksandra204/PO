#include <iostream>
#include "Logical.h"

void p1(const OneArg& op) {
  std::cout << "p1  " <<  op.result(true) << std::endl;
}
void p2(const TwoArg& op) {
  std::cout << "p2  " <<  op.result(true, false) << std::endl;
}

int main() {
  std::cout << "OR   " <<  Logical::eval( OR(), false, false ) << std::endl;
  std::cout << "OR   " <<  Logical::eval( OR(), false, true ) << std::endl;
  std::cout << "AND  " <<  Logical::eval( AND(), false, false ) << std::endl;
  std::cout << "AND  " <<  Logical::eval( AND(), false, Logical::eval(NOT(), false) ) << std::endl;
  std::cout << "AND  " <<  Logical::eval( AND(), Logical::eval(OR(), true, false ), true ) << std::endl;  

  p1( NOT() );
  p2( OR() );
  p2( AND() );
}
/* wynik
OR   0
OR   1
AND  0
AND  0
AND  1
p1  0
p2  1
p2  0
 */
