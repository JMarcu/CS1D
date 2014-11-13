/*************************************************************************
 * AUTHOR      : James Marcu
 * STUDENT ID  : 374443
 * ASS #12     : Graphs
 * CLASS       : CS1D
 * SECTION     : TTh 3:30 AM
 * DUE DATE    : 11/13/2014
 *************************************************************************/
#ifndef GRAPH_H_
#define GRAPH_H_

#include "GraphEdge.h"
using namespace std;

template <typename ElemType>
class Graph
{
	public:
		const List<Vertex<ElemType> >& Vertices() const;
		const List<Edge<ElemType>   >& Edges() const;
		const Vertex<ElemType>& GetVertex(const ElemType& key);
		bool DFS(List<Edge<ElemType> >& discovery,
				 const Vertex<ElemType>& current,
				 List<Vertex<ElemType> > visited = new List<Vertex<ElemType> >);

		void InsertVertex(Vertex<ElemType>& newVertex);
		void InsertEdge  (Edge<ElemType>&   newEdge);
		void EraseVertex (const Vertex<ElemType>& toDelete);
		void EraseEdge   (const Edge<ElemType>&   toDelete);


	private:
		List<Vertex<ElemType> > verticeList;
		List<Edge<ElemType> >   edgeList;
};

template <typename ElemType>
const List<Vertex<ElemType> >& Graph<ElemType>::Vertices() const
{
	return verticeList;
}

template <typename ElemType>
const List<Edge<ElemType> >& Graph<ElemType>::Edges() const
{
	return edgeList;
}

template <typename ElemType>
const Vertex<ElemType>& Graph<ElemType>::GetVertex(const ElemType& key)
{
	typename List<Vertex<ElemType> >::Iterator searchIt;
	bool found;
	Vertex<ElemType>* returnPtr;

	searchIt = verticeList.Begin();
	found = false;

	while(!found && searchIt != verticeList.End())
	{
		if(*(*searchIt) == key)
		{
			found = true;
		}
		else
		{
			++searchIt;
		}
	}
	return (*searchIt);

}

template <typename ElemType>
void Graph<ElemType>::InsertVertex(Vertex<ElemType>& newVertex)
{
	verticeList.InsertBack(newVertex);
}

template <typename ElemType>
void Graph<ElemType>::InsertEdge(Edge<ElemType>& newEdge)
{
	Vertex<ElemType>* arr[2];

	edgeList.InsertBack(newEdge);

	newEdge.EndVerteces(arr);
	arr[0]->AddEdge(newEdge);
	arr[1]->AddEdge(newEdge);

}

template <typename ElemType>
void Graph<ElemType>::EraseVertex(const Vertex<ElemType>& toDelete)
{
	verticeList.Erase(toDelete);
}

template <typename ElemType>
void Graph<ElemType>::EraseEdge(const Edge<ElemType>& toDelete)
{
	edgeList.Erase(toDelete);
}

template <typename ElemType>
bool Graph<ElemType>::DFS(List<Edge<ElemType> >& discovery, const Vertex<ElemType>& current, List<Vertex<ElemType> > visited)
{
	bool found;
	bool search;
	typename List<Edge<ElemType> >::Iterator searchIt;

	visited.InsertBack(current);
	found  = false;
	search = true;

	searchIt = current.IncidentEdges().Begin();
	while (!found && search)
	{
		if(searchIt == current.IncidentEdges().End())
		{
			search = false;
		}
		else if(visited.Search((*searchIt).Opposite(current)))
		{
			++searchIt;
		}
		else
		{
			discovery.InsertBack(*searchIt);
			found = DFS(discovery, (*searchIt).Opposite(current));
			++searchIt;
		}
	}

	return found;
}


#endif /* GRAPH_H_ */
