// Include von lokalem / projektinternem File
#include "window.hpp"
#include "circle.hpp"
#include "color.hpp"
#include "rectangle.hpp"
#include "vec2.hpp"

// Include von File aus einer Fremdbibliothek
#include <GLFW/glfw3.h>

// Standard - Headers
#include <utility>
#include <cmath>
#include <random>
#include <vector>
#include <array>

int main(int argc, char* argv[])
{
  Window win{std::make_pair(800,800)};

  Vec2 n{300,300};
  Color c1{0.8,0.4,0.3};
  Color c2{0.3,0.4,0.8};
  Circle cir{n, 40, c1};
  Vec2 min{400,400};
  Vec2 max{500,450};
  Rectangle rect{min, max, c2};

  std::vector<Circle> circles(10);
  std::array<Rectangle, 10> rects;
  std::default_random_engine generator;
  std::uniform_int_distribution<int> random_color(0,255);
  std::uniform_int_distribution<int> random_size(50,750);
  std::uniform_int_distribution<int> random_radius(10,100);

  for (int unsigned i = 0; i < circles.size(); ++i) {
    Color col{random_color(generator)/255.0f,random_color(generator)/255.0f,random_color(generator)/255.0f};
    Circle cir{Vec2{double(random_size(generator)),double(random_size(generator))}, float(random_radius(generator)), col};
    circles[i] = cir;
  }

  for (int unsigned i = 0; i < rects.size(); ++i) {
    Color col{random_color(generator)/255.0f,random_color(generator)/255.0f,random_color(generator)/255.0f};
    int x1 = random_size(generator);
    int x2 = random_size(generator);
    int y1 = random_size(generator);
    int y2 = random_size(generator);
    Vec2 min = {double((x1<x2)?x1:x2), double((y1<y2)?y1:y2)};
    Vec2 max = {double((x1>x2)?x1:x2), double((y1>y2)?y1:y2)};
    rects[i] = Rectangle{min, max, col};
  }

  while (!win.should_close()) {
    if (win.get_key(GLFW_KEY_ESCAPE) == GLFW_PRESS) {
      win.close();
    }

    bool left_pressed = win.get_mouse_button(GLFW_MOUSE_BUTTON_LEFT) == GLFW_PRESS;

    auto t = win.get_time();

    float x1 = 400.f + 380.f * std::sin(t);
    float y1 = 400.f + 380.f * std::cos(t);

    float x2 = 400.f + 380.f * std::sin(2.0f*t);
    float y2 = 400.f + 380.f * std::cos(2.0f*t);

    float x3 = 400.f + 380.f * std::sin(t-10.f);
    float y3 = 400.f + 380.f * std::cos(t-10.f);

    win.draw_point(x1, y1, 1.0f, 0.0f, 0.0f);
    win.draw_point(x2, y2, 0.0f, 1.0f, 0.0f);
    win.draw_point(x3, y3, 0.0f, 0.0f, 1.0f);

    auto mouse_position = win.mouse_position();
    Vec2 mouse_vector{mouse_position.first,mouse_position.second};

    for (int unsigned i = 0; i < circles.size(); ++i) {
      if(circles[i].is_inside(mouse_vector)) {
        circles[i].draw(win, true);
      } else {
        circles[i].draw(win);
      }
    }

    if(cir.is_inside(mouse_vector)) {
      cir.draw(win, true);
    } else {
      cir.draw(win);
    }
    if(rect.is_inside(mouse_vector)) {
      rect.draw(win, true);
    } else {
      rect.draw(win);
    }

    for (int unsigned i = 0; i < rects.size(); ++i) {
      if(rects[i].is_inside(mouse_vector)) {
        rects[i].draw(win, true);
      } else {
        rects[i].draw(win);
      }
    }
    if (left_pressed) {
      win.draw_line(30.0f, 30.0f, // FROM pixel idx with coords (x=30, y=30)
                    mouse_position.first, mouse_position.second, // TO mouse position in pixel coords
                    1.0,0.0,0.0, // color with r,g,b in [0.0, 1.0]
                    1.0);        // line thickness = 1.0 * default thickness
    }

    win.draw_line(0, mouse_position.second, 10, mouse_position.second, 0.0, 0.0, 0.0);
    win.draw_line(win.window_size().second - 10, mouse_position.second, win.window_size().second, mouse_position.second, 0.0, 0.0, 0.0);

    win.draw_line(mouse_position.first, 0, mouse_position.first, 10, 0.0, 0.0, 0.0);
    win.draw_line(mouse_position.first, win.window_size().second - 10, mouse_position.first, win.window_size().second, 0.0, 0.0, 0.0);

    std::string display_text = "mouse position: (" + std::to_string(mouse_position.first) + ", " + std::to_string(mouse_position.second) + ")";
    
    int text_offset_x = 10;
    int text_offset_y = 5;
    unsigned int font_size = 35;
    
    win.draw_text(text_offset_x, text_offset_y, font_size, display_text);

    win.update();
  }

  return 0;
}
