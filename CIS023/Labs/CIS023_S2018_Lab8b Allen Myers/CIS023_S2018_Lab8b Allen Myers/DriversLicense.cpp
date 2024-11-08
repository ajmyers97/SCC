//Module:	DriversLicense.cpp
//Project:	CIS023_S2018_Lab8b Allen Myers
//Author:	Allen Myers
//Date:		March 21st, 2018
//Purpose:	implementation file for DriversLicense clas
//

#include "stdafx.h"
#include "DriversLicense.h"


DriversLicense::DriversLicense()
{
}


DriversLicense::~DriversLicense()
{
}

DriversLicense::DriversLicense(string str1, string str2, string str3, string str4, string str5)
{
	size_t pRetVal;					///return value from mbstowcs_s

	mbstowcs_s(						//copy string into tchar
		&pRetVal,					//return values
		szLName,					//destination TCHAR
		TCHAR_SIZE,					//size of TCHAR
		str1.c_str(),				//source of string
		TCHAR_SIZE					//max number of chars to copy
	);
	mbstowcs_s(						//copy string into tchar
		&pRetVal,					//return values
		szFName,					//destination TCHAR
		TCHAR_SIZE,					//size of TCHAR
		str2.c_str(),				//source of string
		TCHAR_SIZE					//max number of chars to copy
	);
	mbstowcs_s(						//copy string into tchar
		&pRetVal,					//return values
		szCity,					//destination TCHAR
		TCHAR_SIZE,					//size of TCHAR
		str3.c_str(),				//source of string
		TCHAR_SIZE					//max number of chars to copy
	);
	mbstowcs_s(						//copy string into tchar
		&pRetVal,					//return values
		szAge,					//destination TCHAR
		TCHAR_SIZE,					//size of TCHAR
		str4.c_str(),				//source of string
		TCHAR_SIZE					//max number of chars to copy
	);
	mbstowcs_s(						//copy string into tchar
		&pRetVal,					//return values
		szLicense,					//destination TCHAR
		TCHAR_SIZE,					//size of TCHAR
		str5.c_str(),				//source of string
		TCHAR_SIZE					//max number of chars to copy
	);

	prevNode = nullptr;				//clear next and prev pointers
	nextNode = nullptr;


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

TCHAR * DriversLicense::GetLicense()
{
	return szLicense;
}

void DriversLicense::SetPrev(DriversLicense * node)
{
	prevNode = node;
}

void DriversLicense::SetNext(DriversLicense * node)
{
	nextNode = node;
}

DriversLicense * DriversLicense::GetPrev()
{
	return prevNode;
}

DriversLicense * DriversLicense::GetNext()
{
	return nextNode;
}
