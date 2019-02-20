#include "rectangle.h"

namespace Area {
  template<>float area<Rectangle>(Rectangle const & rectangle) {
    return rectangle.width * rectangle.height;
  }
}
