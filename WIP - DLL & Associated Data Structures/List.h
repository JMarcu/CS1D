/*************************************************************************
 * AUTHOR      : James Marcu
 * STUDENT ID  : 374443
 * ASS #      : 
 * CLASS       : CS1D
 * SECTION     : TTh 3:30 AM
 * DUE DATE    : 
 *************************************************************************/
#include "DoublyLinkedList.h"
  //#include "DoublyLinkedListNode.h"
    //#include <cstddef>

#ifndef LIST_H_
#define LIST_H_

template <typename ElemType>
class List
{
public:
	class Iterator;

	Iterator Begin() const;
	Iterator End()   const;
	int      Size()  const;
	bool     Empty() const;
	Iterator Search(const ElemType& key) const;

	void Insert(const ElemType& newElem, const Iterator& beforeHere);
	void InsertFront(const ElemType& newElem);
	void InsertBack(const ElemType& newElem);
	void Erase(Iterator toErase);
	void Erase(const ElemType& toErase);

private:
	DoublyLinkedList<ElemType> D;
};

template <typename ElemType>
class List<ElemType>::Iterator
{
	typedef DLLNode<ElemType> node;

	public:
		Iterator()
			{currentNode = NULL; endNode = new node;}
		~Iterator()
			{currentNode = NULL;
			endNode = NULL;}

		bool operator==(const Iterator& compareTo) const
			{return currentNode == compareTo.currentNode &&
			        endNode     == compareTo.IsEnd();}
		bool operator!=(const Iterator& compareTo) const
			{return currentNode != compareTo.currentNode ||
					endNode     != compareTo.IsEnd();}
		const ElemType& operator*() const
			{return currentNode->GetElem();}
		node* operator->() const
			{return currentNode;}

		Iterator& operator++()
		{
			if(currentNode->GetNext()->GetNext() != NULL)
				currentNode = currentNode->GetNext();
			else
				endNode = true;
			return *this;
		}
		Iterator& operator++(int)
		{
			Iterator saveState = *this;
			if(currentNode->GetNext()->GetNext() != NULL)
				currentNode = currentNode->GetNext();
			else
				endNode = true;
			return saveState;
		}
		Iterator& operator--()
		{
			if(endNode)
				endNode = false;
			else if(currentNode->GetPrev() != NULL)
				currentNode = currentNode->GetPrev();
			return *this;
		}
		Iterator& operator--(int)
		{
			Iterator saveState = *this;
			if(endNode)
				endNode = false;
			else if(currentNode->GetPrev() != NULL)
				currentNode = currentNode->GetPrev();
			return saveState;
		}

	private:
		friend class List<ElemType>;
		Iterator(node* pointHere, bool endFlag)
			{currentNode = pointHere;  endNode = endFlag;}
		node* GetCurrentNode() const
			{return currentNode;}
		bool IsEnd() const
			{return endNode;}

		node* currentNode;
		bool  endNode;
};

template <typename ElemType>
typename List<ElemType>::Iterator List<ElemType>::Begin() const
{
	return Iterator(D.GetHead(), false);
}

template <typename ElemType>
typename List<ElemType>::Iterator List<ElemType>::End() const
{
	return Iterator(D.GetTail(), true);
}

template <typename ElemType>
int List<ElemType>::Size() const
{
	return D.Size();
}

template <typename ElemType>
bool List<ElemType>::Empty() const
{
	return D.Empty();
}

template <typename ElemType>
typename List<ElemType>::Iterator List<ElemType>::Search(const ElemType& key) const
{
	Iterator searchIt;

	searchIt = Begin();

	while(searchIt != End() && searchIt->GetElem() != key)
	{
		++searchIt;
	}

	return searchIt;
}

template <typename ElemType>
void List<ElemType>::Insert(const ElemType& newElem, const Iterator& beforeHere)
{
	D.Add(newElem, beforeHere.GetCurrentNode());
}

template <typename ElemType>
void List<ElemType>::InsertFront(const ElemType& newElem)
{
	D.AddFront(newElem);
}

template <typename ElemType>
void List<ElemType>::InsertBack(const ElemType& newElem)
{
	D.AddBack(newElem);
}

#endif /* LIST_H_ */
