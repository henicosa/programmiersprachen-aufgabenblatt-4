#define CATCH_CONFIG_RUNNER

// Include von lokalem / projektinternem File
# include "vec2.hpp"
# include "mat2.hpp"
# include "color.hpp"
# include "rectangle.hpp"
# include "circle.hpp"

// Include von File aus einer Fremdbibliothek
# include <catch.hpp>

// Standard - Headers
# include <iostream>

TEST_CASE("vec2", "[vec2]" ) 
{
Vec2 v1{5,3};
REQUIRE (5 == v1.x); 
REQUIRE (3 == v1.y);
Vec2 v2;
REQUIRE (0 == v2.x); 
REQUIRE (0 == v2.y);
Vec2 v3{5,3.0};
REQUIRE (5 == v1.x); 
REQUIRE (3 == v1.y);

REQUIRE (v1 == v3);
}

TEST_CASE("vec_op", "[vec_op]" ) 
{
Vec2 v1{5,3}; 
Vec2 v2{1,-3};
Vec2 sol{6,0};
REQUIRE ((v1+=v2)== sol); 

v1 = Vec2{5,3}; 
v2 = Vec2{-1,3};
sol = Vec2{6,0};
REQUIRE ((v1-=v2)== sol); 

v1 = Vec2{5,3}; 
double s = 1.5;
sol = Vec2{7.5,4.5};
REQUIRE ((v1*=s)== sol); 

v1 = Vec2{5,3}; 
s = 0;
sol = Vec2{0,0};
REQUIRE ((v1/=s)== sol); 

v1 = Vec2{5,3}; 
s = 5.0f;
sol = Vec2{1,3.0f/5.0f};
REQUIRE ((v1/=s)== sol); 
}

//  Exercize 2.4

TEST_CASE("op", "[op]" ) 
{
Vec2 v1{5,3}; 
Vec2 v2{1,-3};
Vec2 sol{6,0};
REQUIRE ((v1+v2)== sol); 

v1 = Vec2{5,3}; 
v2 = Vec2{-1,3};
sol = Vec2{6,0};
REQUIRE ((v1-v2)== sol); 

v1 = Vec2{5,3}; 
double s = 1.5;
sol = Vec2{7.5,4.5};
REQUIRE ((v1*s)== sol); 
REQUIRE ((s*v1)== sol); 

v1 = Vec2{5,3}; 
s = 0;
sol = Vec2{0,0};
REQUIRE ((v1/s)== sol); 

v1 = Vec2{5,3}; 
s = 5.0f;
sol = Vec2{1,3/5.0f};
REQUIRE ((v1/s) == sol); 
}

//  Exercize 2.5

TEST_CASE("Mat2", "[Mat2]" ) 
{
Mat2 m1;
std::cout << m1 << "\n";
Mat2 m2{1,-3,4,0.5};
REQUIRE((m1*=m2)== m2); 

Mat2 m3{0,3,2,-3};
Mat2 sol{-6,12,1,10.5};
Mat2 me;
REQUIRE ((m2 * m3) == sol);
REQUIRE ((sol * inverse(m3)) == m2);
REQUIRE ((sol * inverse(m3) * inverse(m2)) == me);

sol = Mat2{0,2,3,-3};
REQUIRE(transpose(m3) == sol);
REQUIRE(m3.det()==-6);

Vec2 v{3,-2};
Vec2 vsol{9, 11};
REQUIRE((me*v) == v);
REQUIRE((m2*v) == vsol);

double phi = 0.5; //Referenzwerte benutzen
Mat2 rm{float(cos(phi)), float(-sin(phi)), float(sin(phi)), float(cos(phi))};
REQUIRE(make_rotation_mat2(phi)== rm);
}

//  Exercize 2.7

TEST_CASE("color", "[color]" ) 
{
Color c{0.4,1,54};
REQUIRE(c.r == 0.4);
REQUIRE(c.g == 1);
REQUIRE(c.b == 54);
Color c2;
REQUIRE(c2.r == 0.5);
REQUIRE(c2.g == 0.5);
REQUIRE(c2.b == 0.5);
}

//  Exercize 2.9

TEST_CASE("circumference", "[circumference]" ) 
{
  Color grey;
  Vec2 n;
  Vec2 min{-1,-2};
  Circle c1 = Circle(min, 0.5, grey);
  REQUIRE (c1.circumference() == Approx(M_PI)); 
  Circle c2 = Circle(n, 1, grey);
  REQUIRE (c2.circumference() == Approx(2*M_PI)); 
  Vec2 max{2,1};
  REQUIRE(c1.is_inside(min));
  REQUIRE(!c1.is_inside(max));
  Rectangle r1 = Rectangle(min, max, grey);
  REQUIRE (r1.circumference() == Approx(12)); 
  Rectangle r2 = Rectangle(min, n, grey);
  REQUIRE (r2.circumference() == Approx(6));
  REQUIRE (r2.is_inside(min));
  min*=(4);
  REQUIRE (!r2.is_inside(min));   
}

int main(int argc, char *argv[])
{
  return Catch::Session().run(argc, argv);
}
