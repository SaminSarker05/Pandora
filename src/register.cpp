#include <iostream>
#include "register.h"

Register::Register() {};
int Register::get() const { return value; }
void Register::set(int new_value) { value = new_value; }