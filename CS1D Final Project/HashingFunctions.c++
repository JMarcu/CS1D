/*************************************************************************
 * CS1D Final Project
 * -----------------------------------------------------------------------
 * AUTHORS     : James Marcu & Phillip Doyle
 * STUDENT IDs : 374443      & 911579
 * CLASS       : CS1D
 * SECTION     : TTh 3:30 PM
 * DUE DATE    : 12/9/2014
 *************************************************************************/

#include "header.h"

/*************************************************************************
 * FUNCTION StringHashOne
 * _______________________________________________________________________
 * This function hashes a string into an integer between 0 and 67,
 * inclusive of zero. It uses a polynomial hashing algorithm to generate
 * an integer which is then compressed through a modulo operator.
 * _______________________________________________________________________
 * PRE-CONDITIONS -
 * 	key : The string to hash.
 *
 * POST-CONDITIONS -
 * 	Will return an integer between 0 and 67, inclusive of zero.
 *************************************************************************/
int StringHashOne(const string& key)//IN - The key to hash.
{
	const int POLYNOMIAL_CONSTANT = 33;//PROC - The polynomial constant
	                                   //       used for hashing.

	//VARIABLE DECLERATIONS
	string::const_iterator hashIt;//PROC - Used to iterate through the key.
	unsigned int     degreeOfTerm;//PROC - Degree of the current polynomial
	                              //       term during hashing.
	unsigned int     hashValue;   //PROC - Current value of the hashed
	                              //       key.

	//VARIABLE INITIALIZATIONS
	hashIt       = key.begin();
	degreeOfTerm = 1;
	hashValue    = 0;

	/*********************************************************************
	 * PROC - The string is hashed to an integer using the formula
	 *        hash = a1*c + a2*c^2 + a3*c^3 +...+an*c^n where an is the
	 *        nth character of the string and c is the polynomial constant.
	 *********************************************************************/
	while(hashIt != key.end())
	{
		hashValue += unsigned(int(*hashIt) * pow(POLYNOMIAL_CONSTANT, degreeOfTerm));
		++hashIt;
		++degreeOfTerm;
	}

	/*********************************************************************
	 * PROC & OUT - The function returns the integer generated above
	 *              modulo 67 to generate an integer in the range 0-67,
	 *              inclusive of zero.
	 *********************************************************************/
	return abs(int(hashValue) % 67);
}

/*************************************************************************
 * FUNCTION StringHashTwo
 * _______________________________________________________________________
 * This function hashes a string into an integer between 0 and 13,
 * inclusive. It uses a polynomial hashing algorithm to generate
 * an integer which is then compressed.
 * _______________________________________________________________________
 * PRE-CONDITIONS -
 * 	key : The string to hash.
 *
 * POST-CONDITIONS -
 * 	Will return an integer between 0 and 13, inclusive.
 *************************************************************************/
int StringHashTwo(const string& key)//IN - The key to hash.
{
	const int POLYNOMIAL_CONSTANT = 33;//PROC - The polynomial constant
	                                   //       used for hashing.

	//VARIABLE DECLERATIONS
	string::const_iterator hashIt;//PROC - Used to iterate through the key.
	unsigned int     degreeOfTerm;//PROC - Degree of the current polynomial
	                              //       term during hashing.
	unsigned int     hashValue;   //PROC - Current value of the hashed
	                              //       key.

	//VARIABLE INITIALIZATIONS
	hashIt       = key.begin();
	degreeOfTerm = 1;
	hashValue    = 0;

	/*********************************************************************
	 * PROC - The string is hashed to an integer using the formula
	 *        hash = a1*c + a2*c^2 + a3*c^3 +...+an*c^n where an is the
	 *        nth character of the string and c is the polynomial constant.
	 *********************************************************************/
	while(hashIt != key.end())
	{
		hashValue += unsigned(int(*hashIt) * pow(POLYNOMIAL_CONSTANT, degreeOfTerm));
		++hashIt;
		++degreeOfTerm;
	}

	/*********************************************************************
	 * PROC & OUT - The function returns the integer generated above
	 *              modulo 13 to generate an integer in the range 0-13,
	 *              then subtracts that from 13 to generate the final
	 *              integer.
	 *********************************************************************/
	return abs(13 - (int(hashValue) % 13));
}

