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
 * FUNCTION CustomRoute
 * -----------------------------------------------------------------------
 * This calculate a route for visiting user selected NFL stadiums.
 * -----------------------------------------------------------------------
 * PRE-CONDITIONS -
 *  start        : Which city to start in.
 * 	destinations : Which NFL stadiums to visit.
 * 	stadiumGraph : Graph of stadiums and the routes between them.
 *
 * POST-CONDITIONS -
 * 	Purchase map will store any purchases they elect to make.
 *************************************************************************/
Stack<const NFL_Stadium*> CustomRoute(const NFL_Stadium&        start,
		                              const List<NFL_Stadium>&  destinations,
		                              const Graph<NFL_Stadium>& stadiumGraph)
{
	//VARIABLE DECLERATIONS
	Stack<const Vertex<NFL_Stadium>* >   vertStack;//PROC - Stores the order
	                                               //       to visit vertices.
	Stack<const Edge<NFL_Stadium>* >     edgeStack;//PROC - Stores the order
	                                               //       to visit edges.
	Stack<const NFL_Stadium*>            route;    //OUT  - Stores the order
	                                               //       to visit stadiums.
	Stack<const NFL_Stadium*>            tempStack;//PROC - Used to order the
	                                               //       route stack.
	List<const Vertex<NFL_Stadium>*>     destList; //PROC - List of vertices
	                                               //       to visit.
	typename List<NFL_Stadium>::Iterator destIt;   //PROC - Iterates destList.

	/*********************************************************************
	 * PROC - For each stadium in destinations add the vertex containing
	 *        it to destList.
	 *********************************************************************/
	destIt = destinations.Begin();
	while(destIt != destinations.End())
	{
		destList.InsertBack(stadiumGraph.GetVertex(*destIt));
		++destIt;
	}

	/*********************************************************************
	 * PROC - Claculate the path to take.
	 *********************************************************************/
	stadiumGraph.FindShortestPath(stadiumGraph.GetVertex(start),
							      destList,
			                      vertStack,
			                      edgeStack);

	/*********************************************************************
	 * PROC - For each vertex in vertStack put the stadium it contains
	 *        into tempStack.
	 *********************************************************************/
	while(!vertStack.Empty())
	{
		tempStack.Push(&(vertStack.Peek()->GetElem()));
		vertStack.Pop();
	}

	/*********************************************************************
	 * PROC - Transfer the stadiums from tempStack to route. They are now
	 *        in the proper order, with the top stadium being the starting
	 *        one.
	 *********************************************************************/
	while(!tempStack.Empty())
	{
		route.Push(tempStack.Peek());
		tempStack.Pop();
	}

	return route;
}
