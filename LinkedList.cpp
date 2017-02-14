//=====================================================
/**
 * LinkedList.cpp
 * 2017-02-13 18:12
 * KelsenH
 *
 */
//=====================================================
#include "LinkedList.h"

LinkedList::LinkedList (void)
: head_node_ (new Case (0,0))
{

}

LinkedList::~LinkedList (void)
{
  delete head_node_;
}

void LinkedList::append (int x, int y)
{
  Case * current_node = head_node_;
  while (current_node -> get_next_case() != 0)
  {
    current_node = current_node -> get_next_case ();
  }
  current_node -> set_next_case (x,y);
}

Case * LinkedList::get_head_case (void)
{
  return head_node_;
}