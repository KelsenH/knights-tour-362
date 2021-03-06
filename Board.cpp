//=====================================================
/**
 * Board.cpp
 * 2017-02-02 18:38
 * KelsenH
 *
 */
//=====================================================

#include "Board.h"
#include <fstream>

//Default constructor
Board::Board (void) 
: knight_moves (1),
  chosen_move_amt (0)
{
  this -> reset ();
}

//Knight position constructor
Board::Board (int x_position, int y_position)
: knight (x_position, y_position),
  knight_moves (1),
  chosen_move_amt (0)
{
  this -> reset ();
}


/**
* Iterates over the potential moves of the knight
* if they are on the board and have not been visited yet,
* they are put into the 2d possible_moves array
*
* Note that the 0,0 position is actually the top, left
* of the board. The y values should be negative, but for
* simplicity's sake, I chose not to write it that way'
*/
bool Board::getPossibleMoves (void)
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
    if ((test_x < 8 && test_x >= 0) && (test_y < 8 && test_y >=0))
    {
      if (board [test_x][test_y] == 0)
      {
        //std::cout << "Potential Move: " << test_x << " " << test_y << std::endl;
        possible_moves [possible_move_counter] [0] = test_x;
        possible_moves [possible_move_counter] [1] = test_y;
        possible_move_counter ++;
      }
    }
  }
  possible_move_amt = possible_move_counter - chosen_move_amt;
  if (possible_move_amt <= 0)
  {
    return false;
  }
  else
  {
    //std::cout << "Current Possible Moves: " << possible_move_amt << std::endl;
    return true;
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
          std::cout << "K  ";
        }
        else
        {
          if (board[i][j] > 9)
            {
              std::cout << board [i][j] << " ";
            }
          else
          {
            std::cout << board [i][j] << "  ";
          }
        } 
      }
    std::cout << std::endl;
  }
  std::cout << std::endl << std::endl;
}

void Board::writeBoard (std::string fileName)
{
  std::ofstream file;
  file.open (fileName);
  for (int i = 0; i < 8; i++)
  {
      for (int j = 0; j < 8; j++)
      {
        if (i == knight.get_x_pos() && j == knight.get_y_pos()) 
        {
          file << "K  ";
        }
        else
        {
          if (board[i][j] > 9)
            {
              file << board [i][j] << " ";
            }
          else
          {
            file << board [i][j] << "  ";
          }
        } 
      }
    file << std::endl;
  }
  file << std::endl << std::endl;
  file.close ();
}

/**
 * Choosing a move based upon possible how many moves are possible
 * from each potential move. Choose the move with the least amount
 * of places to go from it. 
 */
bool Board::warnsdoff (void) 
{
  int starting_x = knight.get_x_pos ();
  int starting_y = knight.get_y_pos ();
  int starting_possible_moves = possible_move_amt;
  int chosen_move;
  int chosen_move_move_amt = 100;

  //For each possible move
  for (int i = 0; i < starting_possible_moves; i ++)
  {
    bool already_chosen = false;
    for (int j = 0; j < chosen_move_amt; j ++)
    {
      if (chosen_moves [j] == i)
      {
        already_chosen = true;
      }
    }
    if (!already_chosen)
    {
      moveKnight (possible_moves [i][0], possible_moves [i][1]);
      getPossibleMoves ();
      int test_move_amt = possible_move_amt;
      if (test_move_amt < chosen_move_move_amt)
      {
        chosen_move = i;
        chosen_move_move_amt = possible_move_amt;
      }
    }
   moveKnight (starting_x, starting_y);
   getPossibleMoves ();
  }
  
  //Move the knight to that location and check for
  //amt of possible moves.
  //Whichever has the lowest, that is the square we should
  //choose to go to
  moveKnight (starting_x, starting_y);
  getPossibleMoves ();
  int x_move = possible_moves [chosen_move][0];
  int y_move = possible_moves [chosen_move][1];
  moveKnight (x_move, y_move);
  board [starting_x][starting_y] = knight_moves;
  knight_moves ++;
  //Put index of that move in chosen moves array
  chosen_moves.push_back (chosen_move);
  possible_move_amt = starting_possible_moves;
  printBoard ();
}

bool Board::choose_move (void)
{
  //std::cout << "Chosen move amount: " << chosen_move_amt << std::endl;
  if (chosen_move_amt >= possible_move_amt)
  {
    return false;
  }
  else
  {
    chosen_move_amt ++;
  }
  return true;
}

void Board::make_move (void)
{
  int x_move = possible_moves [chosen_move_amt-1][0];
  int y_move = possible_moves [chosen_move_amt-1][1];
  std::cout << "Chosen move amt for pos: "<< chosen_move_amt << std::endl;
  std::cout << "Possible move amt for pos: " << possible_move_amt << std::endl;
  board [knight.get_x_pos()][knight.get_y_pos()] = knight_moves;
  knight.set_pos (x_move, y_move);
  knight_moves ++;
  //printBoard ();
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
