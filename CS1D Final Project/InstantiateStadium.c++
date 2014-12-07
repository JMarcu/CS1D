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
 * FUNCTION InstantiateStadium
 * ______________________________________________________________________
 * This function will read in one block of input from an input file and
 * use it to create a new instance of the stadium object. This object is
 * then returned by reference.
 * ______________________________________________________________________
 * PRE-CONDITIONS -
 * 	inStream : The open file stream to take input from.
 *
 * POST-CONDITIONS -
 * 	stadium  : This points to the stadium object which is being created.
 * 	           The reference, not the pointer itself, is returned at the
 * 	           end.
 *************************************************************************/
NFL_Stadium* InstantiateStadium(ifstream& inStream)//IN & OUT - The input
                                                   //           stream.
{
	//VARIABLE DECLERATIONS
	NFL_Stadium* stadium; //PROC & OUT - Points to the stadium object which
	                      //             will be created and returned.
	string       name;    //PROC       - Stores the stadium's name.
	int          capacity;//PROC       - Stores the stadium's capacity.
	string       roofTemp;//PROC       - Stores the stadium's roof type as
	                      //             a string, before its type cast.
	string       teamTemp;//PROC       - Stores all the information about
	                      //             any teams at the stadium to be parsed.
	string       teamName;//PROC       - Stores a team's name.
	conference   teamConf;//PROC       - Stores a team's conference.
	Team*        teamPtr; //PROC       - Used to dynamically create Teams.
	string       date;    //PROC       - Stores opening date information as
	                      //             a string.

	string		location; //PROC	  - Stores location code for a stadium

	//VARIABLE INITIALIZATIONS
	stadium = new NFL_Stadium();

	/*********************************************************************
	 * INPUT - Get the name of the stadium and add it to the new object.
	 *********************************************************************/
	getline(inStream, name);
	stadium->set_stadium_name(name);

	/*********************************************************************
	 * INPUT - Get the stadium's capacity and add it to the new object.
	 *********************************************************************/
	inStream >> capacity;
	inStream.ignore(1000, '\n');
	stadium->set_capacity(capacity);

	/*********************************************************************
	 * INPUT - Get the stadium's roof type and add it to the new object.
	 *         Its read in as a string. The proper enum is decided by an
	 *         if statement and added into the object.
	 *********************************************************************/
	getline(inStream, roofTemp);
	if(roofTemp == "Open")
	{
		stadium->set_roof(OPEN);
	}
	else if(roofTemp == "Domed")
	{
		stadium->set_roof(DOMED);
	}
	else
	{
		stadium->set_roof(RETRACTABLE);
	}

	/*********************************************************************
	 * INPUT - Get the names and conferences of any teams and add them to
	 *         the stadium.
	 *
	 * PROC  - A string with the information of all teams is stored in
	 *         teamTemp. This string is parsed until the teamTemp string
	 *         is empty.
	 *********************************************************************/
	getline(inStream, teamTemp);
	while (!teamTemp.empty())
	{
		/*****************************************************************
		 * PROC - The first teams name will be the substring up until the
		 *        first dash. This is found and stored in teamName. The
		 *        substring, and the dash, are then erased from the string.
		 *****************************************************************/
		teamName = teamTemp.substr(0, teamTemp.find('-'));
		teamTemp.erase(0, teamTemp.find('-')+1);

		/*****************************************************************
		 * PROC - The first teams conference will be the next substring up
		 *        until either a comma (if there is another team) or an
		 *        endline character (if there is not another team). This
		 *        is found and stored in teamConf. The substring is then
		 *        erased from the string.
		 *****************************************************************/
		if(teamTemp.substr(0, teamTemp.find_first_of(",\n")) == "AFC")
		{
			teamConf = AFC;
		}
		else
		{
			teamConf = NFC;
		}
		teamTemp.erase(0, teamTemp.find_first_of(",\n"));

		/*****************************************************************
		 * PROC - If there is another team in the string, it will be
		 *        seperated by a comma. This checks if there is another
		 *        team and then erases the comma if necessary.
		 *****************************************************************/
		if (!teamTemp.empty())
		{
			teamTemp.erase(0, 1);
		}

		/*****************************************************************
		 * PROC - A new Team object is created with the teamName and
		 *        teamConf and immediately stored in the stadium object.
		 *****************************************************************/
		teamPtr = new Team(teamName, teamConf);
		stadium->add_team(*teamPtr);
	}

	/*********************************************************************
	 * INPUT - Get the stadium's opening date and stores it in the stadium
	 *         object being created.
	 *********************************************************************/
	getline(inStream, date);
		stadium->set_opening_date(*new Date( Months(atoi((date.substr(0, 2)).c_str())),
										 atoi((date.substr(3, 2)).c_str()),
										 atoi((date.substr(6, 4)).c_str())));

	/*********************************************************************
	 * INPUT - Get the stadium's location and stores it in the stadium
	 *         object being created.
	 *********************************************************************/
	getline(inStream, location);
	stadium->set_location(location);


	/*********************************************************************
	 * PROC  - Clears the trailing new line after the entry.
	 *********************************************************************/
	getline(inStream, name);

	/*********************************************************************
	 * OUT  - The stadium object ITSELF is passed back to the calling
	 *        function, NOT the pointer. This allows the object to be
	 *        passed back by reference even though it was locally declared.
	 *********************************************************************/
	return stadium;
}


