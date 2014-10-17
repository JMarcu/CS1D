/*************************************************************************
 * AUTHOR      : James Marcu
 * STUDENT ID  : 374443
 * ASS #3      : Stacks
 * CLASS       : CS1D
 * SECTION     : TTh 3:30 AM
 * DUE DATE    : 9/2/2014
 *************************************************************************/

#ifndef REVERSESTACK_H_
#define REVERSESTACK_H_

#include <queue>

/*************************************************************************
 * FUNCTION ReverseStack
 * _______________________________________________________________________
 * 	 This will manipulate a stack so that it's elements are in the reverse
 * 	 order of how it was passed in.
 * _______________________________________________________________________
 * PRE-CONDITIONS
 *      TYPE           : The type of data stored in the stack.
 * 		stackToReverse : The address of the stack to reverse the elements in.
 *
 * POST-CONDITIONS
 * 		The stack will have its elements placed back in reverse order.
 *************************************************************************/
template <typename TYPE>
void ReverseStack(stack<TYPE>& stackToReverse)//OUT - The stack to reverse
                                              //      the order of.
{
	//VARIABLE DECLERATIONS
	queue<TYPE> tempQueue;//PROC - Stores the elements from the stack so
	                      //       that they can be put back in the opposite
	                      //       order.

	/*********************************************************************
	 * PROC - This will run until the stack is empty. Each element is
	 *        stored in a queue then popped off the stack.
	 *********************************************************************/
	while(!stackToReverse.empty())
	{
		tempQueue.push(stackToReverse.top());
		stackToReverse.pop();
	}

	/*********************************************************************
	 * PROC - The elements in the queue are put back in the stack. What was
	 *        on top of the stack and went into the queue first will now
	 *        go back into the stack first, placing it on the stack's
	 *        bottom. This continues until the queue is empty.
	 *********************************************************************/
	while(!tempQueue.empty())
	{
		stackToReverse.push(tempQueue.front());
		tempQueue.pop();
	}
}

#endif /* REVERSESTACK_H_ */
