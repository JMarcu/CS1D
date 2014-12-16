/*************************************************************************
 * AUTHOR       : James Marcu
 * STUDENT ID   : 374443
 * EXTRA CREDIT : Huffman Coding
 * CLASS        : CS1D
 * SECTION      : TTh 3:30 AM
 * DUE DATE     : 12/15/14
 *************************************************************************/
#ifndef HEADER_H_
#define HEADER_H_

#include <string>
#include <fstream>
#include <iomanip>
#include "BinaryTree.h"
#include "List.h"
using namespace std;

//A struct for modeling a huffman code.
struct HuffCode
{
	//Generic constructor. Weight approximates system max value.
	HuffCode()
		{symbol = ' '; weight = 32000;}

	//Constructor which initializes the symbol and weight.
	HuffCode(char symbolInit, int weightInit)
		{symbol = symbolInit; weight = weightInit;}

	//To HuffCode objects are equal if they have the same symbol.
	bool operator==(const HuffCode& compareTo) const
		{return symbol == compareTo.symbol;}

	char symbol;//The character this codes for.
	int  weight;//The weight of the node.
};

/*************************************************************************
 * FUNCTION SmallestWeight
 * 	In a list of binary tree nodes containing huffman codes, this will
 * 	return an iterator to the node with the smallest weight.
 *************************************************************************/
List<BTNode<HuffCode>* >::Iterator SmallestWeight(const List<BTNode<HuffCode>* >& codes);

/*************************************************************************
 * FUNCTION OutputHuffCodes
 * 	Output the huffman codes for an alphabet to the console.
 *************************************************************************/
void OutputHuffCodes(string alphabet, const HuffmanTree<HuffCode>& huffTree);

/*************************************************************************
 * FUNCTION CompressFile
 * 	This uses a huffman tree to compress a string and store the result
 * 	in an output file.
 *************************************************************************/
void CompressFile(const HuffmanTree<HuffCode>& huffTree,
		          string& originalFile);

/*************************************************************************
 * FUNCTION DecompressFile
 * 	This uses a huffman tree to decode a file and output the result to
 * 	the console
 *************************************************************************/
void DecompressFile(HuffmanTree<HuffCode>* huffTree);

/*************************************************************************
 * FUNCTION ClassHeader
 * 	 This function takes in the programmer's name(s), the class name, and
 *	 the class section. The next argument is assignment type (assType)
 *	 which may be an 'L', or any other character (typically an 'A'). If it
 *	 is set to 'L' then the header will use the word "LAB", else it will
 *	 use the word "ASSIGNMENT" when describing the program. The parameter
 *	 assType is not case sensitive. The parameters assNum and assName
 *	 accept the name of the assignment's name and number. The function will
 *	 output a class heading based on the provided information
 *************************************************************************/
void ClassHeader (string   programmer,//IN & OUT - Programmer's name(s)
				  string   id,        //IN & OUT - Programmer's student
				                      //           id(s)
				  string   className, //IN & OUT - Name of the class this
				                      //           lab/assignment is for.
				  string   section,   //IN & OUT - Section of the class the
					                  //           author is enrolled in
				  char     assType,   //IN & OUT - A character which lets
				                      //           the function know if
					                  //           this is a lab or an
				                      //           assignment.
			      int      assNum,    //IN & OUT - The number of the lab or
					                  //           assignment.
				  string   assName,   //IN & OUT - The name of the lab or
                                      //           assignment.
				  ostream& outStream);//IN       - The stream to output to.

/*************************************************************************
 * FUNCTION WordWrap
 * 	This will read in a string and a margin to fit that string into. It
 * 	will parse through the string and create a version of it with new
 *	 line characters before words that don't fit in the margins. This new
 * 	string is returned to be output.
 *************************************************************************/
string WordWrap(string toWrap,     //IN - The string to be word wrapped.
		        int    lineLength);//IN - The width of the line to fit
                                   //     your string into.

#endif /* HEADER_H_ */
