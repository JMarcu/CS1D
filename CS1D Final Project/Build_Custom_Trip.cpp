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

enum	add_Type{
	FINISH,
	ALL_LIST,
	NFC_LIST,
	AFC_LIST,
	OPEN_LIST,
	RETRACT_LIST,
	SINGLE,
	REMOVE,
	LIST,
	PURCHASE_SOUVENIRS,
	CANCEL,
};

/*************************************************************************
 * FUNCTION Build_Custom_Trip
 * -----------------------------------------------------------------------
 * This function allows the user to create a list of stadiums they wish to
 * visit on their trip. It then calculates a route to visit these
 * stadiums and outputs the results to the console.
 * -----------------------------------------------------------------------
 * PRE-CONDITIONS -
 * 	stadiumName     : The list to store all stadiums, sorted by stadium name.
 * 	teamName        : The list to store all stadiums, sorted by team name.
 * 	afcTeams        : The list to store all stadiums in the AFC.
 * 	nfcTeams        : The list to store all stadiums in the NFC.
 * 	openRoofs       : The list to store all stadiums with open roofs.
 * 	retractableRoofs: The list to store all stadiums with retractable roofs.
 * 	openingDate     : The list to store all stadiums, sorted by opening date.
 * 	stadiumMap      : Map storing all stadiums.
 * 	stadiumGraph    : A graph with all stadiums as vertices.
 * 	souvenirList    : A list of all souvenir's available for purchase.
 *
 * POST-CONDITIONS -
 * 	A trip with all user specified stadiums will be output to the
 * 	console.
 *************************************************************************/
 List<NFL_Stadium> Build_Custom_Trip(const List<NFL_Stadium>& stadiumsAlphabetical,
		 	 	 	 	 	 	     const List<NFL_Stadium>& stadiumsTeamName,
		 	 	 	 	 	 	     const List<NFL_Stadium>& stadiumsAFC,
		 	 	 	 	 	 	     const List<NFL_Stadium>& stadiumsNFC,
		 	 	 	 	 	 	     const List<NFL_Stadium>& stadiumsOpenRoof,
		 	 	 	 	 	 	     const List<NFL_Stadium>& stadiumsRetractableRoof,
		 	 	 	 	 	 	     const List<NFL_Stadium>& stadiumsDateOpened,
		 	 	 	 	 	 	     const Map<string, NFL_Stadium>& stadiumMap,
		 	 	 	 	 	 	     const Graph<NFL_Stadium>&       stadiumGraph,
		 	 	 	 	 	 	     const List<Souvenir>&           souvenirList)
{
	/*********************************************************************
	 * CONSTANTS
	 * -------------------------------------------------------------------
	 * USED FOR OUTPUT
	 * -------------------------------------------------------------------
	 * MENU      : The menu for the trip planner.
	 * STARTING_CITY : Used to prompt for which california stadium
	 *                 the should start in.
	 *********************************************************************/
	string  MENU =  		 	 "Which Stadiums would you like to add to "
			                     "your trip?\n"
					 	 	 	 "----------------------------------------"
			                     "----------\n"
								 "0)  Finish Planning Trip\n"
								 "1)  All Stadiums\n"
								 "2)  All Stadiums with an NFC Team\n"
								 "3)  All Stadiums with an AFC Team\n"
					 	 	 	 "4)  All Stadiums with Open Roofs\n"
								 "5)  All Stadiums with Retractable Roofs\n"
								 "6)  Add a Single Stadium\n"
								 "7)  Remove a Stadium from the Trip\n"
								 "8)  List Stadiums Currently in the Trip\n"
								 "9)  Purchase Souvenirs During the Trip\n"
								 "10) Cancel Trip\n"
					 	 		 "Enter Selection: ";
	const string STARTING_CITY = "Will your trip be starting in: \n"
								 "1) San Francisco\n"
								 "2) San Diego\n"
			                     "3) Oakland\n"
								 "Enter Selection: ";

	add_Type stadiums_to_add;     //IN   - Stores the user's menu choice.
	List<NFL_Stadium> trip_list;  //IN   - Stores which stadiums to visit.
	NFL_Stadium newStadium;       //PROC - stores a new stadium to add.
	NFL_Stadium stadium_to_remove;//PROC - Stores a stadium to remove.
	string single_stadium;		  //IN   - Stores the name of a stadium.
	bool cont;                    //PROC - LCV for loops.
	bool buySouvenir;             //IN   - If the user wants to buy a souvenir.
	int startInCity;              //IN   - The city to start the trip in.
	const NFL_Stadium* start;     //PROC - Points to the stadium to start at.
	Stack<const NFL_Stadium*> tripRoute;//PROC - The route for the trip.
	//PROC - A map for storing souvnir purchases.
	Map<string, List<PurchaseOrder> > purchaseOrders(&StringHashOne, &StringHashTwo);

	do//WHILE (stadiums_to_add != CANCEL)
	{
	/*****************************************************************
	 * INPUT - Displays the menu to the user and reads in their
	 *         choice of action.
	 *****************************************************************/
	 stadiums_to_add = add_Type(ErrorCheckNum(10,0, MENU));
	 cout << endl;

	/*****************************************************************
	 * PROC - Based on the user's input the appropriate action will be
	 *        taken.
	 *****************************************************************/
	 switch(stadiums_to_add)
	 {
	   /*************************************************************
	    * PROC - Finish the input section.
	    *************************************************************/
		case FINISH:
			break;

	   /*************************************************************
		* PROC - Cancel planning a trip altogether.
		*************************************************************/
		case CANCEL:

			while(!trip_list.Empty())
			{
				trip_list.Erase(trip_list.Front());
			}

			break;

	   /*************************************************************
	    * PROC - Adds all Stadiums to the list
	    *************************************************************/
		case ALL_LIST:
			Combine_StadiumLists(stadiumsTeamName, trip_list);
			break;

		/*************************************************************
		 * PROC - Adds the specified Stadium list to the list
		 *************************************************************/
		case NFC_LIST:
			Combine_StadiumLists(stadiumsNFC, trip_list);
			break;

		case AFC_LIST:
			Combine_StadiumLists(stadiumsAFC, trip_list);
			break;

		case OPEN_LIST:
			Combine_StadiumLists(stadiumsOpenRoof, trip_list);
			break;

		case RETRACT_LIST:
			Combine_StadiumLists(stadiumsRetractableRoof, trip_list);
			break;

		/*************************************************************
		 * PROC - Adds the specified stadium  to the list
		 *************************************************************/
		case SINGLE:
			cont = true;
			do//WHILE (cont)
			{
			   /*********************************************************
				* INPUT - Get the stadium's name.
				*********************************************************/
				cout << "Enter a single stadium to add "
					 << "(\"EXIT\" to go back): ";
				getline(cin, single_stadium);

			   /*********************************************************
				* INPUT - If they typed EXIT then stop. Otherwise add
				*         the stadium to the trip_list if possible.
				*********************************************************/
				if(single_stadium == "EXIT")
				{
					cont = false;
				}
				else if(stadiumMap.Find(single_stadium) != NULL)
				{
				   /*****************************************************
					* PROC - Get a reference to the stadium object. If
					*        the stadium can't be found prompt the user
					*        for a different stadium name. If the stadium
					*        is already part of the trip let them know.
					*****************************************************/
					newStadium =  stadiumMap.Find(single_stadium)->GetValue();
					if(trip_list.Search(newStadium) == trip_list.End())
					{
					   /**************************************************
						* PROC - Add the stadium to the list.
						**************************************************/
						trip_list.InsertBack(newStadium);
						cout << single_stadium << " Added\n\n";

					   /**************************************************
						* INPUT & PROC - If the user wants to buy souvenirs
						*                at the stadium, let them.
						**************************************************/
						cout << "Would you like to buy a souvenir from "
							 << "this stadium? (y/n)\n";
						cout << "Enter Selection: ";
						buySouvenir = GetInput("", 'y', 'n', cout, cin) == 'Y';
						if(buySouvenir)
						{
							BuySouvenir(single_stadium, souvenirList, purchaseOrders);
						}

					   /**************************************************
						* INPUT - Ask if they want to add another stadium.
						**************************************************/
						cout << "Would you like to enter another stadium? (y/n)\n";
						cout << "Enter Selection: ";
						cont = GetInput("", 'y', 'n', cout, cin) == 'Y';
					}
					else
					{
						cout << single_stadium
							 << "is already part of the trip.\n";

					   /**************************************************
						* INPUT - Ask if they want to add another stadium.
						**************************************************/
						cout << "Would you like to enter another stadium? "
								"(y/n)\n";
						cout << "Enter Selection: ";
						cont = GetInput("", 'y', 'n', cout, cin) == 'Y';
					}
				}
				else
				{
					cout << "Sorry, \"" << single_stadium
						 <<"\"stadium could not be found.\n";
				}
				cout << endl;

			}while(cont);

			break;

	   /******************************************************************
		* PROC - Removes the specified stadium from the list
		******************************************************************/
		case REMOVE:
			cont = true;
			do//WHILE (cont)
			{
			   /*********************************************************
				* INPUT - Get the stadium's name.
				*********************************************************/
				cout << "Enter a Stadium to Remove (\"EXIT\" to go back): ";
				getline(cin, single_stadium);

				/*********************************************************
				 * PROC - If the user opted to exit then quit.
				 *********************************************************/
				if(single_stadium == "EXIT")
				{
					cont = false;
				}
				else if(stadiumMap.Find(single_stadium) != NULL)
				{
					/*****************************************************
					 * PROC - Get a reference to the stadium. If none can
					 *        be found then let them know.
					 *****************************************************/
					stadium_to_remove =  stadiumMap.Find(single_stadium)->GetValue();
					if(trip_list.Search(stadium_to_remove) != trip_list.End())
					{
						/*************************************************
						 * PROC - Remove the stadium from the list.
						 *************************************************/
						trip_list.Erase(trip_list.Search(stadium_to_remove));
						cout << single_stadium << " Removed\n\n";

						/*************************************************
						 * INPUT - Ask if they want to remove another
						 *         stadium.
						 *************************************************/
						cout << "Would you like to remove another stadium? "
								"(y/n)\n";
						cout << "Enter Selection: ";
						cont = GetInput("", 'y', 'n', cout, cin) == 'Y';
					}
					else
					{
						cout << single_stadium
							 << " is not a part of your trip.\n";

						/*************************************************
						 * INPUT - Ask if they want to remove another
						 *         stadium.
						 *************************************************/
						cout << "Would you like to remove another stadium? "
								"(y/n)\n";
						cout << "Enter Selection: ";
						cont = GetInput("", 'y', 'n', cout, cin) == 'Y';
					}
				}
				else
				{
					cout << "\nThat stadium could not be found.\n";
				}

				cout << endl;
			}while(cont);

			break;

	   /******************************************************************
		* PROC - Purchase souvenirs from a stadium in your trip.
		******************************************************************/
		case PURCHASE_SOUVENIRS:
			cont = true;
			do
		{
			   /**********************************************************
				* INPUT - Get the name of the stadium.
				**********************************************************/
				cout << "Enter the stadium to purchase at (\"EXIT\" to go back): ";
				getline(cin, single_stadium);

			   /**********************************************************
				* PROC - If they opted to quit, then go back to the menu.
				* 		 Otherwise, get a reference to the stadium. If
				* 		 none can be found then let the user know that.
				* 		 If the stadium is not on their trip, let them know
				* 		 that.
				**********************************************************/
				if(single_stadium == "EXIT")
				{
					cont = false;
				}
				else if(stadiumMap.Find(single_stadium) == NULL)
				{
					cout << "\"" << single_stadium
						 << "\" could not be found.\n";
				}
				else if(trip_list.Search(stadiumMap.Find(single_stadium)->GetValue()) == trip_list.End())
				{
					cout << single_stadium << " is not part of your trip."
							"\n\n";
					cout << "Would you like to add it? (y/n)\n";

					if(GetInput("Enter Selection: ", 'y', 'n', cout, cin) == 'Y')
					{
						trip_list.InsertBack(stadiumMap.Find(single_stadium)->GetValue());
						cout << single_stadium << " Added\n\n";

						BuySouvenir(single_stadium, souvenirList, purchaseOrders);
					}
					else
					{
						cout << "Returning you to trip planning menu...\n";
						cont = false;
					}
				}
				else
				{
					BuySouvenir(single_stadium, souvenirList, purchaseOrders);
					cont = false;
				}
				cout << endl;
			}while(cont);

			break;

	   /*************************************************************
		* PROC - Lists stadiums currently scheduled for the trip
		*************************************************************/
		case LIST:
			if(!trip_list.Empty())
			{
				PrintList(trip_list);
			}
			else
			{
				cout << "No stadiums have been added to your trip yet.\n\n";
			}

			break;
	 	}//END switch(stadiumsToAdd)

	}while(stadiums_to_add != CANCEL && stadiums_to_add != FINISH);

   /**********************************************************************
	* PROC - If there are stadiums in the trip list then plan the trip.
	**********************************************************************/
	if(trip_list.Size() > 0)
	{
	   /******************************************************************
		* INPUT - Get the starting city.
		******************************************************************/
		startInCity = (ErrorCheckNum(3, 1, STARTING_CITY));

	   /******************************************************************
		* PROC - Create a reference to the starting city.
		******************************************************************/
		if(startInCity == 1)
		{
			start = &(stadiumMap.Find("Qualcomm Stadium")->GetValue());
		}
		else if(startInCity == 2)
		{
			start = &(stadiumMap.Find("Levi\'s Stadium")->GetValue());
		}
		else
		{
			start = &(stadiumMap.Find("O.co Coliseum")->GetValue());
		}

	   /******************************************************************
		* PROC - Generate the route the trip will take.
		******************************************************************/
		tripRoute = CustomRoute(*start, trip_list, stadiumGraph);

	   /******************************************************************
		* OUT - Output the results to the console.
		******************************************************************/
		TripOutput(tripRoute, trip_list, stadiumGraph, purchaseOrders);
	}

	return trip_list;
}
