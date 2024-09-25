#ifndef ADDER_H
#define ADDER_H

#include <iostream>
#include <utility>

class FullAdder 
{
  public:
    static std::pair<int, int> add(int a, int b, int carry_in);
};

#endif