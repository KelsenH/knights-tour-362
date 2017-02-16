#include "Controller.h"

Controller::Controller (void)
{
  get_inputs ();
  Case * case_ptr = linked_list.get_head_case ();
  while (case_ptr -> get_next_case () != 0)
  {
    case_ptr = case_ptr -> get_next_case ();
    int x = case_ptr -> get_x_pos ();
    int y = case_ptr -> get_y_pos ();
    solve (x,y);
  }
}

void Controller::get_inputs (void)
{
  bool not_finished = true;
  while (not_finished)
  {
    int x;
    int y;
    char answer;
    std::cout << "Please enter a starting x value: ";
    std::cin >> x;
    std::cout << std::endl;
    std::cout << "Please enter a starting y value: ";
    std::cin >> y;
    std::cout << std::endl;
    std::cout << "Do you want to solve for another starting value? (y or n): ";
    std::cin >> answer;
    if (answer == 'n')
    {
      not_finished = false;
    }
    linked_list.append (x,y);
  }
}

void Controller::solve (int x, int y)
{
  std::string fileName = "KnightsTourSolutions.txt";
  std::ofstream file;
  file.open (fileName);
  file << "Solution for [" << x << "] [" << y << "]" << std::endl;

  board.moveKnight (x,y);
  int num_of_moves = 0;
  for (int i = 0; i < 33; i ++)
  {
    board.getPossibleMoves ();
    board.warnsdoff ();
    stack.push (board);
    num_of_moves = board.get_knight_moves ();
  }

  while (num_of_moves < 64)
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
    num_of_moves = board.get_knight_moves ();
  }
  board.writeBoard (fileName);
  file.close(); 
}
