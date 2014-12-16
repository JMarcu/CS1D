/*************************************************************************
 * AUTHOR       : James Marcu
 * STUDENT ID   : 374443
 * EXTRA CREDIT : Huffman Coding
 * CLASS        : CS1D
 * SECTION      : TTh 3:30 AM
 * DUE DATE     : 12/15/14
 *************************************************************************/

#include "header.h"

/*************************************************************************
 * FUNCTION ClassHeader
 * _______________________________________________________________________
 * 	 This function takes in the programmer's name(s), the class name, and
 *	 the class section. The next argument is assignment type (assType)
 *	 which may be an 'L', or any other character (typically an 'A'). If it
 *	 is set to 'L' then the header will use the word "LAB", else it will
 *	 use the word "ASSIGNMENT" when describing the program. The parameter
 *	 assType is not case sensitive. The parameters assNum and assName
 *	 accept the name of the assignment's name and number. The function will
 *	 output a class heading based on the provided information
 * _______________________________________________________________________
 * PRE-CONDITIONS
 * 		programmer     : The programmer's name.
 * 		id             : The programmer's student id. This is passed as a
 * 		                 string so that if there is more than one
 * 		                 programmer they can all enter their ids.
 * 		className      : The class name.
 * 		section        : The programmer's section of the class.
 * 		assType        : 'L' formats the output for a LAB and anything else
 * 		                 formats it for an ASSIGMENT.
 * 		assName        : The assignment's name.
 * 		outStream      : The output stream that this will output into.
 *
 * POST-CONDITIONS
 * 		This function will output a class heading using the above input.
 *************************************************************************/
void ClassHeader (string   programmer,//IN & OUT - Programmer's name(s)
				  string   id,        //IN & OUT - Programmer's student
				                      //           id(s)
				  string   className, //IN & OUT - Name of the class this
				                      //           lab/assignment is for.
				  string   section,   //IN & OUT - Section of the class the
					                  //           author is enrolled in
				  char     assType,   //IN & OUT - A character which lets
				                      //           the function know if
					                  //           this is a lab or an
				                      //           assignment.
			      int      assNum,    //IN & OUT - The number of the lab or
					                  //           assignment.
				  string   assName,   //IN & OUT - The name of the lab or
                                      //           assignment.
				  ostream& outStream) //IN       - The stream to output to.
{
	outStream << left;
	outStream << "******************************************************";
	outStream << "\n*   PROGRAMMED BY : " << programmer;
	outStream << "\n*   " << setw(14) << "STUDENT ID" << ": " << id;
	outStream << "\n*   " << setw(14) << "CLASS" << ": " << className;
	outStream << "\n*   " << setw(14) << "SECTION" << ": " << section;
	if (toupper(assType) == 'L')
	{
		outStream << "\n*   LAB #" << setw(9)
			      << assNum << ": " << assName;
	}
	else
	{
		outStream << "\n*   ASSIGNMENT #" << setw(2)
				  << assNum << ": " << assName;
	}
	outStream << "\n******************************************************"
			  << "\n\n";
	outStream << right;
}
