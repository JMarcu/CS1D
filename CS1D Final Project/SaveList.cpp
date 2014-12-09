/*************************************************************************
 * CS1D Final Project
 * -----------------------------------------------------------------------
 * AUTHORS     : James Marcu & Phillip Doyle
 * STUDENT IDs : 374443      & 911579
 * CLASS       : CS1D
 * SECTION     : TTh 3:30 PM
 * DUE DATE    : 12/9/2014
 *************************************************************************/

#include "header.h"

/*************************************************************************
 * FUNCTION SaveList
 * -----------------------------------------------------------------------
 * This function saves the names of all stadiums in a list to a text file.
 * -----------------------------------------------------------------------
 * PRE-CONDITIONS -
 *	saveThis : The list to store.
 *	saveFile : The name of the file to store the list in.
 *
 * POST-CONDITIONS -
 * 	The names of all stadiums in saveThis will be stored in saveFile.
 *************************************************************************/
void SaveList(const List<NFL_Stadium>& saveThis, string saveFile)
{
	//VARIABLE DECLERATIONS
	ofstream	                oFile;    //PROC - Output file stream.
	List<NFL_Stadium>::Iterator stadiumIt;//PROC - Iterates through the list.

	//VARIABLE INITIALIZATIONS
	stadiumIt = saveThis.Begin();

	//Open the file.
	oFile.open(saveFile.c_str());

	//Output the name of each stadium to the output file.
	while(stadiumIt != saveThis.End())
	{
		oFile << (*stadiumIt).get_stadium_name();
		++stadiumIt;
		//IF-STATEMENT: Performs a check to ensure that an extra
		//				line is not added at end of file
		if(stadiumIt != saveThis.End())
		{
			oFile << endl;
		}
	}

	oFile.close();
}

