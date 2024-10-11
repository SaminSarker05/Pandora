#ifndef CONTROL_UNIT  // preprocesser macro to reduce redundant insertions
#define CONTROL_UNIT

#include "alu.h"
#include "register.h"


class ControlUnit
{
public:
  ControlUnit(ArithmeticLogicUnit& alu, std::vector<Register>& registers);

  void fetch_memory(std::vector<int>& program);
  void execute();

private:
  void decode(int instructions);
  
  ArithmeticLogicUnit alu;
  std::vector<Register> registers;
  std::vector<int> memory;
  Register program_counter;
};

#endif