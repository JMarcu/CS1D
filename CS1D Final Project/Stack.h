/*************************************************************************
 * CS1D Final Project
 * -----------------------------------------------------------------------
 * AUTHORS     : James Marcu & Phillip Doyle
 * STUDENT IDs : 374443      & 911579
 * CLASS       : CS1D
 * SECTION     : TTh 3:30 PM
 * DUE DATE    : 12/9/2014
 *************************************************************************/
#ifndef STACK_H_
#define STACK_H_

#include "DoublyLinkedList.h"
  //#include "DoublyLinkedListNode.h"
    //#include <cstddef>


//A stack made by wrapping a doubly linked list.
template <typename ElemType>
class Stack
{
	public:
	   /*******************************************
		* * * *          ACCESSORS          * * * *
		*******************************************/
		int Size() const                      //Returns the number of elements.
			{return D.Size();}
		bool Empty() const                    //Returns true if empty.
			{return D.IsEmpty();}
		const ElemType& Peek() const          //Returns the first element.
			{return D.GetHead()->GetElem();}
		bool Search(const ElemType& key) const//Returns true if the element was found.
		{
			DLLNode<ElemType>* searchPtr = D.GetHead();
			bool keepSearching = true;
			bool found = false;

			while(keepSearching)
			{
				if(searchPtr->GetElem() == key)
				{
					found = true;
					keepSearching = false;
				}
				else if(searchPtr->GetElem() == D.Back())
				{
					keepSearching = false;
				}
				else
				{
					searchPtr = searchPtr->GetNext();
				}
			}

			return found;
		}

	   /*******************************************
		* * * *          MUTATORS           * * * *
		*******************************************/
		void Push(const ElemType& toPush)//Add an element to the top.
			{D.AddFront(toPush);}
		void Pop()                       //Remove an element from the top.
			{D.DeleteFront();}

	private:
		DoublyLinkedList<ElemType> D;//A doubly linked list.
};

#endif /* STACK_H_ */
