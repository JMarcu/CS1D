/*************************************************************************
 * AUTHOR      : James Marcu
 * STUDENT ID  : 374443
 * ASS #1      : Linked Lists & Queues
 * CLASS       : CS1D
 * SECTION     : TTh 1:00 PM
 * DUE DATE    : 8/26/2014
 *************************************************************************/

#ifndef QUEUE_H_
#define QUEUE_H_

#include "NodeType.h"

//A generic queue using a doubly linked list.
template<class Type>
class Queue
{
	public:
	   /*******************************************
	    * * * * CONSTRUCTORS AND DESTRUCTOR * * * *
	    *******************************************/
		Queue();                               //Constructs an empty object.
		Queue(const NodeType<Type>* firstNode);//Constructs an object with
		                                       //the first node instantiated.
		~Queue();                              //Safely deconstructs the queue.

	   /*******************************************
		* * * *          ACCESSORS          * * * *
		*******************************************/
		NodeType<Type>* GetHead();//Returns the head of the queue.
		NodeType<Type>* GetTail();//Returns the tail of the queue.
		bool            IsEmpty();//Returns true if the queue is empty.
		int             Length(); //Returns the number of nodes in the queue.

	   /*******************************************
		* * * *          MUTATORS           * * * *
		*******************************************/
		void Enqueue(NodeType<Type>* toQueue);//Adds a node to the end of
		                                      //the queue.
		void Dequeue();                       //Removes the head of the
		                                      //queue.
		void Destroy();                       //Destroys all nodes in the
		                                      //queue.

	private:
		NodeType<Type>* head;//Points to the first node in the queue.
		NodeType<Type>* tail;//Points to the last node in the queue.
};

/*************************************************************************
 * FUNCTION Queue(Constructor)
 * _______________________________________________________________________
 * 	 Constructs an empty queue.
 * _______________________________________________________________________
 * PRE-CONDITIONS
 * 		<none>
 *
 * POST-CONDITIONS
 * 		Constructs an empty queue.
 *************************************************************************/
template<class Type>
Queue<Type>::Queue()
{
	head = NULL;
	tail = NULL;
}

/*************************************************************************
 * FUNCTION Queue(Constructor)
 * _______________________________________________________________________
 * 	 Constructs a queue and instantiates the first node.
 * _______________________________________________________________________
 * PRE-CONDITIONS
 * 		firstNode : Points to what will be the first node in the queue.
 *
 * POST-CONDITIONS
 * 		Constructs a queue and instantiates the first node.
 *************************************************************************/
template<class Type>
Queue<Type>::Queue(const NodeType<Type>* firstNode)
{
	head = firstNode;
	tail = firstNode;
	firstNode -> SetNext(NULL);
	firstNode -> SetPrev(NULL);
}

/*************************************************************************
 * FUNCTION Queue(Destructor)
 * _______________________________________________________________________
 * 	 Safely deconstructs the queue. It uses the method Destroy to first
 * 	 delete all nodes in the Queue, by using their own destructors. Destroy
 * 	 also will set head and tail to NULL.
 * _______________________________________________________________________
 * PRE-CONDITIONS
 * 		<none>
 *
 * POST-CONDITIONS
 * 		Safely deconstructs the queue.
 *************************************************************************/
template<class Type>
Queue<Type>::~Queue()
{
	Destroy();
}

/*************************************************************************
 * FUNCTION GetHead
 * _______________________________________________________________________
 * 	 Returns head, a pointer to the first node in the queue.
 * _______________________________________________________________________
 * PRE-CONDITIONS
 * 		<none>
 *
 * POST-CONDITIONS
 * 		head : Will be returned.
 *************************************************************************/
template<class Type>
NodeType<Type>* Queue<Type>::GetHead()
{
	return head;
}

/*************************************************************************
 * FUNCTION GetTail
 * _______________________________________________________________________
 * 	 Returns tail, a pointer to the last node in the queue.
 * _______________________________________________________________________
 * PRE-CONDITIONS
 * 		<none>
 *
 * POST-CONDITIONS
 * 		tail : Will be returned.
 *************************************************************************/
template<class Type>
NodeType<Type>* Queue<Type>::GetTail()
{
	return tail;
}

/*************************************************************************
 * FUNCTION IsEmpty
 * _______________________________________________________________________
 * 	 Returns true if the queue is empty. Returns false if it is not.
 * _______________________________________________________________________
 * PRE-CONDITIONS
 * 		<none>
 *
 * POST-CONDITIONS
 * 		Returns true if the queue is empty. Returns false if it is not.
 *************************************************************************/
template<class Type>
bool Queue<Type>::IsEmpty()
{
	return head == NULL;
}

/*************************************************************************
 * FUNCTION Length
 * _______________________________________________________________________
 * 	 Returns the length of the queue, i.e. the number of nodes in the
 * 	 queue.
 * _______________________________________________________________________
 * PRE-CONDITIONS
 * 		<none>
 *
 * POST-CONDITIONS
 * 		length : The number of nodes in the queue. Will be zero if the
 * 		         queue is empty. Is returned to the calling function.
 *************************************************************************/
template<class Type>
int Queue<Type>::Length()
{
	//VARIABLE DECLERATIONS
	NodeType<Type>* auxPtr;//PROC - Used to move through the queue.
	int             length;//OUT  - Stores the number of nodes in the queue.

	//VARIABLE INITIALIZATIONS
	length = 0;
	auxPtr = head;

	/*********************************************************************
	 * PROC - Checks if the queue is empty. If so no processing is done
	 *        and length is returned as zero.
	 *********************************************************************/
	if (!IsEmpty())
	{
		//If the queue is not empty length is set to 1.
		length++;

		/*****************************************************************
		 * PROC - The pointer will iterate through every node in the list
		 *        and increment length for each node until every node has
		 *        been counted.
		 *****************************************************************/
		while (auxPtr -> next != NULL)
		{
			auxPtr = auxPtr -> next;
			length++;
		}
	}

	return length;
}

/*************************************************************************
 * FUNCTION Enqueue
 * _______________________________________________________________________
 * 	 Adds a node to the end of the queue.
 * _______________________________________________________________________
 * PRE-CONDITIONS
 * 		toQueue : A pointer to the node which will be added to the queue.
 *
 * POST-CONDITIONS
 * 		The node pointed to by toQueue will be added to queue.
 *************************************************************************/
template<class Type>
void Queue<Type>::Enqueue(NodeType<Type>* toQueue)
{
	//First it checks if the queue is empty or not.
	if (head == NULL)
	{
		//If it is empty then head and tail point at the new node, and
		//the node's prev and next fields are set to NULL.
		head =  toQueue;
		tail =  toQueue;
		head -> SetNext(NULL);
		head -> SetPrev(NULL);
	}
	else
	{
		//If it is not empty then the old last node's next field points to
		//the new node, the new node's prev field points at the old last
		//node, the new node's next field points to NULL, and finally tail
		//is set to the new node.
		tail    -> SetNext(toQueue);
		toQueue -> SetPrev(tail);
		toQueue -> SetNext(NULL);
		tail    =  toQueue;
	}
}

/*************************************************************************
 * FUNCTION Dequeue
 * _______________________________________________________________________
 * 	 Removes the first node in the queue by deleting it.
 * _______________________________________________________________________
 * PRE-CONDITIONS
 * 		<none>
 *
 * POST-CONDITIONS
 * 		The first node in the queue is deleted.
 *************************************************************************/
template<class Type>
void Queue<Type>::Dequeue()
{
	//VARIABLE DECLERATIONS
	NodeType<Type>* delPtr;

	//VARIABLE INITIALIZATIONS
	delPtr = head;

	//Checks if the queue is empty. If so no action is taken.
	if (head != NULL)
	{
		//Checks if there is more than one node in the list.
		if (head -> GetNext() != NULL)
		{
			//If there is more than one node, then head is moved to the
			//second node in the queue. The second node's prev field
			//is set to NULL. The first node in the queue is then deleted.
			head = head -> GetNext();
			head -> SetPrev(NULL);
			delete delPtr;
			delPtr = NULL;
		}
		else
		{
			//If there is only one node in the queue it is deleted. Head
			//and tail are then set to NULL.
			delete head;
			head = NULL;
			tail = NULL;
		}
	}
}

/*************************************************************************
 * FUNCTION Destroy
 * _______________________________________________________________________
 * 	 Deletes every node in the queue then sets head and tail to NULL.
 * _______________________________________________________________________
 * PRE-CONDITIONS
 * 		<none>
 *
 * POST-CONDITIONS
 * 		The queue will be empty. All nodes will be deleted.
 *************************************************************************/
template<class Type>
void Queue<Type>::Destroy()
{
	//VARIABLE DECLERATIONS
	NodeType<Type>* delPtr;

	//Runs until the queue is empty.
	while (head != NULL)
	{
		//The auxiliary pointer is set to the first node in the queue. Head
		//is set to the second node in the queue. Then the first node is
		//deleted.
		delPtr = head;
		head   = head -> next;
		delete delPtr;
	}

	//When the queue is empty, the auxiliary pointer is set to NULL for
	//safety and the queue's tail is set to NULL to reflect that it is now
	//empty.
	delPtr = NULL;
	tail   = NULL;
}


#endif /* QUEUE_H_ */
