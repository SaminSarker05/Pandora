#include "alu.h"
#include "register.h"


class ControlUnit
{
public:
  ControlUnit(ArithmeticLogicUnit& alu, std::vector<Register>& registers) : alu(alu), registers(registers) {
    program_counter.set(0);
  }

  // fetch program instructions from memory
  void fetch_memory(std::vector<int>& program) { memory = program; }
  void execute() {
    while (program_counter.get() < memory.size()) {
      int instructions = memory[program_counter.get()];
      decode(instructions);
      program_counter.set(program_counter.get() + 1);
    }
  }

private:
  void decode(int instructions) {


  }
  ArithmeticLogicUnit alu;
  std::vector<Register> registers;
  std::vector<int> memory;
  Register program_counter;
};