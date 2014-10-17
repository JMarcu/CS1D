/*************************************************************************
 * AUTHOR      : James Marcu
 * STUDENT ID  : 374443
 * ASS #4      : Queues and DeQueues
 * CLASS       : CS1D
 * SECTION     : TTh 3:30 AM
 * DUE DATE    : 9/16/2014
 *************************************************************************/

#ifndef HEADER_H_
#define HEADER_H_

/******************************
 * PRE-PROCESSOR DIRECTIVES
 ******************************/
#include <iostream>
#include <iomanip>
#include "Queue.h"
using namespace std;

/******************************
 * FUNCTION PROTOTYPES
 ******************************/

/*************************************************************************
 * FUNCTION OutputSize
 *   This function is a driver for the class Queue's method function
 *   size(). It will output the result to the console.
 *************************************************************************/
void OutputSize(const Queue& queue);//IN - The queue to run size() from.

/*************************************************************************
 * FUNCTION OutputEmpty
 *   This function is a driver for the class Queue's method function
 *   empty(). It will output the result to the console.
 *************************************************************************/
void OutputEmpty(const Queue& queue);//IN - The queue to run empty() from.

/*************************************************************************
 * FUNCTION OutputFront
 *   This function is a driver for the class Queue's method function
 *   front(). It will output the result to the console. If an exception
 *   is thrown the exceptions message will be output instead.
 *************************************************************************/
void OutputFront(const Queue& queue);//IN - The queue to run front() from.

/*************************************************************************
 * FUNCTION OutputEnqueue
 *   This function is a driver for the class Queue's method function
 *   enqueue(). It will output the result to the console.
 *************************************************************************/
void OutputEnqueue(Queue& queue,     //IN - The queue to run enqueue() from.
		           string toEnqueue);//IN - The data to be in the new node.

/*************************************************************************
 * FUNCTION OutputDequeue
 *   This function is a driver for the class Queue's method function
 *   dequeue(). It will output the result to the console. If an exception
 *   is thrown then the exception's message will be output instead.
 *************************************************************************/
void OutputDequeue(Queue& queue);//IN - The queue to run dequeue() from.

/*************************************************************************
 * FUNCTION ClassHeader
 * 	 This function takes in the programmer's name(s), the class name, and
 *	 the class section. The next argument is assignment type (assType)
 *	 which may be an 'L', or any other character (typically an 'A'). If it
 *	 is set to 'L' then the header will use the word "LAB", else it will
 *	 use the word "ASSIGNMENT" when describing the program. The parameter
 *	 assType is not case sensitive. The parameters assNum and assName
 *	 accept the name of the assignment's name and number. The function will
 *	 output a class heading based on the provided information.
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
