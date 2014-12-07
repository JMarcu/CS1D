/*************************************************************************
 * CS1D Final Project
 * -----------------------------------------------------------------------
 * AUTHORS     : James Marcu & Phillip Doyle
 * STUDENT IDs : 374443      & 911579
 * CLASS       : CS1D
 * SECTION     : TTh 3:30 AM
 * DUE DATE    : 12/9/2014
 *************************************************************************/
#ifndef STACK_H_
#define STACK_H_

#include "DoublyLinkedList.h"
  //#include "DoublyLinkedListNode.h"
    //#include <cstddef>

template <typename ElemType>
class Stack
{
	public:
		int Size() const
			{return D.Size();}
		bool Empty() const
			{return D.IsEmpty();}
		const ElemType& Peek() const
			{return D.GetHead()->GetElem();}
		bool Search(const ElemType& key) const
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

		void Push(const ElemType& toPush)
			{D.AddFront(toPush);}
		void Pop()
			{D.DeleteFront();}

	private:
		DoublyLinkedList<ElemType> D;
};



#endif /* STACK_H_ */
