/*************************************************************************
 * AUTHOR      : James Marcu
 * STUDENT ID  : 374443
 * ASS #1      : Linked Lists & Queues
 * CLASS       : CS1D
 * SECTION     : TTh 1:00 PM
 * DUE DATE    : 8/26/2014
 *************************************************************************/

#ifndef HEADER_H_
#define HEADER_H_

/****************************
 * PRE-PROCESSOR DIRECTIVES
 ****************************/
#include <iomanip>
#include "Queue.h"
using namespace std;


/****************************
 * GLOBAL CONSTANTS
 ****************************/
//USED FOR FORMATTING
const int OUT_WIDTH = 80;//The margin the output should fit into.


/****************************
 * FUNCTION PROTOTYPES
 ****************************/

/*************************************************************************
 * FUNCTION GetInput
 * 	 This function gathers string input from the user. It will continue
 * 	 to output a prompt and request input until the user enters the string
 * 	 specified by exitStr as their input. The inputs will be stored in a
 * 	 queue which is returned when the function ends.
 *************************************************************************/
Queue<string>* GetInput(string   prompt,    //OUT  - Will be output to the
		                                    //       user when asking for
		                                    //       input.
		                string   exitStr,   //OUT  - When the user enters
		                                    //       this requests for
		                                    //       input will stop.
		                ostream& outStream, //PROC - Stream to output to.
		                istream& inStream); //PROC - Stream to input from.

/*************************************************************************
 * FUNCTION CleanString
 * 	 This function will read in a string and return a version of that
 * 	 string which has been stripped of all punctuation, symbols and
 * 	 whitespace. It will also be shifted into lowercase. The returned
 * 	 string will only contain lowercase letters.
 *************************************************************************/
string CleanString (string toClean);//IN - The string to clean.

/*************************************************************************
 * FUNCTION IsPalindrome
 * 	 This function determines whether or not a string is a palindrome
 * 	 (a palindrome is the same backwards and forwards). It does not
 * 	 itself disregard whitespace or punctuation; you must get rid of
 * 	 characters you do not want considered before calling this function.
 * 	 This function is case sensitive. The function will return true
 * 	 if the string is a palindrome, false if it is not.
 *************************************************************************/
bool IsPalindrome(string toCheck);//IN - The string to check for if its
                                  //     a palindrome.

/*************************************************************************
 * FUNCTION OutputPalindrome
 * 	 This is an output function for a program designed to tell whether
 * 	 or not a word or phrase is a palindrome. The word or phrase is passed
 * 	 in as a string and a bool is passed in for whether or not it is a
 * 	 palindrome. The function will output a message to the user telling
 * 	 them whether or not that phrase is a palindrome.
 *************************************************************************/
void OutputPalindrome (string word,       //OUT  - The string which may or
		                                  //       may not be a palindrome.
		               bool   palindrome);//PROC - True if word is a
                                          //       palindrome. False
                                          //       otherwise.

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

/*************************************************************************
 * FUNCTION WordWrap
 *   This will read in a string and a margin to fit that string into. It
 *   will parse through the string and create a version of it with new
 *   line characters before words that don't fit in the margins. This new
 *   string is returned to be output.
 *************************************************************************/
string WordWrap(string toWrap,     //IN - The string to be word wrapped.
		        int    lineLength);//IN - The width of the line to fit
                                   //     your string into.

#endif /* HEADER_H_ */
