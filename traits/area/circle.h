#ifndef AREA_CIRCLE_H
#define AREA_CIRCLE_H

#include "../area.h"
#include "../../shapes/circle.h"

namespace Area {
  float area(Circle const & circle);
}

typedef typename concat<AreaImpls, Circle>::type AreaImplsCircle;
#undef AreaImpls
#define AreaImpls AreaImplsCircle

#endif //AREA_CIRCLE_H
