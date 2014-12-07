/*************************************************************************
 * AUTHOR      : James Marcu
 * STUDENT ID  : 374443
 * ASS #      : 
 * CLASS       : CS1D
 * SECTION     : TTh 3:30 AM
 * DUE DATE    : 
 *************************************************************************/

#include "header.h"

Stack<const NFL_Stadium*> CustomRoute(const NFL_Stadium& start,
		                              const List<NFL_Stadium>& destinations,
		                              const Graph<NFL_Stadium>& stadiumGraph)
{
	Stack<const Vertex<NFL_Stadium>* > vertStack;
	Stack<const Edge<NFL_Stadium>* >   edgeStack;
	Stack<const NFL_Stadium*>                 route;
	Stack<const NFL_Stadium*>          tempStack;
	List<const Vertex<NFL_Stadium>*>   destList;
	typename List<NFL_Stadium>::Iterator destIt;

	destIt = destinations.Begin();
	while(destIt != destinations.End())
	{
		destList.InsertBack(stadiumGraph.GetVertex(*destIt));
		++destIt;
	}

	stadiumGraph.FindShortestPath(stadiumGraph.GetVertex(start),
							      destList,
			                      vertStack,
			                      edgeStack);

	while(!vertStack.Empty())
	{
		tempStack.Push(&(vertStack.Peek()->GetElem()));
		vertStack.Pop();
	}

	while(!tempStack.Empty())
	{
		route.Push(tempStack.Peek());
		tempStack.Pop();
	}

	return route;
}
