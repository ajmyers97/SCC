//Module:	HexClass.h
//Project:	CIS023_S2018_HW6 Allen Myers
//Author:	Allen Myers
//Date:		March 10th, 2018
//Purpose:	Implementation file for HexClass
//			Holds data from the input boxes to pass to functions
//
#include "stdafx.h"
#include "HexClass.h"
class Zero{};							//exception class
class Negative{};						//exception class

HexClass::HexClass()
{
	erase();							//defaalt, erase the base class string

}


HexClass::~HexClass()
{
}


HexClass::HexClass(TCHAR *szIn)
{
	////////////////////////////
	//without exception handling--this works
	string strInput;					//converted string from SZIN
	iValue = 0;						//initialize stored integer value (-99 is bad)
	if (lstrlen(szIn) != 0)				//make sure there there is something in the TCHAR before using it
	{
		for (int i = 0; i < lstrlen(szIn); i++)	//roll through TCHAR
			szIn[i] = _totupper(szIn[i]);		//upper case TCHAR
		wstring temp(szIn);						//convert TCHAR to stream
		string str(temp.begin(), temp.end());	//convert stream to string
		iValue = stoul(str, NULL, 16);			//convert string to HEX
	}
	///////////////////////////
	//with exception handling
	//erase();
	//try {
	//	if (lstrlen(szIn) == 0)				//make sure there there is something in the TCHAR before using it
	//		throw 1;						//throw an exception
	//	wstring temp(szIn);						//convert TCHAR to stream
	//	string str(temp.begin(), temp.end());	//convert stream to string
	//	append(str) = stoul(str, NULL, 16);			//convert string to HEX

	//}
	//catch (int)
	//{
	//	MessageBox(							//message box
	//		NULL,							//floating
	//		TEXT("PLEASE INPUT A VALUE"),	//message
	//		TEXT("INPUT ERROR"),			//caption
	//		MB_ICONERROR);					//icon
	//}

}

TCHAR * HexClass::GetNum()
{
	////////////////////////////
	//without exception handling--this works
	_stprintf_s(				//TCHAR safe printf
		szReturn,				//target TCHAR
		TEXT("%i"),				//printf patten
		iValue					//stored value
	);
	return szReturn;

	///////////////////////////
	//with exception handling
	//if (empty())
	//	return szReturn;
	//try {
	//	_stprintf_s(				//TCHAR safe printf
	//		szReturn,				//target TCHAR
	//		TEXT("%i"),				//printf patten
	//		iValue					//stored value
	//	);

	//}
	//catch (Negative)
	//{
	//	MessageBox(							//message box
	//		NULL,							//floating
	//		TEXT("Negative values are okay of course, but this time let's keep it positive."),	//message
	//		TEXT("NEGATIVE INPUT"),			//caption
	//		MB_ICONHAND);					//icon

	//}
	//catch (ZeroException ze)
	//{
	//	MessageBox(							//ERROR MESSAGE
	//		NULL,							//floating
	//		ze.what(),						//USING MESSAGE FROME XCEPTIO CLASS ZERO EXCEPTION
	//		TEXT("INPUT ERROR"),			//caption
	//		MB_ICONASTERISK);				//icon
	//}

	//return szReturn;


}

TCHAR * HexClass::operator+(const HexClass & rcOther)
{
	return ConvertToTCHAR(iValue + rcOther.iValue);		//add values, convert to TCHAR* return
}

TCHAR * HexClass::operator-(const HexClass & rcOther)
{
	return ConvertToTCHAR(iValue - rcOther.iValue);		//subtract values, convert to TCHAR* return
}

TCHAR * HexClass::operator/(const HexClass & rcOther)
{
	//with exception handling, make sure that the value does not divide by zero.
	//throw an error if this happens.
	return ConvertToTCHAR(iValue / rcOther.iValue);		//divide values, convert to TCHAR* return
}

TCHAR * HexClass::operator*(const HexClass & rcOther)
{
	return ConvertToTCHAR(iValue * rcOther.iValue);		//multiply values, convert to TCHAR* return
}

TCHAR * HexClass::operator++()
{
	return ConvertToTCHAR(iValue + 1);
}

TCHAR * HexClass::operator--()
{
	return ConvertToTCHAR(iValue - 1);
}

TCHAR * HexClass::ConvertToTCHAR(int iIn)
{
	//////////////////////////
	//without exception handling--this works
	_stprintf_s(				//TCHAR safe printf
		szReturn,				//target TCHAR
		TEXT("%i"),				//printf patten
		iIn						//integer to convert
	);
	return szReturn;
	//////////////////////////
	//with exception handling
	//do not allow the value to be larger than the value of "FFFF"



}