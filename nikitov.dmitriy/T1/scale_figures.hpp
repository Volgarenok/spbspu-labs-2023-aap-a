#ifndef SCALE_FIGURES_HPP
#define SCALE_FIGURES_HPP

#include <string>
#include "shape.hpp"
#include "composite_shape.hpp"

namespace nikitov
{
  void recognizeScaleParameters(std::string line, point_t& isoScaleCenter, double& ratio);

  void outputFrame(Shape* figure, std::ostream& output);

  void scaleFigure(Shape* figure, const point_t& isoScaleCenter, double ratio);

  void scaleComposition(CompositeShape&, const point_t& isoScaleCenter, double ratio);
}

#endif
