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
 * FUNCTION SaveSouvinirs
 * -----------------------------------------------------------------------
 * This function saves the names of all Souvenir in a list to a text file.
 * -----------------------------------------------------------------------
 * PRE-CONDITIONS -
 *	souvenirList : The list to store.
 *	saveFile     : The name of the file to store the list in.
 *
 * POST-CONDITIONS -
 * 	The names of allSouvenir will be stored in saveFile.
 *************************************************************************/
void  SaveSouvinirs(List<Souvenir>		&souvenirList)
{
	//VARIABLE DECLERATIONS
	ofstream	                oFile;    //PROC - Output file stream.
	List<Souvenir>::Iterator souvIt;//PROC - Iterates through the list.

	//VARIABLE INITIALIZATIONS
	souvIt = souvenirList.Begin();

	//Open the file.
	oFile.open("Souvinir.txt");

	//Output the information for each souvenir to the file
	while(souvIt != souvenirList.End())
	{
		oFile << (*souvIt).Save();

		++souvIt;
		//IF-STATEMENT: Performs a check to ensure that an extra
		//				line is not added at end of file
		if(souvIt != souvenirList.End())
		{
			oFile << endl;
		}
	}

	oFile.close();
}



