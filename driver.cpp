#include "Knight.h"

int main ()
{
  Knight test;
  Knight test_two (5,4);
  test_two.set_x (8);
  std::cout << test_two.get_x_pos() << std::endl;
  test_two.set_y (0);
  test_two.set_x (7);
  return 0;
}
