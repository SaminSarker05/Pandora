#ifndef EIGHT_ADDER
#define EIGHT_ADDER

#include <iostream>


class EightBitAdder 
{
  public:
    static std::pair<int, int> add(int a, int b, int carry_in);
    static std::pair<int, int> subtract(int a, int b);
};


#endif
