/*************************************************************************
 * CS1D Final Project
 * -----------------------------------------------------------------------
 * AUTHORS     : James Marcu & Phillip Doyle
 * STUDENT IDs : 374443      & 911579
 * CLASS       : CS1D
 * SECTION     : TTh 3:30 PM
 * DUE DATE    : 12/9/2014
 *************************************************************************/
#ifndef NFL_STADIUM_H_
#define NFL_STADIUM_H_

#include<string>
#include"Team.h"
#include"DateClass.h"
#include"List.h"
using namespace std;

//The kinds of roof a stadium can have.
enum	roof_type{
	OPEN,
	DOMED,
	RETRACTABLE
};

//Models an NFL stadium.
class NFL_Stadium
{
	public:
	   /*******************************************
	    * * * * CONSTRUCTORS AND DESTRUCTOR * * * *
	    *******************************************/
		//Default Constructor
		NFL_Stadium();

		//Constructor with instantiation options.
		NFL_Stadium(roof_type r_type,
				    string name,
				    unsigned int cap,
				    Date	opening);

		//Destructor
		~NFL_Stadium();


	   /*******************************************
		* * * *          ACCESSORS          * * * *
		*******************************************/
		//Returns the stadium's name.
		const string& get_stadium_name() const;

		//Returns the stadium's roof type.
		roof_type get_roof() const;

		//Returns the stadium's capacity.
		long get_capacity() const;

		//Returns a list of the stadium's teams.
		const List<Team>& return_teams() const;

		//Returns the stadium's opening date.
		Date get_opening_date()	const;

		//Sets the stadium's location
		string get_location()	const;

		//Returns true if at least one of the teams that plays at the
		//stadium competes in the AFC.
		bool is_in_AFC() const;

		//Returns true if at least one of the teams that plays at the
		//stadium competes in the NFC.
		bool is_in_NFC() const;

		//Returns a formatted string used to save the stadium's information
		//to a text file.
		string save() const;

		//Returns a string with the stadium's information which has been
		//formatted for printing to the console.
		string print() const;

		//Comparator for stadiums.
		bool operator!=(const NFL_Stadium& compareTo) const;
		bool operator==(const NFL_Stadium& compareTo) const;


	   /*******************************************
		* * * *          MUTATORS           * * * *
		*******************************************/
		//Sets the stadium's name.
		void set_stadium_name(string s_name);

		//Adds a team to play at the stadium.
		void add_team(const Team& newTeam);

		//Removes a team that plays at the stadium.
		void remove_team(List<Team>::Iterator toRemove);

		//Sets the stadium's roof type.
		void set_roof(roof_type r_type);

		//Sets the stadium's capacity.
		void set_capacity(long cap);

		//Sets the stadium's opening date.
		void set_opening_date(Date opening);

		//Sets the stadium's location
		void set_location(string newlocation);

	private:
		string       stadium_name;//Stadium's name.
		string		 location;	  //Stores Airport Code for Stadium
		List<Team>   teamList;    //List of teams that play at the stadium.
		roof_type    roof;        //Stadium's roof type.
		long         capacity;    //Stadium's capacity.
		Date		 opening_date;//Stadium's opening date.

};

#endif /* NFL_STADIUM_H_ */
