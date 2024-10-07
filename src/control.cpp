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
    // hexadecimals will represent the instructions for fib and binary search
    int opcode = (instructions & 0xff000000) >> 24;

    // extract the register indices and opcode and save into variables
    int reg1 = (instructions & 0x00ff0000) >> 16;
    int reg2 = (instructions & 0x0000ff00) >> 8;
    int reg3 = (instructions & 0x000000ff);

    std::vector<int> operands = {registers[reg1].get(), registers[reg2].get()};
    int result = alu.execute(opcode, operands);
    // save computation from alu into destination register
    registers[reg3].set(result);
  }
  ArithmeticLogicUnit alu;
  std::vector<Register> registers;
  std::vector<int> memory;
  Register program_counter;
};