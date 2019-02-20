#include <iostream>
#include <variant>
#include <vector>

#include "shapes/rectangle.h"
#include "shapes/circle.h"

#include "traits/area.h"
#include "traits/area/rectangle.h"
#include "traits/area/circle.h"

/*
  Example of using Traits using std::variant, std::visit and some Template Metaprogramming-trickery.

  NOTE: C++17 is required for generic lambdas (`[](auto &&foo){...}`-style lambdas), as well as `std::variant` and `std::visit` which lived in the `std::experimental`-namespace before.

 */

int main() {
  std::vector<AreaVariant> shapes;
  shapes.push_back(Circle{1});
  shapes.push_back(Rectangle{2, 4});
  shapes.push_back(Rectangle{3, 3});
  shapes.push_back(Circle{22});

  for(AreaVariant const &shape : shapes) {
    // std::cout << std::visit([](auto &&shape) {return Area::area(shape);}, shape) << std::endl;
    float res = Area::area(shape);
    std::cout << res << std::endl;
  }
}
