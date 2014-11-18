/*************************************************************************
 * AUTHOR      : James Marcu
 * STUDENT ID  : 374443
 * ASS #      : 
 * CLASS       : CS1D
 * SECTION     : TTh 3:30 AM
 * DUE DATE    : 
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

		void Push(const ElemType& toPush)
			{D.AddFront(toPush);}
		void Pop()
			{D.DeleteFront();}

	private:
		DoublyLinkedList<ElemType> D;
};



#endif /* STACK_H_ */
