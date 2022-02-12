
#include "widget.hpp"

std::atomic<uint32_t> Widget::_ctor = 0;
std::atomic<uint32_t> Widget::_dtor = 0;

void Widget::echo() const {
  std::cout << "Base " << _num << " echo()\n";
}

void Widget::initRefCount()
{
    _dtor = 0;
    _ctor = 0;
}