/*************************************************************************
 * AUTHOR      : James Marcu
 * STUDENT ID  : 374443
 * ASS #12     : Graphs
 * CLASS       : CS1D
 * SECTION     : TTh 3:30 AM
 * DUE DATE    : 11/13/2014
 *************************************************************************/
#ifndef GRAPHEDGE_H_
#define GRAPHEDGE_H_

#include "List.h"

template <typename ElemType>
class Vertex;

template <typename ElemType>
class Edge
{
	public:
		Edge();
		Edge(Vertex<ElemType>* oneInit,
			 Vertex<ElemType>* twoInit,
			 int               weightInit);

		void EndVerteces(Vertex<ElemType>** arr) const;
		Vertex<ElemType>*  Opposite(const Vertex<ElemType>& oppOf) const;
		bool               IsAdjacentTo(const Edge<ElemType>& check) const;
		bool               IsIncidentTo(const Vertex<ElemType>& check) const;
		int                GetWeight() const;

	private:
		Vertex<ElemType>* vertexOne;
		Vertex<ElemType>* vertexTwo;
		int               weight;
};

template <typename ElemType>
Edge<ElemType>::Edge()
{
	vertexOne = NULL;
	vertexTwo = NULL;
	weight    = -1;
}

template <typename ElemType>
Edge<ElemType>::Edge(Vertex<ElemType>* oneInit,
					 Vertex<ElemType>* twoInit,
					 int               weightInit)
{
	vertexOne = oneInit;
	vertexTwo = twoInit;
	weight    = weightInit;
}

template <typename ElemType>
void Edge<ElemType>::EndVerteces(Vertex<ElemType>** arr) const
{
	arr[0] = vertexOne;
	arr[1] = vertexTwo;
}

template <typename ElemType>
Vertex<ElemType>* Edge<ElemType>::Opposite(const Vertex<ElemType>& oppOf) const
{
	if(oppOf == vertexOne)
	{
		return vertexTwo;
	}
	else if (oppOf == vertexTwo)
	{
		return vertexOne;
	}
	else
	{
		return NULL;
	}
}

template <typename ElemType>
bool Edge<ElemType>::IsAdjacentTo(const Edge<ElemType>& check) const
{
	return (*(vertexOne->IncidentEdges()->Search(check)) != NULL) ||
		   (*(vertexTwo->IncidentEdges()->Search(check)) != NULL);
}

template <typename ElemType>
bool Edge<ElemType>::IsIncidentTo(const Vertex<ElemType>& check) const
{
	return vertexOne == check || vertexTwo == check;
}

template <typename ElemType>
int Edge<ElemType>::GetWeight() const
{
	return weight;
}

template <typename ElemType>
class Vertex
{
	public:
		Vertex();
		Vertex(const ElemType& elemInit);

		const ElemType&   operator*() const;
		const List<Edge<ElemType> >& IncidentEdges() const;
		bool        IsAdjacentTo(const Vertex<ElemType>& check) const;

		void AddEdge(Edge<ElemType>& newEdge);
		void RemoveEdge(const Edge<ElemType>& toDelete);

	private:
		ElemType    element;
		List< Edge<ElemType> >* edgeList;
};

template <typename ElemType>
Vertex<ElemType>::Vertex()
{
	edgeList = NULL;
}

template <typename ElemType>
Vertex<ElemType>::Vertex(const ElemType& elemInit)
{
	element  = elemInit;
	edgeList = new List<Edge<ElemType> >;
}

template <typename ElemType>
const ElemType& Vertex<ElemType>::operator*() const
{
	return element;
}

template <typename ElemType>
const List<Edge<ElemType> >& Vertex<ElemType>::IncidentEdges() const
{
	return &edgeList;
}

template <typename ElemType>
bool Vertex<ElemType>::IsAdjacentTo(const Vertex<ElemType>& check) const
{
	bool keepSearching;
	typename List<Edge<ElemType> >::Iterator searchIt;

	keepSearching = true;
	searchIt      = edgeList->Begin();

	while(keepSearching)
	{
		if(searchIt != edgeList->End())
		{
			if(searchIt->IsIncidentTo(check))
			{
				keepSearching = false;
			}
			else
			{
				++searchIt;
			}
		}
		else
		{
			keepSearching = false;
		}
	}

	return searchIt() == edgeList->End();
}

template <typename ElemType>
void Vertex<ElemType>::AddEdge(Edge<ElemType>& newEdge)
{
	edgeList->InsertBack(newEdge);
}

template <typename ElemType>
void Vertex<ElemType>::RemoveEdge(const Edge<ElemType>& toDelete)
{
	edgeList->Erase(toDelete);
}

#endif /* GRAPHEDGE_H_ */
