//=====================================================
/**
 * Board.cpp
 * 2017-02-02 18:38
 * KelsenH
 *
 */
//=====================================================

#include "Board.h"

//Default constructor
Board::Board (void) 
{
  this -> reset ();
}

//Knight position constructor
Board::Board (int x_position, int y_position)
:knight (x_position, y_position)
{
  this -> reset ();
}


/**
* Iterates over the potential moves of the knight
* if they are on the board and have not been visited yet,
* they are put into the 2d possible_moves array
*/
void Board::getPossibleMoves (void)
{
  int x [8] = {1,2,2,1,-1,-2,-2,-1};
  int y [8] = {2,1,-1,-2,-2,-1,1,2};
  int possible_move_counter = 0;
  int cur_x = knight.get_x_pos ();
  int cur_y = knight.get_y_pos ();

  for (int i = 0; i < 8; i++)
  {
    int test_x = cur_x + x [i];
    int test_y = cur_y + y [i];
    if (test_x < 8 && test_y < 8)
    {
      if (board [test_x][test_y] == 0)
      {
        possible_moves [possible_move_counter] [0] = test_x;
        possible_moves [possible_move_counter] [1] = test_y;
        possible_move_counter ++;
      }
    }
  }
}

void Board::moveKnight (int x_position, int y_position)
{
    knight.set_pos (x_position, y_position);
}

/**
* Iterates through every space in the board using two
* for loops and prints the value nicely to the terminal
*/
void Board::printBoard (void)
{
  for (int i = 0; i < 8; i++)
  {
      for (int j = 0; j < 8; j++)
      {
        if (i == knight.get_x_pos() && j == knight.get_y_pos()) 
        {
          std::cout << "K ";
        }
        else
        {
            std::cout << board [i][j] << " ";
        } 
      }
    std::cout << std::endl;
  }
}

void Board::warndoff (void) 
{

}

void Board::reset (void)
{
    for (int i = 0; i < 8; i++)
    {
        for (int j = 0; j < 8; j++)
        {
            board[i][j] = 0;
        }
    }
}