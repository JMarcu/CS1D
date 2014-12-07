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

//Options the user can select in the admin menu.
enum	Admin_Menu_Options{
	RETURN_TO_MAIN,
	ADD_STADIUM,
	ADD_TEAM,
	CHANGE_TEAM,
	CHANGE_STADIUM,
	REMOVE_TEAM,
	REMOVE_STADIUM,
	ADD_SOUV,
	REMOVE_SOUV
};

/*************************************************************************
 * FUNCTION AdminMenu
 * -----------------------------------------------------------------------
 * This is a sub-menu with admin only functions that modify the program's
 * data.
 * -----------------------------------------------------------------------
 * PRE-CONDITIONS -
 * 	stadiumName     : The list to store all stadiums, sorted by stadium name.
 * 	teamName        : The list to store all stadiums, sorted by team name.
 * 	afcTeams        : The list to store all stadiums in the AFC.
 * 	nfcTeams        : The list to store all stadiums in the NFC.
 * 	openRoofs       : The list to store all stadiums with open roofs.
 * 	retractableRoofs: The list to store all stadiums with retractable roofs.
 * 	openingDate     : The list to store all stadiums, sorted by opening date.
 *
 * POST-CONDITIONS -
 * 	After the user interacts with this menu and choose to exit, they
 * 	will be returned to the main menu. Any changes made to the lists will
 * 	be passed back.
 *************************************************************************/
void AdminMenu(List<NFL_Stadium>& stadiumsAlphabetical,
			   List<NFL_Stadium>& stadiumsTeamName,
			   List<NFL_Stadium>& stadiumsAFC,
			   List<NFL_Stadium>& stadiumsNFC,
			   List<NFL_Stadium>& stadiumsOpenRoof,
			   List<NFL_Stadium>& stadiumsRetractableRoof,
			   List<NFL_Stadium>& stadiumsDateOpened,
			   Map<string, NFL_Stadium>& stadiumMap,
			   Map<string, Souvenir>&    souvenirMap,
			   List<Souvenir>&           souvenirList,
			   Graph<NFL_Stadium>&       stadiumGraph)
{
	/*********************************************************************
	 * CONSTANTS
	 * -------------------------------------------------------------------
	 * USED FOR OUTPUT
	 * -------------------------------------------------------------------
	 * PASS_PROMPT : Prompts the user for an admin password.
	 * MENU        : The menu interface for the admin menu.
	 *
	 * -------------------------------------------------------------------
	 * USED FOR PROCESSING
	 * -------------------------------------------------------------------
	 * ADMIN_PASSWORD : The administrator password to access this menu.
	 *********************************************************************/
	//USED FOR OUTPUT
	const string PASS_PROMPT = "Enter an administrator password (0000 to "
			                   "return to main menu): ";
	const string MENU        = "Admin Options:\n"
							   "-------------------------\n"
							   "1) Add a Stadium\n"
							   "2) Add a Team\n"
							   "3) Change a Team\n"
							   "4) Change a Stadium\n"
			                   "5) Remove a Team\n"
			                   "6) Remove a Stadium\n"
			                   "7) Add a Souvenir\n"
			                   "8) Remove a Souvenir\n"
							   "0) Return to Main Menu\n\n"
							   "Enter Selection: ";

	//USED FOR PROCESSING
	const int ADMIN_PASSWORD = 1234;

	//VARIABLE DECLERATIONS
	int  password;                   //IN   - The user's password.
	bool checkPass;                  //PROC - Keep checking for the password.
	Admin_Menu_Options userSelection;//PROC - User's menu selection.

	/*********************************************************************
	 * INPUT - The user must enter the correct password in order to enter
	 *         this menu.
	 *********************************************************************/
	do
	{
		password = ErrorCheckNum(9999, 0, PASS_PROMPT);

		checkPass = (password != ADMIN_PASSWORD && password != 0000);

		if(checkPass)
		{
			cout << "\nThe password is incorrect. Please try again.\n\n";
		}
	}while(checkPass);
	cout << endl;

	/*********************************************************************
	 * PROC - If they entered the correct password they get access to the
	 *        menu and can run its options until they wish to return to
	 *        the main menu. If they entered 0000 then they are returned
	 *        straight to the main menu.
	 *********************************************************************/
	if(password == 1234)
	{
		do
		{
			/*************************************************************
			 * INPUT - Get the user's selection from the menu.
			 *************************************************************/
			userSelection = Admin_Menu_Options(ErrorCheckNum(8,0, MENU));

			/*************************************************************
			 * PROC - Execute the user's selection.
			 *************************************************************/
			switch(userSelection)
			{
				//Return straight to the main menu.
				case RETURN_TO_MAIN:
					break;

				//Add a new stadium to the program.
				case ADD_STADIUM:
					AddStadium(stadiumsAlphabetical,
							   stadiumsTeamName,
							   stadiumsAFC,
							   stadiumsNFC,
							   stadiumsOpenRoof,
							   stadiumsRetractableRoof,
							   stadiumsDateOpened,
							   stadiumMap,
							   stadiumGraph);
					break;

				//Add a new team to an existing stadium.
				case ADD_TEAM:
					AddTeam(stadiumMap);
					break;

				//Modify an existing team.
				case CHANGE_TEAM:
					ChangeTeam(stadiumMap);
					break;

				//Modify an existing stadium.
				case CHANGE_STADIUM:
					ChangeStadium(stadiumsAlphabetical,
							   	  stadiumsTeamName,
							   	  stadiumsAFC,
							   	  stadiumsNFC,
							   	  stadiumsOpenRoof,
							   	  stadiumsRetractableRoof,
							   	  stadiumsDateOpened,
							   	  stadiumMap);
					break;
				case REMOVE_TEAM:
					RemoveTeam(stadiumsAlphabetical,
							   stadiumsTeamName,
							   stadiumsAFC,
							   stadiumsNFC,
							   stadiumsOpenRoof,
							   stadiumsRetractableRoof,
							   stadiumsDateOpened,
							   stadiumMap);
					break;
				case REMOVE_STADIUM:
					RemoveStadium(stadiumsAlphabetical,
							   	  stadiumsTeamName,
							   	  stadiumsAFC,
							   	  stadiumsNFC,
							   	  stadiumsOpenRoof,
							   	  stadiumsRetractableRoof,
							   	  stadiumsDateOpened,
							   	  stadiumMap,
							   	  stadiumGraph);
					break;

				case ADD_SOUV:
					AddSouv(souvenirMap,
							 souvenirList);

					break;

				case REMOVE_SOUV:
					RemoveSouv(souvenirMap,
							souvenirList);

					break;
			}
		}while(userSelection != RETURN_TO_MAIN);

		cout << endl;
	}
}
