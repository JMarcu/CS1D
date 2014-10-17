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
 * FUNCTION CleanString
 * _______________________________________________________________________
 * 	 This function will read in a string and return a version of that
 * 	 string which has been stripped of all punctuation, symbols and
 * 	 whitespace. It will also be shifted into lowercase. The returned
 * 	 string will only contain lowercase letters.
 * _______________________________________________________________________
 * PRE-CONDITIONS
 * 		toClean : The string which the function will clean.
 *
 * POST-CONDITIONS
 * 		cleaned : A version of toClean with only letters. These letters
 * 		          have been shifted into lowercase.
 *************************************************************************/
string CleanString (string toClean) //IN - The string to clean.
{
	//VARIABLE DECLERATIONS
	string cleaned;     //OUT  - The version of toClean which has been
	                    //       cleaned. This is returned.
	string::iterator it;//PROC - An iterator used to move through toClean
	                    //       letter by letter.

	//VARIABLE INITIALIZATIONS
	cleaned = "";

	/*********************************************************************
	 * PROC - The function will move through the string character by
	 *        character. If the current character is a letter it is
	 *        shifted to lowercase and added onto the output string.
	 *        If it is not a letter then the function does nothing
	 *        and moves on to the next character.
	 *********************************************************************/
	for (it = toClean.begin(); it != toClean.end(); it++)
	{
		if ((char(*it) >= 65 && char(*it) <=89) ||
			(char(*it) >= 97 && char(*it) <=122))
		{
			cleaned.push_back(tolower(char(*it)));
		}
	}

	return cleaned;
}
