#include "LinkedList.h"
#include "Board.h"
#include "Stack.h"


class Controller 
{
  public:
    Controller ();
    void get_inputs (void);
    void solve ();
  private:
    Board board;
    Stack <Board> stack;
    LinkedList linked_list;
};
