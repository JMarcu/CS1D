/*************************************************************************
 * AUTHOR      : James Marcu
 * STUDENT ID  : 374443
 * ASS #5      : Binary Trees
 * CLASS       : CS1D
 * SECTION     : TTh 3:30 AM
 * DUE DATE    : 9/16/2014
 *************************************************************************/

#include "header.h"

/*************************************************************************
 * Binary Tree ADT Test - Assignment 5: Binary Trees
 * _______________________________________________________________________
 * This program tests the implementation of the binary tree ADT. It adds
 * a series of characters to the tree then traverses it (printing each node
 * it visits) using inorder, preorder, and postorder algorithms.
 * _______________________________________________________________________
 * INPUT -
 * 	<none> Input into the program is hardcoded as a series of characters
 * 	meant to test the binary tree ADT.
 *
 * OUTPUT -
 * 	The output consists of messages letting the user know what is being
 * 	added onto the tree. It also outputs the order nodes are visited during
 * 	the traversal of the tree.
 *************************************************************************/
int main()
{
	/*********************************************************************
	 * Constants
	 * -------------------------------------------------------------------
	 * USED FOR OUTPUT
	 * -------------------------------------------------------------------
	 * MAIN_PROMPT : Output to user upon program start.
	 *
	 * -------------------------------------------------------------------
	 * USED FOR FORMATTING
	 * -------------------------------------------------------------------
	 * LINE_LENGTH : How long each output line should be at max.
	 *********************************************************************/
	const string MAIN_PROMPT = "This program is designed to test the "
			                   "implementation of a binary tree ADT. It "
			                   "uses hardcoded input to construct and "
			                   "traverse a binary tree.\n\n";
	const int    LINE_LENGTH = 80;

	//VARIABLE INITIALIZATIONS
	BinaryTree<char> alphabetTree;

	//Outputs the class header and main prompt to the console.
	ClassHeader("James Marcu", "374443", "CS1D", "TTh 3:30 PM",
			    'A', 5, "Binary Trees", cout);
	cout << WordWrap(MAIN_PROMPT, LINE_LENGTH);

	//Outputs if the tree is currently empty. It should be.
	cout << "The tree is ";
	if (!alphabetTree.Empty())
	{
		cout << "not ";
	}
	cout << "empty\n\n";

	//Outputs a message letting the user know which letter is being added
	//to the tree. The letter is then added to the tree.
	cout << "Adding 'A' to the binary tree." << endl;
	alphabetTree.Add('A');
	cout << "Adding 'B' to the binary tree." << endl;
	alphabetTree.Add('B');
	cout << "Adding 'C' to the binary tree." << endl;
	alphabetTree.Add('C');
	cout << "Adding 'D' to the binary tree." << endl;
	alphabetTree.Add('D');
	cout << "Adding 'E' to the binary tree." << endl;
	alphabetTree.Add('E');
	cout << "Adding 'F' to the binary tree." << endl;
	alphabetTree.Add('F');
	cout << "Adding 'G' to the binary tree." << endl << endl;
	alphabetTree.Add('G');

	//Outputs if the tree is empty (it shouldn't be) and the size of the
	//tree (should be 7).
	cout << "The tree is ";
	if (!alphabetTree.Empty())
	{
		cout << "not ";
	}
	cout << "empty\n";
	cout << "The tree has " << alphabetTree.Size() << "nodes\n";

	//Traverses the list and prints the nodes using an inorder traversal.
	cout << "Inorder Traversal: ";
	alphabetTree.InorderTraversal();
	cout << endl;

	//Traverses the list and prints the nodes using an preorder traversal.
	cout << "Preorder Traversal: ";
	alphabetTree.PreorderTraversal();
	cout << endl;

	//Traverses the list and prints the nodes using an postorder traversal.
	cout << "Postorder Traversal: ";
	alphabetTree.PostorderTraversal();
	cout << endl << endl;

	cout << "Program has finished and will now exit.";

	return 0;
}
