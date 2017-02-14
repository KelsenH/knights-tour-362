
#include "LinkedList.h"
#include "Board.h"
#include "Stack.h"

#include <iostream>

int main ()
{
  Board board;
  Stack <Board> stack;
  stack.push (board);
  board.getPossibleMoves ();
  while (board.choose_move())
  {
    stack.push (board);
    board.getPossibleMoves ();
  }


  return 0;
}
