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
 * FUNCTION GetInput
 * _______________________________________________________________________
 * 	 Outputs a prompt and reads in input of type string from an input
 * 	 stream. Due to string's flexibility in storing data there is no error
 * 	 checking.
 * _______________________________________________________________________
 * PRE-CONDITIONS
 * 		prompt       : This will be output to the output stream before the
 * 		               input is acquired.
 * 		inputStream  : Stream to input from.
 * 		outputStream : Stream to output the prompt to.
 *
 * POST-CONDITIONS
 * 		input        : Will be returned with the data gathered from the
 * 		               input stream.
 *************************************************************************/
string GetInput (string prompt,         //IN & OUT - Prompt sent to the
		                                //           output stream before
		                                //           data is gathered.
		         istream& inputStream,  //PROC     - Stream to input from.
		         ostream& outputStream) //PROC     - Stream to output into.
{
	//VARIABLE DECLERATIONS
	string input;//OUT - Stores the gathered input.

	//Outputs the prompt then reads in the input.
	outputStream << prompt;
	getline(inputStream, input);

	return input;
}
