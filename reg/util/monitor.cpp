#include <iostream>
#include <list>

#include "../../util/monitor.hpp"
#include "../../ds/list.hpp"

using namespace ymy;

size_t SIZE = 1e7;
int main() {
    {
        std::cout << "std list" << std::endl;
        Monitor m;
        std::list<int> l;
        for (int i =0; i < SIZE; ++i) {
            l.push_back(i);
        }
    }
    {
        std::cout << "ymy list" << std::endl;
        Monitor m;
        list<int> l;
        for (int i = 0; i < SIZE; ++i) {
            l.push_back(i);
        }
    }
}
