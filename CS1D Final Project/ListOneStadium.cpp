/*************************************************************************
 * CS1D Final Project
 * -----------------------------------------------------------------------
 * AUTHORS     : James Marcu & Phillip Doyle
 * STUDENT IDs : 374443      & 911579
 * CLASS       : CS1D
 * SECTION     : TTh 3:30 PM
 * DUE DATE    : 12/9/2014
 *************************************************************************/

#include"header.h"

/*************************************************************************
 * FUNCTION ListOneStadium
 * -----------------------------------------------------------------------
 * Searches the map for a stadium by name and outputs its formatted data
 * to the console.
 * -----------------------------------------------------------------------
 * PRE-CONDITIONS -
 * 	stadiumMap      : The map which has all stadiums stored.
 *
 * POST-CONDITIONS -
 * 	The stadium the user entered will have its data output to the console.
 *************************************************************************/
void ListOneStadium(const Map<string, NFL_Stadium>& stadiumMap)
{
	/*********************************************************************
	 * CONSTANTS
	 * -------------------------------------------------------------------
	 * USED FOR OUTPUT
	 * -------------------------------------------------------------------
	 * CONT_PROMPT : Prompts if the user wishes to continue.
	 *********************************************************************/
	const string CONT_PROMPT = "Would you like to search for another "
							   "stadium (y/n)? ";

	//VARIABLE DECLERATIONS
	string	stadiumName;//INPUT - Name of the stadium to output.
	bool    cont;       //PROC  - Whether to keep printing stadiums.

	/*********************************************************************
	 * PROC - Search for and print the information of stadiums provided by
	 *        the user until they indiacte they wish to go back.
	 *********************************************************************/
	do
	{
		/*****************************************************************
		 * INPUT - Get the name of the stadium to output.
		 *****************************************************************/
		cout << "Enter Name of stadium you wish to search for: ";
		getline(cin, stadiumName);

		/*****************************************************************
		 * PROC - If you can find that stadium, print its contents to the
		 *        console. Otherwise let the user know it couldn't be
		 *        found.
		 *****************************************************************/
		if(stadiumMap.Find(stadiumName) != NULL)
		{
			cout << stadiumMap.Find(stadiumName)->GetValue().print() << endl;;
		}
		else
		{
			cout << "\nThat stadium could not be found.\n\n";
		}

		/*****************************************************************
		 * INPUT - Find out if the user wants to search for another
		 *         stadium.
		 *****************************************************************/
		cont = (GetInput(CONT_PROMPT, 'y', 'n', cout, cin) == 'Y');
		cout << endl;

	}while(cont);

}
