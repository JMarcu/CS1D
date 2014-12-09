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
 * FUNCTION CreateHashMap
 * -----------------------------------------------------------------------
 * This function initializes the hash map which stores all current NFL
 * stadiums for the program.
 * -----------------------------------------------------------------------
 * PRE-CONDITIONS -
 * 	stadiumMap : The map to initialize.
 *
 * POST-CONDITIONS -
 * 	Will return a reference to the newly instantiated hash map.
 *************************************************************************/
void CreateHashMap (Map<string, NFL_Stadium>& stadiumMap)
{
	//VARIABLE DECLERATIONS
	NFL_Stadium* stadiumPtr;//Used to add stadiums to the map.
	ifstream     inFile;     //Input file stream.

	//VARIABLE INITIALIZATIONS
	inFile.open("StadiumList - Master");

	/*********************************************************************
	 * PROC - Each stadium is constructed individually by InstantiateStadium
	 *        and then stored in stadiumPtr to be added to the map. This
	 *        goes on until the input file is empty.
	 *********************************************************************/
	while(inFile)
	{
		//Create a new stadium object from the input file.
		stadiumPtr = InstantiateStadium(inFile);

		//Add it to the map.
		stadiumMap.Put(stadiumPtr->get_stadium_name(), *stadiumPtr);
	}

	//Housekeeping
	inFile.close();
}


