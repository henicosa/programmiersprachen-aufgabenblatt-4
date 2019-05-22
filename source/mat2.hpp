# ifndef MAT2_HPP
# define MAT2_HPP

// Mat2 definition
// Include von lokalem / projektinternem File
# include "vec2.hpp"

// Include von File aus einer Fremdbibliothek
# include <catch.hpp>

// Standard - Headers
# include <iostream>
# include <array>

struct Mat2 {
// matrix layout :
//  e_00 e_10
//  e_01 e_11

  float e_00 = 1.0f;
  float e_10 = 0.0f;
  float e_01 = 0.0f;
  float e_11 = 1.0f;

  Mat2& operator*=(Mat2 const& m);
  float det() const;
};

Vec2 operator*(Mat2 const& m , Vec2 const& v);
Vec2 operator*(Vec2 const& v , Mat2 const& m);
Mat2 inverse(Mat2 const& m);
Mat2 transpose(Mat2 const& m);
Mat2 make_rotation_mat2(float phi);
Mat2 operator*(Mat2 const& m1, Mat2 const& m2);
bool operator==(Mat2 const& lhs, Mat2 const& rhs);
std::ostream& operator<<(std::ostream& c, Mat2 const& m);

# endif // MAT2_HPP
