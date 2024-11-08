//Module:	CIS023_S2018_Lab3b Allen Myers.cpp
//Project:	CIS023_S2018_Lab3b Allen Myers
//Author:	Allen Myers
//Date:		January 31st, 2018
//Purpose:	Implementation file for MyClass
//			Convert TCHAR to String
//			Convert string to TCHAR

#include "stdafx.h"
#include "MyClass.h"


MyClass::MyClass()
{
}


MyClass::~MyClass()
{
}

TCHAR * MyClass::Manipulate(TCHAR *sz1, TCHAR *sz2)
{
	string strReturn;					//resulting string

	string str1;				//work strings, converted from sz1, and sz2-local to this section
	string str2;

	size_t pRet;				//return value from mbstowcs_s()
	

	//converts TCHAR to string
	if (lstrlen(sz1) != 0)			//do nothing to an empty TCHAR
	{
		wstring temp(sz1);			//convert TCHAR to wString
		string str(temp.begin(), temp.end()); //convert wstring to string
		str1 = str;				//copy to local variable

	}

	if (lstrlen(sz2) != 0)						//do nothing to an empty TCHAR
	{
		wstring temp(sz2);						//convert TCHAR to wString
		string str(temp.begin(), temp.end());   //convert wstring to string
		str2 = str;								//copy to local variable

	}

	strReturn= str1 + ", " + str2;		//concatinate the results

	mbstowcs_s(					//convert string to TCHAR
		&pRet,						//return value
		szReturn,					//destination TCHAR
		100,						//number of char TCHAR can take
		strReturn.c_str(),			//text of source string
		100							//max chars to copy(usually matches the TCHAR)
		);

	return szReturn;	//returns new value
}
