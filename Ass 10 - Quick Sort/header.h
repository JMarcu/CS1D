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

/*************************************************************************
 * CONSTANTS
 * -----------------------------------------------------------------------
 * USED FOR FORMATTING
 * -----------------------------------------------------------------------
 * COL_WIDTH : The width of the columns in the quick-sort charts.
 *************************************************************************/
//USED FOR FORMATTING
const int COL_WIDTH = 10;

//Used for ArrayFill() to determine how to fill the array.
enum ArrayType
{
	ORDERED, REVERSED, RANDOMIZED
};

//Used by QuickSort() to decide which index to use as the pivot.
enum PivotIndex
{
	FIRST, MIDDLE, RANDOM
};

/*************************************************************************
 * FUNCTION ArrayFill
 * 	This fills arrays according to different parameters.
 *************************************************************************/
void ArrayFill(int* arr, int size, ArrayType fillType);

/*************************************************************************
 * FUNCTION OutputChartHeader
 *	Outputs a small formatted line of text to act as a 'header' for the
 *  charts monitoring quick sort performance.
 *************************************************************************/
void OutputChartHeader(string title);

/*************************************************************************
 * FUNCTION OutputQuickSort
 *  This wraps the quick sort function with information to track its
 *  performance and output the result to the console. It will keep track
 *  of the time taken to run, the number of swaps done in the sort, the
 *  first ten elements before the sort, and the first ten elements after.
 *  These are output to the console when the sort is done in a formatted
 *  chart.
 *************************************************************************/
void OutputQuickSort(int low, int high, int *arr, PivotIndex pivotType);

/*************************************************************************
 * FUNCTION QuickSort
 *  This function is an iterative sorting function. It uses a pivot to
 *  organize subsets of the array as being less than and greater than or
 *  equal to the pivot. It then iterates over those subsections. This
 *  continues until the array is sorted.
 *************************************************************************/
void QuickSort(int low, int high, int *arr, long long& swapCount, PivotIndex pivotType);

/*************************************************************************
 * FUNCTION ClassHeader
 * 	 This function takes in the programmer's name(s), the class name, and
 *	 the class section. The next argument is assignment type (assType)
 *	 which may be an 'L', or any other character (typically an 'A'). If it
 *	 is set to 'L' then the header will use the word "LAB", else it will
 *	 use the word "ASSIGNMENT" when describing the program. The parameter
 *	 assType is not case sensitive. The parameters assNum and assName
 *	 accept the name of the assignment's name and number. The function will
 *	 output a class heading based on the provided information
 *************************************************************************/
void ClassHeader (string   programmer,//IN & OUT - Programmer's name(s)
				  string   id,        //IN & OUT - Programmer's student
				                      //           id(s)
				  string   className, //IN & OUT - Name of the class this
				                      //           lab/assignment is for.
				  string   section,   //IN & OUT - Section of the class the
					                  //           author is enrolled in
				  char     assType,   //IN & OUT - A character which lets
				                      //           the function know if
					                  //           this is a lab or an
				                      //           assignment.
			      int      assNum,    //IN & OUT - The number of the lab or
					                  //           assignment.
				  string   assName,   //IN & OUT - The name of the lab or
                                      //           assignment.
				  ostream& outStream);//IN       - The stream to output to.

/*************************************************************************
 * FUNCTION WordWrap
 * 	This will read in a string and a margin to fit that string into. It
 * 	will parse through the string and create a version of it with new
 * 	line characters before words that don't fit in the margins. This new
 * 	string is returned to be output.
 *************************************************************************/
string WordWrap(string toWrap,     //IN - The string to be word wrapped.
		        int    lineLength);//IN - The width of the line to fit
                                   //     your string into.

#endif /* HEADER_H_ */
