#ifndef ISOSCALE_H
#define ISOSCALE_H
#include "shape.h"

void checkisoScale(Shape* shape, point_t pos, double k);
void isoScale(Shape* shape, const point_t& pos, double k);
void checkisoScaleForPoint(double k);
void isoScaleForPoint(point_t& p, const point_t& position, double k);
#endif
