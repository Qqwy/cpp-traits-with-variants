#ifndef AREA_RECTANGLE_H
#define AREA_RECTANGLE_H

// #include "../area.h"
#include "../../shapes/rectangle.h"

namespace Area {
  float area(Rectangle const & rectangle) {
    return rectangle.width * rectangle.height;
  }
}

#endif //AREA_RECTANGLE_H
