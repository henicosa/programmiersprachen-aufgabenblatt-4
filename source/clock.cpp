// Include von lokalem / projektinternem File
#include "window.hpp"
#include "circle.hpp"
#include "color.hpp"
#include "rectangle.hpp"
#include "vec2.hpp"
#include "mat2.hpp"

// Include von File aus einer Fremdbibliothek
#include <GLFW/glfw3.h>

// Standard - Headers
#include <utility>
#include <cmath>


int main(int argc, char* argv[])
{
  Window win{std::make_pair(800,800), "Digitale Analoguhr"};

  while (!win.should_close()) {
    if (win.get_key(GLFW_KEY_ESCAPE) == GLFW_PRESS) {
      win.close();
    }
    Color c1{0.8,0.4,0.3};
    Color c2{0.3,0.4,0.8};
    Color c3{0.6,0.6,0};
    int adjust = 100;
    auto t = win.get_time();
    float sec_ad = (int(t*adjust) % (60*adjust));
    Vec2 n{400,400};
    Vec2 seconds_hand{0,-350};
    double phi = 2*M_PI/(60);
    Mat2 rotation_matrix = make_rotation_mat2((sec_ad/adjust)*phi);
    seconds_hand = n + (seconds_hand * rotation_matrix);


    float minuits = (int(t) % 3600)/60;
    Vec2 minuits_hand{0,-250};
    rotation_matrix = make_rotation_mat2(minuits * phi);
    minuits_hand = n + (minuits_hand*rotation_matrix);


    float hours = float(int(t) % (3600*24))/(float(60*24));
    Vec2 hours_hand{0,-150};
    rotation_matrix = make_rotation_mat2(hours * phi);
    hours_hand = n + (hours_hand*rotation_matrix);
    win.draw_line(n.x,n.y,hours_hand.x, hours_hand.y, c3.r,c3.g,c3.b,10);
    win.draw_line(n.x,n.y,minuits_hand.x, minuits_hand.y, c2.r,c2.g,c2.b,4);
    win.draw_line(n.x,n.y,seconds_hand.x, seconds_hand.y, c1.r,c1.g,c1.b,2);


    Circle cir{n, 370, c1};
    Vec2 min{400,400};
    Vec2 max{500,450};
    Rectangle rect{min, max, c2};

    cir.draw(win, true, 60);  
    cir.draw(win, false, 12);
    

    win.update();
  }

  return 0;
}