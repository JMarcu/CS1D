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
 * FUNCTION DecompressFile
 * -----------------------------------------------------------------------
 * This uses a huffman tree to decode a file and output the result to
 * the console
 * -----------------------------------------------------------------------
 * PRECONDITIONS-
 * 	huffTree     : The tree to use for decoding.
 *
 * POSTCONDITIONS-
 * 	This uses a huffman tree to decode a file and output the result to
 * the console
 *************************************************************************/
void DecompressFile(HuffmanTree<HuffCode>* huffTree)
{
	//VARIABLE DECLERATIONS
	ifstream inFile;          //PROC - Input filestream variable.
	string   codes;           //IN   - Stores a line of input from the file.
	string::iterator codesIt; //PROC - Iterates over codes.
	BTNode<HuffCode>* treePtr;//PROC - Iterates the huffman tree.
	bool decoding;            //PROC - Used to seperate codes.
	string decoded;           //OUT  - Stores the decoded string.

	//VARIABLE INITIALIZATIONS
	decoded = "";
	inFile.open("Compressed.txt");

	//Keep going until the file ends.
	while(inFile)
	{
		//Grab a single line.
		getline(inFile, codes);

		//Iterate over the entire line.
		codesIt = codes.begin();
		while(codesIt != codes.end())
		{
			//Set the variables up for a single code.
			decoding = true;
			treePtr  = huffTree->GetRoot();

			//Decode one character.
			while(decoding)
			{
				//If the symbol is NULL then keep going.
				if(treePtr->GetElem().symbol == 0)
				{
					//Zero means left child, one means right child.
					if((*codesIt) == '0')
					{
						treePtr = treePtr->GetLeft();
					}
					else
					{
						treePtr = treePtr->GetRight();
					}

					//Next digit in the code
					++codesIt;
				}
				//If the symbol is character then output it
				else
				{
					decoded += treePtr->GetElem().symbol;
					decoding = false;
				}
			}
		}
	}

	//Output the results to the console.
	cout << WordWrap(decoded, 80);
}
