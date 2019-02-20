#ifndef AREA_CIRCLE_H
#define AREA_CIRCLE_H

#include "../area.h"
#include "../../shapes/circle.h"

namespace Area {
  template<> float area<Circle>(Circle const & circle);
}

#endif //AREA_CIRCLE_H
