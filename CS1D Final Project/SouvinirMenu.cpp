/*************************************************************************
 * CS1D Final Project
 * -----------------------------------------------------------------------
 * AUTHORS     : James Marcu & Phillip Doyle
 * STUDENT IDs : 374443      & 911579
 * CLASS       : CS1D
 * SECTION     : TTh 3:30 AM
 * DUE DATE    : 12/9/2014
 *************************************************************************/
#include"header.h"

//Options for the souvenir menu.
enum	Souv_Menu_Options{
				RETURN_TO_MAIN,
				LIST,
				FIND,
			};

/*************************************************************************
 * FUNCTION SouvenirMenu
 * -----------------------------------------------------------------------
 * This is a sub-menu for interacting with souvenirs.
 * -----------------------------------------------------------------------
 * PRE-CONDITIONS -
 * 	souvenirMap : A map containing all souvenir objects.
 *
 * POST-CONDITIONS -
 * 	The user will be returned to the main menu. There are no changes done
 * 	to program data from this menu.
 *************************************************************************/
void SouvenirMenu(const Map<string, Souvenir>& souvenirMap,
					List<Souvenir>		&souvenirList)
{
	/*********************************************************************
	 * CONSTANTS
	 * -------------------------------------------------------------------
	 * USED FOR OUTPUT
	 * -------------------------------------------------------------------
	 * MENU : The main menu for the program.
	 *********************************************************************/
	const string MENU = "  Souvenir Menu:\n"
			            "1) List All Souvenirs\n"
			            "2) Find a Souvinier\n"
			            "0) Exit\n"
			            "Enter Selection: ";

	//VARIABLE DECLERATIONS
	string	          name;         //INPUT - Name of a souvenir to search for.
	Souv_Menu_Options userSelection;//INPUT - Stores user's menu selection.

	do
	{
		/*********************************************************************
		 * INPUT - Get the user's choice from the menu.
		 *********************************************************************/
		userSelection = Souv_Menu_Options(ErrorCheckNum(4,0, MENU));
		cout << endl;

		/*********************************************************************
		 * PROC - Continue in the menu until the user chooses to exit.
		 *********************************************************************/
		switch(userSelection)
		{
			//Return to the main menu.
			case RETURN_TO_MAIN:
				break;

			//Search for a specific souvenir and print its information.
			case FIND:
				//Get the name of the souvenir to find.
				cout << "\nEnter the name of the souvenir you wish to search for: ";
				getline(cin, name);

				//If the souvenir was found print its info. Otherwise let the
				//user know it couldn't be found.
				if(souvenirMap.Find(name) != NULL)
				{
					cout << souvenirMap.Find(name)->GetValue().Print() << endl << endl;
				}
				else
				{
					cout << "\nThat souvenir is not available.\n\n";
				}

				break;

			//Print a formatted list of all souvenirs to the console.
			case LIST:

					List<Souvenir>::Iterator souvIt = souvenirList.Begin();

					cout << left;
					cout << setw(20) << "Souvenir" << '|' << " Price" << endl;
					cout << setfill('-') << setw(20) << '-' << '|' << setw(8) << '-' << endl;
					cout << setfill(' ');

					//FOR-LOOP: Cycles through list outputting each souvinier's name
					//			and price to the user
					for(int count = 0; count < souvenirList.Size(); count++)
					{
						cout << setw(20) << souvIt->GetElem().GetName() << "| " ;
						cout << souvIt->GetElem().GetCost();
						cout << endl;
						souvIt++;
					}

					cout << endl << endl;
				break;
		}

	}while(userSelection != RETURN_TO_MAIN);
}
