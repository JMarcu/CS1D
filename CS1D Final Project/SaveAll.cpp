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
 * FUNCTION SaveAll
 * -----------------------------------------------------------------------
 * This function calls the save function on the stadium map and all of
 * the stadium lists.
 * -----------------------------------------------------------------------
 * PRE-CONDITIONS -
 *  stadiumName      : List of all stadiums sorted by stadium name.
 *  teamName         : List of all stadiums sorted by team name.
 *  afcTeams         : List of all stadiums in the AFC.
 *  nfcTeams         : List of all stadiums in the NFC.
 *  openRoofs        : List of all stadiums with an open roof.
 * 	retractableRoofs : List of all stadiums with a retractable roof.
 * 	openingDate      : List of all stadiums sorted by opening date.
 * 	stadiumMap       : Map containing all stadiums.
 *
 * POST-CONDITIONS -
 *	The text files which store the initialization data for these lists and
 *	the map will be rewritten with any changes made during runtime.
 *************************************************************************/
void SaveAll(const List<NFL_Stadium>& stadiumName,
			 const List<NFL_Stadium>& teamName,
			 const List<NFL_Stadium>& afcTeams,
			 const List<NFL_Stadium>& nfcTeams,
			 const List<NFL_Stadium>& openRoofs,
			 const List<NFL_Stadium>& retractableRoofs,
			 const List<NFL_Stadium>& openingDate,
			 const Map<string, NFL_Stadium>& stadiumMap)
{
	SaveMaster(stadiumName);
	SaveList(stadiumName, "StadiumList - Stadium Name");
	SaveList(teamName, "StadiumList - Team Name");
	SaveList(afcTeams, "StadiumList - AFC");
	SaveList(nfcTeams, "StadiumList - NFC");
	SaveList(openRoofs, "StadiumList - Open Roof");
	SaveList(retractableRoofs, "StadiumList - Retractable Roof");
	SaveList(openingDate, "StadiumList - Date Opened");
}



