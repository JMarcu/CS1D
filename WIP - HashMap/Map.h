/*************************************************************************
 * AUTHOR      : James Marcu
 * STUDENT ID  : 374443
 * ASS #      : 
 * CLASS       : CS1D
 * SECTION     : TTh 3:30 AM
 * DUE DATE    : 
 *************************************************************************/
#ifndef MAP_H_
#define MAP_H_

#include "HashTable.h"

template <typename KeyType, typename ElemType>
class Map
{
	public:
		class Iterator
		{
			typedef HashNode<KeyType, ElemType> node;

			public:
				Iterator();
				Iterator(int posInit);

				int GetPosition() const;
				node* operator*() const;
				node* operator->() const;
				bool operator==(Iterator& compare) const;
				bool operator!=(Iterator& compare) const;

				Iterator operator++();
				Iterator operator++(int);
				Iterator operator--();
				Iterator operator--(int);

			private:
				typename HashTable<KeyType, ElemType>::Iterator* it;

				typename HashTable<KeyType, ElemType>::Iterator GetIt() const;
		};

		int      Size() const;
		bool     Empty() const;
		Iterator Find(const KeyType& key) const;
		Iterator Begin() const;
		Iterator End() const;
		string   Print() const;

		Iterator Put(const KeyType& key, const ElemType& value);
		void     Erase(const KeyType& key);
		void     Erase(Iterator& position);

	private:
		HashTable<KeyType, ElemType> table;
};

template <typename KeyType, typename ElemType>
int Map<KeyType, ElemType>::Size() const
{
	return table.Size();
}

template <typename KeyType, typename ElemType>
bool Map<KeyType, ElemType>::Empty() const
{
	return table.Empty();
}

template <typename KeyType, typename ElemType>
typename Map<KeyType, ElemType>::Iterator Map<KeyType, ElemType>::Find(const KeyType& key) const
{
	return Iterator(table.Find(key).GetPosition());
}

template <typename KeyType, typename ElemType>
string Map<KeyType, ElemType>::Print() const
{
	return table.Print();
}

template <typename KeyType, typename ElemType>
typename Map<KeyType, ElemType>::Iterator Map<KeyType, ElemType>::Put(const KeyType& key, const ElemType& value)
{
	return Iterator((table.Put(key, value).GetPosition()));
}

template <typename KeyType, typename ElemType>
void Map<KeyType, ElemType>::Erase(const KeyType& key)
{
	table.Erase(key);
}

template <typename KeyType, typename ElemType>
void Map<KeyType, ElemType>::Erase(Iterator& position)
{
	table.Erase(position.GetIt());
}

template <typename KeyType, typename ElemType>
Map<KeyType, ElemType>::Iterator::Iterator()
{
	it(0);
}

template <typename KeyType, typename ElemType>
Map<KeyType, ElemType>::Iterator::Iterator(int posInit)
{
	it = new typename HashTable<KeyType, ElemType>::Iterator (posInit);
}

template <typename KeyType, typename ElemType>
int Map<KeyType, ElemType>::Iterator::GetPosition() const
{
	return it->GetPosition();
}

template <typename KeyType, typename ElemType>
HashNode<KeyType, ElemType>* Map<KeyType, ElemType>::Iterator::operator*() const
{
	return *it;
}

template <typename KeyType, typename ElemType>
HashNode<KeyType, ElemType>* Map<KeyType, ElemType>::Iterator::operator->() const
{
	return *it;
}

template <typename KeyType, typename ElemType>
bool Map<KeyType, ElemType>::Iterator::operator==(Iterator& compare) const
{
	return it == compare;
}

template <typename KeyType, typename ElemType>
bool Map<KeyType, ElemType>::Iterator::operator!=(Iterator& compare) const
{
	return it != compare;
}

template <typename KeyType, typename ElemType>
typename Map<KeyType, ElemType>::Iterator Map<KeyType, ElemType>::Iterator::operator++()
{
	return ++it;
}

template <typename KeyType, typename ElemType>
typename Map<KeyType, ElemType>::Iterator Map<KeyType, ElemType>::Iterator::operator++(int)
{
	return it++;
}

template <typename KeyType, typename ElemType>
typename Map<KeyType, ElemType>::Iterator Map<KeyType, ElemType>::Iterator::operator--()
{
	return --it;
}

template <typename KeyType, typename ElemType>
typename Map<KeyType, ElemType>::Iterator Map<KeyType, ElemType>::Iterator::operator--(int)
{
	return it--;
}

template <typename KeyType, typename ElemType>
typename HashTable<KeyType, ElemType>::Iterator Map<KeyType, ElemType>::Iterator::GetIt() const
{
	return it;
}


#endif /* MAP_H_ */
