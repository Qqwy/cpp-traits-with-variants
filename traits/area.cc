#include "area.h"
// #include "../shapes/circle.h"
// namespace Area {
//   float area(Circle const &circle){
//     return circle.radius * circle.radius * 3.1415;
//   }
// }

// #include "../shapes/rectangle.h"
// namespace Area {
//   float area(Rectangle const &rectangle){
//     return rectangle.width * rectangle.height;
//   }
// }

namespace Area {
  template<typename ...Ts> float area(std::variant<Ts...> const &obj) {
      return std::visit([](auto const &obj){ return area(obj);}, obj);
  }
}
