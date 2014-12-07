/*************************************************************************
 * AUTHOR      : James Marcu
 * STUDENT ID  : 374443
 * ASS #      : 
 * CLASS       : CS1D
 * SECTION     : TTh 3:30 AM
 * DUE DATE    : 
 *************************************************************************/

#include "header.h"

void SaveTrips(const List<NFL_Stadium>&  nfcList,
		       const List<NFL_Stadium>&  afcList,
		       const Map<string, NFL_Stadium>& stadiumMap,
		       const Graph<NFL_Stadium>& stadiumGraph)
{
	ofstream oFile;
	const Vertex<NFL_Stadium>* sanDiego;
	const Vertex<NFL_Stadium>* sanFrancisco;
	Stack<const Vertex<NFL_Stadium>* > vertStack;
	Stack<const Edge<NFL_Stadium>* >   edgeStack;
	List<const Vertex<NFL_Stadium>* > destAfcSdo;
	List<const Vertex<NFL_Stadium>* > destAfcSfo;
	List<const Vertex<NFL_Stadium>* > destAllSdo;
	List<const Vertex<NFL_Stadium>* > destAllSfo;
	List<const Vertex<NFL_Stadium>* > destNfcSdo;
	List<const Vertex<NFL_Stadium>* > destNfcSfo;
	typename List<NFL_Stadium>::Iterator destIt;

	sanDiego     = stadiumGraph.GetVertex(stadiumMap.Find("Qualcomm Stadium")->GetValue());
	sanFrancisco = stadiumGraph.GetVertex(stadiumMap.Find("Levi\'s Stadium")->GetValue());

	oFile.open("Trip Planner - AFC Stadiums - San Diego");
	destIt = afcList.Begin();
	while(destIt != afcList.End())
	{
		destAfcSdo.InsertBack(stadiumGraph.GetVertex(*destIt));
		++destIt;
	}
	stadiumGraph.FindShortestPath(sanDiego, destAfcSdo, vertStack, edgeStack);
	while(!vertStack.Empty())
	{
		oFile << vertStack.Peek()->GetElem().get_stadium_name() << endl;
		if(stadiumMap.Find(vertStack.Peek()->GetElem().get_stadium_name())->GetValue().is_in_AFC())
		{
			oFile << 1;
		}
		else
		{
			oFile << 0;
		}

		vertStack.Pop();

		if(!vertStack.Empty())
		{
			oFile << endl;
		}
	}
	oFile.close();
	oFile.clear();

	oFile.open("Trip Planner - AFC Stadiums - San Francisco");
	destIt = afcList.Begin();
	while(destIt != afcList.End())
	{
		destAfcSfo.InsertBack(stadiumGraph.GetVertex(*destIt));
		++destIt;
	}
	stadiumGraph.FindShortestPath(sanFrancisco, destAfcSfo, vertStack, edgeStack);
	while(!vertStack.Empty())
	{
		oFile << vertStack.Peek()->GetElem().get_stadium_name() << endl;
		if(stadiumMap.Find(vertStack.Peek()->GetElem().get_stadium_name())->GetValue().is_in_AFC())
		{
			oFile << 1;
		}
		else
		{
			oFile << 0;
		}

		vertStack.Pop();
		if(!vertStack.Empty())
		{
			oFile << endl;
		}
	}
	oFile.close();
	oFile.clear();

	oFile.open("Trip Planner - All Stadiums - San Diego");
	destIt = afcList.Begin();
	while(destIt != afcList.End())
	{
		destAllSdo.InsertBack(stadiumGraph.GetVertex(*destIt));
		++destIt;
	}
	destIt = nfcList.Begin();
	while(destIt != nfcList.End())
	{
		if(destAllSdo.Search(stadiumGraph.GetVertex(*destIt)) != destAllSdo.End())
		{
			destAllSdo.InsertBack(stadiumGraph.GetVertex(*destIt));
		}
		++destIt;
	}
	stadiumGraph.FindShortestPath(sanDiego, destAllSdo, vertStack, edgeStack);
	while(!vertStack.Empty())
	{
		oFile << vertStack.Peek()->GetElem().get_stadium_name() << endl;
		if(stadiumMap.Find(vertStack.Peek()->GetElem().get_stadium_name())->GetValue().is_in_AFC())
		{
			oFile << 1;
		}
		else
		{
			oFile << 0;
		}

		vertStack.Pop();
		if(!vertStack.Empty())
		{
			oFile << endl;
		}
	}
	oFile.close();
	oFile.clear();

	oFile.open("Trip Planner - All Stadiums - San Francisco");
	destIt = afcList.Begin();
	while(destIt != afcList.End())
	{
		destAllSfo.InsertBack(stadiumGraph.GetVertex(*destIt));
		++destIt;
	}
	destIt = nfcList.Begin();
	while(destIt != nfcList.End())
	{
		if(destAllSfo.Search(stadiumGraph.GetVertex(*destIt)) != destAllSfo.End())
		{
			destAllSfo.InsertBack(stadiumGraph.GetVertex(*destIt));
		}
		++destIt;
	}
	stadiumGraph.FindShortestPath(sanFrancisco, destAllSfo, vertStack, edgeStack);
	while(!vertStack.Empty())
	{
		oFile << vertStack.Peek()->GetElem().get_stadium_name() << endl;
		if(stadiumMap.Find(vertStack.Peek()->GetElem().get_stadium_name())->GetValue().is_in_AFC())
		{
			oFile << 1;
		}
		else
		{
			oFile << 0;
		}

		vertStack.Pop();
		if(!vertStack.Empty())
		{
			oFile << endl;
		}
	}
	oFile.close();
	oFile.clear();

	oFile.open("Trip Planner - NFC Stadiums - San Diego");
	destIt = nfcList.Begin();
	while(destIt != nfcList.End())
	{
		destNfcSdo.InsertBack(stadiumGraph.GetVertex(*destIt));
		++destIt;
	}
	stadiumGraph.FindShortestPath(sanDiego, destNfcSdo, vertStack, edgeStack);
	while(!vertStack.Empty())
	{
		oFile << vertStack.Peek()->GetElem().get_stadium_name() << endl;
		if(stadiumMap.Find(vertStack.Peek()->GetElem().get_stadium_name())->GetValue().is_in_AFC())
		{
			oFile << 1;
		}
		else
		{
			oFile << 0;
		}

		vertStack.Pop();
		if(!vertStack.Empty())
		{
			oFile << endl;
		}
	}
	oFile.close();
	oFile.clear();

	oFile.open("Trip Planner - NFC Stadiums - San Francisco");
	destIt = nfcList.Begin();
	while(destIt != nfcList.End())
	{
		destNfcSfo.InsertBack(stadiumGraph.GetVertex(*destIt));
		++destIt;
	}
	stadiumGraph.FindShortestPath(sanFrancisco, destNfcSfo, vertStack, edgeStack);
	while(!vertStack.Empty())
	{
		oFile << vertStack.Peek()->GetElem().get_stadium_name() << endl;
		if(stadiumMap.Find(vertStack.Peek()->GetElem().get_stadium_name())->GetValue().is_in_AFC())
		{
			oFile << 1;
		}
		else
		{
			oFile << 0;
		}

		vertStack.Pop();
		if(!vertStack.Empty())
		{
			oFile << endl;
		}
	}
	oFile.close();
	oFile.clear();
}
