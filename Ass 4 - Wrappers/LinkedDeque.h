/*************************************************************************
 * AUTHOR      : James Marcu
 * STUDENT ID  : 374443
 * ASS #4      : Queues and DeQueues
 * CLASS       : CS1D
 * SECTION     : TTh 3:30 AM
 * DUE DATE    : 9/16/2014
 *************************************************************************/

/*************************************************************************
 * NOTE : The following code was copied from "Data Structures & Algorithms
 *        2nd Edition" by Michael T. Goodrich, Roberto Tamassia and David
 *        Mount.
 *************************************************************************/

#include "DLinkedList.h"
#include "RuntimeException.h"

#ifndef LINKEDDEQUE_H_
#define LINKEDDEQUE_H_

typedef string Elem;// deque element type

// Exception thrown on performing insert or remove operations on an
//empty deque.
class DequeEmpty : public RuntimeException
{
  public:
    DequeEmpty(const string& err) : RuntimeException(err) {}
};

// deque as doubly linked list
class LinkedDeque
{
  public:
	LinkedDeque();
	~LinkedDeque();

    int size() const;				// number of items in the deque
    bool empty() const;				// is the deque empty?
    const Elem& front() const throw(DequeEmpty); // the first element
    const Elem& back()  const throw(DequeEmpty); // the last element

    void insertFront(const Elem& e);		// insert new first element
    void insertBack(const Elem& e);		// insert new last element
    void removeFront() throw(DequeEmpty); // remove first element
    void removeBack() throw(DequeEmpty); // remove last element

  private:					// member data
    DLinkedList D;				// linked list of elements
    int n;					// number of elements
};




#endif /* LINKEDDEQUE_H_ */
