#ifndef AREA_H
#define AREA_H

#include <variant>

namespace Area {
  template<typename ...Ts> float area(std::variant<Ts...> const &obj);
}

#endif //AREA_H
