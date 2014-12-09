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
 * FUNCTION TripOutput
 * -----------------------------------------------------------------------
 * Outputs a trip to the console.
 * -----------------------------------------------------------------------
 * PRE-CONDITIONS -
 * 	route          : The order in which to visit stadiums.
 * 	destinations   : Which stadiums are destinations for the user.
 * 	purchaseOrders : Which purchases the user wants to make.
 *
 * POST-CONDITIONS -
 * 	Will construct and add a new node to the tree.
 *************************************************************************/
void TripOutput(Stack<const NFL_Stadium*>& route,
		        List<NFL_Stadium>&         destinations,
		        const Graph<NFL_Stadium>&  stadiumGraph,
		        const Map<string, List<PurchaseOrder> >& purchaseOrders)
{
	/*********************************************************************
	 * CONSTANTS
	 * -------------------------------------------------------------------
	 * USED FOR FORMATTING
	 * -------------------------------------------------------------------
	 * SOUVENIR_WIDTH : Width of the output column.
	 *********************************************************************/
	const int SOUVENIR_WIDTH = 15;

	//VARIABLE DECLERATIONS
	float totalDistance;//PROC - Total distance travelled during trip.
	float distance;     //PROC - Distance to get to the current stadium.
	bool  enroute;      //PROC - True if the current stadium is a destination
	float totalCost;    //PROC - Cost of all souvenirs at one stadium.
	float finalCost;    //PROC - Cost of all souvenirs on the trip.
	const NFL_Stadium*         lastStadium; //PROC - The previous stadium.
	const List<PurchaseOrder>* purchaseList;//PROC - List of souvenir purchases.
	typename List<NFL_Stadium>::Iterator   destIt;    //PROC - Iterates the
	                                                  //       destinations.
	typename List<PurchaseOrder>::Iterator purchaseIt;//PROC - Iterates the
                                                      //       purchases.

	//VARIABLE INITIALIZATIONS
	totalDistance = 0;
	enroute       = false;
	finalCost     = 0;

	/*********************************************************************
	 * OUT - Output a header.
	 *********************************************************************/
	cout << left;
	cout << endl;
	cout << setw(OUTPUT_MARGIN) << "Travel Itinerary" << endl;
	cout << setfill('-')
		 << setw(OUTPUT_MARGIN) << "-" << endl
		 << setfill(' ');

	cout << "Start in " << route.Peek()->get_location() << "."
		 << endl << endl;
	lastStadium = route.Peek();
	route.Pop();

	/*********************************************************************
	 * PROC - Do this for every stadium on the trip.
	 *********************************************************************/
	while(!route.Empty())
	{
		/*****************************************************************
		 * OUT - Output this if the user just got to a destination.
		 *****************************************************************/
		if(!enroute)
		{
			cout << "To get to the next stadium: " << endl;
		}

		/*****************************************************************
		 * PROC - Figure if the current stadium is a destination and the
		 *        distance it is from the last stadium.
		 *****************************************************************/
		destIt  = destinations.Search(*route.Peek());
		enroute = destIt == destinations.End();
		distance = stadiumGraph.GetDistance(*lastStadium, *route.Peek());

		/*****************************************************************
		 * OUT - Output how to get to the current stadium from the last
		 *       one.
		 *****************************************************************/
		cout << "Travel " << distance << " miles to "
			 << route.Peek()->get_location() << "."
			 << endl;

		totalDistance += distance;

		/*****************************************************************
		 * PROC - If they have just gotten to a destination.
		 *****************************************************************/
		if(!enroute)
		{
			//Output the stadium they arrived at.
			cout << endl;
			cout << "You have arrived at "
				 << route.Peek()->get_stadium_name()
				 << "!" << endl;

			//Remove it from destinations.
			destinations.Erase((*destIt));

			//Find out if they are purhcasing souvenirs there, and output
			//the order if they are.
			if(purchaseOrders.Find(route.Peek()->get_stadium_name()) != NULL)
			{
				totalCost = 0;

				cout << "You plan on purchasing: \n";

				purchaseList = &purchaseOrders.Find(route.Peek()->get_stadium_name())->GetValue();
				purchaseIt = purchaseList->Begin();
				while(purchaseIt != purchaseList->End())
				{
					cout << "     " << (*purchaseIt).GetQuantity() << "x ";
					cout << setw(SOUVENIR_WIDTH)
						 << (*purchaseIt).GetSouvenir().GetName();
					cout << "Sub Total: $" << (*purchaseIt).GetTotalSale();
					cout << endl;

					totalCost += (*purchaseIt).GetTotalSale();
					finalCost += totalCost;
					++purchaseIt;
				}
				cout << "     TOTAL: $" << totalCost << endl;
			}
			cout << endl;
		}

		lastStadium = route.Peek();
		route.Pop();
	}

	/*********************************************************************
	 * OUT - Output the final data about the trip.
	 *********************************************************************/
	cout << "The final city in your trip has been reached.\n";
	cout << "Total Distance Travelled: " << totalDistance << " miles\n";
	cout << "Total Money Spent on Souvenirs: $" << finalCost << endl << endl;
	cout << right;
}
