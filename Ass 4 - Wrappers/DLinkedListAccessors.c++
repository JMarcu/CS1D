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

bool DLinkedList::empty() const		// is list empty?
{
	return (header->next == trailer);
}

const Elem& DLinkedList::front() const	// get front element
{
	return header->next->elem;
}

const Elem& DLinkedList::back() const		// get back element
{
	return trailer->prev->elem;
}


