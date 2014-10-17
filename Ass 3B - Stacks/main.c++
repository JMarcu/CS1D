/*************************************************************************
 * AUTHOR      : James Marcu
 * STUDENT ID  : 374443
 * ASS #3      : Stacks
 * CLASS       : CS1D
 * SECTION     : TTh 3:30 AM
 * DUE DATE    : 9/2/2014
 *************************************************************************/

#include "header.h"

int main()
{
	/*********************************************************************
	 * CONSTANTS
	 * -------------------------------------------------------------------
	 * USED FOR OUTPUT
	 * -------------------------------------------------------------------
	 * MAIN_PROMPT  : Output to the user when they first start the program.
	 * INPUT_PROMPT : Output to the user when they are asked for input.
	 * EXIT_MESSAGE : Output to the user when the program finishes.
	 *
	 * -------------------------------------------------------------------
	 * USED FOR FORMATTING
	 * -------------------------------------------------------------------
	 * LINE_LENGTH  : The length lines of output should be.
	 *********************************************************************/
	//USED FOR OUTPUT
	const string MAIN_PROMPT  = "Welcome. This program will ask you for "
			                    "algebraic expressions and will tell you "
			                    "if you have used the correct number and "
			                    "type of grouping symbols (i.e. '(', '[', "
			                    "and '{'). You may enter as many "
			                    "expressions into the program as you "
			                    "like.\n\n";
	const string INPUT_PROMPT = "Please enter an expression to check "
			                    "('exit' to quit): ";
	const string EXIT_MESSAGE = "Thank you for using this program. The "
			                    "program will now exit.";

	//USED FOR FORMATTING
	const int    LINE_LENGTH  = 80;

	//VARIABLE DECLERATIONS
	string expression;
	bool   expressionIsValid;
	bool   cont;

	//VARIABLE INITIALIZATIONS
	cont = true;

	/*********************************************************************
	 * OUTPUT - The class header is output to the top of the console,
	 *          followed by the program's main prompt which will give
	 *          the user instructions on what the program does.
	 *********************************************************************/
	ClassHeader("James Marcu", "374443", "CS1D", "TTh 3:30 PM",
			    'A', 3, "Stacks", cout);
	cout << WordWrap(MAIN_PROMPT, LINE_LENGTH);

	/*********************************************************************
	 * INPUT - The user is asked  for the expression they would like to
	 *         have checked. They may enter 'exit' to quit the program.
	 *         If they enter 'exit' then the program exits.
	 *********************************************************************/
	expression = GetInput(INPUT_PROMPT, cin, cout);
	if (expression == "exit")
	{
		cont = false;
	}

	while(cont)
	{
		expressionIsValid = ParenthesesCount(expression);

		OutputResult(expressionIsValid);

		/*****************************************************************
		 * INPUT - The user is asked  for the expression they would like to
		 *         have checked. They may enter 'exit' to quit the program.
		 *         If they enter 'exit' then the program exits.
		 *****************************************************************/
		expression = GetInput(INPUT_PROMPT, cin, cout);
		if (expression == "exit")
		{
			cont = false;
		}
	}

	cout << EXIT_MESSAGE;

	return 0;
}




