//Module:	HexClass.h
//Project:	CIS023_S2018_HW6 Allen Myers
//Author:	Allen Myers
//Date:		March 10th, 2018
//Purpose:	Header file for HexClass
//
#pragma once
class HexClass:
	public string
{
public:
	HexClass();
	~HexClass();

	HexClass(TCHAR*);					//overloaded constructor
	int Convert(TCHAR *);
	TCHAR * Convert(int);

	TCHAR*GetNum();							//return iValue, converted to TCHAR*

											//operator overrides

	TCHAR*operator+(const HexClass& rcOther);		//override +
	TCHAR*operator-(const HexClass& rcOther);		//override -
	TCHAR*operator/(const HexClass& rcOther);		//override *
	TCHAR*operator*(const HexClass& rcOther);		//override +
	TCHAR*operator++();		//override ++
	TCHAR*operator--();		//overide --

private:
	int iValue;								//stored number(from constructor)
	TCHAR szReturn[100];					//return TCHAR

	TCHAR*ConvertToTCHAR(int);				//convert int to TCHAR for testing

};

