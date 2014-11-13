/*************************************************************************
 * AUTHOR      : James Marcu
 * STUDENT ID  : 374443
 * ASS #12     : Graphs
 * CLASS       : CS1D
 * SECTION     : TTh 3:30 AM
 * DUE DATE    : 11/13/2014
 *************************************************************************/
#include <string>
#include <iostream>
#include "Graph.h"
using namespace std;

int main()
{
	Graph<string> asdf;
	Edge<string>*   edgePtr;
	List<Edge<string> > discoveryEdges;

	Vertex<string>* chicago = new Vertex<string>("Chicago");
	asdf.InsertVertex(*chicago);

	Vertex<string>* seattle = new Vertex<string>("Seattle");
	asdf.InsertVertex(*seattle);

	Vertex<string>* sanFrancisco = new Vertex<string>("San Francisco");
	asdf.InsertVertex(*sanFrancisco);

	Vertex<string>* losAngeles = new Vertex<string>("Los Angeles");
	asdf.InsertVertex(*losAngeles);

	Vertex<string>* denver = new Vertex<string>("Denver");
	asdf.InsertVertex(*denver);

	Vertex<string>* kansasCity = new Vertex<string>("Kansas City");
	asdf.InsertVertex(*kansasCity);

	Vertex<string>* dallas = new Vertex<string>("Dallas");
	asdf.InsertVertex(*dallas);

	Vertex<string>* houston = new Vertex<string>("Houston");
	asdf.InsertVertex(*houston);

	Vertex<string>* miami = new Vertex<string>("Miami");
	asdf.InsertVertex(*miami);

	Vertex<string>* atlanta = new Vertex<string>("Atlanta");
	asdf.InsertVertex(*atlanta);

	Vertex<string>* newYork = new Vertex<string>("New York");
	asdf.InsertVertex(*newYork);

	Vertex<string>* boston = new Vertex<string>("Boston");
	asdf.InsertVertex(*boston);

	edgePtr = new Edge<string>(chicago, seattle, 2097);
	asdf.InsertEdge(*edgePtr);

	edgePtr = new Edge<string>(chicago, denver, 1003);
	asdf.InsertEdge(*edgePtr);

	edgePtr = new Edge<string>(chicago, kansasCity, 533);
	asdf.InsertEdge(*edgePtr);

	edgePtr = new Edge<string>(chicago, newYork, 1260);
	asdf.InsertEdge(*edgePtr);

	edgePtr = new Edge<string>(chicago, boston, 983);
	asdf.InsertEdge(*edgePtr);

	edgePtr = new Edge<string>(seattle, sanFrancisco, 807);
	asdf.InsertEdge(*edgePtr);

	edgePtr = new Edge<string>(seattle, denver, 1331);
	asdf.InsertEdge(*edgePtr);

	edgePtr = new Edge<string>(sanFrancisco, losAngeles, 381);
	asdf.InsertEdge(*edgePtr);

	edgePtr = new Edge<string>(sanFrancisco, denver, 1267);
	asdf.InsertEdge(*edgePtr);

	edgePtr = new Edge<string>(losAngeles, denver, 1015);
	asdf.InsertEdge(*edgePtr);

	edgePtr = new Edge<string>(losAngeles, kansasCity, 1663);
	asdf.InsertEdge(*edgePtr);

	edgePtr = new Edge<string>(kansasCity, denver, 599);
	asdf.InsertEdge(*edgePtr);

	edgePtr = new Edge<string>(kansasCity, dallas, 496);
	asdf.InsertEdge(*edgePtr);

	edgePtr = new Edge<string>(kansasCity, atlanta, 864);
	asdf.InsertEdge(*edgePtr);

	edgePtr = new Edge<string>(kansasCity, newYork, 1260);
	asdf.InsertEdge(*edgePtr);

	edgePtr = new Edge<string>(dallas, atlanta, 781);
	asdf.InsertEdge(*edgePtr);

	edgePtr = new Edge<string>(dallas, houston, 239);
	asdf.InsertEdge(*edgePtr);

	edgePtr = new Edge<string>(houston, atlanta, 810);
	asdf.InsertEdge(*edgePtr);

	edgePtr = new Edge<string>(houston, miami, 1187);
	asdf.InsertEdge(*edgePtr);

	edgePtr = new Edge<string>(atlanta, miami, 661);
	asdf.InsertEdge(*edgePtr);

	edgePtr = new Edge<string>(atlanta, newYork, 888);
	asdf.InsertEdge(*edgePtr);

	edgePtr = new Edge<string>(newYork, boston, 214);
	asdf.InsertEdge(*edgePtr);


	asdf.DFS(discoveryEdges, (*chicago));

	return 0;
}

