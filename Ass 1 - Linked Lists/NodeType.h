/*************************************************************************
 * AUTHOR      : James Marcu
 * STUDENT ID  : 374443
 * ASS #1      : Linked Lists & Queues
 * CLASS       : CS1D
 * SECTION     : TTh 1:00 PM
 * DUE DATE    : 8/26/2014
 *************************************************************************/

#ifndef NODETYPE_H_
#define NODETYPE_H_

#include <iostream>

//A generic node for a doubly linked list.
template<class Type>
class NodeType
{
	public:
	   /*******************************************
	    * * * * CONSTRUCTORS AND DESTRUCTOR * * * *
	    *******************************************/
		NodeType();
		NodeType(Type initData);
		~NodeType();

	   /*******************************************
		* * * *          ACCESSORS          * * * *
		*******************************************/
		NodeType<Type>* GetNext();//Returns the next node in the list.
		NodeType<Type>* GetPrev();//Returns the previous node in the list.
		Type            GetData();//Returns the node's data.

	   /*******************************************
		* * * *          MUTATORS           * * * *
		*******************************************/
		void SetNext(NodeType<Type>* nextNode);//Sets the next node.
		void SetPrev(NodeType<Type>* prevNode);//Sets the previous node.
		void SetData(const Type  dataToSet);   //Sets the node's data.

	private:
		NodeType<Type>* next;//Points to the next node in the list.
		NodeType<Type>* prev;//Points to the previous node in the list.
		Type            data;//The data stored in the node.
};

/*************************************************************************
 * FUNCTION NodeType(Constructor)
 * _______________________________________________________________________
 * 	 Constructs an empty NodeType object.
 * _______________________________________________________________________
 * PRE-CONDITIONS
 * 		<none>
 *
 * POST-CONDITIONS
 * 		A new NodeType object will be constructed with no data. Pointers
 * 		will point at NULL.
 *************************************************************************/
template<class Type>
NodeType<Type>::NodeType()
{
	next = NULL;
	prev = NULL;
}

/*************************************************************************
 * FUNCTION NodeType(Constructor)
 * _______________________________________________________________________
 * 	 Constructs a NodeType object with data.
 * _______________________________________________________________________
 * PRE-CONDITIONS
 * 		initData : The data to initialize the object with.
 *
 * POST-CONDITIONS
 * 		A new NodeType object will be constructed with the supplied data.
 * 		Pointers will point at NULL.
 *************************************************************************/
template<class Type>
NodeType<Type>::NodeType(Type initData)
{
	next = NULL;
	prev = NULL;
	data = initData;
}

/*************************************************************************
 * FUNCTION NodeType(Destructor)
 * _______________________________________________________________________
 * 	 Safely deconstructs the node.
 * _______________________________________________________________________
 * PRE-CONDITIONS
 * 		<none>
 *
 * POST-CONDITIONS
 * 		Pointers will be set to NULL before object deconstruction.
 *************************************************************************/
template<class Type>
NodeType<Type>::~NodeType()
{
	next = NULL;
	prev = NULL;
}

/*************************************************************************
 * FUNCTION GetData
 * _______________________________________________________________________
 * 	 Returns the object's data field.
 * _______________________________________________________________________
 * PRE-CONDITIONS
 * 		<none>
 *
 * POST-CONDITIONS
 * 		Information stored in the object's data field will be returned
 * 		to the calling function.
 *************************************************************************/
template<class Type>
Type NodeType<Type>::GetData()
{
	return data;
}

/*************************************************************************
 * FUNCTION GetNext
 * _______________________________________________________________________
 * 	 Returns the next node in the list.
 * _______________________________________________________________________
 * PRE-CONDITIONS
 * 		<none>
 *
 * POST-CONDITIONS
 * 		next : Will be returned.
 *************************************************************************/
template<class Type>
NodeType<Type>* NodeType<Type>::GetNext()
{
	return next;
}

/*************************************************************************
 * FUNCTION GetPrev
 * _______________________________________________________________________
 * 	 Returns the previous node in the list.
 * _______________________________________________________________________
 * PRE-CONDITIONS
 * 		<none>
 *
 * POST-CONDITIONS
 * 		prev : Will be returned.
 *************************************************************************/
template<class Type>
NodeType<Type>* NodeType<Type>::GetPrev()
{
	return prev;
}

/*************************************************************************
 * FUNCTION SetNext
 * _______________________________________________________________________
 * 	 Sets the next node in the list.
 * _______________________________________________________________________
 * PRE-CONDITIONS
 * 		nextNode : Points to what will be the next node in the list.
 *
 * POST-CONDITIONS
 * 		next : Will be set to nextNode.
 *************************************************************************/
template<class Type>
void NodeType<Type>::SetNext(NodeType<Type>* nextNode)
{
	next = nextNode;
}

/*************************************************************************
 * FUNCTION SetPrev
 * _______________________________________________________________________
 * 	 Sets the previous node in the list.
 * _______________________________________________________________________
 * PRE-CONDITIONS
 * 		prevNode : Points to what will be the previous node in the list.
 *
 * POST-CONDITIONS
 * 		prev : Will be set to prevNode.
 *************************************************************************/
template<class Type>
void NodeType<Type>::SetPrev(NodeType<Type>* prevNode)
{
	prev = prevNode;
}

/*************************************************************************
 * FUNCTION SetData
 * _______________________________________________________________________
 * 	 Sets the data stored in the node.
 * _______________________________________________________________________
 * PRE-CONDITIONS
 * 		dataToSet : The data to be stored into the node.
 *
 * POST-CONDITIONS
 * 		data : Will be set to dataToSet.
 *************************************************************************/
template<class Type>
void NodeType<Type>::SetData(Type dataToSet)
{
	data = dataToSet;
}

#endif /* NODETYPE_H_ */
