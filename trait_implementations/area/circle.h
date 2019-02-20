#ifndef AREA_CIRCLE_H
#define AREA_CIRCLE_H

#include "../../traits/area.h"
#include "../../shapes/circle.h"

namespace Area {
  float area(Circle const & circle);
}

/* Adding Circle to Area Trait implementations list. */
typedef typename Trait::markAsImplementation<Circle, AreaImpls>::type AreaImplsCircle;
#undef AreaImpls
#define AreaImpls AreaImplsCircle

#endif //AREA_CIRCLE_H
