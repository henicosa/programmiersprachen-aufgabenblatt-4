# include "rectangle.hpp"

Rectangle::Rectangle() {
  min_ = Vec2{0,0};
  max_ = Vec2{1,1};
}

Rectangle::Rectangle(Vec2 const& min, Vec2 const& max, Color const& c) {
  min_ = min;
  max_ = max;
  c_ = c;
  highlight_color_ = Color{1-c.r,1-c.g,1-c.b};
}

void const Rectangle::draw(Window& w) {
  Vec2 p_lo{min_.x,max_.y};
  Vec2 p_ru{max_.x,min_.y};
  w.draw_line(min_.x,min_.y,p_lo.x,p_lo.y,c_.r,c_.g,c_.b);
  w.draw_line(min_.x,min_.y,p_ru.x,p_ru.y,c_.r,c_.g,c_.b);
  w.draw_line(max_.x,max_.y,p_lo.x,p_lo.y,c_.r,c_.g,c_.b);
  w.draw_line(max_.x,max_.y,p_ru.x,p_ru.y,c_.r,c_.g,c_.b);
}

void const Rectangle::draw(Window& w, bool highlight) {
  if (highlight) {
    Vec2 p_lo{min_.x,max_.y};
    Vec2 p_ru{max_.x,min_.y};
    w.draw_line(min_.x,min_.y,p_lo.x,p_lo.y,highlight_color_.r,highlight_color_.g,highlight_color_.b);
    w.draw_line(min_.x,min_.y,p_ru.x,p_ru.y,highlight_color_.r,highlight_color_.g,highlight_color_.b);
    w.draw_line(max_.x,max_.y,p_lo.x,p_lo.y,highlight_color_.r,highlight_color_.g,highlight_color_.b);
    w.draw_line(max_.x,max_.y,p_ru.x,p_ru.y,highlight_color_.r,highlight_color_.g,highlight_color_.b);}else {
    draw(w);
  }
}

float const Rectangle::circumference() {
  return 2*abs(max_.x - min_.x) + 2*abs(max_.y - min_.y);
}

bool Rectangle::is_inside(const Vec2& point) {
  bool right_x = min_.x <= point.x and point.x <= max_.x;
  bool right_y = min_.y <= point.y and point.y <= max_.y;
  if(right_x and right_y) {
    return true;
  } else {
    return false;
  }
}