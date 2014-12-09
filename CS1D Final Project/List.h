/*************************************************************************
 * CS1D Final Project
 * -----------------------------------------------------------------------
 * AUTHORS     : James Marcu & Phillip Doyle
 * STUDENT IDs : 374443      & 911579
 * CLASS       : CS1D
 * SECTION     : TTh 3:30 PM
 * DUE DATE    : 12/9/2014
 *************************************************************************/
#ifndef LIST_H_
#define LIST_H_

#include "DoublyLinkedList.h"
  //#include "DoublyLinkedListNode.h"
    //#include <cstddef>

//An unordered list created by wrapping a doubly linked list.
template <typename ElemType>
class List
{
public:
	class Iterator;//An iterator for the list.

   /*******************************************
	* * * *          ACCESSORS          * * * *
	*******************************************/
	Iterator  Begin() const;//Returns an iterator for the first element.
	Iterator  End()   const;//Returns an iterator for the second element.
	int       Size()  const;//Returns the number of elements.
	bool      Empty() const;//Returns true if the list is empty.
	const ElemType& Front();//Returns a reference to the element.
	Iterator  Search(const ElemType& key) const;//Returns an iterator to
	                                            //the element which matches
	                                            //key, or the end node if
	                                            //it couldn't be found.

   /*******************************************
	* * * *          MUTATORS           * * * *
	*******************************************/
	void Insert(const ElemType& newElem,      //Inserts a new element into
			    const Iterator& beforeHere);  //the list.
	void InsertFront(const ElemType& newElem);//Adds an element to the front.
	void InsertBack(const ElemType& newElem); //Adds an element to the back.
	void Erase(Iterator toErase);             //Erases an element.
	void Erase(const ElemType& toErase);      //Erases an element.

private:
	DoublyLinkedList<ElemType> D;//A doubly linked list.
};

//An iterator for the list class.
template <typename ElemType>
class List<ElemType>::Iterator
{
	typedef DLLNode<ElemType> node;

	public:
	   /*******************************************
	    * * * * CONSTRUCTORS AND DESTRUCTOR * * * *
	    *******************************************/
		Iterator()
			{currentNode = NULL; endNode = new node;}
		~Iterator()
			{currentNode = NULL;
			endNode = NULL;}

	   /*******************************************
		* * * *          ACCESSORS          * * * *
		*******************************************/
		//Comparison operator overriden to compare their nodes.
		bool operator==(const Iterator& compareTo) const
			{return currentNode == compareTo.currentNode &&
			        endNode     == compareTo.IsEnd();}
		bool operator!=(const Iterator& compareTo) const
			{return currentNode != compareTo.currentNode ||
					endNode     != compareTo.IsEnd();}

		//Overloaded to return a reference to the element.
		ElemType& operator*() const
			{return currentNode->ModElem();}
		node* operator->() const
			{return currentNode;}

		//Overloaded to move to the next and previous nodes in the list.
		Iterator& operator++()
		{
			if(currentNode->GetNext()->GetNext() != NULL)
				currentNode = currentNode->GetNext();
			else
				endNode = true;
			return *this;
		}
		Iterator operator++(int)
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
		Iterator operator--(int)
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

		//Private constructor for making end nodes.
		Iterator(node* pointHere, bool endFlag)
			{currentNode = pointHere;  endNode = endFlag;}
		//Returns a pointer to the iterators node.
		node* GetCurrentNode() const
			{return currentNode;}
		//Returns true if the iterator is an end node.
		bool IsEnd() const
			{return endNode;}

		node* currentNode;//Points to the iterators node.
		bool  endNode;    //True if the iterator points at the end node.
};

/*************************************************************************
 * FUNCTION Begin
 * ______________________________________________________________________
 * Returns an iterator to the first element in the list.
 * ______________________________________________________________________
 * PRE-CONDITIONS -
 * 	<none>
 *
 * POST-CONDITIONS -
 * 	Returns an iterator to the first element in the list.
 *************************************************************************/
template <typename ElemType>
typename List<ElemType>::Iterator List<ElemType>::Begin() const
{
	if(!D.IsEmpty())
	{
		return Iterator(D.GetHead(), false);
	}
	else
	{
		return End();
	}

}

/*************************************************************************
 * FUNCTION End
 * ______________________________________________________________________
 * Returns an iterator to the last element in the list.
 * ______________________________________________________________________
 * PRE-CONDITIONS -
 * 	<none>
 *
 * POST-CONDITIONS -
 * 	Returns an iterator to the last element in the list.
 *************************************************************************/
template <typename ElemType>
typename List<ElemType>::Iterator List<ElemType>::End() const
{
	return Iterator(D.GetTail(), true);
}

/*************************************************************************
 * FUNCTION Size
 * ______________________________________________________________________
 * Returns the number of elements.
 * ______________________________________________________________________
 * PRE-CONDITIONS -
 * 	<none>
 *
 * POST-CONDITIONS -
 * 	Returns the number of elements.
 *************************************************************************/
template <typename ElemType>
int List<ElemType>::Size() const
{
	return D.Size();
}

/*************************************************************************
 * FUNCTION Empty
 * ______________________________________________________________________
 * Returns true if the list is empty.
 * ______________________________________________________________________
 * PRE-CONDITIONS -
 * 	<none>
 *
 * POST-CONDITIONS -
 * 	Returns true if the list is empty.
 *************************************************************************/
template <typename ElemType>
bool List<ElemType>::Empty() const
{
	return D.IsEmpty();
}

/*************************************************************************
 * FUNCTION Search
 * ______________________________________________________________________
 * Returns an iterator pointing to the node which contains an element
 * matching the search key. The iterator will point to end if the key
 * could not be found.
 * ______________________________________________________________________
 * PRE-CONDITIONS -
 * 	key : The search key to search the list for.
 *
 * POST-CONDITIONS -
 * 	Returns an iterator pointing to the node which contains an element
 * matching the search key. The iterator will point to end if the key
 * could not be found.
 *************************************************************************/
template <typename ElemType>
typename List<ElemType>::Iterator List<ElemType>::Search(const ElemType& key) const
{
	//VARIABLE DECLERATIONS
	Iterator searchIt;//Iterates through the list.

	//Check every node to try and find the search key.
	searchIt = Begin();
	while(searchIt != End() && (*searchIt) != key)
	{
		++searchIt;
	}

	return searchIt;
}

/*************************************************************************
 * FUNCTION Front
 * ______________________________________________________________________
 * Returns a reference to the first element.
 * ______________________________________________________________________
 * PRE-CONDITIONS -
 * 	<none>
 *
 * POST-CONDITIONS -
 * 	Returns a reference to the first element.
 *************************************************************************/
template <typename ElemType>
const ElemType& List<ElemType>::Front()
{
	return D.Front();
}

/*************************************************************************
 * FUNCTION Insert
 * ______________________________________________________________________
 * Inserts a new element into the list, at the spot before beforeHere.
 * ______________________________________________________________________
 * PRE-CONDITIONS -
 * 	newElem     : The element to insert into the list.
 * 	beforeHere : Insert the element before here.
 *
 * POST-CONDITIONS -
 * 	Returns a reference to the first element.
 *************************************************************************/
template <typename ElemType>
void List<ElemType>::Insert(const ElemType& newElem,
		                    const Iterator& beforeHere)
{
	D.Add(newElem, beforeHere.GetCurrentNode());
}

/*************************************************************************
 * FUNCTION InsertFront
 * ______________________________________________________________________
 * Inserts a new element into the front of the list.
 * ______________________________________________________________________
 * PRE-CONDITIONS -
 * 	newElem : The element to insert into the list.
 *
 * POST-CONDITIONS -
 * 	Inserts a new element into the front of the list.
 *************************************************************************/
template <typename ElemType>
void List<ElemType>::InsertFront(const ElemType& newElem)
{
	D.AddFront(newElem);
}

/*************************************************************************
 * FUNCTION InsertBack
 * ______________________________________________________________________
 * Inserts a new element into the back of the list.
 * ______________________________________________________________________
 * PRE-CONDITIONS -
 * 	newElem : The element to insert into the list.
 *
 * POST-CONDITIONS -
 * 	Inserts a new element into the back of the list.
 *************************************************************************/
template <typename ElemType>
void List<ElemType>::InsertBack(const ElemType& newElem)
{
	D.AddBack(newElem);
}

/*************************************************************************
 * FUNCTION Erase
 * ______________________________________________________________________
 * Erases an element from the list.
 * ______________________________________________________________________
 * PRE-CONDITIONS -
 * 	toErase : The element to erase.
 *
 * POST-CONDITIONS -
 * 	Erases an element from the list.
 *************************************************************************/
template <typename ElemType>
void List<ElemType>::Erase(const ElemType& toErase)
{
	D.Delete(Search(toErase).GetCurrentNode());
}

/*************************************************************************
 * FUNCTION Erase
 * ______________________________________________________________________
 * Erases an element from the list.
 * ______________________________________________________________________
 * PRE-CONDITIONS -
 * 	toErase : An iterator to the element you want to erase.
 *
 * POST-CONDITIONS -
 * 	Erases an element from the list.
 *************************************************************************/
template <typename ElemType>
void List<ElemType>::Erase(List<ElemType>::Iterator toErase)
{
	D.Delete(toErase.GetCurrentNode());
}

#endif /* LIST_H_ */
