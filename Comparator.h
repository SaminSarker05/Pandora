#ifndef COMPARE_H
#define COMPARE_H

#include <iostream>
#include "EightBitAdder.h"

class Comparator
{
  public:
    Comparator(int a, int b);
    int equal_to() const;
    bool less_than() const;
    bool greater_than() const;
  private:
    int a;
    int b;
};

#endif