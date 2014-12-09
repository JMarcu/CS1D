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
 * FUNCTION BuySouvenir
 * -----------------------------------------------------------------------
 * This allows users to plan on buying souvenirs at stadiums.
 * -----------------------------------------------------------------------
 * PRE-CONDITIONS -
 * 	stadiumName  : The name of the stadium these purchases are made at.
 * 	souvenirList : A list of all the souvenirs in the program.
 * 	purchaseMap  : A map to populate with their purchases.
 *
 * POST-CONDITIONS -
 * 	Purchase map will store any purchases they elect to make.
 *************************************************************************/
void BuySouvenir(const string& stadiumName,
		         const List<Souvenir>& souvenirList,
		         Map<string, List<PurchaseOrder> >& purchaseMap)
{
	/*********************************************************************
	 * CONSTANTS
	 * -------------------------------------------------------------------
	 * USED FOR OUTPUT
	 * -------------------------------------------------------------------
	 * PURCHASE_PROMPT  : Prompts the user to pick a souvenir.
	 * SELECTION_PROMPT : Prompts the user to enter a selection.
	 * QUANTITY_PROMPT  : Prompts the user to enter how many they want
	 *                    to buy.
	 *********************************************************************/
	const string PURCHASE_PROMPT  = "Which souvenir would you like to "
			                        "purchase?\n";
	const string SELECTION_PROMPT = "Enter Selection: ";
	const string QUANTITY_PROMPT  = "Purchase Amount: ";

	//VARIABLE DECLERATIONS
	int souvNumber;       //PROC - The number of souvenirs there are.
	int purchaseSelection;//IN   - Which one the user wants to buy.
	int purchaseQuantity; //IN   - How many they want to buy.
	List<Souvenir>::Iterator souvIt;      //PROC - Iterates souvenir list.
	List<PurchaseOrder>*     purchasePtr; //PROC - Creates purchase order lists.
	List<PurchaseOrder>      purchaseList;//PROC - Stores purchase order lists.
	PurchaseOrder*           orderPtr;    //PROC - Creates purchase orders.

	//VARIABLE INITIALIZATIONS
	souvNumber = 1;

	/*********************************************************************
	 * OUT - Output the main prompt.
	 *********************************************************************/
	cout << left;
	cout << PURCHASE_PROMPT;

	/*********************************************************************
	 * OUT - Output souvenir options.
	 *********************************************************************/
	while(souvIt != souvenirList.End())
	{
		cout << souvNumber << ") "
		     << setw(20) << (souvIt->GetElem().GetName()) << "| "
		     << souvIt->GetElem().GetCost()
		     << endl;
		++souvNumber;
		++souvIt;
	}

	/*********************************************************************
	 * INPUT - Get which souvenir they want to buy.
	 *********************************************************************/
	purchaseSelection = ErrorCheckNum(souvNumber, 1, SELECTION_PROMPT);

	/*********************************************************************
	 * PROC - Get a reference to the souvenir.
	 *********************************************************************/
	souvIt  = souvenirList.Begin();
	for(int i = 0; i < purchaseSelection; ++i)
	{
		++souvIt;
	}

	/*********************************************************************
	 * INPUT - Get how many they want to buy.
	 *********************************************************************/
	purchaseQuantity = ErrorCheckNum(32000, 1, QUANTITY_PROMPT);

	/*********************************************************************
	 * PROC - If there are already purchase order at this stadium then
	 *        get a reference to its existing purchase order list.
	 *        Otherwise create a new list and add it to the purchase
	 *        orders map.
	 *********************************************************************/
	purchasePtr = &purchaseMap.Find(stadiumName)->ModValue();
	if(purchasePtr == NULL)
	{
		purchaseMap.Put(stadiumName, purchaseList);
		purchasePtr = &purchaseMap.Find(stadiumName)->ModValue();
	}

	/*********************************************************************
	 * PROC - Create the purchase order and add it to the list.
	 *********************************************************************/
	orderPtr = new PurchaseOrder(*souvIt, purchaseQuantity);
	purchasePtr->InsertBack(*orderPtr);

	cout << endl << endl;
}
