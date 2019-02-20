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
  std::cout << "Hello, world!\n";

  std::vector<AreaVariant> shapes;
  shapes.push_back(Circle{1});
  shapes.push_back(Rectangle{2, 4});

  for(auto &shape : shapes) {
    std::visit([](auto &&shape){std::cout << Area::area(shape) << std::endl;}, shape);
  }
}
