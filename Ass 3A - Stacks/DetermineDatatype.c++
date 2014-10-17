/*************************************************************************
 * AUTHOR      : James Marcu
 * STUDENT ID  : 374443
 * ASS #3      : Stacks
 * CLASS       : CS1D
 * SECTION     : TTh 3:30 AM
 * DUE DATE    : 9/2/2014
 *************************************************************************/

#include "header.h"

/*************************************************************************
 * FUNCTION DetermineDatatype
 * _______________________________________________________________________
 * 	 This function determines the datatype of a file: string, double, or
 * 	 int. There are several assumptions made. First is that the file is
 * 	 formatted such that each entry is separated by a comma, NOT a newline
 * 	 character. Second, it doesn't handle numbers which use commas (or
 * 	 periods in the European fashion). Third, it assumes that all entries
 * 	 in the file are of the same datatype, so it only checks the first.
 * 	 It will return a value of the enumerated type DATATYPE which
 * 	 corresponds with the datatype of the file.
 * _______________________________________________________________________
 * PRE-CONDITIONS
 * 		inFileStream : An open filestream to check the datatype of.
 * 		File Formatting: 1) Entries seperated by commas.
 * 		                 2) Numbers with mulitple periods ('.')
 * 		                    will be read as strings.
 * 		                 3) The datatype of all entries can be interpreted
 * 		                    as the same datatype.
 *
 * POST-CONDITIONS
 * 		typeOfData  : Will be returned as STRING, INTEGER, or DOUBLE
 * 		              depending on the file's type of data.
 *************************************************************************/
DATATYPE DetermineDatatype(ifstream& inFileStream)//IN - Input stream to
                                                  //     determine the
                                                  //     datatype in.
{
	//VARIABLE DECLERATIONS
	string   data;          //IN & PROC - Stores the first data point from
	                        //            the file.
	int      streamPosition;//PROC - Used to move the stream position back
	                        //       to the beginning after the function
	                        //       has done its work.
	bool     isNumber;      //PROC - Used to keep track of if the data
	                        //       point is a number. This counts both
	                        //       int and double datatypes.
	bool     isDouble;      //PROC - Used to keep track of if the data
	                        //       point is a double.
	string::iterator it;    //PROC - Used to move through the data point,
	                        //       which regardless of type is always
	                        //       read into this function as a string.
	DATATYPE typeOfData;    //OUT  - Is returned with the datatype of the
	                        //       file.

	//VARIABLE INITIALIZATIONS
	isNumber = true;
	isDouble = false;
	streamPosition = inFileStream.tellg();//Set to the current position in
	                                      //the stream. The stream will be
	                                      //returned here after the
	                                      //function is done.

	/*********************************************************************
	 * INPUT - The first datapoint from the file stream is read in and the
	 *         iterator is pointed at its first element.
	 *********************************************************************/
	getline(inFileStream, data, ',');
	it = data.begin();

	/*********************************************************************
	 * PROC - The main loop will move the iterator over each element of
	 *        the data point. It will stop either when it reaches the
	 *        end or when it is conclusive that the data is of type string.
	 *********************************************************************/
	while (it != data.end() && isNumber)
	{
		/*****************************************************************
		 * PROC - First it checks if this character is a number. The ASCII
		 *        values 48-57 correspond to the digits 0-9.
		 *****************************************************************/
		if (*it < 48 || *it > 57)
		{
			/*************************************************************
			 * PROC - If it isn't a number it checks if the character is
			 *        a decimal point. It also checks that this is the
			 *        first decimal point in the string (if it wasn't then
			 *        isDouble would already be set to true). If the
			 *        character is not a decimal point or is the second
			 *        decimal point encountered then isNumber and isDouble
			 *        are both set to false.
			 *************************************************************/
			if (*it == 46 && isDouble == false)
			{
				isDouble = true;
			}
			else
			{
				isNumber = false;
				isDouble = false;
			}
		}

		//Increments the iterator.
		it++;
	}

	/*********************************************************************
	 * PROC - This determines the datatype and sets the return value.
	 *********************************************************************/
	if (isNumber)
	{
		if (isDouble)
		{
			typeOfData = DOUBLE;
		}
		else
		{
			typeOfData = INTEGER;
		}
	}
	else
	{
		typeOfData = STRING;
	}

	//Returns the stream position to where it was initially
	inFileStream.seekg(streamPosition, ios_base::beg);

	return typeOfData;
}
