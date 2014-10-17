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
 * FUNCTION enqueue
 * ______________________________________________________________________
 * Adds a node with element e to the back of the queue.
 * ______________________________________________________________________
 * PRE-CONDITIONS -
 * 	e : The element to be contained in the new node.
 *
 * POST-CONDITIONS -
 * 	Will add a new node with element e to the back of the queue.
 *************************************************************************/
void Queue::enqueue(const Elem& e)
{
	D.insertBack(e);
}

/*************************************************************************
 * FUNCTION dequeue
 * ______________________________________________________________________
 * Removes the front node of the queue. Throws an exception if the queue
 * is empty.
 * ______________________________________________________________________
 * PRE-CONDITIONS -
 * 	<none>
 *
 * POST-CONDITIONS -
 * 	Removes the front node of the queue. Throws an exception if the queue
 *  is empty.
 *************************************************************************/
void Queue::dequeue() throw(QueueEmpty)
{
	if (empty())
	{
		throw QueueEmpty("dequeue on empty queue");
	}
	D.removeFront();
}
