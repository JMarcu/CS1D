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
 * FUNCTION OutputQuickSort
 * -----------------------------------------------------------------------
 * This wraps the quick sort function with information to track its
 * performance and output the result to the console. It will keep track
 * of the time taken to run, the number of swaps done in the sort, the
 * first ten elements before the sort, and the first ten elements after.
 * These are output to the console when the sort is done in a formatted
 * chart.
 * -----------------------------------------------------------------------
 * INPUT -
 * 	low       : The lowest index of the array to sort.
 * 	high      : The highest index of the array to sort.
 * 	arr       : The array to sort.
 * 	pivotType : Whether the pivot should be the first element, the middle
 * 	            element, or a random element.
 *
 * OUTPUT -
 * 	arr             : This is returned, having been sorted.
 * 	operationsCount : Is output to the console, contains the number of
 * 	                  swaps done by the sort.
 * 	tv_nsex         : Is output to the console, contains the number of
 * 	                  nanoseconds taken by the sort.
 * 	temp            : Is output to the console, contains the first elements
 * 	                  of arr from before the sort.
 *************************************************************************/
void OutputQuickSort(int low, int high, int* arr, PivotIndex pivotType)
{
	//VARIABLE DECLERATIONS
	long long operationsCount;//OUT - Stores number of swaps.
	timespec  tS;             //OUT - Stores time elapsed.
	int       temp[10];       //OUT - Stores the first ten unsorted elements.

	//VARIABLE INITIIALIZATIONS
	operationsCount = 0;
    tS.tv_sec       = 0;
    tS.tv_nsec      = 0;

    //Store the first ten unsorted elements of arr in temp.
    for (int i = 0; i < 10; ++i)
    {
    	temp[i] = arr[i];
    }

    //Output the size and pivot type of the array about to be sorted.
    cout << left;
	cout << setw(COL_WIDTH)
		 << high + 1
	     << setw(COL_WIDTH + 5)
	     << (pivotType == FIRST  ? "First" :
	    	 pivotType == MIDDLE ? "Middle":
	    		                   "Random");

	//Start timing, run the sort, and end timing.
    clock_settime(CLOCK_PROCESS_CPUTIME_ID, &tS);

    QuickSort(low, high, arr, operationsCount, pivotType);

    clock_gettime(CLOCK_PROCESS_CPUTIME_ID, &tS);

    //Output the elapsed time and the number of swaps.
    cout << setw(COL_WIDTH + 5) << tS.tv_nsec
    	 << setw(COL_WIDTH)     << operationsCount;

    //Output the first ten elements of the array before and after it
    //was sorted.
    cout << "UNSORTED: ";
    for (int i = 0; i < 10; ++i)
    {
    	cout << temp[i];
    	if (i != 9)
    		cout << ", ";
    }
    cout << endl;

    cout << setw(50) << ' ' << "SORTED  : ";
    for (int i = 0; i < 10; ++i)
    {
    	cout << arr[i];
    	if (i != 9)
    		cout << ", ";
    }
    cout << endl;

    cout << right;
}

