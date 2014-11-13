/*************************************************************************
 * AUTHOR      : James Marcu
 * STUDENT ID  : 374443
 * ASS #12     : Graphs
 * CLASS       : CS1D
 * SECTION     : TTh 3:30 AM
 * DUE DATE    : 11/13/2014
 *************************************************************************/
#include "DoublyLinkedList.h"

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
	void InsertFront(ElemType& newElem);
	void InsertBack(ElemType& newElem);
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
			{currentNode = NULL; delete endNode; endNode = NULL;}

		bool operator==(const Iterator& compareTo) const
			{return currentNode != endNode ?
					currentNode == compareTo.currentNode :
			        compareTo.currentNode == compareTo.endNode;}
		bool operator!=(const Iterator& compareTo) const
			{return currentNode != endNode ?
					currentNode != compareTo.currentNode :
					compareTo.currentNode != compareTo.endNode;}
		ElemType& operator*()
			{return currentNode->GetElem();}
		ElemType& operator->() const
			{return currentNode->GetElem();}

		Iterator& operator++()
		{
			if(currentNode->GetNext() != NULL)
				currentNode = currentNode->GetNext();
			else if(currentNode != endNode)
				currentNode = endNode;
			return *this;
		}
		Iterator& operator++(int)
		{
			Iterator saveState = *this;
			if(currentNode->GetNext() != NULL)
				currentNode = currentNode->GetNext();
			else if(currentNode != endNode)
				currentNode = endNode;
			return saveState;
		}
		Iterator& operator--()
		{
			if(currentNode->GetPrev() != NULL)
				currentNode = currentNode->GetPrev();
			return *this;
		}
		Iterator& operator--(int)
		{
			Iterator saveState = *this;
			if(currentNode->GetPrev() != NULL)
				currentNode = currentNode->GetPrev();
			return saveState;
		}

	private:
		friend class List<ElemType>;
		Iterator(node* pointHere)
			{currentNode = pointHere; endNode = new node;}
		node* GetCurrentNode() const
			{return currentNode;}

		node* currentNode;
		node* endNode;
};

template <typename ElemType>
typename List<ElemType>::Iterator List<ElemType>::Begin() const
{
	return Iterator(D.GetHead());
}

template <typename ElemType>
typename List<ElemType>::Iterator List<ElemType>::End() const
{
	return Iterator(D.GetTail());
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

	while(searchIt != End() && searchIt->GetElem != key)
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
void List<ElemType>::InsertFront(ElemType& newElem)
{
	D.AddFront(newElem);
}

template <typename ElemType>
void List<ElemType>::InsertBack(ElemType& newElem)
{
	D.AddBack(newElem);
}

#endif /* LIST_H_ */
