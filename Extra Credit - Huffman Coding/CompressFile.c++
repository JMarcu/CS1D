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
 * FUNCTION CompressFile
 * -----------------------------------------------------------------------
 * This uses a huffman tree to compress a string and store the result
 * in an output file.
 * -----------------------------------------------------------------------
 * PRECONDITIONS-
 * 	huffTree     : The tree to use for encoding.
 * 	originalFile : The string to encode.
 *
 * POSTCONDITIONS-
 * 	Will create an output file named "Compressed.txt" which will store
 * 	the encoded version of originalFile.
 *************************************************************************/
void CompressFile(const HuffmanTree<HuffCode>& huffTree,
		           string& originalFile)
{
	//VARIABLE DECLERATIONS
	string::iterator stringIt;      //PROC - Iterates the string to encode.
	ofstream         outFile;       //PROC - Output filestream variable.
	string           huffCode;      //PROC - Stores a character's code.
	string           compressedFile;//OUT  - Stores lines for the output file.
	int              count;         //PROC - Controls when codes are output.

	//VARIABLE INITIALIZATIONS
	count = 0;
	outFile.open("Compressed.txt");

	/*********************************************************************
	 * PROC - Create the first code, done outside the loop for formatting.
	 *********************************************************************/
	stringIt       = originalFile.begin();
	huffCode       = huffTree.HuffmanSearch(*stringIt);
	compressedFile = compressedFile + huffCode;
	++stringIt;

	/*********************************************************************
	 * PROC - Iterate over every character in the string.
	 *********************************************************************/
	while(stringIt != originalFile.end())
	{
		//Generate the huffman code.
		huffCode = huffTree.HuffmanSearch(*stringIt);

		//Fifteen codes will be output on each line.
		if(count < 15)
		{
			compressedFile = compressedFile + huffCode;
			++count;
		}
		else
		{
			outFile << compressedFile << endl;
			compressedFile = huffCode;
			count = 0;
		}

		//Iterate.
		++stringIt;
	}

	//Output any leftovers
	if(count != 0)
	{
		outFile << compressedFile;
	}


	outFile.close();
}

