#define CATCH_CONFIG_RUNNER
#include <catch.hpp>
#include <cmath>
#include <algorithm>
#include <functional>

template <class T> 
  T filter(T container, std::function<bool(int)> praedikat) {
    auto it = std::remove_if(container.begin(), container.end(), praedikat);
    container.erase(it , container.end());
    return container;
  }

bool is_even(int n) {return n % 2 == 0;}

bool is_multiple_of_3(int i)
{
  if (i % 3 == 0) {
    return true;
  } else {
    return false;
  }
}

TEST_CASE ( " filter alle vielfache von drei " , " [ erase ] " )
{
  std::vector<unsigned int> v(100);

  for (auto & v : v) {
    v = std::rand() % 101;
  }

  v.erase( std::remove_if(v.begin(), v.end(), 
  [] (int i) -> bool{return !is_multiple_of_3(i);}), v.end());

  REQUIRE(std::all_of( v.cbegin() , v.cend(), is_multiple_of_3));

  // Exercise 3.12
  std::vector<int> v_1{1 ,2 ,3 ,4 ,5 ,6 ,7 ,8 ,9};
  std::vector<int> v_2{9 ,8 ,7 ,6 ,5 ,4 ,3 ,2 ,1};
  std::vector<int> v_3(9);

  std::transform(v_1.begin(), v_1.end(), v_2.begin(), v_3.begin(),
  [] (int a, int b) -> int{return a+b;});

  std::copy(v_3.cbegin(), v_3.cend(), v_1.begin());

  REQUIRE(std::all_of( v_3.cbegin() , v_3.cend(), 
  [] (int i) -> bool{return i == 10;}));

  // Exercise 3.13
  std::vector<int> v_4{1 ,2 ,3 ,4 ,5 ,6};
  std::vector<int> all_even = filter(v_4 , is_even);
  for (auto & v : all_even) {
    std::cout << v << " ";
  }
  REQUIRE(std::all_of( all_even.cbegin() , all_even.cend(), [] (int i) -> bool{return !is_even(i);}));
}
int main (int argc , char* argv[])
{
  return Catch::Session().run( argc, argv );
}