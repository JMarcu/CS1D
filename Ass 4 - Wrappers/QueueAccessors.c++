/*************************************************************************
 * AUTHOR      : James Marcu
 * STUDENT ID  : 374443
 * ASS #4      : Queues and DeQueues
 * CLASS       : CS1D
 * SECTION     : TTh 3:30 AM
 * DUE DATE    : 9/16/2014
 *************************************************************************/

#include "Queue.h"

/*************************************************************************
 * FUNCTION size
 * ______________________________________________________________________
 * Returns the size of the queue.
 * ______________________________________________________________________
 * PRE-CONDITIONS -
 * 	<none>
 *
 * POST-CONDITIONS -
 * 	Will return the size of the queue.
 *************************************************************************/
int Queue::size() const
{
	return D.size();
}

/*************************************************************************
 * FUNCTION empty
 * ______________________________________________________________________
 * Returns true if the queue is empty.
 * ______________________________________________________________________
 * PRE-CONDITIONS -
 * 	<none>
 *
 * POST-CONDITIONS -
 * 	Will return if the queue is empty.
 *************************************************************************/
bool Queue::empty() const
{
	return D.empty();
}

/*************************************************************************
 * FUNCTION front
 * ______________________________________________________________________
 * Returns the value of the front node in the queue. Throws an exception
 * if the queue is empty.
 * ______________________________________________________________________
 * PRE-CONDITIONS -
 * 	<none>
 *
 * POST-CONDITIONS -
 * 	Will return front value in the queue. Throws an exception if queue
 * 	is empty.
 *************************************************************************/
const Elem& Queue::front() const throw(QueueEmpty)
{
	if (empty())
	{
		throw QueueEmpty("front on empty queue");
	}
	return D.front();
}
