/*************************************************************************
 * AUTHOR      : James Marcu
 * STUDENT ID  : 374443
 * ASS #3      : Stacks
 * CLASS       : CS1D
 * SECTION     : TTh 3:30 AM
 * DUE DATE    : 9/2/2014
 *************************************************************************/

#ifndef PRINTSTACK_H_
#define PRINTSTACK_H_

#include <stack>
#include <iostream>
using namespace std;

/*************************************************************************
 * FUNCTION PrintStack
 * _______________________________________________________________________
 * 	 Prints the data stored in a stack to the console.
 * _______________________________________________________________________
 * PRE-CONDITIONS
 *      TYPE         : The type of data stored in the stack.
 * 		stackToPrint : The address of the stack to print.
 * 		prompt       : This is a string which will be printed before the
 * 		               stack to give context to the end user.
 *
 * POST-CONDITIONS
 * 		The stack will be printed out to the console.
 *************************************************************************/
template <typename TYPE>
void PrintStack(stack<TYPE>& stackToPrint,//OUT - The stack whose data you
		                                  //      want printed.
		        string prompt)            //OUT - Will be output to the
                                          //      user before printing the
                                          //      stack.
{
	//VARIABLE DECLERATIONS
	stack<TYPE> tempStack;//PROC - Used to store elements from the initial
	                      //       stack as it is moved through. The initial
	                      //       stack is recreated from this.
	int         element;  //PROC & OUT - Keeps track of which element of
	                      //             the stack is being printed. Output
	                      //             to the user for clarity.

	//VARIABLE INITIALIZATIONS
	element = 1;

	/*********************************************************************
	 * OUT - Outputs the prompt to the user.
	 *********************************************************************/
	cout << prompt;

	/*********************************************************************
	 * PROC - This loop will move through the stack until it reaches the
	 *        end.
	 *********************************************************************/
	while (!stackToPrint.empty())
	{
		/*****************************************************************
		 * OUT - Outputs the current element to the user, along with what
		 *       element number it was.
		 *****************************************************************/
		cout << "Item #" << element << ": " << stackToPrint.top() << endl;


		/*****************************************************************
		 * PROC - The element just printed is put onto the tempStack and
		 *        then popped off the initial stack so that the next
		 *        element can be printed.
		 *****************************************************************/
		tempStack.push(stackToPrint.top());
		stackToPrint.pop();

		//Increments the element counter
		element++;
	}
	cout << endl;//For formatting.

	/*********************************************************************
	 * PROC - This puts the initial stack back together from the tempStack.
	 *********************************************************************/
	while(!tempStack.empty())
	{
		stackToPrint.push(tempStack.top());
		tempStack.pop();
	}
}

#endif /* PRINTSTACK_H_ */
