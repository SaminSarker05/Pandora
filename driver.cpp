#include <iostream>
#include "./include/controlUnit.h"
#include "./include/alu.h"
#include "./include/register.h"

int main() 
{
  // CPU
  std::vector<Register> registers;
  for (int i = 0; i < 4; i++) {
    registers.push_back(Register());
  }
  ArithmeticLogicUnit alu;

  ControlUnit cu(alu, registers);
};