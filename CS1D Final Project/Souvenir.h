/*************************************************************************
 * CS1D Final Project
 * -----------------------------------------------------------------------
 * AUTHORS     : James Marcu & Phillip Doyle
 * STUDENT IDs : 374443      & 911579
 * CLASS       : CS1D
 * SECTION     : TTh 3:30 PM
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

//Purchase orders for souvenirs.
class PurchaseOrder
{
public:
   /*******************************************
	* * * * CONSTRUCTORS AND DESTRUCTOR * * * *
	*******************************************/
	PurchaseOrder()
		{quantity = 0;}
	PurchaseOrder(const Souvenir& prodInit, int amount)
		{product = prodInit; quantity = amount;}

   /*******************************************
	* * * *          ACCESSORS          * * * *
	*******************************************/
	const Souvenir& GetSouvenir() const       //Returns a reference to the
		{return product;}                     //souvenir being bought.

	int GetQuantity() const                   //Returns the number being
		{return quantity;}                    //bought.

	float GetTotalSale() const                //Returns the total price
		{return product.GetCost() * quantity;}//of the purchase.

private:
	Souvenir product; //The souvenir being bought.
	int      quantity;//The number of them being bought.
};

#endif /* SOUVENIR_H_ */


