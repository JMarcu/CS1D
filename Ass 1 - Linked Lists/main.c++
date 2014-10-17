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
 * Assignment 1: Linked Lists and Queues: Palindrome Algorithm
 * _______________________________________________________________________
 * 	 This program will read in a series of strings from the user and store
 * 	 them into a queue modeled as a doubly linked list. Once all inputs
 * 	 have been collected, the program will go through the queue and
 * 	 decide if each string is a palindrome. Before the palindrome algorithm
 * 	 is run, the strings are "cleaned" to remove any whitespace, punctuation,
 * 	 or special characters. The cleaning process also sets all characters
 * 	 in the string to lower case. Once the queue has been processed all
 * 	 of the original strings are output back to the user along with a
 * 	 message telling them if that string is a palindrome or not.
 * _______________________________________________________________________
 * INPUT
 * 		inputQueue : This stores all of the strings the user input. Input
 * 		             gathering is handled by a function which returns this
 * 		             queue.
 *
 * OUTPUT
 * 		inputQueue : The user's inputs are output back to them along with
 * 		             a message telling the user whether or not it was a
 * 		             palindrome.
 *************************************************************************/
int main()
{
	/*********************************************************************
	 * CONSTANTS
	 * -------------------------------------------------------------------
	 * USED FOR INPUT
	 * -------------------------------------------------------------------
	 * INIT_PROMPT  - This is sent to the user when the program first runs.
	 *                It describes the purpose and use of the program.
	 * INPUT_PROMPT - This is output to the user every time an input is
	 *                requested.
	 * END_INPUT    - This is the string the user should input to signify
	 *                they have finished giving the program their input.
	 *********************************************************************/
	//USED FOR INPUT
//	const string INIT_PROMPT  = "This program will tell you if a word or "
//			                    "phrase is a\n"
//
//			                    "palindrome! You may enter as many words "
//			                    "or phrases as\n"
//
//								"you want. When you are finished you will"
//			                    "be told which\n"
//
//							    "of them are palindromes.\n\n";
	const string INIT_PROMPT  = "This program will tell you if a word or "
			                    "phrase is a palindrome! You may enter as "
			                    "many words or phrases as you want. When "
			                    "you are finished you will be told which "
							    "of them are palindromes.\n\n";
	const string INPUT_PROMPT = "Please enter a word or phrase "
			                    "(\'done\' to finish): ";
	const string END_INPUT    = "done";

	//VARIABLE DECLERATIONS
	Queue<string>* inputQueue;        //IN & OUT - Stores the user's input
	                                  //           in a queue. The input
	                                  //           will be output back
	                                  //           to the user when they
	                                  //           are told which are
	                                  //           palindromes.
	string         currentString;     //PROC     - The string from the
	                                  //           queue currently being
	                                  //           processed.
	string         cleanString;       //PROC     - A clean version of the
	                                  //           currentString. All lower
	                                  //           case, no whitespace,
	                                  //           no punctuation, no
	                                  //           special characters.
	bool           stringIsPalindrome;//PROC     - True if currentString
	                                  //           is a palindrome. False
	                                  //           otherwise.

	/*********************************************************************
	 * OUTPUT - Outpust he class header to the console, then outputs the
	 *          initial prompt which describes the purpose and nature of
	 *          the program.
	 *********************************************************************/
	ClassHeader("James Marcu", "374443", "CS1D", "TTh 1:00 PM",
			    'A', 1, "Linked Lists & Queues", cout);
	cout << WordWrap(INIT_PROMPT, OUT_WIDTH);

	/*********************************************************************
	 * INPUT - This function will gather a series of strings from the
	 *         user that the user wish to check for if they are palindromes.
	 *         These string will be returned as a queue.
	 *********************************************************************/
	inputQueue = GetInput(INPUT_PROMPT, END_INPUT, cout, cin);

	/*********************************************************************
	 * PROC - This loop will run through every node in the queue.
	 *********************************************************************/
	while (!inputQueue->IsEmpty())
	{
		/*****************************************************************
		 * PROC - currentString is set to the string at the head of the
		 *        queue.
		 *****************************************************************/
		currentString = inputQueue->GetHead()->GetData();

		/*****************************************************************
		 * PROC - Each string will first be cleaned. This will remove
		 *        whitespace, punctuation, and special characters. It will
		 *        also set all characters to lower case.
		 *****************************************************************/
		cleanString = CleanString(currentString);

		/*****************************************************************
		 * PROC - The cleaned string is sent to the IsPalindrome function
		 *        which will return true if the string is a palindrome and
		 *        false if it is not.
		 *****************************************************************/
		stringIsPalindrome = IsPalindrome(cleanString);

		/*****************************************************************
		 * OUTPUT - The unclenaed string is output to the user along with
		 *          a message that tells them if the string was a
		 *          palindrome or not.
		 *****************************************************************/
		OutputPalindrome (currentString, stringIsPalindrome);

		/*****************************************************************
		 * PROC - The head of the queue is dequeued.
		 *****************************************************************/
		inputQueue->Dequeue();
	}

	return 0;
}
