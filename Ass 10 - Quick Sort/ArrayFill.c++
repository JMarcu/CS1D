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
 * FUNCTION ArrayFill
 * -----------------------------------------------------------------------
 * This fills arrays according to different paramaters.
 * -----------------------------------------------------------------------
 * INPUT -
 * 	arr      : The array to fill.
 * 	size     : The size of the array.
 * 	fillType : Whether the array elements should be ordered, reverse
 * 	           ordered, or randomized.
 *
 * OUTPUT -
 * 	arr      : The array will be filled when the function ends.
 *************************************************************************/
void ArrayFill(int* arr, int size, ArrayType fillType)
{
	switch(fillType)
	{
	case ORDERED:    //Ordered from 1-N.
		for (int index = 0; index < size; ++index)
		{
			arr[index] = index + 1;
		}
		break;
	case REVERSED:   //Reverse ordered from N-1.
		for (int index = size - 1; index >= 0; --index)
		{
			arr[index] = size - index;
		}
		break;
	case RANDOMIZED: //All elements are randomized.
		srand(time(NULL));
		for (int index = 0; index < size; ++index)
		{
			arr[index] = rand() % 30000;
		}
		break;
	}
}

