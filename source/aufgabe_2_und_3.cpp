#include <random>
#include <list>
#include <iostream>
#include <array>
#include <map>
#include <set>

int main() {
  // Exercise 3.2
  std::list<unsigned int> random_list;
  for(int i = 0; i < 100; i++) {
    int num = std::rand() % 101;
    random_list.push_front(num);
    std::cout << num << ", ";
  }
  std::cout << "\n";
  std::set<int> random_set;
  for(auto element : random_list) {
    random_set.insert(element);
  }
  for(int i = 0; i < 101; i++) {
    if(random_set.find(i) == random_set.cend()) {
      std::cout << i << " , ";
    }   
  }
  std::cout << "\n";
  // Exercise 3.10
  std::vector<int> copy_vector (100);
  std::copy (random_list.cbegin(), random_list.cend(), copy_vector.begin());
  for(auto element : random_list) {
    std::cout << element << " # ";
  }
  // Exercise 3.3
  // with map
  std::map<int,int> frequencies_map;
  for(auto element : random_list) {
    frequencies_map[element]++;
  }  
  for(int i = 0; i < 101; i++) {
    std::map<int, int>::iterator it = frequencies_map.find(i);
    if (it != frequencies_map.end()) {
      //std::cout << i << " : " << (*it).second << "\n";
      std::cout << i << " : " << it->second << "\n";
    } else {
      std::cout << i << " : " << 0 << "\n";
    }
  }
  // with list
  /*std::array<int, 101> frequencies;
  for(int i = 0; i < 101; i++) {
    frequencies[i] = 0;
  }
  for(int i = 0; i < 100; i++) {
    frequencies[random_list.front()]++;
    random_list.pop_front();
  }
  for(int i = 0; i < 101; i++) {
    std::cout << i << " : " << frequencies[i] << "\n";
  }*/
  return 0;
}