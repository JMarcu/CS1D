/*************************************************************************
 * AUTHOR      : James Marcu
 * STUDENT ID  : 374443
 * ASS #      : 
 * CLASS       : CS1D
 * SECTION     : TTh 3:30 AM
 * DUE DATE    : 
 *************************************************************************/

#include "List.h"
#include <string>
#include <iostream>
using namespace std;

int main ()
{
	List<string> test;
	List<string>::Iterator testIt;

	test.InsertFront("asdf2");
	test.InsertBack("asdf3");
	testIt = test.Begin();
	test.Insert("asdf1", testIt);
	test.InsertBack("asdf4");


	testIt = test.Begin();
	while(testIt != test.End())
	{
		cout << *testIt << endl;
		++testIt;
	}

	return 0;
}
