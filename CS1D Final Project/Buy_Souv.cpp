/*************************************************************************
 * CS1D Final Project
 * -----------------------------------------------------------------------
 * AUTHORS     : James Marcu & Phillip Doyle
 * STUDENT IDs : 374443      & 911579
 * CLASS       : CS1D
 * SECTION     : TTh 3:30 PM
 * DUE DATE    : 12/9/2014
 *************************************************************************/
//
//#include "header.h"
//
//enum buy_action{
//	DONE,
//	BUY,
//	LIST_SOUV,
//	LIST_STAD
//};
//
//
///*************************************************************************
// * FUNCTION Buy_Souv
// * -----------------------------------------------------------------------
// * This function allows the user to buy souvinirs on their trip
// * -----------------------------------------------------------------------
// * PRE-CONDITIONS -
// * 	visit_Locations : A list of all the stadiums that will be visited.
// *
// * POST-CONDITIONS -
// * 	Will return a list of all stadiums a user wants to visit
// *************************************************************************/
//void	Buy_Souv(List<NFL_Stadium>      visit_Locations,
//				 Map<string, Souvenir>& souvenirMap,
//				 List<Souvenir>&        souvenirList)
//{
//	string		item_to_buy;		//stores name of item to buy;
//	int			num_buy;			//stores number of items to buy;
//	float		total = 0;				//stores total cost of all souv
//	int			num_items_bought = 0;	//stores number of types of item bought
//
//	//Arrays Storing output values
//	string item_bought[souvenirMap.Size()];
//	int	   numbought[souvenirMap.Size()];
//	int	index;	//index for arrays
//
//	string	menu = "Souvenir Menu:\n"
//				   "-------------------\n"
//				   "1) Buy an Item\n"
//			       "2) List All Souvenirs\n"
//			       "3) List Stadiums Visiting\n"
//			       "0) Done\n"
//			       "Enter Selection: ";
//	buy_action selection;	//stores user selection
//
//	List<Souvenir>::Iterator	souvIt = souvenirList.Begin();
//
//
//	cout << "\n Stadiums Being Visited: \n";
//	PrintList(visit_Locations);
//
//
//	cout << left;
//	cout << setw(20) << "Souvenir" << '|' << " Price" << endl;
//	cout << setfill('-') << setw(20) << '-' << '|' << setw(8) << '-' << endl;
//	cout << setfill(' ');
//
//	//FOR-LOOP: Cycles through list outputting each souvinier's name
//	//			and price to the user also initalizes the array
//	//			stronig items bought
//	for(int count = 0; count < souvenirList.Size(); count++)
//	{
//		cout << setw(20) << souvIt->GetElem().GetName() << "| " ;
//		cout << souvIt->GetElem().GetCost();
//		cout << endl;
//		souvIt++;
//		item_bought[count].clear();
//		item_bought[count] = " ";
//		numbought[count] = 0;
//	}
//
//
//	do
//	{
//		/*****************************************************************
//		 * INPUT - Displays the menu to the user and reads in their
//		 *         choice of action.
//		 *****************************************************************/
//		selection = buy_action(ErrorCheckNum(3,0, menu));
//
//		/*****************************************************************
//		 * PROC - Based on the user's input the appropriate action will be
//		 *        taken.
//		 *****************************************************************/
//		switch(selection)
//		{
//
//		/*****************************************************************
//		 * PROC - Displays items purchased
//		 *****************************************************************/
//		case DONE:
//			cout << "\nItems Bought : \n";
//			cout << left;
//			cout << setw(20) << "Souvenir" << '|' << " # Bought" << endl;
//			cout << setfill('-') << setw(20) << '-' << '|' << setw(8) << '-' << endl;
//			cout << setfill(' ');
//
//			index = 0;
//			while(item_bought[index] != " " && index <souvenirMap.Size())
//			{
//				cout << setw(20) << item_bought[index]<< "| " ;
//				cout << showpoint << fixed << setprecision(2) << numbought[index] << endl;
//				index++;
//			}
//
//			cout << "Total Price: " << total << endl <<endl;
//
//			break;
//
//		/*****************************************************************
//		 * PROC - Allows user to buy an item at a stadium. It checks if
//		 * the user has already bought that item, and if so increases
//		 * the total, otherwise it adds it to the array
//		 *****************************************************************/
//		case BUY:
//
//			do{
//				cout << "What Stadium Would you like to buy a souvinier at( Enter \"done\" to exit) : ";
//				getline(cin,item_to_buy);
//
//				//IF-STATEMNET: Checks if user wishes to cancel purchase
//				if (item_to_buy != "done")
//				{
//					cout << "What Item Would you like to buy ( Enter \"done\" to exit) : ";
//					getline(cin,item_to_buy);
//
//					//IF-STATEMNET: Checks if user wishes to cancel purchase or if the item
//					//				does not exist
//					if (item_to_buy != "done" && souvenirMap.Find(item_to_buy) != NULL)
//					{
//						cout << souvenirMap.Find(item_to_buy)->GetValue().Print() << endl << endl;
//						num_buy = ErrorCheckNum(9999,0, "Enter amount you wish to purchase (Enter -1 to cancel) : ");
//						//IF-STATEMNET: Checks if user wishes to cancel purchase
//						if(num_buy != -1)
//						{
//							total += num_buy * souvenirMap.Find(item_to_buy)->GetValue().GetCost();
//
//							index = 0;
//							bool found = false;
//							/*****************************************************************
//							 * PROC - Cycles through the loop until the item being bought is
//							 * found or the last item in the array is reached
//							 *****************************************************************/
//							while(!found && index <souvenirMap.Size())
//							{
//								if(item_to_buy == item_bought[index])
//								{
//									found = true;
//								}
//								else if(item_bought[index] == " ")
//								{
//									found = true;
//								}
//								else
//								{
//									index++;
//								}
//							}
//
//							item_bought[index] = item_to_buy;
//							numbought[index] += num_buy;
//						}
//						item_to_buy.clear();
//					}
//
////					if(souvenirMap.Find(item_to_buy) == NULL)
////					{
////						cout << "\nThat item could not be found.\n\n";
////						item_to_buy.clear();
////					}
//
//				}
//			}while(item_to_buy != "done");
//			break;
//
//
//		case LIST_SOUV:
//
//			souvIt = souvenirList.Begin();
//
//			cout << left;
//			cout << setw(20) << "Souvenir" << '|' << " Price" << endl;
//			cout << setfill('-') << setw(20) << '-' << '|' << setw(8) << '-' << endl;
//			cout << setfill(' ');
//
//			//FOR-LOOP: Cycles through list outputting each souvinier's name
//			//			and price to the user
//			for(int count = 0; count < souvenirList.Size(); count++)
//			{
//				cout << setw(20) << souvIt->GetElem().GetName() << "| " ;
//				cout << souvIt->GetElem().GetCost();
//				cout << endl;
//				souvIt++;
//			}
//			break;
//
//		case LIST_STAD:
//			PrintList(visit_Locations);
//			break;
//		}
//
//	}while(selection != DONE);
//
//}
