#include <iostream>
#include <utility>
#include "FullAdder.h"

std::pair<int, int> FullAdder::add(int a, int b, int carry_in) 
{
  int sum = a ^ b ^ carry_in;
  int carry_out = (a & b) | (a & carry_in) | (b & carry_in);
  return {sum, carry_out};
}