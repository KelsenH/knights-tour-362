
//#include "LinkedList.h"
#include "Board.h"
#include "Stack.h"

#include <iostream>

int main ()
{
  Board board;
  board.moveKnight (4,4);
  Stack <Board> stack;
  stack.push (board);
  int num_of_moves = 0;
  
  for (int i = 0; i < 32; i ++)
  {
    board.getPossibleMoves ();
    board.warnsdoff ();
    stack.push (board);
    num_of_moves = board.get_knight_moves ();
    std::cout << "Current move amt: " << num_of_moves << std::endl;
  }
  
  
  for (int j = 0; j < 1; j ++)
  {
    if (board.getPossibleMoves ())
    {
      if (board.choose_move ())
      {
        stack.push (board);
        board.make_move ();
        board.reset_chosen_move_amt ();
      }
      else 
      {
        board = stack.top ();
        stack.pop();
      }
    }
    else
    {
      board = stack.top ();
      stack.pop ();
    }
    
    board.printBoard ();
    num_of_moves = board.get_knight_moves ();
    //std::cout << "Current move amt: " << num_of_moves << std::endl;
  }   
  return 0;
}


