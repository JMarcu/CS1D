/*************************************************************************
 * AUTHOR      : James Marcu
 * STUDENT ID  : 374443
 * ASS #      : 
 * CLASS       : CS1D
 * SECTION     : TTh 3:30 AM
 * DUE DATE    : 
 *************************************************************************/
#include "header.h"
using namespace std;

/*************************************************************************
 * Assignment 8: Double Hashing
 * _______________________________________________________________________
 * This program tests the implementation of a Map. The map was created by
 * wrapping a hash table. The hash table uses a double hashing algorithm.
 *
 * A series of key/value pairs are added and erased from the map. The map
 * is then printed to the console for inspection. All entries are then
 * manually deleted and the map is printed out one final time to ensure
 * proper deletion.
 * _______________________________________________________________________
 * INPUT -
 * 	<none> All input is hard coded.
 *
 * OUTPUT -
 * 	A series of console messages will be output showing the results of
 * 	the Put() and Erase() calls on the map.
 *************************************************************************/
int main()
{
	/*********************************************************************
	 * CONSTANTS
	 * -------------------------------------------------------------------
	 * USED FOR OUTPUT
	 * -------------------------------------------------------------------
	 * MAIN_PROMPT  : Outputs to the user on program start.
	 * EXIT_MESSAGE : Outputs to the user on program termination.
	 *
	 * -------------------------------------------------------------------
	 * USED FOR FORMATTING
	 * -------------------------------------------------------------------
	 * LINE_LENGTH : Length of output lines. Used for word wrapping.
	 *********************************************************************/
	//USED FOR OUTPUT
	const string MAIN_PROMPT  = "This program serves to test the "
			                    "implementation of a map. A series of "
			                    "key/value pairs are being added to it, and "
			                    "the final result will be output. Then all "
			                    "keys will be deleted and the map will be "
			                    "output one last time.\n\n";
	const string EXIT_MESSAGE = "Program has finished and will now exit.";

	//USED FOR FORMATTING
	const int    LINE_LENGTH  = 80;


	//VARIABLE DECLERATIONS
	Map<int, string> testMap;//PROC & OUT - The instance of the map which
	                         //             this program will use to test
	                         //             the classe's implementation.

	/*********************************************************************
	 * OUTPUT - The class header is output to the top of the console,
	 *          followed by the program's main prompt which will give
	 *          the user instructions on what the program does.
	 *********************************************************************/
	ClassHeader("James Marcu", "374443", "CS1D", "TTh 3:30 PM",
			    'A', 8, "Double Hashing", cout);
	cout << WordWrap(MAIN_PROMPT, 80);

	/*********************************************************************
	 * PROC - A series of key/value pairs will now be added to and removed
	 *        from the map. The keys are all integer literals and the
	 *        values all string literals.
	 *********************************************************************/
	testMap.Put(18, "Laguna Niguel");
	testMap.Put(41, "Mission Viejo");
	testMap.Put(22, "Lake Forest");
	testMap.Put(44, "Irvine");
	testMap.Erase(18);

	testMap.Put(59, "San Clemente");
	testMap.Put(32, "San Diego");
	testMap.Put(49, "Anaheim");
	testMap.Erase(22);

	testMap.Put(73, "Los Angeles");
	testMap.Put(17, "Orange");
	testMap.Put(77, "Palms Springs");
	testMap.Put(26, "Riverside");
	testMap.Erase(49);

	testMap.Put(19, "Brea");
	testMap.Put(60, "Santa Ana");
	testMap.Put(35, "Tustin");
	testMap.Put(52, "Oceanside");
	testMap.Put(11, "La Jolla");
	testMap.Put(18, "Del Mar");
	testMap.Put(22, "Aliso Viejo");
	testMap.Put(49, "Laguna Beach");

	/*********************************************************************
	 * OUT - The map will be printed out to the console for inspection.
	 *********************************************************************/
	cout << "This is the map after all additions and erasures: " << endl;
	cout << WordWrap(testMap.Print(), LINE_LENGTH) << endl << endl;

	/*********************************************************************
	 * PROC - All remaining entries in the map will now be manually erased.
	 *********************************************************************/
	testMap.Erase(41);
	testMap.Erase(44);
	testMap.Erase(59);
	testMap.Erase(32);
	testMap.Erase(73);
	testMap.Erase(17);
	testMap.Erase(77);
	testMap.Erase(26);
	testMap.Erase(19);
	testMap.Erase(60);
	testMap.Erase(35);
	testMap.Erase(52);
	testMap.Erase(11);
	testMap.Erase(18);
	testMap.Erase(22);
	testMap.Erase(49);

	/*********************************************************************
	 * OUT - The (assumedly) empty map will be output to the console to
	 *       ensure successful deletion. Then the exit message will be
	 *       output.
	 *********************************************************************/
	cout << "This is the map after all remaining entries were manually "
		 << "removed: " << endl
	     << WordWrap(testMap.Print(), LINE_LENGTH) << endl << endl
	     << WordWrap(EXIT_MESSAGE, LINE_LENGTH);

	return 0;
}


