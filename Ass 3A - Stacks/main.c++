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
 * Stack Reversing Program - Assignment 3.A: Stacks
 * _______________________________________________________________________
 * 	 This program reads in information from user provided files onto a
 * 	 stack. It accepts string, int, or double datatypes from the files and
 * 	 can decide which kind of data it is working with at runtime. The
 * 	 stacks are then output to the user through the console, reversed, then
 * 	 output again. The user may do this for as many files as they wish.
 * _______________________________________________________________________
 * INPUT
 *      filename : The name of the file to read information from. The
 *                 file extension must be included.
 *
 * OUTPUT
 * 		The contents of the file will be output to the user in original
 * 		and reverse order.
 *************************************************************************/
int main()
{
	/*********************************************************************
	 * CONSTANTS
	 * -------------------------------------------------------------------
	 * USED FOR OUTPUT
	 * -------------------------------------------------------------------
	 * 		MAIN_PROMPT     : Output once at the start of the program
	 * 		                  to let the user know what this program does.
	 * 		FILENAME_PROMPT : Output to the user when asking for a file to
	 * 		                  read data from.
	 * 		EXIT_MESSAGE    : Displayed to user on program termination.
	 *
	 * -------------------------------------------------------------------
	 * USED FOR FORMATTING
	 * -------------------------------------------------------------------
	 * 		LINE_LENGTH : The length of the line to print out when
	 * 		              printing to the console.
	 *********************************************************************/
	//USED FOR OUTPUT
	const string MAIN_PROMPT     = "This program will read in data from "
			                       "a file into a stack then output it to "
			                       "you. Because it was read into a stack "
			                       "the first output will be in reverse "
			                       "order from the file. The program will "
			                       "then reverse the stack and output the "
			                       "data to you again. This will be in "
			                       "same order as the original file, and "
			                       "in the reverse order of the first "
			                       "time it was output to you. You may "
			                       "continue entering files for the "
			                       "as long as you wish.\n\n";
	const string FILENAME_PROMPT = "Please enter the name of the file "
			                       "you would like to read from "
			                       "(exit to quit): ";
	const string EXIT_MESSAGE    = "Program has closed. Thank you for "
			                       "using this program.";

	//USED FOR FORMATTING
	const int LINE_LENGTH = 80;

	//VARIABLE DECLERATIONS
	string   filename;     //IN   - The name of the file the user wants to
	                       //       read input from.
	ifstream inFile;       //IN   - The file stream to read input from.
	bool     cont;         //PROC - Used to control the main loop. True
	                       //       until the user wishes to exit the
	                       //       program.
	DATATYPE inputDatatype;//PROC - The type of data in the input file.

	//VARIABLE INITIALIZATIONS
	cont = true;

	/*********************************************************************
	 * OUT - The class header and the main prompt are output to the
	 *       console.
	 *********************************************************************/
	ClassHeader("James Marcu", "374443", "CS1D - Data Structures",
			    "TTH 3:30 PM", 'A', 3, "Stacks", cout);
	cout << WordWrap(MAIN_PROMPT, LINE_LENGTH);

	/*********************************************************************
	 * IN - The user is asked for the name of the file to input from. If
	 *      they enter 'exit' the program will end. If they enter a file
	 *      then it will attempt to open that file.
	 *********************************************************************/
	filename = GetInput(FILENAME_PROMPT, cin, cout);
	if(filename == "exit")
	{
		cont = false;
	}
	else
	{
		inFile.open(filename.c_str());
	}

	/*********************************************************************
	 * PROC - This is the main loop. It will run until the user exits.
	 *        Each iteration uses the data inside an input file to create,
	 *        print, reverse, and print again a stack.
	 *********************************************************************/
	while(cont)
	{
		/*****************************************************************
		 * PROC - Determines the datatype of the file's data and stores it.
		 *****************************************************************/
		inputDatatype = DetermineDatatype(inFile);

		/*****************************************************************
		 * PROC - Calls StackProcessing with the right datatype, as
		 *        determined above. This function will create a stack from
		 *        the file's data, print it to the console, reverse it,
		 *        print it again, and then delete the stack.
		 *****************************************************************/
		if (inputDatatype == STRING)
		{
			StackProcessing<string> (inFile);
		}
		else if (inputDatatype == INTEGER)
		{
			StackProcessing<int> (inFile);
		}
		else
		{
			StackProcessing<double> (inFile);
		}

		//Closes the file stream and clears its flags.
		inFile.close();
		inFile.clear();

		/*****************************************************************
		 * IN - The user is asked for the name of the file to input from.
		 *      If they enter 'exit' the program will end. If they enter a
		 *      file then it will attempt to open that file.
		 *****************************************************************/
		filename = GetInput(FILENAME_PROMPT, cin, cout);
		if(filename == "exit")
		{
			cont = false;
		}
		else
		{
			inFile.open(filename.c_str());
		}
	}

	cout << WordWrap(EXIT_MESSAGE, LINE_LENGTH);

	return 0;
}



