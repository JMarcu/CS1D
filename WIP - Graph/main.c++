#include "header.h"

int main()
{
	//VARIABLE DECLERATIONS
	Graph<string>        graph;           //The graph.
	const Vertex<string>* vP;
	List<const Vertex<string>* > vL;
	Stack<const Vertex<string>* > vS;
	Stack<const Edge<string>* > eS;
	Tree<const Vertex<string>* > tree;

	InstantiateGraph(graph);

	vP = graph.GetVertex("SFO");

	vL.InsertBack(graph.GetVertex("SFO"));
	vL.InsertBack(graph.GetVertex("SEA"));
	vL.InsertBack(graph.GetVertex("HOU"));
	vL.InsertBack(graph.GetVertex("MIA"));

	graph.ShortestPath(vP, vL, vS, eS);

	while(!vS.Size() == 0)
	{
		cout << vS.Peek()->GetElem();
		vS.Pop();
		cout << endl;

		if(!eS.Empty())
		{
			cout << eS.Peek()->GetWeight();
			eS.Pop();
			cout << endl;
		}
	}

	vP = NULL;

	return 0;
}

