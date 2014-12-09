/*************************************************************************
 * CS1D Final Project
 * -----------------------------------------------------------------------
 * AUTHORS     : James Marcu & Phillip Doyle
 * STUDENT IDs : 374443      & 911579
 * CLASS       : CS1D
 * SECTION     : TTh 3:30 PM
 * DUE DATE    : 12/9/2014
 *************************************************************************/

#include "header.h"

/*************************************************************************
 * FUNCTION CreateHashMap
 * -----------------------------------------------------------------------
 * This function combines two lists into one, without any duplicates
 * -----------------------------------------------------------------------
 * PRE-CONDITIONS -
 * 	list_one : The list to copy from.
 * 	list_two : The list that is copied into.
 *
 * POST-CONDITIONS -
 * 	list_two will have all non-repeating elements of list_one
 *************************************************************************/
 void Combine_StadiumLists(const List<NFL_Stadium>& List_one,
		                         List<NFL_Stadium>& List_two)
 {
	 List<NFL_Stadium>::Iterator stadiumIt_One;//PROC - Iterates list_one
	 List<NFL_Stadium>::Iterator stadiumIt_Two;//PROC - Iterates list_two
	 bool found;//PROC - True if a member was found to copy.

	 /********************************************************************
	  * PROC - Iterate over every element of list one.
	  ********************************************************************/
	 stadiumIt_One = List_one.Begin();
	 while(stadiumIt_One != List_one.End())
	 {
		found = false;
		stadiumIt_Two = List_two.Begin();

	   /******************************************************************
	    * PROC - Iterate over every element of list two to see if the
	    *        element from list one matches any of them.
	    ******************************************************************/
		while(stadiumIt_Two != List_two.End() && !found)
		 {
			found = (*stadiumIt_One == *stadiumIt_Two);

			stadiumIt_Two++;
		 }

	   /******************************************************************
		* PROC - If the element from list one did not match any element
		*        from list two, then copy it to list two.
	    ******************************************************************/
		if(!found)
		{
			List_two.InsertBack(*stadiumIt_One);
		}

		stadiumIt_One++;
	 }
 }
