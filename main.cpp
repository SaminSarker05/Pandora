#include <iostream>
#include "./src/alu.h"

int main() 
{
  ArithmeticLogicUnit alu;
  std::cout << alu.execute(0, {1, 2}) << std::endl;
  std::cout << alu.execute(1, {1, 2}) << std::endl;
  std::cout << alu.execute(2, {1, 2}) << std::endl;
  std::cout << alu.execute(3, {1, 2}) << std::endl;
  std::cout << alu.execute(4, {1, 2}) << std::endl;
};