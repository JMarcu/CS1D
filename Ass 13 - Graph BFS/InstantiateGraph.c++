/*************************************************************************
 * AUTHOR      : James Marcu
 * STUDENT ID  : 374443
 * ASS #      : 
 * CLASS       : CS1D
 * SECTION     : TTh 3:30 AM
 * DUE DATE    : 
 *************************************************************************/

#include "header.h"

void InstantiateGraph(DirectedGraph<string>& graph)
{
	graph.AddVertex("Chicago");      //0
	graph.AddVertex("Seattle");      //1
	graph.AddVertex("Boston");       //2
	graph.AddVertex("San Francisco");//3
	graph.AddVertex("Los Angeles");  //4
	graph.AddVertex("Denver");       //5
	graph.AddVertex("Kansas City");  //6
	graph.AddVertex("Dallas");       //7
	graph.AddVertex("Houston");      //8
	graph.AddVertex("New York");     //9
	graph.AddVertex("Atlanta");      //10
	graph.AddVertex("Miami");        //11

	graph.AddEdge(graph.GetVertex("Chicago"), graph.GetVertex("Boston"), 983);
	graph.AddEdge(graph.GetVertex("Chicago"), graph.GetVertex("Seattle"), 2097);
	graph.AddEdge(graph.GetVertex("Seattle"), graph.GetVertex("Denver"), 1331);
	graph.AddEdge(graph.GetVertex("Seattle"), graph.GetVertex("San Francisco"), 807);
	graph.AddEdge(graph.GetVertex("Boston"), graph.GetVertex("New York"), 214);
	graph.AddEdge(graph.GetVertex("San Francisco"), graph.GetVertex("Los Angeles"), 381);
	graph.AddEdge(graph.GetVertex("Los Angeles"), graph.GetVertex("Denver"), 1015);
	graph.AddEdge(graph.GetVertex("Denver"), graph.GetVertex("San Francisco"), 1267);
	graph.AddEdge(graph.GetVertex("Denver"), graph.GetVertex("Chicago"), 1003);
	graph.AddEdge(graph.GetVertex("Kansas City"), graph.GetVertex("Chicago"), 533);
	graph.AddEdge(graph.GetVertex("Kansas City"), graph.GetVertex("Los Angeles"), 1663);
	graph.AddEdge(graph.GetVertex("Kansas City"), graph.GetVertex("Denver"), 599);
	graph.AddEdge(graph.GetVertex("Kansas City"), graph.GetVertex("New York"), 1260);
	graph.AddEdge(graph.GetVertex("Kansas City"), graph.GetVertex("Atlanta"), 864);
	graph.AddEdge(graph.GetVertex("Dallas"), graph.GetVertex("Los Angeles"), 1435);
	graph.AddEdge(graph.GetVertex("Dallas"), graph.GetVertex("Kansas City"), 496);
	graph.AddEdge(graph.GetVertex("Dallas"), graph.GetVertex("Atlanta"), 781);
	graph.AddEdge(graph.GetVertex("Houston"), graph.GetVertex("Dallas"), 239);
	graph.AddEdge(graph.GetVertex("Houston"), graph.GetVertex("Atlanta"), 810);
	graph.AddEdge(graph.GetVertex("New York"), graph.GetVertex("Chicago"), 787);
	graph.AddEdge(graph.GetVertex("New York"), graph.GetVertex("Atlanta"), 888);
	graph.AddEdge(graph.GetVertex("Atlanta"), graph.GetVertex("Miami"), 661);
	graph.AddEdge(graph.GetVertex("Miami"), graph.GetVertex("Houston"), 1187);
}

