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
 * FUNCTION OutputHuffCodes
 * -----------------------------------------------------------------------
 * Output the huffman codes for an alphabet to the console.
 * -----------------------------------------------------------------------
 * PRECONDITIONS-
 * 	alphabet : All letters there are codes for.
 * 	huffTree : The tree used to code/decode the alphabet.
 *
 * POSTCONDITIONS-
 * 	Output the huffman codes for an alphabet to the console.
 *************************************************************************/
void OutputHuffCodes(string alphabet, const HuffmanTree<HuffCode>& huffTree)
{
	//VARIABLE DECLERATIONS
	string::iterator printIt;//PROC - Iterates the alphabet.

	cout << "Huffman Codes for the Alphabet - \n";

	//Iterate each character in the alphabet. Use the tree to get its
	//code and then output it to the console.
	printIt = alphabet.begin();
	while(printIt != alphabet.end())
	{
		cout << '\'' << (*printIt) << '\'' << " = ";
		cout << huffTree.HuffmanSearch(*printIt);
		cout << endl;

		++printIt;
	}
}

