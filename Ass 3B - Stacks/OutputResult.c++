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
 * FUNCTION OutputResult
 * _______________________________________________________________________
 * 	 This will output to the user whether or not the expression that they
 * 	 entered used grouping symbols in a valid way.
 * _______________________________________________________________________
 * PRE-CONDITIONS
 * 		isValid : Whether or not the expression was valid.
 *
 * POST-CONDITIONS
 * 		The user will receive a message in the console letting them know
 * 		if their expression was valid.
 *************************************************************************/
void OutputResult(bool isValid) //IN - Whether or not the expression
                                //     was valid.
{
	cout << "This expression\'s use of grouping symbols is ";
	if (isValid)
	{
		cout << "valid.\n\n";
	}
	else
	{
		cout << "invalid.\n\n";
	}
}
