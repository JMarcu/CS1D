/*************************************************************************
 * AUTHOR      : James Marcu
 * STUDENT ID  : 374443
 * ASS #      : 
 * CLASS       : CS1D
 * SECTION     : TTh 3:30 AM
 * DUE DATE    : 
 *************************************************************************/

#include "header.h"

void Radix(string* arr, int size, int tuple, int currentTuple)
{
	queue<string> bucket[26];
	int           index;

	if(currentTuple == -1)
	{
		currentTuple = tuple - 1;
	}

	for (index = 0; index < size; ++index)
	{
		bucket[LetterToInt(arr[index][currentTuple]) - 1].push(arr[index]);
	}

	index = 0;
	for (int i = 0; i < 26; ++i)
	{
		while (!bucket[i].empty())
		{
			arr[index] = bucket[i].front();
			bucket[i].pop();
			++index;
		}
	}

	cout << "RADIX SORTED OVER LETTER " << currentTuple + 1 << " - \n";
	for (int i = 0; i < 10; ++i)
	{
		cout << arr[i];
		if (i != 9)
		{
			cout << ", ";
		}
	}
	cout << endl << endl;

	if (currentTuple > 0)
	{
		Radix(arr, size, tuple, currentTuple - 1);
	}
}


