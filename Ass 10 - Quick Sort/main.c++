/*************************************************************************
 * AUTHOR      : James Marcu
 * STUDENT ID  : 374443
 * ASS #10A    : Quick Sort
 * CLASS       : CS1D
 * SECTION     : TTh 3:30 AM
 * DUE DATE    : 11/06/2014
 *************************************************************************/

#include "header.h"

/*************************************************************************
 * Quick Sort Comparison - Assignment 10B
 * -----------------------------------------------------------------------
 * This assignment compares the efficacy of a quick sort on different
 * parameters. The quick sort algorithm is called on integer arrays
 * numbering 3000, 5000, 10000, and 30000 elements. For each size, the
 * algorithm uses the first element, the middle element, and a random
 * element as the pivot. This is repeated three times, with the arrays
 * being ordered the first time, reverse ordered the second, and randomized
 * on the third. Each run is measured by time(ns) and the number of
 * swaps required.
 * -----------------------------------------------------------------------
 * INPUT -
 * 	All input is hard coded. The arrays are filled with either ordered,
 * 	reversed, or randomized integers.
 *
 * OUTPUT -
 * 	The results of the tests are output to the console in formatted
 * 	charts.
 *************************************************************************/
int main()
{
	//VARIABLE DECLERATIONS
	int arr3K [3000]; //PROC & OUT - Stores 3000  integers.
	int arr5K [5000]; //PROC & OUT - Stores 5000  integers.
	int arr10K[10000];//PROC & OUT - Stores 10000 integers.
	int arr30K[30000];//PROC & OUT - Stores 30000 integers.

	/*********************************************************************
	 * OUT - Outputs the class header to the console.
	 *********************************************************************/
	ClassHeader("James Marcu", "374443", "CS1D", "TTh 3:30 PM",
			    'A', 10, "Quick Sort", cout);

	/*********************************************************************
	 * ORDERED ARRAYS
	 *********************************************************************/
	OutputChartHeader("ORDERED");

	//3000 Elements
	ArrayFill(arr3K, 3000, ORDERED);
	OutputQuickSort(0, 2999,  arr3K,  FIRST);

	ArrayFill(arr3K, 3000, ORDERED);
	OutputQuickSort(0, 2999,  arr3K,  MIDDLE);

	ArrayFill(arr3K, 3000, ORDERED);
	OutputQuickSort(0, 2999,  arr3K,  RANDOM);

	//5000 Elements
	ArrayFill(arr5K, 5000, ORDERED);
	OutputQuickSort(0, 4999,  arr5K,  FIRST);

	ArrayFill(arr5K, 5000, ORDERED);
	OutputQuickSort(0, 4999,  arr5K,  MIDDLE);

	ArrayFill(arr5K, 5000, ORDERED);
	OutputQuickSort(0, 4999,  arr5K,  RANDOM);

	//10000 Elements
	ArrayFill(arr10K, 10000, ORDERED);
	OutputQuickSort(0, 9999,  arr10K, FIRST);

	ArrayFill(arr10K, 10000, ORDERED);
	OutputQuickSort(0, 9999,  arr10K, MIDDLE);

	ArrayFill(arr10K, 10000, ORDERED);
	OutputQuickSort(0, 9999,  arr10K, RANDOM);

	//30000 Elements
	ArrayFill(arr30K, 30000, ORDERED);
	OutputQuickSort(0, 29999, arr30K, FIRST);

	ArrayFill(arr30K, 30000, ORDERED);
	OutputQuickSort(0, 29999, arr30K, MIDDLE);

	ArrayFill(arr30K, 30000, ORDERED);
	OutputQuickSort(0, 29999, arr30K, RANDOM);

	cout << endl << endl;


	/*********************************************************************
	 * REVERSE ORDERED ARRAYS
	 *********************************************************************/
	OutputChartHeader("REVERSE ORDERED");

	//3000 Elements
	ArrayFill(arr3K, 3000, REVERSED);
	OutputQuickSort(0, 2999,  arr3K,  FIRST);

	ArrayFill(arr3K, 3000, REVERSED);
	OutputQuickSort(0, 2999,  arr3K,  MIDDLE);

	ArrayFill(arr3K, 3000, REVERSED);
	OutputQuickSort(0, 2999,  arr3K,  RANDOM);

	//5000 Elements
	ArrayFill(arr5K, 5000, REVERSED);
	OutputQuickSort(0, 4999,  arr5K,  FIRST);

	ArrayFill(arr5K, 5000, REVERSED);
	OutputQuickSort(0, 4999,  arr5K,  MIDDLE);

	ArrayFill(arr5K, 5000, REVERSED);
	OutputQuickSort(0, 4999,  arr5K,  RANDOM);

	//10000 Elements
	ArrayFill(arr10K, 10000, REVERSED);
	OutputQuickSort(0, 9999,  arr10K, FIRST);

	ArrayFill(arr10K, 10000, REVERSED);
	OutputQuickSort(0, 9999,  arr10K, MIDDLE);

	ArrayFill(arr10K, 10000, REVERSED);
	OutputQuickSort(0, 9999,  arr10K, RANDOM);

	//30000 Elements
	ArrayFill(arr30K, 30000, REVERSED);
	OutputQuickSort(0, 29999, arr30K, FIRST);

	ArrayFill(arr30K, 30000, REVERSED);
	OutputQuickSort(0, 29999, arr30K, MIDDLE);

	ArrayFill(arr30K, 30000, REVERSED);
	OutputQuickSort(0, 29999, arr30K, RANDOM);

	cout << endl << endl;


	/*********************************************************************
	 * RANDOMIZED ARRAYS
	 *********************************************************************/
	OutputChartHeader("RANDOM NUMBERS");

	//3000 Elements
	ArrayFill(arr3K, 3000, RANDOMIZED);
	OutputQuickSort(0, 2999,  arr3K,  FIRST);

	ArrayFill(arr3K, 3000, RANDOMIZED);
	OutputQuickSort(0, 2999,  arr3K,  MIDDLE);

	ArrayFill(arr3K, 3000, RANDOMIZED);
	OutputQuickSort(0, 2999,  arr3K,  RANDOM);

	//5000 Elements
	ArrayFill(arr5K, 5000, RANDOMIZED);
	OutputQuickSort(0, 4999,  arr5K,  FIRST);

	ArrayFill(arr5K, 5000, RANDOMIZED);
	OutputQuickSort(0, 4999,  arr5K,  MIDDLE);

	ArrayFill(arr5K, 5000, RANDOMIZED);
	OutputQuickSort(0, 4999,  arr5K,  RANDOM);

	//10000 Elements
	ArrayFill(arr10K, 10000, RANDOMIZED);
	OutputQuickSort(0, 9999,  arr10K, FIRST);

	ArrayFill(arr10K, 10000, RANDOMIZED);
	OutputQuickSort(0, 9999,  arr10K, MIDDLE);

	ArrayFill(arr10K, 10000, RANDOMIZED);
	OutputQuickSort(0, 9999,  arr10K, RANDOM);

	//30000 Elements
	ArrayFill(arr30K, 30000, RANDOMIZED);
	OutputQuickSort(0, 29999, arr30K, FIRST);

	ArrayFill(arr30K, 30000, RANDOMIZED);
	OutputQuickSort(0, 29999, arr30K, MIDDLE);

	ArrayFill(arr30K, 30000, RANDOMIZED);
	OutputQuickSort(0, 29999, arr30K, RANDOM);

	cout << endl;

	/*********************************************************************
	 * OUTPUT - The results are analyzed and output to the console.
	 *********************************************************************/
	cout << WordWrap("Using the left most pivot is a bad idea because if"
			         "the array was already sorted (not uncommon) then you "
			         "run in the worst case, which is O(n^2). The best case "
			         "is O(logn) which is a substantial improvement. On "
			         "average there was little difference between a random "
			         "pivot or the middle pivot, but when there was the "
			         "middle pivot came out just slightly better so I "
			         "suppose thats the strategy I would prefer.", 80);
}
