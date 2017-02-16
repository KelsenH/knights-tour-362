#include "Controller.h"

Controller::Controller (void)
{
  get_inputs ();
  solve ();
}

Controller::get_inputs (void)
{
  bool not_finished = true;
  while (not_finished)
  {
    int x;
    int y;
    char answer;
    std::cout << "Please enter a starting x value: ";
    std::cin << x;
    std::cout << std::endl;
    std::cout << "Please enter a starting y value: ";
    std::cin << y;
    std::cout << std::endl;
    std::cout << "Do you want to solve for another starting value? (y or n): ";
    std::cin << answer;
    if (answer == )
  }
}
