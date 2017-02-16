#ifndef CONTROLLER_H
#define CONTROLLER_H

#include "LinkedList.h"
#include "Board.h"
#include "Stack.h"
#include <fstream>


class Controller
{
  public:
    Controller (void);
    void get_inputs (void);
    void solve (int x, int y);
  private:
    Board board;
    Stack <Board> stack;
    LinkedList linked_list;
};

#endif