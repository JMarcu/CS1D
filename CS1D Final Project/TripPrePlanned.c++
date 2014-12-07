/*************************************************************************
 * AUTHOR      : James Marcu
 * STUDENT ID  : 374443
 * ASS #      : 
 * CLASS       : CS1D
 * SECTION     : TTh 3:30 AM
 * DUE DATE    : 
 *************************************************************************/

#include "header.h"

/*************************************************************************
 * FUNCTION AllStaiumdsSDO
 * -----------------------------------------------------------------------
 * Generates a route for visiting all stadiums from San Diego using the
 * save file.
 * -----------------------------------------------------------------------
 * PRE-CONDITIONS -
 * 	route      : The stack that holds the route to take.
 * 	stadiumMap : A map of stadium names->stadium objects.
 *
 * POST-CONDITIONS -
 * 	The stack 'route' is filled with the route to take.
 *************************************************************************/
void AllStadiumsSDO(Stack<const NFL_Stadium*>& route,
		List<NFL_Stadium>& destinations,
		            const Map<string, NFL_Stadium>& stadiumMap)
{
	//VARIABLE DECLERATIONS
	ifstream inFile;     //PROC - The input file stream variable.
	string   stadiumName;//PROC - Stores the stadium names from the file.
	bool     isDest;
	Stack<const NFL_Stadium*> tempStack;//PROC - Used to order the stadiums.

	//Open the file.
	inFile.open("Trip Planner - All Stadiums - San Diego");

	//Read each line.
	while(getline(inFile, stadiumName))
	{
		//Add the corresponding stadium to the stack.
		tempStack.Push(&stadiumMap.Find(stadiumName)->GetValue());

		inFile >> isDest;
		inFile.ignore(1000, '\n');

		if(isDest)
		{
			destinations.InsertBack(stadiumMap.Find(stadiumName)->GetValue());
		}
	}

	//Push from tempStack to route. The stadiums are ordered right now.
	while(!tempStack.Empty())
	{
		route.Push(tempStack.Peek());
		tempStack.Pop();
	}

	inFile.close();
}

/*************************************************************************
 * FUNCTION AllStaiumdsSFO
 * -----------------------------------------------------------------------
 * Generates a route for visiting all stadiums from San Francisco using the
 * save file.
 * -----------------------------------------------------------------------
 * PRE-CONDITIONS -
 * 	route      : The stack that holds the route to take.
 * 	stadiumMap : A map of stadium names->stadium objects.
 *
 * POST-CONDITIONS -
 * 	The stack 'route' is filled with the route to take.
 *************************************************************************/
void AllStadiumsSFO(Stack<const NFL_Stadium*>& route,
		List<NFL_Stadium>& destinations,
		            const Map<string, NFL_Stadium>& stadiumMap)
{
	//VARIABLE DECLERATIONS
	ifstream inFile;     //PROC - The input file stream variable.
	string   stadiumName;//PROC - Stores the stadium names from the file.
	bool     isDest;
	Stack<const NFL_Stadium*> tempStack;//PROC - Used to order the stadiums.

	//Open the file.
	inFile.open("Trip Planner - All Stadiums - San Francisco");

	//Read each line.
	while(getline(inFile, stadiumName))
	{
		//Add the corresponding stadium to the stack.
		tempStack.Push(&stadiumMap.Find(stadiumName)->GetValue());

		inFile >> isDest;
		inFile.ignore(1000, '\n');

		if(isDest)
		{
			destinations.InsertBack(stadiumMap.Find(stadiumName)->GetValue());
		}
	}

	//Push from tempStack to route. The stadiums are ordered right now.
	while(!tempStack.Empty())
	{
		route.Push(tempStack.Peek());
		tempStack.Pop();
	}

	inFile.close();
}

/*************************************************************************
 * FUNCTION AFCStadiumsSDO
 * -----------------------------------------------------------------------
 * Generates a route for visiting all AFC stadiums from San Diego using the
 * save file.
 * -----------------------------------------------------------------------
 * PRE-CONDITIONS -
 * 	route      : The stack that holds the route to take.
 * 	stadiumMap : A map of stadium names->stadium objects.
 *
 * POST-CONDITIONS -
 * 	The stack 'route' is filled with the route to take.
 *************************************************************************/
void AFCStadiumsSDO(Stack<const NFL_Stadium*>& route,
		List<NFL_Stadium>& destinations,
		            const Map<string, NFL_Stadium>& stadiumMap)
{
	//VARIABLE DECLERATIONS
	ifstream inFile;     //PROC - The input file stream variable.
	string   stadiumName;//PROC - Stores the stadium names from the file.
	bool     isDest;
	Stack<const NFL_Stadium*> tempStack;//PROC - Used to order the stadiums.

	//Open the file.
	inFile.open("Trip Planner - AFC Stadiums - San Diego");

	//Read each line.
	while(getline(inFile, stadiumName))
	{
		//Add the corresponding stadium to the stack.
		tempStack.Push(&stadiumMap.Find(stadiumName)->GetValue());

		inFile >> isDest;
		inFile.ignore(1000, '\n');

		if(isDest)
		{
			destinations.InsertBack(stadiumMap.Find(stadiumName)->GetValue());
		}
	}

	//Push from tempStack to route. The stadiums are ordered right now.
	while(!tempStack.Empty())
	{
		route.Push(tempStack.Peek());
		tempStack.Pop();
	}

	inFile.close();
}

/*************************************************************************
 * FUNCTION AFCStaiumdsSFO
 * -----------------------------------------------------------------------
 * Generates a route for visiting all stadiums from San Francisco using the
 * save file.
 * -----------------------------------------------------------------------
 * PRE-CONDITIONS -
 * 	route      : The stack that holds the route to take.
 * 	stadiumMap : A map of stadium names->stadium objects.
 *
 * POST-CONDITIONS -
 * 	The stack 'route' is filled with the route to take.
 *************************************************************************/
void AFCStadiumsSFO(Stack<const NFL_Stadium*>& route,
		List<NFL_Stadium>& destinations,
		            const Map<string, NFL_Stadium>& stadiumMap)
{
	//VARIABLE DECLERATIONS
	ifstream inFile;     //PROC - The input file stream variable.
	string   stadiumName;//PROC - Stores the stadium names from the file.
	bool     isDest;
	Stack<const NFL_Stadium*> tempStack;//PROC - Used to order the stadiums.

	//Open the file.
	inFile.open("Trip Planner - AFC Stadiums - San Francisco");

	//Read each line.
	while(getline(inFile, stadiumName))
	{
		//Add the corresponding stadium to the stack.
		tempStack.Push(&stadiumMap.Find(stadiumName)->GetValue());

		inFile >> isDest;
		inFile.ignore(1000, '\n');

		if(isDest)
		{
			destinations.InsertBack(stadiumMap.Find(stadiumName)->GetValue());
		}
	}

	//Push from tempStack to route. The stadiums are ordered right now.
	while(!tempStack.Empty())
	{
		route.Push(tempStack.Peek());
		tempStack.Pop();
	}

	inFile.close();
}

/*************************************************************************
 * FUNCTION NFCStadiumsSDO
 * -----------------------------------------------------------------------
 * Generates a route for visiting all NFC stadiums from San Diego using the
 * save file.
 * -----------------------------------------------------------------------
 * PRE-CONDITIONS -
 * 	route      : The stack that holds the route to take.
 * 	stadiumMap : A map of stadium names->stadium objects.
 *
 * POST-CONDITIONS -
 * 	The stack 'route' is filled with the route to take.
 *************************************************************************/
void NFCStadiumsSDO(Stack<const NFL_Stadium*>& route,
		List<NFL_Stadium>& destinations,
		            const Map<string, NFL_Stadium>& stadiumMap)
{
	//VARIABLE DECLERATIONS
	ifstream inFile;     //PROC - The input file stream variable.
	string   stadiumName;//PROC - Stores the stadium names from the file.
	bool     isDest;
	Stack<const NFL_Stadium*> tempStack;//PROC - Used to order the stadiums.

	//Open the file.
	inFile.open("Trip Planner - NFC Stadiums - San Diego");

	//Read each line.
	while(getline(inFile, stadiumName))
	{
		//Add the corresponding stadium to the stack.
		tempStack.Push(&stadiumMap.Find(stadiumName)->GetValue());

		inFile >> isDest;
		inFile.ignore(1000, '\n');

		if(isDest)
		{
			destinations.InsertBack(stadiumMap.Find(stadiumName)->GetValue());
		}
	}

	//Push from tempStack to route. The stadiums are ordered right now.
	while(!tempStack.Empty())
	{
		route.Push(tempStack.Peek());
		tempStack.Pop();
	}

	inFile.close();
}

/*************************************************************************
 * FUNCTION NFCStaiumdsSFO
 * -----------------------------------------------------------------------
 * Generates a route for visiting all NFC stadiums from San Francisco using
 * the save file.
 * -----------------------------------------------------------------------
 * PRE-CONDITIONS -
 * 	route      : The stack that holds the route to take.
 * 	stadiumMap : A map of stadium names->stadium objects.
 *
 * POST-CONDITIONS -
 * 	The stack 'route' is filled with the route to take.
 *************************************************************************/
void NFCStadiumsSFO(Stack<const NFL_Stadium*>& route,
		List<NFL_Stadium>& destinations,
		            const Map<string, NFL_Stadium>& stadiumMap)
{
	//VARIABLE DECLERATIONS
	ifstream inFile;     //PROC - The input file stream variable.
	string   stadiumName;//PROC - Stores the stadium names from the file.
	bool     isDest;
	Stack<const NFL_Stadium*> tempStack;//PROC - Used to order the stadiums.

	//Open the file.
	inFile.open("Trip Planner - NFC Stadiums - San Francisco");

	//Read each line.
	while(getline(inFile, stadiumName))
	{
		//Add the corresponding stadium to the stack.
		tempStack.Push(&stadiumMap.Find(stadiumName)->GetValue());

		inFile >> isDest;
		inFile.ignore(1000, '\n');

		if(isDest)
		{
			destinations.InsertBack(stadiumMap.Find(stadiumName)->GetValue());
		}
	}

	//Push from tempStack to route. The stadiums are ordered right now.
	while(!tempStack.Empty())
	{
		route.Push(tempStack.Peek());
		tempStack.Pop();
	}

	inFile.close();
}
