/*************************************************************************
 * CS1D Final Project
 * -----------------------------------------------------------------------
 * AUTHORS     : James Marcu & Phillip Doyle
 * STUDENT IDs : 374443      & 911579
 * CLASS       : CS1D
 * SECTION     : TTh 3:30 PM
 * DUE DATE    : 12/9/2014
 *************************************************************************/
#ifndef HASHTABLE_H_
#define HASHTABLE_H_

#include <iostream>
#include <sstream>
using namespace std;

//This is a node for the hash table found below.
template <typename KeyType, typename ElemType>
class HashNode
{
	public:
	   /*******************************************
	    * * * * CONSTRUCTORS AND DESTRUCTOR * * * *
	    *******************************************/
		//The default constructor, takes in the key and value of the node.
		HashNode(const KeyType& keyInit, const ElemType& valueInit)
			{key = keyInit; value = valueInit; deleted = false; end = false;}
		//This constructor creates the "end" node of the bucket array.
		HashNode(bool isEnd)
			{deleted = true; end = true;}

	   /*******************************************
		* * * *          ACCESSORS          * * * *
		*******************************************/
		const KeyType& GetKey() const   //Returns the key stored in
			{if (!deleted && !end)      //the node.
				return key;
			 else
				 throw EmptyNode();
			}
		const ElemType& GetValue() const//Returns the value stored
			{if (!deleted && !end)      //in the node.
				return value;
			 else
				 throw EmptyNode();
			}
		bool Deleted() const            //Returns if the node is 'deleted'.
			{return deleted;}
		bool End() const                //Returns if this is an end node.
			{return end;}

	   /*******************************************
		* * * *          MUTATORS           * * * *
		*******************************************/
		ElemType& ModValue()                   //Returns a non-constant
		{if (!deleted && !end)                 //reference to the element
			return value;                      //so that it can be modified.
		 else
			 throw EmptyNode();
		}
		void SetKey(const KeyType& newKey)     //Sets the key in the node.
			{if (!deleted && !end)
				key = newKey;
			 else
				 throw EmptyNode();
			}
		void SetValue(const ElemType& newValue)//Sets the value in the node.
			{if (!deleted && !end)
				value = newValue;
			 else
				 throw EmptyNode();
			}
		void Delete()                          //Marks the node as 'deleted'.
			{deleted = true;}

	private:
	   /*******************************************
		* * * *         VARIABLES           * * * *
		*******************************************/
		KeyType  key;    //The key of the node.
		ElemType value;  //The value stored in the node.
		bool     deleted;//If the node is 'deleted' it will be ignored in
		                 //searches through the table and its key/value
		                 //pair becomes inaccessible.
		bool     end;    //Whether or not the node is an 'end' node. If it
		                 //is its key and value cannot be interacted with.

	   /*******************************************
		* * * *         EXCEPTIONS          * * * *
		*******************************************/
		class EmptyNode{};//Thrown if an attempt is made to access/modify
		                  //the key/value pair while the node is marked as
		                  //'end' or 'deleted'.
};

//This is a hashtable. It uses a double hashing algorithm to hash keys.
template <typename KeyType, typename ElemType>
class HashTable
{
   /*******************************************
	* * * *         DATATYPES           * * * *
	*******************************************/
	typedef HashNode<KeyType, ElemType> node;//Shorthand for a node in the table.

	public:
		//An iterator for the hash table.
		class Iterator
		{
			public:
			   /*******************************************
			    * * * * CONSTRUCTORS AND DESTRUCTOR * * * *
			    *******************************************/
				Iterator();          //Defaults position to the first index.
				Iterator(int posInit,//Sets the index to start at.
						 node* buck);

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
				int   position;//Stores the index the iterator is pointing to.
				node* bucket;
		};

	   /*******************************************
		* * * * CONSTRUCTORS AND DESTRUCTOR * * * *
		*******************************************/
		//Takes in two pointers-to-functions to use in the hashing algorithm.
		//Defaults to the two functions at the top of this file.
		HashTable(int(*hashOne)(const KeyType&),
				  int(*hashTwo)(const KeyType&));

	   /*******************************************
		* * * *          ACCESSORS          * * * *
		*******************************************/
		int Size() const;                       //Returns the number of
		                                        //elements in the table.
		bool Empty() const;                     //Returns if the table is
		                                        //empty.
		HashNode<KeyType, ElemType>* Find(const KeyType& key) const;//Returns a iterator to the
		                                        //provided key. Points at
		                                        //'end' if not found.
		string Print() const;                   //Prints a list of stored
		                                        //values to the console.
		Iterator Begin() const;                 //Returns an iterator to the
		                                        //first node.
		Iterator End() const;                   //Returns an iterator to the
		                                        //'end' node.

	   /*******************************************
		* * * *          MUTATORS           * * * *
		*******************************************/
		void Put(const KeyType& key,      //Stores a new key/value pair.
				     const ElemType& newElem);
		bool Erase(const KeyType& key);       //Erases the node with the key.
		bool Erase(Iterator& position);       //Erases the node at the position.

	private:
	   /*******************************************
		* * * *         VARIABLES           * * * *
		*******************************************/
		node*     bucket[68];                    //Bucket array to store nodes.
		int       size;                          //Number of elements.
		int       (*HashOne)(const KeyType&);    //First hashing algorithm.
		int       (*HashTwo)(const KeyType&);    //Second hashing algorithm.

	   /*******************************************
		* * * *          ACCESSORS          * * * *
		*******************************************/
		int       Hash(const KeyType& key) const;//Hashes a key into an index.

	   /*******************************************
		* * * *         EXCEPTIONS          * * * *
		*******************************************/
		class KeyNotFound{};//Thrown if an attempt to find a key didn't work.
		class BucketFull{}; //Thrown if the bucket array is full while
		                    //trying to add a new node.
};

/*************************************************************************
 * METHOD HashTable
 * ______________________________________________________________________
 * Constructs a hashtable with the provided functions as the hashing
 * algorithm.
 * ______________________________________________________________________
 * PRE-CONDITIONS -
 *  hashOneInit: Points to the first hashing algorithm.
 *  hashTwoInit: Points to the second hashing algorithm.
 *
 * POST-CONDITIONS -
 * 	Creates an instance of HashTable.
 *************************************************************************/
template <typename KeyType, typename ElemType>
HashTable<KeyType, ElemType>::HashTable(int(*hashOneInit)(const KeyType&),//First hash
		                                int(*hashTwoInit)(const KeyType&))//Second hash
{
	//Set the variables of the new table.
	HashOne = hashOneInit;
	HashTwo = hashTwoInit;
	size    = 0;

	//Fill the bucket with NULL.
	for (int i = 0; i < 67; i++)
	{
		bucket[i] = NULL;
	}

	//Create the 'end' node in the bucket.
	bucket[18] = new HashNode<KeyType, ElemType>(true);
}

/*************************************************************************
 * METHOD Size
 * ______________________________________________________________________
 * Returns the number of elements in the table.
 * ______________________________________________________________________
 * PRE-CONDITIONS -
 *  <none>
 *
 * POST-CONDITIONS -
 * 	size: number of elements in the table
 *************************************************************************/
template <typename KeyType, typename ElemType>
int HashTable<KeyType, ElemType>::Size() const
{
	return size;
}

/*************************************************************************
 * METHOD Empty
 * ______________________________________________________________________
 * Returns true if the table is empty.
 * ______________________________________________________________________
 * PRE-CONDITIONS -
 *  <none>
 *
 * POST-CONDITIONS -
 * 	empty: true if the table is empty
 *************************************************************************/
template <typename KeyType, typename ElemType>
bool HashTable<KeyType, ElemType>::Empty() const
{
	return size == 0;
}

/*************************************************************************
 * METHOD Find
 * ______________________________________________________________________
 * Returns an iterator pointing to the node which contains the provided
 * key.
 * ______________________________________________________________________
 * PRE-CONDITIONS -
 *  key: The key to search the table for.
 *
 * POST-CONDITIONS -
 * 	An iterator will be returned pointing to the node with a matching key.
 * 	If no matching key was found the iterator will point to the 'end' node.
 *************************************************************************/
template <typename KeyType, typename ElemType>
HashNode<KeyType, ElemType>* HashTable<KeyType, ElemType>::Find(const KeyType& key) const
{
	//VARIABLE DECLERATIONS
	int j;             //PROC - used in the hashing algorithm as a constant
	int index;         //PROC - the index of the node to return
	bool keepSearching;//PROC - whether or not to continue searching
	bool keyFound;     //PROC - whether or not the key has been found

	//VARIABLE INITIALIZATIONS
	keepSearching = true;
	keyFound      = false;
	j             = 0;

	/*********************************************************************
	 * PROC - This is a modified version of the hashing algorithm. Unlike
	 *        Hash(), this will not stop when it encounters a deleted node.
	 *        It is possible that the node being searched for collided with
	 *        a deleted node when it was added and is further in the table.
	 *********************************************************************/
	do//while (keepSearching)
	{
		//Hash or rehash the key then increment j.
		index = (HashOne(key) + (j * HashTwo(key))) % 67;
		++j;

		//If j is greater than or equal to the bucket array's size then
		//there is no need to keep searching. We still have to check if
		//the key is in the final node though.
		if (j >= 67)
		{
			keepSearching = false;
		}

		//First check if the node being pointed to is NULL or deleted.
		if (bucket[index] != NULL && !bucket[index]->Deleted())
		{
			//If its not then check its key.
			if (bucket[index]->GetKey() == key)
			{
				//If the key matches then stop searching.
				keepSearching = false;
				keyFound      = true;
			}
		}
	}while (keepSearching);

	//If the key was found return an iterator pointing to it.
	//Else return an iterator pointing at the 'end' node.
	if (keyFound)
	{
		return bucket[index];
	}
	else
	{
		return NULL;
	}
}

/*************************************************************************
 * METHOD Print
 * ______________________________________________________________________
 * Returns a string containing a comma-separated list of all the values
 * in the table.
 * ______________________________________________________________________
 * PRE-CONDITIONS -
 *  <none>
 *
 * POST-CONDITIONS -
 * 	Returns a string containing a comma-separated list of all the values
 * 	in the table.
 *************************************************************************/
template <typename KeyType, typename ElemType>
string HashTable<KeyType, ElemType>::Print() const
{
	//VARIABLE DECLERATIONS
	int index;       //PROC - the index being accessed
	ostringstream ss;//PROC - stores the values to be converted to a string

	//VARIABLE INITIALIZATIONS
	index      = 0;

	//The first index must be added separately as no comma proceeds it.
	//If the node there is NULL or deleted "EMPTY" is added. Else it adds
	//the value stored there.
	if (bucket[index] == NULL || bucket[index]->Deleted())
	{
		ss << "EMPTY";
	}
	else
	{
		ss << bucket[index]->GetValue().get_stadium_name();
	}

	//The same as above, but it also adds commas and spaces between entries
	//and will run through the rest of the index.
	for (index = 1; index < 67; ++index)
	{
		if (bucket[index] == NULL || bucket[index]->Deleted())
		{
			ss << ", EMPTY";
		}
		else
		{
			ss << ", " << bucket[index]->GetValue().get_stadium_name();
		}
	}

	//Convert the stream to a string and return it.
	return ss.str();
}

/*************************************************************************
 * METHOD Begin
 * ______________________________________________________________________
 * Returns an iterator pointing to the first index in the table.
 * ______________________________________________________________________
 * PRE-CONDITIONS -
 *  <none>
 *
 * POST-CONDITIONS -
 * 	Returns an iterator pointing to the first index in the table.
 *************************************************************************/
template <typename KeyType, typename ElemType>
typename HashTable<KeyType, ElemType>::Iterator HashTable<KeyType, ElemType>::Begin() const
{
	return Iterator(0);
}

/*************************************************************************
 * METHOD Begin
 * ______________________________________________________________________
 * Returns an iterator pointing to the node-beyond-the-last node of the
 * table.
 * ______________________________________________________________________
 * PRE-CONDITIONS -
 *  <none>
 *
 * POST-CONDITIONS -
 * 	Returns an iterator pointing to the node-beyond-the-last node of the
 * 	table.
 *************************************************************************/
template <typename KeyType, typename ElemType>
typename HashTable<KeyType, ElemType>::Iterator HashTable<KeyType, ElemType>::End() const
{
	return Iterator(18);
}

/*************************************************************************
 * METHOD Put
 * ______________________________________________________________________
 * Adds a new node with the provided value/key pair to the table.
 *
 * EXCEPTIONS - BucketFull: if the bucket is full when a new node tries
 *                          to enter it this will be thrown from Hash().
 *                          Put() will catch it and terminate.
 * _____________________________________________________________________
 * PRE-CONDITIONS -
 *  key  : The key of the new key/value pair.
 *	value: The value of the new key/value pair.
 *
 * POST-CONDITIONS -
 * 	Returns an iterator pointing to the new node.
 *************************************************************************/
template <typename KeyType, typename ElemType>
void HashTable<KeyType, ElemType>::Put(const KeyType& key,
		                               const ElemType& newElem)
{
	//VARIABLE DECLERATIONS
	int index;//PROC - The index the new node is going into.

	//If the bucket array is full then it will throw an error, which will
	//be caught here.
	try
	{
		//Hash the key to get an index.
		index = Hash(key);

		//If there is a deleted node there then clear it from memory.
		if (bucket[index] != NULL)
		{
			delete bucket[index];
		}

		//Create a new node with the key/value pair.
		bucket[index] = new node(key, newElem);

		//Increment the size counter.
		++size;
	}
	catch (BucketFull& err)
	{
		cerr << "ERROR: Hash table is full.";
	}
}

/*************************************************************************
 * METHOD Erase
 * ______________________________________________________________________
 * Deletes the node in the table with the given key.
 * _____________________________________________________________________
 * PRE-CONDITIONS -
 *  key  : The key of the node to delete.
 *
 * POST-CONDITIONS -
 * 	Deletes the node with the given key.
 * 	success: Returns true if the node was found and deleted.
 *************************************************************************/
template <typename KeyType, typename ElemType>
bool HashTable<KeyType, ElemType>::Erase(const KeyType& key)
{
	//VARIABLE DECLERATIONS
	bool success;//OUT  - if the node was found and deleted

	//VARIABLE INITIALIZATIONS
	success = false;

	Find(key)->Delete();
	--size;
	success = true;

	return success;
}

/*************************************************************************
 * METHOD Erase
 * ______________________________________________________________________
 * Deletes the node in the table at the given position.
 * _____________________________________________________________________
 * PRE-CONDITIONS -
 *  position: The position of the node to delete.
 *
 * POST-CONDITIONS -
 * 	Deletes the node with the given key.
 * 	success: Returns true if the node was found and deleted.
 *************************************************************************/
template <typename KeyType, typename ElemType>
bool HashTable<KeyType, ElemType>::Erase(Iterator& position)
{
	//VARIABLE DECLERATIONS
	bool success;

	//VARIABLE INITIALIZATIONS
	success = false;//OUT - if the node was found and deleted

	//If the iterator points to a non-null node then delete it and decrement
	//the size counter.
	if (bucket[position.GetPosition()] != NULL)
	{
		bucket[position.GetPosition()]->Delete();
		--size;
		success = true;
	}

	return success;
}

/*************************************************************************
 * METHOD Hash
 * ______________________________________________________________________
 * Uses a double hashing algorithm to hash keys into indexes for the
 * bucket array.
 * _____________________________________________________________________
 * PRE-CONDITIONS -
 *  key: The key to hash.
 *
 * POST-CONDITIONS -
 * 	index: The integer value of the hashed key.
 *************************************************************************/
template <typename KeyType, typename ElemType>
int HashTable<KeyType, ElemType>::Hash(const KeyType& key) const
{
	//VARIABLE DECLERATIONS
	int j;             //PROC - Used in the hashing process as a constant.
	bool keepSearching;//PROC - Controls when to stop hashing.
	int index;         //OUT  - The integer value of the hashed key.

	//VARIABLE INITIALIZATIONS
	j = 0;
	keepSearching = true;

	/*********************************************************************
	 * PROC - This is the main body of the hashing algorithm. It will run
	 *        until every node has been probed or an available node has
	 *        been found.
	 *********************************************************************/
	do//while (keepSearching);
	{
		//Hash the key and get an index, then increment j.
		index = (HashOne(key) + (j * HashTwo(key))) % 67;
		++j;

		//If every node has been probed then stop hashing. We still need
		//to check if the final node is available though.
		if (j >= 67)
		{
			keepSearching = false;
		}

		//If the node is NULL or deleted then it is available. If there
		//is a node there though then check if it's key matches the one
		//given. No duplicate keys are allowed.
		if (bucket[index] != NULL && !bucket[index]->Deleted())
		{
			//If the key is already in the table then stop hashing.
			if (bucket[index]->GetKey() == key)
			{
				keepSearching = false;
			}
			//If this is the final node and it isn't available then throw
			//a BucketFull exception.
			else if (j >= 67)
			{
				throw BucketFull();
			}
		}
		//If the nodes available quit hashing.
		else
		{
			keepSearching = false;
		}

	}while (keepSearching);

	return index;
}


/*************************************************************************
 *
 * -----------------------------------------------------------------------
 * CLASS HashTable::Iterator
 * -----------------------------------------------------------------------
 * All methods below belong to the class HashTable::Iterator.
 *
 *************************************************************************/


/*************************************************************************
 * METHOD Iterator
 * ______________________________________________________________________
 * Constructs the iterator with a default position of index 0.
 * _____________________________________________________________________
 * PRE-CONDITIONS -
 *  <none>
 *
 * POST-CONDITIONS -
 * 	Creates an instance of the object iterator.
 *************************************************************************/
template <typename KeyType, typename ElemType>
HashTable<KeyType, ElemType>::Iterator::Iterator()
{
	position = 0;
	bucket   = NULL;
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
HashTable<KeyType, ElemType>::Iterator::Iterator(int posInit, node* buck)
{
	position = posInit;
	bucket   = buck;
}

/*************************************************************************
 * METHOD GetPosition
 * ______________________________________________________________________
 * Returns the index number pointed to by the iterator.
 * _____________________________________________________________________
 * PRE-CONDITIONS -
 *  <none>
 *
 * POST-CONDITIONS -
 * 	position: The index of the node the iterator points to.
 *************************************************************************/
template <typename KeyType, typename ElemType>
int HashTable<KeyType, ElemType>::Iterator::GetPosition() const
{
	return position;
}

/*************************************************************************
 * METHOD operator*
 * ______________________________________________________________________
 * Overloaded to return the a pointer to the node pointed at by the
 * iterator.
 * _____________________________________________________________________
 * PRE-CONDITIONS -
 *  <none>
 *
 * POST-CONDITIONS -
 * 	Returns a pointer to the node at the iterator's position.
 *************************************************************************/
template <typename KeyType, typename ElemType>
HashNode<KeyType, ElemType>* HashTable<KeyType, ElemType>::Iterator::operator*() const
{
	return bucket[position];
}

/*************************************************************************
 * METHOD operator->
 * ______________________________________________________________________
 * Overloaded to run on the node at the iterator's position instead of
 * the iterator itself.
 * _____________________________________________________________________
 * PRE-CONDITIONS -
 *  <none>
 *
 * POST-CONDITIONS -
 * 	Runs the arrow operator on the iterator's node.
 *************************************************************************/
template <typename KeyType, typename ElemType>
HashNode<KeyType, ElemType>* HashTable<KeyType, ElemType>::Iterator::operator->() const
{
	HashNode<KeyType, ElemType>* returnPtr;
	returnPtr = &bucket[position];
	return returnPtr;
}

/*************************************************************************
 * METHOD operator==
 * ______________________________________________________________________
 * Returns true if the two iterators node's are equal.
 * _____________________________________________________________________
 * PRE-CONDITIONS -
 *  <none>
 *
 * POST-CONDITIONS -
 * 	Returns true if the two iterators node's are equal.
 *************************************************************************/
template <typename KeyType, typename ElemType>
bool HashTable<KeyType, ElemType>::Iterator::operator==(Iterator& compare) const
{
	return bucket[position] == *compare;
}

/*************************************************************************
 * METHOD operator!=
 * ______________________________________________________________________
 * Returns true if the two iterators node's are not equal.
 * _____________________________________________________________________
 * PRE-CONDITIONS -
 *  <none>
 *
 * POST-CONDITIONS -
 * 	Returns true if the two iterators node's are not equal.
 *************************************************************************/
template <typename KeyType, typename ElemType>
bool HashTable<KeyType, ElemType>::Iterator::operator!=(Iterator& compare) const
{
	return bucket[position] != *compare;
}

/*************************************************************************
 * METHOD operator++
 * ______________________________________________________________________
 * The pre-increment operator. Moves the iterator to the next index of the
 * table.
 * _____________________________________________________________________
 * PRE-CONDITIONS -
 *  <none>
 *
 * POST-CONDITIONS -
 * 	The iterator will point to the next index in the table.
 *************************************************************************/
template <typename KeyType, typename ElemType>
typename HashTable<KeyType, ElemType>::Iterator HashTable<KeyType, ElemType>::Iterator::operator++()
{
	return Iterator(bucket[++position]);
}

/*************************************************************************
 * METHOD operator++
 * ______________________________________________________________________
 * The post-increment operator. Moves the iterator to the next index of the
 * table.
 * _____________________________________________________________________
 * PRE-CONDITIONS -
 *  <none>
 *
 * POST-CONDITIONS -
 * 	The iterator will point to the next index in the table.
 *************************************************************************/
template <typename KeyType, typename ElemType>
typename HashTable<KeyType, ElemType>::Iterator HashTable<KeyType, ElemType>::Iterator::operator++(int)
{
	return Iterator(bucket[position++]);
}

/*************************************************************************
 * METHOD operator--
 * ______________________________________________________________________
 * The pre-decrement operator. Moves the iterator to the previous index of
 * the table.
 * _____________________________________________________________________
 * PRE-CONDITIONS -
 *  <none>
 *
 * POST-CONDITIONS -
 * 	The iterator will point to the previous index in the table.
 *************************************************************************/
template <typename KeyType, typename ElemType>
typename HashTable<KeyType, ElemType>::Iterator HashTable<KeyType, ElemType>::Iterator::operator--()
{
	return Iterator(bucket[--position]);
}

/*************************************************************************
 * METHOD operator--
 * ______________________________________________________________________
 * The post-decrement operator. Moves the iterator to the previous index of
 * the table.
 * _____________________________________________________________________
 * PRE-CONDITIONS -
 *  <none>
 *
 * POST-CONDITIONS -
 * 	The iterator will point to the previous index in the table.
 *************************************************************************/
template <typename KeyType, typename ElemType>
typename HashTable<KeyType, ElemType>::Iterator HashTable<KeyType, ElemType>::Iterator::operator--(int)
{
	return Iterator(bucket[position--]);
}

#endif /* HASHTABLE_H_ */
