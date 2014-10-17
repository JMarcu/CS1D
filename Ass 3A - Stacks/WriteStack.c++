/*************************************************************************
 * AUTHOR      : James Marcu
 * STUDENT ID  : 374443
 * ASS #3      : Stacks
 * CLASS       : CS1D
 * SECTION     : TTh 3:30 AM
 * DUE DATE    : 9/2/2014
 *************************************************************************/

#include "header.h"

/*************************************************************************
 * FUNCTION WriteStack
 * _______________________________________________________________________
 * 	 This function will create a stack from an input file. The function
 * 	 is overloaded to create stacks using type string, int, or double
 * 	 since the numerical datatypes have different ways of being read in
 * 	 than other datatypes.
 *
 * 	 The formatting of the file is as such: Entries must be seperated by
 * 	 commas, not \n characters. A space after the comma is optional.
 * _______________________________________________________________________
 * PRE-CONDITIONS
 * 		inputStack   : The stack to write to.
 * 		inFileStream : The file stream to read input from.
 *
 * POST-CONDITIONS
 * 		inputStack   : Will have been initialized from the input stream.
 * 		inFileStream : File position will be set to the end of the file.
 *************************************************************************/

void WriteStack (stack<string>& inputStack,//IN & OUT - Stack to initialize.
		         ifstream& inFileStream)   //IN       - Stream to read from.
{
	//VARIABLE DECLERATIONS
	string tempStorage;//PROC - Data is read into here from the stream
	                   //       before it is read onto the stack.

	/*********************************************************************
	 * PROC - The loop will go until the end of the file. Each data point
	 *        is read in then pushed onto the stack. If there is a space
	 *        between the comma and the next data point it is ignored.
	 *********************************************************************/
	while (inFileStream)
	{
		getline(inFileStream, tempStorage, ',');
		if (inFileStream.peek() == ' ')
		{
			inFileStream.ignore(10000, ' ');
		}
		inputStack.push(tempStorage);
	}
}

void WriteStack (stack<int>& inputStack, //IN & OUT - Stack to initialize.
                 ifstream& inFileStream) //IN       - Stream to read from.
{
	//VARIABLE DECLERATIONS
	int tempStorage;//PROC - Data is read into here from the stream
	                //       before it is read onto the stack.


	/*********************************************************************
	 * PROC - The loop will go until the end of the file. Each data point
	 *        is read in then pushed onto the stack. If there is a space
	 *        between the comma and the next data point it is ignored.
	 *********************************************************************/
	while (inFileStream)
	{
		inFileStream >> tempStorage;
		inFileStream.ignore(10000, ',');
		if (inFileStream.peek() == ' ')
		{
			inFileStream.ignore(10000, ' ');
		}
		inputStack.push(tempStorage);
	}
}

void WriteStack (stack<double>& inputStack,//IN & OUT - Stack to initialize.
                 ifstream& inFileStream)   //IN       - Stream to read from.
{
	//VARIABLE DECLERATIONS
	double tempStorage;//PROC - Data is read into here from the stream
	                   //       before it is read onto the stack.


	/*********************************************************************
	 * PROC - The loop will go until the end of the file. Each data point
	 *        is read in then pushed onto the stack. If there is a space
	 *        between the comma and the next data point it is ignored.
	 *********************************************************************/
	while (inFileStream)
	{
		inFileStream >> tempStorage;
		inFileStream.ignore(10000, ',');
		if (inFileStream.peek() == ' ')
		{
			inFileStream.ignore(10000, ' ');
		}
		inputStack.push(tempStorage);
	}
}
