
//#include "LinkedList.h"
#include "Board.h"
#include "Stack.h"

//#include <iostream>

int main ()
{
  Board board;
  board.moveKnight (4,4);
  Stack <Board> stack;
  stack.push (board);
  int num_of_moves = 0;
  
  for (int i = 0; i < 40; i ++)
  {
    board.getPossibleMoves ();
    board.warnsdoff ();
    stack.push (board);
  }
  
  board.getPossibleMoves ();
  
  while (num_of_moves < 64)
  {
    if (board.choose_move ())
    {
      board.getPossibleMoves ();
      stack.push (board);
      board.reset_chosen_move_amt ();
    }
    else 
    {
      stack.pop ();
      board = stack.top ();
      board.printBoard ();
    }
    num_of_moves = board.get_knight_moves ();
    board.getPossibleMoves ();
  } 
  return 0;
}


