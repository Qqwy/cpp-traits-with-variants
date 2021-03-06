#ifndef AREA_RECTANGLE_H
#define AREA_RECTANGLE_H

#include "../../traits/area.h"
#include "../../shapes/rectangle.h"

namespace Area {
  float area(Rectangle const & rectangle);
}

/* Adding Rectangle to Area Trait implementations list. */
typedef typename Trait::markAsImplementation<Rectangle, AreaImpls>::type AreaImplsRect;
#undef AreaImpls
#define AreaImpls AreaImplsRect

#endif //AREA_RECTANGLE_H
