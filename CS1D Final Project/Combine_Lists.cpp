/*************************************************************************
 * CS1D Final Project
 * -----------------------------------------------------------------------
 * AUTHORS     : James Marcu & Phillip Doyle
 * STUDENT IDs : 374443      & 911579
 * CLASS       : CS1D
 * SECTION     : TTh 3:30 AM
 * DUE DATE    : 12/9/2014
 *************************************************************************/

#include "header.h"

/*************************************************************************
 * FUNCTION CreateHashMap
 * -----------------------------------------------------------------------
 * This function combines two lists into one, without any duplicates
 * -----------------------------------------------------------------------
 * PRE-CONDITIONS -
 * 	list_one
 * 	list_two
 *
 * POST-CONDITIONS -
 * 	list_One will have all non-repeating elements from list_two
 *************************************************************************/
 void Combine_StadiumLists(const List<NFL_Stadium>& List_one,
		 List<NFL_Stadium>& List_two)
 {
	 List<NFL_Stadium>::Iterator stadiumIt_One;
	 List<NFL_Stadium>::Iterator stadiumIt_Two;
	 bool	found;


	 stadiumIt_One = List_one.Begin();
	 while(stadiumIt_One != List_one.End())
	 {
		found = false;
		stadiumIt_Two = List_two.Begin();

		while(stadiumIt_Two != List_two.End() && !found)
		 {
			found = (*stadiumIt_One == *stadiumIt_Two);

			stadiumIt_Two++;
		 }
		if(!found)
		{
			List_two.InsertBack(*stadiumIt_One);
		}
		stadiumIt_One++;
	 }
 }
