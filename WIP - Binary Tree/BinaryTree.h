/*************************************************************************
 * AUTHOR      : James Marcu
 * STUDENT ID  : 374443
 * ASS #      : 
 * CLASS       : CS1D
 * SECTION     : TTh 3:30 AM
 * DUE DATE    : 
 *************************************************************************/
#ifndef BINARYTREE_H_
#define BINARYTREE_H_

#include "BinaryTreeNode.h"
#include "BinaryTreeIterator.h"

template <typename ElemType>
class BinaryTree
{
	protected:
		typedef BTNode<ElemType> node;

		class Iterator
		{
			public:
				Iterator();
				Iterator(node* nodeInit);

				node* operator*() const;
				node* operator->() const;
				bool  operator==(Iterator& compare) const;
				bool  operator!=(Iterator& compare) const;

			protected:
				node* currentNode;
		};

		class Inorder: public Iterator
		{
			public:
				Inorder();
				Inorder(node* nodeInit);

				Inorder operator++();
				Inorder operator++(int);
				Inorder operator--();
				Inorder operator--(int);
		};

		class Preorder: public Iterator
		{
			public:
				Preorder operator++();
				Preorder operator++(int);
				Preorder operator--();
				Preorder operator--(int);
		};

		class Postorder: public Iterator
		{
			public:
				Postorder operator++();
				Postorder operator++(int);
				Postorder operator--();
				Postorder operator--(int);
		};

		class BreadthFirst: public Iterator
		{
			public:
				BreadthFirst& operator++();
				BreadthFirst& operator++(int);
				BreadthFirst& operator--();
				BreadthFirst& operator--(int);
		};

		typedef Iterator     BTiterator;
		typedef Inorder      BTinorder;
		typedef Preorder     BTpreorder;
		typedef Postorder    BTpostorder;
		typedef BreadthFirst BTbreadth;

	public:
		virtual ~BinaryTree();

		int Height() const;
		int Size() const;
		int LeafCount() const;
		bool Search(const ElemType& key) const;
		void PrintInorder(ostream& outstream=cout) const;
		void PrintPreorder(ostream& outstream=cout) const;
		void PrintPostorder(ostream& outstream=cout) const;
		void PrintBreadthFirst(ostream& outstream=cout) const;

		void Add(const ElemType& newElem);
		virtual bool Delete(const ElemType& toDelete);
		void Destroy();

	protected:
		node* root;

		int Max(int x, int y);

		int Height(node* rootNode) const;
		int Size(node* rootNode) const;
		virtual node* Search(const ElemType& key, node* rootNode) const;
		virtual void Add(const ElemType& newElem, node* rootNode);
		void Destroy(node* rootNode);
};

template <typename ElemType>
BinaryTree<ElemType>::~BinaryTree()
{
	Destroy();
	root = NULL;
}

/*************************************************************************
 * FUNCTION GetHeight
 * _______________________________________________________________________
 * Returns the height of the tree. This is the public version which can be
 * called only on the tree's root.
 * _______________________________________________________________________
 * PRE-CONDITIONS
 * 	<none>
 *
 * POST-CONDITIONS
 * 	height: The height of the tree.
 *************************************************************************/
template <typename ElemType>
int BinaryTree<ElemType>::Height() const
{
	return Height(root);
}

/*************************************************************************
 * FUNCTION GetHeight
 * _______________________________________________________________________
 * Returns the height of the tree. This is the private version which can be
 * called on any subtree.
 * _______________________________________________________________________
 * PRE-CONDITIONS
 * 	rootNode: The root of the subtree to start at.
 *
 * POST-CONDITIONS
 * 	height: The height of the tree.
 *************************************************************************/
template <typename ElemType>
int BinaryTree<ElemType>::Height(node* rootNode) const
{
	//VARIABLE DECLERATIONS
	int height;//OUT - Height of the tree.

	//If the node is NULL the height is zero. Otherwise its one more than
	//the height of its tallest subtree.
	if (rootNode == NULL)
	{
		height = 0;
	}
	else
	{
		height = 1 + Max(Height(rootNode->GetLeft()), Height(rootNode->GetRight()));
	}

	return height;
}

/*************************************************************************
 * FUNCTION Size
 * _______________________________________________________________________
 * Returns the number of nodes in the tree. This is the public version
 * which can be called only on the tree's root.
 * _______________________________________________________________________
 * PRE-CONDITIONS
 * 	<none>
 *
 * POST-CONDITIONS
 * 	size: The number of nodes in the tree.
 *************************************************************************/
template <typename ElemType>
int BinaryTree<ElemType>::Size() const
{
	return Size(root);
}

/*************************************************************************
 * FUNCTION Size
 * _______________________________________________________________________
 * Returns the number of nodes in the tree. This is the private version
 * which can be called on any subtree.
 * _______________________________________________________________________
 * PRE-CONDITIONS
 * 	rootNode: The root of the subtree to start at.
 *
 * POST-CONDITIONS
 * 	size: The number of nodes in the tree.
 *************************************************************************/
template <typename ElemType>
int BinaryTree<ElemType>::Size(node* rootNode) const
{
	//VARIABLE DECLERATIONS
	int size;//OUT - Number of nodes in the tree.

	//If the root is NULL the size is zero. Otherwise the size is one more
	//than the sum of the size of its two subtrees.
	if (rootNode == NULL)
	{
		size = 0;
	}
	else
	{
		size = 1 + Size(rootNode->GetLeft()) + Size(rootNode->GetRight());
	}

	return size;
}

template <typename ElemType>
int BinaryTree<ElemType>::LeafCount() const
{
	int       leafCount;
	BTinorder it;

	while (*it != NULL)
	{
		if (it->GetLeft() == NULL && it->GetRight() == NULL)
		{
			leafCount++;
		}
	}

	return leafCount;
}

template <typename ElemType>
bool BinaryTree<ElemType>::Search(const ElemType& key) const
{
	return Search(key, root) != NULL;
}

template <typename ElemType>
BTNode<ElemType>* BinaryTree<ElemType>::Search(const ElemType& key, node* rootNode) const
{
	BTinorder it(root);

	while(it->GetElem() != key)
	{
		it++;
	}

	return *it;
}

template <typename ElemType>
void BinaryTree<ElemType>::PrintInorder(ostream& outstream) const
{
	BTinorder it(root);

	while (*it != NULL)
	{
		outstream << it->GetElem();
	}
}

template <typename ElemType>
void BinaryTree<ElemType>::PrintPreorder(ostream& outstream) const
{
	BTpreorder it(root);

	while (*it != NULL)
	{
		outstream << it->GetElem();
	}
}

template <typename ElemType>
void BinaryTree<ElemType>::PrintPostorder(ostream& outstream) const
{
	BTpostorder it(root);

	while (*it != NULL)
	{
		outstream << it->GetElem();
	}
}

template <typename ElemType>
void BinaryTree<ElemType>::PrintBreadthFirst(ostream& outstream) const
{
	BTbreadth it(root);

	while (*it != NULL)
	{
		outstream << it->GetElem();
	}
}

/*************************************************************************
 * FUNCTION Add
 * _______________________________________________________________________
 * Adds a node with the provided data to the tree. Automatically keeps
 * the tree balanced.
 * _______________________________________________________________________
 * PRE-CONDITIONS
 * 	newElem: The data to store in the new node.
 *
 * POST-CONDITIONS
 * 	A new node will be added to the tree with the provided data.
 *************************************************************************/
template <typename ElemType>
void BinaryTree<ElemType>::Add(const ElemType& newElem)
{
	//If the tree is empty the node is added as the root. Otherwise the
	//recursive version of this function is called.
	 if (root == NULL)
	 {
		 root = new node;
		 root->elem   = newElem;
		 root->left   = NULL;
		 root->right  = NULL;
		 root->parent = NULL;
	 }
	 else
	 {
		 Add(newElem, root);
	 }
}

/*************************************************************************
 * FUNCTION Add
 * _______________________________________________________________________
 * Adds a node with the provided data to the tree. This is the private
 * recursive version. It automatically keeps the tree balanced.
 * _______________________________________________________________________
 * PRE-CONDITIONS
 * 	newElem : The data to store in the new node.
 * 	rootNode: The root of the subtree the node will be added to.
 *
 * POST-CONDITIONS
 * 	A new node will be added to the tree with the provided data.
 *************************************************************************/
template <typename ElemType>
void BinaryTree<ElemType>::Add(const ElemType& newElem, node* rootNode)
{
	//First the algorithm will attempt to add the node to the left of the
	//root node.
	if(rootNode->GetLeft() == NULL)
	{
		rootNode->SetLeft(new node);
		rootNode->GetLeft()->SetElem(newElem);
		rootNode->GetLeft()->SetLeft(NULL);
		rootNode->GetLeft()->SetRight(NULL);
		rootNode->GetLeft()->SetParent(rootNode);
	}
	//Then it will attempt to add it to the right of the root node.
	else if(rootNode->GetRight() == NULL)
	{
		rootNode->SetRight(new node);
		rootNode->GetRight()->SetElem(newElem);
		rootNode->GetRight()->SetLeft(NULL);
		rootNode->GetRight()->SetRight(NULL);
		rootNode->GetRight()->SetParent(rootNode);
	}
	//If the root node already has two children...
	else
	{
		//The algorithm will call itself on the smaller of the two
		//subtrees. If the subtrees are equal it goes to the left.
		if (Size(rootNode->GetLeft()) <= Size(rootNode->GetRight()))
		{
			Add(newElem, rootNode->GetLeft());
		}
		else
		{
			Add(newElem, rootNode->GetRight());
		}
	}
}

/*************************************************************************
 * FUNCTION Delete
 * _______________________________________________________________________
 * Deletes a node from the tree which contains the provided data. This does
 * not cause the tree to become unbalanced. If the data cannot be found
 * in the tree then the function returns false.
 * _______________________________________________________________________
 * PRE-CONDITIONS
 * 	toDelete: The data stored in the node which is to be deleted.
 *
 * POST-CONDITIONS
 * 	The node will be deleted and the tree updated. If no suitable node
 * 	could be found then the function returns false.
 *************************************************************************/
template <typename ElemType>
bool BinaryTree<ElemType>::Delete(const ElemType& toDelete)
{
	//VARIABLE DECLERATIONS
	node* replacePtr; //CALC - Points to the node which will take the place
	                  //       of the deleted node in the tree.
	node* delPtr;     //CALC - Points at the node which will be deleted.
	bool  success;    //OUT -  Returns true if deletion was successfull.

	//VARIABLE INITIALIZATioNS
	replacePtr  = root;
	delPtr      = Search(toDelete, root);
	success     = delPtr != NULL;

	//If the node to be deleted is an external node then it can just be
	//deleted and none of this is necessary.
	if (success && !delPtr->IsExternal())
	{
		//The node which will replace the deleted node is the leftmost node
		//in the tree. This is because due to the nature of the algorithm
		//for adding nodes into the tree, no damage will be done to the
		//balance of the tree if this node is used.
		while (replacePtr->GetLeft() != NULL)
		{
			replacePtr = replacePtr->GetLeft();
		}

		//It is possible for the left most node in the tree to have no left
		//child but have a right child if a delete call was previously
		//used and no node has been added since. If this is the case, then
		//the right child is used as the replacement node instead. This
		//is the only case where IsLeftChild will be false.
		if (replacePtr->GetRight() != NULL)
		{
			replacePtr = replacePtr->GetRight();
		}

		//The replacement node's parent has its child pointer updated to
		//NULL.
		if (replacePtr->IsLeftChild())
		{
			replacePtr->GetParent()->SetLeft(NULL);
		}
		else
		{
			replacePtr->GetParent()->SetRight(NULL);
		}

		//The replacement node has its parent, left, and right pointers
		//updated to be the same as the to be deleted node.
		replacePtr->SetParent(delPtr->GetParent());
		replacePtr->SetLeft(delPtr->GetLeft());
		replacePtr->SetRight(delPtr->GetRight());
	}

	//The node is deleted.
	if (success)
	{
		delete delPtr;
	}

	return success;
}

/*************************************************************************
 * FUNCTION Destroy
 * _______________________________________________________________________
 * Every node in the tree is deleted and the root is set to NULL. This is
 * the public version of the method.
 * _______________________________________________________________________
 * PRE-CONDITIONS
 * 	<none>
 *
 * POST-CONDITIONS
 * 	The tree is destroyed and made to be empty.
 *************************************************************************/
template <typename ElemType>
void BinaryTree<ElemType>::Destroy()
{
	if (root != NULL)
	{
		Destroy(root);
		root = NULL;
	}
}

/*************************************************************************
 * FUNCTION Destroy
 * _______________________________________________________________________
 * Every node in the tree is deleted and the root is set to NULL. This is
 * the recursive, private version of the method.
 * _______________________________________________________________________
 * PRE-CONDITIONS
 * 	rootNode: The root of the subtree this method is being called on.
 *
 * POST-CONDITIONS
 * 	The tree is destroyed and made to be empty.
 *************************************************************************/
template <typename ElemType>
void BinaryTree<ElemType>::Destroy(node* rootNode)
{
	//If there is a left subtree, Destroy is called on it.
	if (rootNode->GetLeft() != NULL)
	{
		Destroy(rootNode->GetLeft());
	}

	//If there is a right subtree, Destroy is called on it.
	if (rootNode->GetRight() != NULL)
	{
		Destroy(rootNode->GetRight());
	}

	//The root of the subtree is deleted.
	delete rootNode;
}

/*************************************************************************
 * FUNCTION Iterator
 * _______________________________________________________________________
 * Default constructor for the tree's iterator.
 * _______________________________________________________________________
 * PRE-CONDITIONS
 * 	<none>
 *
 * POST-CONDITIONS
 * 	Sets the currentNode pointer to the root of the tree.
 *************************************************************************/
template <typename ElemType>
BinaryTree<ElemType>::Iterator::Iterator()
{
	currentNode = root;
}

/*************************************************************************
 * FUNCTION Iterator
 * _______________________________________________________________________
 * Constructor for the tree's iterator.
 * _______________________________________________________________________
 * PRE-CONDITIONS
 * 	nodeInit: The node of the tree the iterator will point to.
 *
 * POST-CONDITIONS
 * 	Sets the currentNode pointer to the node passed in.
 *************************************************************************/
template <typename ElemType>
BinaryTree<ElemType>::Iterator::Iterator(node* nodeInit)
{
	currentNode = nodeInit;
}

/*************************************************************************
 * FUNCTION operator*
 * _______________________________________________________________________
 * Returns the pointer to the iterator's current node.
 * _______________________________________________________________________
 * PRE-CONDITIONS
 * 	<none>
 *
 * POST-CONDITIONS
 * 	Returns the pointer to the iterator's current node.
 *************************************************************************/
template <typename ElemType>
BTNode<ElemType>* BinaryTree<ElemType>::Iterator::operator*() const
{
	return currentNode;
}

/*************************************************************************
 * FUNCTION operator->
 * _______________________________________________________________________
 * Simple redefinition to allow the arrow operator to call on the iterator's
 * pointer.
 * _______________________________________________________________________
 * PRE-CONDITIONS
 * 	<none>
 *
 * POST-CONDITIONS
 * 	Allows the iterator's pointer to be accessed through the arrow
 * 	operator.
 *************************************************************************/
template <typename ElemType>
BTNode<ElemType>* BinaryTree<ElemType>::Iterator::operator->() const
{
	return currentNode;
}

/*************************************************************************
 * FUNCTION operator==
 * _______________________________________________________________________
 * Returns true if the two iterators point to the same node.
 * _______________________________________________________________________
 * PRE-CONDITIONS
 * 	<none>
 *
 * POST-CONDITIONS
 * 	Returns true if the two iterators point to the same node.
 *************************************************************************/
template <typename ElemType>
bool BinaryTree<ElemType>::Iterator::operator==(Iterator& compare) const
{
	return *this == *compare;
}

/*************************************************************************
 * FUNCTION operator==
 * _______________________________________________________________________
 * Returns true if the two iterators point to different nodes.
 * _______________________________________________________________________
 * PRE-CONDITIONS
 * 	<none>
 *
 * POST-CONDITIONS
 * 	Returns true if the two iterators point to different nodes.
 *************************************************************************/
template <typename ElemType>
bool BinaryTree<ElemType>::Iterator::operator!=(Iterator& compare) const
{
	return *this != *compare;
}

/*************************************************************************
 * FUNCTION Inorder
 * _______________________________________________________________________
 * Default constructor for the Inorder iterator.
 * _______________________________________________________________________
 * PRE-CONDITIONS
 * 	<none>
 *
 * POST-CONDITIONS
 * 	Sets the currentNode pointer to the bottom left node of the tree.
 *************************************************************************/
template <typename ElemType>
BinaryTree<ElemType>::Inorder::Inorder()
{
	//Starts the pointer at the root of the tree.
	Iterator::currentNode = root;

	//Searches to the bottom left node of the tree and sets currentNode
	//equal to it.
	while (Iterator::currentNode->GetLeft() != NULL)
	{
		Iterator::currentNode = Iterator::currentNode->GetLeft();
	}
}

/*************************************************************************
 * FUNCTION Inorder
 * _______________________________________________________________________
 * Constructor for the Inorder iterator.
 * _______________________________________________________________________
 * PRE-CONDITIONS
 * 	nodeInit: The node of the tree the iterator will point to.
 *
 * POST-CONDITIONS
 * 	Sets the currentNode pointer to the value passed in.
 *************************************************************************/
template <typename ElemType>
BinaryTree<ElemType>::Inorder::Inorder(node* nodeInit)
{
	Iterator::currentNode = nodeInit;
}

/*************************************************************************
 * FUNCTION Inorder::operator++()
 * _______________________________________________________________________
 * Increments the iterator to the next node using an inorder traversal.
 * This is the pre-increment version of the operator.
 * _______________________________________________________________________
 * PRE-CONDITIONS
 * 	<none>
 *
 * POST-CONDITIONS
 * 	The iterator will point at the next inorder node. Will return an
 * 	incremented version of the operator.
 *************************************************************************/
template <typename ElemType>
typename BinaryTree<ElemType>::Inorder BinaryTree<ElemType>::Inorder::operator++()
{
	//If the current node has a right child, move to it and then go to
	//its left most child.
	if (Iterator::currentNode->GetRight() != NULL)
	{
		Iterator::currentNode = Iterator::currentNode->GetRight();

		while (Iterator::currentNode->GetLeft() != NULL)
		{
			Iterator::currentNode = Iterator::currentNode->GetLeft();
		}
	}
	//Otherwise, if the current node is itself a left childe you go to its
	//parent node.
	else if (Iterator::currentNode->IsLeftChild())
	{
		Iterator::currentNode = Iterator::currentNode->GetParent();
	}
	//If neither, then move up the tree until the current node is the left
	//child.
	else
	{
		while (Iterator::currentNode->IsRightChild())
		{
			Iterator::currentNode = Iterator::currentNode->GetParent();
		}
	}

	//Return the updated iterator for use in the calling function.
	return *this;
}

/*************************************************************************
 * FUNCTION Inorder::operator++()
 * _______________________________________________________________________
 * Increments the iterator to the next node using an inorder traversal.
 * This is the post-increment function.
 * _______________________________________________________________________
 * PRE-CONDITIONS
 * 	<none>
 *
 * POST-CONDITIONS
 * 	The iterator will point at the next inorder node. Will return a
 * 	non-incremented version of the operator.
 *************************************************************************/
template <typename ElemType>
typename BinaryTree<ElemType>::Inorder BinaryTree<ElemType>::Inorder::operator++(int)
{
	//VARIABLE DECLERATIONS
	Inorder saveState;//OUT - Stores the pre-increment value of the iterator.

	//VARIABLE INITIALIZATIONS
	saveState = *this;

	//Increment the iterator.
	++(*this);

	//Return its pre-increment value.
	return saveState;
}

/*************************************************************************
 * FUNCTION Inorder::operator--()
 * _______________________________________________________________________
 * Decrements the iterator to the previous node using an inorder traversal.
 * This is the pre-decrement version of the operator.
 * _______________________________________________________________________
 * PRE-CONDITIONS
 * 	<none>
 *
 * POST-CONDITIONS
 * 	The iterator will point at the next inorder node. Will return an
 * 	incremented version of the operator.
 *************************************************************************/
template <typename ElemType>
typename BinaryTree<ElemType>::Inorder BinaryTree<ElemType>::Inorder::operator--()
{
	//If the iterator has a left child, go to it and then go to the right
	//most child of its subtree.
	if (Iterator::currentNode->GetLeft() != NULL)
	{
		Iterator::currentNode = Iterator::currentNode->GetLeft();

		while (Iterator::currentNode->GetRight() != NULL)
		{
			Iterator::currentNode = Iterator::currentNode->GetRight();
		}
	}
	//Otherwise, if the node is a left child, go up the tree until it is
	//a right child, then go up one more time.
	else
	{
		while (Iterator::currentNode->IsLeftChild())
		{
			Iterator::currentNode = Iterator::currentNode->GetParent();
		}

		Iterator::currentNode = Iterator::currentNode->GetParent();
	}

	//Return the decremented iterator for use in the calling function.
	return *this;
}

/*************************************************************************
 * FUNCTION Inorder::operator--()
 * _______________________________________________________________________
 * Decrements the iterator to the previous node using an inorder traversal.
 * This is the post-decrement version of the operator.
 * _______________________________________________________________________
 * PRE-CONDITIONS
 * 	<none>
 *
 * POST-CONDITIONS
 * 	The iterator will point at the next inorder node. Will return an
 * 	non=incremented version of the operator.
 *************************************************************************/
template <typename ElemType>
typename BinaryTree<ElemType>::Inorder BinaryTree<ElemType>::Inorder::operator--(int)
{
	//VARIABLE DECLERATIONS
	Inorder saveState;//OUT - Stores the pre decerment value of the iterator.

	//VARIABLE INITIALIZATIONS
	saveState = this;

	//Decerement the iterator.
	--this;

	//Return its pre-decrement value for use in the calling function.
	return saveState;
}

#endif /* BINARYTREE_H_ */
