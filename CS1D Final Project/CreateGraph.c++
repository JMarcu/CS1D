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
 * FUNCTION CreateGraph
 * -----------------------------------------------------------------------
 * This function instantiates the program's graph object.
 * -----------------------------------------------------------------------
 * PRE-CONDITIONS -
 * 	stadiumGraph : The graph to instantiate.
 * 	stadiumList  : A list containing all stadiums.
 * 	stadiumMap   : A map containing all stadiums.
 *
 * POST-CONDITIONS -
 * 	The stadiumGraph will be instantiated with all the data from the
 * 	program.
 *************************************************************************/
void CreateGraph(Graph<NFL_Stadium>&             stadiumGraph,
		         const List<NFL_Stadium>&        stadiumList,
		         const Map<string, NFL_Stadium>& stadiumMap)
{
	//VARIABLE DECLERATIONS
	ifstream inFile;    //PROC - Input file stream variable.
	string   stadiumOne;//IN - Name of the first stadium.
	string   stadiumTwo;//IN - Name of the second stadium.
	float    weight;    //IN - Weight of an edge.
	typename List<NFL_Stadium>::Iterator stadiumIt;//PROC - Iterates the
	                                               //       stadium list.

	/*********************************************************************
	 * PROC - Add each stadium to the graph as a vertex.
	 *********************************************************************/
	stadiumIt = stadiumList.Begin();
	while(stadiumIt != stadiumList.End())
	{
		stadiumGraph.AddVertex(stadiumMap.Find((*stadiumIt).get_stadium_name())->GetValue());

		++stadiumIt;
	}

	/*********************************************************************
	 * PROC - Add each edge found in the input file to the graph.
	 *********************************************************************/
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

