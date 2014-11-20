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
	DirectedGraph<string>        graph;
	List<DirectedEdge<string>* > discoveryEdges;
	List<DirectedEdge<string>* > backEdges;
	List<DirectedEdge<string>* > crossEdges;
	List<DirectedEdge<string>* > forwardEdges;
	bool                         graphIsConnected;
	typename List<DirectedEdge<string>* >::Iterator edgeIt;

	graphIsConnected = true;

	/*********************************************************************
	 * OUT - Outputs the class header to the console.
	 *********************************************************************/
	ClassHeader("James Marcu", "374443", "CS1D", "TTh 3:30 PM",
			    'A', 13, "Directed Graphs", cout);

	InstantiateGraph(graph);

	cout << "Now conducting a depth first search...\n";
	graph.DFS(graph.GetVertex("Seattle"),
			  discoveryEdges,
			  backEdges,
			  crossEdges,
			  forwardEdges,
			  graphIsConnected);

	if(graphIsConnected)
	{
		cout << "The graph is strongly connected.";
	}
	else
	{
		cout << "The graph is NOT strongly connected.";
	}
	cout << endl << endl;

	cout << "The graphs discovery edges are: \n";
	edgeIt = discoveryEdges.Begin();
	while(edgeIt != discoveryEdges.End())
	{
		cout << left
			 << setw(COL_WIDTH) << (*edgeIt)->GetOrigin()->GetElem()
			 << "---> "
			 << setw(COL_WIDTH) << (*edgeIt)->GetDestination()->GetElem()
		     << " : "
		     << (*edgeIt)->GetWeight() << " miles"
		     << endl
		     << right;

		++edgeIt;
	}
	cout << endl;

	cout << "The graphs back edges are: \n";
	edgeIt = backEdges.Begin();
	while(edgeIt != backEdges.End())
	{
		cout << left
			 << setw(COL_WIDTH) << (*edgeIt)->GetOrigin()->GetElem()
			 << "---> "
			 << setw(COL_WIDTH) << (*edgeIt)->GetDestination()->GetElem()
		     << " : "
		     << (*edgeIt)->GetWeight() << " miles"
		     << endl
		     << right;

		++edgeIt;
	}
	cout << endl;

	cout << "The graphs forward edges are: \n";
	edgeIt = forwardEdges.Begin();
	if (forwardEdges.Size() > 0)
	{
		while(edgeIt != forwardEdges.End())
		{
			cout << left
				 << setw(COL_WIDTH) << (*edgeIt)->GetOrigin()->GetElem()
				 << "---> "
				 << setw(COL_WIDTH) << (*edgeIt)->GetDestination()->GetElem()
			     << " : "
			     << (*edgeIt)->GetWeight() << " miles"
			     << endl
			     << right;

			++edgeIt;
		}
		cout << endl;
	}
	else
	{
		cout << "None.\n\n";
	}


	cout << "The graphs cross edges are: \n";
	edgeIt = crossEdges.Begin();
	while(edgeIt != crossEdges.End())
	{
		cout << left
			 << setw(COL_WIDTH) << (*edgeIt)->GetOrigin()->GetElem()
			 << "---> "
			 << setw(COL_WIDTH) << (*edgeIt)->GetDestination()->GetElem()
		     << " : "
		     << (*edgeIt)->GetWeight() << " miles"
		     << endl
		     << right;
		++edgeIt;
	}
	cout << endl << endl;

	cout << "Now conducting a breadth first search...\n";
	graph.BFS(graph.GetVertex("Boston"));

	return 0;
}

