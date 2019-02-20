#ifndef AREA_H
#define AREA_H

#include <variant>

namespace Area {
  // template<typename ...Ts> float area(std::variant<Ts...> const &obj);
  template<typename T> float area(T const &obj);

  template<typename ...Ts> float area(std::variant<Ts...> const &obj) {
    return std::visit([](auto const &obj){ return area(obj);}, obj);
  }

}

#endif //AREA_H
