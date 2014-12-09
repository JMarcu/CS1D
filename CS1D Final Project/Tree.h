/*************************************************************************
 * CS1D Final Project
 * -----------------------------------------------------------------------
 * AUTHORS     : James Marcu & Phillip Doyle
 * STUDENT IDs : 374443      & 911579
 * CLASS       : CS1D
 * SECTION     : TTh 3:30 PM
 * DUE DATE    : 12/9/2014
 *************************************************************************/
#ifndef TREE_H_
#define TREE_H_

#include <cstddef>
using namespace std;

//Node for a tree
template <class TYPE>
class TreeNode
{
	public:
	   /*******************************************
	    * * * * CONSTRUCTORS AND DESTRUCTOR * * * *
	    *******************************************/
		//Constructs a node with the provided parent and element.
		TreeNode(TreeNode<TYPE>* parentInit, const TYPE& elemInit)
		{
			parent = parentInit;
			size = 0;
			children = new TreeNode*[0];
			elem = elemInit;
		}
		~TreeNode()//Safely destructs the node since its children are all dynamic.
		{
			if(size > 0)
			{
				for (int i = 0; i < size; ++i)
				{
					delete children[i];
					children[i] = NULL;
				}
			}
			delete[] children;
			children = NULL;
		}

	   /*******************************************
		* * * *          ACCESSORS          * * * *
		*******************************************/
		TreeNode** GetChildren() const//Returns an array of pointers to its children.
			{return children;}
		int ChildCount() const        //Returns the number of children.
			{return size;}
		const TYPE& GetElem() const   //Returns a reference to its element.
			{return elem;}
		TreeNode* GetParent() const   //Returns a pointer to its parent.
			{return parent;}


	   /*******************************************
		* * * *          MUTATORS           * * * *
		*******************************************/
		void AddChild(const TYPE& childElem)
		{
			//VARIABLE DECLERATIONS
			TreeNode*  newChild;//PROC - Used to build the new node.
			TreeNode** tempArr; //PROC - Used to build a new children array.

			//Increment size and create a new child array of that size.
			++size;
			tempArr = new TreeNode*[size];

			//Copy over the information from the old array.
			for(int i = 0; i < size-1; ++i)
			{
				tempArr[i] = children[i];
			}

			//Create a new child node and add it to the child array.
			newChild = new TreeNode(this, childElem);
			tempArr[size-1] = newChild;

			//Delete the old array and have children point to the new one.
			delete[] children;
			children = tempArr;
		}

	private:
		TYPE elem;          //The data stored in the node.
		TreeNode** children;//A dynamic array of pointers to child nodes.
		TreeNode*  parent;  //A pointer to the node's parent node.
		int size;           //The number of children this node has.
};

//An unordered tree.
template <class TYPE>
class Tree
{
	public:
	   /*******************************************
	    * * * * CONSTRUCTORS AND DESTRUCTOR * * * *
	    *******************************************/
		Tree(); //Generic constructor.
		~Tree();//Destructor.


	   /*******************************************
		* * * *          ACCESSORS          * * * *
		*******************************************/
		bool Empty() const;             //Returns true if tree is empty.
		int Size() const;               //Returns the size of the tree.
		TreeNode<TYPE>* GetRoot() const;//Returns a pointer to the root.
		TreeNode<TYPE>* Search(const TYPE& key) const;//Returns a pointer to
		                                              //the node containing
		                                              //the key

	   /*******************************************
		* * * *          MUTATORS           * * * *
		*******************************************/
		void Add(const TYPE& data, TreeNode<TYPE>* parent);//Adds a node.


	protected:
		//A recursive version of search.
		TreeNode<TYPE>* Search(const TYPE& key, TreeNode<TYPE>* start) const;

		TreeNode<TYPE>* root;//Points to the root node of the tree.
		int size;            //The number of nodes in the tree.
};

/*************************************************************************
 * METHOD Constructor
 * -----------------------------------------------------------------------
 * Default constructor.
 * -----------------------------------------------------------------------
 * PRE-CONDITIONS -
 * 	<none>
 *
 * POST-CONDITIONS -
 * 	Constructs an object of class tree.
 *************************************************************************/
template <class TYPE>
Tree<TYPE>::Tree()
{
	root = NULL;
	size = 0;
}

/*************************************************************************
 * METHOD Destructor
 * -----------------------------------------------------------------------
 * Safely deconstructs a tree.
 * -----------------------------------------------------------------------
 * PRE-CONDITIONS -
 * 	<none>
 *
 * POST-CONDITIONS -
 * 	The tree is safely destroyed.
 *************************************************************************/
template <class TYPE>
Tree<TYPE>::~Tree()
{
	if (root != NULL)
	{
		delete root;
	}
}

/*************************************************************************
 * METHOD Empty
 * -----------------------------------------------------------------------
 * Returns true if the tree is empty.
 * -----------------------------------------------------------------------
 * PRE-CONDITIONS -
 * 	<none>
 *
 * POST-CONDITIONS -
 * 	Returns true if the tree is empty.
 *************************************************************************/
template <class TYPE>
bool Tree<TYPE>::Empty() const
{
	return size = 0;
}

/*************************************************************************
 * METHOD Size
 * -----------------------------------------------------------------------
 * Returns the number of nodes in the tree.
 * -----------------------------------------------------------------------
 * PRE-CONDITIONS -
 * 	<none>
 *
 * POST-CONDITIONS -
 * 	Returns the number of nodes in the tree.
 *************************************************************************/
template <class TYPE>
int Tree<TYPE>::Size() const
{
	return size;
}

/*************************************************************************
 * METHOD GetRoot
 * -----------------------------------------------------------------------
 * Returns a pointer to the root node of the tree.
 * -----------------------------------------------------------------------
 * PRE-CONDITIONS -
 * 	<none>
 *
 * POST-CONDITIONS -
 * 	Returns a pointer to the root node of the tree.
 *************************************************************************/
template <class TYPE>
TreeNode<TYPE>* Tree<TYPE>::GetRoot() const
{
	return root;
}

/*************************************************************************
 * METHOD Search
 * -----------------------------------------------------------------------
 * Returns a pointer to the node containing the provided key.
 * -----------------------------------------------------------------------
 * PRE-CONDITIONS -
 * 	key : The element to search the tree for.
 *
 * POST-CONDITIONS -
 * 	returnPtr : Will be returned pointing to the node containing the
 * 	            provided key. NULL if not found.
 *************************************************************************/
template <class TYPE>
TreeNode<TYPE>* Tree<TYPE>::Search(const TYPE& key) const
{
	//VARIABLE DECLERATIONS
	TreeNode<TYPE>** children; //Points to the children of a node.
	TreeNode<TYPE>*  returnPtr;//Points to the result of the search.

	//If the root is the node you're looking for then return it.
	if(root->GetElem() == key)
	{
		return root;
	}
	//Otherwise, if the root has no children, it wasn't found. Return null.
	else if (root->ChildCount() == 0)
	{
		return NULL;
	}
	//If there are children then...
	else
	{
		//Set children to point to the root's children.
		children = root->GetChildren();

		//Search each child to see if it holds the key. If it does then
		//return that node.
		for(int i = 0; i < root->ChildCount(); ++i)
		{
			if (children[i]->GetElem() == key)
			{
				return children[i];
			}
		}

		//If the key is still not found then run a recursive search on
		//each child.
		for(int i = 0; i < root->ChildCount(); ++i)
		{
			returnPtr = Search(key, children[i]);
			if (returnPtr != NULL)
			{
				return returnPtr;
			}
		}
	}
}

/*************************************************************************
 * METHOD Search
 * -----------------------------------------------------------------------
 * This is a private, recursive version of the search method.
 * -----------------------------------------------------------------------
 * PRE-CONDITIONS -
 * 	key    : The element to search the tree for.
 * 	start  : Where to start the recursive search.
 *
 * POST-CONDITIONS -
 * 	returnPtr : Will be returned pointing to the node containing they key,
 * 	            or NULL if it couldn't be found.
 *************************************************************************/
template <class TYPE>
TreeNode<TYPE>* Tree<TYPE>::Search(const TYPE& key, TreeNode<TYPE>* start) const
{
	//VARIABLE DECLERATIONS
	TreeNode<TYPE>** children; //Points to the children of a node.
	TreeNode<TYPE>*  returnPtr;//Points to the result of the search.

	//If there are no children then it couldn't be found here. Return NULL.
	if (start->ChildCount() == 0)
	{
		return NULL;
	}
	else
	{
		children = start->GetChildren();

		//Search each child to see if it contains the key. If it does
		//then return it.
		for(int i = 0; i < start->ChildCount(); ++i)
		{
			if (children[i]->GetElem() == key)
			{
				return children[i];
			}
		}

		//If the key hasn't been found then run the search on each of
		//this node's children.
		for(int i = 0; i < start->ChildCount(); ++i)
		{
			returnPtr = Search(key, children[i]);
			if (returnPtr != NULL)
			{
				return returnPtr;
			}
		}
	}
}

/*************************************************************************
 * METHOD Add
 * -----------------------------------------------------------------------
 * Adds a new node to the tree.
 * -----------------------------------------------------------------------
 * PRE-CONDITIONS -
 * 	data   : The element to put in the new node.
 * 	parent : Points to the node that should be the parent of the new node.
 *
 * POST-CONDITIONS -
 * 	Will construct and add a new node to the tree.
 *************************************************************************/
template <class TYPE>
void Tree<TYPE>::Add(const TYPE& data, TreeNode<TYPE>* parent)
{
	if(size != 0)
	{
		//Run the AddChild method of its parent node.
		parent->AddChild(data);
	}
	else
	{
		//If there are no nodes in the tree then make the new node the
		//root.
		root = new TreeNode<TYPE>(NULL, data);
	}

	//Increment the size counter.
	++size;
}

#endif
