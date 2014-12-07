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
 * FUNCTION PrintList
 * -----------------------------------------------------------------------
 * This will output the contents of a stadium list to the console.
 * -----------------------------------------------------------------------
 * PRE-CONDITIONS -
 * 	printThis : The list of stadiums which are to be printed.
 *
 * POST-CONDITIONS -
 * 	The information for the stadiums in printThis will be output to the
 * 	console.
 *************************************************************************/
void PrintList(const List<NFL_Stadium>& printThis)
{
	/*********************************************************************
	 * VARIABLE DECLERATIONS
	 *********************************************************************/
	//PROC - Used to iterate through the list.
	List<NFL_Stadium>::Iterator stadiumIt;

	//PROC - Used to iterate through a stadium's list of teams.
	List<Team>::Iterator teamIt;

	/*********************************************************************
	 * VARIABLE INITIALIZATIONS
	 *********************************************************************/
	stadiumIt = printThis.Begin();

	/*********************************************************************
	 * OUT - Outputs the headers for the table.
	 *********************************************************************/
	cout << left;
	cout << setw(39) << "Team Name" << '|' << "Stadium" << endl;
	cout << setfill('-') << setw(39) << '-' << '|' << setw(40) << '-' << endl;
	cout << setfill(' ');

	/*********************************************************************
	 * OUT - The name of the stadium and its team(s) are output to the
	 *       table.
	 *********************************************************************/
	for (int i = 0; i < printThis.Size(); i++)
	{
		//Output the first teams name and the column line.
		teamIt = (*stadiumIt).return_teams().Begin();
		cout << setw(39) << (*teamIt).GetName() << '|';
		++teamIt;

		//Output the stadiums names.
		cout << setw(40) << (*stadiumIt).get_stadium_name() << endl;

		//Output any other team names.
		while(teamIt != (*stadiumIt).return_teams().End())
		{
			cout << setw(39) << (*teamIt).GetName() << '|' << endl;
			++teamIt;
		}

		//Next stadium.
		++stadiumIt;
	}

	cout << endl << right;
}



