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
 * FUNCTION IsPalindrome
 * _______________________________________________________________________
 * 	 This function determines whether or not a string is a palindrome
 * 	 (a palindrome is the same backwards and forwards). It does not
 * 	 itself disregard whitespace or punctuation; you must get rid of
 * 	 characters you do not want considered before calling this function.
 * 	 This function is case sensitive. The function will return true
 * 	 if the string is a palindrome, false if it is not.
 * _______________________________________________________________________
 * PRE-CONDITIONS
 * 		toCheck      : The function will check this string to see if it
 * 		               is a palindrome. Any characters you do not want
 * 		               considered (ie whitespace, punctuation, etc.) need
 * 		               to be removed BEFORE calling this function or it
 * 		               will consider them.
 *
 * POST-CONDITIONS
 * 		isPalindrome : A simple boolean. True if the string is a
 * 		               palindrome, false otherwise.
 *************************************************************************/
bool IsPalindrome(string toCheck) //IN - The string to check for if its
                                  //     a palindrome.
{
	//VARIABLE DECLERATIONS
	bool             isPalindrome; //OUT  - If the string is a palindrome.
	string::iterator frontIterator;//PROC - Used to compare characters in
	                               //       the string. Starts at the front
	                               //       and moves to the end.
	string::iterator backIterator; //PROC - Used to compare characters in
	                               //       the string. Starts at the end
	                               //       and moves to the front.

	//VARIABLE INITIALIZATIONS
	isPalindrome  = true;
	frontIterator = toCheck.begin();
	backIterator  = toCheck.end();
	backIterator--;

	/*********************************************************************
	 * PROC - This loop compares the two characters being pointed at by
	 *        the iterators. It will run until they either do not match
	 *        (ie the string is not a palindrome) or until the reach the
	 *        middle of the string (ie every character is checked).
	 *********************************************************************/
	while (isPalindrome && frontIterator < backIterator)
	{
		/*****************************************************************
		 * PROC - If the characters do not match then the string is not
		 *        a palindrome. If they do match then the iterators are
		 *        moved to their next characters.
		 *****************************************************************/
		if (*frontIterator != *backIterator)
		{
			isPalindrome = false;
		}
		else
		{
			frontIterator++;
			backIterator--;
		}
	}

	return isPalindrome;
}


