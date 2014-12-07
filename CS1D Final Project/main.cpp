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

int	main()
{
	/*********************************************************************
	 * CONSTANTS
	 * -------------------------------------------------------------------
	 * USED FOR OUTPUT
	 * -------------------------------------------------------------------
	 * MAIN_MENU : The main menu for the program.
	 * EXIT      : Displays when the program exits.
	 *********************************************************************/
	const string MAIN_MENU    = "Main Menu:\n"
							 	"------------------------------\n"
								"1) Explore NFL Stadium Details\n"
							 	"2) Trip Planner\n"
							 	"3) Souvenirs\n"
							 	"4) Administrator Options\n"
							 	"0) Exit\n"
							 	"Enter Selection: ";

	const string EXIT_MESSAGE = "Thank you for using our program. It will "
			                    "now exit.";

	/*********************************************************************
	 * VARIABLE DECLERATIONS
	 *********************************************************************/
	//IN, PROC - This map stores all the stadiums in the program.
	//           Any accessing of stadiums directly is done through here.
	Map<string, NFL_Stadium> stadiumMap(&StringHashOne, &StringHashTwo);

	//IN, PROC, OUT - A list of all stadiums sorted by stadium name.
	List<NFL_Stadium> stadiumsAlphabetical;

	//IN, PROC, OUT - A list of all stadiums sorted by team name.
	List<NFL_Stadium> stadiumsTeamName;

	//IN, PROC, OUT - A list of all stadiums in the AFC.
	List<NFL_Stadium> stadiumsAFC;

	//IN, PROC, OUT - A list of all stadiums in the NFC.
	List<NFL_Stadium> stadiumsNFC;

	//IN, PROC, OUT - A list of all stadiums with open roofs.
	List<NFL_Stadium> stadiumsOpenRoof;

	//IN, PROC, OUT - A list of all stadiums with retractable roofs.
	List<NFL_Stadium> stadiumsRetractableRoof;

	//IN, PROC, OUT - A list of all stadiums, sorted by opening date.
	List<NFL_Stadium> stadiumsDateOpened;

	//IN, PROC, OUT - This map contains all souvenir objects which may
	//                be purchased by end users.
	Map<string, Souvenir> souvenirMap(&StringHashOne, &StringHashTwo);

	//IN, PROC, OUT - This graph is used to plan trips to the stadiums.
	Graph<NFL_Stadium> stadiumGraph;

	//IN, PROC, OUT - This list contains all souvenir objects which may
	//                be purchased by end users.
	List<Souvenir>		souvenirList;

	//IN - Stores the user's choice when in the console menu.
	Main_Menu_Options	userSelection;

	/*********************************************************************
	 * PROC - This will generate the map of all stadiums from the storage
	 *        file. Then the stadium lists will be instantiated from their
	 *        own lists and the map. Finally, the souvenir map will be
	 *        created.
	 *********************************************************************/
	CreateHashMap(stadiumMap);
	GenerateStadiumLists(stadiumsAlphabetical,
						 stadiumsTeamName,
						 stadiumsAFC,
						 stadiumsNFC,
						 stadiumsOpenRoof,
						 stadiumsRetractableRoof,
						 stadiumsDateOpened,
						 stadiumMap);
	CreateSouvenirMap(souvenirMap,souvenirList);
	CreateGraph(stadiumGraph, stadiumsAlphabetical, stadiumMap);


	/*********************************************************************
	 * INPUT - This loop will output the program's main menu to the user
	 *         and read in the user's choice. The appropriate function
	 *         will be called to handle the user's choice and when they
	 *         have finished they will be brought back here. The loop will
	 *         run until the user chooses to exit the program.
	 *********************************************************************/
	do{
		/*****************************************************************
		 * INPUT - Displays the main menu to the user and reads in their
		 *         choice of action.
		 *****************************************************************/
		userSelection = Main_Menu_Options(ErrorCheckNum(4,0, MAIN_MENU));
		cout << endl;

		/*****************************************************************
		 * PROC - Based on the user's input the appropriate action will be
		 *        taken.
		 *****************************************************************/
		switch(userSelection)
		{
			/*************************************************************
			 * PROC - If the user elects to exit the map and all lists will
			 *        be saved before the program quits.
			 *************************************************************/
			case EXIT:
				SaveAll(stadiumsAlphabetical,
						stadiumsTeamName,
						stadiumsAFC,
						stadiumsNFC,
						stadiumsOpenRoof,
						stadiumsRetractableRoof,
						stadiumsDateOpened,
						stadiumMap);
				 SaveSouvinirs(souvenirList);
				break;

			/*************************************************************
			 * PROC - The user will be brought to a new menu for interacting
			 *        with the stadiums.
			 *************************************************************/
			case	LIST_MENU:
				ListMenu(stadiumsAlphabetical,
						 stadiumsTeamName,
						 stadiumsAFC,
						 stadiumsNFC,
						 stadiumsOpenRoof,
						 stadiumsRetractableRoof,
						 stadiumsDateOpened,
						 stadiumMap);
				break;

			/*************************************************************
			 * PROC - The user will be brought to a new menu for planning a
			 *        trip to visit NFL stadiums.
			 *************************************************************/
			case	TRIP_MENU:
				TripPlannerMenu(stadiumsAlphabetical,
						 stadiumsTeamName,
						 stadiumsAFC,
						 stadiumsNFC,
						 stadiumsOpenRoof,
						 stadiumsRetractableRoof,
						 stadiumsDateOpened,
						 stadiumMap,
						 stadiumGraph,
						 souvenirList);

				break;

			/*************************************************************
			 * PROC - The user will be brought to a new menu for
			 *        interacting with souvenirs.
			 *************************************************************/
			case	SOUVINIR_OPTIONS:
				SouvenirMenu(souvenirMap,souvenirList);
				break;

			/*************************************************************
			 * PROC - The user will be brought to an admin menu with admin
			 *        only options. They must have an admin password to
			 *        access this menu, otherwise they will be brought back
			 *        here.
			 *************************************************************/
			case	ADMIN_MENU:
				AdminMenu(stadiumsAlphabetical,
						  stadiumsTeamName,
						  stadiumsAFC,
						  stadiumsNFC,
						  stadiumsOpenRoof,
						  stadiumsRetractableRoof,
						  stadiumsDateOpened,
						  stadiumMap,
						  souvenirMap,
						  souvenirList,
						  stadiumGraph);
				break;
		}
	}while(userSelection != EXIT);

	cout << EXIT_MESSAGE;

	return 0;
}
