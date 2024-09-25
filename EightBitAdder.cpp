#include <utility>
#include <iostream>
#include "EightBitAdder.h"
#include "FullAdder.h"

std::pair<int, int> EightBitAdder::add(int a, int b, int carry_in) 
{
  int sum = 0;
  int carry = carry_in;
  for (int i = 0; i < 8; ++i) {
    int ith_a_bit = 1 & (a >> i);
    int ith_b_bit = 1 & (b >> i);
    auto res = FullAdder::add(ith_a_bit, ith_b_bit, carry);
    sum |= (res.first << i);
    carry = res.second;
  }
  return {sum, carry};
}

std::pair<int, int> EightBitAdder::subtract(int a, int b) 
{
  int negation_of_b = (~b) + 1;
  return add(a, negation_of_b, 1);
}