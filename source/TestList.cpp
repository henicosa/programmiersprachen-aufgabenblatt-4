#define CATCH_CONFIG_RUNNER

// Include von lokalem / projektinternem File
#include "List.hpp"

// Include von File aus einer Fremdbibliothek
#include <catch.hpp>

// Standard - Headers
#include <iostream>


TEST_CASE("initial_test", "[initial_test]" ) 
{
  List<int> test{};
  REQUIRE(test.size()==0);
  REQUIRE(test.empty()==true);
}

int main(int argc, char *argv[])
{
  return Catch::Session().run(argc, argv);
}
