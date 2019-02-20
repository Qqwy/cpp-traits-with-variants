#include <iostream>
#include <variant>
#include <vector>

#include "shapes/rectangle.h"
#include "shapes/circle.h"

#include "traits/area.h"
#include "trait_implementations/area/rectangle.h"
#include "trait_implementations/area/circle.h"


using AreaVariant =  std::variant<Rectangle, Circle>;

int main() {
  std::vector<AreaVariant> shapes;
  shapes.push_back(Circle{1});
  shapes.push_back(Rectangle{2, 4});
  shapes.push_back(Rectangle{3, 3});
  shapes.push_back(Circle{22});

  for(AreaVariant const &shape : shapes) {
    std::cout << Area::area(shape) << std::endl;
  }
}
