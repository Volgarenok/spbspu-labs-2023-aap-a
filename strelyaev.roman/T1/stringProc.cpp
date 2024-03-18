#include "stringProc.hpp"
#include <stdexcept>
#include <string>
#include <cstring>
#include <ostream>
#include "inputShapes.hpp"

void strelyaev::scaleCommand(const char* string, Shape* const* list, size_t current_index, std::ostream& out)
{
  size_t pos = 0;
  const char* argument_string = string + 6;
  double arguments[3]{};
  for (size_t i = 0; i < 3; ++i)
  {
    arguments[i] = std::stod(argument_string, std::addressof(pos));
    argument_string += pos;
  }
  scaleShapes(list, current_index, arguments, out);
}

void strelyaev::toScaleIso(Shape* shape, const point_t point, const double k)
{
  point_t start = shape->getFrameRect().pos;
  shape->move(point);
  point_t moved = shape->getFrameRect().pos;
  double dx = (moved.x - start.x) * k;
  double dy = (moved.y - start.y) * k;
  shape->unsafeScale(k);
  shape->move(-dx, -dy);
}

void strelyaev::outputShapes(std::ostream& out, const Shape* const* list, size_t current_index)
{
  double sum = 0;
  for (size_t i = 0; i < current_index; i++)
  {
    sum += list[i]->getArea();
  }
  out << std::fixed;
  out.precision(1);
  out << sum;

  for (size_t i = 0; i < current_index; i++)
  {
    rectangle_t rect = list[i]->getFrameRect();
    double left_bottom_x = rect.pos.x - rect.width / 2;
    double left_bottom_y = rect.pos.y - rect.height / 2;
    double right_top_x = rect.pos.x + rect.width / 2;
    double right_top_y = rect.pos.y + rect.height / 2;
    out << " " << left_bottom_x << " " << left_bottom_y;
    out << " " << right_top_x << " " << right_top_y;
  }
  out << "\n";
}

void strelyaev::scaleShapes(Shape* const* list, size_t current_index, const double* arguments, std::ostream& out)
{
  if (current_index == 0)
  {
    throw std::logic_error("Nothing to scale");
  }
  if (arguments[2] < 0)
  {
    throw std::logic_error("Invalid SCALE argument.");
  }
  const point_t center = {arguments[0], arguments[1]};
  outputShapes(out, list, current_index);
  for (size_t i = 0; i < current_index; i++)
  {
    toScaleIso(list[i], center, arguments[2]);
  }
  outputShapes(out, list, current_index);
}

