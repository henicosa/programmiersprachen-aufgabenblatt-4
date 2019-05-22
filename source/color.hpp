# ifndef COLOR_HPP
# define COLOR_HPP
#include <iostream>

struct Color {
  double r = 0.5;
  double g = 0.5;
  double b = 0.5;
};

std::ostream& operator<<(std::ostream& os, Color const& c);
# endif //color.hpp