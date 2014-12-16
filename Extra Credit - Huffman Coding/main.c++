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
 * Extra Credit: Huffman Coding
 * -----------------------------------------------------------------------
 * This program will generate a set of codes for an input file using
 * huffman coding. It then creates a huffman tree and uses it to compress
 * and decompress the original file.
 * -----------------------------------------------------------------------
 * INPUT-
 * 	The input is a hardcoded input file named GettysburgAddress.txt
 *
 * OUTPUT-
 * 	The program will output to the console what is happening. It will
 * 	also create an output file named Compressed.txt where it will store
 * 	the compressed input file.
 *************************************************************************/
int main()
{
	/*********************************************************************
	 * VARIABLE DECLERATIONS
	 *********************************************************************/
	//INPUT - Stores the Gettysburg Address from the input file.
	string gettysburgAddress;

	//INPUT - Contains one copy of every character in the input file.
	string alphabet;

	//PROC - Maps the integer value of all ASCII characters to how frequently
	//       they are used in the input file.
	int frequencyMatrix[127] = {0};

	//PROC - Used to iterate the input file to count character frequency.
	string::iterator frequencyProcessor;

	//PROC - Used to grab single lines out of the input file.
	string tempInput;

	//PROC - Used to store a frequency value from the frequency matrix.
	int frequency;

	//PROC - A list of all the huffman code nodes.
	List<BTNode<HuffCode>* > codeList;

	//PROC - Used to store the two nodes in codeList with the smallest weight.
	List<BTNode<HuffCode>* >::Iterator smallestOne;
	List<BTNode<HuffCode>* >::Iterator smallestTwo;

	//PROC - Used to store the nodes from the iterators above.
	BTNode<HuffCode>* nodePtrOne;
	BTNode<HuffCode>* nodePtrTwo;

	//PROC - Used to dynamically create HuffCode objects.
	HuffCode* codePtr;

	//PROC - Used to dynamically create new nodes.
	BTNode<HuffCode>* newNodePtr;

	//PROC - Used to create the huffman tree from the sorted nodes.
	HuffmanTree<HuffCode>* huffTree;

	//PROC - The input file stream.
	ifstream inFile;


	//VARIABLE INITIALIZATIONS
	gettysburgAddress = "";
	alphabet          = "";

	/*********************************************************************
	 * INPUT - Read in from the input file and count the frequency of
	 *         every character used.
	 *********************************************************************/
	inFile.open("GettysburgAddress.txt");
	while(inFile)
	{
		//Read in one line from the file.
		getline(inFile, tempInput);

		//Iterate over each character in the line.
		frequencyProcessor = tempInput.begin();
		while(frequencyProcessor != tempInput.end())
		{
			//If this is the first occurence of that character then
			//add it to alphabet.
			if(frequencyMatrix[int(*frequencyProcessor)] == 0)
			{
				alphabet = alphabet + *frequencyProcessor;
			}

			//Use the ASCII value as a key for the matrix, and increment
			//its frequency counter there.
			++frequencyMatrix[int(*frequencyProcessor)];

			//Next character.
			++frequencyProcessor;
		}

		//Add the single line to the string which stores the whole file.
		gettysburgAddress += tempInput;
	}

	/*********************************************************************
	 * PROC - Use the frequency information to create a set of HuffCode
	 *        objects for the alphabet.
	 *********************************************************************/
	for (int i = 0; i < 127; ++i)
	{
		//Get the frequency of the current character.
		frequency = frequencyMatrix[i];

		//If this character was used at least once then create a HuffCode
		//object for it and put that object in a binary tree node, then
		//add that node to the code list.
		if (frequency  > 0)
		{
			codePtr    = new HuffCode(char(i), frequency);
			nodePtrOne = new BTNode<HuffCode>(*codePtr);
			codeList.InsertBack(nodePtrOne);
		}
	}

	/*********************************************************************
	 * PROC - This will take the list of all huffman codes and create
	 *        a binary tree from them.
	 *********************************************************************/
	while(codeList.Size() > 1)
	{
		//Store the node with the smallest weight and remove it from the
		//list.
		smallestOne = SmallestWeight(codeList);
		nodePtrOne = (*smallestOne);
		codeList.Erase(smallestOne);

		//Store the node with the smallest weight and remove it from the
		//list.
		smallestTwo = SmallestWeight(codeList);
		nodePtrTwo = (*smallestTwo);
		codeList.Erase(smallestTwo);

		//Create a new HuffCode object whose weight is the combined weight
		//of the two nodes selected above.
		codePtr = new HuffCode(0, nodePtrOne->GetElem().weight +
				                  nodePtrTwo->GetElem().weight);

		//Have the two nodes above be made children of the new node. The
		//smaller of the two will be the left child.
		if(nodePtrOne->GetElem().weight < nodePtrTwo->GetElem().weight)
		{
			newNodePtr = new BTNode<HuffCode>(nodePtrOne, nodePtrTwo,
					                          NULL, *codePtr);
		}
		else
		{
			newNodePtr = new BTNode<HuffCode>(nodePtrTwo, nodePtrOne,
					                          NULL, *codePtr);
		}

		//Have the two nodes point at the new node as their parent.
		nodePtrOne->SetParent(newNodePtr);
		nodePtrTwo->SetParent(newNodePtr);

		//Insert the new node into the list of codes.
		codeList.InsertBack(newNodePtr);
	}

	/*********************************************************************
	 * PROC - Use the one remaining node (of which all other nodes are
	 *        children) as the root for a binary tree. This is essentially
	 *        a wrapper.
	 *********************************************************************/
	huffTree = new HuffmanTree<HuffCode>(newNodePtr);

	/*********************************************************************
	 * OUTPUT - Output the class header to the console.
	 *********************************************************************/
	ClassHeader("James Marcu", "374443", "CS1D", "TTh 3:30 PM",
			    'A', 14, "Extra Credit: Huffman Coding", cout);

	/*********************************************************************
	 * OUTPUT - Output the huffman codes for each letter in the alphabet
	 *          to the console.
	 *********************************************************************/
	OutputHuffCodes(alphabet, *huffTree);
	cout << endl;

	/*********************************************************************
	 * OUTPUT - Output the huffman tree using a breadth-first traversal to
	 *          the console
	 *********************************************************************/
	cout << "The Huffman Tree -\n";
	huffTree->Print();
	cout << endl;

	/*********************************************************************
	 * PROC - Use the huffman tree to compress the contents of the input
	 *        file.
	 *********************************************************************/
	cout << "Now Compressing the File...\n";
	CompressFile(*huffTree, gettysburgAddress);
	cout << "* * * *Compression Complete* * * *\n";
	cout << endl;

	/*********************************************************************
	 * OUTPUT - Decode the compressed file and output the result to the
	 *          console.
	 *********************************************************************/
	cout << "The Decompressed File- \n";
	DecompressFile(huffTree);

	return 0;
}

