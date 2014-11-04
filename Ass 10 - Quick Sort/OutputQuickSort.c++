/*************************************************************************
 * AUTHOR      : James Marcu
 * STUDENT ID  : 374443
 * ASS #      : 
 * CLASS       : CS1D
 * SECTION     : TTh 3:30 AM
 * DUE DATE    : 
 *************************************************************************/

#include "header.h"

void OutputQuickSort(int low, int high, int *arr, PivotIndex pivotType)
{
	long long operationsCount;
	timespec  tS;

	operationsCount = 0;
    tS.tv_sec = 0;
    tS.tv_nsec = 0;

    cout << left;
	cout << setw(COL_WIDTH/2)
		 << high + 1
	     << setw(COL_WIDTH)
	     << (pivotType == FIRST  ? "First" :
	    	 pivotType == MIDDLE ? "Middle":
	    		                   "Random");

    clock_settime(CLOCK_PROCESS_CPUTIME_ID, &tS);

    QuickSort(low, high, arr, operationsCount, pivotType);

    clock_gettime(CLOCK_PROCESS_CPUTIME_ID, &tS);

    cout << setw(COL_WIDTH) << tS.tv_nsec
    	 << setw(COL_WIDTH) << operationsCount << endl;
    cout << right;
}

