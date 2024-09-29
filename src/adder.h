#ifndef FULL_ADDER
#define FULL_ADDER

#include <iostream>
#include <utility>
#include <cmath>

class FullAdder 
{
public:
  FullAdder();
  std::pair<int, int> add(int a, int b, int carry_in=0);
  std::pair<int, int> subtract(int a, int b);
  
private:
  std::pair<int, int> addOneBit(int a, int b, int carry_in);
};

#endif
