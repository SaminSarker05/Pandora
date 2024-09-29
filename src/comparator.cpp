#include <iostream>
#include <utility>
#include <cmath>
#include "adder.h"
#include "comparator.h"

Comparator::Comparator() {};

int Comparator::less_than(int a, int b) {
  int diff = tool.subtract(a, b).first;
  if (diff < 0) {
    return 1;
  }
  return 0;
}

int Comparator::greater_than(int a, int b) {
  int diff = tool.subtract(a, b).first;
  if (diff > 0) {
    return 1;
  }
  return 0;
}

int Comparator::equal_to(int a, int b) {
  int diff = tool.subtract(a, b).first;
  if (diff == 0) {
    return 1;
  }
  return 0;
}