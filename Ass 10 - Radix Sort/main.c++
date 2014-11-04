/*************************************************************************
 * AUTHOR      : James Marcu
 * STUDENT ID  : 374443
 * ASS #      : 
 * CLASS       : CS1D
 * SECTION     : TTh 3:30 AM
 * DUE DATE    : 
 *************************************************************************/

#include "header.h"

int main()
{
	string array[10];

	array[0] = "abcd";
	array[1] = "lsds";
	array[2] = "ksjt";
	array[3] = "ktrp";
	array[4] = "absw";
	array[5] = "azba";
	array[6] = "rkds";
	array[7] = "dddd";
	array[8] = "kdfa";
	array[9] = "zedz";

	cout << "UNSORTED - \n";
	for (int i = 0; i < 10; ++i)
	{
		cout << array[i];
		if (i != 9)
		{
			cout << ", ";
		}
	}
	cout << endl << endl;

	Radix(array, 10, 4);

	cout << "SORTED - \n";
	for (int i = 0; i < 10; ++i)
	{
		cout << array[i];
		if(i != 9)
		{
			cout << ", ";
		}
	}

	return 0;
}

