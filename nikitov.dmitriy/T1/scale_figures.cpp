#include "scale_figures.hpp"
#include <iostream>
#include "shape.hpp"

void nikitov::recognizeScaleParameters(std::string line, point_t& isoScaleCenter, double& ratio)
{
  std::string name = "SCALE";
  line = line.substr(name.length());
  const char* cLine = line.c_str();
  size_t coordinatePointer = 0;
  double coordinates[3] = {};
  for (size_t i = 0; i != 3; ++i)
  {
    coordinates[i] = std::stod(cLine, std::addressof(coordinatePointer));
    cLine += coordinatePointer;
  }
  isoScaleCenter = { coordinates[0], coordinates[1] };
  ratio = coordinates[2];
}

void nikitov::outputFrame(Shape* figure, std::ostream& output)
{
  rectangle_t frame = figure->getFrameRect();
  output << frame.pos.x - frame.width / 2.0;
  output << ' ' << frame.pos.y - frame.height / 2.0;
  output << ' ' << frame.pos.x + frame.width / 2.0;
  output << ' ' << frame.pos.y + frame.height / 2.0;
}

void nikitov::scaleFigure(Shape* figure, const point_t& isoScaleCenter, double ratio)
{
  point_t center = figure->getFrameRect().pos;
  figure->move(isoScaleCenter);
  figure->unsafeScale(ratio);
  double dx = (isoScaleCenter.x - center.x) * ratio;
  double dy = (isoScaleCenter.y - center.y) * ratio;
  figure->move(-dx, -dy);
}

void nikitov::scaleComposition(CompositeShape& composition, const point_t& isoScaleCenter, double ratio)
{
  point_t center = composition.getFrameRect().pos;
  composition.move(isoScaleCenter);
  composition.scale(ratio);
  double dx = (isoScaleCenter.x - center.x) * ratio;
  double dy = (isoScaleCenter.y - center.y) * ratio;
  composition.move(-dx, -dy);
}
