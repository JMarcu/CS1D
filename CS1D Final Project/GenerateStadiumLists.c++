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
 * FUNCTION GenerateStadiumLists
 * -----------------------------------------------------------------------
 * This function will generate the stadium lists for the program from the
 * storage files.
 * -----------------------------------------------------------------------
 * INPUT -
 * 	stadiumName     : The list to store all stadiums, sorted by stadium name.
 * 	teamName        : The list to store all stadiums, sorted by team name.
 * 	afcTeams        : The list to store all stadiums in the AFC.
 * 	nfcTeams        : The list to store all stadiums in the NFC.
 * 	openRoofs       : The list to store all stadiums with open roofs.
 * 	retractableRoofs: The list to store all stadiums with retractable roofs.
 * 	openingDate     : The list to store all stadiums, sorted by opening date.
 * 	stadiumMap      : The map which has all stadiums stored.
 *
 * OUTPUT -
 * 	The lists which were passed in by reference will be filled with the
 * 	appropriate stadiums.
 *************************************************************************/
void GenerateStadiumLists(List<NFL_Stadium>&  stadiumName,
						  List<NFL_Stadium>&  teamName,
						  List<NFL_Stadium>&  afcTeams,
						  List<NFL_Stadium>&  nfcTeams,
						  List<NFL_Stadium>&  openRoofs,
						  List<NFL_Stadium>&  retractableRoofs,
						  List<NFL_Stadium>&  openingDate,
						  const Map<string, NFL_Stadium>& stadiumMap)
{
	/*********************************************************************
	 * VARIABLE DECLERATIONS
	 *********************************************************************/
	//PROC - The file stream variable.
	ifstream inFile;

	//PROC - Temporarily stores input from the files.
	string   temp;

	/*********************************************************************
	 * IN & PROC - Reads in stadium names from the input file. These names
	 *             are used as keys to access stadium objects from the
	 *             map. These stadium objects are then added to the
	 *             appropriate list.
	 *********************************************************************/
	inFile.open("StadiumList - Stadium Name");
	while(inFile.good())
	{
		getline(inFile, temp);
		stadiumName.InsertBack(stadiumMap.Find(temp)->GetValue());
		temp = "";
	}
	inFile.close();
	inFile.clear();

	/*********************************************************************
	 * IN & PROC - Reads in stadium names from the input file. These names
	 *             are used as keys to access stadium objects from the
	 *             map. These stadium objects are then added to the
	 *             appropriate list.
	 *********************************************************************/
	inFile.open("StadiumList - Team Name");
	while(inFile.good())
	{
		getline(inFile, temp);
		teamName.InsertBack((stadiumMap.Find(temp))->GetValue());
		temp = "";
	}
	inFile.close();
	inFile.clear();

	/*********************************************************************
	 * IN & PROC - Reads in stadium names from the input file. These names
	 *             are used as keys to access stadium objects from the
	 *             map. These stadium objects are then added to the
	 *             appropriate list.
	 *********************************************************************/
	inFile.open("StadiumList - AFC");
	while(inFile.good())
	{
		getline(inFile, temp);
		afcTeams.InsertBack((stadiumMap.Find(temp))->GetValue());
		temp = "";
	}
	inFile.close();
	inFile.clear();

	/*********************************************************************
	 * IN & PROC - Reads in stadium names from the input file. These names
	 *             are used as keys to access stadium objects from the
	 *             map. These stadium objects are then added to the
	 *             appropriate list.
	 *********************************************************************/
	inFile.open("StadiumList - NFC");
	while(inFile.good())
	{
		getline(inFile, temp);
		nfcTeams.InsertBack((stadiumMap.Find(temp))->GetValue());
		temp = "";
	}
	inFile.close();
	inFile.clear();

	/*********************************************************************
	 * IN & PROC - Reads in stadium names from the input file. These names
	 *             are used as keys to access stadium objects from the
	 *             map. These stadium objects are then added to the
	 *             appropriate list.
	 *********************************************************************/
	inFile.open("StadiumList - Open Roof");
	while(inFile.good())
	{
		getline(inFile, temp);
		openRoofs.InsertBack((stadiumMap.Find(temp))->GetValue());
		temp = "";
	}
	inFile.close();
	inFile.clear();

	/*********************************************************************
	 * IN & PROC - Reads in stadium names from the input file. These names
	 *             are used as keys to access stadium objects from the
	 *             map. These stadium objects are then added to the
	 *             appropriate list.
	 *********************************************************************/
	inFile.open("StadiumList - Retractable Roof");
	while(inFile.good())
	{
		getline(inFile, temp);
		retractableRoofs.InsertBack((stadiumMap.Find(temp))->GetValue());
		temp = "";
	}
	inFile.close();
	inFile.clear();

	/*********************************************************************
	 * IN & PROC - Reads in stadium names from the input file. These names
	 *             are used as keys to access stadium objects from the
	 *             map. These stadium objects are then added to the
	 *             appropriate list.
	 *********************************************************************/
	inFile.open("StadiumList - Date Opened");
	while(inFile.good())
	{
		getline(inFile, temp);
		openingDate.InsertBack((stadiumMap.Find(temp))->GetValue());
		temp = "";
	}
	inFile.close();
	inFile.clear();
}
