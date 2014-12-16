/*************************************************************************
 * AUTHOR       : James Marcu
 * STUDENT ID   : 374443
 * EXTRA CREDIT : Huffman Coding
 * CLASS        : CS1D
 * SECTION      : TTh 3:30 AM
 * DUE DATE     : 12/15/14
 *************************************************************************/

#include "header.h"

/*************************************************************************
 * FUNCTION SmallestWeight
 * -----------------------------------------------------------------------
 * In a list of binary tree nodes containing huffman codes, this will
 * return an iterator to the node with the smallest weight.
 * -----------------------------------------------------------------------
 * PRECONDITIONS-
 * 	codes : The list to search.
 *
 * POSTCONDITIONS-
 * 	Returns a iterator to the node with the smallest weight.
 *************************************************************************/
List<BTNode<HuffCode>* >::Iterator SmallestWeight(const List<BTNode<HuffCode>* >& codes)
{
	//VARIABLE DECLERATIONS
	List<BTNode<HuffCode>* >::Iterator returnIt;//OUT  - The iterator to return.
	List<BTNode<HuffCode>* >::Iterator iterator;//PROC - Iterates the list.

	//VARIABLE INITIALIZATIONS
	returnIt = codes.Begin();
	iterator = codes.Begin();

	//Iterate over every node.
	while(iterator != codes.End())
	{
		//If this node has a smaller weight than the current smallest
		//the stroe it.
		if ((*iterator)->GetElem().weight < (*returnIt)->GetElem().weight)
		{
			returnIt = iterator;
		}

		//Next node.
		++iterator;
	}

	return returnIt;
}

