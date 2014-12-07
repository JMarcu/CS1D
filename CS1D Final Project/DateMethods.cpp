/*************************************************************************
 * CS1D Final Project
 * -----------------------------------------------------------------------
 * AUTHORS     : James Marcu & Phillip Doyle
 * STUDENT IDs : 374443      & 911579
 * CLASS       : CS1D
 * SECTION     : TTh 3:30 AM
 * DUE DATE    : 12/9/2014
 *************************************************************************/
#include"DateClass.h"
#include "header.h"

	//CONSTRUCTOR
	Date::	Date()
		{
		day = 1;
		month = JAN;
		year = 0;
		}

	Date::	Date(Months newMonth, int newDay, int newYear)
		{
		day = newDay;
		month = newMonth;
		year = newYear;
		}

	//DESTRUCTOR
	Date::	~Date()
		{
		}

	//SET-MEMBERS: Members that allow the client to change private data values
	void	Date::setDay(int newDay)
		{
			day = newDay;
		}

	void	Date::setYear(int newYear)
		{
			year = newYear;
		}

	void	Date::setMonth(Months newMonth)
		{
			month = newMonth;
		}


	void	Date::setDate(Months newMonth, int newDay, int newYear)
	{
		day = newDay;
		month = newMonth;
		year = newYear;
	}

	//GET MEMBERS: Allow client to access private data values

	int		Date::getDay()	const
		{
		return day;
		}

	int		Date::getYear()	const
		{
			return year;
		}

	Months	Date::getMonth()	const
		{
			return month;
		}
//OPERATOR-OVERLOAD: Overloads of comparison operators
//					 to compare two dates
	bool Date::operator == (Date compareTo) const
		{
			return (day == compareTo.day && month == compareTo.month &&
					year == compareTo.year);
		}


	bool Date::operator > (Date compareTo) const
	{
		return ((day > compareTo.day)
				&& (month > compareTo.month)
				&& (year > compareTo.year));
	}

	bool Date::operator < (Date compareTo) const
	{
		return ((day < compareTo.day)
						&& (month < compareTo.month)
						&& (year < compareTo.year));
	}
	bool Date::operator <= (Date compareTo) const
		{
			if(year < compareTo.getYear())
			{
				return true;
			}
			else if (year > compareTo.getYear())
			{
				return false;
			}
			else
			{
				if(month < compareTo.getMonth())
				{
					return true;
				}
				else if (month > compareTo.getMonth())
				{
					return false;
				}
				else
				{
					if(day <= compareTo.getDay())
					{
						return true;
					}
					else
					{
						return false;
					}
				}
			}
		}
	bool Date::operator >= (Date compareTo) const
		{
		return ((day >=  compareTo.day)
								&& (month >=  compareTo.month)
								&& (year >=  compareTo.year));
		}



/*************************************************************************
 * FUNCTION PrintData
 * _______________________________________________________________________
 *	This method outputs the date in a formatted style
 * _______________________________________________________________________
 * PRE-CONDITIONS
 * 		none
 * POST-CONDTIONS
 * 		This function will output the date
 ************************************************************************/
	string Date::printDate() const
	{
		std::ostringstream output;


		if( month < 10)
		{
			output << '0';
		}
		output << month;

		output << '/';

		if( day < 10)
		{
			output << '0';
		}
		output << day;

		output << '/';

		output << year;

		return output.str();
	}

