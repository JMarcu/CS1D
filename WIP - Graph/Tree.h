/*
 * BinaryTree.h
 *
 *  Created on: Sep 22, 2014
 *      Author: James
 */

#ifndef TREE_H_
#define TREE_H_

#include <iostream>
using namespace std;

//Node for a binary tree.
template <class TYPE>
class TreeNode
{
	public:
		TreeNode(TreeNode<TYPE>* parentInit, const TYPE& elemInit)
		{
			parent = parentInit;
			size = 0;
			children = new TreeNode*[0];
			elem = elemInit;
		}
		~TreeNode()
		{
			if(size > 0)
			{
				for (int i = 0; i < size; ++i)
				{
					delete children[i];
					children[i] = NULL;
				}
			}

			children = NULL;
		}

		TreeNode** GetChildren() const
			{return children;}
		int ChildCount() const
			{return size;}
		const TYPE& GetElem() const
			{return elem;}
		TreeNode* GetParent() const
			{return parent;}

		void AddChild(const TYPE& childElem)
		{
			TreeNode*  newChild;
			TreeNode** tempArr;

			++size;
			tempArr = new TreeNode*[size];

			for(int i = 0; i < size-1; ++i)
			{
				tempArr[i] = children[i];
			}

			newChild = new TreeNode(this, childElem);
			tempArr[size-1] = newChild;
			delete children;
			children = tempArr;
		}

	private:
		TYPE elem;     //The data stored in the node.
		TreeNode** children;
		TreeNode*  parent;
		int size;
};

//An unordered binary tree.
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
		bool Empty() const;                //Returns true if tree is empty.
		int Size() const;
		TreeNode<TYPE>* GetRoot() const;
		TreeNode<TYPE>* Search(const TYPE& key) const;
		void Print(TreeNode<TYPE>* start) const
		{
			cout << start->GetElem()->GetElem() << endl;
			if(start->ChildCount() > 0)
			{
				for (int i = 0; i < start->ChildCount(); ++i)
				{
					Print(start->GetChildren()[i]);
				}
			}

		}

	   /*******************************************
		* * * *          MUTATORS           * * * *
		*******************************************/
		void Add(const TYPE& data, TreeNode<TYPE>* parent);       //Adds a node with the data to the tree.


	protected:
		TreeNode<TYPE>* Search(const TYPE& key, TreeNode<TYPE>* start) const;

		void Destroy(TreeNode<TYPE>* start);

		TreeNode<TYPE>* root;//Points to the root node of the tree.
		int size;
};

template <class TYPE>
Tree<TYPE>::Tree()
{
	root = NULL;
	size = 0;
}

template <class TYPE>
Tree<TYPE>::~Tree()
{
	if (root != NULL)
	{
		delete root;
	}
}

template <class TYPE>
bool Tree<TYPE>::Empty() const
{
	return size = 0;
}

template <class TYPE>
int Tree<TYPE>::Size() const
{
	return size;
}

template <class TYPE>
TreeNode<TYPE>* Tree<TYPE>::GetRoot() const
{
	return root;
}

template <class TYPE>
TreeNode<TYPE>* Tree<TYPE>::Search(const TYPE& key) const
{
	TreeNode<TYPE>** children;
	TreeNode<TYPE>*  returnPtr;

	if(root->GetElem() == key)
	{
		return root;
	}
	else if (root->ChildCount() == 0)
	{
		return NULL;
	}
	else
	{
		children = root->GetChildren();

		for(int i = 0; i < root->ChildCount(); ++i)
		{
			if (children[i]->GetElem() == key)
			{
				return children[i];
			}
		}

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

template <class TYPE>
void Tree<TYPE>::Add(const TYPE& data, TreeNode<TYPE>* parent)
{
	if(size != 0)
	{
		parent->AddChild(data);
	}
	else
	{
		root = new TreeNode<TYPE>(NULL, data);
	}

	++size;
}

template <class TYPE>
TreeNode<TYPE>* Tree<TYPE>::Search(const TYPE& key, TreeNode<TYPE>* start) const
{
	TreeNode<TYPE>** children;
	TreeNode<TYPE>*  returnPtr;

	if (start->ChildCount() == 0)
	{
		return NULL;
	}
	else
	{
		children = start->GetChildren();

		for(int i = 0; i < start->ChildCount(); ++i)
		{
			if (children[i]->GetElem() == key)
			{
				return children[i];
			}
		}



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

template <class TYPE>
void Tree<TYPE>::Destroy(TreeNode<TYPE>* start)
{
	while(start->ChildCount() != 0)
	{
	}
}

#endif
