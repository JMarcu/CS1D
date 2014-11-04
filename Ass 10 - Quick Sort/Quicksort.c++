#include "header.h"

//Function for partitioning array
int Partition(int low, int high, int *arr, long long& swaps, PivotIndex pivotType)
{
	int hIndex;
    int lIndex;
    int pivot;
    int temp;

    hIndex = high;
    lIndex = low;

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

    while(lIndex < hIndex)
    {
    	while(arr[lIndex] < pivot)
		{
		   lIndex++;
		}

		while(arr[hIndex] > pivot)
		{
			hIndex--;
		}

		if(lIndex < hIndex)
		{
			temp        = arr[lIndex];
			arr[lIndex] = arr[hIndex];
			arr[hIndex] = temp;
			++swaps;
		}
    }

    return hIndex;
}

void QuickSort (int low, int high, int *arr, long long& swapCount, PivotIndex pivotType)
{
	stack<int> sortStack;
	int        pivotIndex;

    // push initial values of l and h to stack
    sortStack.push(low);
    sortStack.push(high);

    // Keep popping from stack while is not empty
    while (!sortStack.empty())
    {
        // Pop h and l
        high = sortStack.top();
        sortStack.pop();

        low = sortStack.top();
        sortStack.pop();

        // Set pivot element at its correct position in sorted array
        pivotIndex = Partition(low, high, arr, swapCount, pivotType);

        // If there are elements on left side of pivot, then push left
        // side to stack
        if (pivotIndex - 1 > low)
        {
            sortStack.push(low);
            sortStack.push(pivotIndex - 1);
        }

        // If there are elements on right side of pivot, then push right
        // side to stack
        if (pivotIndex + 1 < high)
        {
            sortStack.push(pivotIndex + 1);
            sortStack.push(high);
        }
    }
}
