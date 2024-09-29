#include "adder.h"
#include <iostream>
#include <utility>
#include <cmath>

FullAdder::FullAdder() {};

std::pair<int, int> FullAdder::add(int a, int b, int carry_in) 
{
  int sum = 0;
  int carry = carry_in;
  for (int i = 0; i < 32; ++i) {
    int ith_a_bit = (a >> i) & 1;
    int ith_b_bit = (b >> i) & 1;
    auto result = addOneBit(ith_a_bit, ith_b_bit, carry);

    // check if MSB is 1 and result is negative number
    if (i == 63 and result.first == 1) {
      sum = -pow(2, 31) + sum;
    } else {
      sum |= (result.first << i);
    }
    carry = result.second;
  }
  return {sum, carry};
}

std::pair<int, int> FullAdder::subtract(int a, int b) {
  int b_invert = ~b;
  return add(a, b_invert, 1);
}

std::pair<int, int> FullAdder::addOneBit(int a, int b, int carry_in)
{
  int sum = (a ^ b) ^ carry_in;
  int carry_out = (a & b) | (a & carry_in) | (b & carry_in);
  return {sum, carry_out};
}

