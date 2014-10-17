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

int LinkedDeque::size() const
{
	return n;
}

bool LinkedDeque::empty() const
{
	return D.empty();
}

const Elem& LinkedDeque::front() const throw(DequeEmpty)
{
	if (empty())
	{
		throw DequeEmpty("front of empty deque");
	}

	return D.front();
}

const Elem& LinkedDeque::back() const throw(DequeEmpty)
{
	if (empty())
	{
		throw DequeEmpty("back of empty deque");
	}

	return D.back();
}


