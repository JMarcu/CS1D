/*************************************************************************
 * AUTHOR      : James Marcu
 * STUDENT ID  : 374443
 * ASS #      : 
 * CLASS       : CS1D
 * SECTION     : TTh 3:30 AM
 * DUE DATE    : 
 *************************************************************************/
#ifndef HASHTABLE_H_
#define HASHTABLE_H_

#include <iostream>
#include <sstream>
using namespace std;

template <typename KeyType>
int FirstHash(KeyType key)
{
	return key % 17;
}

template <typename KeyType>
int SecondHash(KeyType key)
{
	return 13 - (key % 13);
}

template <typename KeyType, typename ElemType>
class HashNode
{
	public:
		HashNode(const KeyType& keyInit, const ElemType& valueInit)
			{key = keyInit; value = valueInit; deleted = false;}
		HashNode(bool isEnd)
			{deleted = true; end = true;}

		const KeyType& GetKey() const
			{if (!deleted)
				return key;
			 else
				 throw EmptyNode();
			}
		const ElemType& GetValue() const
			{if (!deleted)
				return value;
			 else
				 throw EmptyNode();
			}
		bool Deleted() const
			{return deleted;}
		bool End() const
			{return end;}

		void SetKey(const KeyType& newKey)
			{key = newKey;}
		void SetValue(const ElemType& newValue)
			{value = newValue;}
		void Delete()
			{deleted = true;}

	private:
		KeyType  key;
		ElemType value;
		bool     deleted;
		bool     end;

		class EmptyNode{};
};

template <typename KeyType, typename ElemType>
class HashTable
{
	typedef HashNode<KeyType, ElemType> node;

	public:
		class Iterator
		{
			public:
				Iterator();
				Iterator(int posInit);

				int   GetPosition() const;
				node* operator*() const;
				node* operator->() const;
				bool      operator==(Iterator& compare) const;
				bool      operator!=(Iterator& compare) const;

				Iterator  operator++();
				Iterator  operator++(int);
				Iterator  operator--();
				Iterator  operator--(int);

			private:
				int position;
		};

		HashTable(int(*hashOne)(const KeyType&) = FirstHash, int(*hashTwo)(const KeyType&) = SecondHash);

		int Size() const;
		bool Empty() const;
		Iterator Find(const KeyType& key) const;
		string Print() const;
		Iterator Begin() const;
		Iterator End() const;

		Iterator Put(const KeyType& key, const ElemType& newElem);
		bool Erase(const KeyType& key);
		bool Erase(Iterator& position);

	private:
		node*     bucket[18];
		int       size;
		int       (*HashOne)(const KeyType&);
		int       (*HashTwo)(const KeyType&);
		int       Hash(const KeyType& key) const;

		class KeyNotFound{};
		class BucketFull{};
};

template <typename KeyType, typename ElemType>
HashTable<KeyType, ElemType>::HashTable(int(*hashOneInit)(const KeyType&), int(*hashTwoInit)(const KeyType&))
{
	HashOne = hashOneInit;
	HashTwo = hashTwoInit;
	size    = 0;

	for (int i = 0; i < 17; i++)
	{
		bucket[i] = NULL;
	}

	bucket[18] = new HashNode<KeyType, ElemType>(true);
}

template <typename KeyType, typename ElemType>
int HashTable<KeyType, ElemType>::Size() const
{
	return size;
}

template <typename KeyType, typename ElemType>
bool HashTable<KeyType, ElemType>::Empty() const
{
	return size == 0;
}

template <typename KeyType, typename ElemType>
typename HashTable<KeyType, ElemType>::Iterator HashTable<KeyType, ElemType>::Find(const KeyType& key) const
{
	//VARIABLE DECLERATIONS
	int j;
	int index;
	bool keepSearching;
	bool keyFound;

	//VARIABLE INITIALIZATIONS
	j = 0;
	keepSearching = true;
	keyFound      = false;

	do
	{
		index = (HashOne(key) + (j * HashTwo(key))) % 17;
		++j;

		if (j >= 17)
		{
			keepSearching = false;
		}

		if (bucket[index] != NULL && !bucket[index]->Deleted())
		{
				if (bucket[index]->GetKey() == key)
				{
					keepSearching = false;
					keyFound      = true;
				}
		}

	}while (keepSearching);

	if (keyFound)
	{
		return Iterator(index);
	}
	else
	{
		return Iterator(18);
	}
}

template <typename KeyType, typename ElemType>
string HashTable<KeyType, ElemType>::Print() const
{
	int index;
	ostringstream ss;

	index      = 0;

	if (bucket[index] == NULL || bucket[index]->Deleted())
	{
		ss << "EMPTY";
	}
	else
	{
		ss << bucket[index]->GetValue();
	}

	for (index = 1; index < 17; ++index)
	{
		if (bucket[index] == NULL || bucket[index]->Deleted())
		{
			ss << ", EMPTY";
		}
		else
		{
			ss << ", " << bucket[index]->GetValue();
		}
	}

	return ss.str();
}

template <typename KeyType, typename ElemType>
typename HashTable<KeyType, ElemType>::Iterator HashTable<KeyType, ElemType>::Begin() const
{
	return Iterator(0);
}

template <typename KeyType, typename ElemType>
typename HashTable<KeyType, ElemType>::Iterator HashTable<KeyType, ElemType>::End() const
{
	return Iterator(18);
}

template <typename KeyType, typename ElemType>
typename HashTable<KeyType, ElemType>::Iterator HashTable<KeyType, ElemType>::Put(const KeyType& key, const ElemType& newElem)
{
	int index;

	try
	{
		index = Hash(key);

		if (bucket[index] != NULL)
		{
			delete bucket[index];
		}

		bucket[index] = new node(key, newElem);

		++size;

		return Iterator(index);
	}
	catch (BucketFull& err)
	{
	}
}

template <typename KeyType, typename ElemType>
bool HashTable<KeyType, ElemType>::Erase(const KeyType& key)
{
	int  index;
	bool success;

	index = Find(key).GetPosition();
	success = false;

	if (bucket[index] != NULL &&
		!bucket[index]->Deleted() &&
		bucket[index]->GetKey() == key)
	{
		bucket[index]->Delete();
		--size;
		success = true;
	}

	return success;
}

template <typename KeyType, typename ElemType>
bool HashTable<KeyType, ElemType>::Erase(Iterator& position)
{
	bool success;

	success = false;

	if (bucket[position.GetPosition()] != NULL)
	{
		bucket[position.GetPosition()]->Delete();
		--size;
		success = true;
	}

	return success;
}

template <typename KeyType, typename ElemType>
int HashTable<KeyType, ElemType>::Hash(const KeyType& key) const
{
	//VARIABLE DECLERATIONS
	int j;
	int index;
	bool keepSearching;

	//VARIABLE INITIALIZATIONS
	j = 0;
	keepSearching = true;

	do
	{
		index = (HashOne(key) + (j * HashTwo(key))) % 17;
		++j;

		if (j >= 17)
		{
			keepSearching = false;
		}

		if (bucket[index] != NULL && !bucket[index]->Deleted())
		{
				if (bucket[index]->GetKey() == key)
				{
					keepSearching = false;
				}
				else if (j >= 17)
				{
					throw BucketFull();
				}
		}
		else
		{
			keepSearching = false;
		}

	}while (keepSearching);

	return index;
}

template <typename KeyType, typename ElemType>
HashTable<KeyType, ElemType>::Iterator::Iterator()
{
	position = 0;
}

template <typename KeyType, typename ElemType>
HashTable<KeyType, ElemType>::Iterator::Iterator(int posInit)
{
	position = posInit;
}

template <typename KeyType, typename ElemType>
int HashTable<KeyType, ElemType>::Iterator::GetPosition() const
{
	return position;
}

template <typename KeyType, typename ElemType>
HashNode<KeyType, ElemType>* HashTable<KeyType, ElemType>::Iterator::operator*() const
{
	return bucket[position];
}

template <typename KeyType, typename ElemType>
HashNode<KeyType, ElemType>* HashTable<KeyType, ElemType>::Iterator::operator->() const
{
	return bucket[position];
}

template <typename KeyType, typename ElemType>
bool HashTable<KeyType, ElemType>::Iterator::operator==(Iterator& compare) const
{
	return bucket[position] == *compare;
}

template <typename KeyType, typename ElemType>
bool HashTable<KeyType, ElemType>::Iterator::operator!=(Iterator& compare) const
{
	return bucket[position] != *compare;
}

template <typename KeyType, typename ElemType>
typename HashTable<KeyType, ElemType>::Iterator HashTable<KeyType, ElemType>::Iterator::operator++()
{
	return Iterator(bucket[++position]);
}

template <typename KeyType, typename ElemType>
typename HashTable<KeyType, ElemType>::Iterator HashTable<KeyType, ElemType>::Iterator::operator++(int)
{
	return Iterator(bucket[position++]);
}

template <typename KeyType, typename ElemType>
typename HashTable<KeyType, ElemType>::Iterator HashTable<KeyType, ElemType>::Iterator::operator--()
{
	return Iterator(bucket[--position]);
}

template <typename KeyType, typename ElemType>
typename HashTable<KeyType, ElemType>::Iterator HashTable<KeyType, ElemType>::Iterator::operator--(int)
{
	return Iterator(bucket[position--]);
}

#endif /* HASHTABLE_H_ */
