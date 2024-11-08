//Module:	HexClass.cpp
//Project:	CIS023_S2018_Lab6a Allen Myers
//Author:	Allen Myers
//Date:		Feb 26th, 2018
//Purpose:	Implementation file for HexClass
//			Converts hex to int, int to hex
//			uses method overloading
//

#include "stdafx.h"
#include "HexClass.h"


HexClass::HexClass()
{
}


HexClass::~HexClass()
{
}

int HexClass::Convert(TCHAR* szIn)
{
	iReturn = 0;								//initialize return value

	if (lstrlen(szIn) != 0)						//do nothing if input is length of zero chars
	{
		wstring temp(szIn);						//convert TCHAR to stream
		string str(temp.begin(), temp.end());	//convert stream to string

		iReturn = stoul(str, NULL, 16);			//convert string to HEX
	}

	return iReturn;								//return integer
}

TCHAR * HexClass::Convert(int iIn)
{
	stringstream sStream;						//temp stream
	sStream << hex << iIn;						//convert input integer value to hex
	string strHex(sStream.str());				//convert stream to string


	size_t pRet;								//mbstowcs_s return value
	mbstowcs_s(									//convert string to TCHAR
		&pRet,									//return value
		szReturn,								//target TCHAR
		100,									//size of TCHAR
		strHex.c_str(),							//source string
		100);									//mac chars to copy

	return szReturn;							//return TCHAR
}
