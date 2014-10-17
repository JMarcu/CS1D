/*************************************************************************
 * AUTHOR      : James Marcu
 * STUDENT ID  : 374443
 * ASS #4      : Queues and DeQueues
 * CLASS       : CS1D
 * SECTION     : TTh 3:30 AM
 * DUE DATE    : 9/16/2014
 *************************************************************************/

#include "header.h"

/*************************************************************************
 * FUNCTION OutputSize
 * ______________________________________________________________________
 * This function is a driver for the class Queue's method function
 * size(). It will output the result to the console.
 * ______________________________________________________________________
 * PRE-CONDITIONS -
 * 	queue : The queue to from which to run size().
 *
 * POST-CONDITIONS -
 * 	A console message with the size of the queue will be output.
 *************************************************************************/
void OutputSize(const Queue& queue) //IN - The queue to run size() from.
{
	cout << "The queue is " << queue.size() << " elements long.\n";
}

/*************************************************************************
 * FUNCTION OutputEmpty
 * ______________________________________________________________________
 * This function is a driver for the class Queue's method function
 * empty(). It will output the result to the console.
 * ______________________________________________________________________
 * PRE-CONDITIONS -
 * 	queue : The queue to from which to run empty().
 *
 * POST-CONDITIONS -
 * 	A console message with whether or not the queue is empty will be
 * 	output.
 *************************************************************************/
void OutputEmpty(const Queue& queue) //IN - The queue to run empty() from.
{
	cout << "The queue is ";
	if (!queue.empty())
	{
		cout << "not ";
	}
	cout << "empty.\n";
}

/*************************************************************************
 * FUNCTION OutputFront
 * ______________________________________________________________________
 * This function is a driver for the class Queue's method function
 * front(). It will output the result to the console. If an exception
 * is thrown the exceptions message will be output instead.
 * ______________________________________________________________________
 * PRE-CONDITIONS -
 * 	queue : The queue to from which to run front().
 *
 * POST-CONDITIONS -
 * 	A console message with the front node of the queue will be output.
 *************************************************************************/
void OutputFront(const Queue& queue) //IN - The queue to run front() from.
{
	try
	{
		cout << "The front element of the queue is \"" << queue.front()
		     << "\".\n";
	}
	catch (QueueEmpty& err)
	{
		cout << "ERROR: " << err.getMessage() << endl;
	}
}

/*************************************************************************
 * FUNCTION OutputEnqueue
 * ______________________________________________________________________
 * This function is a driver for the class Queue's method function
 * enqueue(). It will output the result to the console.
 * ______________________________________________________________________
 * PRE-CONDITIONS -
 * 	queue : The queue to from which to run enqueue().
 *
 * POST-CONDITIONS -
 * 	A console message with the new node of the queue will be output.
 *************************************************************************/
void OutputEnqueue(Queue& queue,     //IN - The queue to run enqueue() from.
		           string toEnqueue) //IN - The data to be in the new node.
{
	cout << "Now adding \"" << toEnqueue << "\" to the back of the queue.\n";
	queue.enqueue(toEnqueue);
}

/*************************************************************************
 * FUNCTION OutputDequeue
 * ______________________________________________________________________
 * This function is a driver for the class Queue's method function
 * dequeue(). It will output the result to the console. If an exception
 * is thrown then the exception's message will be output instead.
 * ______________________________________________________________________
 * PRE-CONDITIONS -
 * 	queue : The queue to from which to run dequeue().
 *
 * POST-CONDITIONS -
 * 	A console message with the removed node of the queue will be output.
 *************************************************************************/
void OutputDequeue(Queue& queue) //IN - The queue to run dequeue() from.
{
	try
	{
		//This if statement ensures that if the queue is empty it is the
		//dequeue method that throws the exception, not front. Since this
		//function serves to test whether or not dequeue() works, having
		//the function exit at front() when the queue is empty would be
		//bad (you can't test dequeue() on an empty queue then).
		if (!queue.empty())
		{
			cout << "Now removing \"" << queue.front() << "\" from the "
			     << "front of the queue.\n";
		}
		queue.dequeue();
	}
	catch (QueueEmpty& err)
	{
		cout << "ERROR: " << err.getMessage() << endl;
	}
}
