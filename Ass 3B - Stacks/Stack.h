/*************************************************************************
 * AUTHOR      : James Marcu
 * STUDENT ID  : 374443
 * ASS #3      : Stacks
 * CLASS       : CS1D
 * SECTION     : TTh 3:30 AM
 * DUE DATE    : 9/2/2014
 *************************************************************************/

#ifndef STACK_H_
#define STACK_H_

#include "NodeType.h"

template <typename TYPE>
class Stack
{
	public:
	   /*******************************************
	    * * * * CONSTRUCTORS AND DESTRUCTOR * * * *
	    *******************************************/
		Stack();                       //Default constructor.
		Stack(NodeType<TYPE>* initTop);//Constructor which initializes the
		                               //top node.
		~Stack();                      //Default destructor.

	   /*******************************************
		* * * *          ACCESSORS          * * * *
		*******************************************/
		      NodeType<TYPE>* Top();  //Returns a pointer to the top node.
		const bool            Empty();//Returns true if the stack is empty.
		const int             Size(); //Returns the size of the stack.

	   /*******************************************
		* * * *          MUTATORS           * * * *
		*******************************************/
		void Push(NodeType<TYPE>* node);//Adds a node to the top of the stack.
		void Push(TYPE element);        //Creates a new node from the
		                                //provided data and pushes it on
		                                //top of the stack.
		void Pop();                     //Removes and returns the top node
		                                //of the stack.

	private:
		NodeType<TYPE>* top;//Points to the top node of the stack.
};

/*************************************************************************
 * FUNCTION Stack(Constructor)
 * _______________________________________________________________________
 * 	 Constructs an empty stack.
 * _______________________________________________________________________
 * PRE-CONDITIONS
 * 		<none>
 *
 * POST-CONDITIONS
 * 		Constructs an empty stack.
 *************************************************************************/
template <class TYPE>
Stack<TYPE>::Stack()
{
	top = NULL;
}

/*************************************************************************
 * FUNCTION Stack(Constructor)
 * _______________________________________________________________________
 * 	 Constructs a stack and initializes the top node.
 * _______________________________________________________________________
 * PRE-CONDITIONS
 * 		initTop : Points to what should be the top node in the new stack.
 *
 * POST-CONDITIONS
 * 		Constructs a stack and initializes the top node
 *************************************************************************/
template <class TYPE>
Stack<TYPE>::Stack(NodeType<TYPE>* initTop)
{
	top = initTop;
}

/*************************************************************************
 * FUNCTION ~Stack(Destructor)
 * _______________________________________________________________________
 * 	 Safely destroys the stack.
 * _______________________________________________________________________
 * PRE-CONDITIONS
 * 		<none>
 *
 * POST-CONDITIONS
 * 		Safely destroys the stack.
 *************************************************************************/
template <class TYPE>
Stack<TYPE>::~Stack()
{
	NodeType<TYPE>* delPtr;

	while (top != NULL)
	{
		delPtr = top;
		top    = top->GetNext();
		delete top;
	}

	delPtr = NULL;
}

/*************************************************************************
 * FUNCTION Top
 * _______________________________________________________________________
 * 	 Returns the address of the top node in the stack.
 * _______________________________________________________________________
 * PRE-CONDITIONS
 * 		<none>
 *
 * POST-CONDITIONS
 * 		Returns the address of the top node in the stack.
 *************************************************************************/
template <class TYPE>
NodeType<TYPE>* Stack<TYPE>::Top()
{
	NodeType<TYPE>* topPtr;
	topPtr = top;
	return topPtr;
}

/*************************************************************************
 * FUNCTION Empty
 * _______________________________________________________________________
 * 	 Returns true if the stack is empty, false otherwise.
 * _______________________________________________________________________
 * PRE-CONDITIONS
 * 		<none>
 *
 * POST-CONDITIONS
 * 		Returns true if the stack is empty, false otherwise.
 *************************************************************************/
template <class TYPE>
const bool Stack<TYPE>::Empty()
{
	return top == NULL;
}

/*************************************************************************
 * FUNCTION Size
 * _______________________________________________________________________
 * 	 Returns the number of nodes in the stack.
 * _______________________________________________________________________
 * PRE-CONDITIONS
 * 		<none>
 *
 * POST-CONDITIONS
 * 		nodeCount : The number of nodes in the stack.
 *************************************************************************/
template <class TYPE>
const int Stack<TYPE>::Size()
{
	//VARIABLE DECLERATIONS
	int             nodeCount;
	NodeType<TYPE>* auxPtr;

	//VARIABLE INSTANTIATIONS
	nodeCount = 0;
	auxPtr    = top;

	/*********************************************************************
	 * PROC - This will move throughe very node in the list. At each node,
	 *        the pointer moves down to the next node in the stack and
	 *        the counter is incremented.
	 *********************************************************************/
	while (auxPtr != NULL)
	{
		auxPtr = auxPtr -> GetNext();
		nodeCount++;
	}

	return nodeCount;
}

/*************************************************************************
 * FUNCTION Push
 * _______________________________________________________________________
 * 	 Adds a new node to the stack.
 * _______________________________________________________________________
 * PRE-CONDITIONS
 * 		node : Points to the node you want to push onto the stack.
 *
 * POST-CONDITIONS
 * 		The new node will be on top of the stack.
 *************************************************************************/
template <class TYPE>
void Stack<TYPE>::Push(NodeType<TYPE>* node)
{
	//First it checks if the stack is empty or not.
	if (top == NULL)
	{
		//If it is empty then head points at the new node, and
		//the node's prev and next fields are set to NULL.
		top =  node;
		top -> SetNext(NULL);
		top -> SetPrev(NULL);
	}
	else
	{
		//If its not empty the node is put onto the top of the stack.
		top  -> SetPrev(node);
		node -> SetNext(node);
		node -> SetPrev(NULL);
		top  =  node;
	}
}

/*************************************************************************
 * FUNCTION Push
 * _______________________________________________________________________
 * 	 Creates a new node from provided data and then pushes it onto the
 * 	 stack.
 * _______________________________________________________________________
 * PRE-CONDITIONS
 * 		element : The data to put in the new node.
 *
 * POST-CONDITIONS
 * 		The data will be added into a node and pushed onto the stack.
 *************************************************************************/
template <class TYPE>
void Stack<TYPE>::Push(TYPE element)
{
	//VARIABLE DECLERATIONS
	NodeType<TYPE>* node;
	node = new NodeType<TYPE>;
	node -> SetData(element);

	//First it checks if the stack is empty or not.
	if (top == NULL)
	{
		//If it is empty then head points at the new node, and
		//the node's prev and next fields are set to NULL.
		top =  node;
		top -> SetNext(NULL);
		top -> SetPrev(NULL);
	}
	else
	{
		//If its not empty the node is put onto the top of the stack.
		top  -> SetPrev(node);
		node -> SetNext(top);
		node -> SetPrev(NULL);
		top  =  node;
	}

	node = NULL;
}

/*************************************************************************
 * FUNCTION Pop
 * _______________________________________________________________________
 * 	 Removes and deletes a node from the top of a stack. It will call
 * 	 the removed node's destructor.
 * _______________________________________________________________________
 * PRE-CONDITIONS
 * 		Stack cannot be empty.
 *
 * POST-CONDITIONS
 * 		The top node of the stack will be removed.
 *************************************************************************/
template <class TYPE>
void Stack<TYPE>::Pop()
{
	NodeType<TYPE>* delPtr;

	delPtr = top;

	top =  top -> GetNext();
	if (top != NULL)
	{
		top -> SetPrev(NULL);
	}
	delete delPtr;
	delPtr = NULL;
}

#endif /* STACK_H_ */
