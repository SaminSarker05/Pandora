#ifndef COMPARATOR
#define COMPARATOR

#include <iostream>
#include <utility>
#include <cmath>
#include "adder.h"

class Comparator
{
public:
  Comparator();
  int less_than(int a, int b);
  int greater_than(int a, int b);
  int equal_to(int a, int b);
private:
  FullAdder tool;
};

#endif