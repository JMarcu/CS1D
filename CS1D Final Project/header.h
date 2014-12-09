/*************************************************************************
 * CS1D Final Project
 * -----------------------------------------------------------------------
 * AUTHORS     : James Marcu & Phillip Doyle
 * STUDENT IDs : 374443      & 911579
 * CLASS       : CS1D
 * SECTION     : TTh 3:30 PM
 * DUE DATE    : 12/9/2014
 *************************************************************************/
#ifndef HEADER_H_
#define HEADER_H_

#include <string>
#include <iostream>
#include <iomanip>
#include <ostream>
#include <sstream>
#include <fstream>
#include <math.h>
#include <stdlib.h>
#include <limits>
#include "NFL_Stadium.h"
#include "Map.h"
#include "Graph.h"
#include "Souvenir.h"
#include "ErrorCheckNum.h"
using namespace std;

/*********************************************************************
 * CONSTANTS
 * -------------------------------------------------------------------
 * USED FOR FORMATTING
 * -------------------------------------------------------------------
 * OUTPUT_MARGIN : The width of output to the console.
 *********************************************************************/
const int OUTPUT_MARGIN = 80;

//Main_menu_Options	- Stores options for main menu
enum	Main_Menu_Options{
	EXIT,
	LIST_MENU,
	TRIP_MENU,
	SOUVINIR_OPTIONS,
	ADMIN_MENU,
};

/*************************************************************************
 * FUNCTION CreateHashMap
 * 	This function initializes the hash map which stores all current NFL
 * 	stadiums for the program.
 *************************************************************************/
void CreateHashMap(Map<string, NFL_Stadium>& stadiumMap);

/*************************************************************************
 * FUNCTION StringHashOne
 * 	This function hashes a string into an integer between 0 and 67,
 * 	inclusive of zero. It uses a polynomial hashing algorithm to generate
 * 	an integer which is then compressed through a modulo operator.
 *************************************************************************/
int StringHashOne(const string& key);

/*************************************************************************
 * FUNCTION StringHashTwo
 * 	This function hashes a string into an integer between 0 and 13,
 * 	inclusive. It uses a polynomial hashing algorithm to generate
 * 	an integer which is then compressed.
 *************************************************************************/
int StringHashTwo(const string& key);

/*************************************************************************
 * FUNCTION InstantiateStadium
 * 	This function will read in one block of input from an input file and
 * 	use it to create a new instance of the stadium object. This object is
 * 	then returned by reference.
 *************************************************************************/
NFL_Stadium* InstantiateStadium(ifstream& inStream);

/*************************************************************************
 * FUNCTION GenerateStadiumLists
 * 	This function will generate the stadium lists for the program from the
 * 	storage files.
 *************************************************************************/
void GenerateStadiumLists(List<NFL_Stadium>&  stadiumName,
						  List<NFL_Stadium>&  teamName,
						  List<NFL_Stadium>&  afcTeams,
						  List<NFL_Stadium>&  nfcTeams,
						  List<NFL_Stadium>&  openRoofs,
						  List<NFL_Stadium>&  retractableRoofs,
						  List<NFL_Stadium>&  openingDate,
						  const Map<string, NFL_Stadium>& stadiumMap);

/*************************************************************************
 * FUNCTION CreateGraph
 * 	This function instantiates the program's graph object.
 *************************************************************************/
void CreateGraph(Graph<NFL_Stadium>&             stadiumGraph,
		         const List<NFL_Stadium>&        stadiumList,
		         const Map<string, NFL_Stadium>& stadiumMap);

/*************************************************************************
 * FUNCTION CreateSouvenirMap
 * 	This function populates the hash map which stores all current
 * 	Souvenirs for the program.
 *************************************************************************/
void CreateSouvenirMap( Map<string, Souvenir>& souvenirMap,
						List<Souvenir>		&souvenirList);

/*************************************************************************
 * FUNCTION SaveAll
 * 	This function calls the save function on the stadium map and all of
 * 	the stadium lists.
 *************************************************************************/
void SaveAll(const List<NFL_Stadium>& stadiumName,
			 const List<NFL_Stadium>& teamName,
			 const List<NFL_Stadium>& afcTeams,
			 const List<NFL_Stadium>& nfcTeams,
			 const List<NFL_Stadium>& openRoofs,
			 const List<NFL_Stadium>& retractableRoofs,
			 const List<NFL_Stadium>& openingDate,
			 const Map<string, NFL_Stadium>& stadiumMap);

/*************************************************************************
 * FUNCTION SaveMaster
 * 	This function saves the master file of stadium information.
 *************************************************************************/
void SaveMaster(const List<NFL_Stadium>& stadiumName);

/*************************************************************************
 * FUNCTION SaveList
 * 	This function saves the names of all stadiums in a list to a text file.
 *************************************************************************/
void SaveList(const List<NFL_Stadium>& saveThis, string saveFile);

/*************************************************************************
 * FUNCTION SaveSouvinirs
 * 	This function saves the names of all Souvenir in a list to a text file.
 *************************************************************************/
void  SaveSouvinirs(List<Souvenir>		&souvenirList);

/*************************************************************************
 * FUNCTION ListMenu
 *  This is a sub-menu for the program with options for looking at
 *  stadiums.
 *************************************************************************/
void ListMenu(const List<NFL_Stadium>& stadiumsAlphabetical,
			  const List<NFL_Stadium>& stadiumsTeamName,
			  const List<NFL_Stadium>& stadiumsAFC,
			  const List<NFL_Stadium>& stadiumsNFC,
			  const List<NFL_Stadium>& stadiumsOpenRoof,
			  const List<NFL_Stadium>& stadiumsRetractableRoof,
			  const List<NFL_Stadium>& stadiumsDateOpened,
			  const Map<string, NFL_Stadium>& stadiumMap);

/*************************************************************************
 * FUNCTION PrintList
 * 	This will output the contents of a stadium list to the console.
 *************************************************************************/
void PrintList(const List<NFL_Stadium>& printThis);

/*************************************************************************
 * FUNCTION ListOneStadium
 * 	Searches the map for a stadium by name and outputs its formatted data
 *	 to the console.
 *************************************************************************/
void ListOneStadium(const Map<string, NFL_Stadium>& stadiumMap);

/*************************************************************************
 * FUNCTION SouvenirMenu
 * 	This is a sub-menu for interacting with souvenirs.
 *************************************************************************/
void SouvenirMenu(const Map<string, Souvenir>& souvenirMap,
		List<Souvenir>		&souvenirList);

/**********************************************************
 * TripPlanner
 *	This function contains the menu for the program's
 *	trip planning feature
 *********************************************************/
void TripPlannerMenu(const List<NFL_Stadium>& stadiumsAlphabetical,
		const List<NFL_Stadium>& stadiumsTeamName,
		const List<NFL_Stadium>& stadiumsAFC,
		const List<NFL_Stadium>& stadiumsNFC,
		const List<NFL_Stadium>& stadiumsOpenRoof,
		const List<NFL_Stadium>& stadiumsRetractableRoof,
		const List<NFL_Stadium>& stadiumsDateOpened,
		   const Map<string, NFL_Stadium>& stadiumMap,
		             const Graph<NFL_Stadium>&       stadiumGraph,
		             const List<Souvenir>& souvenirList);

/*************************************************************************
 * FUNCTION Build_Custom_Trip
 * 	This function allows the user to create a list of stadiums they wish to
 * 	visit on their trip. It then calculates a route to visit these
 * 	stadiums and outputs the results to the console.
 *************************************************************************/
List<NFL_Stadium> Build_Custom_Trip(const List<NFL_Stadium>& stadiumsAlphabetical,
		 	 	 	 	 	 	    const List<NFL_Stadium>& stadiumsTeamName,
		 	 	 	 	 	 	    const List<NFL_Stadium>& stadiumsAFC,
		 	 	 	 	 	 	    const List<NFL_Stadium>& stadiumsNFC,
		 	 	 	 	 	 	    const List<NFL_Stadium>& stadiumsOpenRoof,
		 	 	 	 	 	 	    const List<NFL_Stadium>& stadiumsRetractableRoof,
		 	 	 	 	 	 	    const List<NFL_Stadium>& stadiumsDateOpened,
		 	 	 	 	 	 	    const Map<string, NFL_Stadium>& stadiumMap,
		 	 	 	 	 	 	    const Graph<NFL_Stadium>&       stadiumGraph,
		 	 	 	 	 	 	    const List<Souvenir>&           souvenirList);

/*************************************************************************
 * FUNCTION CreateHashMap
 * 	This function combines two lists into one, without any duplicates
 *************************************************************************/
void Combine_StadiumLists(const List<NFL_Stadium>& List_one,
							    List<NFL_Stadium>& List_two);

/*************************************************************************
 * FUNCTION CustomRoute
 * 	This calculate a route for visiting user selected NFL stadiums.
 *************************************************************************/
Stack<const NFL_Stadium*> CustomRoute(const NFL_Stadium&        start,
		                              const List<NFL_Stadium>&  destinations,
		                              const Graph<NFL_Stadium>& stadiumGraph);

/*************************************************************************
 * FUNCTION BuySouvenir
 * 	This allows users to plan on buying souvenirs at stadiums.
 *************************************************************************/
void BuySouvenir(const string& stadiumName,
		         const List<Souvenir>& souvenirList,
		         Map<string, List<PurchaseOrder> >& purchaseMap);

/*************************************************************************
 * FUNCTION TripOutput
 * 	Outputs a trip to the console.
 *************************************************************************/
void TripOutput(Stack<const NFL_Stadium*>& route,
		        List<NFL_Stadium>&         destinations,
		        const Graph<NFL_Stadium>&  stadiumGraph,
		        const Map<string, List<PurchaseOrder> >& purchaseOrders);

/*************************************************************************
 * FUNCTION AdminMenu
 * 	This is a sub-menu with admin only functions that modify the program's
 * 	data.
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
			   Graph<NFL_Stadium>&       stadiumGraph);

/*************************************************************************
 * FUNCTION AlphabeticalOrder
 * 	This function returns true if the first string passed in is before
 * 	the second string passed in alphabetically. This function has a couple
 * 	of important differences between it and the compare method of the string
 * 	class. First of all, it is case independent. For true alphabetical
 * 	ordering compare needs all characters to be the same case. Second,
 * 	this orders the shorter word before the longer one (if all characters
 * 	match) rather than after it, unlike compare.
 *************************************************************************/
bool AlphabeticalOrder(string stringOne, string stringTwo);

/*************************************************************************
 * FUNCTION InsertToLists
 * 	This will insert a new stadium object into the proper location in the
 * 	program's stadium lists.
 *************************************************************************/
void InsertToLists(List<NFL_Stadium>& stadiumsAlphabetical,
   	    		   List<NFL_Stadium>& stadiumsTeamName,
   	    		   List<NFL_Stadium>& stadiumsAFC,
   	    		   List<NFL_Stadium>& stadiumsNFC,
   	    		   List<NFL_Stadium>& stadiumsOpenRoof,
   	    		   List<NFL_Stadium>& stadiumsRetractableRoof,
   	    		   List<NFL_Stadium>& stadiumsDateOpened,
   	    		   NFL_Stadium*       stadiumPtr);

/*************************************************************************
 * FUNCTION RemoveFromLists
 * 	This will remove a stadium object from the program's stadium lists.
 *************************************************************************/
void RemoveFromLists(List<NFL_Stadium>& stadiumsAlphabetical,
   	    			 List<NFL_Stadium>& stadiumsTeamName,
   	    			 List<NFL_Stadium>& stadiumsAFC,
   	    			 List<NFL_Stadium>& stadiumsNFC,
   	    			 List<NFL_Stadium>& stadiumsOpenRoof,
   	    			 List<NFL_Stadium>& stadiumsRetractableRoof,
   	    			 List<NFL_Stadium>& stadiumsDateOpened,
   	    			 NFL_Stadium*       stadiumPtr);

/*************************************************************************
 * FUNCTION AddStadium
 * 	This function allows an admin to add a new stadium to the program.
 *************************************************************************/
void AddStadium(List<NFL_Stadium>& stadiumsAlphabetical,
		   	    List<NFL_Stadium>& stadiumsTeamName,
		   	    List<NFL_Stadium>& stadiumsAFC,
		   	    List<NFL_Stadium>& stadiumsNFC,
		   		List<NFL_Stadium>& stadiumsOpenRoof,
		   		List<NFL_Stadium>& stadiumsRetractableRoof,
		   		List<NFL_Stadium>& stadiumsDateOpened,
		   		Map<string, NFL_Stadium>& stadiumMap,
		   		Graph<NFL_Stadium>&       stadiumGraph);

/*************************************************************************
 * FUNCTION AddTeam
 * 	This function allows an admin to add a new team to an existing
 * 	stadium within the program.
 *************************************************************************/
void AddTeam(Map<string, NFL_Stadium>& stadiumMap);

/*************************************************************************
 * FUNCTION ChangeTeam
 * 	This function allows an admin to modify an existing team object.
 *************************************************************************/
void ChangeTeam(Map<string, NFL_Stadium>& stadiumMap);

/*************************************************************************
 * FUNCTION ChangeStadium
 * 	This function allows an admin to modify an existing stadium.
 *************************************************************************/
void ChangeStadium(List<NFL_Stadium>& stadiumsAlphabetical,
				   List<NFL_Stadium>& stadiumsTeamName,
				   List<NFL_Stadium>& stadiumsAFC,
				   List<NFL_Stadium>& stadiumsNFC,
				   List<NFL_Stadium>& stadiumsOpenRoof,
				   List<NFL_Stadium>& stadiumsRetractableRoof,
				   List<NFL_Stadium>& stadiumsDateOpened,
				   Map<string, NFL_Stadium>& stadiumMap);

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
				   Graph<NFL_Stadium>&       stadiumGraph);

/*************************************************************************
 * FUNCTION RemoveTeam
 * 	This function allows an admin to remove an existing team.
 *************************************************************************/
void RemoveTeam(List<NFL_Stadium>& stadiumsAlphabetical,
		   	    List<NFL_Stadium>& stadiumsTeamName,
		   	    List<NFL_Stadium>& stadiumsAFC,
		   	    List<NFL_Stadium>& stadiumsNFC,
		   	    List<NFL_Stadium>& stadiumsOpenRoof,
		   	    List<NFL_Stadium>& stadiumsRetractableRoof,
		   	    List<NFL_Stadium>& stadiumsDateOpened,
		   	    Map<string, NFL_Stadium>& stadiumMap);

/*************************************************************************
 * FUNCTION RemoveSouv
 * 	This function allows an admin to remove an existing souvenir.
 *************************************************************************/
void RemoveSouv(Map<string, Souvenir>& souvenirMap,
				List<Souvenir>&        souvenirList);

/*************************************************************************
 * FUNCTION AddSouv
 * 	This function allows an admin to add a new souvenir to the program.
 *************************************************************************/
void AddSouv(Map<string, Souvenir>& souvenirMap,
			List<Souvenir>&         souvenirList);

/*************************************************************************
 * FUNCTION InstantiateStadium
 * 	This function will read in one block of input from an input file and
 * 	use it to create a new instance of the Souvenir object. This object is
 * 	then returned by reference.
 *************************************************************************/
Souvenir* InstantiateSouvenir(ifstream& inStream);//IN & OUT - The input
                                                  //           stream.

/**********************************************************
 * PrintHeader-
 *	This function receives an assignment name, type and number
 *	 then outputs the appropriate header
 *********************************************************/
void PrintHeader(ostream &oFile,	// IN - Output stream
				 string asName,		// IN - assignment Name
				 char asType,		// IN - assignment type
				 	 	 	 	 	// 		(LAB or ASSIGNMENT)
				 int asNum);		// IN - assignment number

/************************************************************************
 * OutputLine
 * 	This function outputs a line consisting of a single character
 ************************************************************************/
void OutputLine(char symbol,		   //IN- Symbol for the line
			    ostream &oFile,		   //IN- Output Location
			    const int LINE_LENGTH); //IN - Length of the line

/*************************************************************************
 * FUNCTION GetInput
 * This will get a character value from the user through the provided
 * input stream. The input will be error checked to make sure it is
 * equal to at least one of two provided values. The character will always
 * be returned as an uppercase character.
 *************************************************************************/
char GetInput(string   prompt,   //IN & OUT - The prompt which is sent
								 //           to the user.
			  char     char1,    //CALC     - One acceptable input.
			  char     char2,    //CALC     - Other acceptable input.
			  ostream& outStream,//CALC     - The stream to output to.
			  istream& inStream);//CALC     - The stream to input from.

#endif /* HEADER_H_ */
