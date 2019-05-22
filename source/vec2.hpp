# ifndef VEC2_HPP
# define VEC2_HPP

// Include von File aus einer Fremdbibliothek
# include <catch.hpp>
// Standard - Headers
# include <iostream>


// Vec2 data type definition
struct Vec2
{
/* TODO add member variables with
default member initialisation*/
double x = 0.0;
double y = 0.0;

//bool operator==(Vec2 const& v );
Vec2& operator+=(Vec2 const& v );
Vec2& operator-=(Vec2 const& v );
Vec2& operator*=(float s );
Vec2& operator/=(float s );
};

Vec2 operator+(Vec2 const& u ,Vec2 const& v);
Vec2 operator-(Vec2 const& u ,Vec2 const& v);
Vec2 operator*(Vec2 const& v ,float s);
Vec2 operator/(Vec2 const& v ,float s);
Vec2 operator*(float s ,Vec2 const& v);
bool operator==(Vec2 const& lhs,  Vec2 const& rhs);

std::ostream& operator<<(std::ostream& c, Vec2 const& v);
# endif // VEC2_HPP