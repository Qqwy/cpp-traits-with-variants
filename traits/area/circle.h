#ifndef AREA_CIRCLE_H
#define AREA_CIRCLE_H

// #include "../area.h"
#include "../../shapes/circle.h"

namespace Area {
  float area(Circle const & circle) {
    return circle.radius * circle.radius * 3.1415;
  }
}

#endif //AREA_CIRCLE_H
