/*************************************************************************
 * CS1D Final Project
 * -----------------------------------------------------------------------
 * AUTHORS     : James Marcu & Phillip Doyle
 * STUDENT IDs : 374443      & 911579
 * CLASS       : CS1D
 * SECTION     : TTh 3:30 PM
 * DUE DATE    : 12/9/2014
 *************************************************************************/
#ifndef DATECLASS_H_
#define DATECLASS_H_

#include <string>
#include <iostream>
using namespace std;

//Months of the year
enum Months{
			JAN = 1,
			FEB,
			MARCH,
			APR,
			MAY,
			JUN,
			JUL,
			AUG,
			SEP,
			OCT,
			NOV,
			DEC
};

//CLASS: Class storing a date
class	Date{
		public:
			Date();
			Date(Months newMonth, int newDay, int newYear);

			~Date();

			//set Members - Used to Change the private data members
			void	setDay(int newDay);
			void	setYear(int newYear);
			void	setMonth(Months newMonth);
			void	setDate(Months newMonth, int newDay, int newYear);

			//get Members	Used to access the private data members
			int		getDay()	const; //Returns the day.
			int		getYear()	const; //Returns the year.
			Months	getMonth()	const; //Returns the month.
			string	printDate() const; //Returns string with date

			//Overloads == operator to check if dates are the same
			bool operator == (Date compareTo) const;
			bool operator > (Date compareTo) const;
			bool operator < (Date compareTo) const;
			bool operator <= (Date compareTo) const;
			bool operator >= (Date compareTo) const;

		private:
			 int		day;
			 Months		month;
			 int		year;
};


#endif /* DATECLASS_H_ */
