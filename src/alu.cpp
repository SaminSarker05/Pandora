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

class ArithmeticLogicUnit
{
public:
  // given inputs to do logical or arithmic operation; unary or binary
  // inputs
  // opcode = operation
  // operands
  ArithmeticLogicUnit() {}
  void execute(int instruction, const std::vector<int>& operands) {
    switch (instruction) {
      case opcode::ADD:
        std::cout << "add" << std::endl; break;
      case opcode::SUB:
        std::cout << "subtract" << std::endl; break;
      case opcode::LESS_THAN:
        std::cout << "compare < " << std::endl; break;
      case opcode::GREATER_THAN:
        std::cout << "compare > " << std::endl; break;
      case opcode::EQUAL_TO:
        std::cout << "=" << std::endl; break;
      case opcode::AND:
        std::cout << "and" << std::endl; break;
      case opcode::OR:
        std::cout << "or" << std::endl; break;
      case opcode::NOT:
        std::cout << "not" << std::endl; break;
      case opcode::XOR:
        std::cout << "xor" << std::endl; break;
    }
  }
  void add(std::vector<int>& operands) 
  {


  }
  void subtract(std::vector<int>& operands) {
    
  }
  // void less_than(std::vector<int>& operands) {}
  // void greater_than(std::vector<int>& operands) {}
  // void equal_to(std::vector<int>& operands) {}
  // void and_(std::vector<int>& operands) {}
  // void or_(std::vector<int>& operands) {}
  // void not_(std::vector<int>& operands) {}
  // void xor_(std::vector<int>& operands) {}

};

int main()
{
  std::cout << "hello world" << std::endl;
  ArithmeticLogicUnit alu;
  alu.execute(2, {1, 2});
}