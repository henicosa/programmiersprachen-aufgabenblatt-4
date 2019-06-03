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

TEST_CASE("push_pop_test", "[push_pop_test]" ) 
{
  List<int> test{};
  test.push_back(4);
  REQUIRE(test.size()==1);
  REQUIRE(test.empty()==false);
  test.push_back(-9);
  REQUIRE(test.size()==2);
  REQUIRE(test.back()==-9);
  test.push_front(5);
  REQUIRE(test.size()==3);
  REQUIRE(test.front()==5);

  test.pop_back();
  REQUIRE(test.size()==2);
  REQUIRE(test.back()==4);
  test.pop_front();
  REQUIRE(test.size()==1);
  REQUIRE(test.front()==4);
  test.pop_front();
  REQUIRE(test.size()==0);

  test.push_front(45);
  REQUIRE(test.front()==45);

  test.pop_back();
  REQUIRE(test.empty());
}

TEST_CASE("clear", "[clear]" ) 
{
  List<int> test{};
  test.push_back(4);
  test.push_back(-9);
  test.push_front(5);
  test.push_front(45);
  REQUIRE(!test.empty());
  test.clear();
  REQUIRE(test.empty());
}

TEST_CASE("iterator_operator", "[iterator_operator]" ) 
{
  List<int> test{};
  REQUIRE(test.begin() == test.end());
  test.push_back(4);
  test.push_back(-9);
  test.push_front(5);
  test.push_front(45);
  REQUIRE(*test.begin() == 45);
  auto i = test.begin();
  REQUIRE(*(i++) == 45);
  REQUIRE(*(i++) == 5);
  REQUIRE(*(++i) == -9);
  REQUIRE(++i == test.end()); 
  REQUIRE(i != test.begin()); 
  List<std::string> test2{};
  /*test2.push_back("Juicy Salif");
  auto i = test2.begin();
  REQUIRE(i->size() == 11);*/
  }

TEST_CASE("list==,!=", "[iterator_operator]" ) 
{
  List<std::string> test1{};
  List<std::string> test2{};
  REQUIRE(test1 == test2);
  REQUIRE(!(test1 != test2));
  test1.push_front("Name ");
  test1.push_back("Herbert.");
  test1.push_front("ist ");
  test1.push_front("Mein ");
  REQUIRE(test1 != test2);
  test2.push_front("Name ");
  test2.push_back("Siegfried.");
  test2.push_front("ist ");
  test2.push_front("Mein ");
  REQUIRE(test1 != test2);
  test2.pop_back();
  test2.push_back("Herbert.");
  REQUIRE(test1 == test2);
  test2.push_front("Mein ");
  REQUIRE(test1 != test2);
  }

  TEST_CASE ("copy constructor" , "[constructor]" )
  {
    List<int> list;
    list.push_front(1);
    list.push_front(2);
    list.push_front(3);
    list.push_front(4);
    List<int> list2{list};
    REQUIRE(list == list2);
  }



int main(int argc, char *argv[])
{
  return Catch::Session().run(argc, argv);
}
