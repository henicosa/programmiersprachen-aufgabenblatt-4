# ifndef CIRCLE_HPP
# define CIRCLE_HPP

// Include von lokalem / projektinternem File
# include "color.hpp"
# include "mat2.hpp"
# include "vec2.hpp"
# include "mat2.hpp"
# include "color.hpp"
# include "window.hpp"
#include <iostream>

// Include von File aus einer Fremdbibliothek
# include  <catch.hpp>


class Circle {
public:
  Circle();
  Circle(Vec2 const& mid, float r, Color const& c, std::string const& name = "Kreis");
  float const circumference();
  void draw(Window& w, bool highlight = false, int divisor = 21) const;
  bool is_inside(const Vec2& point);
  std::ostream& print(std::ostream& os) const;
  std::string const& get_name() const;
  double get_radius() const;
private:
  Vec2 mid_;//vector to the circles middle
  float r_; //radius
  Color c_; //color  
  std::string name_;
  Color higlight_color_; 
};

std::ostream& operator<<(std::ostream& os, Circle const& circ);
bool operator<(Circle const& c1, Circle const& c2);
bool operator>(Circle const& c1, Circle const& c2);
bool operator==(Circle const& c1, Circle const& c2);

# endif //circle.hpp