//Module:	DriversLicense.h
//Project:	CIS023_S2018_Lab8b Allen Myers
//Author:	Allen Myers
//Date:		March 21st, 2018
//Purpose:	header file for DriverLicense.cpp
//			node class for linked list
//
#pragma once
class DriversLicense
{
public:
	DriversLicense();
	~DriversLicense();

	DriversLicense(string, string, string, string, string);		//overloaded constructor

	TCHAR *GetLName();											//return values
	TCHAR *GetFName();
	TCHAR *GetCity();
	TCHAR *GetAge();
	TCHAR *GetLicense();

	void SetPrev(DriversLicense*);								//set previous node
	void SetNext(DriversLicense*);								//set next node
	DriversLicense*GetPrev();									//return prev node
	DriversLicense*GetNext();									//return next node
private:
	TCHAR szLName[TCHAR_SIZE];									//stored values
	TCHAR szFName[TCHAR_SIZE];
	TCHAR szCity[TCHAR_SIZE];
	TCHAR szAge[TCHAR_SIZE];
	TCHAR szLicense[TCHAR_SIZE];

	DriversLicense*prevNode;									//pointer to prev node
	DriversLicense*nextNode;									//pointer to next node




};

