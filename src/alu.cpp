#include <iostream>
#include <vector>
#include "adder.h"
#include "comparator.h"
#include "alu.h"


ArithmeticLogicUnit::ArithmeticLogicUnit() {}

int ArithmeticLogicUnit::execute(int instruction, const std::vector<int>& operands) 
{
  switch (instruction) 
  {
    case opcode::ADD: return add(operands);
    case opcode::AND: return operands[0] & operands[1];
    case opcode::OR: return operands[0] | operands[1];
    case opcode::NOT: return ~operands[0];
    case opcode::XOR: return operands[0] ^ operands[1];
    case opcode::SUB: return subtract(operands);
    case opcode::LESS_THAN: return less(operands);
    case opcode::GREATER_THAN: return greater(operands);
    case opcode::EQUAL_TO: return equal(operands);
  }
  return 0;
}

int ArithmeticLogicUnit::add(const std::vector<int>& operands)  
{
  int num1 = operands[0];
  int num2 = operands[1];
  return summer.add(num1, num2).first;
}

int ArithmeticLogicUnit::subtract(const std::vector<int>& operands) 
{
  int num1 = operands[0];
  int num2 = operands[1];
  return summer.subtract(num1, num2).first;
}

int ArithmeticLogicUnit::less(const std::vector<int>& operands) 
{
  int num1 = operands[0];
  int num2 = operands[1];
  return compare.less_than(num1, num2);
}

int ArithmeticLogicUnit::greater(const std::vector<int>& operands) 
{
  int num1 = operands[0];
  int num2 = operands[1];
  return compare.greater_than(num1, num2);
}

int ArithmeticLogicUnit::equal(const std::vector<int>& operands) 
{
  int num1 = operands[0];
  int num2 = operands[1];
  return compare.equal_to(num1, num2);
}

