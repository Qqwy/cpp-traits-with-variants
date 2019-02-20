#ifndef AREA_RECTANGLE_H
#define AREA_RECTANGLE_H

#include "../area.h"
#include "../../shapes/rectangle.h"

namespace Area {
  template<> float area<Rectangle>(Rectangle const & rectangle);
}

#endif //AREA_RECTANGLE_H
