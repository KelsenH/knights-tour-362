#ifndef NODE_H_
#define NODE_H_

template <typename T>
class Node
{
    public:
      Node (const T& data, Node * next_node);
      
      T getData (void);
      
      Node * getNextNode (void);

    private:
      T data_;

      Node <T> * next_node_; 

};

#include "Node.cpp"


#endif 