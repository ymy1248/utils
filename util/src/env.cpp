#include "env.hpp"

void Base::echo() const {
  std::cout << "Base " << _num << " echo()\n";
}