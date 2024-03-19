#include "input_output_shapes.hpp"
#include <iomanip>
#include <string>
#include "rectangle.hpp"
#include "circle.hpp"
#include "ellipse.hpp"
#include "square.hpp"

void stepanov::inputArrayShape(std::istream& input, size_t const size, double * arguments)
{
  for (size_t i = 0; i < size; ++i)
  {
    input >> arguments[i];
    if (!input)
    {
      throw std::invalid_argument("Invalid argument");
    }
  }
}
void stepanov::inputRectangle(std::istream& input, Shape** shapes, size_t& size_shapes)
{
  size_t size = 4;
  double * arguments = new double[size]{};
  try
  {
    inputArrayShape(input, size, arguments);
    shapes[size_shapes] = new Rectangle({ arguments[0], arguments[1] }, { arguments[2], arguments[3] });
  }
  catch (const std::exception&)
  {
    delete[] arguments;
    throw;
  }
  ++size_shapes;
  delete[] arguments;
}

void stepanov::inputCircle(std::istream& input, Shape** shapes, size_t& size_shapes)
{
  size_t size = 3;
  double * arguments = new double[size]{};
  try
  {
    inputArrayShape(input, size, arguments);
    shapes[size_shapes] = new Circle({ arguments[0], arguments[1] }, arguments[2]);
  }
  catch (const std::exception&)
  {
    delete[] arguments;
    throw;
  }
  ++size_shapes;
  delete[] arguments;
}

void stepanov::inputEllipse(std::istream& input, Shape** shapes, size_t& size_shapes)
{
  size_t size = 4;
  double * arguments = new double[size]{};
  try
  {
    inputArrayShape(input, size, arguments);
    shapes[size_shapes] = new Ellipse({ arguments[0], arguments[1] }, arguments[2], arguments[3]);
  }
  catch (const std::exception&)
  {
    delete[] arguments;
    throw;
  }
  ++size_shapes;
  delete[] arguments;
}

void stepanov::inputSquare(std::istream& input, Shape** shapes, size_t& size_shapes)
{
  size_t size = 3;
  double * arguments = new double[size]{};
  try
  {
    inputArrayShape(input, size, arguments);
    shapes[size_shapes] = new Square({ arguments[0], arguments[1] }, arguments[2]);
  }
  catch (const std::exception&)
  {
    delete[] arguments;
    throw;
  }
  ++size_shapes;
  delete[] arguments;
}

void::stepanov::deleteShapes(Shape** shapes, size_t size_shapes)
{
  for (size_t i = 0; i < size_shapes; ++i)
  {
    delete shapes[i];
  }
  delete[] shapes;
}

stepanov::Shape** stepanov::inputShapes(std::istream& input, size_t& size_shapes)
{
  stepanov::Shape** shapes = nullptr;
  shapes = new Shape * [1000] {};
  std::string shape = "";
  while ((input >> shape) && (shape != "SCALE"))
  {
    try
    {
      if (shape == "RECTANGLE")
      {
        inputRectangle(input, shapes, size_shapes);
      }
      else if (shape == "CIRCLE")
      {
        inputCircle(input, shapes, size_shapes);
      }
      else if (shape == "ELLIPSE")
      {
        inputEllipse(input, shapes, size_shapes);
      }
      else if (shape == "SQUARE")
      {
        inputSquare(input, shapes, size_shapes);
      }
    }
    catch (const std::bad_alloc& e)
    {
      stepanov::deleteShapes(shapes, size_shapes);
      throw;
    }
    catch (const std::invalid_argument& e)
    {
      std::cerr << "Error: " << e.what() << "\n";
    }
  }
  return shapes;
}

void stepanov::outputShapes(std::ostream& output, const Shape * const * shapes, size_t size_shapes)
{
  double area = 0.0;
  for (size_t i = 0; i < size_shapes; ++i)
  {
    area += shapes[i]->getArea();
  }
  output << std::fixed << std::setprecision(1);
  output << area;
  for (size_t i = 0; i < size_shapes; ++i)
  {
    double width = shapes[i]->getFrameRect().width;
    double height = shapes[i]->getFrameRect().height;
    point_t pos = shapes[i]->getFrameRect().pos;
    point_t leftCorner = {pos.x - width / 2, pos.y - height / 2};
    point_t rightCorner = {pos.x + width / 2, pos.y + height / 2};
    output << " " << leftCorner.x << " " << leftCorner.y << " " << rightCorner.x << " " << rightCorner.y;
  }
  output << '\n';
}
