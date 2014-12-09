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
 * FUNCTION Constructor
 * -----------------------------------------------------------------------
 * This will create a stadium object using default values.
 * -----------------------------------------------------------------------
 * PRECONDITIONS -
 * 	<none>
 *
 * POSTCONDITIONS -
 * 	Instantiates a NFL_Stadium using default values.
 *************************************************************************/
NFL_Stadium::NFL_Stadium()
{
	stadium_name.clear();
	roof     = OPEN;
	capacity = 0;
}

/*************************************************************************
 * FUNCTION Constructor
 * -----------------------------------------------------------------------
 * This will create a stadium object using the provided values.
 * -----------------------------------------------------------------------
 * PRECONDITIONS -
 * 	r_type  : The stadium's roof type.
 * 	name    : The stadium's name.
 * 	cap     : The stadium's capacity.
 * 	opening : The stadium's opening date.
 *
 * POSTCONDITIONS -
 * 	Instantiates a NFL_Stadium using default values.
 *************************************************************************/
NFL_Stadium::NFL_Stadium(roof_type    r_type,
		                 string       name,
		                 unsigned int cap,
		                 Date         opening)
{
	stadium_name = name;
	roof         = r_type;
	capacity     = cap;
	opening_date = opening;
}

/*************************************************************************
 * FUNCTION Destructor
 * -----------------------------------------------------------------------
 * Safely deletes an NFL_Stadium object.
 * -----------------------------------------------------------------------
 * PRECONDITIONS -
 * 	<none>
 *
 * POSTCONDITIONS -
 * 	Destroys an NFL_Stadium object.
 *************************************************************************/
NFL_Stadium::~NFL_Stadium()
{

}

/*************************************************************************
 * FUNCTION get_stadium_name
 * -----------------------------------------------------------------------
 * Returns the stadium's name.
 * -----------------------------------------------------------------------
 * PRECONDITIONS -
 * 	<none>
 *
 * POSTCONDITIONS -
 * 	Returns the stadium's name.
 *************************************************************************/
const string& NFL_Stadium::get_stadium_name() const
{
	return stadium_name;
}

/*************************************************************************
 * FUNCTION get_roof
 * -----------------------------------------------------------------------
 * Returns the stadium's roof type.
 * -----------------------------------------------------------------------
 * PRECONDITIONS -
 * 	<none>
 *
 * POSTCONDITIONS -
 * 	Returns the stadium's roof type.
 *************************************************************************/
roof_type		NFL_Stadium::get_roof()	const
{
	return	roof;
}

/*************************************************************************
 * FUNCTION get_capacity
 * -----------------------------------------------------------------------
 * Returns the stadium's capacity.
 * -----------------------------------------------------------------------
 * PRECONDITIONS -
 * 	<none>
 *
 * POSTCONDITIONS -
 * 	Returns the stadium's capacity.
 *************************************************************************/
long NFL_Stadium::get_capacity() const
{
	return capacity;
}

/*************************************************************************
 * FUNCTION get_opening_date
 * -----------------------------------------------------------------------
 * Returns the stadium's opening date.
 * -----------------------------------------------------------------------
 * PRECONDITIONS -
 * 	<none>
 *
 * POSTCONDITIONS -
 * 	Returns the stadium's opening date.
 *************************************************************************/
Date NFL_Stadium::get_opening_date() const
{
	return opening_date;
}

/*************************************************************************
 * FUNCTION get_Location
 * -----------------------------------------------------------------------
 * Returns the stadium's location code
 * -----------------------------------------------------------------------
 * PRECONDITIONS -
 * 	<none>
 *
 * POSTCONDITIONS -
 * 	Returns the stadium's location code
 *************************************************************************/
string  NFL_Stadium::get_location()	const
{
	return location;
}

/*************************************************************************
 * FUNCTION return_teams
 * -----------------------------------------------------------------------
 * Returns a list of the stadium's teams.
 * -----------------------------------------------------------------------
 * PRECONDITIONS -
 * 	<none>
 *
 * POSTCONDITIONS -
 * 	Returns a list of the stadium's teams.
 *************************************************************************/
const List<Team>& NFL_Stadium::return_teams() const
{
	return teamList;
}

/*************************************************************************
 * FUNCTION is_in_AFC
 * -----------------------------------------------------------------------
 * Returns true if at least one team that plays at the stadium plays in
 * the AFC.
 * -----------------------------------------------------------------------
 * PRECONDITIONS -
 * 	<none>
 *
 * POSTCONDITIONS -
 * 	Returns true if at least one team that plays at the stadium plays in
 *  the AFC.
 *************************************************************************/
bool NFL_Stadium::is_in_AFC() const
{
	//VARIABLE DECLERATIONS
	List<Team>::Iterator teamIt;//PROC - Iterates the team list.
	bool inAFC;                 //OUT  - Returns from the function.

	//VARIBLE INITIALIZATIONS
	teamIt = teamList.Begin();
	inAFC = false;

	//Go until we have an answer.
	while(!inAFC && teamIt != teamList.End())
	{
		//If the team is in the AFC return true, otherwise check next
		//team.
		if ((*teamIt).GetConference() == AFC)
		{
			inAFC = true;
		}
		else
		{
			++teamIt;
		}
	}

	return inAFC;
}

/*************************************************************************
 * FUNCTION is_in_NFC
 * -----------------------------------------------------------------------
 * Returns true if at least one team that plays at the stadium plays in
 * the NFC.
 * -----------------------------------------------------------------------
 * PRECONDITIONS -
 * 	<none>
 *
 * POSTCONDITIONS -
 * 	Returns true if at least one team that plays at the stadium plays in
 *  the NFC.
 *************************************************************************/
bool NFL_Stadium::is_in_NFC() const
{
	//VARIABLE DECLERATIONS
	List<Team>::Iterator teamIt;//PROC - Iterates the list of teams.
	bool inNFC;                 //OUT  - Returns true if a team is in
	                            //       the NFC.

	//VARIABLE INITIALIZATIONS
	teamIt = teamList.Begin();
	inNFC = false;

	//Check every team, or until at least one is in the NFC.
	while(!inNFC && teamIt != teamList.End())
	{
		//If the team is in the NFC return true, otherwise check the next
		//team.
		if ((*teamIt).GetConference() == NFC)
		{
			inNFC = true;
		}
		else
		{
			++teamIt;
		}
	}

	return inNFC;
}

/*************************************************************************
 * FUNCTION save
 * -----------------------------------------------------------------------
 * Returns a string which has been formatted for storage in a text file.
 * This will save the stadium's information between program executions.
 * -----------------------------------------------------------------------
 * PRECONDITIONS -
 * 	<none>
 *
 * POSTCONDITIONS -
 * 	Returns a string formatted for saving the stadium's data.
 *************************************************************************/
string NFL_Stadium::save() const
{
	//VARIABLE DECLERATIONS
	ostringstream        output;//PROC - Stores the stadium's data.
	List<Team>::Iterator teamIt;//PROC - Iterates the team list.

	//VARIABLE INITIALIZATIONS
	teamIt = teamList.Begin();

	//Each of the stadium's fields are put into the string stream in
	//proper formatting.
	output << stadium_name << endl;
	output << capacity << endl;
	switch(roof)
	{
		case OPEN:output << "Open" << endl;
			break;
		case DOMED:output << "Domed" << endl;
			break;
		case RETRACTABLE:output << "Retractable" << endl;
			break;
	}

	while(teamIt != teamList.End())
	{
		output << (*teamIt).GetName();
		output << '-';
		if((*teamIt).GetConference() == AFC)
		{
			output << "AFC";
		}
		else
		{
			output << "NFC";
		}

		++teamIt;
		if(teamIt != teamList.End())
		{
			output << ',';
		}
	}
	output << endl;
	output << opening_date.printDate() << endl;
	output << location << endl;

	//The string stream is converted to a string and returned.
	return output.str();
}

/*************************************************************************
 * FUNCTION print
 * -----------------------------------------------------------------------
 * Returns a string which has been formatted for output to the console,
 * and contains all of the stadium's information
 * -----------------------------------------------------------------------
 * PRECONDITIONS -
 * 	<none>
 *
 * POSTCONDITIONS -
 * 	Returns a string formatted for outputting the stadium's data to the
 * 	console.
 *************************************************************************/
string NFL_Stadium::print() const
{
	const int COL_WIDTH = 13;

	//VARIABLE DECLERATIONS
	ostringstream output;//PROC - Stores the stadium's data.
	List<Team>::Iterator teamIt;

	//Outputs the stadium's data to the string stream with formatting.
	output << left;
	output << endl;

	output << setw(COL_WIDTH)
		   << "Stadium Name " << ": "
		   << stadium_name    << endl;

	output << setw(COL_WIDTH)
	       << "Max Capacity"  << ": "
	       << capacity        << endl;

	output << setw(COL_WIDTH)
	       << "Roof Type"     << ": ";
	switch(roof)
	{
		case OPEN:output << "Open\n";
			break;
		case DOMED:output << "Domed\n";
			break;
		case RETRACTABLE:output << "Retractable\n";
			break;
	}

	output << setw(COL_WIDTH)
		   << "Opened" << ": "
		   << opening_date.printDate() << endl;

	output << setw(COL_WIDTH)
		   << "Team(s)" << ": ";
	teamIt = teamList.Begin();
	while(teamIt != teamList.End())
	{
		output << (*teamIt).GetName()       << " - ";
		if((*teamIt).GetConference() == AFC)
		{
			output << "AFC\n";
		}
		else
		{
			output << "NFC\n";
		}

		++teamIt;
		if(teamIt != teamList.End())
		{
			output << setw(COL_WIDTH + 2) << " ";
		}
	}

	output << right;

	//The stream is converted to a string and returned.
	return output.str();
}

/*************************************************************************
 * FUNCTION !=
 * -----------------------------------------------------------------------
 * Overloaded to compare a stadiums name.
 * -----------------------------------------------------------------------
 * PRECONDITIONS -
 * 	compareTo : The other stadium.
 *
 * POSTCONDITIONS -
 * 	True if the two stadiums don't have the same name.
 *************************************************************************/
bool NFL_Stadium::operator!=(const NFL_Stadium& compareTo) const
{
	return stadium_name != compareTo.get_stadium_name();
}

/*************************************************************************
 * FUNCTION ==
 * -----------------------------------------------------------------------
 * Overloaded to compare a stadiums name.
 * -----------------------------------------------------------------------
 * PRECONDITIONS -
 * 	compareTo : The other stadium.
 *
 * POSTCONDITIONS -
 * 	True if the two stadiums have the same name.
 *************************************************************************/
bool NFL_Stadium::operator==(const NFL_Stadium& compareTo) const
{
	return stadium_name == compareTo.get_stadium_name();
}

/*************************************************************************
 * FUNCTION add_team
 * -----------------------------------------------------------------------
 * Adds a team to the list of teams that play at the stadium.
 * -----------------------------------------------------------------------
 * PRECONDITIONS -
 * 	newTeam : The team to add to the stadium.
 *
 * POSTCONDITIONS -
 * 	The new team will be added to the stadium's list of teams.
 *************************************************************************/
void NFL_Stadium::add_team(const Team& newTeam)
{
	//Insert it into the list.
	teamList.InsertBack(newTeam);
}

/*************************************************************************
 * FUNCTION remove_team
 * -----------------------------------------------------------------------
 * Removes a team from the stadium.
 * -----------------------------------------------------------------------
 * PRECONDITIONS -
 * 	toRemove : An iterator pointing at the team to remove.
 *
 * POSTCONDITIONS -
 * 	Removes a team from the stadium.
 *************************************************************************/
void NFL_Stadium::remove_team(List<Team>::Iterator toRemove)
{
	teamList.Erase(toRemove);
}

/*************************************************************************
 * FUNCTION set_roof
 * -----------------------------------------------------------------------
 * Sets the stadium's roof type.
 * -----------------------------------------------------------------------
 * PRECONDITIONS -
 * 	r_type : The type of roof to set for the stadium.
 *
 * POSTCONDITIONS -
 * 	The stadium's roof type will be set to r_type.
 *************************************************************************/
void NFL_Stadium::set_roof(roof_type r_type)
{
	roof = r_type;
}

/*************************************************************************
 * FUNCTION set_capacity
 * -----------------------------------------------------------------------
 * Sets the stadium's capacity.
 * -----------------------------------------------------------------------
 * PRECONDITIONS -
 * 	cap : The capacity to set for the stadium.
 *
 * POSTCONDITIONS -
 * 	The stadium's capacity will be set to cap.
 *************************************************************************/
void NFL_Stadium::set_capacity(long cap)
{
	capacity = cap;
}

/*************************************************************************
 * FUNCTION set_opening_date
 * -----------------------------------------------------------------------
 * Sets the stadium's opening date.
 * -----------------------------------------------------------------------
 * PRECONDITIONS -
 * 	opening : The opening date to set for the stadium.
 *
 * POSTCONDITIONS -
 * 	The stadium's opening date will be set to opening.
 *************************************************************************/
void NFL_Stadium::set_opening_date(Date opening)
{
	opening_date = opening;
}

/*************************************************************************
 * FUNCTION set_stadium_name
 * -----------------------------------------------------------------------
 * Sets the stadium's name.
 * -----------------------------------------------------------------------
 * PRECONDITIONS -
 * 	s_name : The name to set for the stadium.
 *
 * POSTCONDITIONS -
 * 	The stadium's name will be set to s_name.
 *************************************************************************/
void NFL_Stadium::set_stadium_name(string s_name)
{
	stadium_name = s_name;
}


/*************************************************************************
 * FUNCTION set_location
 * -----------------------------------------------------------------------
 * Set's the stadium's location
 * -----------------------------------------------------------------------
 * PRECONDITIONS -
 * 	<none>
 *
 * POSTCONDITIONS -
 * 	changes the stadium's location
 *************************************************************************/
void	NFL_Stadium:: set_location(string newlocation)
{
	location =  newlocation;
}
