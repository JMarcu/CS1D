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

#include "LinkedDeque.h"

LinkedDeque::LinkedDeque()
{
	n = 0;
}

LinkedDeque::~LinkedDeque()
{

}

void LinkedDeque::insertFront(const Elem& e)
{
    D.addFront(e);
    n++;
}

// insert new last element
void LinkedDeque::insertBack(const Elem& e)
{
    D.addBack(e);
    n++;
}

// remove first element
void LinkedDeque::removeFront() throw(DequeEmpty)
{
	if (empty())
	{
		throw DequeEmpty("removeFront of empty deque");
	}

    D.removeFront();
    n--;
}

// remove last element
void LinkedDeque::removeBack() throw(DequeEmpty)
{
	if (empty())
	{
		throw DequeEmpty("removeBack of empty deque");
	}
	else
    D.removeBack();
    n--;
}
