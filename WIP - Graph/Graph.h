/*************************************************************************
 * AUTHOR      : James Marcu
 * STUDENT ID  : 374443
 * ASS #      : 
 * CLASS       : CS1D
 * SECTION     : TTh 3:30 AM
 * DUE DATE    : 
 *************************************************************************/
#ifndef GRAPH_H_
#define GRAPH_H_

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

		//Returns the vertex's element.
		const ElemType& GetElem() const
			{return element;}

		//Returns the vertex's index in the adjacency matrix.
		int GetPosition() const
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

//An undirected, weighted edge for a graph.
template <typename ElemType>
class Edge
{
	public:
	   /*******************************************
	    * * * * CONSTRUCTORS AND DESTRUCTOR * * * *
	    *******************************************/
	    //Default constructor
		Edge()
			{firstVertex = NULL; secondVertex = NULL; weight = 0;}

		//Initialization constructor.
		Edge(const Vertex<ElemType>* vertOne, const Vertex<ElemType>* vertTwo, float weightInit)
			{firstVertex = vertOne; secondVertex = vertTwo; weight = weightInit;}

		//Destructor
		~Edge()
			{firstVertex = NULL; secondVertex = NULL;}


	   /*******************************************
		* * * *          ACCESSORS          * * * *
		*******************************************/

		//Returns the vertex on the opposite side of the argument.
		const Vertex<ElemType>* Opposite(const Vertex<ElemType>* oppOf) const
			{if(oppOf == firstVertex)
				return secondVertex;
			 else if(oppOf == secondVertex)
			    return firstVertex;
			 else
			    return NULL;}

		//Returns a 2 element array containing the incident vertices.
		const Vertex<ElemType>** EndVertices() const
		{
			const Vertex<ElemType>** vertArr = new const Vertex<ElemType>*[2];
			vertArr[0] = firstVertex;
			vertArr[1] = secondVertex;
			return vertArr;
		}

		//Returns the weight of the edge.
		float GetWeight() const
			{return weight;}

		//Returns true if the edge is incident to v.
		bool IsIncidentTo(const Vertex<ElemType>* v) const
			{return v == firstVertex || v == secondVertex;}

	private:
		const Vertex<ElemType>* firstVertex; //First incident vertex.
		const Vertex<ElemType>* secondVertex;//Second incident vertex.
		float weight;                        //Weight of the edge.
};

//An undirected graph, built on an adjacency matrix. Edges are weighted.
template <typename ElemType>
class Graph
{
	public:
	   /*******************************************
	    * * * * CONSTRUCTORS AND DESTRUCTOR * * * *
	    *******************************************/
		Graph(); //Default constructor
		~Graph();//Destructor


	   /*******************************************
		* * * *          ACCESSORS          * * * *
		*******************************************/
		//Returns a pointer to a vertex with the provided search key.
		const Vertex<ElemType>* GetVertex(const ElemType& key);

		//The two stacks will be returned tracing a shortest path from
		//start to each vertex in destinations.
		void FindShortestPath(const Vertex<ElemType>* start,
				List<const Vertex<ElemType>*>&        destinations,
				Stack<const Vertex<ElemType>* >&      vertexStack,
				Stack<const Edge<ElemType>* >&        edgeStack) const;


	   /*******************************************
		* * * *          MUTATORS           * * * *
		*******************************************/
		//Adds a vertex to the graph.
		void AddVertex(const ElemType& elemInit);

		//Adds an edge to the graph.
		void AddEdge(const Vertex<ElemType>* vertOne,
				     const Vertex<ElemType>* vertTwo,
				     float weight);

		//Erases a vertex from the graph.
		void EraseVertex(Vertex<ElemType>* toErase);

		//Erases an edge from the graph.
		void EraseEdge(Edge<ElemType>* toErase);

	private:
	   /*******************************************
		* * * *         VARIABLES           * * * *
		*******************************************/
		List<Vertex<ElemType> > vertexList;//List of verteces.
		List<Edge<ElemType> > edgeList;    //List of edges.
		Edge<ElemType>*** adjacencyMatrix; //Adjacency matrix.
		int  size;                         //Number of verteces.

	   /*******************************************
		* * * *          ACCESSORS          * * * *
		*******************************************/
		//Finds the shortest path from start to its nearest neighbour in
		//destinations using a greedy algorithm. The stacks are updated
		//with the path taken.
		const Vertex<ElemType>* Dijkstra(const Vertex<ElemType>*         start,
				                         List<const Vertex<ElemType>*>   &destinations,
				                         Stack<const Vertex<ElemType>* > &vertexStack,
				                         Stack<const Edge<ElemType>* >   &edgeStack) const;


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

/*************************************************************************
 * METHOD Destructor
 * ______________________________________________________________________
 * Default destructor.
 * ______________________________________________________________________
 * PRE-CONDITIONS -
 *  <none>
 *
 * POST-CONDITIONS -
 * 	Destroys an instance of graph.
 *************************************************************************/
template <typename ElemType>
Graph<ElemType>::~Graph()
{
	//The adjacency matrix is dynamically created so we must destroy it
	//ourselves.
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
 * FUNCTIONS FindShortestPath
 * -----------------------------------------------------------------------
 * This function will attempt to find the shortest path from a starting
 * vertex to a list of other vertices. It uses a nearest neighbor
 * heuristic which averages a 25% error from the optimal solution. Paths
 * from one vertex to another are done using a greedy algorithm,
 * specifically Dijkstra's. The path is stored in two stacks such that
 * the top of the vertex stack is the first node visited on the path, then
 * the next element of the stack is the next node, and so on. The same is
 * true of the edge stack.
 * -----------------------------------------------------------------------
 * PRE-CONDITIONS
 * 	start        : Points to the vertex to start at.
 * 	destinations : A list of pointers-to-vertices. These are the vertices
 * 	               the function is looking for the shortest path to.
 * 	vertexStack  : This stack traces the path of the alogrithm. It should
 * 	               be passed in empty.
 * 	edgeStack    : The same as the vertex stack, but for edges which were
 * 	               traversed.
 *
 * POST-CONDITIONS
 * 	destinations : This list will be empty when the function quits.
 * 	vertexStack  : The vertices in this stack are, from top to bottom, the
 * 	               path found by the function.
 * 	edgeStack    : The edges in this stack are, from top to bottom, the
 * 	               edges used to follow the path found in this function.
 *************************************************************************/
template <typename ElemType>
void Graph<ElemType>::FindShortestPath(const Vertex<ElemType>*          start,
		                               List<const Vertex<ElemType>*>   &destinations,
		                               Stack<const Vertex<ElemType>* > &vertexStack,
		                               Stack<const Edge<ElemType>* >   &edgeStack) const
{
	//VARIABLE DECLERATIONS
	const Vertex<ElemType>* origin;//PROC - Stores the starting point for
	                               //       the search for each individual
	                               //       vertex.

	//VARIABLE INITIALIZATIONS
	origin = start;

	//Add the starting node to the vertex stack.
	vertexStack.Push(start);

	/*********************************************************************
	 * PROC - Each time this loop runs, the shortest path from the origin
	 *        vertex to its nearest neighbor on the destinations list
	 *        is added to the stacks. The loop exits when all elements
	 *        of destinations have been added to the path.
	 *********************************************************************/
	while(!destinations.Empty())
	{
		cout << "test";
		cin.ignore(1000, '\n');
		/*****************************************************************
		 * PROC - The Dijkstra function will update the stacks with the
		 *        path to origin's nearest neighbor. Origin will be set
		 *        to the node that the function ended on. Destinations
		 *        will have the node that Dijkstra found removed.
		 *****************************************************************/
		origin = Dijkstra(origin, destinations, vertexStack, edgeStack);
	}
}

/*************************************************************************
 * FUNCTIONS Dijkstra
 * -----------------------------------------------------------------------
 * This function will use Dijkstra's algorithm to find the shortest path
 * from a starting vertex to the closest vertex in a list of destinations.
 * When any member of the list of destination vertices is found the
 * function will put the path it took to get there at the bottom of the
 * vertex and edge stacks. After it finds one destination vertex in
 * the list it will remove that vertex from the list and exit.
 * -----------------------------------------------------------------------
 * PRE-CONDITIONS
 * 	start        : Points to the vertex to start at.
 * 	destinations : A list of pointers-to-vertices. These are the vertices
 * 	               the function is looking for the shortest path to.
 * 	vertexStack  : This stack traces the path of the alogrithm. The path
 * 	               used in the function is added to the BOTTOM of the stack.
 * 	               i.e. if the stack started with (top->bottom)ABC, and
 * 	               the function went CDEF, the stack would be returned
 * 	               with ABCDEF.
 * 	edgeStack    : The same as the vertex stack, but for edges which were
 * 	               traversed.
 *
 * POST-CONDITIONS
 * 	destinations : The destination which the function found a path to
 * 	               will be removed from the list.
 * 	vertexStack  : Updated with the path the function took.
 * 	edgeStack    : Updated with the path the function took.
 * 	newVertex    : The function also returns a pointer. This points to
 * 	               the vertex in destination which the function found a
 * 	               path to.
 *************************************************************************/
template <typename ElemType>
const Vertex<ElemType>* Graph<ElemType>::Dijkstra(const Vertex<ElemType>*          start,
		                                          List<const Vertex<ElemType>*>&   destinations,
		                                          Stack<const Vertex<ElemType>* >& vertexStack,
		                                          Stack<const Edge<ElemType>* >&   edgeStack) const
{
	/*********************************************************************
	 * VARIABLE DECLERATIONS
	 *********************************************************************/

	//PROC - Each vertex's position in the adjacency matrix corresponds here
	//       to the cost to reach it from the starting point.
	float costMatrix[size];

	//PROC - A tree which keeps track of the path travelled so far.
	Tree<const Vertex<ElemType>* > pathTree;

	//PROC - Used to iterate pathTree.
	TreeNode<const Vertex<ElemType>* >* treePtr;

	//PROC - Keeps track of each vertices parent in the algorithm.
	const Vertex<ElemType>* parentVertex;

	//PROC - Tracks which vertices have been visited so far.
	List<const Vertex<ElemType>* > visitedVertices;

	//PROC - Tracks which vertices are 'active'. A vertice is active if it
	//       still has edges which go to unvisited vertices.
	List<const Vertex<ElemType>* > activeVertices;

	//PROC - Used to iterate activeVertices.
	typename List<const Vertex<ElemType>* >::Iterator activeIt;

	//PROC - Tracks which edges have been visited so far.
	List<const Edge<ElemType>* > visitedEdges;

	//PROC - Used to iterate visitedEdges.
	typename List<const Edge<ElemType>* >::Iterator edgeIt;

	//PROC - Stores the vertex which is about to be put into the cloud.
	const Vertex<ElemType>* newVertex;

	//PROC - Stores the edge which is about to be put into the cloud.
	Edge<ElemType>* newEdge;

	//PROC - The cost to arrive at the newly added vertice from the starting
	//       vertex.
	float newVertCost;

	//PROC - Used to remove no longer active vertices as removing them
	//       with an iterator breaks the iterator.
	const Vertex<ElemType>* removeFromActive;

	//PROC - Used to flag vertices which are no longer active for removal.
	bool stillActive;

	//PROC - A LCV that controls the main loop. True while a member of
	//       destinations has yet to be found.
	bool findNextDest;

	//PROC - Stores any existing values of vertexStack in reverse to maintain
	//       proper order.
	Stack<const Vertex<ElemType>* > tempVertexStack;

	//PROC - Stores any existing values of edgeStack in reverse to maintain
	//       proper order.
	Stack<const Edge<ElemType>* > tempEdgeStack;

	/*********************************************************************
	 * PROC - Set the cost to get to the starting node as zero
	 *********************************************************************/
	costMatrix[start->GetPosition()] = 0;

	/*********************************************************************
	 * PROC - Add the starting node to visited vertices, active vertices,
	 *         and the path tree.
	 *********************************************************************/
	visitedVertices.InsertBack(start);
	activeVertices.InsertBack(start);
	pathTree.Add(start, NULL);

	/*********************************************************************
	 * PROC - If the starting node is a destination, remove it from the
	 *        list of destinations. Only go on if there are still
	 *        vertices in the list of destinations.
	 *********************************************************************/
	if(destinations.Search(start) != destinations.End())
	{
		destinations.Erase(start);
	}
	findNextDest = !destinations.Empty();

	/*********************************************************************
	 * PROC - This will loop until it arrives at a node found in
	 *        destinations. It searches for the next closest node to any
	 *        other node in the tree and adds it in.
	 *********************************************************************/
	while(findNextDest)
	{
		//Start at the beginning of the active vertices.
		activeIt    = activeVertices.Begin();

		//Set the newVertCost to the max it can be, so anything else is
		//lower.
		newVertCost = numeric_limits<float>::max();

		/*****************************************************************
		 * PROC - Every edge of every active vertice will be checked in
		 *        order to find the closest.
		 *****************************************************************/
		while(activeIt != activeVertices.End())
		{
			//Set the stillActive flag to false.
			stillActive = false;

			/*************************************************************
			 * PROC - We check the adjacency matrix for edges to the
			 *        current vertex.
			 *************************************************************/
			for(int i = 0; i < size; ++i)
			{
				//If the matrix returns NULL there is no edge there.
				if(adjacencyMatrix[(*activeIt)->GetPosition()][i] != NULL)
				{
					//This checks if the edge points to an unvisited vertex.
					if(visitedVertices.Search(adjacencyMatrix[(*activeIt)->GetPosition()][i]->Opposite(*activeIt)) == visitedVertices.End())
					{
						//If the loop gets here then the current vertex points to
						//at least one unvisited vertex and is still active.
						stillActive = true;

						//If the cost to get to the new vertex from the starting vertex is the lowest of all checked, unadded vertices.
						if(costMatrix[(*activeIt)->GetPosition()] + (adjacencyMatrix[(*activeIt)->GetPosition()][i])->GetWeight() < newVertCost)
						{
							parentVertex = *activeIt;
							newEdge      = adjacencyMatrix[(*activeIt)->GetPosition()][i];
							newVertex    = newEdge->Opposite(*activeIt);
							newVertCost  = costMatrix[(*activeIt)->GetPosition()] + (adjacencyMatrix[(*activeIt)->GetPosition()][i])->GetWeight();
						}//END check cost

					}//END check if edge points to active vertex.

				}//END check if edge exists

			}//END for(int i = 0; i < size; ++i)

			/*************************************************************
			 * PROC - If the vertex isn't active then remove it from the
			 *        list of active vertices.
			 *************************************************************/
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
		}//END (activeIt != activeVertices.End())

		/*****************************************************************
		 * PROC - Add the cost to get to the new vertex from the starting
		 *        vertex to the cost matrix.
		 *****************************************************************/
		costMatrix[newVertex->GetPosition()] = newVertCost;

		/*****************************************************************
		 * PROC - Add the new vertex to the list of visited vertices,
		 *        active vertices, and the path tree. Add the edge we
		 *        took to get there to the list of visited edges.
		 *****************************************************************/
		visitedVertices.InsertBack(newVertex);
		activeVertices.InsertBack(newVertex);
		pathTree.Add(newVertex, pathTree.Search(parentVertex));
		visitedEdges.InsertBack(newEdge);

		/*****************************************************************
		 * PROC - If the newly added vertex is a member of destinations
		 *        then this block of code will run, which adds the path
		 *        to get there to the two stacks passed into this
		 *        function. Otherwise it is skipped and the main loop
		 *        repeats again.
		 *****************************************************************/
		if(destinations.Search(newVertex) != destinations.End())
		{
			/*************************************************************
			 * PROC - Tree pointer will point to the new vertices place in
			 *		  the tree. The edge list iterator will point to the
			 *		  last element in the list, the most recently added
			 *		  edge.
			 *************************************************************/
			treePtr = pathTree.Search(newVertex);
			edgeIt = visitedEdges.End();
			--edgeIt;

			/*************************************************************
			 * PROC - Pop all existing contents of vertexStack into
			 * 	      tempVertexStack. This will preserve their order
			 * 	      while new elements are added.
			 *
			 * 	      The same is done for edgeStack and its temporary
			 * 	      version.
			 *************************************************************/
			while(!vertexStack.Empty())
			{
				tempVertexStack.Push(vertexStack.Peek());
				vertexStack.Pop();
			}

			while(!edgeStack.Empty())
			{
				tempEdgeStack.Push(edgeStack.Peek());
				edgeStack.Pop();
			}


			/*************************************************************
			 * PROC - The tree pointer will be pointing at the most
			 *        recently vertex node. The root of the tree will be
			 *        the starting vertex. Traveling up the tree to the
			 *        root will give us the path we took to get from the
			 *        starting vertex to the destination. Each one of these
			 *        vertexes is pushed onto the vertex stack.
			 *
			 *        Edges are looked at most-recently-added first in
			 *        order to find an edge incident to both the current
			 *        vertex and its parent in the tree. This is the edge
			 *        we took to get from the parent to the current vertex.
			 *        These edges are pushed to the edge stack.
			 *************************************************************/
			while(treePtr != pathTree.GetRoot())
			{
				//Find the edge we used to get to the parent vertex in
				//the path tree.
				while(!(*edgeIt)->IsIncidentTo(treePtr->GetElem()) ||
				      !(*edgeIt)->IsIncidentTo(treePtr->GetParent()->GetElem()))
				{
					--edgeIt;
				}

				//Push the edge and vertex to the stacks.
				edgeStack.Push((*edgeIt));
				vertexStack.Push(treePtr->GetElem());

				//Move up the tree
				treePtr = treePtr->GetParent();
			}

			/*************************************************************
			 * PROC - Pop the original contents of the edge and vertex
			 *        stacks back into them. Their order is now preserved.
			 *************************************************************/
			while(!tempEdgeStack.Empty())
			{
				edgeStack.Push(tempEdgeStack.Peek());
				tempEdgeStack.Pop();
			}

			while(!tempVertexStack.Empty())
			{
				vertexStack.Push(tempVertexStack.Peek());
				tempVertexStack.Pop();
			}

			/*************************************************************
			 * PROC - Remove this node from the list of destinations and
			 *        flag that we can exit the function call.
			 *************************************************************/
			destinations.Erase(newVertex);
			findNextDest = false;

		}//END if(destinations.Search(newVertex) != destinations.End())

	}//END while(findNextDest)

	/*********************************************************************
	 * OUT - Return a pointer to the vertex in destinations which
	 *       this program found the path to.
	 *********************************************************************/
	return newVertex;
}

/*************************************************************************
 * FUNCTION IncrementMatrix
 * -----------------------------------------------------------------------
 * This increases the size of the adjacency matrix by one for if any
 * new vertices are added.
 * -----------------------------------------------------------------------
 * PRE-CONDITIONS
 *  The 'size' variable in the graph must be incremented before this
 *  function is called. Currently, this is handled.
 *
 * POST-CONDITIONS
 * 	The adjacency matrix will be one size larger in the x and y directions.
 *************************************************************************/
template <typename ElemType>
void Graph<ElemType>::IncrementMatrix()
{
	//VARIABLE DECLERATIONS
	Edge<ElemType>*** matrix;//PROC - Used to construct the new matrix.

	/*********************************************************************
	 * PROC - Construct a new matrix of the desired size.
	 *********************************************************************/
	matrix = new Edge<ElemType>**[size];
	for (int i = 0; i < size; ++i)
	{
		matrix[i] = new Edge<ElemType>*[size];
		for (int j = 0; j < size; j++)
		{
			matrix[i][j] = NULL;
		}
	}

	/*********************************************************************
	 * PROC - Copy the contents of the old matrix into the new one.
	 *********************************************************************/
	for (int i = 0; i < size-1; ++i)
	{
		for (int j = 0; j < size-1; ++j)
		{
			matrix[i][j] = adjacencyMatrix[i][j];
		}
	}

	/*********************************************************************
	 * PROC - Delete the old adjacency matrix.
	 *********************************************************************/
	for (int i = 0; i < size-1; ++i)
	{
		for (int j = 0; j < size-1; ++j)
		{
			delete[] adjacencyMatrix[i][j];
		}
		delete[] adjacencyMatrix[i];
	}

	/*********************************************************************
	 * PROC - Have adjacencyMatrix point to the new matrix.
	 *********************************************************************/
	adjacencyMatrix = matrix;
}

/*************************************************************************
 * FUNCTION AddVertex
 * -----------------------------------------------------------------------
 * Adds a vertex to the graph.
 * -----------------------------------------------------------------------
 * PRE-CONDITIONS
 *  elemInit : The element to be stored in the new vertex.
 *
 * POST-CONDITIONS
 * 	A vertex will be added containing elemInit.
 *************************************************************************/
template <typename ElemType>
void Graph<ElemType>::AddVertex(const ElemType& elemInit)
{
	//VARIABLE DECLERATIONS
	Vertex<ElemType>* addPtr;//PROC - Used to construct the vertex.

	//Increment the size of the graph and the matrix.
	++size;
	IncrementMatrix();

	//Construct the new vertex and add it to the list of vertices.
	addPtr = new Vertex<ElemType>(elemInit, size - 1);
	vertexList.InsertBack(*addPtr);

}

/*************************************************************************
 * FUNCTION AddEdge
 * -----------------------------------------------------------------------
 * Adds an edge to the graph.
 * -----------------------------------------------------------------------
 * PRE-CONDITIONS
 *  vertOne : The first vertex the edge is incident to.
 *  vertTwo : The second vertex the edge is incident to.
 *  weight  : The weight of the edge.
 *
 * POST-CONDITIONS
 * 	An edge will be added to the graph.
 *************************************************************************/
template <typename ElemType>
void Graph<ElemType>::AddEdge(const Vertex<ElemType>* vertOne,
		                      const Vertex<ElemType>* vertTwo,
		                      float                   weight)
{
	//VARIABLE DECLERATIONS
	Edge<ElemType>* addPtr;//PROC - Used to construct the edge.

	//Create the new edge and add it to the edge list.
	addPtr = new Edge<ElemType>(vertOne, vertTwo, weight);
	edgeList.InsertBack(*addPtr);

	//Add a pointer to the new edge in the proper locations within the
	//adjacency matrix.
	adjacencyMatrix[vertOne->GetPosition()][vertTwo->GetPosition()] = addPtr;
	adjacencyMatrix[vertTwo->GetPosition()][vertOne->GetPosition()] = addPtr;
}

#endif /* DIRECTEDGRAPH_H_ */
