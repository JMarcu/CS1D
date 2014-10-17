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

/******************************
 * PRE-PROCESSOR DIRECTIVES
 ******************************/
#include <iostream>
#include <iomanip>
#include <string>
#include "Stack.h"
using namespace std;

/******************************
 * FUNCTION PROTOTYPES
 ******************************/

/*************************************************************************
 * FUNCTION ParenthesesCount
 * 	 This function will read in a mathematical expression as a string
 * 	 and determine if it's use of grouping symbols is valid. Each open
 * 	 grouping symbol is pushed onto a stack and removed as its closing
 * 	 counterpart is found. If a closing symbol that does not match the
 * 	 most recent open symbol is encountered, or if not every open symbol
 * 	 has a closing symbol, then the expression is invalid. This function
 * 	 will return true if the expression is valid, false otherwise.
 *************************************************************************/
bool ParenthesesCount(string expression);//IN - The expression to check
                                         //     the validity of.

/*************************************************************************
 * FUNCTION OutputResult
 * 	 This will output to the user whether or not the expression that they
 * 	 entered used grouping symbols in a valid way.
 *************************************************************************/
void OutputResult(bool isValid);//IN - Whether or not the expression
                                //     was valid.

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
 * FUNCTION ClassHeader
 * 	 This function takes in the programmer's name(s), the class name, and
 *	 the class section. The next argument is assignment type (assType)
 *	 which may be an 'L', or any other character (typically an 'A'). If it
 *	 is set to 'L' then the header will use the word "LAB", else it will
 *	 use the word "ASSIGNMENT" when describing the program. The parameter
 *	 assType is not case sensitive. The parameters assNum and assName
 *	 accept the name of the assignment's name and number. The function will
 *	 output a class heading based on the provided information.
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
 *   This will read in a string and a margin to fit that string into. It
 *   will parse through the string and create a version of it with new
 *   line characters before words that don't fit in the margins. This new
 *   string is returned to be output.
 *************************************************************************/
string WordWrap(string toWrap,     //IN - The string to be word wrapped.
		        int    lineLength);//IN - The width of the line to fit
                                   //     your string into.

#endif /* HEADER_H_ */
