#include "alu.h"
#include "register.h"


class ControlUnit
{
public:
  ControlUnit(ArithmeticLogicUnit& alu, std::vector<Register>& registers) : alu(alu), registers(registers) {}
  void fetch_memory(std::vector<int>& program) {

  }
  void decode() {}
  void execute() {}

private:
  ArithmeticLogicUnit alu;
  std::vector<Register> registers;
};