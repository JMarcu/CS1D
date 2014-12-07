/*************************************************************************
 * AUTHOR      : James Marcu
 * STUDENT ID  : 374443
 * ASS #      : 
 * CLASS       : CS1D
 * SECTION     : TTh 3:30 AM
 * DUE DATE    : 
 *************************************************************************/

#include "header.h"

void CreateGraph(Graph<NFL_Stadium>& stadiumGraph,
		         const List<NFL_Stadium>& stadiumList,
		         const Map<string, NFL_Stadium>& stadiumMap)
{
	typename List<NFL_Stadium>::Iterator stadiumIt;
	ifstream inFile;
	string   stadiumOne;
	string   stadiumTwo;
	float    weight;

	stadiumIt = stadiumList.Begin();

	while(stadiumIt != stadiumList.End())
	{
		stadiumGraph.AddVertex(stadiumMap.Find((*stadiumIt).get_stadium_name())->GetValue());

		++stadiumIt;
	}

	inFile.open("Stadium Connections");

	while(inFile)
	{
		getline(inFile, stadiumOne);
		getline(inFile, stadiumTwo);
		inFile >> weight;
		inFile.ignore(1000, '\n');

		stadiumGraph.AddEdge(stadiumGraph.GetVertex(stadiumMap.Find(stadiumOne)->GetValue()),
				             stadiumGraph.GetVertex(stadiumMap.Find(stadiumTwo)->GetValue()),
				             weight);
	}


	inFile.close();
}
