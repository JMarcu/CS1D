/*************************************************************************
 * CS1D Final Project
 * -----------------------------------------------------------------------
 * AUTHORS     : James Marcu & Phillip Doyle
 * STUDENT IDs : 374443      & 911579
 * CLASS       : CS1D
 * SECTION     : TTh 3:30 AM
 * DUE DATE    : 12/9/2014
 *************************************************************************/
#ifndef SOUVENIR_H_
#define SOUVENIR_H_

#include<string>
using namespace std;

//Models a souvenir for sale at an NFL stadium.
class Souvenir
{
	public:
	   /*******************************************
	    * * * * CONSTRUCTORS AND DESTRUCTOR * * * *
	    *******************************************/
		//Default Constructor
		Souvenir();

		//Non-Default Constructor
		Souvenir(string name, float cost);

		//Destructor
		~Souvenir(); //Destructor

	   /*******************************************
		* * * *          ACCESSORS          * * * *
		*******************************************/
		//Returns the souvenir's name.
		string GetName() const;

		//Returns the souvenir's cost.
		float  GetCost() const;

		//Returns a string of the souvenir's data for output to the console.
		string Print()   const;

		//Returns a string of the souvenir's data for output to a text file,
		//used to save the souvenir between sessions.
		string Save()    const;


		bool operator!=(const Souvenir& compareTo) const;

	   /*******************************************
		* * * *          MUTATORS           * * * *
		*******************************************/
		//Sets the souvenir's name.
		void  SetName(string name);

		//Sets the souvenir's cost.
		void  SetCost(float cost);

	private:
		string itemName;//The souvenir's name.
		float  price;   //The souvenir's cost.
};

class PurchaseOrder
{
public:
	PurchaseOrder()
		{quantity = 0;}
	PurchaseOrder(const Souvenir& prodInit, int amount)
		{product = prodInit; quantity = amount;}

	const Souvenir& GetSouvenir() const
		{return product;}

	int GetQuantity() const
		{return quantity;}

	float GetTotalSale() const
		{return product.GetCost() * quantity;}

private:
	Souvenir product;
	int      quantity;
};

#endif /* SOUVENIR_H_ */


