#include "utilities.hpp"

int main()
{
  Shape* shape = nullptr;

  std::string command;
  while (std::cin >> command)
  {
    if (command == "RECTANGLE")
    {
      if (shape != nullptr)
      {
        delete shape;
      }
      shape = readShape();
    }
    else if (command == "SCALE")
    {
      if (shape == nullptr)
      {
        std::cerr << "No shape to scale\n";
      }
      else
      {
        float centerX, centerY, scale_factor;
        std::cin >> centerX >> centerY >> scale_factor;
        try
        {
          shape->move({0.0, 0.0});
          shape->scale(scale_factor);
          shape->move({centerX, centerY});
        }
        catch (const std::invalid_argument& e)
        {
          std::cerr << "Error: " << e.what() << "\n";
        }
      }
    }
    else
    {
      std::cerr << "Error: Unknown command.\n";
    }
  }

  if (shape != nullptr)
  {
    printShapeInfo(*shape);
    delete shape;
  }
  return 0;
}
