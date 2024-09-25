#include <iostream>

class Register 
{
  public:
    Register() : value(0) {}
    void set(int new_value) {
      value = new_value & 255;  // ensure only 8 bits are stored
    }
    int get() const {
      return value;
    }

  private:
    int value;

};