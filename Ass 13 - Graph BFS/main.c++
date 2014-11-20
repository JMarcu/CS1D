/*************************************************************************
 * AUTHOR      : James Marcu
 * STUDENT ID  : 374443
 * ASS #13     : Directed Graph
 * CLASS       : CS1D
 * SECTION     : TTh 3:30 AM
 * DUE DATE    : 11/20/2014
 *************************************************************************/

#include "header.h"

/*************************************************************************
 * Directed Graph - Assignment 13
 * -----------------------------------------------------------------------
 * This program tests the implementation of a directed graph and its
 * depth-first search and breadth-first search functions.
 * -----------------------------------------------------------------------
 * INPUT -
 * 	Input is hardcoded within the InstantiateGraph function.
 *
 * OUTPUT -
 * 	Outputs the results of the DFS and BFS functions.
 *************************************************************************/
int main()
{
	//VARIABLE DECLERATIONS
	DirectedGraph<string>        graph;           //The graph.
	List<DirectedEdge<string>* > discoveryEdges;  //Discovery edges from the DFS.
	List<DirectedEdge<string>* > backEdges;       //Back edges from the DFS.
	List<DirectedEdge<string>* > crossEdges;      //Cross edges from the DFS.
	List<DirectedEdge<string>* > forwardEdges;    //Forward edges from the DFS.
	bool                         graphIsConnected;//If the graph is strongly connected.
	typename List<DirectedEdge<string>* >::Iterator edgeIt;//Used to iterate
	                                                       //lists of edges.

	//VARIABLE INITIALIZATIONS
	graphIsConnected = true;

	/*********************************************************************
	 * OUT - Outputs the class header to the console.
	 *********************************************************************/
	ClassHeader("James Marcu", "374443", "CS1D", "TTh 3:30 PM",
			    'A', 13, "Directed Graphs", cout);

	/*********************************************************************
	 * IN - Initializes the graph using hardcoded data.
	 *********************************************************************/
	InstantiateGraph(graph);

	/*********************************************************************
	 * PROC - Runs the DFS search on the graph starting at Seattle. The
	 *        edges will be returned in the provided lists.
	 *********************************************************************/
	cout << "Now conducting a depth first search...\n";
	graph.DFS(graph.GetVertex("Seattle"),
			  discoveryEdges,
			  backEdges,
			  crossEdges,
			  forwardEdges,
			  graphIsConnected);

	/*********************************************************************
	 * OUT - Outputs if the graph was strongly connected.
	 *********************************************************************/
	if(graphIsConnected)
	{
		cout << "The graph is strongly connected.";
	}
	else
	{
		cout << "The graph is NOT strongly connected.";
	}
	cout << endl << endl;

	/*********************************************************************
	 * OUT - Outputs the discovery edges from the DFS.
	 *********************************************************************/
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

	/*********************************************************************
	 * OUT - Outputs the back edges from the DFS.
	 *********************************************************************/
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

	/*********************************************************************
	 * OUT - Outputs the forward edges from the DFS.
	 *********************************************************************/
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

	/*********************************************************************
	 * OUT - Outputs the cross edges from the DFS.
	 *********************************************************************/
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

	/*********************************************************************
	 * PROC & OUT - Runs a breadth first search on the graph starting at
	 *              Boston. This function will print the results to the
	 *              console internally.
	 *********************************************************************/
	cout << "Now conducting a breadth first search...\n";
	graph.BFS(graph.GetVertex("Boston"));

	return 0;
}

