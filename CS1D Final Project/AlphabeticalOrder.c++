/*************************************************************************
 * CS1D Final Project
 * -----------------------------------------------------------------------
 * AUTHORS     : James Marcu & Phillip Doyle
 * STUDENT IDs : 374443      & 911579
 * CLASS       : CS1D
 * SECTION     : TTh 3:30 AM
 * DUE DATE    : 12/9/2014
 *************************************************************************/

#include "header.h"

/*************************************************************************
 * FUNCTION AlphabeticalOrder
 * -----------------------------------------------------------------------
 * This function returns true if the first string passed in is before
 * the second string passed in alphabetically. This function has a couple
 * of important differences between it and the compare method of the string
 * class. First of all, it is case independent. For true alphabetical
 * ordering compare needs all characters to be the same case. Second,
 * this orders the shorter word before the longer one (if all characters
 * match) rather than after it, unlike compare.
 * -----------------------------------------------------------------------
 * PRE-CONDITIONS -
 * 	stringOne: The first string to compare.
 * 	stringTwo: The second string to compare.
 *
 * POST-CONDITIONS -
 * 	This will return true if the first string is before the second
 * 	alphabetically.
 *************************************************************************/
bool AlphabeticalOrder(string stringOne, string stringTwo)
{
	//VARIABLE DECLERATIONS
	string::iterator oneIt;	   //PROC - Iterates the first string.
	string::iterator twoIt;	   //PROC - Iterates the second string.
	bool             keepGoing;//PROC - Controls main loop.
	bool             inOrder;  //PROC - If the strings are in order.

	//VARIABLE INITIALIZATIONS
	oneIt = stringOne.begin();
	twoIt = stringTwo.begin();
	keepGoing = true;

	/*********************************************************************
	 * PROC - There are a number of conditions that can cause the sort
	 *        to exit.
	 *********************************************************************/
	while(keepGoing)
	{
		//If the second string has ended but the first hasn't then they
		//aren't in order.
		if(twoIt == stringTwo.end() && oneIt != stringOne.end())
		{
			inOrder   = false;
			keepGoing = false;
		}
		//If the first string has ended, whether or not the second string
		//has ended, they are in order.
		else if(oneIt == stringOne.end())
		{
			inOrder   = true;
			keepGoing = false;
		}
		//If string one's character is greater than string two's character
		//then they aren't in order.
		else if(toupper(*oneIt) > toupper(*twoIt))
		{
			inOrder   = false;
			keepGoing = false;
		}
		//If string one's character is less than string two's character
		//then they are in order.
		else if(toupper(*oneIt) < toupper(*twoIt))
		{
			inOrder   = true;
			keepGoing = false;
		}
		//If neither string has ended and the characters are equal we need
		//to check the next character.
		else
		{
			++oneIt;
			++twoIt;
		}
	}

	return inOrder;
}

