/*
 * SkipList.h
 *
 *  Created on: Oct 16, 2014
 *      Author: jmarcu0
 */

#ifndef SKIPLIST_H_
#define SKIPLIST_H_

#include <cstddef>
#include <cstdlib>
#include <iostream>
using namespace std;

enum Infinity{
	NOT_INF, POS_INF, NEG_INF
};

template <typename ElemType>
class SkipNode
{
	typedef SkipNode<ElemType> node;

	public:
		SkipNode(int levelInit)
		{level  = levelInit; isInf = NOT_INF;
		 up     = NULL; down   = NULL; left   = NULL; right  = NULL;}
		SkipNode(const ElemType& elemInit, int levelInit)
		{level  = levelInit; element = elemInit; isInf = NOT_INF;
		 up     = NULL; down   = NULL; left   = NULL; right  = NULL;}
		SkipNode(int levelInit, Infinity posOrNeg)
		{level  = levelInit; isInf = posOrNeg;
		 up     = NULL; down   = NULL; left   = NULL; right  = NULL;}

		int   GetLevel() const
		{return level;}
		node* GetUp() const
		{return up;}
		node* GetDown() const
		{return down;}
		node* GetLeft() const
		{return left;}
		node* GetRight() const
		{return right;}
		const ElemType& GetElem() const
		{return isInf == NOT_INF ? element : NULL;}
		Infinity GetInf() const
		{return isInf;}
		bool operator>(node* compareTo) const
		{return compareTo->GetInf() != POS_INF &&
				element > compareTo->GetElem();}
		bool operator>(ElemType compareTo) const
		{return element > compareTo;}
		bool operator>=(node* compareTo) const
		{return compareTo->GetInf() == POS_INF ? isInf == POS_INF : true &&
				element >= compareTo->GetElem();}
		bool operator>=(ElemType compareTo) const
		{return element >= compareTo;}
		bool operator<(node* compareTo) const
		{return compareTo->GetInf() != NEG_INF &&
				element > compareTo->GetElem();}
		bool operator<(ElemType compareTo) const
		{return element > compareTo;}
		bool operator<=(node* compareTo) const
		{return compareTo->GetInf() == NEG_INF ? isInf == NEG_INF : true &&
				element >= compareTo->GetElem();}
		bool operator<=(ElemType compareTo) const
		{return element >= compareTo;}

		void SetUp(node* newUp)
		{up = newUp;}
		void SetDown(node* newDown)
		{down = newDown;}
		void SetLeft(node* newLeft)
		{left = newLeft;}
		void SetRight(node* newRight)
		{right = newRight;}
		void SetElem(const ElemType& newElem)
		{element = newElem;}

	private:
		int      level;
		node*    up;
		node*    down;
		node*    left;
		node*    right;
		ElemType element;
		Infinity isInf;
};

template <typename ElemType>
class SkipList
{
	typedef SkipNode<ElemType> node;

	public:
		class Iterator;

		SkipList();

		int      Size() const;
		bool     Empty() const;
		Iterator Search(const ElemType& searchKey) const;
		node* Begin() const;
		node* End() const;

		node* Insert(const ElemType& newElem);
		bool     Delete(const ElemType& toDelete);
		void     Delete(Iterator toDelete);

	private:
		int   numberOfLevels;
		int   size;
		node* begin;
		node* end;

		void AddLevel();
};

template <typename ElemType>
class SkipList<ElemType>::Iterator
{
	public:
		Iterator()
		{currentNode = NULL;}
		Iterator(node* pointTo)
		{currentNode = pointTo;}

		bool  operator==(Iterator compareTo) const
		{return currentNode == *compareTo;}
		bool  operator!=(Iterator compareTo) const
		{return currentNode != *compareTo;}
		node* operator*()  const
		{return currentNode;}
		node* operator->() const
		{return currentNode;}

		Iterator operator++()
		{	if (currentNode->GetRight() != NULL)
				currentNode = currentNode->GetRight();
			else{
				DropDown();
				while (currentNode->GetLeft() != NULL)
					currentNode = currentNode->GetLeft();
			}
			return Iterator(currentNode);
		}
		Iterator operator++(int)
		{	Iterator copy(currentNode);
			if (currentNode->GetRight() != NULL)
				currentNode = currentNode->GetRight();
			else{
				ClimbUp();
				while (currentNode->GetLeft() != NULL)
					currentNode = currentNode->GetLeft();
			}
			return copy;
		}
		Iterator operator--()
		{	if (currentNode->GetLeft() != NULL)
				currentNode = currentNode->GetLeft();
			else{
				DropDown();
				while (currentNode->GetRight() != NULL)
					currentNode = currentNode->GetRight();
			}
			return Iterator(currentNode);
		}
		Iterator operator--(int)
		{	Iterator copy(currentNode);
			if (currentNode->GetLeft() != NULL)
				currentNode = currentNode->GetLeft();
			else{
				DropDown();
				while (currentNode->GetRight() != NULL)
					currentNode = currentNode->GetRight();
			}
			return copy;
		}
		void DropDown()
		{	if (currentNode->GetDown() != NULL)
		    {currentNode = currentNode->GetDown();}
		}
		void ClimbUp()
		{	if (currentNode->GetUp() != NULL)
			{currentNode = currentNode->GetUp();}
		}

	private:
		node* currentNode;
};

template <typename ElemType>
SkipList<ElemType>::SkipList()
{
	numberOfLevels = 1;
	size           = 0;

	begin = new node(1, NEG_INF);
	end   = new node(1, POS_INF);
	begin->SetRight(end);
	end  ->SetLeft(begin);
}

template <typename ElemType>
int SkipList<ElemType>::Size() const
{
	return size;
}

template <typename ElemType>
bool SkipList<ElemType>::Empty() const
{
	return size == 0;
}

template <typename ElemType>
typename SkipList<ElemType>::Iterator SkipList<ElemType>::Search(const ElemType& searchKey) const
{
	Iterator searchIt;
	bool     found;

	searchIt   = Begin();
	found      = false;

	while (!found && *searchIt != NULL)
	{
		if (*searchIt == searchKey)
		{
			found      = true;
		}
		else
		{
			if (searchIt->GetRight() > searchKey)
			{
				searchIt.DropDown();
			}

			++searchIt;
		}
	}

	if (!found)
	{
		searchIt = End();
	}

	return searchIt;
}

template <typename ElemType>
SkipNode<ElemType>* SkipList<ElemType>::Begin() const
{
	return begin;
}

template <typename ElemType>
SkipNode<ElemType>* SkipList<ElemType>::End() const
{
	return end;
}

template <typename ElemType>
SkipNode<ElemType>* SkipList<ElemType>::Insert(const ElemType& newElem)
{
	node* insertPtr;
	int   insertLevel;
	node* newNode;
	node* lastInsert;

	insertLevel = 1;
	lastInsert  = NULL;

	while (rand() % 2 == 1)
	{
		++insertLevel;
	}

	while (numberOfLevels < insertLevel)
	{
		AddLevel();
	}

	insertPtr = Begin();
	for(int currentLevel = numberOfLevels; currentLevel > 0; --currentLevel)
	{
		cout << "asdf1";
		cin.ignore(1000, '\n');
		while(*(insertPtr->GetRight()) < newElem)
		{
			cout << "asdf2";
			cin.ignore(1000, '\n');
			insertPtr = insertPtr->GetRight();
		}
		cout << "asdf3";
		cin.ignore(1000, '\n');
		if(insertPtr->GetLevel() <= insertLevel)
		{
			cout << "asdf4";
			cin.ignore(1000, '\n');
			newNode = new node(newElem, insertPtr->GetLevel());
			newNode->SetRight(insertPtr->GetRight());
			newNode->SetLeft(insertPtr);
			newNode->SetUp(lastInsert);
			if (insertPtr->GetLevel() != insertLevel)
			{
				lastInsert->SetDown(newNode);
			}

			insertPtr->GetRight()->SetLeft(newNode);
			insertPtr->SetRight(newNode);
		}

		insertPtr = insertPtr->GetDown();
		lastInsert = newNode;
	}

	newNode->SetDown(NULL);

	++size;

	return newNode;
}

template <typename ElemType>
bool SkipList<ElemType>::Delete(const ElemType& toDelete)
{
	Iterator delPtr;
	bool     success;

	delPtr = Search(toDelete);

	if (delPtr != End())
	{
		Delete(delPtr);
		success = true;
	}
	else
	{
		success = false;
	}

	return success;
}

template <typename ElemType>
void SkipList<ElemType>::Delete(Iterator toDelete)
{
	int   levelsToDelete;
	node* delPtr;

	levelsToDelete = toDelete->GetLevel();

	for (;levelsToDelete > 0; --levelsToDelete)
	{
		toDelete->GetRight()->SetLeft (toDelete->GetRight());
		toDelete->GetLeft() ->SetRight(toDelete->GetLeft());

		delPtr = *toDelete;
		toDelete.DropDown();

		delete delPtr;
	}

	--size;
}

template <typename ElemType>
void SkipList<ElemType>::AddLevel()
{
	node* addIt;
	node* posInfPtr;

	addIt = Begin();

	++numberOfLevels;

	addIt->SetUp(new node(numberOfLevels, NEG_INF));
	addIt->GetUp()->SetDown(addIt);
	addIt = addIt->GetUp();

	addIt->SetRight(new node(numberOfLevels, POS_INF));
	addIt->GetRight()->SetLeft(addIt);

	posInfPtr = addIt->GetDown();
	while (posInfPtr->GetInf() != POS_INF)
	{
		posInfPtr = posInfPtr->GetRight();
	}

	addIt->GetRight()->SetDown(posInfPtr);
	posInfPtr->SetUp(addIt->GetRight());

	begin = addIt;
}

#endif /* SKIPLIST_H_ */
