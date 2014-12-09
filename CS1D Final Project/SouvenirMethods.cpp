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
 * FUNCTION Constructor
 * -----------------------------------------------------------------------
 * Constructs an instance of Souvenir with default values.
 * -----------------------------------------------------------------------
 * PRECONDITIONS -
 * 	<none>
 *
 * POSTCONDITIONS -
 * 	Constructs an instance of Souvenir with default values.
 *************************************************************************/
Souvenir::Souvenir()
{
	price = 0;
}

/*************************************************************************
 * FUNCTION Constructor
 * -----------------------------------------------------------------------
 * Constructs an instance of Souvenir with the provided values.
 * -----------------------------------------------------------------------
 * PRECONDITIONS -
 * 	name : The souvenir's name.
 * 	cost : The souvenir's cost.
 *
 * POSTCONDITIONS -
 * 	Constructs an instance of Souvenir with the provided values.
 *************************************************************************/
Souvenir::Souvenir(string name, float cost)
{
	itemName = name;
	price    = cost;
}

/*************************************************************************
 * FUNCTION Destructor
 * -----------------------------------------------------------------------
 * Destroys and instance of Souvenir.
 * -----------------------------------------------------------------------
 * PRECONDITIONS -
 * 	<none>
 *
 * POSTCONDITIONS -
 * 	Destroys and instance of Souvenir.
 *************************************************************************/
Souvenir::~Souvenir()
{

}

/*************************************************************************
 * FUNCTION GetName
 * -----------------------------------------------------------------------
 * Returns the name of the item.
 * -----------------------------------------------------------------------
 * PRECONDITIONS -
 * 	<none>
 *
 * POSTCONDITIONS -
 * 	Returns the name of the item.
 *************************************************************************/
string Souvenir::GetName() const
{
	return itemName;
}

/*************************************************************************
 * FUNCTION GetCost
 * -----------------------------------------------------------------------
 * Returns the price of the item.
 * -----------------------------------------------------------------------
 * PRECONDITIONS -
 * 	<none>
 *
 * POSTCONDITIONS -
 * 	Returns the price of the item.
 *************************************************************************/
float Souvenir::GetCost() const
{
	return price;
}

/*************************************************************************
 * FUNCTION Print
 * -----------------------------------------------------------------------
 * Returns a string with the item's details which has been formatted
 * for output to the console.
 * -----------------------------------------------------------------------
 * PRECONDITIONS -
 * 	<none>
 *
 * POSTCONDITIONS -
 * 	Returns a string with the item's details which has been formatted
 *  for output to the console.
 *************************************************************************/
string Souvenir::Print() const
{
	ostringstream out;
	out << "\nItem Name : " << itemName;
	out << "\nCost      : $" << showpoint << fixed << setprecision(2) << price;
	return out.str();
}

/*************************************************************************
 * FUNCTION Save
 * -----------------------------------------------------------------------
 * Returns a string with the item's details which has been formatted
 * for saving in a text file.
 * -----------------------------------------------------------------------
 * PRECONDITIONS -
 * 	<none>
 *
 * POSTCONDITIONS -
 * 	Returns a string with the item's details which has been formatted
 *  for saving in a text file.
 *************************************************************************/
string Souvenir::Save() const
{
	ostringstream out;
	out << itemName;
	out << "\n$" << showpoint << fixed << setprecision(2) << price;
	return out.str();
}

/*************************************************************************
 * FUNCTION SetName
 * -----------------------------------------------------------------------
 * Sets the souvenir's name.
 * -----------------------------------------------------------------------
 * PRECONDITIONS -
 * 	name : The souvenir's name.
 *
 * POSTCONDITIONS -
 * 	Sets the souvenir's name field to name.
 *************************************************************************/
void Souvenir::SetName(string name)
{
	itemName = name;
}

/*************************************************************************
 * FUNCTION SetCost
 * -----------------------------------------------------------------------
 * Sets the souvenir's cost.
 * -----------------------------------------------------------------------
 * PRECONDITIONS -
 * 	cost : The souvenir's cost.
 *
 * POSTCONDITIONS -
 * 	Sets the souvenir's price field to cost.
 *************************************************************************/
void Souvenir::SetCost(float cost)
{
	price = cost;
}

/*************************************************************************
 * FUNCTION operator!=
 * -----------------------------------------------------------------------
 * Overloaded to compare the names of the souvenirs.
 * -----------------------------------------------------------------------
 * PRECONDITIONS -
 * compareTo : The other souvenir.
 *
 * POSTCONDITIONS -
 * 	True if the two souvenirs don't have the same name.
 *************************************************************************/
bool  Souvenir::operator!=(const Souvenir& compareTo) const
{
	return itemName != compareTo.itemName;
}
