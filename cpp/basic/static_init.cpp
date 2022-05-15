#include <static.hpp>

int foo(int n)
{
    return n * 2;
}
int Widget1::s_var0 = Widget1::s_var1;
int Widget1::s_var3 = foo(100);
int Widget1::s_var5 = foo(100);