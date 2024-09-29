#ifndef ALU
#define ALU

#include <iostream>
#include <vector>
#include "adder.h"
#include "comparator.h"

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

class ArithmeticLogicUnit
{
public:
  ArithmeticLogicUnit();
  int execute(int instruction, const std::vector<int>& operands);

private:
  int add(const std::vector<int>& operands);
  int subtract(const std::vector<int>& operands);
  int less(const std::vector<int>& operands);
  int greater(const std::vector<int>& operands);
  int equal(const std::vector<int>& operands);
  FullAdder summer;
  Comparator compare;
};

#endif