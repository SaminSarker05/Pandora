#include <iostream>
#include <vector>

enum opcode {
  ADD,
  SUB,
  LESS_THAN,
  GREATER_THAN,
  EQUAL_TO,
  AND,
  OR,
  NOT,
  XOR
};

class FullAdder 
{
public:
  FullAdder() {};

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

class ArithmeticLogicUnit
{
public:
  // given inputs to do logical or arithmic operation; unary or binary
  // inputs
  // opcode = operation
  // operands
  ArithmeticLogicUnit() {}

  int execute(int instruction, const std::vector<int>& operands) 
  {
    switch (instruction) {
      case opcode::ADD: return add(operands);
      case opcode::AND: return operands[0] & operands[1];
      case opcode::OR: return operands[0] | operands[1];
      case opcode::NOT: return ~operands[0];
      case opcode::XOR: return operands[0] ^ operands[1];
      case opcode::SUB: return subtract(operands);
      case opcode::LESS_THAN:
        std::cout << "compare < " << std::endl; break;
      case opcode::GREATER_THAN:
        std::cout << "compare > " << std::endl; break;
      case opcode::EQUAL_TO:
        std::cout << "=" << std::endl; break;
    }
    return 0;
  }

  int add(const std::vector<int>& operands) 
  {
    int num1 = operands[0];
    int num2 = operands[1];
    return summer.add(num1, num2).first;
  }

  int subtract(const std::vector<int>& operands) 
  {
    int num1 = operands[0];
    int num2 = operands[1];
    return summer.subtract(num1, num2).first;
  }
private:
  FullAdder summer;
};

int main()
{
  std::cout << "hello world..." << std::endl;
  ArithmeticLogicUnit alu;
  std::cout << alu.execute(0, {1, 2}) << std::endl;
}