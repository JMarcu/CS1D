/*************************************************************************
 * AUTHOR      : James Marcu
 * STUDENT ID  : 374443
 * ASS #      : 
 * CLASS       : CS1D
 * SECTION     : TTh 3:30 AM
 * DUE DATE    : 
 *************************************************************************/

#include "header.h"

int main()
{
	DirectedGraph<string> graph;
	bool                  graphIsConnected;

	/*********************************************************************
	 * OUT - Outputs the class header to the console.
	 *********************************************************************/
	ClassHeader("James Marcu", "374443", "CS1D", "TTh 3:30 PM",
			    'A', 13, "Directed Graphs", cout);

	InstantiateGraph(graph);

	graphIsConnected = graph.IsStronglyConnected(graph.GetVertex("Seattle"));

	if(graphIsConnected)
	{
		cout << "The graph is strongly connected.\n\n";
	}
	else
	{
		cout << "The graph is NOT strongly connected.\n\n";
	}

	graph.BFS(graph.GetVertex("Boston"));

	return 0;
}

