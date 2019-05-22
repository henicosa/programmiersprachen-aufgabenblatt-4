#include <set>
#include "circle.hpp"
#include <iostream>

int main() {
  std::set<Circle> circles;
  for(int i = 0; i < 3; ++i) {
    std::cout << "Bitte geben sie einen Namen ein: ";
    std::string name;
    std::getline(std::cin, name);
    bool insertable = true;
    for(auto element : circles) {
      if(name == element.get_name()) {
        insertable = false;
      }
    }
    if (insertable) {
      circles.insert(Circle(Vec2{double(100*i), 100}, 40, Color{50,100,150}, name));
    } else {
      std::cout << "Den gibt's schon.\n";
    }
  }
  auto it = circles.find(Circle(Vec2{}, 10, Color{}, "Herbert"));
  std::cout << *it;
  return 0;
}