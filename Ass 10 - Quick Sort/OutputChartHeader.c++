/*************************************************************************
 * AUTHOR      : James Marcu
 * STUDENT ID  : 374443
 * ASS #      : 
 * CLASS       : CS1D
 * SECTION     : TTh 3:30 AM
 * DUE DATE    : 
 *************************************************************************/

#include "header.h"

void OutputChartHeader(string title)
{
	cout << left;
	cout << title << " -\n";
	cout << setw(COL_WIDTH/2) << "Size(N)"
		 << setw(COL_WIDTH)   << "Pivot Type"
		 << setw(COL_WIDTH)   << "Time (ns)"
		 << setw(COL_WIDTH)   << "Swaps" << endl << endl;
	cout << right;
}

