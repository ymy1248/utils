#define CATCH_CONFIG_MAIN
#include "../catch.hpp"
#include "../../ds/list.hpp"

TEST_CASE("list basic", "[list]")
{
  ymy::list<int> l;
  for (int i = 0; i < 10; ++i) {
    l.push_back(i);
  }
  REQUIRE(l.size() == 10);
}
