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

void InsertToLists(List<NFL_Stadium>& stadiumsAlphabetical,
   	    		   List<NFL_Stadium>& stadiumsTeamName,
   	    		   List<NFL_Stadium>& stadiumsAFC,
   	    		   List<NFL_Stadium>& stadiumsNFC,
   	    		   List<NFL_Stadium>& stadiumsOpenRoof,
   	    		   List<NFL_Stadium>& stadiumsRetractableRoof,
   	    		   List<NFL_Stadium>& stadiumsDateOpened,
   	    		   NFL_Stadium*       stadiumPtr)
{
	bool insertFurther;
	List<NFL_Stadium>::Iterator stadiumIt;

	/*********************************************************************
	 * PROC - Add the stadium to the list of all stadiums, sorted by
	 *        stadium name.
	 *********************************************************************/
	stadiumIt     = stadiumsAlphabetical.Begin();
	insertFurther = true;
	while(insertFurther)
	{
		if (stadiumIt == stadiumsAlphabetical.End())
		{
			insertFurther = false;
			stadiumsAlphabetical.InsertBack(*stadiumPtr);
		}
		else if(AlphabeticalOrder(stadiumPtr->get_stadium_name(),
				                 (*stadiumIt).get_stadium_name()))
		{
			insertFurther = false;
			stadiumsAlphabetical.Insert(*stadiumPtr, stadiumIt);
		}
		else
		{
			++stadiumIt;
		}
	}

	/*********************************************************************
	 * PROC - Add the stadium to the list of all stadiums, sorted by
	 *        team name.
	 *********************************************************************/
	stadiumIt     = stadiumsTeamName.Begin();
	insertFurther = true;
	while(insertFurther)
	{
		if (stadiumIt == stadiumsTeamName.End())
		{
			insertFurther = false;
			stadiumsTeamName.InsertBack(*stadiumPtr);
		}
		else if(AlphabeticalOrder(stadiumPtr->get_stadium_name(),
				                 (*stadiumIt).get_stadium_name()))
		{
			insertFurther = false;
			stadiumsTeamName.Insert(*stadiumPtr, stadiumIt);
		}
		else
		{
			++stadiumIt;
		}
	}

	/*********************************************************************
	 * PROC - If at least one of the teams who plays at the stadium is in
	 *        the AFC, add the stadium to the list of AFC stadiums.
	 *********************************************************************/
	if(stadiumPtr->is_in_AFC())
	{
		stadiumIt     = stadiumsAFC.Begin();
		insertFurther = true;
		while(insertFurther)
		{
			if (stadiumIt == stadiumsAFC.End())
			{
				insertFurther = false;
				stadiumsAFC.InsertBack(*stadiumPtr);
			}
			else if(AlphabeticalOrder(stadiumPtr->get_stadium_name(),
					                 (*stadiumIt).get_stadium_name()))
			{
				insertFurther = false;
				stadiumsAFC.Insert(*stadiumPtr, stadiumIt);
			}
			else
			{
				++stadiumIt;
			}
		}
	}

	/*********************************************************************
	 * PROC - If at least one of the teams who plays at the stadium is in
	 *        the NFC, add the stadium to the list of NFC stadiums.
	 *********************************************************************/
	if(stadiumPtr->is_in_NFC())
	{
		stadiumIt     = stadiumsNFC.Begin();
		insertFurther = true;
		while(insertFurther)
		{
			if (stadiumIt == stadiumsNFC.End())
			{
				insertFurther = false;
				stadiumsNFC.InsertBack(*stadiumPtr);
			}
			else if(AlphabeticalOrder(stadiumPtr->get_stadium_name(),
					                 (*stadiumIt).get_stadium_name()))
			{
				insertFurther = false;
				stadiumsNFC.Insert(*stadiumPtr, stadiumIt);
			}
			else
			{
				++stadiumIt;
			}
		}
	}

	/*********************************************************************
	 * PROC - If the stadium has an open roof then add it to the list of
	 *        stadiums with open roofs. If the roof is retractable though,
	 *        add it to that list instead.
	 *********************************************************************/
	if(stadiumPtr->get_roof() == OPEN)
	{
		stadiumIt     = stadiumsOpenRoof.Begin();
		insertFurther = true;
		while(insertFurther)
		{
			if (stadiumIt == stadiumsOpenRoof.End())
			{
				insertFurther = false;
				stadiumsOpenRoof.InsertBack(*stadiumPtr);
			}
			else if(AlphabeticalOrder(stadiumPtr->get_stadium_name(),
					                 (*stadiumIt).get_stadium_name()))
			{
				insertFurther = false;
				stadiumsOpenRoof.Insert(*stadiumPtr, stadiumIt);
			}
			else
			{
				++stadiumIt;
			}
		}
	}
	else if(stadiumPtr->get_roof() == RETRACTABLE)
	{
		stadiumIt     = stadiumsRetractableRoof.Begin();
		insertFurther = true;
		while(insertFurther)
		{
			if (stadiumIt == stadiumsRetractableRoof.End())
			{
				insertFurther = false;
				stadiumsRetractableRoof.InsertBack(*stadiumPtr);
			}
			else if(AlphabeticalOrder(stadiumPtr->get_stadium_name(),
					                 (*stadiumIt).get_stadium_name()))
			{
				insertFurther = false;
				stadiumsRetractableRoof.Insert(*stadiumPtr, stadiumIt);
			}
			else
			{
				++stadiumIt;
			}
		}
	}

	/*********************************************************************
	 * PROC - Add the stadium to the list of all stadiums, ordered by
	 *        the date they opened.
	 *********************************************************************/
	stadiumIt     = stadiumsDateOpened.Begin();
	insertFurther = true;
	while(insertFurther)
	{
		if (stadiumIt == stadiumsDateOpened.End())
		{
			insertFurther = false;
			stadiumsDateOpened.InsertBack(*stadiumPtr);
		}
		else if(stadiumPtr->get_opening_date() <= (*stadiumIt).get_opening_date())
		{
			insertFurther = false;
			stadiumsDateOpened.Insert(*stadiumPtr, stadiumIt);
		}
		else
		{
			++stadiumIt;
		}
	}
}

void RemoveFromLists(List<NFL_Stadium>& stadiumsAlphabetical,
   	    			 List<NFL_Stadium>& stadiumsTeamName,
   	    			 List<NFL_Stadium>& stadiumsAFC,
   	    			 List<NFL_Stadium>& stadiumsNFC,
   	    			 List<NFL_Stadium>& stadiumsOpenRoof,
   	    			 List<NFL_Stadium>& stadiumsRetractableRoof,
   	    			 List<NFL_Stadium>& stadiumsDateOpened,
   	    			 NFL_Stadium*       stadiumPtr)
{
	List<NFL_Stadium>::Iterator stadiumIt;

	stadiumIt = stadiumsAlphabetical.Search(*stadiumPtr);
	stadiumsAlphabetical.Erase(stadiumIt);

	stadiumIt = stadiumsTeamName.Search(*stadiumPtr);
	stadiumsTeamName.Erase(stadiumIt);

	stadiumIt = stadiumsAFC.Search(*stadiumPtr);
	if(stadiumIt != stadiumsAFC.End())
	{
		stadiumsAFC.Erase(stadiumIt);
	}

	stadiumIt = stadiumsNFC.Search(*stadiumPtr);
	if(stadiumIt != stadiumsNFC.End())
	{
		stadiumsNFC.Erase(stadiumIt);
	}

	stadiumIt = stadiumsOpenRoof.Search(*stadiumPtr);
	if(stadiumIt != stadiumsOpenRoof.End())
	{
		stadiumsOpenRoof.Erase(stadiumIt);
	}

	stadiumIt = stadiumsRetractableRoof.Search(*stadiumPtr);
	if(stadiumIt != stadiumsOpenRoof.End())
	{
		stadiumsRetractableRoof.Erase(stadiumIt);
	}

	stadiumsDateOpened.Erase(stadiumsDateOpened.Search(*stadiumPtr));
}

/*************************************************************************
 * FUNCTION AddStadium
 * -----------------------------------------------------------------------
 * This function allows an admin to add a new stadium to the program.
 * -----------------------------------------------------------------------
 * PRE-CONDITIONS -
 * 	stadiumName     : The list to store all stadiums, sorted by stadium name.
 * 	teamName        : The list to store all stadiums, sorted by team name.
 * 	afcTeams        : The list to store all stadiums in the AFC.
 * 	nfcTeams        : The list to store all stadiums in the NFC.
 * 	openRoofs       : The list to store all stadiums with open roofs.
 * 	retractableRoofs: The list to store all stadiums with retractable roofs.
 * 	openingDate     : The list to store all stadiums, sorted by opening date.
 * 	stadiumMap      : The map which has all stadiums stored.
 *
 * POST-CONDITIONS -
 * 	The new stadium will have been added to the map and any applicable
 * 	lists.
 *************************************************************************/
void AddStadium(List<NFL_Stadium>& stadiumsAlphabetical,
		   	    List<NFL_Stadium>& stadiumsTeamName,
		   	    List<NFL_Stadium>& stadiumsAFC,
		   	    List<NFL_Stadium>& stadiumsNFC,
		   		List<NFL_Stadium>& stadiumsOpenRoof,
		   		List<NFL_Stadium>& stadiumsRetractableRoof,
		   		List<NFL_Stadium>& stadiumsDateOpened,
		   		Map<string, NFL_Stadium>& stadiumMap,
		   		Graph<NFL_Stadium>&       stadiumGraph)
{
	/*********************************************************************
	 * CONSTANTS
	 * -------------------------------------------------------------------
	 * USED FOR OUTPUT
	 * -------------------------------------------------------------------
	 * NAME_PROMPT        : Prompts the admin for the new stadium's name.
	 * ROOF_PROMPT        : Prompts the admin for the new stadium's roof type.
	 * CAPACITY_PROMPT    : Prompts the admin for the new stadium's capacity.
	 * FIRST_TEAM_PROMPT  : Prompts the admin for the new stadium's team.
	 * SECOND_TEAM_PROMPT : Prompts the admin for any other teams.
	 * TEAM_NAME_PROMPT   : Prompts the admin for a team's name.
	 * TEAM_CONF_PROMPT   : Prompts the admin for a team's conference.
	 * YEAR_PROMPT        : Prompts the admin for a stadium's opening year.
	 * MONTH_PROMPT       : Prompts the admin for a stadium's opening month.
	 * DAY_PROMPT         : Prompts the user for a stadium's opening day.
	 * LOCATION_PROMPT    : Prompts the user for the stadium's location.
	 * GRAPH_PROMPT       : Prompts the user for a trip planner route.
	 * DEST_PROMPT        : Prompts the user for the other stadium in a route.
	 * DEST_ERROR         : Tells the user their destination was invalid.
	 * WEIGHT_PROMPT      : Prompts the user for the distance of the route.
	 * ROUTE_PROMPT       : Prompts for if there are more routes.
	 * SUCCESS            : Ouptputs at the end of the program.
	 *********************************************************************/
	const string NAME_PROMPT        = "What is the name of the stadium? ";
	const string ROOF_PROMPT        = "Does the stadium have a: \n"
			 	 	 	 	          "\t1 - Open Roof\n"
			 	 	 	 	          "\t2 - Domed Roof\n"
			 	 	 	 	          "\t3 - Retractable Roof\n"
			                          "Selection: ";
	const string CAPACITY_PROMPT    = "What is the stadium\'s capacity? ";
	const string FIRST_TEAM_PROMPT  = "Please enter the information for this "
			                          "stadium\'s team: \n";
	const string SECOND_TEAM_PROMPT = "Does this stadium have another team (y/n)? ";
	const string TEAM_NAME_PROMPT   = "What is the team\'s name? ";
	const string TEAM_CONF_PROMPT   = "What is the team\'s conference?\n"
			                          "\t1 - AFC\n"
			                          "\t2 - NFC\n"
			                          "Selection: ";
	const string YEAR_PROMPT        = "What year did the stadium open in? ";
	const string MONTH_PROMPT       = "What month did the stadium open in? ";
	const string DAY_PROMPT         = "What day did the stadium open on? ";
	const string LOCATION_PROMPT    = "What city is this stadium in? ";
	const string GRAPH_PROMPT       = "\nPlease enter at least one route for "
			                          "the trip planner.\n";
	const string DEST_PROMPT        = "What is the name of the stadium "
			                          "this route goes to? ";
	const string DEST_ERROR         = "\nThat stadium could not be found.\n"
			                          "Please enter a new stadium name.\n\n";
	const string WEIGHT_PROMPT      = "How far in miles is this route? ";
	const string ROUTE_PROMPT       = "\nAre there more routes to add? (y/n)\n"
			                          "Enter Selection: ";
	const string SUCCESS            = "\nThe stadium has been added "
			                          "to the program successfully.\n\n";

	//VARIABLE DECLERATIONS
	NFL_Stadium* stadiumPtr;     //PROC - Creates a new stadium object.
	string       stadiumName;    //IN   - The stadium's name.
	roof_type    stadiumRoof;    //IN   - The stadium's roof type.
	long         stadiumCapacity;//IN   - The stadium's capacity.
	int          openingYear;    //IN   - The stadium's opening year.
	int          openingMonth;   //IN   - The stadium's opening month.
	int          openingDay;     //IN   - The stadium's opening day.
	bool         enterTeams;     //IN   - Whether to keep entering teams.
	Date*        stadiumDate;    //PROC - The stadium's opening date.
	string       stadiumLocation;//IN   - The stadium's location.
	string       teamName;       //IN   - A team's name.
	conference   teamConference; //IN   - A team's conference.
	Team*        teamPtr;        //PROC - Used to create new team objects.
	List<NFL_Stadium>::Iterator stadiumIt;//PROC - Iterates stadium lists.
	List<Team>::Iterator        teamIt;   //PROC - Iteratres team lists.
	bool         validDest;      //PROC - Used to find a valid route destination.
	bool         enterRoutes;    //PROC - Used to continue entering routes.
	string       destination;    //IN   - Name of the stadium a route goes to.
	float        weight;         //IN   - Distance(mi) of a route.

	//VARIABLE INITIALIZATIONS
	enterTeams  = true;
	enterRoutes = true;

	cout << NAME_PROMPT;
	getline(cin, stadiumName);

	stadiumRoof = roof_type(ErrorCheckNum(3, 1, ROOF_PROMPT) - 1);

	stadiumCapacity = ErrorCheckNum(500000, 0, CAPACITY_PROMPT);

	openingYear  = ErrorCheckNum(3000, 1900, YEAR_PROMPT);
	openingMonth = ErrorCheckNum(12,   1,    MONTH_PROMPT);
	openingDay   = ErrorCheckNum(31,   1,    DAY_PROMPT);
	stadiumDate  = new Date(Months(openingMonth), openingDay, openingYear);

	stadiumPtr = new NFL_Stadium(stadiumRoof, stadiumName, stadiumCapacity, *stadiumDate);

	cout << LOCATION_PROMPT;
	getline(cin, stadiumLocation);
	stadiumPtr->set_location(stadiumLocation);

	cout << FIRST_TEAM_PROMPT;
	while(enterTeams)
	{
		cout << TEAM_NAME_PROMPT;
		getline(cin, teamName);

		teamConference = conference(ErrorCheckNum(2, 1, TEAM_CONF_PROMPT) - 1);

		teamPtr = new Team(teamName, teamConference);

		stadiumPtr->add_team(*teamPtr);

		if (GetInput(SECOND_TEAM_PROMPT, 'y', 'n', cout, cin) == 'N')
		{
			enterTeams = false;
		}
	}

	cout << GRAPH_PROMPT;
	stadiumGraph.AddVertex(*stadiumPtr);
	do
	{
		validDest = false;
		while(!validDest)
		{
			cout << DEST_PROMPT;
			getline(cin, destination);

			if(stadiumMap.Find(destination) != NULL)
			{
				validDest = true;
			}
			else
			{
				cout << DEST_ERROR;
			}
		}

		weight = ErrorCheckNum(30000.0, 0.0, WEIGHT_PROMPT);

		stadiumGraph.AddEdge(stadiumGraph.GetVertex(*stadiumPtr),
				             stadiumGraph.GetVertex(stadiumMap.Find(destination)->GetValue()),
				             weight);

		if (GetInput(ROUTE_PROMPT, 'y', 'n', cout, cin) == 'N')
		{
			enterRoutes = false;
		}

	}while(enterRoutes);

	InsertToLists(stadiumsAlphabetical,
    		   	  stadiumsTeamName,
    		   	  stadiumsAFC,
    		   	  stadiumsNFC,
    		   	  stadiumsOpenRoof,
    		   	  stadiumsRetractableRoof,
    		   	  stadiumsDateOpened,
    		   	  stadiumPtr);

	/*********************************************************************
	 * PROC - Add the stadium to the map of all stadiums.
	 *********************************************************************/
	stadiumMap.Put(stadiumPtr->get_stadium_name(), *stadiumPtr);
cout << "test";
cin.ignore(1000, '\n');
	SaveTrips(stadiumsAFC, stadiumsNFC, stadiumMap, stadiumGraph);

	cout << SUCCESS;
}

void AddTeam(Map<string, NFL_Stadium>& stadiumMap)
{
	/*********************************************************************
	 * CONSTANTS
	 * -------------------------------------------------------------------
	 * USED FOR OUTPUT
	 * -------------------------------------------------------------------
	 * NAME_PROMPT        : Prompts the admin for the new stadium's name.
	 * ROOF_PROMPT        : Prompts the admin for the new stadium's roof type.
	 * CAPACITY_PROMPT    : Prompts the admin for the new stadium's capacity.
	 * FIRST_TEAM_PROMPT  : Prompts the admin for the new stadium's team.
	 * SECOND_TEAM_PROMPT : Prompts the admin for any other teams.
	 * TEAM_NAME_PROMPT   : Prompts the admin for a team's name.
	 * TEAM_CONF_PROMPT   : Prompts the admin for a team's conference.
	 * YEAR_PROMPT        : Prompts the admin for a stadium's opening year.
	 * MONTH_PROMPT       : Prompts the admin for a stadium's opening month.
	 * DAY_PROMPT         : Prompts the user for a stadium's opening day.
	 * SUCCESS            : Ouptputs at the end of the program.
	 *********************************************************************/
	const string NAME_PROMPT    = "\nWhat is the team's name? ";
	const string CONF_PROMPT    = "Which conference do they play in?\n"
			                      "\t1 - AFC\n"
			                      "\t2 - NFC\n"
			                      "Selection: ";
	const string STADIUM_PROMPT = "Which stadium do they play at? ";
	const string STADIUM_ERROR  = "\nThat stadium does not exist. Please "
			                      "enter a different stadium.\n\n";
	const string SUCCESS        = "\nThe team has been successfully added to "
			                      "the program.\n\n";

	//VARIABLE DECLERATIONS
	string       teamName;   //IN   - The team's name.
	conference   teamConf;   //IN   - The team's conference.
	Team*        teamPtr;    //PROC - Used to create the new team object.
	string       stadiumName;//IN   - The stadium's name.
	NFL_Stadium* teamStadium;//PROC - Points to the stadium the team
	                         //       plays at.
	bool         loopAgain;  //PROC - Used as a loop control variable.

	/*********************************************************************
	 * INPUT - Get the team's name.
	 *********************************************************************/
	cout << NAME_PROMPT;
	getline(cin, teamName);

	teamConf = conference(ErrorCheckNum(2, 1, CONF_PROMPT) - 1);

	teamPtr = new Team(teamName, teamConf);

	do
	{
		cout << STADIUM_PROMPT;
		getline(cin, stadiumName);

		if(stadiumMap.Find(stadiumName) == NULL)
		{
			cout << STADIUM_ERROR;
			loopAgain = true;
		}
		else
		{
			teamStadium = &((stadiumMap.Find(stadiumName))->ModValue());
			loopAgain = false;
		}
	}while(loopAgain);

	teamStadium->add_team(*teamPtr);
	cout << SUCCESS;
}

void ChangeTeam(Map<string, NFL_Stadium>& stadiumMap)
{
	const string STADIUM_PROMPT = "Which stadium does the team you wish to "
			                      "modify play at? ";
	const string STADIUM_ERROR  = "\nThat stadium does not exist. Please "
			                      "enter a different stadium.\n\n";
	const string TEAM_ERROR     = "You have declined to modify every team "
			                      "for your chosen stadium. Would you like "
			                      "to check another stadium instead (y/n)? ";
	const string CHANGE_NAME    = "Would you like to modify the teams "
			                      "name (y/n)? ";
	const string NAME_PROMPT    = "Please enter the team's new name: ";
	const string CHANGE_CONF    = "Would you like to switch the team's "
			                      "conference (y/n)?";
	const string RETURN         = "\nChanges complete. Press <enter> to "
			                      "return to the admin menu...\n";

	string stadiumName;
	NFL_Stadium* stadiumPtr;
	List<Team>::Iterator teamIt;
	bool   stadiumLoop;
	bool   teamLoop;
	bool   quit;
	char   modifyTeam;
	char   diffStadium;
	char   changeName;
	string teamName;
	char   changeConf;

	do
	{
		cout << STADIUM_PROMPT;
		getline(cin, stadiumName);

		if(stadiumMap.Find(stadiumName) == NULL)
		{
			cout << STADIUM_ERROR;
			stadiumLoop = true;
		}
		else
		{
			stadiumPtr = &((stadiumMap.Find(stadiumName))->ModValue());
			stadiumLoop = false;

			teamIt = (stadiumPtr->return_teams()).Begin();
			teamLoop = true;
			while(teamLoop)
			{
				modifyTeam = GetInput("Do you wish to modify the " +
						              (*teamIt).GetName() + " (y/n)? ",
						              'Y', 'N', cout, cin);

				if(modifyTeam == 'N')
				{
					++teamIt;
					if(teamIt == (stadiumPtr->return_teams()).End())
					{
						teamLoop = false;
						diffStadium = GetInput(TEAM_ERROR, 'Y', 'N', cout, cin);

						stadiumLoop = (diffStadium == 'Y');
						quit        = !stadiumLoop;
					}
					else
					{
						teamLoop = true;
					}
				}
				else
				{
					teamLoop = false;
					quit     = false;
				}
			}
		}
	}while(stadiumLoop);

	if(!quit)
	{
		changeName = GetInput(CHANGE_NAME, 'Y', 'N', cout, cin);

		if(changeName == 'Y')
		{
			cout << NAME_PROMPT;
			getline(cin, teamName);
		}

		cout << "The " << (*teamIt).GetName() << " currently play in the ";
		if((*teamIt).GetConference() == AFC)
		{
			cout << "AFC. ";
		}
		else
		{
			cout << "NFC. ";
		}
		cout << "Would you like to change their conference to the ";
		if((*teamIt).GetConference() == AFC)
		{
			cout << "NFC (y/n)? ";
		}
		else
		{
			cout << "AFC (y/n)? ";
		}

		changeConf = GetInput(" ", 'Y', 'N', cout, cin);

		if(changeConf == 'Y')
		{
			if((*teamIt).GetConference() == AFC)
			{
				(*teamIt).SetConference(NFC);
			}
			else
			{
				(*teamIt).SetConference(AFC);
			}
		}

		if(changeName == 'Y')
		{
			(*teamIt).SetName(teamName);
		}
	}

	cout << RETURN;
	cin.ignore(1000, '\n');
}

void ChangeStadium(List<NFL_Stadium>& stadiumsAlphabetical,
				   List<NFL_Stadium>& stadiumsTeamName,
				   List<NFL_Stadium>& stadiumsAFC,
				   List<NFL_Stadium>& stadiumsNFC,
				   List<NFL_Stadium>& stadiumsOpenRoof,
				   List<NFL_Stadium>& stadiumsRetractableRoof,
				   List<NFL_Stadium>& stadiumsDateOpened,
				   Map<string, NFL_Stadium>& stadiumMap)
{
	const string STADIUM_PROMPT = "What is the name of the stadium you "
			                      "wish to modify? ";
	const string STADIUM_ERROR  = "\nThat stadium does not exist. Please "
			                      "enter a different stadium.\n\n";
	const string STADIUM_MOD_MENU = "\nWhich field would you like to modify?\n"
			                        "1) Name\n"
			                        "2) Roof Type\n"
			                        "3) Capacity\n"
			                        "4) Opening Date\n"
			                        "0) Save Changes and Exit\n"
			                        "Selection: ";
	const string SUCCESS          = "\nYour changes have been saved. Now "
			                        "returning to the admin menu.\n\n";

	string stadiumName;
	NFL_Stadium* stadiumPtr;
	bool  stadiumLoop;
	int   userSelection;
	int   newRoof;
	long  capacity;
	int   year;
	int   month;
	int   day;
	Date* datePtr;
	NFL_Stadium temp;
	List<NFL_Stadium>::Iterator stadiumIt;

	do
	{
		cout << STADIUM_PROMPT;
		getline(cin, stadiumName);

		if(stadiumMap.Find(stadiumName) == NULL)
		{
			cout << STADIUM_ERROR;
			stadiumLoop = true;
		}
		else
		{
			stadiumPtr  = &((stadiumMap.Find(stadiumName))->ModValue());
			stadiumLoop = false;
		}
	}while(stadiumLoop);

	temp = *stadiumPtr;

	do
	{
		userSelection = ErrorCheckNum(4, 0, STADIUM_MOD_MENU);

		switch(userSelection)
		{
		case 1:
			cout << "\nThe stadium's current name is: "
			     << temp.get_stadium_name()
			     << endl;

			cout << "Please enter the new name: ";
			getline(cin, stadiumName);

			temp.set_stadium_name(stadiumName);

			break;
		case 2:
			cout << "\nThe stadium's current roof is "
			     << (temp.get_roof() == OPEN  ? "open." :
			         temp.get_roof() == DOMED ? "domed. " :
			         	 	                    "retractable. ");
			cout << endl;

			cout << "Do you want to set the stadiums roof type to be: \n"
			     << "1) Open\n"
			     << "2) Domed\n"
			     << "3) Retractable\n"
			     << "Selection: ";
			newRoof = ErrorCheckNum(3, 1, " ");

			temp.set_roof(roof_type(newRoof - 1));

			break;
		case 3:
			cout << "\nThe stadium's current capacity is: "
			     << temp.get_capacity()
			     << endl;

			cout << "Please enter the stadium's new capacity:";
			capacity = ErrorCheckNum(500000, 0, " ");

			temp.set_capacity(capacity);

			break;
		case 4:
			cout << "\nThe stadium's current opening date is: "
			     << (temp.get_opening_date()).printDate()
                 << endl;

			cout << "Enter the opening year: ";
			cin  >> year;
			cin.ignore(1000, '\n');

			cout << "Enter the opening month: ";
			cin  >> month;
			cin.ignore(1000, '\n');

			cout << "Enter the opening day: ";
			cin  >> day;
			cin.ignore(1000, '\n');

			datePtr = new Date(Months(month), day, year);
			temp.set_opening_date(*datePtr);

			break;
		case 0:
			RemoveFromLists(stadiumsAlphabetical,
					      	stadiumsTeamName,
					      	stadiumsAFC,
					      	stadiumsNFC,
					      	stadiumsOpenRoof,
					      	stadiumsRetractableRoof,
					      	stadiumsDateOpened,
					      	stadiumPtr);

			InsertToLists(stadiumsAlphabetical,
					      stadiumsTeamName,
					      stadiumsAFC,
					      stadiumsNFC,
					      stadiumsOpenRoof,
					      stadiumsRetractableRoof,
					      stadiumsDateOpened,
					      &temp);

			stadiumMap.Erase(stadiumPtr->get_stadium_name());
			stadiumMap.Put(temp.get_stadium_name(), temp);

			cout << SUCCESS;
			break;
		}
	}while(userSelection != 0);
}

void RemoveStadium(List<NFL_Stadium>& stadiumsAlphabetical,
				   List<NFL_Stadium>& stadiumsTeamName,
				   List<NFL_Stadium>& stadiumsAFC,
				   List<NFL_Stadium>& stadiumsNFC,
				   List<NFL_Stadium>& stadiumsOpenRoof,
				   List<NFL_Stadium>& stadiumsRetractableRoof,
				   List<NFL_Stadium>& stadiumsDateOpened,
				   Map<string, NFL_Stadium>& stadiumMap,
				   Graph<NFL_Stadium>&       stadiumGraph)
{
	const string NAME_PROMPT = "\nEnter the name of the stadium you "
			                   "wish to remove: ";
	const string NAME_ERROR  = "\nThat stadium could not be found. Please "
			                   "try again.\n";

	string stadiumName;
	NFL_Stadium* stadiumPtr;
	bool getName;

	do
	{
		cout << NAME_PROMPT;
		getline(cin, stadiumName);

		if(stadiumMap.Find(stadiumName) == NULL)
		{
			cout << NAME_ERROR;
			getName = true;
		}
		else
		{
			stadiumPtr = &(stadiumMap.Find(stadiumName)->ModValue());
			getName = false;
		}
	}while(getName);

	RemoveFromLists(stadiumsAlphabetical,
			      	stadiumsTeamName,
			      	stadiumsAFC,
			      	stadiumsNFC,
			      	stadiumsOpenRoof,
			      	stadiumsRetractableRoof,
			      	stadiumsDateOpened,
			      	stadiumPtr);

	stadiumMap.Erase(stadiumPtr->get_stadium_name());

	stadiumGraph.EraseVertex(stadiumGraph.GetVertex(*stadiumPtr));

	SaveTrips(stadiumsAFC, stadiumsNFC, stadiumMap, stadiumGraph);

	cout << endl;
}

void RemoveTeam(List<NFL_Stadium>& stadiumsAlphabetical,
		   	    List<NFL_Stadium>& stadiumsTeamName,
		   	    List<NFL_Stadium>& stadiumsAFC,
		   	    List<NFL_Stadium>& stadiumsNFC,
		   	    List<NFL_Stadium>& stadiumsOpenRoof,
		   	    List<NFL_Stadium>& stadiumsRetractableRoof,
		   	    List<NFL_Stadium>& stadiumsDateOpened,
		   	    Map<string, NFL_Stadium>& stadiumMap)
{
	const string STADIUM_PROMPT = "\nWhich stadium does the team you wish to "
			                      "remove play at? ";
	const string STADIUM_ERROR  = "\nThat stadium does not exist. Please "
			                      "enter a different stadium.\n";
	const string TEAM_ERROR     = "\nYou have declined to remove any team "
			                      "from your chosen stadium. Would you like "
			                      "to check another stadium instead (y/n)? ";
	const string CHANGE_NAME    = "Would you like to modify the teams "
			                      "name (y/n)? ";
	const string NAME_PROMPT    = "Please enter the team's new name: ";
	const string CHANGE_CONF    = "Would you like to switch the team's "
			                      "conference (y/n)?";
	const string RETURN         = "\nChanges complete. Press <enter> to "
			                      "return to the admin menu...\n";

	string stadiumName;
	NFL_Stadium* stadiumPtr;
	NFL_Stadium  tempStadium;
	List<Team>::Iterator teamIt;
	bool   stadiumLoop;
	bool   teamLoop;
	bool   quit;
	char   removeTeam;
	char   diffStadium;
	string teamName;

	do
	{
		cout << STADIUM_PROMPT;
		getline(cin, stadiumName);

		if(stadiumMap.Find(stadiumName) == NULL)
		{
			cout << STADIUM_ERROR;
			stadiumLoop = true;
		}
		else
		{
			stadiumPtr  = &((stadiumMap.Find(stadiumName))->ModValue());
			tempStadium = *stadiumPtr;

			teamIt = tempStadium.return_teams().Begin();

			cout << endl;
			do
			{
				removeTeam = GetInput("Do you wish to remove the " +
						              (*teamIt).GetName() + " (y/n)? ",
						              'Y', 'N', cout, cin);

				if(removeTeam == 'N')
				{
					++teamIt;
					if(teamIt == (stadiumPtr->return_teams()).End())
					{
						teamLoop = false;
						diffStadium = GetInput(TEAM_ERROR, 'Y', 'N', cout, cin);

						stadiumLoop = (diffStadium == 'Y');
						quit        = !stadiumLoop;
					}
					else
					{
						teamLoop = true;
					}
				}
				else
				{
					teamLoop = false;
					stadiumLoop = false;
					quit     = false;
				}
			}while(teamLoop);
		}
	}while(stadiumLoop);

	if(!quit)
	{
		tempStadium.remove_team(teamIt);

		RemoveFromLists(stadiumsAlphabetical,
				      	stadiumsTeamName,
				      	stadiumsAFC,
				      	stadiumsNFC,
				      	stadiumsOpenRoof,
				      	stadiumsRetractableRoof,
				      	stadiumsDateOpened,
				      	stadiumPtr);

		InsertToLists(stadiumsAlphabetical,
				      stadiumsTeamName,
				      stadiumsAFC,
				      stadiumsNFC,
				      stadiumsOpenRoof,
				      stadiumsRetractableRoof,
				      stadiumsDateOpened,
				      &tempStadium);

		stadiumMap.Erase(stadiumPtr->get_stadium_name());
		stadiumMap.Put(tempStadium.get_stadium_name(), tempStadium);

		cout << RETURN;
		cin.ignore(1000, '\n');
	}
	else
	{
		cout << endl;
	}
}


/*************************************************************************
 * FUNCTION RemoveSouv
 * 	This function removes a souvinier from the map and list
 **************************************************************************/
void RemoveSouv( Map<string, Souvenir>& souvenirMap,
					List<Souvenir>		&souvenirList)
{
	string souvName;

	cout << "\nWhich Souvenier do you wish to remove? ";
	getline(cin, souvName);

	if(souvenirMap.Find(souvName) != NULL)
		{
			cout << souvenirMap.Find(souvName)->GetValue().Print() << endl;

			//IF-STATEMENT: Prompts user to confimr the deletion
			if((GetInput("Are you sure you wish to remove " + souvName+ " (y/n)? ", 'Y', 'N', cout, cin)) == 'Y')
			{
				List<Souvenir>::Iterator souvIt;
				souvIt = souvenirList.Search(souvenirMap.Find(souvName)->ModValue());
				souvenirList.Erase(souvIt);
				souvenirMap.Erase(souvName);
			}
			else
			{
				cout << "\n Canceling Removal.\n";
			}
		}
		else
		{
			cout << "\nThat souvenir is not available.\n";
		}
}


/*************************************************************************
 * FUNCTION RemoveSouv
 * 	This function adds a new souvinier to the map and list
 **************************************************************************/
void AddSouv( Map<string, Souvenir>& souvenirMap,
		List<Souvenir>		&souvenirList)
{

	string	name;
	float	cost;

	cout << "What is the name of the new Souvenir? ";
	getline(cin, name);

	cost = ErrorCheckNum(9999.99, 0.0, "Enter the price of the item: ");
	Souvenir	newItem(name, cost);

	souvenirMap.Put(name, newItem);
	souvenirList.InsertBack(newItem);

}
