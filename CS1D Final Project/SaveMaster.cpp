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
 * FUNCTION SaveMaster
 * -----------------------------------------------------------------------
 * This function saves the master file of stadium information.
 * -----------------------------------------------------------------------
 * PRE-CONDITIONS -
 * 	stadiumName : A list of all stadiums sorted by name.
 *
 * POST-CONDITIONS -
 *	All the stadiums will have their data stored in the master file.
 *************************************************************************/
void SaveMaster(const List<NFL_Stadium>& stadiumName)
{
	//VARIABLE DECLERATIONS
	ofstream oFile;                       //PROC - Output stream.
	List<NFL_Stadium>::Iterator stadiumIt;//PROC - Iterates the list.

	//VARIABLE INITIALIZATIONS
	stadiumIt = stadiumName.Begin();

	//Open the output file.
	oFile.open("StadiumList - Master");

	//Call the save function on each stadium and store the results in the
	//output file.
	while(stadiumIt != stadiumName.End())
	{
		oFile << (*stadiumIt).save();
		++stadiumIt;
		if(stadiumIt != stadiumName.End())
		{
			oFile << endl;
		}
	}

	oFile.close();
}
