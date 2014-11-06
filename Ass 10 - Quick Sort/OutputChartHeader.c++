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
 * FUNCTION OutputChartHeader
 * -----------------------------------------------------------------------
 * Outputs a small formatted line of text to act as a 'header' for the
 * charts monitoring quick sort performance.
 * -----------------------------------------------------------------------
 * INPUT -
 * 	title : The title of chart.
 *
 * OUTPUT -
 * 	Sends to the console something that looks like this:
 * 	     title -
 * 	     Size(N)      Pivot Type      Time(ns)      Swaps
 *
 *************************************************************************/
void OutputChartHeader(string title)
{
	cout << left;
	cout << title << " -\n";
	cout << setw(COL_WIDTH)       << "Size(N)"
		 << setw(COL_WIDTH + 5)   << "Pivot Type"
		 << setw(COL_WIDTH + 5)   << "Time (ns)"
		 << setw(COL_WIDTH)       << "Swaps" << endl << endl;
	cout << right;
}

