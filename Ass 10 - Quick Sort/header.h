/*************************************************************************
 * AUTHOR      : James Marcu
 * STUDENT ID  : 374443
 * ASS #      : 
 * CLASS       : CS1D
 * SECTION     : TTh 3:30 AM
 * DUE DATE    : 
 *************************************************************************/
#ifndef HEADER_H_
#define HEADER_H_

#include <time.h>
#include <cstdlib>
#include <iostream>
#include <iomanip>
#include <stack>
#include <string>
using namespace std;

const int COL_WIDTH = 20;

enum PivotIndex
{
	FIRST, MIDDLE, RANDOM
};

void OutputChartHeader(string title);
void OutputQuickSort(int low, int high, int *arr, PivotIndex pivotType);
void QuickSort(int low, int high, int *arr, long long& swapCount, PivotIndex pivotType);

#endif /* HEADER_H_ */
