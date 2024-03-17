#include "input_output.hpp"
#include <string>
#include "rectangle.hpp"
#include "parallelogram.hpp"
#include "diamond.hpp"
#include "complexquad.hpp"


void lebedev::clearShapes(Shape ** shapes, size_t shape_count)
{
  for (size_t i = 0; i < shape_count; ++i)
  {
    delete shapes[i];
  }
  delete[] shapes;
}

void lebedev::inputRectangle(std::istream & input, Shape ** shapes, size_t & shapes_count)
{
  double args[4] = {};
  for (size_t i = 0; i < 4; ++i)
  {
    input >> args[i];
    if (!input)
    {
      throw std::invalid_argument("Invalid arguments for the Rectangle in input");
    }
  }
  shapes[shapes_count] = new Rectangle({args[0], args[1]}, {args[2], args[3]});
  ++shapes_count;
}

void lebedev::inputParallelogram(std::istream & input, Shape ** shapes, size_t & shapes_count)
{
  double args[6] = {};
  for (size_t i = 0; i < 6; ++i)
  {
    input >> args[i];
    if (!input)
    {
      throw std::invalid_argument("Invalid arguments for the Parallelogram in input");
    }
  }
  shapes[shapes_count] = new Parallelogram({args[0], args[1]}, {args[2], args[3]}, {args[4], args[5]});
  ++shapes_count;
}

void lebedev::inputDiamond(std::istream & input, Shape ** shapes, size_t & shapes_count)
{
  double args[6] = {};
  for (size_t i = 0; i < 6; ++i)
  {
    input >> args[i];
    if (!input)
    {
      throw std::invalid_argument("Invalid arguments for the Diamond in input");
    }
  }
  shapes[shapes_count] = new Diamond({args[0], args[1]}, {args[2], args[3]}, {args[4], args[5]});
  ++shapes_count;
}

void lebedev::inputComplexquad(std::istream & input, Shape ** shapes, size_t & shapes_count)
{
  double args[8] = {};
  for (size_t i = 0; i < 8; ++i)
  {
    input >> args[i];
    if (!input)
    {
      throw std::invalid_argument("Invalid arguments for the Complexquad in input");
    }
  }
  shapes[shapes_count] = new Complexquad({args[0], args[1]}, {args[2], args[3]}, {args[4], args[5]}, {args[6], args[7]});
  ++shapes_count;
}

lebedev::Shape ** lebedev::inputShapes(std::istream & input, size_t & shapes_count)
{
  lebedev::Shape ** shapes = nullptr;
  lebedev::Shape ** buffer_shapes = nullptr;
  std::string current_name = "";
  while ((input >> current_name) && (current_name != "SCALE"))
  {
    buffer_shapes = shapes;
    shapes = new Shape * [shapes_count + 1]{};
    if (buffer_shapes != nullptr)
    {
      for (size_t i = 0; i < shapes_count; ++i)
      {
        shapes[i] = buffer_shapes[i];
      }
    }
    delete[] buffer_shapes;
    try
    {
      if (current_name == "RECTANGLE")
      {
        inputRectangle(input, shapes, shapes_count);
      }
      else if (current_name == "PARALLELOGRAM")
      {
        inputParallelogram(input, shapes, shapes_count);
      }
      else if (current_name == "DIAMOND")
      {
        inputDiamond(input, shapes, shapes_count);
      }
      else if (current_name == "COMPLEXQUAD")
      {
        inputComplexquad(input, shapes, shapes_count);
      }
    }
    catch (const std::bad_alloc &)
    {
      clearShapes(shapes, shapes_count);
      throw;
    }
    catch (const std::invalid_argument & e)
    {
      std::cerr << "Error: " << e.what() << "\n";
    }
    std::string skip_line = "";
    std::getline(input, skip_line);
  }
  return shapes;
}

void lebedev::outputFrameRect(std::ostream & output, const Shape * const * shapes, size_t shape_num)
{
  double width = shapes[shape_num]->getFrameRect().width;
  double height = shapes[shape_num]->getFrameRect().height;
  point_t center = shapes[shape_num]->getFrameRect().pos;
  point_t leftDownCorner = { center.x - width / 2, center.y - height / 2 };
  point_t rightUpCorner = { center.x + width / 2, center.y + height / 2 };
  output << " " << leftDownCorner.x << " " << leftDownCorner.y << " " << rightUpCorner.x << " " << rightUpCorner.y;
}

void lebedev::outputShapes(std::ostream & output, const Shape * const * shapes, size_t shapes_count)
{
  if (shapes_count == 0)
  {
    throw std::logic_error("No shapes to output");
  }
  double area = 0.0;
  for (size_t i = 0; i < shapes_count; i++)
  {
    if (shapes[i])
    {
      area += shapes[i]->getArea();
    }
  }
  output << area;
  for (size_t i = 0; i < shapes_count; ++i)
  {
    if (shapes[i])
    {
      outputFrameRect(output, shapes, i);
    }
  }
}
