/*************************************************************************
 * AUTHOR      : James Marcu
 * STUDENT ID  : 374443
 * ASS #3      : Stacks
 * CLASS       : CS1D
 * SECTION     : TTh 3:30 AM
 * DUE DATE    : 9/2/2014
 *************************************************************************/

#ifndef STACKPROCESSING_C___
#define STACKPROCESSING_C___

#include "PrintStack.h"
#include "ReverseStack.h"

/*************************************************************************
 * FUNCTION StackProcessing
 * _______________________________________________________________________
 * 	 This function is responsible for handling the bulk of the program's
 * 	 work. It was conveniant to write as a template so that each of the
 * 	 functions called here did not have to be called seperately inside of
 * 	 an if statement in main for each possible datatype. No actual work
 * 	 is done in this function. Instead, it calls other functions to
 * 	 manipulate the stack.
 *
 * 	 First the stack is created from the input file. Then it is printed to
 * 	 the user. After that it is reversed, then printed out again. Finally
 * 	 it is destroyed.
 * _______________________________________________________________________
 * PRE-CONDITIONS
 *      TYPE      : The type of data stored in the stack.
 * 		inputFile : An open filestream that contains the input data for
 * 		            the stack.
 *
 * POST-CONDITIONS
 * 		The stack will have been created, printed, reversed, printed
 * 		again, and then destroyed.
 *
 * 		The inputstream will have its position
 * 		at the end of the file.
 *************************************************************************/
template <typename TYPE>
void StackProcessing (ifstream& inputFile)
{
	//VARIABLE DECLERATIONS
	stack<TYPE>* stackPtr;//IN, PROC, & OUT - A pointer is used so that the
	                      //                  stack can be deleted at the
	                      //                  end of the function easily.

	//VARIABLE INITIALIZATIONS
	stackPtr = new stack<TYPE>;

	/*********************************************************************
	 * PROC - First the stack is written from the input file.
	 *        Then the stack is printed to the user.
	 *        After the stack is reversed.
	 *        Finally it is printed out to the user one last time.
	 *********************************************************************/
	WriteStack(*stackPtr, inputFile);
	PrintStack(*stackPtr, "Your data from the file: \n");
	ReverseStack(*stackPtr);
	PrintStack(*stackPtr, "Your data, now reversed: \n");

	//The stack is deleted and the pointer set to null, just to be safe.
	delete stackPtr;
	stackPtr = NULL;

	//The user is updated for clarity.
	cout << "Processing of file complete.\n\n";
}


#endif /* STACKPROCESSING_C___ */
