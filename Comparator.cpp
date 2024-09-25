#include <iostream>
#include "EightBitAdder.h"
#include "Comparator.h"

Comparator::Comparator(int a, int b) : a(a), b(b) {};

int Comparator::equal_to() const 
{
  std::pair<int, int> res = EightBitAdder::subtract(a, b);
  int sum = res.first;
  return sum == 0;
}

bool Comparator::less_than() const 
{
  std::pair<int, int> res = EightBitAdder::subtract(a, b);
  int sum = res.first;
  return ((sum >> 7) & 1) == 1;
}

bool Comparator::greater_than() const 
{
  return !(less_than() or equal_to());
}