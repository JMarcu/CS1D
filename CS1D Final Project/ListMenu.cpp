/*************************************************************************
 * CS1D Final Project
 * -----------------------------------------------------------------------
 * AUTHORS     : James Marcu & Phillip Doyle
 * STUDENT IDs : 374443      & 911579
 * CLASS       : CS1D
 * SECTION     : TTh 3:30 AM
 * DUE DATE    : 12/9/2014
 *************************************************************************/

#include"header.h"

//These correspond to the user's options in this menu.
enum	List_Menu_Options{
	RETURN_TO_MAIN,
	STADIUM_NAME,
	TEAM_NAME,
	AFC_STADIUMS,
	NFC_STADIUMS,
	OPEN_ROOF,
	RETRACTABLE_ROOF,
	OPENING_DATE,
	FIND_ONE
};

/*************************************************************************
 * FUNCTION ListMenu
 * -----------------------------------------------------------------------
 * This is a sub-menu for the program with options for looking at
 * stadiums.
 * -----------------------------------------------------------------------
 * PRE-CONDITIONS -
 * 	stadiumName     : The list to store all stadiums, sorted by stadium name.
 * 	teamName        : The list to store all stadiums, sorted by team name.
 * 	afcTeams        : The list to store all stadiums in the AFC.
 * 	nfcTeams        : The list to store all stadiums in the NFC.
 * 	openRoofs       : The list to store all stadiums with open roofs.
 * 	retractableRoofs: The list to store all stadiums with retractable roofs.
 * 	openingDate     : The list to store all stadiums, sorted by opening date.
 * 	stadiumMap      : The map which has all stadiums stored.
 *
 * POST-CONDITIONS -
 * 	After the user interacts with this menu and choose to exit, they
 * 	will be returned to the main menu. None of the available options here
 * 	change the program's data.
 *************************************************************************/
void ListMenu(const List<NFL_Stadium>& stadiumsAlphabetical,
			  const List<NFL_Stadium>& stadiumsTeamName,
			  const List<NFL_Stadium>& stadiumsAFC,
			  const List<NFL_Stadium>& stadiumsNFC,
			  const List<NFL_Stadium>& stadiumsOpenRoof,
			  const List<NFL_Stadium>& stadiumsRetractableRoof,
			  const List<NFL_Stadium>& stadiumsDateOpened,
			  const Map<string, NFL_Stadium>& stadiumMap)
{
	/*********************************************************************
	 * CONSTANTS
	 * -------------------------------------------------------------------
	 * USED FOR OUTPUT
	 * -------------------------------------------------------------------
	 * MENU : The main menu for the program.
	 *********************************************************************/
	const string MENU = "Would you like to list by:\n"
			            "1) Stadium Name\n"
			            "2) Team Name\n"
			            "3) AFC Conference Stadiums\n"
			            "4) NFC Conference Stadiums\n"
			            "5) Open Roof Stadiums\n"
					 	"6) Retractable Roof Stadiums\n"
			            "7) Opening Date\n"
			            "8) Find One Stadium\n"
			            "0) Go Back\n"
			            "Enter Selection: ";

	/*********************************************************************
	 * VARIABLE DECLERATIONS
	 *********************************************************************/
	//IN - Stores the user's choice from the menu.
	List_Menu_Options	userSelection;

	/*********************************************************************
	 * PROC - The user's choices in this menu will be executed until they
	 *        indicate they wish to exit.
	 *********************************************************************/
	do
	{
		/*****************************************************************
		 * INPUT - The user is shown the menu and give their choice.
		 *****************************************************************/
		userSelection = List_Menu_Options(ErrorCheckNum(8,0, MENU));
		cout << endl;

		/*****************************************************************
		 * PROC - The user's choice is executed.
		 *****************************************************************/
		switch(userSelection)
		{
			/*************************************************************
			 * OUT - A table of stadiums is output to the console which
			 *       contains all stadiums sorted by stadium name.
			 *************************************************************/
			case STADIUM_NAME:
				PrintList(stadiumsAlphabetical);
				break;

			/*************************************************************
			 * OUT - A table of stadiums is output to the console which
			 *       contains all stadiums sorted by team name.
			 *************************************************************/
			case TEAM_NAME:
				PrintList(stadiumsTeamName);
				break;

			/*************************************************************
			 * OUT - A table of stadiums is output to the console which
			 *       contains all stadiums in the AFC sorted by stadium
			 *       name.
			 *************************************************************/
			case AFC_STADIUMS:
				PrintList(stadiumsAFC);
				break;

			/*************************************************************
			 * OUT - A table of stadiums is output to the console which
			 *       contains all stadiums in the NFC sorted by stadium
			 *       name.
			 *************************************************************/
			case NFC_STADIUMS:
				PrintList(stadiumsNFC);
				break;

			/*************************************************************
			 * OUT - A table of stadiums is output to the console which
			 *       contains all stadiums with open roofs sorted by
			 *       stadium name.
			 *************************************************************/
			case OPEN_ROOF:
				PrintList(stadiumsOpenRoof);
				break;

			/*************************************************************
			 * OUT - A table of stadiums is output to the console which
			 *       contains all stadiums with retractable roofs sorted
			 *       by stadium name.
			 *************************************************************/
			case RETRACTABLE_ROOF:
				PrintList(stadiumsRetractableRoof);
				break;

			/*************************************************************
			 * OUT - A table of stadiums is output to the console which
			 *       contains all stadiums sorted by opening date.
			 *************************************************************/
			case OPENING_DATE:
				PrintList(stadiumsDateOpened);
				break;

			/*************************************************************
			 * OUT - Returns the data about a single stadium.
			 *************************************************************/
			case FIND_ONE:
				ListOneStadium(stadiumMap);
				break;

			/*************************************************************
			 * PROC - No action is taken. The user will be returned to the
			 *        main menu.
			 *************************************************************/
			case RETURN_TO_MAIN:
				break;
		}
	}while(userSelection != RETURN_TO_MAIN);
}
