//Module:	DriversLicense.h
//Project:	CIS023_S2018_Lab8a Allen Myers
//Author:	Allen Myers
//Date:		March 19th, 2018
//Purpose:	Header file for DriversLicense.cpp.
//			node class for linked list
//
#pragma once
class DriversLicense
{
public:
	DriversLicense();
	~DriversLicense();

	void SetData(string, string, string, string, string);
	void SetNext(DriversLicense*);
	DriversLicense*GetNext();

	TCHAR *GetLName();				//return data
	TCHAR *GetFName();
	TCHAR *GetCity();
	TCHAR *GetAge();
	TCHAR *GetDLNum();

private:			
	TCHAR szLName[TCHAR_SIZE];	//stored data
	TCHAR szFName[TCHAR_SIZE];
	TCHAR szCity[TCHAR_SIZE];
	TCHAR szAge[TCHAR_SIZE];
	TCHAR szDLNum[TCHAR_SIZE];

	DriversLicense*Next;			//pointer to next node in linked list
};

