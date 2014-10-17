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

// constructor
DLinkedList::DLinkedList()
{
	// create sentinels
    header  = new DNode;
    trailer = new DNode;

    // have them point to each other
    header->next  = trailer;
    trailer->prev = header;
}

// destructor
DLinkedList::~DLinkedList()
{
	// remove all but sentinels
	while (!empty())
	{
		removeFront();
	}

	// remove the sentinels
    delete header;
    delete trailer;
}

void DLinkedList::add(DNode* v, const Elem& e)
{
	// create a new node for e
    DNode* u = new DNode;
    u->elem = e;

    // link u in between v and v->prev
    u->next = v;
    u->prev = v->prev;
    v->prev->next = v->prev = u;
}

// add to front of list
void DLinkedList::addFront(const Elem& e)
{
	add(header->next, e);
}

// add to back of list
void DLinkedList::addBack(const Elem& e)
{
	add(trailer, e);
}

// remove node v
void DLinkedList::remove(DNode* v)
{
    DNode* u = v->prev;// predecessor
    DNode* w = v->next;// successor

    // unlink v from list
    u->next = w;
    w->prev = u;

    delete v;
}

// remove from font
void DLinkedList::removeFront()
{
	remove(header->next);
}

// remove from back
void DLinkedList::removeBack()
{
	remove(trailer->prev);
}
