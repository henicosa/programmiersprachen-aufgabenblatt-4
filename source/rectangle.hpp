# ifndef RECTANGLE_HPP
# define RECTANGLE_HPP

// Include von lokalem / projektinternem File
# include "vec2.hpp"
# include "mat2.hpp"
# include "color.hpp"
# include "window.hpp"

class Rectangle
{
public:
    Rectangle();
    Rectangle(Vec2 const& min, Vec2 const& max, Color const& c);
    float const circumference();
    void const draw(Window& w);
    void const draw(Window& w, bool highlight);
    bool is_inside(const Vec2& point);
private:
    Vec2 min_;
    Vec2 max_;
    Color c_;   
    Color highlight_color_;
};

# endif //color.hpp