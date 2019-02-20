#include <iostream>
#include <variant>
#include <vector>

#include "shapes/rectangle.h"
#include "shapes/circle.h"

#include "traits/area.h"
#include "traits/area/rectangle.h"
#include "traits/area/circle.h"


using AreaVariant =  std::variant<Rectangle, Circle>;

int main() {
  std::vector<AreaVariant> shapes;
  shapes.push_back(Circle{1});
  shapes.push_back(Rectangle{2, 4});

  for(AreaVariant const &shape : shapes) {
    // std::cout << std::visit([](auto &&shape) {return Area::area(shape);}, shape) << std::endl;
    float res = Area::area(shape);
    std::cout << res << std::endl;
  }
}
