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
 * visit on their trip
 * -----------------------------------------------------------------------
 * PRE-CONDITIONS -
 * 	<none>
 *
 * POST-CONDITIONS -
 * 	Will return a list of all stadiums a user wants to visit
 *************************************************************************/
 List<NFL_Stadium> Build_Custom_Trip(const List<NFL_Stadium>& stadiumsAlphabetical,
		 const List<NFL_Stadium>& stadiumsTeamName,
		 const List<NFL_Stadium>& stadiumsAFC,
		 const List<NFL_Stadium>& stadiumsNFC,
		 const List<NFL_Stadium>& stadiumsOpenRoof,
		 const List<NFL_Stadium>& stadiumsRetractableRoof,
		 const List<NFL_Stadium>& stadiumsDateOpened,
		 const Map<string, NFL_Stadium>& stadiumMap,
		 const List<Souvenir>& souvenirList,
		 Map<string, List<PurchaseOrder> >& purchaseOrders)
{
	add_Type	stadiums_to_add;		//Stores Option user wishes to
									// Add/remove or list
	List<NFL_Stadium> trip_list;		//stores List of locations user wishes to visit
	NFL_Stadium newStadium;
	NFL_Stadium stadium_to_remove;
	string		single_stadium;			//Stores name of single stadium to add
	bool cont;
	bool buySouvenir;

	//Stores menu for user to select how to add/remove a stadium
	string  add_menu =  "Which Stadiums would you like to add to your trip?\n"
					 "--------------------------------------------------\n"
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

	do//WHILE (stadiums_to_add != CANCEL)
	{
	/*****************************************************************
	 * INPUT - Displays the menu to the user and reads in their
	 *         choice of action.
	 *****************************************************************/
	 stadiums_to_add = add_Type(ErrorCheckNum(10,0, add_menu));
	 cout << endl;


	/*****************************************************************
	 * PROC - Based on the user's input the appropriate action will be
	 *        taken.
	 *****************************************************************/
	 switch(stadiums_to_add)
	 {
		case FINISH:
			break;

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
			 * PROC - Adds the specified Stadium  to the list
			 *************************************************************/
		case SINGLE:
			cont = true;
			do//WHILE (cont)
			{
				cout << "Enter a single stadium to add (\"EXIT\" to go back): ";
				getline(cin, single_stadium);

				if(single_stadium == "EXIT")
				{
					cont = false;
				}
				else if(stadiumMap.Find(single_stadium) != NULL)
				{
					newStadium =  stadiumMap.Find(single_stadium)->GetValue();
					if(trip_list.Search(newStadium) == trip_list.End())
					{
						trip_list.InsertBack(newStadium);
						cout << single_stadium << " Added\n\n";

						cout << "Would you like to buy a souvenir from this stadium? (y/n)\n";
						cout << "Enter Selection: ";
						buySouvenir = GetInput("", 'y', 'n', cout, cin) == 'Y';
						if(buySouvenir)
						{
							BuySouvenir(single_stadium, souvenirList, purchaseOrders);
						}

						cout << "\nWould you like to enter another stadium? (y/n)\n";
						cout << "Enter Selection: ";
						cont = GetInput("", 'y', 'n', cout, cin) == 'Y';
					}
					else
					{
						cout << single_stadium
							 << "is already part of the trip.\n";
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

	   /*************************************************************
		* PROC - Removes the specified Stadium from the list
		*************************************************************/
		case REMOVE:
			cont = true;
			do//WHILE (cont)
			{
				cout << "Enter a Stadium to Remove (\"EXIT\" to go back): ";
				getline(cin, single_stadium);

				/*************************************************************
				 * PROC - Checks if Stadium USer specifies exists and
				 *  is in the list.
				 *************************************************************/
				if(single_stadium == "EXIT")
				{
					cont = false;
				}
				else if(stadiumMap.Find(single_stadium) != NULL)
				{
					stadium_to_remove =  stadiumMap.Find(single_stadium)->GetValue();
					if(trip_list.Search(stadium_to_remove) != trip_list.End())
					{
						trip_list.Erase(trip_list.Search(stadium_to_remove));
						cout << single_stadium << " Removed\n\n";

						cout << "Would you like to remove another stadium? (y/n)\n";
						cout << "Enter Selection: ";
						cont = GetInput("", 'y', 'n', cout, cin) == 'Y';
					}
					else
					{
						cout << single_stadium
							 << " is not a part of your trip.\n";
					}
				}
				else
				{
					cout << "\nThat stadium could not be found.\n";
				}

				cout << endl;
			}while(cont);

			break;

		case PURCHASE_SOUVENIRS:
			cont = true;
			do
			{
				cout << "Enter the stadium to purchase at (\"EXIT\" to go back): ";
				getline(cin, single_stadium);

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
					cout << single_stadium << " is not part of your trip.\n\n";
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
		* PROC - Lists stadiums currently in the list
		*************************************************************/
		case LIST:
			PrintList(trip_list);
			break;
	 	}//END switch(stadiumsToAdd)

	}while(stadiums_to_add != CANCEL && stadiums_to_add != FINISH);

	return trip_list;
}
