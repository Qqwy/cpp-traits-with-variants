#include "circle.h"

namespace Area {
  template<>float area<Circle>(Circle const & circle) {
    return circle.radius * circle.radius * 3.1415;
  }
}
