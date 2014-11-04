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

void QuickSortIterative (int low, int high, int *arr, long long& swapCount, PivotIndex pivotType)
{
	stack<int> sortStack;
	int        pivot;

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
        pivot = Partition(low, high, arr, swapCount, pivotType);

        // If there are elements on left side of pivot, then push left
        // side to stack
        if (pivot - 1 > low)
        {
            sortStack.push(low);
            sortStack.push(pivot - 1);
        }

        // If there are elements on right side of pivot, then push right
        // side to stack
        if (pivot + 1 < high)
        {
            sortStack.push(pivot + 1);
            sortStack.push(high);
        }
    }
}

void QuickSort(int low, int high, int *arr, long long& swapCount, PivotIndex pivotType)
{
  int index;

  if(low < high)
  {
	  cout << "for real?";
	  cin.ignore(1000, '\n');

	  index = Partition(low, high, arr, swapCount, pivotType);
	  cout << index;
	  cin.ignore(1000, '\n');

	  if (index - low > high - index)
	  {
		  cout << low << '-' << high << "***";
		  cin.ignore(1000, '\n');

		  QuickSortIterative(low, index - 1, arr, swapCount, pivotType);

		  cout << low << '-' << high << "**";
		  cin.ignore(1000, '\n');

		  QuickSort(index+1, high, arr, swapCount, pivotType);
	  }
	  else
	  {
		  cout << low << '-' << high << "*" << index;
		  cin.ignore(1000, '\n');

		  QuickSortIterative(index+1, high, arr, swapCount, pivotType);

		  cout << low << '-' << high;
		  cin.ignore(1000, '\n');

		  QuickSort(low, index-1, arr, swapCount, pivotType);
	  }
  }

}
