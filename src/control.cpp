#include "alu.h"
#include "register.h"


class ControlUnit
{
public:
  ControlUnit(ArithmeticLogicUnit& alu, std::vector<Register>& registers) : alu(alu), registers(registers) {
    program_counter.set(0);
  }

  // fetch program instructions from memory
  void fetch_memory(std::vector<int>& program) { 
    std::cout << "working.." << std::endl;

    memory = program; 
  }

  void execute() {
    while (program_counter.get() < memory.size()) {
      int instructions = memory[program_counter.get()];
      decode(instructions);
      program_counter.set(program_counter.get() + 1);
    }
  }

private:
  void decode(int instructions) {
    // hexadecimals will represent the instructions; extract opcode and register #s
    int op= (instructions & 0xff000000) >> 24;
    int reg1 = (instructions & 0x00ff0000) >> 16;
    int reg2 = (instructions & 0x0000ff00) >> 8;
    int reg3 = (instructions & 0x000000ff);

    std::vector<int> operands = {registers[reg1].get(), registers[reg2].get()};

    int result = 0;
    int address = 0;

    switch(op) {
      case opcode::ADD:
      case opcode::SUB:
      case opcode::LESS_THAN:
      case opcode::GREATER_THAN:
      case opcode::EQUAL_TO:
      case opcode::AND:
      case opcode::OR:
      case opcode::XOR:
      case opcode::NOT:
        result = alu.execute(op, operands);
        registers[reg3].set(result);
        break;
      case opcode::LOAD:
        address = registers[reg1].get();
        registers[reg2].set(memory[address]);
        break;
      case opcode::STORE: {
        address = registers[reg2].get();
        memory[address] = registers[reg1].get();
        break;
      }
      case opcode::JUMP: {
        address = registers[reg1].get();
        program_counter.set(address);
        break;
      }
      default:
        std::cout << "invalid op code/instructions." << std::endl;
        break;
    }
  }
  ArithmeticLogicUnit alu;
  std::vector<Register> registers;
  std::vector<int> memory;
  Register program_counter;
};