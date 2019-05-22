#include <cstdlib>
#include <vector>
#include <list>
#include <iostream>
#include <iterator>
#include <algorithm>

int main () {
  std::vector<int> v_0(10);

  for (auto & v : v_0) {
    v = std::rand() % 10;
  }
  std::copy(std::cbegin( v_0 ) ,std::cend( v_0 ) ,
    std::ostream_iterator<int>(std::cout, "\n"));
  std::cout << "\n";

  std::list<int> l_0(std::cbegin(v_0) ,std::cend(v_0));
  std::list<int> l_1(std::cbegin(l_0) ,std::cend(l_0));
  std::reverse(std::begin(l_1) ,std::end(l_1));
  std::copy (std::cbegin(l_1) ,std::cend(l_1),
  std::ostream_iterator<int>(std::cout, "\n" ));
  std::cout << "\n";

  l_1.sort();
  std::copy ( l_1.cbegin() , l_1.cend(),
  std::ostream_iterator <int>( std::cout , "\n"));
  std::cout << "\n";

  std::generate(std::begin(v_0) ,std::end(v_0) , std::rand);
  std::copy (v_0.crbegin() , v_0.crend() ,
  std::ostream_iterator<int>(std::cout, "\n"));
  return 0;
}