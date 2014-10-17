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

int main()
{
	Map<int, string> asdf;

	asdf.Put(18, "Laguna Niguel");
	asdf.Put(41, "Mission Viejo");
	asdf.Put(22, "Lake Forest");
	asdf.Put(44, "Irvine");
	asdf.Erase(18);

	asdf.Put(59, "San Clemente");
	asdf.Put(32, "San Diego");
	asdf.Put(49, "Anaheim");
	asdf.Erase(22);

	asdf.Put(73, "Los Angeles");
	asdf.Put(17, "Orange");
	asdf.Put(77, "Palms Springs");
	asdf.Put(26, "Riverside");
	asdf.Erase(49);

	asdf.Put(19, "Brea");
	cout << WordWrap(asdf.Print(), 80) << endl << endl;
	asdf.Put(60, "Santa Ana");
	cout << WordWrap(asdf.Print(), 80) << endl << endl;
	asdf.Put(35, "Tustin");
	cout << WordWrap(asdf.Print(), 80) << endl << endl;
	asdf.Put(52, "Oceanside");
	cout << WordWrap(asdf.Print(), 80) << endl << endl;
	asdf.Put(11, "La Jolla");
	cout << WordWrap(asdf.Print(), 80) << endl << endl;
	asdf.Put(18, "Del Mar");
	cout << WordWrap(asdf.Print(), 80) << endl << endl;
	asdf.Put(22, "Aliso Viejo");
	cout << WordWrap(asdf.Print(), 80) << endl << endl;
	asdf.Put(49, "Laguna Beach");

	cout << WordWrap(asdf.Print(), 80) << endl << endl;

	asdf.Erase(41);
	asdf.Erase(44);
	asdf.Erase(59);
	asdf.Erase(32);
	asdf.Erase(73);
	asdf.Erase(17);
	asdf.Erase(77);
	asdf.Erase(26);
	asdf.Erase(19);
	asdf.Erase(60);
	asdf.Erase(35);
	asdf.Erase(52);
	asdf.Erase(11);
	asdf.Erase(18);
	asdf.Erase(22);
	asdf.Erase(49);

	cout << WordWrap(asdf.Print(), 80) << endl << endl;

	return 0;
}


