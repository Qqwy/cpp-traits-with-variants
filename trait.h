#ifndef TRAIT_H
#define TRAIT_H

#include <variant>

// Template metaprogramming to concatenate type lists,
// such that Trait implementations can add themselves to the known list of implementations.

namespace Trait {
  // empty sentinel
  struct Void {};

  // 'markAsImplementation' is used as type-only struct for concatenation of type lists.
  // (It is named after its purpose rather than its internals).
  // Note the template-template parameter 'List'.
  template <typename ...> struct markAsImplementation;

  // Base case (adding type to empty type list)
  template <template <typename ...> class List, typename T>
  struct markAsImplementation<T, List<Void>>
    {
      typedef List<T> type;
    };

  // Recursive case (adding type to type list which contains other types already)
  template <template <typename ...> class List, typename ...Types, typename T>
  struct markAsImplementation<T, List<Types...>>
    {
      typedef List<Types..., T> type;
    };

  // Type-only struct to keep a type list
  template <typename...> struct TypeList {};

  // Empty list to concatenate to.
  template <>
    struct TypeList<Void> {};
  typedef TypeList<Void> TypeListEmpty;


  // Convert a TypeList to a std::variant.
  template <typename ...Args>
    struct TypeListVariant
    {
      typedef std::variant<Args...> type;
    };

  template <typename ...Args>
    struct TypeListVariant<TypeList<Args...>>
    {
      typedef std::variant<Args...> type;
    };
}

#endif //TRAIT_H
