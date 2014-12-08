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
 * FUNCTION InsertToLists
 * -----------------------------------------------------------------------
 * This will insert a new stadium object into the proper location in the
 * program's stadium lists.
 * -----------------------------------------------------------------------
 * PRE-CONDITIONS -
 * 	stadiumAlphabetical 	: The list to store all stadiums, sorted by
 * 	                          stadium name.
 * 	stadiumsTeamName   		: The list to store all stadiums, sorted by
 * 							  team name.
 * 	stadiumsAFC            	: The list to store all stadiums in the AFC.
 * 	stadiumsNFC        		: The list to store all stadiums in the NFC.
 * 	stadiumsOpenRoof       	: The list to store all stadiums with open roofs.
 * 	stadiumsRetractableRoof	: The list to store all stadiums with
 * 							  retractable roofs.
 * 	stadiumsDateOpened     	: The list to store all stadiums, sorted by
 * 							  opening date.
 * 	stadiumPtr      		: The new stadium object to add to the lists.
 *
 * POST-CONDITIONS -
 * 	stadiumPtr : The stadium object pointed to will be added in the
 * 	             correct location to the relevant lists.
 *
 *************************************************************************/
void InsertToLists(List<NFL_Stadium>& stadiumsAlphabetical,
   	    		   List<NFL_Stadium>& stadiumsTeamName,
   	    		   List<NFL_Stadium>& stadiumsAFC,
   	    		   List<NFL_Stadium>& stadiumsNFC,
   	    		   List<NFL_Stadium>& stadiumsOpenRoof,
   	    		   List<NFL_Stadium>& stadiumsRetractableRoof,
   	    		   List<NFL_Stadium>& stadiumsDateOpened,
   	    		   NFL_Stadium*       stadiumPtr)
{
	//VARIABLE DECLERATIONS
	bool insertFurther;                   //PROC - Controls the loop that
	                                      //       iterates to the insertion
	                                      //       point in the lists.
	List<NFL_Stadium>::Iterator stadiumIt;//PROC - Iterates the lists of
	                                      //       stadiums.

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

/*************************************************************************
 * FUNCTION RemoveToLists
 * -----------------------------------------------------------------------
 * This will remove a stadium object from the program's stadium lists.
 * -----------------------------------------------------------------------
 * PRE-CONDITIONS -
 * 	stadiumAlphabetical 	: The list to store all stadiums, sorted by
 * 	                          stadium name.
 * 	stadiumsTeamName   		: The list to store all stadiums, sorted by
 * 							  team name.
 * 	stadiumsAFC            	: The list to store all stadiums in the AFC.
 * 	stadiumsNFC        		: The list to store all stadiums in the NFC.
 * 	stadiumsOpenRoof       	: The list to store all stadiums with open roofs.
 * 	stadiumsRetractableRoof	: The list to store all stadiums with
 * 							  retractable roofs.
 * 	stadiumsDateOpened     	: The list to store all stadiums, sorted by
 * 							  opening date.
 * 	stadiumPtr      		: The stadium object to remove from the lists.
 *
 * POST-CONDITIONS -
 * 	stadiumPtr : The stadium object pointed to will be removed from the
 * 	             relevant lists.
 *
 *************************************************************************/
void RemoveFromLists(List<NFL_Stadium>& stadiumsAlphabetical,
   	    			 List<NFL_Stadium>& stadiumsTeamName,
   	    			 List<NFL_Stadium>& stadiumsAFC,
   	    			 List<NFL_Stadium>& stadiumsNFC,
   	    			 List<NFL_Stadium>& stadiumsOpenRoof,
   	    			 List<NFL_Stadium>& stadiumsRetractableRoof,
   	    			 List<NFL_Stadium>& stadiumsDateOpened,
   	    			 NFL_Stadium*       stadiumPtr)
{
	//VARIABLE DECLERATIONS
	List<NFL_Stadium>::Iterator stadiumIt;//PROC - Used to iterate the
	                                      //       lists of stadiums.

	/*********************************************************************
	 * PROC - All stadiums belong to these lists. The stadium object will
	 *        be removed from them.
	 *********************************************************************/
	stadiumIt = stadiumsAlphabetical.Search(*stadiumPtr);
	stadiumsAlphabetical.Erase(stadiumIt);

	stadiumIt = stadiumsTeamName.Search(*stadiumPtr);
	stadiumsTeamName.Erase(stadiumIt);

	stadiumsDateOpened.Erase(stadiumsDateOpened.Search(*stadiumPtr));

	/*********************************************************************
	 * PROC - If the stadium has a team in the AFC it is on this
	 *        list and will be removed.
	 *********************************************************************/
	stadiumIt = stadiumsAFC.Search(*stadiumPtr);
	if(stadiumIt != stadiumsAFC.End())
	{
		stadiumsAFC.Erase(stadiumIt);
	}

	/*********************************************************************
	 * PROC - If the stadium has a team in the NFC it is on this
	 *        list and will be removed.
	 *********************************************************************/
	stadiumIt = stadiumsNFC.Search(*stadiumPtr);
	if(stadiumIt != stadiumsNFC.End())
	{
		stadiumsNFC.Erase(stadiumIt);
	}

	/*********************************************************************
	 * PROC - If the stadium has an open roof it will be in this list and
	 *        will be removed.
	 *********************************************************************/
	stadiumIt = stadiumsOpenRoof.Search(*stadiumPtr);
	if(stadiumIt != stadiumsOpenRoof.End())
	{
		stadiumsOpenRoof.Erase(stadiumIt);
	}

	/*********************************************************************
	 * PROC - If the stadium has a retractable roof it will be in this list
	 *        and will be removed.
	 *********************************************************************/
	stadiumIt = stadiumsRetractableRoof.Search(*stadiumPtr);
	if(stadiumIt != stadiumsOpenRoof.End())
	{
		stadiumsRetractableRoof.Erase(stadiumIt);
	}
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
	bool         validDest;      //PROC - Used to find a valid route destination.
	bool         enterRoutes;    //PROC - Used to continue entering routes.
	string       destination;    //IN   - Name of the stadium a route goes to.
	float        weight;         //IN   - Distance(mi) of a route.
	List<NFL_Stadium>::Iterator stadiumIt;//PROC - Iterates stadium lists.
	List<Team>::Iterator        teamIt;   //PROC - Iterates team lists.

	//VARIABLE INITIALIZATIONS
	enterTeams  = true;
	enterRoutes = true;

	/*********************************************************************
	 * INPUT - Get the name of the new stadium.
	 *********************************************************************/
	cout << NAME_PROMPT;
	getline(cin, stadiumName);

	/*********************************************************************
	 * INPUT - Get the roof type of the new stadium.
	 *********************************************************************/
	stadiumRoof = roof_type(ErrorCheckNum(3, 1, ROOF_PROMPT) - 1);

	/*********************************************************************
	 * INPUT - Get the capacity of the new stadium.
	 *********************************************************************/
	stadiumCapacity = ErrorCheckNum(500000, 0, CAPACITY_PROMPT);

	/*********************************************************************
	 * INPUT - Get the opening date of the new stadium.
	 *********************************************************************/
	openingYear  = ErrorCheckNum(3000, 1900, YEAR_PROMPT);
	openingMonth = ErrorCheckNum(12,   1,    MONTH_PROMPT);
	openingDay   = ErrorCheckNum(31,   1,    DAY_PROMPT);
	stadiumDate  = new Date(Months(openingMonth), openingDay, openingYear);

	/*********************************************************************
	 * PROC - Create the stadium object using this data. We have all the
	 *        information we need to initialize, so we create it here and
	 *        modify it from here on out.
	 *********************************************************************/
	stadiumPtr = new NFL_Stadium(stadiumRoof,      stadiumName,
			                     stadiumCapacity, *stadiumDate);

	/*********************************************************************
	 * INPUT - Get the location of the new stadium.
	 *********************************************************************/
	cout << LOCATION_PROMPT;
	getline(cin, stadiumLocation);
	stadiumPtr->set_location(stadiumLocation);

	/*********************************************************************
	 * INPUT - Get the teams that play at the new stadium.
	 *********************************************************************/
	cout << FIRST_TEAM_PROMPT;
	while(enterTeams)
	{
		/*****************************************************************
		 * INPUT - Get the name of the team.
		 *****************************************************************/
		cout << TEAM_NAME_PROMPT;
		getline(cin, teamName);

		/*****************************************************************
		 * INPUT - Get the conference of the team.
		 *****************************************************************/
		teamConference = conference(ErrorCheckNum(2, 1, TEAM_CONF_PROMPT) - 1);

		/*********************************************************************
		 * PROC - Create the team and add it to the stadium.
		 *********************************************************************/
		teamPtr = new Team(teamName, teamConference);
		stadiumPtr->add_team(*teamPtr);

		/*****************************************************************
		 * INPUT - Find out if there are other teams that play at the
		 *         stadium to add to the program.
		 *****************************************************************/
		if (GetInput(SECOND_TEAM_PROMPT, 'y', 'n', cout, cin) == 'N')
		{
			enterTeams = false;
		}
	}

	/*********************************************************************
	 * INPUT - Get the routes that this stadium is on for use in the
	 *         program's trip planning function. At least one must be
	 *         provided.
	 *********************************************************************/
	cout << GRAPH_PROMPT;
	stadiumGraph.AddVertex(*stadiumPtr);
	do
	{
		/*****************************************************************
		 * INPUT - The user enters the name of the stadium that the route
		 *         connects to. The name is checked for validity.
		 *****************************************************************/
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

		/*****************************************************************
		 * INPUT - Get the weight of the edge.
		 *****************************************************************/
		weight = ErrorCheckNum(30000.0, 0.0, WEIGHT_PROMPT);

		/*****************************************************************
		 * PROC - Add the route to the graph.
		 *****************************************************************/
		stadiumGraph.AddEdge(stadiumGraph.GetVertex(*stadiumPtr),
				             stadiumGraph.GetVertex(stadiumMap.Find(destination)->GetValue()),
				             weight);

		/*****************************************************************
		 * INPUT - Find out if there are more routes to add.
		 *****************************************************************/
		if (GetInput(ROUTE_PROMPT, 'y', 'n', cout, cin) == 'N')
		{
			enterRoutes = false;
		}

	}while(enterRoutes);

	/*********************************************************************
	 * PROC - Add the new stadium object to the program's stadium lists.
	 *********************************************************************/
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

	/*********************************************************************
	 * INPUT - Update the pre-programmed trips with the new stadium in
	 *         the destinations list.
	 *********************************************************************/
	SaveTrips(stadiumsNFC, stadiumsAFC, stadiumMap, stadiumGraph);

	cout << SUCCESS;
}

/*************************************************************************
 * FUNCTION AddTeam
 * -----------------------------------------------------------------------
 * This function allows an admin to add a new team to an existing
 * stadium within the program.
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
 * 	The new team will be added to the appropriate stadium.
 *************************************************************************/
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

	/*********************************************************************
	 * INPUT - Get the team's conference.
	 *********************************************************************/
	teamConf = conference(ErrorCheckNum(2, 1, CONF_PROMPT) - 1);

	/*********************************************************************
	 * PROC - Create the team object.
	 *********************************************************************/
	teamPtr = new Team(teamName, teamConf);

	/*********************************************************************
	 * INPUT - Get the stadium to add the team to.
	 *********************************************************************/
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

	/*********************************************************************
	 * PROC - Add the team to the stadium.
	 *********************************************************************/
	teamStadium->add_team(*teamPtr);
	cout << SUCCESS;
}

/*************************************************************************
 * FUNCTION ChangeTeam
 * -----------------------------------------------------------------------
 * This function allows an admin to modify an existing team object.
 * -----------------------------------------------------------------------
 * PRE-CONDITIONS -
 * 	stadiumMap      : The map which has all stadiums stored.
 *
 * POST-CONDITIONS -
 * 	The team object will be updated.
 *************************************************************************/
void ChangeTeam(Map<string, NFL_Stadium>& stadiumMap)
{
	/*********************************************************************
	 * CONSTANTS
	 * -------------------------------------------------------------------
	 * USED FOR OUTPUT
	 * -------------------------------------------------------------------
	 * STADIUM_PROMPT : Prompts the user for the name of the stadium
	 *  				the team plays at.
	 * STADIUM_ERROR  : Output if the user enters an incorrect stadium
	 *                  name.
	 * TEAM_ERROR     : Output if the user declines to modify all teams
	 *                  at their chosen stadium.
	 * CHANGE_NAME    : Prompts the user for a change in name for the team.
	 * NAME_PROMPT    : Output when the user enters the new name.
	 * CHANGE_CONF    : Prompts if the user wants to modify the conference.
	 * RETURN         : A closing output for user feedback.
	 *********************************************************************/
	const string STADIUM_PROMPT = "Which stadium does the team you wish to "
			                      "modify play at? ";
	const string STADIUM_ERROR  = "\nThat stadium does not exist. Please "
			                      "enter a different stadium.\n\n";
	const string TEAM_ERROR     = "You have declined to modify every team "
			                      "for your chosen stadium.\nWould you like "
			                      "to check another stadium instead (y/n)? ";
	const string CHANGE_NAME    = "Would you like to modify the teams "
			                      "name (y/n)? ";
	const string NAME_PROMPT    = "Please enter the team's new name: ";
	const string CHANGE_CONF    = "Would you like to switch the team's "
			                      "conference (y/n)?";
	const string RETURN         = "\nChanges complete. Press <enter> to "
			                      "return to the admin menu...\n";

	//VARIABLE DECLERATIONS
	string stadiumName;         //IN   - Name of the team's stadium.
	NFL_Stadium* stadiumPtr;    //PROC - Points at the team's stadium.
	List<Team>::Iterator teamIt;//PROC - Used to iterate lists of teams.
	bool   stadiumLoop;         //PROC - Controls the stadium name input loop.
	bool   teamLoop;            //PROC - Controls the team selection loop.
	bool   quit;                //PROC - Controls the main do-while loop.
	char   modifyTeam;          //IN   - If the user wants to modify the
	                            //       team.
	char   diffStadium;         //IN   - If the user wants to switch to a
	                            //       different stadium.
	char   changeName;          //IN   - If the user wants to change the
	                            //       team's name.
	string teamName;            //IN   - The team's new name.
	char   changeConf;          //IN   - If the user wants to change the
	                            //       teams conference.

	/*********************************************************************
	 * IN - Select the stadium the team plays at and the correct team
	 *      from that stadium.
	 *********************************************************************/
	do
	{
		/*****************************************************************
		 * INPUT - Get the team's name.
		 *****************************************************************/
		cout << STADIUM_PROMPT;
		getline(cin, stadiumName);

		/*****************************************************************
		 * PROC - If the stadium name cannot be found then the program
		 *        will prompt for a new one.
		 *****************************************************************/
		if(stadiumMap.Find(stadiumName) == NULL)
		{
			cout << STADIUM_ERROR;
			stadiumLoop = true;
		}
		else//Else if the name is found...
		{
			/*************************************************************
			 * PROC - Get a reference to the stadium.
			 ************************************************************/
			stadiumPtr = &((stadiumMap.Find(stadiumName))->ModValue());
			stadiumLoop = false;

			/*************************************************************
			 * INPUT - Get which team at the stadium the user wants to
			 *         modify. If they decline every team at the chosen
			 *         stadium they are prompted to enter a new stadium,
			 *         or they can choose to exit.
			 *************************************************************/
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

	/*********************************************************************
	 * PRCO - Allow the admin to make changes to the team they selected.
	 *********************************************************************/
	if(!quit)
	{
		/*****************************************************************
		 * INPUT - Allow the user to change the team's name.
		 *****************************************************************/
		changeName = GetInput(CHANGE_NAME, 'Y', 'N', cout, cin);
		if(changeName == 'Y')
		{
			cout << NAME_PROMPT;
			getline(cin, teamName);
		}

		/*****************************************************************
		 * INPUT - Allow the user to change the team's conference.
		 *****************************************************************/
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

		/*****************************************************************
		 * PROC - Change the team's conference.
		 *****************************************************************/
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

		/*****************************************************************
		 * PROC - Change the team's name.
		 *****************************************************************/
		if(changeName == 'Y')
		{
			(*teamIt).SetName(teamName);
		}
	}//END if(!quit)

	cout << RETURN;
	cin.ignore(1000, '\n');
}

/*************************************************************************
 * FUNCTION ChangeStadium
 * -----------------------------------------------------------------------
 * This function allows an admin to modify an existing stadium.
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
 * 	The stadium will have the changes selected enacted on it.
 *************************************************************************/
void ChangeStadium(List<NFL_Stadium>& stadiumsAlphabetical,
				   List<NFL_Stadium>& stadiumsTeamName,
				   List<NFL_Stadium>& stadiumsAFC,
				   List<NFL_Stadium>& stadiumsNFC,
				   List<NFL_Stadium>& stadiumsOpenRoof,
				   List<NFL_Stadium>& stadiumsRetractableRoof,
				   List<NFL_Stadium>& stadiumsDateOpened,
				   Map<string, NFL_Stadium>& stadiumMap)
{
	/*********************************************************************
	 * CONSTANTS
	 * -------------------------------------------------------------------
	 * USED FOR OUTPUT
	 * -------------------------------------------------------------------
	 * STADIUM_PROMPT   : Prompts for the name of the stadium.
	 * STADIUM_ERROR    : Output if the entered stadium could not be found.
	 * STADIUM_MOD_MENU : A menu for options on how to modify the stadium.
	 * SUCCESS          : Output at the end for user feedback.
	 *********************************************************************/
	const string STADIUM_PROMPT   = "What is the name of the stadium you "
			                        "wish to modify? ";
	const string STADIUM_ERROR    = "\nThat stadium does not exist. Please "
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

	//VARIABLE DECLERATIONS
	string stadiumName;     //IN   - The stadium's name.
	NFL_Stadium* stadiumPtr;//PROC - Points at the stadium.
	bool  stadiumLoop;      //PROC - Controls the input loop.
	int   userSelection;    //IN   - Stores the users menu choice.
	int   newRoof;          //IN   - Which roof the stadium should have.
	long  capacity;         //IN   - The stadium's capacity.
	int   year;             //IN   - The stadium's opening date.
	int   month;            //IN   - The stadium's opening month.
	int   day;              //IN   - The stadium's opening day.
	Date* datePtr;          //PROC - Creates new date objects.
	NFL_Stadium temp;       //PROC - Used to modify the stadium.
	List<NFL_Stadium>::Iterator stadiumIt;//PROC - Iterates stadium lists.

	/*********************************************************************
	 * INPUT - Get the ename of the stadium to modify and create a
	 *         reference to the object.
	 *********************************************************************/
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

	/*********************************************************************
	 * PROC - Allow the admin to make changes to the stadium they selected.
	 *********************************************************************/
	do
	{
		/*****************************************************************
		 * INPUT - Get the field they want to modify.
		 *****************************************************************/
		userSelection = ErrorCheckNum(4, 0, STADIUM_MOD_MENU);

		switch(userSelection)
		{
		/*****************************************************************
		 * PROC - Change the stadium's name.
		 *****************************************************************/
		case 1:
			cout << "\nThe stadium's current name is: "
			     << temp.get_stadium_name()
			     << endl;

			cout << "Please enter the new name: ";
			getline(cin, stadiumName);

			temp.set_stadium_name(stadiumName);

			break;

		/*****************************************************************
		 * PROC - Change the stadium's roof type.
		 *****************************************************************/
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

		/*****************************************************************
		 * PROC - Change the stadium's capacity.
		 *****************************************************************/
		case 3:
			cout << "\nThe stadium's current capacity is: "
			     << temp.get_capacity()
			     << endl;

			cout << "Please enter the stadium's new capacity:";
			capacity = ErrorCheckNum(500000, 0, " ");

			temp.set_capacity(capacity);

			break;

		/*****************************************************************
		 * PROC - Change the stadium's opening date.
		 *****************************************************************/
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

		/*****************************************************************
		 * PROC - When the admin is done making changes the program updates.
		 *****************************************************************/
		case 0:
			/*************************************************************
			 * PROC - Remove the current stadium object from the program.
			 *************************************************************/
			RemoveFromLists(stadiumsAlphabetical,
					      	stadiumsTeamName,
					      	stadiumsAFC,
					      	stadiumsNFC,
					      	stadiumsOpenRoof,
					      	stadiumsRetractableRoof,
					      	stadiumsDateOpened,
					      	stadiumPtr);
			stadiumMap.Erase(stadiumPtr->get_stadium_name());

			/*****************************************************************
			 * PROC - Replace the old object with the new one.
			 *****************************************************************/
			InsertToLists(stadiumsAlphabetical,
					      stadiumsTeamName,
					      stadiumsAFC,
					      stadiumsNFC,
					      stadiumsOpenRoof,
					      stadiumsRetractableRoof,
					      stadiumsDateOpened,
					      &temp);
			stadiumMap.Put(temp.get_stadium_name(), temp);

			cout << SUCCESS;
			break;
		}//END switch(userSelection)
	}while(userSelection != 0);
}

/*************************************************************************
 * FUNCTION RemoveStadium
 * -----------------------------------------------------------------------
 * This function allows an admin to remove an existing stadium.
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
 * 	stadiumGraph    : The graph of all stadiums, used for trip planning.
 *
 * POST-CONDITIONS -
 * 	The stadium will be removed from the program.
 *************************************************************************/
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
	/*********************************************************************
	 * CONSTANTS
	 * -------------------------------------------------------------------
	 * USED FOR OUTPUT
	 * -------------------------------------------------------------------
	 * NAME_PROMPT : Prompts for the name of the stadium.
	 * NAME_ERROR  : Output if the entered stadium could not be found.
	 *********************************************************************/
	const string NAME_PROMPT = "\nEnter the name of the stadium you "
			                   "wish to remove: ";
	const string NAME_ERROR  = "\nThat stadium could not be found. Please "
			                   "try again.\n";

	//VARIABLE DECLERATIONS
	string stadiumName;     //IN   - The stadium's name.
	NFL_Stadium* stadiumPtr;//PROC - A pointer to the stadium object.
	bool getName;           //PROC - Controls the input loop.

	/*********************************************************************
	 * INPUT - Get the name of the stadium to remove and make a reference
	 *         to it.
	 *********************************************************************/
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

	/*********************************************************************
	 * PROC - Remove the stadium from the program's storage.
	 *********************************************************************/
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

	/*********************************************************************
	 * PROC - Recreate the pre-planned trips without the now removed
	 *        stadium.
	 *********************************************************************/
	SaveTrips(stadiumsAFC, stadiumsNFC, stadiumMap, stadiumGraph);

	cout << endl;
}

/*************************************************************************
 * FUNCTION RemoveTeam
 * -----------------------------------------------------------------------
 * This function allows an admin to remove an existing team.
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
 * 	The team will be removed from the program.
 *************************************************************************/
void RemoveTeam(List<NFL_Stadium>& stadiumsAlphabetical,
		   	    List<NFL_Stadium>& stadiumsTeamName,
		   	    List<NFL_Stadium>& stadiumsAFC,
		   	    List<NFL_Stadium>& stadiumsNFC,
		   	    List<NFL_Stadium>& stadiumsOpenRoof,
		   	    List<NFL_Stadium>& stadiumsRetractableRoof,
		   	    List<NFL_Stadium>& stadiumsDateOpened,
		   	    Map<string, NFL_Stadium>& stadiumMap)
{
	/*********************************************************************
	 * CONSTANTS
	 * -------------------------------------------------------------------
	 * USED FOR OUTPUT
	 * -------------------------------------------------------------------
	 * STADIUM_PROMPT : Prompts for the name of the stadium.
	 * STADIUM_ERROR  : Output if the entered stadium could not be found.
	 * TEAM_ERROR     : Output if the user doesn't want to remove any
	 *                  teams from their chosen stadium.
	 * RETURN         : Output at function close for user feedback.
	 *********************************************************************/
	const string STADIUM_PROMPT = "\nWhich stadium does the team you wish to "
			                      "remove play at? ";
	const string STADIUM_ERROR  = "\nThat stadium does not exist. Please "
			                      "enter a different stadium.\n";
	const string TEAM_ERROR     = "\nYou have declined to remove any team "
			                      "from your chosen stadium. Would you like "
			                      "to check another stadium instead (y/n)? ";
	const string RETURN         = "\nChanges complete. Press <enter> to "
			                      "return to the admin menu...\n";

	//VARIABLE DECLERATIONS
	string stadiumName;         //IN   - The stadium's name.
	NFL_Stadium* stadiumPtr;    //PROC - A pointer to the stadium.
	NFL_Stadium  tempStadium;   //PROC - A temporary reference to the stadium.
	List<Team>::Iterator teamIt;//PROC - Iterates lists of teams.
	bool   stadiumLoop;         //PROC - Controls the stadium input loop.
	bool   teamLoop;            //PROC - Controls the team input loop.
	bool   quit;                //PROC - Allows the user to exit early.
	char   removeTeam;          //IN   - Used to select which team to remove.
	char   diffStadium;         //IN   - Used to switch to a different stadium.
	string teamName;            //IN   - Name of the team to remove.

	/*********************************************************************
	 * INPUT - Get a reference to the stadium the team plays at.
	 *********************************************************************/
	do//while(stadiumLoop)
	{
		/*****************************************************************
		 * INPUT - Get the name of the stadium.
		 *****************************************************************/
		cout << STADIUM_PROMPT;
		getline(cin, stadiumName);

		/*****************************************************************
		 * PROC - If the stadium could not be found then prompt for a new
		 *        selection.
		 *****************************************************************/
		if(stadiumMap.Find(stadiumName) == NULL)
		{
			cout << STADIUM_ERROR;
			stadiumLoop = true;
		}
		else//Else if the stadium does exist...
		{
			/*************************************************************
			 * PROC - Create a reference to the stadium.
			 *************************************************************/
			stadiumPtr  = &((stadiumMap.Find(stadiumName))->ModValue());
			tempStadium = *stadiumPtr;

			teamIt = tempStadium.return_teams().Begin();

			cout << endl;

			/*************************************************************
			 * INPUT - Select which team of the stadium to remove.
			 *************************************************************/
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

	/*********************************************************************
	 * PROC - Delete the team.
	 *********************************************************************/
	if(!quit)
	{
		/*****************************************************************
		 * PROC - Remove the team from the stadium object.
		 *****************************************************************/
		tempStadium.remove_team(teamIt);

		/*****************************************************************
		 * PROC - Remove the current stadium object from program.
		 *****************************************************************/
		RemoveFromLists(stadiumsAlphabetical,
				      	stadiumsTeamName,
				      	stadiumsAFC,
				      	stadiumsNFC,
				      	stadiumsOpenRoof,
				      	stadiumsRetractableRoof,
				      	stadiumsDateOpened,
				      	stadiumPtr);
		stadiumMap.Erase(stadiumPtr->get_stadium_name());

		/*****************************************************************
		 * PROC - Replace the stadium with its modified version.
		 *****************************************************************/
		InsertToLists(stadiumsAlphabetical,
				      stadiumsTeamName,
				      stadiumsAFC,
				      stadiumsNFC,
				      stadiumsOpenRoof,
				      stadiumsRetractableRoof,
				      stadiumsDateOpened,
				      &tempStadium);
		stadiumMap.Put(tempStadium.get_stadium_name(), tempStadium);

		cout << RETURN;
		cin.ignore(1000, '\n');
	}
	else//Allows the user to exit without making changes.
	{
		cout << endl;
	}
}

/*************************************************************************
 * FUNCTION RemoveSouv
 * -----------------------------------------------------------------------
 * This function allows an admin to remove an existing souvenir.
 * -----------------------------------------------------------------------
 * PRE-CONDITIONS -
 * 	souvenirMap  : A map which stores all souvenir objects.
 * 	souvenirList : A list which stores all souvenir objects.
 *
 * POST-CONDITIONS -
 * 	The souvenir will be removed from the program.
 *************************************************************************/
void RemoveSouv(Map<string, Souvenir>& souvenirMap,
				List<Souvenir>&        souvenirList)
{
	//VARIABLE DECLERATIONS
	string souvName;//IN - The name of the souvenir to remove.

	/*********************************************************************
	 * INPUT - Get the name of the souvenir to delete.
	 *********************************************************************/
	cout << "\nWhich Souvenier do you wish to remove? ";
	getline(cin, souvName);

	/*********************************************************************
	 * PROC - If the souvenir exists then delete it. Otherwise return to
	 *        the admin menu.
	 *********************************************************************/
	if(souvenirMap.Find(souvName) != NULL)
		{
			cout << souvenirMap.Find(souvName)->GetValue().Print() << endl;

			/*************************************************************
			 * INPUT - Prompts to make sure the user wants to remove
			 *         the chosen souvenir.
			 *************************************************************/
			if((GetInput("Are you sure you wish to remove " + souvName
					   + " (y/n)? ", 'Y', 'N', cout, cin)) == 'Y')
			{
				/*********************************************************
				 * PROC - Delete the souvenir.
				 *********************************************************/
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
 * FUNCTION AddSouv
 * -----------------------------------------------------------------------
 * This function allows an admin to add a new souvenir to the program.
 * -----------------------------------------------------------------------
 * PRE-CONDITIONS -
 * 	souvenirMap  : A map which stores all souvenir objects.
 * 	souvenirList : A list which stores all souvenir objects.
 *
 * POST-CONDITIONS -
 * 	The souvenir will be added from the program.
 *************************************************************************/
void AddSouv(Map<string, Souvenir>& souvenirMap,
			List<Souvenir>&         souvenirList)
{
	/*********************************************************************
	 * CONSTANTS
	 * -------------------------------------------------------------------
	 * USED FOR OUTPUT
	 * -------------------------------------------------------------------
	 * RETURN         : Output at function close for user feedback.
	 *********************************************************************/
	const string RETURN         = "\nChanges complete. Press <enter> to "
			                      "return to the admin menu...\n";

	//VARIABLE DECLERATIONS
	string	name;//IN - The souvenir's name.
	float	cost;//IN - The souvenir's cost.

	/*********************************************************************
	 * INPUT - Get the name of the souvenir.
	 *********************************************************************/
	cout << "What is the name of the new souvenir? ";
	getline(cin, name);

	/*********************************************************************
	 * INPUT - Get the cost of the souvenir.
	 *********************************************************************/
	cost = ErrorCheckNum(9999.99, 0.0, "Enter the price of the item: ");
	cout << endl;

	/*********************************************************************
	 * PROC - Create the new object.
	 *********************************************************************/
	Souvenir newItem(name, cost);

	/*********************************************************************
	 * PROC - Add it to the program.
	 *********************************************************************/
	souvenirMap.Put(name, newItem);
	souvenirList.InsertBack(newItem);

	cout << RETURN;
}
