#include <iostream>
#include <utility>

class FullAdder {
public:
  static std::pair<int, int> add(int a, int b, int carry_in) {
    int sum = a ^ b ^ carry_in;
    int carry_out = (a & b) | (a & carry_in) | (b & carry_in);
    return {sum, carry_out};
  }
};

class EightBitAdder {
public:
  static std::pair<int, int> add(int a, int b, int carry_in) {
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
};

int main() {
  auto res = EightBitAdder::add(3, 4, 0);
  std::cout << res.first << " " << res.second << std::endl;
}

