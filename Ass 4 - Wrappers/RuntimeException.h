/*************************************************************************
 * AUTHOR      : James Marcu
 * STUDENT ID  : 374443
 * ASS #3      : Stacks
 * CLASS       : CS1D
 * SECTION     : TTh 3:30 AM
 * DUE DATE    : 9/2/2014
 *************************************************************************/

/*************************************************************************
 * NOTE : The following code was copied from "Data Structures & Algorithms
 *        2nd Edition" by Michael T. Goodrich, Roberto Tamassia and David
 *        Mount.
 *************************************************************************/

#ifndef RUNTIMEEXCEPTION_H_
#define RUNTIMEEXCEPTION_H_

#include <string>
using namespace std;

//A generic exception.
class RuntimeException
{
	private:
		string errorMsg;

	public:
		RuntimeException(const string& err) {errorMsg = err; }
		string getMessage() const { return errorMsg; }
};



#endif /* RUNTIMEEXCEPTION_H_ */
