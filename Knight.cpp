//=====================================================
/**
 * Knight.cpp
 * 2017-02-02 09:52
 * KelsenH
 *
 */
//=====================================================

#include "Knight.h"

//Default constructor, places knight at corner space
Knight::Knight (void)
:x_position_ (0),
 y_position_ (0)
{

}

/* Initializes position to parameter values
 * Uses conditional operator to make sure values are
 * always kept between 0 and 7
 */
Knight::Knight (int x_position, int y_position)
:x_position_ ((x_position < 0 || x_position > 7) ? 0 : x_position),
 y_position_ ((y_position < 0 || y_position > 7) ? 0 : y_position)
{

}

//Destructor
Knight::~Knight (void)
{
  delete this;
}

/* Set the x_position of the knight
 * Checks to make sure it is within the bounds of the board
 */
void Knight::set_x (int x_position)
{
  if (x_position >= 0 && x_position < 8)
  {
    x_position_ = x_position;
  }
  else
  {
    std::cout << "Position out of bounds" << std::endl;
  }
}

/* Set the y_position of the knight
 * Checks to make sure it is within the bounds of the board
 */
void Knight::set_y (int y_position)
{
  if (y_position >= 0 && y_position < 8)
  {
    y_position_ = y_position;
  }
  else
  {
    std::cout << "Position out of bounds" << std::endl;
  }
}

/* Set both the x and y position of the knight
 * Uses set_x and set_y methods to check bounds
 */
void Knight::set_pos (int x_position, int y_position)
{
  this -> set_x (x_position);
  this -> set_y (y_position);
}

int Knight::get_x_pos (void)
{
  return x_position_;
}

int Knight::get_y_pos (void)
{
  return y_position_;
}



