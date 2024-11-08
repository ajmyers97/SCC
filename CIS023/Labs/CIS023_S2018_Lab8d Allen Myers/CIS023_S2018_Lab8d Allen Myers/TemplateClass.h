// Module:		TemplateClass.h
// Project:		CIS023_S1018_Lab6d Mark Berrett
// Author:		Mark Berrett
// Date:		March 7, 2018
// Purpose:		Template functions
//					Compare the size of two variables
//					Convert TCHAR to integer
//					Convert integer to TCHAR
//					Convert TCHAR to string
//					Convert string to TCHAR
//

#pragma once

#include <string>		// string class
#include <sstream>		// stream class

using namespace std;	// Use standard namespaces

#define TCHAR_SIZE 128	// TCHAR array size


// compares two items of similar basic datat type
// returns -1 if first < second
// returns 0 if the items are identical
// returns 1 if first > second
template <class Type>
Type CompareSize(Type x, Type y)
{
	if (x < y)								// is first value less than second?
		return -1;
	else if (x == y)						// are the values equal?
		return 0;
	else									// default: the first value must be greater than the second
		return 1;

}

// converts specified TCHAR into an integer, using specified base
// returns integer
// no exception handling
// uses stoi, so invalid TCHAR returns 0 integer
template <class Type>
int TCHARtoInt(TCHAR* szIn, Type iBase)
{
	int iReturn = 0;

	if (lstrlen(szIn) > 0 &&
		lstrlen(szIn) < 10)						// do nothing if empty or too many digits
	{
		wstring temp(szIn);						// convert TCHAR to stream
		string str(temp.begin(), temp.end());	// convert stream to string

		iReturn = stoi(str, NULL, iBase);		// convert to integer using specified base
	}
	return iReturn;
}

// converts integer into a TCHAR
// modifies parameter TCHAR in place
// max 10 digit integer
// no exception handling
template <class Type>
void InttoTCHAR(Type iIn, TCHAR* szIn)
{
	TCHAR szWork[10];						// produced at compile time, so must be hardcoded size

	// clear 
	memset(szIn, 0, sizeof(szIn));

	_stprintf_s(szWork,						// convert integer to TCHAR
		TEXT("%i"),		
		iIn);

	_tcscpy_s(szIn,							// display input integer in output field
		10,
		szWork);							// use template convert to TCHAR
}

// converts TCHAR to string
// uses pointer to string (calling code needs &string)
template <class Type>
void TCHARtoString(TCHAR* szIn, Type* strIn)
{
	if (lstrlen(szIn) == 0)					// must be characters to store
		strIn->erase();						//		then empty return string
	else
	{
		wstring temp(szIn);					// convert TCHAR to stream
		string str(temp.begin(),			// convert stream to string
			temp.end());

		strIn->append(str);					// copy temp string to return string
	}
}

// converts string to TCHAR
// modifies TCHAR in place
// returns mbstowcs_s return code
// max TCHAR_SIZE char string length
template <class Type>
size_t StringtoTCHAR(Type* strIn, TCHAR* szIn)
{
	size_t pReturnValue = 0;				// return code from mbstowcs_s

	if (strIn->length() == 0 ||
		strIn->length() > TCHAR_SIZE)		// don't attempt to convert if bad input string size
	{
		memset(szIn, 0, sizeof(szIn));
	}
	else
	{
		mbstowcs_s(							// convert ASCII to Unicode
			&pReturnValue,					// convert ok
			szIn,							// destination string
			TCHAR_SIZE,						// max size of destination
			strIn->c_str(),					// source string
			TCHAR_SIZE);					// max chars to copy

	}
	return pReturnValue;					// return error code
}

