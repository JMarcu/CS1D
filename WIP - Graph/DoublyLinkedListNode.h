/*************************************************************************
 * AUTHOR      : James Marcu
 * STUDENT ID  : 374443
 * ASS #5      : Binary Trees
 * CLASS       : CS1D
 * SECTION     : TTh 3:30 AM
 * DUE DATE    : 9/23/2014
 *************************************************************************/

#ifndef DOUBLYLINKEDLISTNODE_H_
#define DOUBLYLINKEDLISTNODE_H_

#include <cstddef>

//A node for a doubly linked list
template <class ElemType>
class DLLNode
{
	typedef DLLNode <ElemType> node;

	public:
	   /********************************************
		* * * * CONSTRUCTORS AND DESTRUCTORS * * * *
		********************************************/
		DLLNode(); //Default constructor
		~DLLNode();//Destructor

	   /*******************************************
		* * * *          ACCESSORS          * * * *
		*******************************************/
		node* GetNext() const;          //Gets the value of next.
		node* GetPrev() const;          //Gets the value of prev.
		const ElemType& GetElem() const;//Gets the value of elem.

	   /*******************************************
		* * * *          MUTATORS           * * * *
		*******************************************/
		void SetNext(node* nextNode);      //Sets the value of next.
		void SetPrev(node* prevNode);      //Sets the value of prev.
		void SetElem(const ElemType& data);//Sets the value of elem.

	private:
		node*    next;//Points to the next node in the list.
		node*    prev;//Points to the previous node in the list.
		ElemType elem;//The data stored in the node.
};

/*************************************************************************
 * FUNCTION Node (Constructor)
 * ______________________________________________________________________
 * Generic constructor. Points next and prev to null.
 * ______________________________________________________________________
 * PRE-CONDITIONS -
 * 	<none>
 *
 * POST-CONDITIONS -
 * 	Creates an instance of node.
 *************************************************************************/
template <class ElemType>
DLLNode<ElemType>::DLLNode()
{
	prev = NULL;
	next = NULL;
}

/*************************************************************************
 * FUNCTION ~Node
 * ______________________________________________________________________
 * Sets next and prev to null before destroying the node.
 * ______________________________________________________________________
 * PRE-CONDITIONS -
 * 	<none>
 *
 * POST-CONDITIONS -
 * 	Sets next and prev to null before destroying the node.
 *************************************************************************/
template <class ElemType>
DLLNode<ElemType>::~DLLNode()
{
	prev = NULL;
	next = NULL;
}

/*************************************************************************
 * FUNCTION GetNext
 * ______________________________________________________________________
 * Returns a pointer to next.
 * ______________________________________________________________________
 * PRE-CONDITIONS -
 * 	<none>
 *
 * POST-CONDITIONS -
 * 	next: Returned by value to calling function.
 *************************************************************************/
template <class ElemType>
DLLNode<ElemType>* DLLNode<ElemType>::GetNext() const
{
	return next;
}

/*************************************************************************
 * FUNCTION GetPrev
 * ______________________________________________________________________
 * Returns a pointer to prev.
 * ______________________________________________________________________
 * PRE-CONDITIONS -
 * 	<none>
 *
 * POST-CONDITIONS -
 * 	prev: Returned by value to calling function.
 *************************************************************************/
template <class ElemType>
DLLNode<ElemType>* DLLNode<ElemType>::GetPrev() const
{
	return prev;
}

/*************************************************************************
 * FUNCTION GetElem
 * ______________________________________________________________________
 * Returns the address of the node's data as a constant.
 * ______________________________________________________________________
 * PRE-CONDITIONS -
 * 	<none>
 *
 * POST-CONDITIONS -
 * 	elem: Returned by constant reference to calling function.
 *************************************************************************/
template <class ElemType>
const ElemType& DLLNode<ElemType>::GetElem() const
{
	return elem;
}

/*************************************************************************
 * FUNCTION SetNext
 * ______________________________________________________________________
 * Sets the value of next.
 * ______________________________________________________________________
 * PRE-CONDITIONS -
 * 	nextNode: The address of the node to set next to.
 *
 * POST-CONDITIONS -
 * 	next: Will be set to nextNode.
 *************************************************************************/
template <class ElemType>
void DLLNode<ElemType>::SetNext(node* nextNode)
{
	next = nextNode;
}

/*************************************************************************
 * FUNCTION SetPrev
 * ______________________________________________________________________
 * Sets the value of prev.
 * ______________________________________________________________________
 * PRE-CONDITIONS -
 * 	prevNode: The address of the node to set prev to.
 *
 * POST-CONDITIONS -
 * 	prev: Will be set to prevNode.
 *************************************************************************/
template <class ElemType>
void DLLNode<ElemType>::SetPrev(node* prevNode)
{
	prev = prevNode;
}

/*************************************************************************
 * FUNCTION SetPrev
 * ______________________________________________________________________
 * Sets the value of prev.
 * ______________________________________________________________________
 * PRE-CONDITIONS -
 * 	prevNode: The address of the node to set prev to.
 *
 * POST-CONDITIONS -
 * 	prev: Will be set to prevNode.
 *************************************************************************/
template <class ElemType>
void DLLNode<ElemType>::SetElem(const ElemType& newElem)
{
	const ElemType* elemPtr = &newElem;
	elem = *elemPtr;
}

#endif /* DOUBLYLINKEDLIST_H_ */
