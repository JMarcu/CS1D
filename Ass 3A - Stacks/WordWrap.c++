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
 * FUNCTION WordWrap
 * ______________________________________________________________________
 * This will read in a string and a margin to fit that string into. It
 * will parse through the string and create a version of it with new
 * line characters before words that don't fit in the margins. This new
 * string is returned to be output.
 * ______________________________________________________________________
 * PRE-CONDITIONS -
 * 	toWrap     : The string you want to be word wrapped.
 * 	lineLength : The width of the line you want the string to conform to.
 *
 * POST-CONDITIONS -
 * 	wrapped    : A version of the input string which has been word wrapped
 * 	             with new line characters.
 *************************************************************************/
string WordWrap(string toWrap,     //IN - The string to be word wrapped.
		        int    lineLength) //IN - The width of the line to fit
                                   //     your string into.
{
	//VARIABLE DECLERATIONS
	int    charCount;   //CALC - Iterates through the string.
	int    stringLength;//CALC - Total length of the string.
	string word;        //CALC - Temporarily stores words from your string.
	string line;        //CALC - Stores a line until it would exceed the
	                    //       the margin.
	string wrapped;     //OUT  - Final version of the word wrapped string.

	//VARIABLE INITIALIZATIONS
	stringLength = toWrap.length();
	word    = "";
	line    = "";
	wrapped = "";

	//Iterates through every character of the string
	for (charCount = 0; charCount < stringLength; charCount++)
	{
		//If this character is not a space then its added to the current
		//word.
		if (toWrap[charCount] != ' ')
		{
			word = word + toWrap[charCount];
		}
		else //If it is a space then the word has ended
		{
			//If the word can't fit on the current line without going
			//over the margin then add it to the final string with a new
			//line character and reset the line.
			if (line.length() + word.length() > lineLength)
			{
				wrapped = wrapped + line + '\n';
				line.clear();
			}
			//Update line with the word and add a space after. Then reset
			//word.
			line = line + word + ' ';
			word.clear();
		}
	}

	//This checks the last word, which won't be checked above because there
	//probably isn't a space at the end of your string.
	if (line.length() + word.length() > lineLength)
	{
		wrapped = wrapped + line + '\n';
		line.clear();
	}
	wrapped = wrapped + line + word;

	return wrapped;
}
