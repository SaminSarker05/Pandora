#include <iostream>
#include <utility>

class FullAdder 
{
public:
  std::pair<int, int> add(int a, int b, int carry_in=0) 
  {
    int sum = 0;
    int carry = carry_in;
    for (int i = 0; i < 64; ++i) {
      int ith_a_bit = (a >> i) & 1;
      int ith_b_bit = (b >> i) & 1;
      auto result = addOneBit(ith_a_bit, ith_b_bit, carry);
      sum |= (result.first << i);
      carry = result.second;
    }
    return {sum, carry};
  }
  std::pair<int, int> subtract(int a, int b) {
    // limitation: does not work if a < b; fix with comparator
    int b_invert = ~b;
    return add(a, b_invert, 1);
  }
private:
  std::pair<int, int> addOneBit(int a, int b, int carry_in)
  {
    int sum = (a ^ b) ^ carry_in;
    int carry_out = (a & b) | (a & carry_in) | (b & carry_in);
    return {sum, carry_out};
  }
};
