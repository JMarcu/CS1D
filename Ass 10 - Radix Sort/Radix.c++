/*************************************************************************
 * AUTHOR      : James Marcu
 * STUDENT ID  : 374443
 * ASS #10B    : Radix Sorting
 * CLASS       : CS1D
 * SECTION     : TTh 3:30 AM
 * DUE DATE    : 11/4/2014
 *************************************************************************/

#include "header.h"

/*************************************************************************
 * FUNCTION Radix
 * -----------------------------------------------------------------------
 * This sorts an array of strings using a radix sort.
 * -----------------------------------------------------------------------
 * PRECONDITIONS -
 * 	arr   : The array to sort.
 * 	size  : The number of elements in arr.
 * 	tuple : How many tuples the strings to be sorted are.
 * 	currentTuple : Which tuple is being sorted currently.
 *
 * POSTCONDITIONS -
 * 	arr : It is returned by reference in a sorted state.
 *************************************************************************/
void Radix(string* arr, int size, int tuple, int currentTuple)
{
	//VARIABLE DECLERATIONS
	queue<string> bucket[26];//PROC - A bucket array of queues used to store
	                         //       strings. Each index of the bucket
	                         //       correlates with a letter.
	int           index;     //PROC - Used for iteration.

	/*********************************************************************
	 * PROC - If current tuple is -1 that means this is the initial call
	 *        of Radix() and not a recursive call. We start on the last
	 *        character of the string.
	 *********************************************************************/
	if(currentTuple == -1)
	{
		currentTuple = tuple - 1;
	}

	/*********************************************************************
	 * PROC - Each element in the array is stored into a queue in the
	 *        bucket array. The queue it is stored in is the queue at the
	 *        nth index of the bucket, where n is the current tuple's
	 *        alphabetical number. ie if we are sorting on the 4th
	 *        character, and our string is "bcde", then 'e' is the 5th
	 *        letter of the alphabet. The string "bcde" will then be
	 *        stored in the 5th (index 4) queue of the bucket.
	 *********************************************************************/
	for (index = 0; index < size; ++index)
	{
		bucket[LetterToInt(arr[index][currentTuple]) - 1].push(arr[index]);
	}

	/*********************************************************************
	 * PROC - The array is repopulated in alphabetical order, as determined
	 *        by the characters we just sorted.
	 *********************************************************************/
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

	/*********************************************************************
	 * OUT - The updated array is output to the console.
	 *********************************************************************/
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

	/*********************************************************************
	 * PROC - If the sorting isn't done we recursively call the function
	 *        on the next character.
	 *********************************************************************/
	if (currentTuple > 0)
	{
		Radix(arr, size, tuple, currentTuple - 1);
	}
}


