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

void TripOutput(Stack<const NFL_Stadium*>&      route,
		        List<NFL_Stadium>&  destinations,
		        const Graph<NFL_Stadium>& stadiumGraph,
		        const Map<string, List<PurchaseOrder> >& purchaseOrders)
{
	const int SOUVENIR_WIDTH = 15;
	const int QUANTITY_WIDTH = 3;

	float        totalDistance;
	float        distance;
	const NFL_Stadium* lastStadium;
	typename List<NFL_Stadium>::Iterator destIt;
	typename List<PurchaseOrder>::Iterator purchaseIt;
	const List<PurchaseOrder>* purchaseList;
	bool enroute;
	float totalCost;
	float finalCost;

	totalDistance = 0;
	enroute       = false;
	finalCost     = 0;

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

	while(!route.Empty())
	{
		if(!enroute)
		{
			cout << "To get to the next stadium: " << endl;
		}

		destIt  = destinations.Search(*route.Peek());
		enroute = destIt == destinations.End();

		distance = stadiumGraph.GetDistance(*lastStadium, *route.Peek());
		cout << "Travel " << distance << " miles to "
			 << route.Peek()->get_location() << "."
			 << endl;

		totalDistance += distance;

		if(!enroute)
		{
			cout << endl;
			cout << "You have arrived at "
				 << route.Peek()->get_stadium_name()
				 << "!" << endl;

			destinations.Erase((*destIt));

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

	cout << "The final city in your trip has been reached.\n";
	cout << "Total Distance Travelled: " << totalDistance << " miles\n";
	cout << "Total Money Spent on Souvenirs: $" << finalCost << endl << endl;
	cout << right;
}



