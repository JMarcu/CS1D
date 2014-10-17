/*************************************************************************
 * AUTHOR      : James Marcu
 * STUDENT ID  : 374443
 * ASS #3      : Stacks
 * CLASS       : CS1D
 * SECTION     : TTh 3:30 AM
 * DUE DATE    : 9/2/2014
 *************************************************************************/

#ifndef HEADER_H_
#define HEADER_H_

/***********************************
 * PRE PROCESSOR DIRECTIVES
 ***********************************/
#include <iomanip>
#include <fstream>
#include <string>
#include <sstream>
#include "StackProcessing.h"
using namespace std;

/***********************************
 * CUSTOM DATATYPES
 ***********************************/
//Used to represent datatypes abstractly.
enum DATATYPE{
	STRING, INTEGER, DOUBLE
};

/***********************************
 * FUNCTION PROTOTYPES
 ***********************************/
/*************************************************************************
 * FUNCTION GetInput
 * 	 Outputs a prompt and reads in input of type string from an input
 * 	 stream. Due to string's flexibility in storing data there is no error
 * 	 checking.
 *************************************************************************/
string GetInput (string prompt,         //IN & OUT - Prompt sent to the
		                                //           output stream before
		                                //           data is gathered.
		         istream& inputStream,  //PROC     - Stream to input from.
		         ostream& outputStream);//PROC     - Stream to output into.

/*************************************************************************
 * FUNCTION DetermineDatatype
 * 	 This function determines the datatype of a file: string, double, or
 * 	 int. There are several assumptions made. First is that the file is
 * 	 formatted such that each entry is separated by a comma, NOT a newline
 * 	 character. Second, it doesn't handle numbers which use commas (or
 * 	 periods in the European fashion). Third, it assumes that all entries
 * 	 in the file are of the same datatype, so it only checks the first.
 * 	 It will return a value of the enumerated type DATATYPE which
 * 	 corresponds with the datatype of the file.
 *************************************************************************/
DATATYPE DetermineDatatype(ifstream& inFileStream);//IN - Input stream to
                                                   //     determine the
                                                   //     datatype in.

/*************************************************************************
 * FUNCTION WriteStack
 * 	 This function will create a stack from an input file. The function
 * 	 is overloaded to create stacks using type string, int, or double
 * 	 since the numerical datatypes have different ways of being read in
 * 	 than other datatypes.
 *
 * 	 The formatting of the file is as such: Entries must be seperated by
 * 	 commas, not \n characters. A space after the comma is optional.
 *************************************************************************/
void WriteStack (stack<string>& inputStack,//IN & OUT - Stack to initialize.
		         ifstream& inFileStream);  //IN       - Stream to read from.
void WriteStack (stack<int>& inputStack,   //IN & OUT - Stack to initialize.
                 ifstream& inFileStream);  //IN       - Stream to read from.
void WriteStack (stack<double>& inputStack,//IN & OUT - Stack to initialize.
                 ifstream& inFileStream);  //IN       - Stream to read from.

/*************************************************************************
 * FUNCTION PrintStack
 * 	 Prints the data stored in a stack to the console.
 *************************************************************************/
template <typename TYPE>
void PrintStack(stack<TYPE>& stackToPrint,//OUT - The stack whose data you
		                                  //      want printed.
		        string prompt);           //OUT - Will be output to the
                                          //      user before printing the
                                          //      stack.

/*************************************************************************
 * FUNCTION ReverseStack
 * 	 This will manipulate a stack so that it's elements are in the reverse
 * 	 order of how it was passed in.
 *************************************************************************/
template <typename TYPE>
void ReverseStack(stack<TYPE>& stackToReverse);//OUT - The stack to reverse
                                               //      the order of.

/*************************************************************************
 * FUNCTION WordWrap
 *   This will read in a string and a margin to fit that string into. It
 *   will parse through the string and create a version of it with new
 *   line characters before words that don't fit in the margins. This new
 *   string is returned to be output.
 *************************************************************************/
string WordWrap(string toWrap,     //IN - The string to be word wrapped.
		        int    lineLength);//IN - The width of the line to fit
                                   //     your string into.

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


#endif /* HEADER_H_ */
