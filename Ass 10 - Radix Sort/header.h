/*************************************************************************
 * AUTHOR      : James Marcu
 * STUDENT ID  : 374443
 * ASS #10B    : Radix Sorting
 * CLASS       : CS1D
 * SECTION     : TTh 3:30 AM
 * DUE DATE    : 11/4/2014
 *************************************************************************/
#ifndef HEADER_H_
#define HEADER_H_

#include <string>
#include <iostream>
#include <iomanip>
#include <queue>
using namespace std;

/*************************************************************************
 * FUNCTION LetterToInt
 * Converts a character to an int representing its position in the
 * alphabet.
 *************************************************************************/
int LetterToInt(char letter);

/*************************************************************************
 * FUNCTION Radix
 * This sorts an array of strings using a radix sort.
 *************************************************************************/
void Radix(string* arr, int size, int tuple, int currentTuple = -1);

/*************************************************************************
 * FUNCTION ClassHeader
 * 	 This function takes in the programmer's name(s), the class name, and
 *	 the class section. The next argument is assignment type (assType)
 *	 which may be an 'L', or any other character (typically an 'A'). If it
 *	 is set to 'L' then the header will use the word "LAB", else it will
 *	 use the word "ASSIGNMENT" when describing the program. The parameter
 *	 assType is not case sensitive. The parameters assNum and assName
 *	 accept the name of the assignment's name and number. The function will
 *	 output a class heading based on the provided information
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
				  ostream& outStream);//IN       - The stream to output to.

#endif /* HEADER_H_ */
