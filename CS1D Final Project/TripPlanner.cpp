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

enum	Trip_Menu_Options{
	RETURN_TO_MAIN,
	VISIT_ALL_STADIUMS,
	VISIT_ALL_AFC,
	VISIT_ALL_NFC,
	CUSTOM_TRIP
};

void TripPlannerMenu(const List<NFL_Stadium>& stadiumsAlphabetical,
		const List<NFL_Stadium>& stadiumsTeamName,
		const List<NFL_Stadium>& stadiumsAFC,
		const List<NFL_Stadium>& stadiumsNFC,
		const List<NFL_Stadium>& stadiumsOpenRoof,
		const List<NFL_Stadium>& stadiumsRetractableRoof,
		const List<NFL_Stadium>& stadiumsDateOpened,
		   const Map<string, NFL_Stadium>& stadiumMap,
		             const Graph<NFL_Stadium>&       stadiumGraph,
		             const List<Souvenir>& souvenirList)
{
	const string MENU = "Please select an option for your trip:\n"
			            "--------------------------------------\n"
			            "1) Visit all NFL stadiums.\n"
			            "2) Visit all AFC stadiums.\n"
			            "3) Visit all NFC stadiums.\n"
			            "4) Plan a custom trip.\n"
						"0) Return to Main Menu.\n"
			            "Enter Selection: ";
	const string STARTING_CITY = "Will your trip be starting in: \n"
			                     "1) San Francisco\n"
			                     "2) San Diego\n"
			                     "Enter Selection: ";

	/*********************************************************************
	 * VARIABLE DECLERATIONS
	 *********************************************************************/
	//IN - Stores the user's choice from the menu.
	Trip_Menu_Options userSelection;
	const NFL_Stadium* start;
	Stack<const NFL_Stadium*> tripRoute;
	List<NFL_Stadium> destinations;
	bool startSDO;
	Map<string, List<PurchaseOrder> > purchaseOrders(&StringHashOne, &StringHashTwo);
	/*********************************************************************
	 * PROC - The user's choices in this menu will be executed until they
	 *        indicate they wish to exit.
	 *********************************************************************/
	do
	{
		/*****************************************************************
		 * INPUT - The user is shown the menu and give their choice.
		 *****************************************************************/
		userSelection = Trip_Menu_Options(ErrorCheckNum(4,0, MENU));
		cout << endl;

		/*****************************************************************
		 * PROC - The user's choice is executed.
		 *****************************************************************/
		switch(userSelection)
		{
			case VISIT_ALL_STADIUMS:
				startSDO = (ErrorCheckNum(2, 1, STARTING_CITY) - 1);

				if(startSDO)
				{
					AllStadiumsSDO(tripRoute, destinations, stadiumMap);
				}
				else
				{
					AllStadiumsSFO(tripRoute, destinations, stadiumMap);
				}

				TripOutput(tripRoute, destinations, stadiumGraph, purchaseOrders);

				break;

			case VISIT_ALL_AFC:
				startSDO = (ErrorCheckNum(2, 1, STARTING_CITY) - 1);

				if(startSDO)
				{
					AFCStadiumsSDO(tripRoute, destinations, stadiumMap);
				}
				else
				{
					AFCStadiumsSFO(tripRoute, destinations, stadiumMap);
				}

				TripOutput(tripRoute, destinations, stadiumGraph, purchaseOrders);

				break;

			case VISIT_ALL_NFC:
				startSDO = (ErrorCheckNum(2, 1, STARTING_CITY) - 1);

				if(startSDO)
				{
					NFCStadiumsSDO(tripRoute, destinations, stadiumMap);
				}
				else
				{
					NFCStadiumsSFO(tripRoute, destinations, stadiumMap);
				}

				TripOutput(tripRoute, destinations, stadiumGraph, purchaseOrders);

				break;

			case CUSTOM_TRIP:
				destinations = Build_Custom_Trip(stadiumsAlphabetical,
							   stadiumsTeamName,
							   stadiumsAFC,
							   stadiumsNFC,
							   stadiumsOpenRoof,
							   stadiumsRetractableRoof,
							   stadiumsDateOpened,
							   stadiumMap,
							   souvenirList,
							   purchaseOrders);

				if(destinations.Size() > 0)
				{
					startSDO = (ErrorCheckNum(2, 1, STARTING_CITY)) - 1;

					if(startSDO)
					{
						start = &(stadiumMap.Find("Qualcomm Stadium")->GetValue());
					}
					else
					{
						start = &(stadiumMap.Find("Levi\'s Stadium")->GetValue());
					}

					tripRoute = CustomRoute(*start, destinations, stadiumGraph);

					TripOutput(tripRoute, destinations, stadiumGraph, purchaseOrders);
				}

				break;

			/*************************************************************
			 * PROC - No action is taken. The user will be returned to the
			 *        main menu.
			 *************************************************************/
			case RETURN_TO_MAIN:
				break;
		}

		if(userSelection != RETURN_TO_MAIN)
		{
			cout << "Press Enter to Return to Main Menu";
			cin.ignore(1000, '\n');
			cout << endl;
			userSelection = RETURN_TO_MAIN;
		}
	}while(userSelection != RETURN_TO_MAIN);
}
