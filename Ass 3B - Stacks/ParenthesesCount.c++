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
 * FUNCTION ParenthesesCount
 * _______________________________________________________________________
 * 	 This function will read in a mathematical expression as a string
 * 	 and determine if it's use of grouping symbols is valid. Each open
 * 	 grouping symbol is pushed onto a stack and removed as its closing
 * 	 counterpart is found. If a closing symbol that does not match the
 * 	 most recent open symbol is encountered, or if not every open symbol
 * 	 has a closing symbol, then the expression is invalid. This function
 * 	 will return true if the expression is valid, false otherwise.
 * _______________________________________________________________________
 * PRE-CONDITIONS
 * 		expression : The mathematical expression to check the validity of.
 *
 * POST-CONDITIONS
 * 		isValid    : This will return true if the expression's use of
 * 		             grouping symbols was valid.
 *************************************************************************/
bool ParenthesesCount(string expression) //IN - The expression to check
                                         //     the validity of.
{
	/*********************************************************************
	 * CONSTANTS
	 * -------------------------------------------------------------------
	 * USED FOR PROCESSING
	 * -------------------------------------------------------------------
	 * OPEN_PARAN   : The ASCII value of an open parentheses '('
	 * CLOSE_PARAN  : The ASCII value of a closed parentheses ')'
	 * OPEN_SQUARE  : The ASCII value of an open square bracket '['
	 * CLOSE_SQUARE : The ASCII value of a closed square bracket ']'
	 * OPEN_CURLY   : The ASCII value of an open curly bracket '{'
	 * CLOSE_CURLY  : The ASCII value of a closed curly bracket '}'
	 *********************************************************************/
	//USED FOR PROCESSING
	const int OPEN_PARAN   = 40;
	const int CLOSE_PARAN  = 41;
	const int OPEN_SQUARE  = 91;
	const int CLOSE_SQUARE = 93;
	const int OPEN_CURLY   = 123;
	const int CLOSE_CURLY  = 125;

	//VARIABLE DECLERATIONS
	Stack<char>*     groupingStack;//PROC - Stores open grouping symbols
	                               //       from the expression and
	                               //       removes them when it finds
	                               //       corresponding closed symbols.
	string::iterator frontIterator;//PROC - Used to compare characters in
	                               //       the string. Starts at the front
	                               //       and moves to the end.
	string::iterator backIterator; //PROC - Used to compare characters in
	                               //       the string. Starts at the end
	                               //       and moves to the front.
	bool             isValid;      //OUT  - Returns true if the expressions
	                               //       grouping symbols are valid.

	//VARIABLE INITIALIZATIONS
	groupingStack = new Stack<char>;
	frontIterator = expression.begin();
	backIterator  = expression.end();
	isValid       = true;

	/*********************************************************************
	 * PROC - This will check every character in the expression.
	 *********************************************************************/
	while (isValid && frontIterator != backIterator)
	{
		/*****************************************************************
		 * PROC - If the character is an open grouping symbol it is pushed
		 *        onto the stack.
		 *
		 *        Else if the character is a closed grouping symbol there
		 *        is a secondary check for validity.
		 *
		 *        If it is neither then no action is taken and the program
		 *        goes straight to incrementing the iterator.
		 *****************************************************************/
		if (*frontIterator == OPEN_PARAN  ||
			*frontIterator == OPEN_SQUARE ||
			*frontIterator == OPEN_CURLY)
		{
			groupingStack->Push(*frontIterator);
		}
		else if (*frontIterator == CLOSE_PARAN  ||
				 *frontIterator == CLOSE_SQUARE ||
				 *frontIterator == CLOSE_CURLY)
		{
			/**************************************************************
			 * PROC - If the character is a closed grouping symbol, it
			 *        checks first that the stack is not empty. If the
			 *        stack is empty then it is incorrect to have a closed
			 *        grouping symbol and the expression is invalid.
			 *
			 *        If the stack is not empty then it checks if the
			 *        closing symbol matches the most recent open symbol.
			 *        If it does not then the expression is invalid.
			 *************************************************************/
			if (groupingStack->Empty())
			{
				isValid = false;
			}
			else if (groupingStack->Top()->GetData() + 1 != *frontIterator &&
					 groupingStack->Top()->GetData() + 2 != *frontIterator)
			{
				isValid = false;
			}
			else
			{
				groupingStack->Pop();
			}
		}

		//Increments the iterator.
		frontIterator++;
	}//END while (isValid && frontIterator != backIterator)

	/*********************************************************************
	 * PROC - If at the end the stack is not empty then some open symbols
	 *        were never closed and the expression is invalid.
	 *********************************************************************/
	if (!groupingStack->Empty())
	{
		isValid = false;
	}

	return isValid;
}
