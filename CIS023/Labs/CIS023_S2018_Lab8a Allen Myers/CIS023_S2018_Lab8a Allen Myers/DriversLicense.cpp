//Module:	DriversLicense.cpp
//Project:	CIS023_S2018_Lab8a Allen Myers
//Author:	Allen Myers
//Date:		March 19th, 2018
//Purpose:	Implementation file for DriversLicense.cpp.
//			node class for linked list
//

#include "stdafx.h"
#include "DriversLicense.h"


DriversLicense::DriversLicense()
{
	Next = nullptr;			//initialize pointer to next node in linked list
}


DriversLicense::~DriversLicense()
{
}

void DriversLicense::SetData(string str1, string str2, string str3, string str4, string str5)
{
	size_t pRetVal;				//return values for mbstowcs_s
	mbstowcs_s(					//convert string to TCHAR
		&pRetVal,				//return value
		szLName,				//dest TCHAR
		TCHAR_SIZE,				//size of TCHAR
		str1.c_str(),			//source string
		TCHAR_SIZE				//max chars to copy
	);
	///size_t pRetVal;				//return values for mbstowcs_s
	mbstowcs_s(					//convert string to TCHAR
		&pRetVal,				//return value
		szFName,				//dest TCHAR
		TCHAR_SIZE,				//size of TCHAR
		str2.c_str(),			//source string
		TCHAR_SIZE				//max chars to copy
	);
	//	size_t pRetVal;				//return values for mbstowcs_s
	mbstowcs_s(					//convert string to TCHAR
		&pRetVal,				//return value
		szCity,				//dest TCHAR
		TCHAR_SIZE,				//size of TCHAR
		str3.c_str(),			//source string
		TCHAR_SIZE				//max chars to copy
	);
	//	size_t pRetVal;				//return values for mbstowcs_s
	mbstowcs_s(					//convert string to TCHAR
		&pRetVal,				//return value
		szAge,				//dest TCHAR
		TCHAR_SIZE,				//size of TCHAR
		str4.c_str(),			//source string
		TCHAR_SIZE				//max chars to copy
	);
	//	size_t pRetVal;				//return values for mbstowcs_s
	mbstowcs_s(					//convert string to TCHAR
		&pRetVal,				//return value
		szDLNum,				//dest TCHAR
		TCHAR_SIZE,				//size of TCHAR
		str5.c_str(),			//source string
		TCHAR_SIZE				//max chars to copy
	);
	Next = nullptr;			//initialize pointer to next node in linked list


}


TCHAR * DriversLicense::GetLName()
{
	return szLName;
}

TCHAR * DriversLicense::GetFName()
{
	return szFName;
}

TCHAR * DriversLicense::GetCity()
{
	return szCity;
}

TCHAR * DriversLicense::GetAge()
{
	return szAge;
}

TCHAR * DriversLicense::GetDLNum()
{
	return szDLNum;
}
void DriversLicense::SetNext(DriversLicense *Node)
{
	Next = Node;
}

DriversLicense * DriversLicense::GetNext()
{
	return Next;
}
