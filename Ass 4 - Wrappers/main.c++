/*************************************************************************
 * AUTHOR      : James Marcu
 * STUDENT ID  : 374443
 * ASS #4      : Queues and DeQueues
 * CLASS       : CS1D
 * SECTION     : TTh 3:30 AM
 * DUE DATE    : 9/16/2014
 *************************************************************************/

#include "header.h"

/*************************************************************************
 * Wrapping - Assignment 4: Queues and DeQues
 * _______________________________________________________________________
 * This program tests the implementation of a queue. The queue was created
 * by wrapping a deque, which was itself implemented as a doubly linked
 * list. The input is hard coded as constants, as the program only serves
 * to ensure the implementation of the queue was successful. Drivers are
 * used to output the results of each method call to the console.
 * _______________________________________________________________________
 * INPUT -
 * 	<none>
 *
 * OUTPUT -
 * 	A series of console messages will be output showing the success of
 * 	the queue's method calls.
 *************************************************************************/
int main()
{
	/*********************************************************************
	 * CONSTANTS
	 * -------------------------------------------------------------------
	 * USED FOR OUTPUT
	 * -------------------------------------------------------------------
	 * MAIN_PROMPT  : Outputs to the user on program start.
	 * EXIT_MESSAGE : Outputs to the user on program termination.
	 *
	 * -------------------------------------------------------------------
	 * USED FOR PROCESSING
	 * -------------------------------------------------------------------
	 * STRING1 : Hard coded data for testing the queue.
	 * STRING2 : Hard coded data for testing the queue.
	 * STRING3 : Hard coded data for testing the queue.
	 * STRING4 : Hard coded data for testing the queue.
	 *
	 * -------------------------------------------------------------------
	 * USED FOR FORMATTING
	 * -------------------------------------------------------------------
	 * LINE_LENGTH : Length of output lines. Used for word wrapping.
	 *********************************************************************/
	//USED FOR OUTPUT
	const string MAIN_PROMPT  = "This program tests a Queue, which was "
			                    "created by wrapping a deque, which was "
			                    "itself created by wrapping a doubly linked "
			                    "list. It calls the member functions of the "
			                    "queue and outputs the results.\n\n";
	const string EXIT_MESSAGE = "All method calls successful. Program will "
			                     "now quit.";

	//USED FOR PROCESSING
	const string STRING1      = "A man, a plan, a canal, Panama";
	const string STRING2      = "Was it a car or a cat I saw?";
	const string STRING3      = "Sit on a potato pan, Otis";
	const string STRING4      = "Isn't this a cool class?";

	//USED FOR FORMATTING
	const int    LINE_LENGTH = 80;

	//VARIABLE DECLERATIONS
	Queue queue;//IN, PROC, OUT - The queue which will be used to test
	            //                the class queue.

	/*********************************************************************
	 * OUTPUT - The class header is output to the top of the console,
	 *          followed by the program's main prompt which will give
	 *          the user instructions on what the program does.
	 *********************************************************************/
	ClassHeader("James Marcu", "374443", "CS1D", "TTh 3:30 PM",
			    'A', 3, "Stacks", cout);
	cout << WordWrap(MAIN_PROMPT, LINE_LENGTH);

	/*********************************************************************
	 * OUTPUT - Tests the size() and empty() functions on an empty queue
	 *          and outputs the results.
	 *********************************************************************/
	OutputSize(queue);
	OutputEmpty(queue);
	cout << endl;

	/*********************************************************************
	 * OUTPUT - Tests the enqueue function on four hard coded strings and
	 *          outputs the results.
	 *********************************************************************/
	OutputEnqueue(queue, STRING1);
	OutputEnqueue(queue, STRING2);
	OutputEnqueue(queue, STRING3);
	OutputEnqueue(queue, STRING4);
	cout << endl;

	/*********************************************************************
	 * OUTPUT - Tests the empty function on a non-empty queue and outputs
	 *          the results.
	 *********************************************************************/
	OutputEmpty(queue);
	cout << endl;

	/*********************************************************************
	 * OUTPUT - Tests the dequeue function on a non-empty queue.
	 *          Also tests the size and front functions on a non-empty
	 *          queue as each node is dequeued. Results will be output.
	 *********************************************************************/
	while (!queue.empty())
	{
		OutputSize(queue);
		OutputFront(queue);
		OutputDequeue(queue);
		cout << endl;
	}

	/*********************************************************************
	 * OUTPUT - Tests the size and empty functions on an empty queue. Also
	 *          done to ensure dequeuing in the previous step was
	 *          successful. Results will be output.
	 *********************************************************************/
	OutputSize(queue);
	OutputEmpty(queue);
	cout << endl;

	/*********************************************************************
	 * OUTPUT - Tests the front and dequeue methods on an empty queue and
	 *          outputs the results.
	 *********************************************************************/
	OutputFront(queue);
	OutputDequeue(queue);
	cout << endl;

	/*********************************************************************
	 * OUTPUT - Outputs an exit message for user clarity.
	 *********************************************************************/
	cout << WordWrap(EXIT_MESSAGE, LINE_LENGTH);

	return 0;
}
