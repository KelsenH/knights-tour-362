
//#include "LinkedList.h"
#include "Board.h"
#include "Stack.h"

//#include <iostream>

int main ()
{
  Board board;
  Stack <Board> stack;
  stack.push (board);
  int num_of_moves = 0;
  
  while (num_of_moves < 52)
  {
    while (board.getPossibleMoves () && board.choose_move())
    {
      stack.push (board);
      board.reset_chosen_move_amt();
    }
    
    while (!(board.getPossibleMoves ()))
    {
      stack.pop ();
      board = stack.top ();
      std::cout << "Here" << std::endl;
    } 
    num_of_moves = board.get_knight_moves ();
  }
  return 0;
}
