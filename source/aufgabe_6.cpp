#define CATCH_CONFIG_RUNNER

#include <set>
#include "circle.hpp"
#include <iostream>
#include <algorithm>
#include <functional>

// Include von File aus einer Fremdbibliothek
# include <catch.hpp>

TEST_CASE ( " teste die aufgaben " , " [ exercises ] " ) {
  std::vector<Circle> container{};
  container.push_back(Circle(Vec2{double(100), 100}, 5, Color{50,10,150}));
  container.push_back(Circle(Vec2{double(100), 100}, 3, Color{50,10,150}));
  container.push_back(Circle(Vec2{double(100), 100}, 8, Color{50,10,150}));
  container.push_back(Circle(Vec2{double(100), 100}, 1, Color{50,100,150}));
  container.push_back(Circle(Vec2{double(100), 100}, 5, Color{50,100,150}));
  //std::sort(container.begin(), container.end());
  //exercise 3.7
  /*
  std::sort(container.begin(), container.end(), [] (Circle& lhs, Circle& rhs) -> bool{return lhs < rhs;});
  */
  //exercise 3.8
  std::sort(container.begin(), container.end(), std::less{});
  std::cout << container[0] << container[1];
  REQUIRE(std::is_sorted(container.cbegin(), container.cend()));

  // Exercise 3.14
  std::vector<Circle> small_circles(container.size());
  auto filter_lambda = [] (Circle c) -> bool{return c.get_radius() <= 4;};
  small_circles.erase(std::copy_if(container.cbegin(), container.cend() ,
  small_circles.begin(), filter_lambda), small_circles.end());
  REQUIRE(std::all_of(small_circles.cbegin(), small_circles.cend(), 
  [] (Circle c) -> bool{return c.get_radius() < 4;}));
}

int main(int argc , char* argv[]) {
  return Catch::Session().run( argc, argv );
}