/*
 * BinaryTree.h
 *
 *  Created on: Sep 22, 2014
 *      Author: James
 */

#ifndef BINARYTREE_H_
#define BINARYTREE_H_

#include <iostream>
using namespace std;

//Node for a binary tree.
template <class TYPE>
struct BTNode
{
	TYPE elem;     //The data stored in the node.
	BTNode* left;  //Points to the left child.
	BTNode* right; //Points to the right child.
	BTNode* parent;//Points to the parent node.

	BTNode()
	{left = NULL; right = NULL; parent = NULL;}//Constructor
};

//An unordered binary tree.
template <class TYPE>
class BinaryTree
{
	public:
	   /*******************************************
	    * * * * CONSTRUCTORS AND DESTRUCTOR * * * *
	    *******************************************/
		BinaryTree(); //Generic constructor.
		~BinaryTree();//Destructor.

	   /*******************************************
		* * * *          ACCESSORS          * * * *
		*******************************************/
		bool Empty() const;                //Returns true if tree is empty.
		void InorderTraversal() const;     //Prints nodes using inorder traversal.
		void PreorderTraversal() const;    //Prints nodes using preorder traversal.
		void PostorderTraversal() const;   //Prints nodes using postorder traversal.
		int  GetHeight() const;            //Returns the height of the tree.
		int  Size() const;                 //Returns the number of nodes in the tree.
		bool Search(const TYPE& key) const;//Returns true if the key is in
		                                   //the tree.

	   /*******************************************
		* * * *          MUTATORS           * * * *
		*******************************************/
		void Add(const TYPE& data);       //Adds a node with the data to the tree.
		void Delete(const TYPE& toDelete);//Deletes a node with the data from the tree.
		void Destroy();                   //Destroys all nodes in the tree.

	protected:
		BTNode<TYPE>* root;//Points to the root node of the tree.

	   /*******************************************
		* * * *          ACCESSORS          * * * *
		*******************************************/
		//These are recursive versions of the public methods seen above. They
		//are kept private to preserve encapsulation.
		void Inorder(BTNode<TYPE>* rootNode) const;
		void Preorder(BTNode<TYPE>* rootNode) const;
		void Postorder(BTNode<TYPE>* rootNode) const;
		int  GetHeight(BTNode<TYPE>* rootNode) const;
		int  Size(BTNode<TYPE>* rootNode) const;
		BTNode<TYPE>* Search(const TYPE& data, BTNode<TYPE>* rootNode) const;
		int  Max(int x, int y) const;//Returns the larger of two ints.

	   /*******************************************
		* * * *          MUTATORS           * * * *
		*******************************************/
		//These are recursive versions of the public methods seen above. They
		//are kept private to preserve encapsulation.
		void Add(const TYPE& data, BTNode<TYPE>* rootNode);
		void Destroy(BTNode<TYPE>* &rootNode);

};

/*************************************************************************
 * FUNCTION BinaryTree (Constructor)
 * _______________________________________________________________________
 * Builds an object of BinaryTree. Sets root to NULL.
 * _______________________________________________________________________
 * PRE-CONDITIONS
 * 	<none>
 *
 * POST-CONDITIONS
 * 	Instantiates a binary tree with a NULL root.
 *************************************************************************/
template <class TYPE>
BinaryTree<TYPE>::BinaryTree()
{
	root = NULL;
}

/*************************************************************************
 * FUNCTION BinaryTree (Destructor)
 * _______________________________________________________________________
 * Calls the destructor of each node.
 * _______________________________________________________________________
 * PRE-CONDITIONS
 * 	<none>
 *
 * POST-CONDITIONS
 * 	Calls the destructor of each node.
 *************************************************************************/
template <class TYPE>
BinaryTree<TYPE>::~BinaryTree()
{
	Destroy();
}

/*************************************************************************
 * FUNCTION Empty
 * _______________________________________________________________________
 * Returns true if the tree is empty.
 * _______________________________________________________________________
 * PRE-CONDITIONS
 * 	<none>
 *
 * POST-CONDITIONS
 * 	Returns true if the tree is empty.
 *************************************************************************/
template <class TYPE>
bool BinaryTree<TYPE>::Empty() const
{
	return root == NULL;
}

/*************************************************************************
 * FUNCTION InorderTraversal
 * _______________________________________________________________________
 * Prints the tree's nodes using an inorder traversal. This is the public
 * version which can only start at the tree's root.
 * _______________________________________________________________________
 * PRE-CONDITIONS
 * 	<none>
 *
 * POST-CONDITIONS
 * 	Prints the tree's nodes using an inorder traversal.
 *************************************************************************/
template <class TYPE>
void BinaryTree<TYPE>::InorderTraversal() const
{
	Inorder(root);
}

/*************************************************************************
 * FUNCTION InorderTraversal
 * _______________________________________________________________________
 * Prints the tree's nodes using an inorder traversal. This is the private
 * version which can be called on any subtree.
 * _______________________________________________________________________
 * PRE-CONDITIONS
 * 	rootNode: The root of the subtree to start the traversal at.
 *
 * POST-CONDITIONS
 * 	Prints the tree's nodes using an inorder traversal.
 *************************************************************************/
template <class TYPE>
void BinaryTree<TYPE>::Inorder(BTNode<TYPE>* rootNode) const
{
	if (rootNode != NULL)
	{
		Inorder(rootNode->left);
		cout << rootNode->elem << " ";
		Inorder(rootNode->right);
	}
}

/*************************************************************************
 * FUNCTION PreorderTraversal
 * _______________________________________________________________________
 * Prints the tree's nodes using an preorder traversal. This is the public
 * version which can only be called on the tree's root.
 * _______________________________________________________________________
 * PRE-CONDITIONS
 * 	<none>
 *
 * POST-CONDITIONS
 * 	Prints the tree's nodes using an preorder traversal.
 *************************************************************************/
template <class TYPE>
void BinaryTree<TYPE>::PreorderTraversal() const
{
	Preorder(root);
}

/*************************************************************************
 * FUNCTION PreorderTraversal
 * _______________________________________________________________________
 * Prints the tree's nodes using an preorder traversal. This is the private
 * version which can be called on any subtree.
 * _______________________________________________________________________
 * PRE-CONDITIONS
 * 	rootNode: The root of the subtree to start the traversal at.
 *
 * POST-CONDITIONS
 * 	Prints the tree's nodes using an preorder traversal.
 *************************************************************************/
template <class TYPE>
void BinaryTree<TYPE>::Preorder(BTNode<TYPE>* rootNode) const
{
	if (rootNode != NULL)
	{
		cout << rootNode->elem << " ";
		Preorder(rootNode->left);
		Preorder(rootNode->right);
	}
}

/*************************************************************************
 * FUNCTION PostorderTraversal
 * _______________________________________________________________________
 * Prints the tree's nodes using an postorder traversal. This is the public
 * version which can only be called on the tree's root.
 * _______________________________________________________________________
 * PRE-CONDITIONS
 * 	<none>
 *
 * POST-CONDITIONS
 * 	Prints the tree's nodes using an postorder traversal.
 *************************************************************************/
template <class TYPE>
void BinaryTree<TYPE>::PostorderTraversal() const
{
	Postorder(root);
}

/*************************************************************************
 * FUNCTION PostorderTraversal
 * _______________________________________________________________________
 * Prints the tree's nodes using an postorder traversal. This is the private
 * version which can be called on any subtree.
 * _______________________________________________________________________
 * PRE-CONDITIONS
 * 	rootNode: The root of the subtree to start the traversal at.
 *
 * POST-CONDITIONS
 * 	Prints the tree's nodes using an postorder traversal.
 *************************************************************************/
template <class TYPE>
void BinaryTree<TYPE>::Postorder(BTNode<TYPE>* rootNode) const
{
	if (rootNode != NULL)
	{
		Postorder(rootNode->left);
		Postorder(rootNode->right);
		cout << rootNode->elem << " ";
	}
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
template <class TYPE>
int BinaryTree<TYPE>::GetHeight() const
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
template <class TYPE>
int BinaryTree<TYPE>::GetHeight(BTNode<TYPE>* rootNode) const
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
		height = 1 + Max(GetHeight(rootNode->left), GetHeight(rootNode->right));
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
template <class TYPE>
int BinaryTree<TYPE>::Size() const
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
template <class TYPE>
int BinaryTree<TYPE>::Size(BTNode<TYPE>* rootNode) const
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
		size = 1 + Size(rootNode->left) + Size(rootNode->right);
	}

	return size;
}

/*************************************************************************
 * FUNCTION Search
 * _______________________________________________________________________
 * Returns true if the provided key can be found in the tree. This is the
 * public version which can only be called on the root.
 * _______________________________________________________________________
 * PRE-CONDITIONS
 * 	key: The data to search the tree for.
 *
 * POST-CONDITIONS
 * 	Returns true if the key is in the tree.
 *************************************************************************/
template <class TYPE>
bool BinaryTree<TYPE>::Search(const TYPE& key) const
{
	return Search(key, root) == NULL;
}

/*************************************************************************
 * FUNCTION Search
 * _______________________________________________________________________
 * Returns a pointer to the node containing the search key. The pointer
 * points to NULL if the key was not found.
 * _______________________________________________________________________
 * PRE-CONDITIONS
 * 	key      : The data to search the tree for.
 * 	rootNode : The root of the subtree to search through.
 *
 * POST-CONDITIONS
 * 	searchPtr: Is returned pointing to the node whose element matches the
 * 	           search key. It will be pointing at NULL if no node was found.
 *************************************************************************/
template <class TYPE>
BTNode<TYPE>* BinaryTree<TYPE>::Search(const TYPE& key, BTNode<TYPE>* rootNode) const
{
	//VARIABLE DECLERATIONS
	BTNode<TYPE>* searchPtr;//OUT - Is returned pointing to the node with
	                        //      the key. Will point at NULL if the key
	                        //      was not found.

	//VARIABLE INITIALIZATIONS
	searchPtr == NULL;

	//First checks if the rootnode is the key.
	if (rootNode->elem == key)
	{
		searchPtr = rootNode;
	}
	else
	{
		//The left subtree is searched.
		if (rootNode->left != NULL)
		{
			searchPtr = Search(key, rootNode->left);
		}

		//If the key is still not found, the right subtree is searched.
		if (searchPtr == NULL && rootNode->right != NULL)
		{
			searchPtr = Search(key, rootNode->right);
		}
	}

	return searchPtr;
}

/*************************************************************************
 * FUNCTION Add
 * _______________________________________________________________________
 * Adds a node with the provided data to the tree. Automatically keeps
 * the tree balanced.
 * _______________________________________________________________________
 * PRE-CONDITIONS
 * 	data: The data to store in the new node.
 *
 * POST-CONDITIONS
 * 	A new node will be added to the tree with the provided data.
 *************************************************************************/
template <class TYPE>
void BinaryTree<TYPE>::Add(const TYPE& data)
{
	//If the tree is empty the noded is added as the root. Otherwise the
	//recursive version of this function is called.
	 if (root == NULL)
	 {
		 root = new BTNode<TYPE>;
		 root->elem   = data;
		 root->left   = NULL;
		 root->right  = NULL;
		 root->parent = NULL;
	 }
	 else
	 {
		 Add(data, root);
	 }
}

/*************************************************************************
 * FUNCTION Add
 * _______________________________________________________________________
 * Adds a node with the provided data to the tree. This is the private
 * recursive version. It automatically keeps the tree balanced.
 * _______________________________________________________________________
 * PRE-CONDITIONS
 * 	data    : The data to store in the new node.
 * 	rootNode: The root of the subtree the node will be added to.
 *
 * POST-CONDITIONS
 * 	A new node will be added to the tree with the provided data.
 *************************************************************************/
template <class TYPE>
void BinaryTree<TYPE>::Add(const TYPE& data, BTNode<TYPE>* rootNode)
{
	//First the algorithm will attempt to add the node to the left of the
	//root node.
	if(rootNode->left == NULL)
	{
		rootNode->left = new BTNode<TYPE>;
		rootNode->left->elem   = data;
		rootNode->left->left   = NULL;
		rootNode->left->right  = NULL;
		rootNode->left->parent = rootNode;
	}
	//Then it will attempt to add it to the right of the root node.
	else if(rootNode->right == NULL)
	{
		rootNode->right = new BTNode<TYPE>;
		rootNode->right->elem   = data;
		rootNode->right->left   = NULL;
		rootNode->right->right  = NULL;
		rootNode->right->parent = rootNode;
	}
	//If the root node already has two children...
	else
	{
		//The algorithm will call itself on the smaller of the two
		//subtrees. If the subtrees are equal it goes to the left.
		if (Size(rootNode->left) <= Size(rootNode->right))
		{
			Add(data, rootNode->left);
		}
		else
		{
			Add(data, rootNode->right);
		}
	}
}

/*************************************************************************
 * FUNCTION Delete
 * _______________________________________________________________________
 * Deletes a node from the tree which contains the provided data. This does
 * not cause the tree to become unbalanced. If the data cannot be found
 * in the tree then no action is taken.
 * _______________________________________________________________________
 * PRE-CONDITIONS
 * 	toDelete: The data stored in the node which is to be deleted.
 *
 * POST-CONDITIONS
 * 	The node will be deleted and the tree updated. If no suitable node
 * 	could be found nothing happens.
 *************************************************************************/
template <class TYPE>
void BinaryTree<TYPE>::Delete(const TYPE& toDelete)
{
	//VARIABLE DECLERATIONS
	BTNode<TYPE>* replacePtr; //Points to the node which will take the place
	                          //of the deleted node in the tree.
	BTNode<TYPE>* delPtr;     //Points at the node which will be deleted.
	bool          isLeftChild;//Whether or not the node being deleted is
	                          //the left child of its parent.

	//VARIABLE INITIALIZATioNS
	replacePtr  = root;
	delPtr      = Search(toDelete, root);
	isLeftChild = true;

	//If the node to be deleted is an external node then it can just be
	//deleted.
	if (delPtr->left != NULL || delPtr->right != NULL)
	{
		//The node which will replace the deleted node is the leftmost node
		//in the tree. This is because due to the nature of the algorithm
		//for adding nodes into the tree, no damage will be done to the
		//balance of the tree if this node is used.
		while (replacePtr->left != NULL)
		{
			replacePtr = replacePtr->left;
		}

		//It is possible for the left most node in the tree to have no left
		//child, but have a right child, if a delete call was previously
		//used and no node has been added since. If this is the case, then
		//the right child is used as the replacement node instead. This
		//is the only case where isLeftChild will be falst.
		if (replacePtr->right != NULL)
		{
			replacePtr = replacePtr->right;
			isLeftChild = false;
		}

		//The replacement node's parent has its child pointer updated to
		//NULL.
		if (isLeftChild)
		{
			replacePtr->parent->left = NULL;
		}
		else
		{
			replacePtr->parent->right = NULL;
		}

		//The replacement node has its parent, left, and right pointers
		//updated to be the same as the to be deleted node.
		replacePtr->parent = delPtr->parent;
		replacePtr->left   = delPtr->left;
		replacePtr->right  = delPtr->right;
	}

	//The node is deleted.
	delete delPtr;
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
template <class TYPE>
void BinaryTree<TYPE>::Destroy()
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
template <class TYPE>
void BinaryTree<TYPE>::Destroy(BTNode<TYPE>* &rootNode)
{
	//If there is a left subtree, Destroy is called on it.
	if (rootNode->left != NULL)
	{
		Destroy(rootNode->left);
	}

	//If there is a right subtree, Destroy is called on it.
	if (rootNode->right != NULL)
	{
		Destroy(rootNode->right);
	}

	//The root of the subtree is deleted.
	delete rootNode;
}

/*************************************************************************
 * FUNCTION Max
 * _______________________________________________________________________
 * Returns the larger of two integers.
 * _______________________________________________________________________
 * PRE-CONDITIONS
 * 	x: An integer, will be returned if greater than y.
 * 	y: An integer, will be returned if greater than x.
 *
 * POST-CONDITIONS
 * 	larger: This is returned with the value of whichever is larger, x or y.
 *************************************************************************/
template <class TYPE>
int BinaryTree<TYPE>::Max(int x, int y) const
{
	//VARIABLE DECLERATIONS
	int larger;//OUT - Will be returned with the value of whichever is
	           //      larger, x or y.

	//Larger is set to the larger of x and y.
	if (x >= y)
	{
		larger = x;
	}
	else
	{
		larger = y;
	}

	return larger;
}

#endif /* BINARYTREE_H_ */
