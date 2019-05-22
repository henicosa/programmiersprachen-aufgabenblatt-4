#include "vec2.hpp"

/*
bool Vec2::operator==(Vec2 const& v2) {
    if (x == v2.x and y == v2.y) {
        return true;
    } else {
        return false;
    }
}
*/

Vec2& Vec2::operator+=(Vec2 const& v) {
  x += v.x;
  y += v.y;
  return *this;
}

Vec2& Vec2::operator*=(float s) {
  x *= s;
  y *= s;
  return *this;
}

Vec2& Vec2::operator/=(float s) {
  if(s == 0) {
    std::cout << "Division by 0 not defined.";
    x = 0;
    y = 0;
    return *this;
  } else {
  x /= s;
  y /= s;
  return *this;
  }
}


Vec2& Vec2::operator-=(Vec2 const& v) {
  x -= v.x;
  y -= v.y;
  return *this;
}

bool operator==(Vec2 const& lhs,  Vec2 const& rhs) {
  if ((lhs.x == Approx(rhs.x)) and (lhs.y == Approx(rhs.y))) {
    return true;
  } else {
    return false;
  }
}

std::ostream& operator<<(std::ostream& c, Vec2 const& v) {
  c << "[" << v.x << ", " << v.y << "]";
  return c;
}

Vec2 operator+( Vec2 const& u , Vec2 const& v ) {
  Vec2 w = u;
  return w += v;
}

Vec2 operator-( Vec2 const& u , Vec2 const& v ) {
  Vec2 w = u;
  return w -= v;
}

Vec2 operator*( Vec2 const& v , float s ) {
  Vec2 w = v;
  return w *= s;
}

Vec2 operator/( Vec2 const& v , float s ) {
  if(s == 0) {
    std::cout << "Division by 0 not defined.";
    Vec2 v2{0,0};
    return v2;
  } else {
  Vec2 w = v;
  return w /= s;
  }
}

Vec2 operator*( float s , Vec2 const& v ) {
  Vec2 w = v;
  return w *= s;
}