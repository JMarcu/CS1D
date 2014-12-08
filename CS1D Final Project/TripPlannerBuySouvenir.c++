/*************************************************************************
 * AUTHOR      : James Marcu
 * STUDENT ID  : 374443
 * ASS #      : 
 * CLASS       : CS1D
 * SECTION     : TTh 3:30 AM
 * DUE DATE    : 
 *************************************************************************/

#include "header.h"

void BuySouvenir(const string& stadiumName,
		         const List<Souvenir>& souvenirList,
		         Map<string, List<PurchaseOrder> >& purchaseMap)
{
	const string PURCHASE_PROMPT = "Which souvenir would you like to "
			                       "purchase?\n";
	const string SELECTION_PROMPT = "Enter Selection: ";
	const string QUANTITY_PROMPT  = "Purchase Amount: ";

	List<Souvenir>::Iterator souvIt;
	List<PurchaseOrder>      purchaseList;
	PurchaseOrder*           orderPtr;
	int souvNumber;
	int purchaseSelection;
	int purchaseQuantity;

	souvNumber = 1;

	cout << left;
	cout << PURCHASE_PROMPT;

	//FOR-LOOP: Cycles through list outputting each souvinier's name
	//			and price to the user
	souvIt  = souvenirList.Begin();
	while(souvIt != souvenirList.End())
	{
		cout << souvNumber << ") "
		     << setw(20) << (souvIt->GetElem().GetName()) << "| "
		     << souvIt->GetElem().GetCost()
		     << endl;
		++souvNumber;
		++souvIt;
	}
	purchaseSelection = ErrorCheckNum(souvNumber, 1, SELECTION_PROMPT);

	souvIt  = souvenirList.Begin();
	for(int i = 0; i < purchaseSelection; ++i)
	{
		++souvIt;
	}

	purchaseQuantity = ErrorCheckNum(32000, 1, QUANTITY_PROMPT);

	purchaseMap.Put(stadiumName, purchaseList);

	orderPtr = new PurchaseOrder(*souvIt, purchaseQuantity);

	purchaseMap.Find(stadiumName)->ModValue().InsertBack(*orderPtr);

	cout << endl << endl;
}
