#include <iostream>
#include "Comparator.h"
#include "EightBitAdder.h"

int main() {
  auto res = EightBitAdder::add(3, 4, 0);
  std::cout << res.first << std::endl;  // expecting 7
  Comparator check(3, 4);

  std::cout << check.less_than() << " " << check.greater_than()
  << " " << check.equal_to() << std::endl;

  return 0;
}