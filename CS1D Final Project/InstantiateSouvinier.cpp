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
 * FUNCTION InstantiateSouvenir
 * -----------------------------------------------------------------------
 * This function will read in one block of input from an input file and
 * use it to create a new instance of the Souvenir object. This object is
 * then returned by reference.
 * -----------------------------------------------------------------------
 * PRE-CONDITIONS -
 * 	inStream : The open file stream to take input from.
 *
 * POST-CONDITIONS -
 * 	Souvenir : This points to the Souvenir object which is being created.
 * 	           The reference, not the pointer itself, is returned at the
 * 	           end.
 *************************************************************************/
Souvenir* InstantiateSouvenir(ifstream& inStream)//IN & OUT - The input
                                                 //           stream.
{
	//VARIABLE DECLERATIONS
	Souvenir*	 souvenir;//OUT  - Used to create new souvenir objects.
	string		 name;    //PROC - Stores the souvenir's name.
	char		 junk;	  //PROC - Used to get rid of junk $ char
	float		 price;   //PROC - Stores the souvenir's price.

	//Read in the values from the file.
	getline(inStream, name);
	inStream.get(junk);
	inStream >> price;
	inStream.ignore(1000, '\n');

	//Create the new souvenir object.
	souvenir = new Souvenir(name, price);

	return souvenir;

}


