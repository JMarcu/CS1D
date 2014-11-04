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
	int index;
	int count;
	int arr3K [3000];
	int arr5K [5000];
	int arr10K[10000];
	int arr30K[30000];
	int arr50K[50000];

//	for (index = 0; index < 3000; ++index)
//	{
//		arr3K [index] = index + 1;
//		arr5K [index] = index + 1;
//		arr10K[index] = index + 1;
//		arr30K[index] = index + 1;
//		arr50K[index] = index + 1;
//	}
//
//	for (; index < 5000; ++index)
//	{
//		arr5K [index] = index + 1;
//		arr10K[index] = index + 1;
//		arr30K[index] = index + 1;
//		arr50K[index] = index + 1;
//	}
//
//	for (; index < 10000; ++index)
//	{
//		arr10K[index] = index + 1;
//		arr30K[index] = index + 1;
//		arr50K[index] = index + 1;
//	}
//
//	for (; index < 30000; ++index)
//	{
//		arr30K[index] = index + 1;
//		arr50K[index] = index + 1;
//	}
//
//	for (; index < 50000; ++index)
//	{
//		arr50K[index] = index + 1;
//	}
//
//
//
//	OutputChartHeader("ORDERED");
//
//	OutputQuickSort(0, 2999,  arr3K,  FIRST);
//	OutputQuickSort(0, 2999,  arr3K,  MIDDLE);
//	OutputQuickSort(0, 2999,  arr3K,  RANDOM);
//
//	OutputQuickSort(0, 4999,  arr5K,  FIRST);
//	OutputQuickSort(0, 4999,  arr5K,  MIDDLE);
//	OutputQuickSort(0, 4999,  arr5K,  RANDOM);
//
//	OutputQuickSort(0, 9999,  arr10K, FIRST);
//	OutputQuickSort(0, 9999,  arr10K, MIDDLE);
//	OutputQuickSort(0, 9999,  arr10K, RANDOM);
//
//	OutputQuickSort(0, 29999, arr30K, FIRST);
//	OutputQuickSort(0, 29999, arr30K, MIDDLE);
//	OutputQuickSort(0, 29999, arr30K, RANDOM);
//
//	OutputQuickSort(0, 49999, arr50K, FIRST);
//	OutputQuickSort(0, 49999, arr50K, MIDDLE);
//	OutputQuickSort(0, 49999, arr50K, RANDOM);
//
//	cout << endl << endl;
//
//
//
//
//
//
//
//	OutputChartHeader("REVERSE ORDERED");
//
//	count = 3000;
//	for (index = 0; index < 3000; ++index)
//	{
//		arr3K[index] = count;
//		--count;
//	}
//	OutputQuickSort(0, 2999,  arr3K,  FIRST);
//
//	count = 3000;
//	for (index = 0; index < 3000; ++index)
//	{
//		arr3K[index] = count;
//		--count;
//	}
//	OutputQuickSort(0, 2999,  arr3K,  MIDDLE);
//
//	count = 3000;
//	for (index = 0; index < 3000; ++index)
//	{
//		arr3K[index] = count;
//		--count;
//	}
//	OutputQuickSort(0, 2999,  arr3K,  RANDOM);
//
//
//	count = 5000;
//	for (index = 0; index < 5000; ++index)
//	{
//		arr5K[index] = count;
//		--count;
//	}
//	OutputQuickSort(0, 4999,  arr5K,  FIRST);
//
//	count = 5000;
//	for (index = 0; index < 5000; ++index)
//	{
//		arr5K[index] = count;
//		--count;
//	}
//	OutputQuickSort(0, 4999,  arr5K,  MIDDLE);
//
//	count = 5000;
//	for (index = 0; index < 5000; ++index)
//	{
//		arr5K[index] = count;
//		--count;
//	}
//	OutputQuickSort(0, 4999,  arr5K,  RANDOM);
//
//	count = 10000;
//	for (index = 0; index < 10000; ++index)
//	{
//		arr10K[index] = count;
//		--count;
//	}
//	OutputQuickSort(0, 9999,  arr10K, FIRST);
//
//	count = 10000;
//	for (index = 0; index < 10000; ++index)
//	{
//		arr10K[index] = count;
//		--count;
//	}
//	OutputQuickSort(0, 9999,  arr10K, MIDDLE);
//
//	count = 10000;
//	for (index = 0; index < 10000; ++index)
//	{
//		arr10K[index] = count;
//		--count;
//	}
//	OutputQuickSort(0, 9999,  arr10K, RANDOM);
//
//	count = 30000;
//	for (index = 0; index < 30000; ++index)
//	{
//		arr30K[index] = count;
//		--count;
//	}
//	OutputQuickSort(0, 29999, arr30K, FIRST);
//
//	count = 30000;
//	for (index = 0; index < 30000; ++index)
//	{
//		arr30K[index] = count;
//		--count;
//	}
//	OutputQuickSort(0, 29999, arr30K, MIDDLE);
//
//	count = 30000;
//	for (index = 0; index < 30000; ++index)
//	{
//		arr30K[index] = count;
//		--count;
//	}
//	OutputQuickSort(0, 29999, arr30K, RANDOM);
//
//
//	count = 50000;
//	for (index = 0; index < 50000; ++index)
//	{
//		arr50K[index] = count;
//		--count;
//	}
//	OutputQuickSort(0, 49999, arr50K, FIRST);
//
//	count = 50000;
//	for (index = 0; index < 50000; ++index)
//	{
//		arr50K[index] = count;
//		--count;
//	}
//	OutputQuickSort(0, 49999, arr50K, MIDDLE);
//
//	count = 50000;
//	for (index = 0; index < 50000; ++index)
//	{
//		arr50K[index] = count;
//		--count;
//	}
//	OutputQuickSort(0, 49999, arr50K, RANDOM);
//
//	cout << endl << endl;






	OutputChartHeader("RANDOM NUMBERS");

	srand(time(NULL));
	for (index = 0; index < 3000; ++index)
	{
		arr3K [index] = rand() % 3000;
	}
	OutputQuickSort(0, 2999,  arr3K,  FIRST);

	srand(1);
	for (index = 0; index < 3000; ++index)
	{
		arr3K [index] = rand() % 3000;
	}
	OutputQuickSort(0, 2999,  arr3K,  MIDDLE);
	srand(1);
	for (index = 0; index < 3000; ++index)
	{
		arr3K [index] = rand() % 3000;
	}
	OutputQuickSort(0, 2999,  arr3K,  RANDOM);


	srand(1);
	for (index = 0; index < 5000; ++index)
	{
		arr5K [index] = rand() % 3000;
	}
	OutputQuickSort(0, 4999,  arr5K,  FIRST);
	srand(1);
	for (index = 0; index < 5000; ++index)
	{
		arr5K [index] = rand() % 3000;
	}
	OutputQuickSort(0, 4999,  arr5K,  MIDDLE);
	srand(1);
	for (index = 0; index < 5000; ++index)
	{
		arr5K [index] = rand() % 3000;
	}
	OutputQuickSort(0, 4999,  arr5K,  RANDOM);


	srand(1);
	for (index = 0; index < 10000; ++index)
	{
		arr10K [index] = rand() % 3000;
	}
	OutputQuickSort(0, 9999,  arr10K, FIRST);
	srand(1);
	for (index = 0; index < 10000; ++index)
	{
		arr10K [index] = rand() % 3000;
	}
	OutputQuickSort(0, 9999,  arr10K, MIDDLE);
	srand(1);
	for (index = 0; index < 10000; ++index)
	{
		arr10K [index] = rand() % 3000;
	}
	OutputQuickSort(0, 9999,  arr10K, RANDOM);

	srand(1);
	for (index = 0; index < 30000; ++index)
	{
		arr30K [index] = rand() % 3000;
	}
	OutputQuickSort(0, 29999, arr30K, FIRST);
	srand(1);
	for (index = 0; index < 30000; ++index)
	{
		arr30K [index] = rand() % 3000;
	}
	OutputQuickSort(0, 29999, arr30K, MIDDLE);
	srand(1);
	for (index = 0; index < 30000; ++index)
	{
		arr30K [index] = rand() % 3000;
	}
	OutputQuickSort(0, 29999, arr30K, RANDOM);

	srand(1);
	for (index = 0; index < 50000; ++index)
	{
		arr50K [index] = rand() % 3000;
	}
	OutputQuickSort(0, 49999, arr50K, FIRST);
	srand(1);
	for (index = 0; index < 50000; ++index)
	{
		arr50K [index] = rand() % 3000;
	}
	OutputQuickSort(0, 49999, arr50K, MIDDLE);
	srand(1);
	for (index = 0; index < 50000; ++index)
	{
		arr50K [index] = rand() % 3000;
	}
	OutputQuickSort(0, 49999, arr50K, RANDOM);
}
