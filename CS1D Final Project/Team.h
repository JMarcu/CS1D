/*************************************************************************
 * CS1D Final Project
 * -----------------------------------------------------------------------
 * AUTHORS     : James Marcu & Phillip Doyle
 * STUDENT IDs : 374443      & 911579
 * CLASS       : CS1D
 * SECTION     : TTh 3:30 AM
 * DUE DATE    : 12/9/2014
 *************************************************************************/
#ifndef TEAM_H_
#define TEAM_H_

#include <string>
using namespace std;

//Conferences in the NFL.
enum conference{
	AFC,
	NFC
};

//Models an NFL team.
class Team
{
	public:
	   /*******************************************
	    * * * * CONSTRUCTORS AND DESTRUCTOR * * * *
	    *******************************************/
		//Default Constructor
		Team()
		{conferenceType = AFC;}

		//Constructor using provided values.
		Team(string nameInit, conference confInit)
		{name = nameInit; conferenceType = confInit;}


	   /*******************************************
		* * * *          ACCESSORS          * * * *
		*******************************************/
		//Returns the team's name.
		string GetName() const
		{return name;}

		//Returns the team's conference.
		conference GetConference() const
		{return conferenceType;}


	   /*******************************************
		* * * *          MUTATORS           * * * *
		*******************************************/
		//Sets the teams name.
		void SetName(string newName)
		{name = newName;}

		//Sets the teams conference.
		void SetConference(conference newConf)
		{conferenceType = newConf;}

	private:
		string     name;          //The team's name.
		conference conferenceType;//The team's conference.
};

#endif /* TEAM_H_ */
