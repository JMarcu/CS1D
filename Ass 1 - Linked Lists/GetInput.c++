/*************************************************************************
 * AUTHOR      : James Marcu
 * STUDENT ID  : 374443
 * ASS #1      : Linked Lists & Queues
 * CLASS       : CS1D
 * SECTION     : TTh 1:00 PM
 * DUE DATE    : 8/26/2014
 *************************************************************************/

#include "header.h"

/*************************************************************************
 * FUNCTION GetInput
 * _______________________________________________________________________
 * 	 This function gathers string input from the user. It will continue
 * 	 to output a prompt and request input until the user enters the string
 * 	 specified by exitStr as their input. The inputs will be stored in a
 * 	 queue which is returned when the function ends.
 * _______________________________________________________________________
 * PRE-CONDITIONS
 * 		prompt     : The prompt to give to the user when asking for input.
 * 		exitStr    : The input which will end requests for input.
 * 		outStream  : The output stream to output into.
 * 		inStream   : The input stream to read input from.
 *
 * POST-CONDITIONS
 * 		inputQueue : This linked list stores all of the gathered input in
 * 		             a queue.
 *************************************************************************/
Queue<string>* GetInput(string   prompt,    //OUT  - Will be output to the
		                                    //       user when asking for
		                                    //       input.
		                string   exitStr,   //OUT  - When the user enters
		                                    //       this requests for
		                                    //       input will stop.
		                ostream& outStream, //PROC - Stream to output to.
		                istream& inStream)  //PROC - Stream to input from.
{
	//VARIABLE DECLERATIONS
	Queue<string>*    inputQueue;//OUT  - Stores all gathered user input.
	NodeType<string>* nodePtr;   //PROC - Used to create new nodes in
	                             //       inputQueue.
	string            tempInput; //IN   - The user's input. It is read into
	                             //       here before being enqueued.

	//VARIABLE INITIALIZATIONS
	inputQueue   = new Queue<string>;

	/*********************************************************************
	 * IN & OUT - The user is given the prompt and the function reads in
	 *            their input.
	 *********************************************************************/
	outStream << prompt;
	getline(inStream, tempInput);

	/*********************************************************************
	 * PROC - If the input does not match the exitStr then a new node is
	 *        created to store this input. It is then added onto the end
	 *        of the inputQueue.
	 *********************************************************************/
	while (tempInput != exitStr)
	{
		nodePtr    =  new NodeType<string>;
		nodePtr    -> SetData(tempInput);
		inputQueue -> Enqueue(nodePtr);

		/*****************************************************************
		 * IN & OUT - The user is given the prompt and the function reads
		 *            in their input.
		 *****************************************************************/
		outStream << prompt;
		getline(inStream, tempInput);
	}
	cout << endl << endl;

	return inputQueue;
}


