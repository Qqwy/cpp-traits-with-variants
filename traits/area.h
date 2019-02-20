#ifndef AREA_H
#define AREA_H

#include <variant>

namespace Area {
  template<typename T> float area(T const &obj);

  // When called with a variant, forward to implementation of resp. types.
  template<typename ...Ts> float area(std::variant<Ts...> const &obj) {
    return std::visit([](auto const &obj){ return area(obj);}, obj);
  }

}
struct Void {};

template <typename ...> struct concat;

template <template <typename ...> class List, typename T>
struct concat<List<Void>, T>
{
  typedef List<T> type;
};

template <template <typename ...> class List, typename ...Types, typename T>
struct concat<List<Types...>, T>
{
  typedef List<Types..., T> type;
};

template <typename...> struct TypeList {};

template <>
struct TypeList<Void> {};
typedef TypeList<Void> TypelistVoid;
#define AreaImpls TypelistVoid



template <typename ...Args>
struct convertToVariant
{
  typedef std::variant<Args...> type;
};

template <typename ...Args>
struct convertToVariant<TypeList<Args...>>
{
  typedef std::variant<Args...> type;
};



#endif //AREA_H
