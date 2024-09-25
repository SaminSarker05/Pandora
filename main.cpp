#include <iostream>
#include "Comparator.h"
#include "EightBitAdder.h"

int main() {
  auto res = EightBitAdder::add(3, 4, 0);
  std::cout << res.first << std::endl;  // expecting 7



  return 0;
}