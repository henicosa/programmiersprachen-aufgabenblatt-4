#include "color.hpp"

std::ostream& operator<<(std::ostream& os, Color const& c) {
  os << "{" << c.r << ", " << c.g << ", " << c.b << "}";
  return os;
}