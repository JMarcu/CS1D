/*************************************************************************
 * AUTHOR      : James Marcu
 * STUDENT ID  : 374443
 * ASS #      : 
 * CLASS       : CS1D
 * SECTION     : TTh 3:30 AM
 * DUE DATE    : 
 *************************************************************************/

#include "MinHeap.h"

int main()
{
	Heap<int> tree;

	cout << "Adding 88 to the heap.\n";
	tree.Add(88);
	cout << "The heap using inorder traversal: ";
	tree.InorderTraversal();
	cout << endl << endl;

	cout << "Adding 22 to the heap.\n";
	tree.Add(22);
	cout << "The heap using inorder traversal: ";
	tree.InorderTraversal();
	cout << endl << endl;

	cout << "Adding 77 to the heap.\n";
	tree.Add(77);
	cout << "The heap using inorder traversal: ";
	tree.InorderTraversal();
	cout << endl << endl;

	cout << "Adding 55 to the heap.\n";
	tree.Add(55);
	cout << "The heap using inorder traversal: ";
	tree.InorderTraversal();
	cout << endl << endl;

	cout << "Adding 44 to the heap.\n";
	tree.Add(44);
	cout << "The heap using inorder traversal: ";
	tree.InorderTraversal();
	cout << endl << endl;

	cout << "Adding 11 to the heap.\n";
	tree.Add(11);
	cout << "The heap using inorder traversal: ";
	tree.InorderTraversal();
	cout << endl << endl;

	cout << "Adding 66 to the heap.\n";
	tree.Add(66);
	cout << "The heap using inorder traversal: ";
	tree.InorderTraversal();
	cout << endl << endl;

	cout << "Adding 33 to the heap.\n";
	tree.Add(33);
	cout << "The heap using inorder traversal: ";
	tree.InorderTraversal();
	cout << endl << endl;

	return 0;
}
