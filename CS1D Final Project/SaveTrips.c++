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
	const NFL_Stadium* stadiumPtr;
	Stack<const Vertex<NFL_Stadium>* > vertStack;
	Stack<const Edge<NFL_Stadium>* >   edgeStack;
	List<const Vertex<NFL_Stadium>* > destAfcSdo;
	List<const Vertex<NFL_Stadium>* > destAfcSfo;
	List<const Vertex<NFL_Stadium>* > destAllSdo;
	List<const Vertex<NFL_Stadium>* > destAllSfo;
	List<const Vertex<NFL_Stadium>* > destNfcSdo;
	List<const Vertex<NFL_Stadium>* > destNfcSfo;
	List<const Vertex<NFL_Stadium>* > listSanDiegoAFC;
	List<const Vertex<NFL_Stadium>* > listSanFranAFC;
	List<const Vertex<NFL_Stadium>* > listSanDiegoAll;
	List<const Vertex<NFL_Stadium>* > listSanFranAll;
	List<const Vertex<NFL_Stadium>* > listSanDiegoNFC;
	List<const Vertex<NFL_Stadium>* > listSanFranNFC;
	List<const Vertex<NFL_Stadium>* > visitedDests;
	typename List<NFL_Stadium>::Iterator destIt;

	sanDiego     = stadiumGraph.GetVertex(stadiumMap.Find("Qualcomm Stadium")->GetValue());
	sanFrancisco = stadiumGraph.GetVertex(stadiumMap.Find("Levi\'s Stadium")->GetValue());

	oFile.open("Trip Planner - AFC Stadiums - San Diego");
	destIt = afcList.Begin();
	while(destIt != afcList.End())
	{
		destAfcSdo.InsertBack(stadiumGraph.GetVertex(*destIt));
		listSanDiegoAFC.InsertBack(stadiumGraph.GetVertex(*destIt));
		++destIt;
	}
	stadiumGraph.FindShortestPath(sanDiego, destAfcSdo, vertStack, edgeStack);
	destIt = afcList.Begin();
	while(!vertStack.Empty())
	{
		stadiumPtr = &vertStack.Peek()->GetElem();
		oFile << stadiumPtr->get_stadium_name() << endl;
		cout << stadiumPtr->get_stadium_name() << endl;
		if(listSanDiegoAFC.Search(stadiumGraph.GetVertex(*stadiumPtr)) != listSanDiegoAFC.End())
		{
			oFile << 1;
			listSanDiegoAFC.Erase(stadiumGraph.GetVertex(*stadiumPtr));
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
		listSanFranAFC.InsertBack(stadiumGraph.GetVertex(*destIt));
		++destIt;
	}
	stadiumGraph.FindShortestPath(sanFrancisco, destAfcSfo, vertStack, edgeStack);
	while(!vertStack.Empty())
	{
		stadiumPtr = &vertStack.Peek()->GetElem();
		oFile << stadiumPtr->get_stadium_name() << endl;
		if(listSanFranAFC.Search(stadiumGraph.GetVertex(*stadiumPtr)) != listSanFranAFC.End())
		{
			oFile << 1;
			listSanFranAFC.Erase(stadiumGraph.GetVertex(*stadiumPtr));
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
		listSanDiegoAll.InsertBack(stadiumGraph.GetVertex(*destIt));
		++destIt;
	}
	destIt = nfcList.Begin();
	while(destIt != nfcList.End())
	{
		if(listSanDiegoAll.Search(stadiumGraph.GetVertex(*destIt)) != listSanDiegoAll.End())
		{
			listSanDiegoAll.InsertBack(stadiumGraph.GetVertex(*destIt));
		}
		++destIt;
	}
	stadiumGraph.FindShortestPath(sanDiego, destAllSdo, vertStack, edgeStack);
	while(!vertStack.Empty())
	{
		stadiumPtr = &vertStack.Peek()->GetElem();
		oFile << stadiumPtr->get_stadium_name() << endl;
		if(listSanDiegoAll.Search(stadiumGraph.GetVertex(*stadiumPtr)) != listSanDiegoAll.End())
		{
			oFile << 1;
			listSanDiegoAll.Erase(stadiumGraph.GetVertex(*stadiumPtr));
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
		listSanFranAll.InsertBack(stadiumGraph.GetVertex(*destIt));
		++destIt;
	}
	destIt = nfcList.Begin();
	while(destIt != nfcList.End())
	{
		if(listSanFranAll.Search(stadiumGraph.GetVertex(*destIt)) != listSanFranAll.End())
		{
			destAllSfo.InsertBack(stadiumGraph.GetVertex(*destIt));
			listSanFranAll.InsertBack(stadiumGraph.GetVertex(*destIt));
		}
		++destIt;
	}
	stadiumGraph.FindShortestPath(sanFrancisco, destAllSfo, vertStack, edgeStack);
	while(!vertStack.Empty())
	{
		oFile << stadiumPtr->get_stadium_name() << endl;
		if(listSanFranAll.Search(stadiumGraph.GetVertex(*stadiumPtr)) != listSanFranAll.End())
		{
			oFile << 1;
			listSanFranAll.Erase(stadiumGraph.GetVertex(*stadiumPtr));
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
		listSanDiegoNFC.InsertBack(stadiumGraph.GetVertex(*destIt));
		++destIt;
	}
	cout << 2;
	cin.ignore(100, '\n');
	stadiumGraph.FindShortestPath(sanDiego, destNfcSdo, vertStack, edgeStack);
	cout << 3;
	cin.ignore(100, '\n');
	while(!vertStack.Empty())
	{
		stadiumPtr = &vertStack.Peek()->GetElem();
		oFile << vertStack.Peek()->GetElem().get_stadium_name() << endl;
		if(listSanDiegoNFC.Search(stadiumGraph.GetVertex(*stadiumPtr)) != listSanDiegoNFC.End())
		{
			listSanDiegoNFC.Erase(stadiumGraph.GetVertex(*stadiumPtr));
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
		listSanFranNFC.InsertBack(stadiumGraph.GetVertex(*destIt));
		++destIt;
	}
	stadiumGraph.FindShortestPath(sanFrancisco, destNfcSfo, vertStack, edgeStack);
	while(!vertStack.Empty())
	{
		oFile << vertStack.Peek()->GetElem().get_stadium_name() << endl;
		if(listSanDiegoNFC.Search(stadiumGraph.GetVertex(*stadiumPtr)) != listSanDiegoNFC.End())
		{
			listSanFranNFC.Erase(stadiumGraph.GetVertex(*stadiumPtr));
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
