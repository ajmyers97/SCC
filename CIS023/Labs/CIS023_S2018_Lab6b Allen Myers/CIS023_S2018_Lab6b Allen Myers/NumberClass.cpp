//Module:	NumberClass.cpp
//Project:	CIS023_S2018_Lab6b Allen Myers
//Author:	Allen Myers
//Date:		Feb 28th, 2018
//Purpose:	Implementation file for numberclass.cpp
//			Method overloading example
//
#include "stdafx.h"
#include "NumberClass.h"


NumberClass::NumberClass()
{
	iValue = -99;						//default value, just in case default constructor called

}


NumberClass::~NumberClass()
{
}

NumberClass::NumberClass(TCHAR *szIn)
{
	string strInput;					//converted string from SZIN
	iValue = -99;						//initialize stored integer value (-99 is bad)
	if (lstrlen(szIn) != 0)				//make sure there there is something in the TCHAR before using it
	{
		for (int i = 0;i < lstrlen(szIn);i++)	//roll through TCHAR
			szIn[i] = _totupper(szIn[i]);		//upper case TCHAR
		wstring temp(szIn);						//convert TCHAR to stream
		string str(temp.begin(), temp.end());	//convert stream to string
		strInput = str;							//copy to our work string
	}
	//TEST USER INPUT FOR VALUES
	if (strInput == "ZERO")						//zero=0
		iValue = 0;
	else if (strInput == "ONE")					//ONE=1
		iValue = 1;
	else if (strInput == "TWO")					//TWO=2
		iValue = 2;
	else if (strInput == "THREE")				//THREE=3
		iValue = 3;
	else if (strInput == "FOUR")				//FOUR=4
		iValue = 4;
	else if (strInput == "FIVE")				//FIVE=5
		iValue = 5;
	else if (strInput == "SIX")					//SIX=6
		iValue = 6;
	else if (strInput == "SEVEN")				//SEVEN=7
		iValue = 7;
	else if (strInput == "EIGHT")				//EIGHT=8
		iValue = 8;
	else if (strInput == "NINE")				//NINE=9
		iValue = 9;
	//NO ELSE(DEFAULT) NEEDED BECAUSE iValue INITIALIZED AT TOP OF THIS CONSTRUCTOR



}

TCHAR * NumberClass::GetNum()
{
	_stprintf_s(				//TCHAR safe printf
		szReturn,				//target TCHAR
		TEXT("%i"),				//printf patten
		iValue					//stored value
	);
	return szReturn;
}

TCHAR * NumberClass::operator+(const NumberClass & rcOther)
{
	return ConvertToTCHAR(iValue + rcOther.iValue);		//add values, convert to TCHAR* return
}

TCHAR * NumberClass::operator-(const NumberClass & rcOther)
{
	return ConvertToTCHAR(iValue - rcOther.iValue);		//subtract values, convert to TCHAR* return
}

TCHAR * NumberClass::operator/(const NumberClass & rcOther)
{
	return ConvertToTCHAR(iValue / rcOther.iValue);		//divide values, convert to TCHAR* return
}

TCHAR * NumberClass::operator*(const NumberClass & rcOther)
{
	return ConvertToTCHAR(iValue * rcOther.iValue);		//multiply values, convert to TCHAR* return
}

TCHAR * NumberClass::operator++()
{
	return ConvertToTCHAR(iValue + 1);
}

TCHAR * NumberClass::operator--()
{
	return ConvertToTCHAR(iValue - 1);
}

TCHAR * NumberClass::ConvertToTCHAR(int iIn)
{

	_stprintf_s(				//TCHAR safe printf
		szReturn,				//target TCHAR
		TEXT("%i"),				//printf patten
		iIn						//integer to convert
	);
	return szReturn;
}
