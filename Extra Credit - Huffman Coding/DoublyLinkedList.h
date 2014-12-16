/*************************************************************************
 * AUTHOR       : James Marcu
 * STUDENT ID   : 374443
 * EXTRA CREDIT : Huffman Coding
 * CLASS        : CS1D
 * SECTION      : TTh 3:30 AM
 * DUE DATE     : 12/15/14
 *************************************************************************/
#ifndef DOUBLYLINKEDLIST_H_
#define DOUBLYLINKEDLIST_H_

#include "DoublyLinkedListNode.h"
//#include <cstddef>

//A doubly linked list
template <class ElemType>
class DoublyLinkedList
{
	typedef DLLNode<ElemType> node;

	public:
	   /********************************************
		* * * * CONSTRUCTORS AND DESTRUCTORS * * * *
		********************************************/
		DoublyLinkedList(); //Generic Constructor

	   /*******************************************
		* * * *          ACCESSORS          * * * *
		*******************************************/
		node* GetHead() const;         //Returns a pointer to the first
		                               //node in the list, NOT the sentinal
		                               //node.
		node* GetTail() const;         //Returns a pointer to the last node
		                               //in the list, NOT the sentinal node.
		bool  IsEmpty() const;         //Returns true if the list is empty.
		int   Size()    const;         //Returns the size of the list.
		ElemType& Front() const; //Returns the element of the first
		                               //node.
		const ElemType& Back()  const; //Returns the element of the last
		                               //node.

	   /*******************************************
		* * * *          MUTATORS           * * * *
		*******************************************/
		void Add(const ElemType& newElem,      //Adds a node with newElem before
				 node* beforeHere);            //another node in the list.
		void AddFront(const ElemType& newElem);//Adds a new node to the front.
		void AddBack(const ElemType& newElem); //Adds a new node to the back.
		void Delete(node* toDelete);           //Deletes a node from the list.
		void DeleteFront();                    //Deletes the front node.
		void DeleteBack();                     //Deletes the back node.

	private:
		node* head;//Points to a sentinel node at the front.
		node* tail;//Points to a sentinel node in the back.
		int   size;//Size of the list.
};

/*************************************************************************
 * FUNCTION DoublyLinkedList (Constructor)
 * ______________________________________________________________________
 * Generic constructor. Creates sentinel nodes at head and tail,
 * initializes size.
 * ______________________________________________________________________
 * PRE-CONDITIONS -
 * 	<none>
 *
 * POST-CONDITIONS -
 * 	Creates an instance of DoublyLinkedList.
 *************************************************************************/
template <class ElemType>
DoublyLinkedList<ElemType>::DoublyLinkedList()
{
	//Create the sentinel nodes
	head = new node;
	tail = new node;

	//Point them at eachother
	head->SetNext(tail);
	tail->SetPrev(head);

	//Set size to zero.
	size = 0;
}

/*************************************************************************
 * FUNCTION GetHead
 * ______________________________________________________________________
 * Returns a pointer to the first node in the list. It does NOT return
 * a pointer to the sentinel node, and it does NOT return the element
 * of that front node.
 * ______________________________________________________________________
 * PRE-CONDITIONS -
 * 	<none>
 *
 * POST-CONDITIONS -
 * 	Returns a pointer to the front node of the list.
 *************************************************************************/
template <class ElemType>
DLLNode<ElemType>* DoublyLinkedList<ElemType>::GetHead() const
{
	return head->GetNext();
}

/*************************************************************************
 * FUNCTION GetTail
 * ______________________________________________________________________
 * Returns a pointer to the last node in the list. It does NOT return
 * a pointer to the sentinel node, and it does NOT return the element
 * of that back node.
 * ______________________________________________________________________
 * PRE-CONDITIONS -
 * 	<none>
 *
 * POST-CONDITIONS -
 * 	Returns a pointer to the last node of the list.
 *************************************************************************/
template <class ElemType>
DLLNode<ElemType>* DoublyLinkedList<ElemType>::GetTail() const
{
	return tail->GetPrev();
}

/*************************************************************************
 * FUNCTION IsEmpty
 * ______________________________________________________________________
 * Returns true if the list is empty.
 * ______________________________________________________________________
 * PRE-CONDITIONS -
 * 	<none>
 *
 * POST-CONDITIONS -
 * 	Returns true if the list is empty.
 *************************************************************************/
template <class ElemType>
bool DoublyLinkedList<ElemType>::IsEmpty() const
{
	return size == 0;
}

/*************************************************************************
 * FUNCTION Size
 * ______________________________________________________________________
 * Returns the size of the list.
 * ______________________________________________________________________
 * PRE-CONDITIONS -
 * 	<none>
 *
 * POST-CONDITIONS -
 * 	Returns the size of the list.
 *************************************************************************/
template <class ElemType>
int DoublyLinkedList<ElemType>::Size() const
{
	return size;
}

/*************************************************************************
 * FUNCTION Front
 * ______________________________________________________________________
 * Returns the element of the front node in the list by constant
 * reference.
 * ______________________________________________________________________
 * PRE-CONDITIONS -
 * 	<none>
 *
 * POST-CONDITIONS -
 * 	Returns the element of the front node in the list.
 *************************************************************************/
template <class ElemType>
ElemType& DoublyLinkedList<ElemType>::Front() const
{
	return head->GetNext()->ModElem();
}

/*************************************************************************
 * FUNCTION Back
 * ______________________________________________________________________
 * Returns the element of the last node in the list by constant
 * reference.
 * ______________________________________________________________________
 * PRE-CONDITIONS -
 * 	<none>
 *
 * POST-CONDITIONS -
 * 	Returns the element of the last node in the list.
 *************************************************************************/
template <class ElemType>
const ElemType& DoublyLinkedList<ElemType>::Back() const
{
	return tail->GetPrev()->GetElem();
}

/*************************************************************************
 * FUNCTION Add
 * ______________________________________________________________________
 * Adds a new node to the list, whose data is provided, before the node
 * specified by the function call.
 * ______________________________________________________________________
 * PRE-CONDITIONS -
 * 	newElem    : The new node's element.
 * 	beforeHere : The node to place the new node before.
 *
 * POST-CONDITIONS -
 * 	Adds a new node to the list.
 *************************************************************************/
template <class ElemType>
void DoublyLinkedList<ElemType>::Add(const ElemType& newElem,//IN - The new node's
		                                                     //     element.
		                             node* beforeHere)       //IN - The node to
		                                                     //     place it
		                                                     //     before.
{
	//Create the new node. Set the data to newElem. Point it's next to
	//the node it comes before, point its prev to the node previous to
	//beforeHere.
	node* newNode = new node;
	newNode->SetNext(beforeHere);
	newNode->SetPrev(beforeHere->GetPrev());
	newNode->SetElem(newElem);

	//Have the nodes on either side point to beforeHere.
	beforeHere->GetPrev()->SetNext(newNode);
	beforeHere->SetPrev(newNode);

	//Increment size.
	size++;
}

/*************************************************************************
 * FUNCTION AddFront
 * ______________________________________________________________________
 * Adds a new node to the front of the list.
 * ______________________________________________________________________
 * PRE-CONDITIONS -
 * 	newElem: The element of the new node.
 *
 * POST-CONDITIONS -
 * 	Adds a new node to the front of the list.
 *************************************************************************/
template <class ElemType>
void DoublyLinkedList<ElemType>::AddFront(const ElemType& newElem)//IN - New node's element.
{
	Add(newElem, head->GetNext());
}

/*************************************************************************
 * FUNCTION AddBack
 * ______________________________________________________________________
 * Adds a new node to the back of the list.
 * ______________________________________________________________________
 * PRE-CONDITIONS -
 * 	newElem: The new node's element.
 *
 * POST-CONDITIONS -
 * 	Adds a new node to the back of the list.
 *************************************************************************/
template <class ElemType>
void DoublyLinkedList<ElemType>::AddBack(const ElemType& newElem)//IN - New node's element.
{
	Add(newElem, tail);
}

/*************************************************************************
 * FUNCTION Delete
 * ______________________________________________________________________
 * Removes a node from the list.
 * ______________________________________________________________________
 * PRE-CONDITIONS -
 * 	toDelete: Points to the node to be deleted.
 *
 * POST-CONDITIONS -
 * 	Deletes a node and removes it from the list.
 *************************************************************************/
template <class ElemType>
void DoublyLinkedList<ElemType>::Delete(DLLNode<ElemType>* toDelete)//IN - Node to be
                                                            //     deleted.
{
	//Have the list move around the node to be deleted
	toDelete->GetNext()->SetPrev(toDelete->GetPrev());
	toDelete->GetPrev()->SetNext(toDelete->GetNext());

	//Decrement size
	size--;

	//Delete the node
	delete toDelete;
}

/*************************************************************************
 * FUNCTION DeleteFront
 * ______________________________________________________________________
 * Deletes the front node in the list.
 * ______________________________________________________________________
 * PRE-CONDITIONS -
 * 	<none>
 *
 * POST-CONDITIONS -
 * 	Deletes the front node in the list.
 *************************************************************************/
template <class ElemType>
void DoublyLinkedList<ElemType>::DeleteFront()
{
	if (head->GetNext() != tail)
		Delete(head->GetNext());
}

/*************************************************************************
 * FUNCTION DeleteBack
 * ______________________________________________________________________
 * Deletes the back node in the list.
 * ______________________________________________________________________
 * PRE-CONDITIONS -
 * 	<none>
 *
 * POST-CONDITIONS -
 * 	Deletes the back node in the list.
 *************************************************************************/
template <class ElemType>
void DoublyLinkedList<ElemType>::DeleteBack()
{
	Delete(tail->GetPrev());
}

#endif /* DOUBLYLINKEDLIST_H_ */
