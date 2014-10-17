/*************************************************************************
 * AUTHOR      : James Marcu
 * STUDENT ID  : 374443
 * ASS #7      : Heaps
 * CLASS       : CS1D
 * SECTION     : TTh 3:30 AM
 * DUE DATE    : 
 *************************************************************************/
#ifndef BINARYTREENODE_H_
#define BINARYTREENODE_H_

#include <iostream>
using namespace std;

template <typename ElemType>
class BTNode
{
	private:
		typedef BTNode<ElemType> node;

	public:
	   /*******************************************
		* * * * CONSTRUCTORS AND DESTRUCTOR * * * *
		*******************************************/
		BTNode()
			{left = NULL; right = NULL; parent = NULL;}
		~BTNode()
			{}

	   /*******************************************
		* * * *          ACCESSORS          * * * *
		*******************************************/
		const ElemType& GetElem() const
			{return elem;}
		node* GetLeft() const
			{return left;}
		node* GetRight() const
			{return right;}
		node* GetParent() const
			{return parent;}
		bool IsLeftChild() const
			{return parent != NULL ? parent->GetLeft() == this : false;}
		bool IsRightChild() const
			{return parent != NULL ? parent->GetRight() == this : false;}
		bool IsExternal() const
			{return left == NULL && right == NULL;}
		bool IsRoot() const
			{return parent == NULL;}

	   /*******************************************
		* * * *          MUTATORS           * * * *
		*******************************************/
		void SetElem(const ElemType& newElem)
			{elem = newElem;}
		void SetLeft(node* leftChild)
			{left = leftChild;}
		void SetRight(node* rightChild)
			{right = rightChild;}
		void SetParent(node* parentNode)
			{parent = parentNode;}

	private:
		ElemType elem;
		node*  left;
		node*  right;
		node*  parent;
};

#endif /* BINARYTREENODE_H_ */
