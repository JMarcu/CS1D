/*************************************************************************
 * AUTHOR      : James Marcu
 * STUDENT ID  : 374443
 * ASS #      : 
 * CLASS       : CS1D
 * SECTION     : TTh 3:30 AM
 * DUE DATE    : 
 *************************************************************************/

#include "SkipList.h"
#include <string>
#include <iostream>
using namespace std;

int main()
{
	SkipList<int> test;

	test.Insert(1);
//	test.Insert(2);
//	test.Insert(3);
//	test.Insert(4);

//	SkipNode<int>* auxPtr;
//
//	auxPtr = test.Begin();
//
//	while (auxPtr != test.End())
//	{
//		cout << "Level:   " << auxPtr->GetLevel() << endl;
//		cout << "Element: " << auxPtr->GetElem()  << endl << endl;
//
//		if (auxPtr->GetRight() == NULL)
//		{
//			auxPtr = auxPtr->GetDown();
//			while (auxPtr->GetLeft() != NULL)
//			{
//				auxPtr = auxPtr->GetLeft();
//			}
//		}
//		else
//		{
//			auxPtr = auxPtr->GetRight();
//		}
//	}

	return 0;
}
