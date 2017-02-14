//=====================================================
/**
 * LinkedList.h
 * 2017-02-13 15:57
 * KelsenH
 *
 */
//=====================================================

#ifndef LINKED_LIST_H
#define LINKED_LIST_H

#include "Case.cpp"
/**
 * @class LinkedList
 *
 * Basic linked list implementation
 */
class LinkedList
{
public:
  LinkedList (void);

  ~LinkedList (void);

  void append (int x, int y);

  Case * get_head_case (void);

private:
  Case * head_node_;
};

#endif