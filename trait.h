#ifndef TRAIT_H
#define TRAIT_H

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

#endif //TRAIT_H
