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

//A vertex for a graph.
template <typename ElemType>
class Vertex
{
	public:
	   /*******************************************
	    * * * * CONSTRUCTORS AND DESTRUCTOR * * * *
	    *******************************************/
		Vertex()                                     //Default
			{position = -1;}
		Vertex(const ElemType& elemInit, int posInit)//Initializes the
			{element = elemInit; position = posInit;}//data and position.

	   /*******************************************
		* * * *          ACCESSORS          * * * *
		*******************************************/
		const ElemType& GetElem() const//Returns the vertex's element.
			{return element;}
		int GetPosition() const        //Returns the position of the vertex.
			{return position;}
		//These operators are overloaded to compare the verteces' elements.
		bool operator==(const Vertex<ElemType>& compareTo) const
			{return element != compareTo.GetElem();}
		bool operator!=(const Vertex<ElemType>& compareTo) const
			{return element != compareTo.GetElem();}

	private:
		ElemType element; //The data stored in the vertex.
		int      position;//The position of the vertex, used in the
		                  //adjacenecy matrix.
};

//A directed edge for a graph.
template <typename ElemType>
class Edge
{
	public:
	   /*******************************************
	    * * * * CONSTRUCTORS AND DESTRUCTOR * * * *
	    *******************************************/
		Edge()                                      //Default constructor
			{firstVertex = NULL; secondVertex = NULL; weight = 0;}
		Edge(const Vertex<ElemType>* vertOne,    //Initializes
		     const Vertex<ElemType>* vertTwo,      //values of edge.
		     float weightInit)
			{firstVertex = vertOne; secondVertex = vertTwo; weight = weightInit;}
		~Edge()
			{firstVertex = NULL; secondVertex = NULL;}

	   /*******************************************
		* * * *          ACCESSORS          * * * *
		*******************************************/
		const Vertex<ElemType>* Opposite(const Vertex<ElemType>* oppOf) const
			{if(oppOf == firstVertex)
				return secondVertex;
			 else if(oppOf == secondVertex)
			    return firstVertex;
			 else
			    return NULL;}
		const Vertex<ElemType>** EndVertices() const
		{
			const Vertex<ElemType>** vertArr = new const Vertex<ElemType>*[2];
			vertArr[0] = firstVertex;
			vertArr[1] = secondVertex;
			return vertArr;
		}
		int GetWeight() const                         //Returns edge's weight.
			{return weight;}
		bool IsIncidentTo(const Vertex<ElemType>* v) const
			{return v == firstVertex || v == secondVertex;}

	private:
		const Vertex<ElemType>* firstVertex;     //Where the edge is coming from.
		const Vertex<ElemType>* secondVertex;//Where the edge is going to.
		float weight;                         //Weight of the edge.
};

template <typename ElemType>
class Graph
{
	public:
	   /*******************************************
	    * * * * CONSTRUCTORS AND DESTRUCTOR * * * *
	    *******************************************/
		Graph();//Default
		~Graph();


	   /*******************************************
		* * * *          ACCESSORS          * * * *
		*******************************************/
		//Returns a pointer to a vertex with the provided search key.
		const Vertex<ElemType>* GetVertex(const ElemType& key);

		//A depth first search.
		void DFS(const Vertex<ElemType>* start,
                 List<Edge<ElemType>* >& discoveryEdges,
                 List<Edge<ElemType>* >& backEdges,
                 List<Edge<ElemType>* >& crossEdges,
                 List<Edge<ElemType>* >& forwardEdges,
                 bool& isStronglyConnected = false) const;

		//Returns true if the graph is strongly connected.
		bool IsStronglyConnected(const Vertex<ElemType>* start) const;

		//A breadth first search.
		void BFS(const Vertex<ElemType>* start) const;

		void ShortestPath(const Vertex<ElemType>* start,
				List<const Vertex<ElemType>*> destinations,
				Stack<const Vertex<ElemType>* >& vertexStack,
				Stack<const Edge<ElemType>* >& edgeStack) const;


	   /*******************************************
		* * * *          MUTATORS           * * * *
		*******************************************/
		//Adds a vertex to the graph.
		void AddVertex(const ElemType& elemInit);

		void AddVertex(const Vertex<ElemType>& toAdd);

		//Adds an edge to the graph.
		void AddEdge(const Vertex<ElemType>* vertOne,
				     const Vertex<ElemType>* vertTwo,
				     float weight);

		void AddEdge(Edge<ElemType>& toAdd);

		//Erases a vertex from the graph.
		void EraseVertex(Vertex<ElemType>* toErase);

		//Erases an edge from the graph.
		void EraseEdge(Edge<ElemType>* toErase);

	private:
	   /*******************************************
		* * * *         VARIABLES           * * * *
		*******************************************/
		List<Vertex<ElemType> > vertexList;       //List of verteces.
		List<Edge<ElemType> > edgeList;   //List of edges.
		Edge<ElemType>*** adjacencyMatrix;//Adjacency matrix.
		int  size;                                //Number of verteces.

	   /*******************************************
		* * * *          ACCESSORS          * * * *
		*******************************************/
		//Prints the results of a BFS to the console.
		void PrintBFS(const List<List<const Vertex<ElemType>* > >& toPrint) const;


	   /*******************************************
		* * * *          MUTATORS           * * * *
		*******************************************/
		//Increases the size of the adjacency matrix by one.
		void IncrementMatrix();

};

/*************************************************************************
 * METHOD Constructor
 * ______________________________________________________________________
 * Default constructor.
 * ______________________________________________________________________
 * PRE-CONDITIONS -
 *  <none>
 *
 * POST-CONDITIONS -
 * 	Instantiates a directed graph.
 *************************************************************************/
template <typename ElemType>
Graph<ElemType>::Graph()
{
	size = 0;

	adjacencyMatrix    = new Edge<ElemType>**[0];
	adjacencyMatrix[0] = new Edge<ElemType>* [0];
}

template <typename ElemType>
Graph<ElemType>::~Graph()
{
	cout << "GRAPH";
	cin.ignore(1000, '\n');

	for (int i = 0; i < size; ++i)
	{
		delete[] adjacencyMatrix[i];
	}
	delete[] adjacencyMatrix;
	adjacencyMatrix = NULL;
}

/*************************************************************************
 * METHOD GetVertex
 * ______________________________________________________________________
 * Returns a pointer to a vertex in directed graph whose element matches
 * the provided search key.
 * ______________________________________________________________________
 * PRE-CONDITIONS -
 *  key : The element that you are searching the graph for.
 *
 * POST-CONDITIONS -
 * 	Returns a pointer to the matching vertex, or NULL if not found.
 *************************************************************************/
template <typename ElemType>
const Vertex<ElemType>* Graph<ElemType>::GetVertex(const ElemType& key)
{
	//VARIABLE DECLERATIONS
	//PROC & OUT - Searches the vertex list.
	typename List<Vertex<ElemType> >::Iterator searchIt;
	bool found;      //PROC - If the vertex is found yet.
	bool endOfSearch;//PROC - If all verteces have been searched.

	//VARIABLE INITIALIZATIONS
	searchIt    = vertexList.Begin();
	found       = false;
	endOfSearch = false;

	/*********************************************************************
	 * PROC - Searches until either a matching vertex is found or all
	 *        verteces have been searched.
	 *********************************************************************/
	while (!found && !endOfSearch)
	{
		//First checks if we're at the end of the vertex list. If we are
		//then end the search. Otherwise check the current vertex.
		if(searchIt != vertexList.End())
		{
			//If it matches the key then set found to true.
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

	//If the key was found then return a pointer to it. Otherwise return
	//NULL.
	if(found)
	{
		return &(*searchIt);
	}
	else
	{
		return NULL;
	}
};

/*************************************************************************
 * METHOD DFS
 * ______________________________________________________________________
 * Performs a depth first search on the graph and returns all relevant
 * information.
 * ______________________________________________________________________
 * PRE-CONDITIONS -
 *  start               : Points to the first vertex in the search.
 *  discoveryEdges      : A list for storing edges.
 *  backEdges           : A list for storing edges.
 *  crossEdges          : A list for storing edges.
 *  forwardEdges        : A list for storing edges.
 *  isStronglyConnected : Will store if the graph is strongly connected.
 *                        If this field is not provided the check will not
 *                        be done.
 *
 * POST-CONDITIONS -
 *  discoveryEdges      : All discovery edges will have been added to the list.
 *  backEdges           : All back edges will have been added to the list.
 *  crossEdges          : All cross edges will have been added to the list.
 *  forwardEdges        : All forward edges will have been added to the list.
 *  isStronglyConnected : If the graph is strongly connected.
 *************************************************************************/
template <typename ElemType>
void Graph<ElemType>::DFS(const Vertex<ElemType>* start,
        						  List<Edge<ElemType>* >& discoveryEdges,
        						  List<Edge<ElemType>* >& backEdges,
        						  List<Edge<ElemType>* >& crossEdges,
        						  List<Edge<ElemType>* >& forwardEdges,
        						  bool& isStronglyConnected) const
{
	/*********************************************************************
	 * VARIABLE DECLERATIONS
	 *********************************************************************/
	//PROC - List of all unvisited nodes.
	List<const Vertex<ElemType>* >  unvisited;

	//PROC - List of all 'active' nodes. Nodes are active if they or their
	//       ancestors are being visited.
	List<const Vertex<ElemType>* >  active;

	//PROC - List of all edges which have been looked at.
	List<Edge<ElemType>* >  visitedEdges;

	//PROC - Used to traverse lists of edges.
	typename List<Edge<ElemType>* >::Iterator edgeIt;

	//PROC - A stack of visited nodes. Used to backtrack.
	Stack<const Vertex<ElemType>* > history;

	//PROC - Points to the vertex currently being visited.
	const Vertex<ElemType>*   currentVertex;

	//PROC - Points to the vertex which will be visited next.
	const Vertex<ElemType>*   nextVertex;

	//PROC - Used to point at edges for inspection.
	Edge<ElemType>*   edgePtr;

	//PROC - Whether all connected vertex's of the current vertex have been
	//       checked yet.
	bool searchForVertex;

	//PROC - Whether the current vertex was a dead end.
	bool deadEnd;

	//PROC - Used to access the adjacency matrix.
	int  index;

	//PROC - Stores an edge's position in visitedEdges.
	int  edgeTimeCount;

	//PROC - These keep track of the position of two edges in visitedEdges.
	int  edgeTimeOne;
	int  edgeTimeTwo;

	/*********************************************************************
	 * PROC - Instantiates unvisited, a list of pointers to all unvisited
	 *        verteces.
	 *********************************************************************/
	typename List<Vertex<ElemType> >::Iterator vertexIt;
	vertexIt = vertexList.Begin();
	const Vertex<ElemType>** vertexAuxPtr;
	while(vertexIt != vertexList.End())
	{
		vertexAuxPtr = new const Vertex<ElemType>*(&(*vertexIt));
		unvisited.InsertBack(*vertexAuxPtr);
		++vertexIt;
	}

	/*********************************************************************
	 * PROC - Sets up the initial conditions of the search.
	 *********************************************************************/
	currentVertex = start;
	active.InsertBack(start);
	history.Push(start);
	unvisited.Erase(start);

	/*********************************************************************
	 * PROC - The search continues until history is empty. This indicates
	 *        all connected verteces have been visited.
	 *********************************************************************/
	while (!history.Empty())
	{
		//Reset variables at the top of the loop.
		searchForVertex = true;
		deadEnd         = false;
		index           = 0;

		//Will search for an unvisited vertex connected to the current
		//vertex.
		while (searchForVertex)
		{
			//If we have checked every index of the adjacency matrix then
			//this is a dead end.
			if (index >= size)
			{
				searchForVertex = false;
				deadEnd         = true;
			}
			//If there is an edge at this index...
			else if(adjacencyMatrix[currentVertex->GetPosition()][index] != NULL)
			{
				//Set edgePtr to point at the edge and nextVertex to point
				//at its destination.
				edgePtr = adjacencyMatrix[currentVertex->GetPosition()][index];
				nextVertex = edgePtr->GetDestination();

				//If the destination has not been visited yet...
				if (unvisited.Search(nextVertex) != unvisited.End())
				{
					//The edge is a discvoery edge.
					discoveryEdges.InsertBack(edgePtr);
					visitedEdges.InsertBack(edgePtr);

					//Add the next vertex to history, remove it from
					//unvisited, and add it to active.
					history.Push(nextVertex);
					unvisited.Erase(nextVertex);
					active.InsertBack(nextVertex);

					//Update current vertex to point at the new vertex.
					currentVertex = nextVertex;

					//We're done searching this vertex for now.
					searchForVertex = false;
				}
				//If the vertex had been visited, but we haven't tried this
				//edge before...
				else if (visitedEdges.Search(edgePtr) == visitedEdges.End())
				{
					//If the destination of the edge is not active then
					//it is either a cross or forward edge.
					if(active.Search(edgePtr->GetDestination()) == active.End())
					{
						//Reset variables.
						edgeTimeCount = 0;
						edgeTimeOne   = visitedEdges.Size() + 1;
						edgeTimeTwo   = -1;
						edgeIt = visitedEdges.Begin();

						//Discover when the destination was visited.
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

						//If the destination was visited before the current
						//node it is a cross edge. Otherwise it is a
						//forward edge.
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
					//If, however, the destination vertex is still active
					//then this is a back edge.
					else
					{
						backEdges.InsertBack(edgePtr);
						visitedEdges.InsertBack(edgePtr);
					}

				}
			}

			//Check the next index in vertex's adjacency matrix.
			++index;
		}

		//If the last vertex was a dead end...
		if(deadEnd)
		{
			//The current vertex is no longer active.
			active.Erase(history.Peek());

			//Remove it from history.
			history.Pop();

			//The current vertex is now the old one's parent.
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

	//If the user provided a variable for isStrongly connected then run
	//a check for that.
	if (isStronglyConnected)
	{
		//If unvisited is not empty then the graph is not strongly connected.
		//If it is, we have to check again with all edges reversed.
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
bool Graph<ElemType>::IsStronglyConnected(const Vertex<ElemType>* start) const
{
	bool stronglyConnected;

	List<const Vertex<ElemType>* >  unvisited;
	Stack<const Vertex<ElemType>* > history;
	const Vertex<ElemType>*   currentVertex;
	const Vertex<ElemType>*   nextVertex;
	bool                      searchForVertex;
	bool                      deadEnd;
	int                       index;
	Edge<ElemType>*** revMatrix;

	revMatrix = new Edge<ElemType>**[size];
	for (int i = 0; i < size; ++i)
	{
		revMatrix[i] = new Edge<ElemType>*[size];
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
void Graph<ElemType>::BFS(const Vertex<ElemType>* start) const
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
void Graph<ElemType>::PrintBFS(const List<List<const Vertex<ElemType>* > >& toPrint) const
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

//Assumes graph is connected
template <typename ElemType>
void Graph<ElemType>::ShortestPath(const Vertex<ElemType>* start, List<const Vertex<ElemType>*> destinations, Stack<const Vertex<ElemType>* >& vertexStack, Stack<const Edge<ElemType>* >& edgeStack) const
{
	float costMatrix[size];

	Tree<const Vertex<ElemType>* > pathTree;
	const Vertex<ElemType>*      parentVertex;
	TreeNode<const Vertex<ElemType>* >* treePtr;
	bool findNextDest;

	List<const Vertex<ElemType>* > visitedVertices;
	typename List<const Vertex<ElemType>* >::Iterator visitedIt;

	List<const Vertex<ElemType>* > activeVertices;
	typename List<const Vertex<ElemType>* >::Iterator activeIt;

	List<const Edge<ElemType>* >   visitedEdges;
	typename List<const Edge<ElemType>* >::Iterator edgeIt;

	List<const Edge<ElemType>* > peripheralEdges;

	Edge<ElemType>* newEdge;
	const Vertex<ElemType>* removeFromActive;
	float newVertCost;
	const Vertex<ElemType>* newVertex;

	bool stillActive;

	costMatrix[start->GetPosition()] = 0;
	visitedVertices.InsertBack(start);
	activeVertices.InsertBack(start);
	pathTree.Add(start, NULL);

	if(destinations.Search(start) != destinations.End())
	{
		destinations.Erase(start);
	}

	findNextDest = !destinations.Empty();

	while(findNextDest)
	{
		activeIt    = activeVertices.Begin();
		newVertCost = 32000;

		while(activeIt != activeVertices.End())
		{
			stillActive = false;

			for(int i = 0; i < size; ++i)
			{
				if(adjacencyMatrix[(*activeIt)->GetPosition()][i] != NULL)
				{
					if(visitedVertices.Search(adjacencyMatrix[(*activeIt)->GetPosition()][i]->Opposite(*activeIt)) == visitedVertices.End())
					{

						stillActive = true;

						if(costMatrix[(*activeIt)->GetPosition()] + (adjacencyMatrix[(*activeIt)->GetPosition()][i])->GetWeight() < newVertCost)
						{
							parentVertex = *activeIt;
							newEdge = adjacencyMatrix[(*activeIt)->GetPosition()][i];
							newVertex = newEdge->Opposite(*activeIt);
							newVertCost = costMatrix[(*activeIt)->GetPosition()] + (adjacencyMatrix[(*activeIt)->GetPosition()][i])->GetWeight();
						}
					}
				}
			}

			if(!stillActive)
			{
				removeFromActive = (*activeIt);
				++activeIt;
				activeVertices.Erase(removeFromActive);
			}
			else
			{
				++activeIt;
			}
		}

		costMatrix[newVertex->GetPosition()] = newVertCost;
		visitedVertices.InsertBack(newVertex);
		activeVertices.InsertBack(newVertex);
		visitedEdges.InsertBack(newEdge);
		pathTree.Add(newVertex, pathTree.Search(parentVertex));


		/*********************************************************************
		 * If the new vertex is a destination, then...
		 *********************************************************************/
		if(destinations.Search(newVertex) != destinations.End())
		{
			treePtr = pathTree.Search(newVertex);
			edgeIt = visitedEdges.End();
			--edgeIt;

			while(treePtr != pathTree.GetRoot())
			{
				while(!(*edgeIt)->IsIncidentTo(treePtr->GetElem()) ||
				      !(*edgeIt)->IsIncidentTo(treePtr->GetParent()->GetElem()))
				{
					--edgeIt;
				}

				edgeStack.Push((*edgeIt));
				vertexStack.Push(treePtr->GetElem());

				treePtr = treePtr->GetParent();
			}

			destinations.Erase(newVertex);
			findNextDest = false;
		}//END if(destinations.Search(newVertex) != destinations.End())
	}//END while(findNextDest)

	if(!destinations.Empty())
	{
		ShortestPath(newVertex, destinations, vertexStack, edgeStack);
	}

	vertexStack.Push(start);
}

template <typename ElemType>
void Graph<ElemType>::IncrementMatrix()
{
	Edge<ElemType>*** matrix;

	matrix = new Edge<ElemType>**[size];
	for (int i = 0; i < size; ++i)
	{
		matrix[i] = new Edge<ElemType>*[size];
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
void Graph<ElemType>::AddVertex(const ElemType& elemInit)
{
	Vertex<ElemType>* addPtr;

	++size;
	addPtr = new Vertex<ElemType>(elemInit, size - 1);

	vertexList.InsertBack(*addPtr);
	IncrementMatrix();
}

template <typename ElemType>
void Graph<ElemType>::AddVertex(const Vertex<ElemType>& toAdd)
{
	++size;

	vertexList.InsertBack(toAdd);
	IncrementMatrix();
}

template <typename ElemType>
void Graph<ElemType>::AddEdge(const Vertex<ElemType>* vertOne, const Vertex<ElemType>* vertTwo, float weight)
{
	Edge<ElemType>* addPtr;

	addPtr = new Edge<ElemType>(vertOne, vertTwo, weight);

	edgeList.InsertBack(*addPtr);

	adjacencyMatrix[vertOne->GetPosition()][vertTwo->GetPosition()] = addPtr;
	adjacencyMatrix[vertTwo->GetPosition()][vertOne->GetPosition()] = addPtr;
}

template <typename ElemType>
void Graph<ElemType>::AddEdge(Edge<ElemType>& toAdd)
{
	edgeList.InsertBack(toAdd);

	adjacencyMatrix[toAdd.EndVertices()[0]->GetPosition()][toAdd.EndVertices()[1]->GetPosition()] = &toAdd;
	adjacencyMatrix[toAdd.EndVertices()[1]->GetPosition()][toAdd.EndVertices()[0]->GetPosition()] = &toAdd;
}

#endif /* DIRECTEDGRAPH_H_ */
