/*************************************************************************
 * CS1D Final Project
 * -----------------------------------------------------------------------
 * AUTHORS     : James Marcu & Phillip Doyle
 * STUDENT IDs : 374443      & 911579
 * CLASS       : CS1D
 * SECTION     : TTh 3:30 PM
 * DUE DATE    : 12/9/2014
 *************************************************************************/

#include "header.h"

/*************************************************************************
 * FUNCTION GetInput
 * ______________________________________________________________________
 * This will get a character value from the user through the provided
 * input stream. The input will be error checked to make sure it is
 * equal to at least one of two provided values. The character will always
 * be returned as an uppercase character.
 * ______________________________________________________________________
 * PRE-CONDITIONS -
 * 	 prompt    : The prompt which will be output to the user before asking
 * 	             for input. This will be output after every failed input.
 * 	 char1     : One of the acceptable inputs.
 * 	 char2     : The other acceptable input.
 * 	 outStream : Stream to output into.
 * 	 inStream  : Stream to input from.
 *
 * POST-CONDITIONS -
 *   This will return an error checked character input.
 *************************************************************************/
char GetInput(string   prompt,   //IN & OUT - The prompt which is sent
		                         //           to the user.
		      char     char1,    //CALC     - One acceptable input.
		      char     char2,    //CALC     - Other acceptable input.
		      ostream& outStream,//CALC     - The stream to output to.
		      istream& inStream) //CALC     - The stream to input from.
{
	//VARIABLE DECLERATIONS
	bool   valid;    //CALC - Controls error checking.
	char   input;    //OUT  - Holds user input.

	//VARIABLE INITIALIZATIONS
	valid = false;

	/*********************************************************************
	 * INPUT - Asks the user for their input and reads it in. The input
	 *         will be error checked. The user will be prompted for input
	 *         until they provide valid input.
	 *********************************************************************/
	outStream << left;
	do //while (!valid)
	{
		//Prompt the user
		outStream << prompt;

		//Read in their response
		inStream.get(input);

		//Check if the input is an acceptable value. Output an error
		//if its not.
		if (toupper(input) != toupper(char1) &&
			toupper(input) != toupper(char2))
		{
			outStream <<  "**** "<< input << " is an invalid entry "
			          << "****\n";

			outStream << "**** Please input " << char1 << " or "
			          << char2 << "   ****\n\n";

			cin.ignore(numeric_limits<streamsize>::max(), '\n');
		}
		//If its good, set valid to true and exit the loop.
		else
		{
			valid = true;
		}
	}while (!valid);

	//Housekeeping
	outStream << right;
	cin.ignore(numeric_limits<streamsize>::max(), '\n');

	return toupper(input);
}
