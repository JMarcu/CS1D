/*************************************************************************
 * CS1D Final Project
 * -----------------------------------------------------------------------
 * AUTHORS     : James Marcu & Phillip Doyle
 * STUDENT IDs : 374443      & 911579
 * CLASS       : CS1D
 * SECTION     : TTh 3:30 PM
 * DUE DATE    : 12/9/2014
 *************************************************************************/
#ifndef ERRORCHECKNUM_H_
#define ERRORCHECKNUM_H_

#include "header.h"

/**************************************************************************
*
* FUNCTION Template ErrorCheckInput
* ________________________________________________________________________
* This function prompts the user for a numerical  input reads, in the
* input and error checks it against an upper and lower bound. If the input is
* outside the bounds or a character it outputs an error message
* ________________________________________________________________________
* PRE-CONDITIONS:
*		TOPBOUND:	an integer that holds the upper bound of an error
*					message
*		LOWERBOUND: an integer that holds the lower bound of an error
*					message
*		prompt:     a string that holds the prompt message for the user
*
* POST-CONDITIONS:
* 		This function first outputs information to the screen prompting the
* 		user on their options before allowing the user to input an integer
* 		which is later returned.
*
**************************************************************************/
template <class inputNum>
inputNum ErrorCheckNum(inputNum TOPBOUND,//IN: The Top input Bound
					inputNum LOWERBOUND, //IN: The bottom Input Bound
					string prompt) 			//IN: String containing the prompt
{
	inputNum input;			//RETURN: 	  The input read in
	bool     invalid;		//PROCESSING: If the input is valid
	int		 setWAdj;		//PROCESSING: The width for lining up
							//			  The error message
	string errorLine1;		// PROCESSING: Length of first line for
							//			   error message
	string errorLine2;		//PROCESSING: Length of second Line for
							//			  error message
	ostringstream outputFirstLine;
	ostringstream outputSecondLine;

	//INITALIZE: setting invalid to true
	invalid = true;			//PROCESSING: Used to check if input is invalid

	//INITALIZE: Creating the second line for the error message to be output
	outputSecondLine << "Please input a number between "
						<< LOWERBOUND << " and "  << left << TOPBOUND;
	errorLine2 = outputSecondLine.str();

	do //DO-WHILE: Executes while input is invalid
	{
		cout << prompt;
		//IF-ELSE-IF: Checking the input against the invalid conditions
		if(!(cin  >> input))
		{
			cout << "****  " << errorLine2 << "  ****\n\n";
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
		}
		else if (input < LOWERBOUND || input > TOPBOUND)
		{
			outputFirstLine << "The number "  <<  input <<
					" is an invalid entry";
			errorLine1 = outputFirstLine.str();

			//IF: Checking if First or second line or the error message is
			//	 larger and setting setWAdy accordingly
			if ( errorLine2.size() > errorLine1.size())
			{
				setWAdj = errorLine2.size();
			}
			else
			{
				setWAdj = errorLine1.size();
			}

			cout << "**** " << setw(setWAdj) << left << errorLine1 << " ****\n";
			cout << "**** " << setw(setWAdj) << errorLine2 << " ****\n\n";

			//INITALIZE: Reinitializing variables for the first line
			//			 of the error message
			setWAdj = 0;
			errorLine1.clear();
			outputFirstLine.str("");
			outputFirstLine.clear();
		}
		else
		{
			invalid = false;
		}
	}while( invalid); // END: DO-WHILE

	cin.ignore(numeric_limits<streamsize>::max(), '\n');

	return input;
}
#endif /* ERRORCHECKNUM_H_ */
