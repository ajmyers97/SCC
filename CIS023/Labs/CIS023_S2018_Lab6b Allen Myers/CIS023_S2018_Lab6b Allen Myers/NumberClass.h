//Module:	NumberClass.h
//Project:	CIS023_S2018_Lab6b Allen Myers
//Author:	Allen Myers
//Date:		Feb 28th, 2018
//Purpose:	Header file for numberclass.cpp
//
//
#pragma once
class NumberClass
{
public:
	NumberClass();
	~NumberClass();


	NumberClass(TCHAR*);					//overloaded constructor

	TCHAR*GetNum();							//return iValue, converted to TCHAR*
	
	//operator overrides

	TCHAR*operator+(const NumberClass& rcOther);		//override +
	TCHAR*operator-(const NumberClass& rcOther);		//override -
	TCHAR*operator/(const NumberClass& rcOther);		//override *
	TCHAR*operator*(const NumberClass& rcOther);		//override +
	TCHAR*operator++();		//override ++
	TCHAR*operator--();		//overide --

private:
	int iValue;								//stored number(from constructor)
	TCHAR szReturn[100];					//return TCHAR

	TCHAR*ConvertToTCHAR(int);				//convert int to TCHAR for testing
};

