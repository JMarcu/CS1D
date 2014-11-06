#include "header.h"

/*************************************************************************
 * FUNCTION Partition
 * -----------------------------------------------------------------------
 * This function partitions a set of integers around a pivot. It is called
 * iteratively by the quick sort function. After it is called it guarantees
 * that every number in the range it was given which is lower than the
 * returned index is to the left of the index, and likewise for larger
 * numbers and the right of the index.
 * -----------------------------------------------------------------------
 * INPUT -
 * 	low   	  : The lowest index of the array to sort.
 * 	high  	  : The highest index of the array to sort.
 * 	arr   	  : The array to sort.
 * 	swaps 	  : The number of swaps used to sort the array.
 * 	pivotType : Whether to pivot on the first element, the middle element,
 * 	            or a random element.
 *
 * OUTPUT -
 * 	arr    : This is returned, having been sorted over the given range.
 * 	swaps  : This is returned, having been updated with the number of
 * 	         swaps used during this function.
 * 	hIndex : This is returned pointing to the index of the pivot. Every
 * 	         index (within the provided range) to the left of this has a
 * 	         number less than or equal to the pivot, and every index to the
 * 	         right has a number greater than or equal to the pivot.
 *************************************************************************/
int Partition(int low, int high, int *arr, long long& swaps, PivotIndex pivotType)
{
	//VARIABLE DECLERATIONS
	int hIndex;//PROC & OUT - Stores the index of the higher number being
	           //             sorted. Is returned pointing at the pivot.
    int lIndex;//PROC       - Stores the index of the lower number being
               //             sorted.
    int pivot; //PROC       - The value, not index, of the pivot.
    int temp;  //PROC       - Used to temporarily store values during swaps.

    //VARIABLE INITIALIZATIONS
    lIndex = low;
    hIndex = high;

    /*********************************************************************
     * PROC - Set the pivot based on the pivot type.
     *********************************************************************/
    switch(pivotType)
    {
		case FIRST:
		  pivot = arr[low];
		  break;

		case MIDDLE:
		  pivot = arr[((high - low) / 2) + low];
		  break;

		case RANDOM:
		  srand(time(NULL));
		  pivot = arr[(rand() % (high - low)) + low];
		  break;
    }

    /*********************************************************************
     * PROC - This loop will run as long as the index of the lower number
     *        being sorted is lower than the index of the higher number
     *        being sorted.
     *********************************************************************/
    while(lIndex < hIndex)
    {
        /*****************************************************************
         * PROC - If lIndex's number is less than the pivot it is already
         *        sorted and lIndex goes up until it finds one that isn't.
         *****************************************************************/
    	while(arr[lIndex] < pivot)
		{
		   lIndex++;
		}

        /*****************************************************************
         * PROC - If hIndex's number is greater than the pivot it is
         *        already sorted and hIndex goes up until it finds one
         *        that isn't.
         *****************************************************************/
		while(arr[hIndex] > pivot)
		{
			hIndex--;
		}

        /*****************************************************************
         * PROC - If lIndex is less than hIndex and they have both found
         *        unsorted numbers, then the numbers are swapped. The
         *        higher number is now on the right of the pivot and the
         *        lower number is now on its left.
         *****************************************************************/
		if(lIndex < hIndex)
		{
			/*************************************************************
			 * PROC - If the two numbers are equal then they must be the
			 *        same value as the pivot. If this is the case then
			 *        hIndex simply decrements passed it and it is sorted
			 *        in a later call.
			 *
			 *        Otherwise, the swap proceeds as normal.
			 *************************************************************/
			if(arr[lIndex] == arr[hIndex])
			{
				hIndex--;
			}
			else
			{
				temp        = arr[lIndex];
				arr[lIndex] = arr[hIndex];
				arr[hIndex] = temp;
				++swaps;
			}
		}
    }

    return hIndex;
}

/*************************************************************************
 * FUNCTION QuickSort
 * -----------------------------------------------------------------------
 * This function is an iterative sorting function. It uses a pivot to
 * organize subsets of the array as being less than and greater than or
 * equal to the pivot. It then iterates over those subsections. This
 * continues until the array is sorted.
 * -----------------------------------------------------------------------
 * INPUT -
 * 	low   	  : The lowest index of the array to sort.
 * 	high  	  : The highest index of the array to sort.
 * 	arr   	  : The array to sort.
 * 	swaps 	  : The number of swaps used to sort the array.
 * 	pivotType : Whether to pivot on the first element, the middle element,
 * 	            or a random element.
 *
 * OUTPUT -
 * 	arr    : This is returned, having been sorted over the given range.
 * 	swaps  : This is returned, having been updated with the number of
 * 	         swaps used during this function.
 *************************************************************************/
void QuickSort (int low, int high, int *arr, long long& swapCount, PivotIndex pivotType)
{
	//VARIABLE DECLERATIONS
	stack<int> sortStack; //PROC - This stores the low-high index pairs
	                      //       that still need to be iterated over.
	int        pivotIndex;//PROC - Stores the index of the current pivot.

    /*********************************************************************
     * PROC - High and low are pushed onto the stack as its initial values.
     *********************************************************************/
    sortStack.push(low);
    sortStack.push(high);

    /*********************************************************************
     * PROC - Since the stack stores the ranges of the array to be
     *        iterated over, the function will loop until the stack is
     *        empty indicating that all ranges of the array are sorted.
     *********************************************************************/
    while (!sortStack.empty())
    {
        /*****************************************************************
         * PROC - The range to iterate over is retrieved form the stack.
         *****************************************************************/
        high = sortStack.top();
        sortStack.pop();

        low = sortStack.top();
        sortStack.pop();

        /*****************************************************************
         * PROC - The range is partitioned and the index of the pivot is
         *        returned.
         *****************************************************************/
        pivotIndex = Partition(low, high, arr, swapCount, pivotType);

        /*****************************************************************
         * PROC - If there are elements to the left of the pivot then
         *        that range is added to the stack.
         *****************************************************************/
        if (pivotIndex - 1 > low)
        {
            sortStack.push(low);
            sortStack.push(pivotIndex - 1);
        }

        /*****************************************************************
         * PROC - If there are elements to the right of the pivot then
         *        that range is added to the stack.
         *****************************************************************/
        if (pivotIndex + 1 < high)
        {
            sortStack.push(pivotIndex + 1);
            sortStack.push(high);
        }
    }
}
