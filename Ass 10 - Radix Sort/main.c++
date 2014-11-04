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
 * Radix Sorting Strings - Assignment 10B
 * -----------------------------------------------------------------------
 * This program tests the implementation of a radix sort on an array of
 * strings.
 * -----------------------------------------------------------------------
 * INPUT -
 * 	array : This is a hardcoded array of strings.
 *
 * OUTPUT -
 * 	array : It is output after each pass of the radix sort.
 *************************************************************************/
int main()
{
	//VARIABLE DECLERATIONS
	string array[10];//IN, PROC, & OUT - The array of strings to sort.

	/*********************************************************************
	 * OUT - Outputs the class header to the console.
	 *********************************************************************/
	ClassHeader("James Marcu", "374443", "CS1D", "TTh 3:30 PM",
			    'A', 10, "Radix Sorting", cout);

	/*********************************************************************
	 * INPUT - The hard coded input is entered into the array.
	 *********************************************************************/
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

	/*********************************************************************
	 * OUT - The unsorted array is output to the console.
	 *********************************************************************/
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

	/*********************************************************************
	 * PROC - The array is sorted.
	 *********************************************************************/
	Radix(array, 10, 4);

	/*********************************************************************
	 * OUT - The now sorted array is output to the console.
	 *********************************************************************/
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

