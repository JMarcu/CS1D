/*************************************************************************
 * AUTHOR      : James Marcu
 * STUDENT ID  : 374443
 * ASS #4      : Queues and DeQueues
 * CLASS       : CS1D
 * SECTION     : TTh 3:30 AM
 * DUE DATE    : 9/16/2014
 *************************************************************************/

#include "LinkedDeque.h"

#ifndef QUEUE_H_
#define QUEUE_H_

//Runtime exception for Queue methods that can't be called on an empty
//queue, but were anyways.
class QueueEmpty : public RuntimeException
{
  public:
    QueueEmpty(const string& err) : RuntimeException(err) {}
};

//A queue created by wrapping a dequeue, implemented as a doubly linked
//list.
class Queue
{
	public :
	   /*******************************************
		* * * *          ACCESSORS          * * * *
		*******************************************/
		int   size() 		const;                  //Returns size of queue.
		bool  empty()       const;                  //Returns true if queue
		                                            //is empty.
		const Elem& front() const throw(QueueEmpty);//Returns the element
		                                            //in the front node of
		                                            //the queue.

	   /*******************************************
		* * * *          MUTATORS           * * * *
		*******************************************/
		void enqueue(const Elem& e);     //Adds a node with element e to
		                                 //the back of the queue.
		void dequeue() throw(QueueEmpty);//Removes the front node.

	private :
		LinkedDeque D; //Deque which was wrapped to create the queue.
};

#endif /* QUEUE_H_ */
