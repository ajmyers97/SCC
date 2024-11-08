//Module:	HexClass.h
//Project:	CIS023_S2018_Lab6a Allen Myers
//Author:	Allen Myers
//Date:		Feb 26th, 2018
//Purpose:	Header file for HexClas.cpp
//

#pragma once
class HexClass
{
public:
	HexClass();
	~HexClass();

	int Convert(TCHAR*);				//convert HEX number(as a TCHAR) to integer(base 10).
	TCHAR* Convert(int);					//convert integer to Hex


private:
	int iReturn;						//return integer
	TCHAR szReturn[100];				//return TCHAR
};	

