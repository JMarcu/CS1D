/*************************************************************************
 * AUTHOR      : James Marcu
 * STUDENT ID  : 374443
 * ASS #      : 
 * CLASS       : CS1D
 * SECTION     : TTh 3:30 AM
 * DUE DATE    : 
 *************************************************************************/

#ifndef HEAP_H_
#define HEAP_H_

#include "BinaryTree.h"
#include "math.h"
#include <queue>

//A heap, built off a generic binary tree. Organized with the minimum
//value as the root.
template <typename ElemType>
class Heap : public BinaryTree<ElemType>
{
	public:
		Heap(); //Constructor
		~Heap();//Destructor

		const ElemType& Min() const;//Returns the root node. This will have
		                            //the lowest value in the heap.

		void RemoveMin();              //Removes the root node.
		void Add(const ElemType& data);//Adds the data into the heap.

	private:
		BTNode<ElemType>* newestNode;  //Used for adding nodes.

		//Private, recursive version of Add.
		void Add(const ElemType& data, BTNode<ElemType>* rootNode);
		void BubbleUp();                          //Resorts the tree after
		                                          //adding a new node.
		void BubbleDown(BTNode<ElemType>* bubble);//Resorts the tree after
		                                          //deleting a node.
};

template <typename ElemType>
Heap<ElemType>::Heap()
{
	BinaryTree<ElemType>::root = NULL;
	newestNode = NULL;
}

template <typename ElemType>
Heap<ElemType>::~Heap()
{
	BinaryTree<ElemType>::Destroy();
}

template <typename ElemType>
const ElemType& Heap<ElemType>::Min() const
{
	return BinaryTree<ElemType>::root->elem;
}

template <typename ElemType>
void Heap<ElemType>::Add(const ElemType& data)
{
	if (BinaryTree<ElemType>::root == NULL)
	{
		BinaryTree<ElemType>::root = new BTNode<ElemType>;
		BinaryTree<ElemType>::root->elem = data;
		newestNode = BinaryTree<ElemType>::root;
	}
	else
	{
		Add(data, BinaryTree<ElemType>::root);
	}
}

template <typename ElemType>
void Heap<ElemType>::Add(const ElemType& data, BTNode<ElemType>* rootNode)
{
	//First tries to add to the left child of the node.
	if (rootNode->left == NULL)
	{
		rootNode->left         = new BTNode<ElemType>;
		rootNode->left->parent = rootNode;
		rootNode->left->elem   = data;
		newestNode = rootNode->left;
	}
	//Then tries to add to the right child.
	else if (rootNode->right == NULL)
	{
		rootNode->right         = new BTNode<ElemType>;
		rootNode->right->parent = rootNode;
		rootNode->right->elem   = data;
		newestNode = rootNode->right;
	}
	//If the left subtree is incomplete then the add function is recursively
	//called on it.
	else if (BinaryTree<ElemType>::Size(rootNode->left) !=
			 (pow(2, (BinaryTree<ElemType>::GetHeight(rootNode->left))) - 1))
	{
		Add(data, rootNode->left);
	}
	//If the right subtree has fewer nodes than a complete left subtree then
	//the add function is recursively called on it.
	else if (BinaryTree<ElemType>::Size(rootNode->right) !=
			 BinaryTree<ElemType>::Size(rootNode->left))
	{
		Add(data, rootNode->right);
	}
	//Otherwise the tree is full and a new node is created in the bottom
	//left.
	else
	{
		newestNode = rootNode;

		while (newestNode->left != NULL)
		{
			newestNode = newestNode->left;
		}

		newestNode->left = new BTNode<ElemType>;
		newestNode->left->parent = Heap<ElemType>::newestNode;
		newestNode->left->elem = data;
		newestNode = newestNode->left;
	}

	//The tree is resorted if necessary.
	if (newestNode->parent != NULL &&
		newestNode->elem < newestNode->parent->elem)
	{
		BubbleUp();
	}
}

template <class ElemType>
void Heap<ElemType>::BubbleUp()
{
	BTNode<ElemType>* parentPtr;
	BTNode<ElemType>* leftChild;
	BTNode<ElemType>* rightChild;

	parentPtr  = newestNode->parent;
	leftChild  = newestNode->left;
	rightChild = newestNode->right;

	if (parentPtr->parent != NULL)
	{
		if (newestNode->parent->parent->left == (newestNode->parent))
		{
			newestNode->parent->parent->left = newestNode;
		}
		else
		{
			newestNode->parent->parent->right = newestNode;
		}
	}

	newestNode->parent = newestNode->parent->parent;

	if (parentPtr->left == newestNode)
	{
		if (parentPtr->right != NULL)
		{
			parentPtr->right->parent = newestNode;
		}

		newestNode->right = parentPtr->right;
		newestNode->left  = parentPtr;
	}
	else
	{
		parentPtr->left->parent = newestNode;
		newestNode->left  = parentPtr->left;
		newestNode->right = parentPtr;
	}

	parentPtr->parent = newestNode;
	parentPtr->left   = leftChild;
	parentPtr->right  = rightChild;

	if (leftChild != NULL)
	{
		leftChild->parent = parentPtr;
	}

	if (rightChild!= NULL)
	{
		rightChild->parent = parentPtr;
	}

	if (newestNode->parent == NULL)
	{
		BinaryTree<ElemType>::root = newestNode;
	}

	if (newestNode->parent != NULL &&
			newestNode->elem < newestNode->parent->elem)
	{
		BubbleUp();
	}
}

template <typename ElemType>
void Heap<ElemType>::RemoveMin()
{
	BTNode<ElemType>* replacementPtr;
	queue<BTNode<ElemType>* > breadthTraversal;

	if (BinaryTree<ElemType>::root != NULL)
	{
		breadthTraversal.push(BinaryTree<ElemType>::root);
	}

	while (!breadthTraversal.empty())
	{
		replacementPtr = breadthTraversal.front();

		if(replacementPtr->left != NULL)
		{
			breadthTraversal.push(replacementPtr->left);
		}

		if(replacementPtr->right != NULL)
		{
			breadthTraversal.push(replacementPtr->right);
		}

		breadthTraversal.pop();
	}

	if (replacementPtr->parent->left == replacementPtr)
	{
		replacementPtr->parent->left = NULL;
	}
	else
	{
		replacementPtr->parent->right = NULL;
	}

	replacementPtr->parent  = NULL;
	if (BinaryTree<ElemType>::root->left != replacementPtr)
	{
		replacementPtr->left = BinaryTree<ElemType>::root->left;
	}
	else
	{
		replacementPtr->left = NULL;
	}

	if (BinaryTree<ElemType>::root->right != replacementPtr)
	{
		replacementPtr->right = BinaryTree<ElemType>::root->right;
	}
	else
	{
		replacementPtr->right = NULL;
	}

	delete BinaryTree<ElemType>::root;
	BinaryTree<ElemType>::root = replacementPtr;

	BubbleDown(replacementPtr);
}

template <typename ElemType>
void Heap<ElemType>::BubbleDown(BTNode<ElemType>* bubble)
{
	BTNode<ElemType>* largerChild;
	BTNode<ElemType>* parentPtr;
	BTNode<ElemType>* leftChild;
	BTNode<ElemType>* rightChild;

	if (bubble->left != NULL && bubble->right != NULL)
	{
		if (bubble->left->elem > bubble->right->elem)
		{
			largerChild = bubble->left;
		}
		else
		{
			largerChild = bubble->right;
		}
	}
	else if (bubble->left == NULL && bubble->right != NULL)
	{
		largerChild = bubble->right;
	}
	else if (bubble->left != NULL && bubble->right == NULL)
	{
		largerChild = bubble->left;
	}
	else
	{
		largerChild = NULL;
	}

	if (largerChild != NULL && bubble->elem > largerChild->elem)
	{
		parentPtr  = bubble->parent;
		leftChild  = bubble->left;
		rightChild = bubble->right;

		bubble->right  = largerChild->right;
		bubble->left   = largerChild->left;
		bubble->parent = largerChild;

		largerChild->parent = parentPtr;
		if (leftChild == largerChild)
		{
			largerChild->left  = bubble;
			largerChild->right = rightChild;
		}
		else
		{
			largerChild->right = bubble;
			largerChild->left  = leftChild;
		}

		if (bubble == BinaryTree<ElemType>::root)
		{
			BinaryTree<ElemType>::root = largerChild;
		}

		if (bubble->left != NULL || bubble->right != NULL)
		{
			BubbleDown(bubble);
		}
	}
}


#endif /* HEAP_H_ */
