//Constructor
template <typename T>
Node<T>::Node (const T& data, Node * next_node)
: data_ (data),
  next_node_ (next_node)
{

}

template <typename T>
T Node<T>::getData (void)
{
  return data_;
}

template <typename T>
 Node<T> * Node<T>::getNextNode (void)
{
  return next_node_;
}

