/*************************************************************************
 * AUTHOR       : James Marcu
 * STUDENT ID   : 374443
 * EXTRA CREDIT : Huffman Coding
 * CLASS        : CS1D
 * SECTION      : TTh 3:30 AM
 * DUE DATE     : 12/15/14
 *************************************************************************/
#ifndef BINARYTREE_H_
#define BINARYTREE_H_

#include "BinaryTreeNode.h"

//This is a binary tree which is used to create huffman trees for
//huffman encoding.
template <typename ElemType>
class HuffmanTree
{
	protected:
		typedef BTNode<ElemType> node;//Simple typedef of the node.

	public:
	   /*******************************************
		* * * * CONSTRUCTORS AND DESTRUCTOR * * * *
		*******************************************/
		HuffmanTree();                          //Default Constructor
		HuffmanTree(BTNode<ElemType>* rootInit);//Initializes the tree.
		virtual ~HuffmanTree();                 //Destructor.

	   /*******************************************
		* * * *          ACCESSORS          * * * *
		*******************************************/
		int Height() const;                    //The height of the tree.
		int Size() const;                      //The number of nodes.
		int LeafCount() const;                 //The number of external nodes.
		bool Search(const ElemType& key) const;//True if the key is an element.
		string HuffmanSearch(char key) const;  //Returns the huffman code of the key.
		void Print() const;                    //Prints a breadth-first
		                                       //traversal of the tree.

	   /*******************************************
		* * * *          MUTATORS           * * * *
		*******************************************/
		node* GetRoot();                              //Returns the root.
		void Add(const ElemType& newElem);            //Adds a new node.
		virtual bool Delete(const ElemType& toDelete);//Deletes a node.
		void Destroy();                               //Destroys the tree.

	protected:
		node* root;//Root of the tree.

	   /*******************************************
		* * * *          ACCESSORS          * * * *
		*******************************************/
		//Returns the larger of two integers.
		int Max(int x, int y) const;

		//These are private, recursive versions of the above methods.
		int Height(node* rootNode) const;
		int Size(node* rootNode) const;
		virtual node* Search(const ElemType& key, node* rootNode) const;
		string HuffmanSearch(char key, node* rootNode) const;
		void PrintLevel(node* rootNode, int level) const;

	   /*******************************************
		* * * *          MUTATORS           * * * *
		*******************************************/
		//These are private, recursive versions of the above methods.
		virtual void Add(const ElemType& newElem, node* rootNode);
		void Destroy(node* rootNode);
};

/*************************************************************************
 * FUNCTION HuffmanTree
 * _______________________________________________________________________
 * Creates an empty tree.
 * _______________________________________________________________________
 * PRE-CONDITIONS
 * 	<none>
 *
 * POST-CONDITIONS
 * 	Creates an empty tree.
 *************************************************************************/
template <typename ElemType>
HuffmanTree<ElemType>::HuffmanTree()
{
	root = NULL;
}

/*************************************************************************
 * FUNCTION HuffmanTree
 * _______________________________________________________________________
 * Initializes the tree with the provided node.
 * _______________________________________________________________________
 * PRE-CONDITIONS
 * 	rootInit: Will be made the tree's root.
 *
 * POST-CONDITIONS
 * 	Initializes the tree with the provided node.
 *************************************************************************/
template <typename ElemType>
HuffmanTree<ElemType>::HuffmanTree(BTNode<ElemType>* rootInit)
{
	root = rootInit;
}

/*************************************************************************
 * FUNCTION ~HuffmanTree
 * _______________________________________________________________________
 * Safely destroys the tree.
 * _______________________________________________________________________
 * PRE-CONDITIONS
 *  <none>
 *
 * POST-CONDITIONS
 * 	Safely destroys the tree.
 *************************************************************************/
template <typename ElemType>
HuffmanTree<ElemType>::~HuffmanTree()
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
int HuffmanTree<ElemType>::Height() const
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
int HuffmanTree<ElemType>::Height(node* rootNode) const
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
int HuffmanTree<ElemType>::Size() const
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
int HuffmanTree<ElemType>::Size(node* rootNode) const
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

/*************************************************************************
 * FUNCTION Search
 * _______________________________________________________________________
 * Will return true if the key can be found in the tree.
 * _______________________________________________________________________
 * PRE-CONDITIONS
 *  key: The element to look for.
 *
 * POST-CONDITIONS
 * 	Will return true if the key can be found in the tree.
 *************************************************************************/
template <typename ElemType>
bool HuffmanTree<ElemType>::Search(const ElemType& key) const
{
	//If the root has the key return true. Otherwise recursively search
	//the children.
	if(root->GetElem() == key)
	{
		return true;
	}
	else
	{
		return Search(key, root->GetLeft()) !=  NULL ||
			   Search(key, root->GetRight()) != NULL;
	}
}

/*************************************************************************
 * FUNCTION Search
 * _______________________________________________________________________
 * This is a private version of search. It is recursive, and it returns
 * a pointer to the node it finds. It will return NULL if unsuccessful.
 * _______________________________________________________________________
 * PRE-CONDITIONS
 *  key: The element to look for.
 *
 * POST-CONDITIONS
 * 	Will return true if the key can be found in the tree.
 *************************************************************************/
template <typename ElemType>
BTNode<ElemType>* HuffmanTree<ElemType>::Search(const ElemType& key,
		                                        node* rootNode) const
{
	//VARIABLE DECLERATIONS
	node* returnPtr;//Used to store the address of the node it finds.

	//If this node has the key then return a pointer to it.
	if(rootNode->GetElem() == key)
	{
		return rootNode;
	}
	//Otherwise search the children.
	else
	{
		returnPtr = Search(key, rootNode->GetLeft());
		if(returnPtr  == NULL)
		{
			return Search(key, rootNode->GetRight());
		}
		else
		{
			return returnPtr;
		}
	}
}

/*************************************************************************
 * FUNCTION HuffmanSearch
 * _______________________________________________________________________
 * This searches the tree for the provided key and returns its
 * Huffman Code. Its an interface to keep the recursive version private.
 * _______________________________________________________________________
 * PRE-CONDITIONS
 *  key: The element to look for.
 *
 * POST-CONDITIONS
 * 	Will return the huffman code of the key.
 *************************************************************************/
template <typename ElemType>
string HuffmanTree<ElemType>::HuffmanSearch(char key) const
{
	return HuffmanSearch(key, root);
}

/*************************************************************************
 * FUNCTION HuffmanSearch
 * _______________________________________________________________________
 * This searches the tree for the provided key and returns its
 * Huffman Code. This is a private recursive version.
 * _______________________________________________________________________
 * PRE-CONDITIONS
 *  key: The element to look for.
 *
 * POST-CONDITIONS
 * 	Will return the huffman code of the key.
 *************************************************************************/
template <typename ElemType>
string HuffmanTree<ElemType>::HuffmanSearch(char key, node* rootNode) const
{
	//VARIABLE DECLERATIONS
	string code;   //OUT  - Stores the code.
	node*  nodePtr;//PROC - Used to move around the tree.

	//VARIABLE INITIALIZATIONS
	code = "";
	nodePtr = rootNode;

	//If this node has the key then generate the code.
	if(rootNode->GetElem().symbol == key)
	{
		//Move up the tree to the root to create the code.
		while(nodePtr != root)
		{
			if(nodePtr->IsLeftChild())
			{
				code = "0" + code;
			}
			else
			{
				code = "1" + code;
			}

			nodePtr = nodePtr->GetParent();
		}
	}
	//If this node isn't the key then check its children. If it has
	//no children then return an empty string..
	else if (rootNode->GetRight() != NULL)
	{
		code = HuffmanSearch(key, rootNode->GetRight());

		if(code == "")
		{
			code = HuffmanSearch(key, rootNode->GetLeft());
		}
	}
	else if (rootNode->GetLeft() != NULL)
	{
		code = HuffmanSearch(key, rootNode->GetLeft());
	}

	return code;
}

/*************************************************************************
 * FUNCTION Print
 * _______________________________________________________________________
 * Prints the tree using a breadth first traversal.
 * _______________________________________________________________________
 * PRE-CONDITIONS
 *  <none>
 *
 * POST-CONDITIONS
 * 	Prints the tree using a breadth first traversal.
 *************************************************************************/
template <typename ElemType>
void HuffmanTree<ElemType>::Print() const
{
	//If the tree only has one node then output the root.
	if(root->GetLeft() == NULL && root->GetRight() == NULL)
	{
		cout << "ROOT: " << root->GetElem().symbol << endl;
	}
	else
	{
		//For each level run the print level function.
		for(int i = 1; i <= Height(); ++i)
		{
			cout << "Level " << i-1 << ": ";
			PrintLevel(root, i);
			cout << endl;
		}
	}
}

/*************************************************************************
 * FUNCTION PrintLevel
 * _______________________________________________________________________
 * Prints a single level of the tree to the console.
 * _______________________________________________________________________
 * PRE-CONDITIONS
 *  rootNode : The calling node.
 *  level    : The level being printed. May be adjusted.
 *
 * POST-CONDITIONS
 * 	Prints a single level of the tree to the console.
 *************************************************************************/
template <typename ElemType>
void HuffmanTree<ElemType>::PrintLevel(node* rootNode, int level) const
{
	//If the tree is empty then return.
	if(root == NULL)
	{
		return;
	}
	//If level == 1 then output the node.
	else if (level == 1)
	{
		if(rootNode->GetElem().symbol != 0)
		{
			cout << rootNode->GetElem().symbol << "-";
		}
		cout << rootNode->GetElem().weight << " ";
	}
	//If level is greater then one...
	else if(level > 1)
	{
		//Recursively call this function on the children of the calling
		//node using a level that is one smaller.
		if(rootNode->GetLeft() != NULL)
		{
			PrintLevel(rootNode->GetLeft(),  level - 1);
		}

		if(rootNode->GetRight() != NULL)
		{
			PrintLevel(rootNode->GetRight(), level - 1);
		}

	}
}

/*************************************************************************
 * FUNCTION GetRoot
 * _______________________________________________________________________
 * Returns a pointer to the tree's root.
 * _______________________________________________________________________
 * PRE-CONDITIONS
 *  <none>
 *
 * POST-CONDITIONS
 * 	Returns a pointer to the tree's root.
 *************************************************************************/
template <typename ElemType>
BTNode<ElemType>* HuffmanTree<ElemType>::GetRoot()
{
	return root;
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
void HuffmanTree<ElemType>::Add(const ElemType& newElem)
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
void HuffmanTree<ElemType>::Add(const ElemType& newElem, node* rootNode)
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
bool HuffmanTree<ElemType>::Delete(const ElemType& toDelete)
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
void HuffmanTree<ElemType>::Destroy()
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
void HuffmanTree<ElemType>::Destroy(node* rootNode)
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
 * FUNCTION Max
 * _______________________________________________________________________
 * Returns the larger of two integers.
 * _______________________________________________________________________
 * PRE-CONDITIONS
 * 	x: The first integer.
 * 	y: The second integer.
 *
 * POST-CONDITIONS
 * 	Returns the larger of two integers.
 *************************************************************************/
template <typename ElemType>
int HuffmanTree<ElemType>::Max(int x, int y) const
{
	if (x > y)
	{
		return x;
	}
	else
	{
		return y;
	}
}

#endif /* BINARYTREE_H_ */
