// $Id: Stack.cpp 827 2011-02-07 14:20:53Z hillj $

// Honor Pledge:
//
// I pledge that I have neither given nor received any help
// on this assignment.

//
// Stack
//
template <typename T>
Stack <T>::Stack (void)
: topOfStack (nullptr)
{
  
}

//
// Stack
//
template <typename T>
Stack <T>::Stack (const Stack & stack)
: topOfStack (nullptr)
{
  if (this -> is_empty())
  {
    throw empty_exception ();
  }
  else
  {
    bool keep_going = true;
    Node <T> * cur_node = topOfStack;
    while (keep_going)
    {
      this -> push (topOfStack -> getData ());
      cur_node = cur_node -> getNextNode ();
      if (cur_node == nullptr)
      {
        keep_going = false;
      }
    }
  }
}

//
// ~Stack
//
template <typename T>
Stack <T>::~Stack (void)
{
  delete [] topOfStack;
}

//
// push
//
template <typename T>
void Stack <T>::push (T element)
{
  topOfStack = new Node <T> (element, topOfStack);  
}

//
// pop
//
template <typename T>
void Stack <T>::pop (void)
{
  if (this -> is_empty())
  {
    throw empty_exception ();
  }
  else
  {
    Node <T> * cur_top = topOfStack;
    topOfStack = topOfStack -> getNextNode ();
    delete cur_top;
  }
}

//
// operator =
//
template <typename T>
const Stack <T> & Stack <T>::operator = (const Stack & rhs)
{
  delete topOfStack;
  bool keep_going = true;
  Node <T> * cur_node = topOfStack;
  while (keep_going)
  {
    this -> push (topOfStack -> getData ());
    cur_node = cur_node -> getNextNode ();
    if (cur_node == nullptr)
    {
      keep_going = false;
    }
  }
}

//
// clear
//
template <typename T>
void Stack <T>::clear (void)
{
  delete topOfStack;
  topOfStack = nullptr;
}
