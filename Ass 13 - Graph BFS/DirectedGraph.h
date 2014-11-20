/*************************************************************************
 * AUTHOR      : James Marcu
 * STUDENT ID  : 374443
 * ASS #      : 
 * CLASS       : CS1D
 * SECTION     : TTh 3:30 AM
 * DUE DATE    : 
 *************************************************************************/
#ifndef DIRECTEDGRAPH_H_
#define DIRECTEDGRAPH_H_

#include "List.h"
#include "Stack.h"
#include <iostream>
using namespace std;

template <typename ElemType>
class Vertex
{
	public:
		Vertex()
			{position = -1;}
		Vertex(const ElemType& elemInit, int posInit)
			{element = elemInit; position = posInit;}

		const ElemType& GetElem() const
			{return element;}
		int       GetPosition() const
			{return position;}
		bool operator==(const Vertex<ElemType>& compareTo) const
			{return element != compareTo.GetElem();}
		bool operator!=(const Vertex<ElemType>& compareTo) const
			{return element != compareTo.GetElem();}

	private:
		ElemType element;
		int      position;
};

template <typename ElemType>
class DirectedEdge
{
	public:
		DirectedEdge()
			{origin = NULL; destination = NULL; weight = 0;}
		DirectedEdge(const Vertex<ElemType>* originInit, const Vertex<ElemType>* destInit, int weightInit)
			{origin = originInit; destination = destInit; weight = weightInit;}

		const Vertex<ElemType>* GetOrigin() const
			{return origin;}
		const Vertex<ElemType>* GetDestination() const
			{return destination;}
		int GetWeight() const
			{return weight;}

	private:
		const Vertex<ElemType>* origin;
		const Vertex<ElemType>* destination;
		int weight;
};

template <typename ElemType>
class DirectedGraph
{
	public:
		DirectedGraph();

		const Vertex<ElemType>* GetVertex(const ElemType& key);
		void DFS(const Vertex<ElemType>* start,
                 List<DirectedEdge<ElemType>* >& discoveryEdges,
                 List<DirectedEdge<ElemType>* >& backEdges,
                 List<DirectedEdge<ElemType>* >& crossEdges,
                 List<DirectedEdge<ElemType>* >& forwardEdges,
                 bool& isStronglyConnected = false) const;
		bool IsStronglyConnected(const Vertex<ElemType>* start) const;
		void BFS(const Vertex<ElemType>* start) const;
		void PrintBFS(const List<List<const Vertex<ElemType>* > >& toPrint) const;
		void PrintPositions() const;
		void PrintMatrix() const;

		void AddVertex(const ElemType& elemInit);
		void AddEdge(const Vertex<ElemType>* origin, const Vertex<ElemType>* destination, int weight);
		void EraseVertex(Vertex<ElemType>* toErase);
		void EraseEdge(DirectedEdge<ElemType>* toErase);

	private:
		List<Vertex<ElemType> > vertexList;
		List<DirectedEdge<ElemType> > edgeList;
		DirectedEdge<ElemType>*** adjacencyMatrix;
		int  size;

		void IncrementMatrix();
};

template <typename ElemType>
DirectedGraph<ElemType>::DirectedGraph()
{
	size = 0;

	adjacencyMatrix    = new DirectedEdge<ElemType>**[0];
	adjacencyMatrix[0] = new DirectedEdge<ElemType>* [0];
}

template <typename ElemType>
const Vertex<ElemType>* DirectedGraph<ElemType>::GetVertex(const ElemType& key)
{
	typename List<Vertex<ElemType> >::Iterator searchIt;
	bool found;
	bool endOfSearch;

	searchIt    = vertexList.Begin();
	found       = false;
	endOfSearch = false;

	while (!found && !endOfSearch)
	{
		if(searchIt != vertexList.End())
		{
			if(searchIt->GetElem().GetElem() == key)
			{
				found = true;
			}
			else
			{
				++searchIt;
			}
		}
		else
		{
			endOfSearch = true;
		}
	}

	if(found)
	{
		return &(*searchIt);
	}
	else
	{
		return NULL;
	}
};

template <typename ElemType>
void DirectedGraph<ElemType>::DFS(const Vertex<ElemType>* start,
        						  List<DirectedEdge<ElemType>* >& discoveryEdges,
        						  List<DirectedEdge<ElemType>* >& backEdges,
        						  List<DirectedEdge<ElemType>* >& crossEdges,
        						  List<DirectedEdge<ElemType>* >& forwardEdges,
        						  bool& isStronglyConnected) const
{
	List<const Vertex<ElemType>* >  unvisited;
	List<const Vertex<ElemType>* >  active;
	List<DirectedEdge<ElemType>* >  visitedEdges;
	typename List<DirectedEdge<ElemType>* >::Iterator edgeIt;
	Stack<const Vertex<ElemType>* > history;
	const Vertex<ElemType>*   currentVertex;
	const Vertex<ElemType>*   nextVertex;
	DirectedEdge<ElemType>*   edgePtr;
	bool                      searchForVertex;
	bool                      deadEnd;
	int                       index;
	int                       edgeTimeCount;
	int                       edgeTimeOne;
	int                       edgeTimeTwo;

	typename List<Vertex<ElemType> >::Iterator vertexIt;
	vertexIt = vertexList.Begin();
	const Vertex<ElemType>** vertexAuxPtr;
	while(vertexIt != vertexList.End())
	{
		vertexAuxPtr = new const Vertex<ElemType>*(&(*vertexIt));
		unvisited.InsertBack(*vertexAuxPtr);
		++vertexIt;
	}

	currentVertex = start;
	active.InsertBack(start);

	history.Push(start);
	unvisited.Erase(start);

	while (!history.Empty())
	{
		searchForVertex = true;
		deadEnd         = false;
		index           = 0;

		while (searchForVertex)
		{
			if (index >= size)
			{
				searchForVertex = false;
				deadEnd         = true;
			}
			else if(adjacencyMatrix[currentVertex->GetPosition()][index] != NULL)
			{
				edgePtr = adjacencyMatrix[currentVertex->GetPosition()][index];
				nextVertex = edgePtr->GetDestination();

				if (unvisited.Search(nextVertex) != unvisited.End())
				{
					discoveryEdges.InsertBack(edgePtr);
					visitedEdges.InsertBack(edgePtr);

					history.Push(nextVertex);
					unvisited.Erase(nextVertex);
					active.InsertBack(nextVertex);

					currentVertex = nextVertex;

					searchForVertex = false;
				}
				else if (visitedEdges.Search(edgePtr) == visitedEdges.End())
				{
					if(active.Search(edgePtr->GetDestination()) == active.End())
					{
						edgeTimeCount = 0;
						edgeTimeOne   = visitedEdges.Size() + 1;
						edgeTimeTwo   = -1;
						edgeIt = visitedEdges.Begin();

						while(edgeTimeTwo < 0)
						{
							if((*edgeIt)->GetDestination() == edgePtr->GetDestination())
							{
								edgeTimeTwo = edgeTimeCount;
							}
							else
							{
								++edgeTimeCount;
								++edgeIt;
							}
						}

						if (edgeTimeOne < edgeTimeTwo)
						{
							crossEdges.InsertBack(edgePtr);
							visitedEdges.InsertBack(edgePtr);
						}
						else
						{
							forwardEdges.InsertBack(edgePtr);
							visitedEdges.InsertBack(edgePtr);
						}
					}
					else
					{
						backEdges.InsertBack(edgePtr);
						visitedEdges.InsertBack(edgePtr);
					}

				}
			}

			++index;
		}

		if(deadEnd)
		{
			active.Erase(history.Peek());

			history.Pop();

			if(!history.Empty())
			{
				currentVertex = history.Peek();
			}
			else
			{
				currentVertex = NULL;
			}
		}
	}

	if (isStronglyConnected)
	{
		if(unvisited.Empty())
		{
			isStronglyConnected = IsStronglyConnected(start);
		}
		else
		{
			isStronglyConnected = false;
		}
	}
}

template <typename ElemType>
bool DirectedGraph<ElemType>::IsStronglyConnected(const Vertex<ElemType>* start) const
{
	bool stronglyConnected;

	List<const Vertex<ElemType>* >  unvisited;
	Stack<const Vertex<ElemType>* > history;
	const Vertex<ElemType>*   currentVertex;
	const Vertex<ElemType>*   nextVertex;
	bool                      searchForVertex;
	bool                      deadEnd;
	int                       index;
	DirectedEdge<ElemType>*** revMatrix;

	revMatrix = new DirectedEdge<ElemType>**[size];
	for (int i = 0; i < size; ++i)
	{
		revMatrix[i] = new DirectedEdge<ElemType>*[size];
		for (int j = 0; j < size; j++)
		{
			revMatrix[i][j] = adjacencyMatrix[j][i];
		}
	}

	typename List<Vertex<ElemType> >::Iterator it;
	it = vertexList.Begin();
	const Vertex<ElemType>** auxPtr;
	while(it != vertexList.End())
	{
		auxPtr = new const Vertex<ElemType>*(&(*it));
		unvisited.InsertBack(*auxPtr);
		++it;
	}

	currentVertex = start;

	history.Push(start);
	unvisited.Erase(start);

	while (!history.Empty())
	{
		searchForVertex = true;
		deadEnd         = false;
		index           = 0;

		while (searchForVertex)
		{
			if (index >= size)
			{
				searchForVertex = false;
				deadEnd         = true;
			}
			else if(revMatrix[currentVertex->GetPosition()][index] != NULL)
			{
				nextVertex = revMatrix[currentVertex->GetPosition()][index]->GetOrigin();

				if (unvisited.Search(nextVertex) != unvisited.End())
				{
					history.Push(nextVertex);
					unvisited.Erase(nextVertex);

					currentVertex = nextVertex;

					searchForVertex = false;
				}
			}

			++index;
		}

		if(deadEnd)
		{
			history.Pop();

			if(!history.Empty())
			{
				currentVertex = history.Peek();
			}
			else
			{
				currentVertex = NULL;
			}
		}
	}

	stronglyConnected = unvisited.Empty();

	for (int i = 0; i < size-1; ++i)
	{
		delete[] revMatrix[i];
	}
	delete[] revMatrix;

	return stronglyConnected;
}

template <typename ElemType>
void DirectedGraph<ElemType>::BFS(const Vertex<ElemType>* start) const
{
	List<const Vertex<ElemType>* >  unvisited;
	List<List<const Vertex<ElemType>* > > masterList;
	List<const Vertex<ElemType>* >* currentLevel;
	List<const Vertex<ElemType>* >* nextLevel;
	const Vertex<ElemType>*         insertPtr;
	bool                            keepGoing;
	typename List<const Vertex<ElemType>* >::Iterator levelIt;

	keepGoing = true;

	typename List<Vertex<ElemType> >::Iterator it;
	it = vertexList.Begin();
	const Vertex<ElemType>** auxPtr;
	while(it != vertexList.End())
	{
		auxPtr = new const Vertex<ElemType>*(&(*it));
		unvisited.InsertBack(*auxPtr);
		++it;
	}

	currentLevel = new List<const Vertex<ElemType>* >;
	currentLevel->InsertBack(start);
	masterList.InsertBack(*currentLevel);
	unvisited.Erase(start);

	while(keepGoing)
	{
		keepGoing = false;
		levelIt = currentLevel->Begin();
		nextLevel = new List<const Vertex<ElemType>* >;
		while(levelIt != currentLevel->End())
		{
			for(int index = 0; index < size; ++index)
			{
				if (adjacencyMatrix[(*levelIt)->GetPosition()][index] != NULL)
				{
					insertPtr = adjacencyMatrix[(*levelIt)->GetPosition()][index]->GetDestination();

					if(unvisited.Search(insertPtr) != unvisited.End())
					{
						nextLevel->InsertBack(insertPtr);
						unvisited.Erase(insertPtr);

						keepGoing = true;
					}
				}
			}

			++levelIt;
		}

		if(keepGoing)
		{
			masterList.InsertBack(*nextLevel);
			currentLevel = nextLevel;
		}
	}

	PrintBFS(masterList);
}

template <typename ElemType>
void DirectedGraph<ElemType>::PrintBFS(const List<List<const Vertex<ElemType>* > >& toPrint) const
{
	int level;
	typename List<List<const Vertex<ElemType>* > >::Iterator    masterIt;
	typename List<const Vertex<ElemType>* >::Iterator listIt;

	level = 0;
	masterIt = toPrint.Begin();

	while(masterIt != toPrint.End())
	{
		cout << "Level " << level << " -\n";

		listIt   = (*masterIt).Begin();

		while(listIt != (*masterIt).End())
		{
			cout << (*listIt)->GetElem();
			++listIt;

			if(listIt != (*masterIt).End())
			{
				cout << ", ";
			}
			else
			{
				cout << endl << endl;
			}
		}

		++level;
		++masterIt;
	}
}

template <typename ElemType>
void DirectedGraph<ElemType>::IncrementMatrix()
{
	DirectedEdge<ElemType>*** matrix;

	matrix = new DirectedEdge<ElemType>**[size];
	for (int i = 0; i < size; ++i)
	{
		matrix[i] = new DirectedEdge<ElemType>*[size];
		for (int j = 0; j < size; j++)
		{
			matrix[i][j] = NULL;
		}
	}

	for (int i = 0; i < size-1; ++i)
	{
		for (int j = 0; j < size-1; ++j)
		{
			matrix[i][j] = adjacencyMatrix[i][j];
		}
	}

	for (int i = 0; i < size-1; ++i)
	{
		for (int j = 0; j < size-1; ++j)
		{
			delete[] adjacencyMatrix[i][j];
		}
		delete[] adjacencyMatrix[i];
	}
	delete[] adjacencyMatrix;

	adjacencyMatrix = matrix;
}

template <typename ElemType>
void DirectedGraph<ElemType>::AddVertex(const ElemType& elemInit)
{
	Vertex<ElemType>* addPtr;

	++size;
	addPtr = new Vertex<ElemType>(elemInit, size - 1);

	vertexList.InsertBack(*addPtr);;
	IncrementMatrix();
}

template <typename ElemType>
void DirectedGraph<ElemType>::AddEdge(const Vertex<ElemType>* origin, const Vertex<ElemType>* destination, int weight)
{
	DirectedEdge<ElemType>* addPtr;

	addPtr = new DirectedEdge<ElemType>(origin, destination, weight);

	edgeList.InsertBack(*addPtr);

	adjacencyMatrix[origin->GetPosition()][destination->GetPosition()] = addPtr;
}

template <typename ElemType>
void DirectedGraph<ElemType>::PrintPositions() const
{
	typename List<Vertex<ElemType> >::Iterator it;

	it = vertexList.Begin();

	while(it != vertexList.End())
	{
		cout << (*it).GetElem() << ": " << (*it).GetPosition() << endl;
		++it;
	}
}

template <typename ElemType>
void DirectedGraph<ElemType>::PrintMatrix() const
{
	for (int i = 0; i < size; ++i)
	{
		for(int j = 0; j < size; ++j)
		{
			if(adjacencyMatrix[i][j] != NULL)
			{
				cout << adjacencyMatrix[i][j]->GetDestination()->GetElem();
			}
			else
			{
				cout << "NULL";
			}
			cout << "  ";
		}
		cout << endl;
	}
}

#endif /* DIRECTEDGRAPH_H_ */
