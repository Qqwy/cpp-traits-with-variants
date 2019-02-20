#ifndef AREA_H
#define AREA_H

#include <variant>

#include "../trait.h"

namespace Area {
  // When called directly with a type that implements it
  template<typename T> float area(T const &obj);

  // When called with a variant, forward to implementation of resp. type.
  template<typename ...Ts> float area(std::variant<Ts...> const &obj) {
    return std::visit([](auto const &obj){ return area(obj);}, obj);
  }
}

/* No types implement this Trait until they re-define this macro to point to a TypeList that contains them. */
#define AreaImpls Trait::TypeListEmpty

/* will use the overridden AreaImpls: */
#define AreaVariant Trait::TypeListVariant<AreaImpls>::type

#endif //AREA_H
