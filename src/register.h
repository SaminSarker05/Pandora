#ifndef REGISTER
#define REGISTER

#include <iostream>

class Register
{
public:
  Register();
  int get() const;
  void set(int new_value);
private:
  int value;
};

#endif