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
 * FUNCTION CreateSouvenirMap
 * -----------------------------------------------------------------------
 * This function populates the hash map which stores all current
 * Souveniers for the program.
 * -----------------------------------------------------------------------
 * PRE-CONDITIONS -
 * 	souvenirMap  : The map to populate.
 * 	souvenirList : The list to populate.
 *
 * POST-CONDITIONS -
 * 	Will return the newly populated map and list by reference.
 *************************************************************************/
void CreateSouvenirMap(Map<string, Souvenir>& souvenirMap,
		               List<Souvenir>&        souvenirList)
{
	//VARIABLE DECLERATIONS
	Souvenir* souvenirPtr;//PROC - Creates new souvenir obejcts.
	ifstream  infile;     //PROC - Input file stream.
	string    itemName;   //PROC - Name of the souvenir.
	string    junk;       //PROC - Used to clear input.

	infile.open("Souvinir.txt");

	//Adds each Souvenir in the file to the map
	while(infile)
	{
		souvenirPtr = InstantiateSouvenir(infile);
		souvenirMap.Put(souvenirPtr->GetName(), *souvenirPtr);
	}
	infile.close();
	infile.clear();



	//Adds each Souvenir in the file to the list
	infile.open("Souvinir.txt");
	while(infile)
	{
		getline(infile,itemName);
		getline(infile, junk);
		if(souvenirMap.Find(itemName) != NULL)
		{
			souvenirList.InsertBack(souvenirMap.Find(itemName)->GetValue());
		}
		itemName.clear();
	}
	infile.close();
	infile.clear();

}
