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
 * FUNCTION OutputPalindrome
 * _______________________________________________________________________
 * 	 This is an output function for a program designed to tell whether
 * 	 or not a word or phrase is a palindrome. The word or phrase is passed
 * 	 in as a string and a bool is passed in for whether or not it is a
 * 	 palindrome. The function will output a message to the user telling
 * 	 them whether or not that phrase is a palindrome.
 * _______________________________________________________________________
 * PRE-CONDITIONS
 * 		word       : The string in question.
 * 		palindrome : Whether or not that string is a palindrome.
 *
 * POST-CONDITIONS
 * 		A message will be output to the user containing the string and
 * 		whether or not it is a palindrome.
 *************************************************************************/
void OutputPalindrome (string word,       //OUT  - The string which may or
		                                  //       may not be a palindrome.
		               bool   palindrome) //PROC - True if word is a
                                          //       palindrome. False
                                          //       otherwise.
{
	//VARIABLE DECLERATIONS
	string outputString; //Stores the output as a string so that it can
	                     //be word wrapped.

	//VARIABLE INITIALIZATIONS
	outputString = "";

	//Stores word into outputString.
	outputString += "\"" + word + "\" is ";

	//If the word is not a palindrome, outputs the word "not".
	if (!palindrome)
	{
		outputString += "not ";
	}

	//Finishes the sentence.
	outputString += "a palindrome!\n";

	//Outputs a word wrapped version of the output string to the console.
	cout << WordWrap(outputString, OUT_WIDTH);
}
