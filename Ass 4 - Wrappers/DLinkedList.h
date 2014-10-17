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

#ifndef DLINKEDLIST_H_
#define DLINKEDLIST_H_

#include <string>
using namespace std;

// list element type
typedef string Elem;

// doubly linked list node
class DNode
{
	private:
    	Elem elem;					// node element value
    	DNode* prev;				// previous node in list
    	DNode* next;				// next node in list
    	friend class DLinkedList;	// allow DLinkedList access
 };

// doubly linked list
class DLinkedList
{
	public:
    	DLinkedList();	// constructor
    	~DLinkedList();	// destructor

    	bool  empty() const;		  // is list empty?
    	const Elem& front() const;	  // get front element
    	const Elem& back() const;	  // get back element
        void  addFront(const Elem& e);// add to front of list
        void  addBack(const Elem& e); // add to back of list
        void  removeFront();		  // remove from front
        void  removeBack();			  // remove from back

	private:
        DNode* header;	// list sentinels
        DNode* trailer;

	protected:// local utilities
        void add(DNode* v, const Elem& e);// insert new node before v
        void remove(DNode* v);			  // remove node v
 };

#endif /* DLINKEDLIST_H_ */
