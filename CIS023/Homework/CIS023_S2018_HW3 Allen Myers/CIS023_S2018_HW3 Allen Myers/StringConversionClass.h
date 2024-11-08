//Module: CIS023_S2018_HW3 Allen Myers.cpp
//Program:		CIS023_S2018_HW3 Allen Myers.
//Author:		Allen Myers
//Date:			February 3rd, 2018
//Purpose:		Header File for StringConversionClass
//				Convert TCHAR to String
//				Convert string to TCHA
#pragma once
class StringConversionClass
{
public:
	StringConversionClass();
	~StringConversionClass();




	//TCHAR* Manipulate(TCHAR*, TCHAR*);	//we need the address of the pointer for what is located in the TCHAR(Converts the TCHAR to string and String to TCHAR)
	//TCHAR szReturn[100];		//return value of TCHAR array

	TCHAR*ConvertTCHARtoString(TCHAR*);
	TCHAR szReturnString[100];

	TCHAR*ConvertStringtoTCHAR(TCHAR*);
	TCHAR szReturnTCHAR[100];
};

