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
//#include <iostream>
//#include <string>
//using namespace std;

//An unordered map implemented with a double-hashing hash table.
template <typename KeyType, typename ElemType>
class Map
{
	public:
	   /*******************************************
		* * * *         DATATYPES           * * * *
		*******************************************/
		//An iterator for the map.
		class Iterator
		{
		   /*******************************************
			* * * *         DATATYPES           * * * *
			*******************************************/
			typedef HashNode<KeyType, ElemType> node;//Shorthand for the
			                                         //nodes the iterator
			                                         //will work with.

			public:
			   /*******************************************
			    * * * * CONSTRUCTORS AND DESTRUCTOR * * * *
			    *******************************************/
				Iterator();           //Default constructor.
				Iterator(int posInit);//Set the initial position.

			   /*******************************************
				* * * *          ACCESSORS          * * * *
				*******************************************/
				int   GetPosition() const;                //Returns the index
				node* operator*() const;                  //Returns the node
				node* operator->() const;                 //Accesses the node
				bool  operator==(Iterator& compare) const;//Compare iterators
				bool  operator!=(Iterator& compare) const;//Compare iterators

			   /*******************************************
				* * * *          MUTATORS           * * * *
				*******************************************/
				Iterator operator++();   //Increments to the next index.
				Iterator operator++(int);//Increments to the next index.
				Iterator operator--();   //Decrements to the previous index.
				Iterator operator--(int);//Decrements to the previous index.

			private:
			   /*******************************************
				* * * *         VARIABLES           * * * *
				*******************************************/
				//The hash table iterator which this map iterator is
				//wrapped around.
				typename HashTable<KeyType, ElemType>::Iterator* it;

			   /*******************************************
				* * * *          ACCESSORS          * * * *
				*******************************************/
				//Returns the hash-table iterator being used internally.
				//Used by certain wrappers in Map, but not intended for
				//outside use.
				typename HashTable<KeyType, ElemType>::Iterator GetIt() const;
		};

		/*******************************************
		 * * * *          ACCESSORS          * * * *
		 *******************************************/
		int      Size() const;                  //Returns the number of
		                                        //elements.
		bool     Empty() const;                 //Returns if the map is empty.
		Iterator Find(const KeyType& key) const;//Returns an iterator for
		                                        //the given key.
		Iterator Begin() const;                 //Returns an iterator for the
		                                        //first entry.
		Iterator End() const;                   //Returns an iterator for the
		                                        //entry-after-the-last-entry.
		string   Print() const;                 //Returns a string of all values.

	   /*******************************************
		* * * *          MUTATORS           * * * *
		*******************************************/
		Iterator Put(const KeyType& key,    //Adds a new key/value pair.
				     const ElemType& value);
		bool     Erase(const KeyType& key); //Erases the given key/value pair.
		bool     Erase(Iterator& position); //Erases the pair at the given
		                                    //position.

	private:
	   /*******************************************
		* * * *         VARIABLES           * * * *
		*******************************************/
		HashTable<KeyType, ElemType> table;//The map is a wrapper of this
		                                   //hash table.
};

/*************************************************************************
 * METHOD Size
 * ______________________________________________________________________
 * Returns the number of elements in the map.
 * ______________________________________________________________________
 * PRE-CONDITIONS -
 *  <none>
 *
 * POST-CONDITIONS -
 * 	Returns the number of elements in the map.
 *************************************************************************/
template <typename KeyType, typename ElemType>
int Map<KeyType, ElemType>::Size() const
{
	return table.Size();
}

/*************************************************************************
 * METHOD Empty
 * ______________________________________________________________________
 * Returns true if the map is empty.
 * ______________________________________________________________________
 * PRE-CONDITIONS -
 *  <none>
 *
 * POST-CONDITIONS -
 * 	Returns true if the map is empty
 *************************************************************************/
template <typename KeyType, typename ElemType>
bool Map<KeyType, ElemType>::Empty() const
{
	return table.Empty();
}

/*************************************************************************
 * METHOD Find
 * ______________________________________________________________________
 * Returns an iterator pointing to the entry which contains the provided
 * key.
 * ______________________________________________________________________
 * PRE-CONDITIONS -
 *  key: The key to search the map for.
 *
 * POST-CONDITIONS -
 * 	An iterator will be returned pointing to the entry with a matching key.
 * 	If no matching key was found the iterator will point to the 'end' entry.
 *************************************************************************/
template <typename KeyType, typename ElemType>
typename Map<KeyType, ElemType>::Iterator Map<KeyType, ElemType>::Find(const KeyType& key) const
{
	return Iterator(table.Find(key).GetPosition());
}

/*************************************************************************
 * METHOD Print
 * ______________________________________________________________________
 * Returns a string containing a comma-separated list of all the values
 * in the map.
 * ______________________________________________________________________
 * PRE-CONDITIONS -
 *  <none>
 *
 * POST-CONDITIONS -
 * 	Returns a string containing a comma-separated list of all the values
 * 	in the map.
 *************************************************************************/
template <typename KeyType, typename ElemType>
string Map<KeyType, ElemType>::Print() const
{
	return table.Print();
}

/*************************************************************************
 * METHOD Put
 * ______________________________________________________________________
 * Adds a new entry with the provided value/key pair to the map.
 * _____________________________________________________________________
 * PRE-CONDITIONS -
 *  key  : The key of the new key/value pair.
 *	value: The value of the new key/value pair.
 *
 * POST-CONDITIONS -
 * 	Returns an iterator pointing to the new entry.
 *************************************************************************/
template <typename KeyType, typename ElemType>
typename Map<KeyType, ElemType>::Iterator Map<KeyType, ElemType>::Put(const KeyType& key,
		                                                              const ElemType& value)
{
	return Iterator((table.Put(key, value).GetPosition()));
}

/*************************************************************************
 * METHOD Erase
 * ______________________________________________________________________
 * Deletes the entry in the table with the given key.
 * _____________________________________________________________________
 * PRE-CONDITIONS -
 *  key  : The key of the entry to delete.
 *
 * POST-CONDITIONS -
 * 	Deletes the entry with the given key.
 * 	Returns true if the node was found and deleted.
 *************************************************************************/
template <typename KeyType, typename ElemType>
bool Map<KeyType, ElemType>::Erase(const KeyType& key)
{
	return table.Erase(key);
}

/*************************************************************************
 * METHOD Erase
 * ______________________________________________________________________
 * Deletes the entry in the table at the given position.
 * _____________________________________________________________________
 * PRE-CONDITIONS -
 *  position: The position of the node to delete.
 *
 * POST-CONDITIONS -
 * 	Deletes the entry with the given key.
 * 	Returns true if the entry was found and deleted.
 *************************************************************************/
template <typename KeyType, typename ElemType>
bool Map<KeyType, ElemType>::Erase(Iterator& position)
{
	return table.Erase(position.GetIt());
}


/*************************************************************************
 *
 * -----------------------------------------------------------------------
 * CLASS Map::Iterator
 * -----------------------------------------------------------------------
 * All methods below belong to the class Map::Iterator.
 *
 *************************************************************************/


/*************************************************************************
 * METHOD Iterator
 * ______________________________________________________________________
 * Constructs the iterator with a default position the first entry.
 * _____________________________________________________________________
 * PRE-CONDITIONS -
 *  <none>
 *
 * POST-CONDITIONS -
 * 	Creates an instance of the object iterator.
 *************************************************************************/
template <typename KeyType, typename ElemType>
Map<KeyType, ElemType>::Iterator::Iterator()
{
	it = it(0);
}

/*************************************************************************
 * METHOD Iterator
 * ______________________________________________________________________
 * Constructs the iterator with a provided position.
 * _____________________________________________________________________
 * PRE-CONDITIONS -
 *  posInit: The index that of the node the iterator should point to.
 *
 * POST-CONDITIONS -
 * 	Creates an instance of the object iterator.
 *************************************************************************/
template <typename KeyType, typename ElemType>
Map<KeyType, ElemType>::Iterator::Iterator(int posInit)
{
	it = new typename HashTable<KeyType, ElemType>::Iterator (posInit);
}

/*************************************************************************
 * METHOD GetPosition
 * ______________________________________________________________________
 * Returns the index number pointed to by the wrapped iterator.
 * _____________________________________________________________________
 * PRE-CONDITIONS -
 *  <none>
 *
 * POST-CONDITIONS -
 * 	Returns the index number pointed to by the wrapped iterator.
 *************************************************************************/
template <typename KeyType, typename ElemType>
int Map<KeyType, ElemType>::Iterator::GetPosition() const
{
	return it->GetPosition();
}

/*************************************************************************
 * METHOD operator*
 * ______________________________________________________________________
 * Overloaded to return the a pointer to the entry pointed at by the
 * iterator.
 * _____________________________________________________________________
 * PRE-CONDITIONS -
 *  <none>
 *
 * POST-CONDITIONS -
 * 	Returns a pointer to the entry at the iterator's position.
 *************************************************************************/
template <typename KeyType, typename ElemType>
HashNode<KeyType, ElemType>* Map<KeyType, ElemType>::Iterator::operator*() const
{
	return *it;
}

/*************************************************************************
 * METHOD operator->
 * ______________________________________________________________________
 * Overloaded to run on the entry at the iterator's position instead of
 * the iterator itself.
 * _____________________________________________________________________
 * PRE-CONDITIONS -
 *  <none>
 *
 * POST-CONDITIONS -
 * 	Runs the arrow operator on the iterator's entry.
 *************************************************************************/
template <typename KeyType, typename ElemType>
HashNode<KeyType, ElemType>* Map<KeyType, ElemType>::Iterator::operator->() const
{
	return *it;
}

/*************************************************************************
 * METHOD operator==
 * ______________________________________________________________________
 * Returns true if the two iterators entrie's are equal.
 * _____________________________________________________________________
 * PRE-CONDITIONS -
 *  <none>
 *
 * POST-CONDITIONS -
 * 	Returns true if the two iterators entrie's are equal.
 *************************************************************************/
template <typename KeyType, typename ElemType>
bool Map<KeyType, ElemType>::Iterator::operator==(Iterator& compare) const
{
	return it == compare;
}

/*************************************************************************
 * METHOD operator!=
 * ______________________________________________________________________
 * Returns true if the two iterators entrie's are not equal.
 * _____________________________________________________________________
 * PRE-CONDITIONS -
 *  <none>
 *
 * POST-CONDITIONS -
 * 	Returns true if the two iterators entrie's are not equal.
 *************************************************************************/
template <typename KeyType, typename ElemType>
bool Map<KeyType, ElemType>::Iterator::operator!=(Iterator& compare) const
{
	return it != compare;
}

/*************************************************************************
 * METHOD operator++
 * ______________________________________________________________________
 * The pre-increment operator. Moves the iterator to the next entry.
 * _____________________________________________________________________
 * PRE-CONDITIONS -
 *  <none>
 *
 * POST-CONDITIONS -
 * 	The iterator will point to the next entry.
 *************************************************************************/
template <typename KeyType, typename ElemType>
typename Map<KeyType, ElemType>::Iterator Map<KeyType, ElemType>::Iterator::operator++()
{
	return ++it;
}

/*************************************************************************
 * METHOD operator++
 * ______________________________________________________________________
 * The post-increment operator. Moves the iterator to the next entry.
 * _____________________________________________________________________
 * PRE-CONDITIONS -
 *  <none>
 *
 * POST-CONDITIONS -
 * 	The iterator will point to the next entry.
 *************************************************************************/
template <typename KeyType, typename ElemType>
typename Map<KeyType, ElemType>::Iterator Map<KeyType, ElemType>::Iterator::operator++(int)
{
	return it++;
}

/*************************************************************************
 * METHOD operator--
 * ______________________________________________________________________
 * The pre-decrement operator. Moves the iterator to the previous entry.
 * _____________________________________________________________________
 * PRE-CONDITIONS -
 *  <none>
 *
 * POST-CONDITIONS -
 * 	The iterator will point to the previous entry.
 *************************************************************************/
template <typename KeyType, typename ElemType>
typename Map<KeyType, ElemType>::Iterator Map<KeyType, ElemType>::Iterator::operator--()
{
	return --it;
}

/*************************************************************************
 * METHOD operator--
 * ______________________________________________________________________
 * The post-decrement operator. Moves the iterator to the previous entry.
 * _____________________________________________________________________
 * PRE-CONDITIONS -
 *  <none>
 *
 * POST-CONDITIONS -
 * 	The iterator will point to the previous entry.
 *************************************************************************/
template <typename KeyType, typename ElemType>
typename Map<KeyType, ElemType>::Iterator Map<KeyType, ElemType>::Iterator::operator--(int)
{
	return it--;
}

/*************************************************************************
 * METHOD GetIt
 * ______________________________________________________________________
 * Returns the iterator that is being wrapped by the map iterator. This is
 * used for certain other wrappers in the map class but is inaccessible
 * outside of it.
 * _____________________________________________________________________
 * PRE-CONDITIONS -
 *  <none>
 *
 * POST-CONDITIONS -
 * 	The iterator being wrapped is returned.
 *************************************************************************/
template <typename KeyType, typename ElemType>
typename HashTable<KeyType, ElemType>::Iterator Map<KeyType, ElemType>::Iterator::GetIt() const
{
	return it;
}


#endif /* MAP_H_ */
