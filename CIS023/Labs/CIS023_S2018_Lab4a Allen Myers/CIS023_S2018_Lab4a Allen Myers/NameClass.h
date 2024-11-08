//Module:	NameClass.h
//Project:	CIS023_S2018_Lab4a Allen Myers
//Author:	Allen Myers
//Date:		February 5th, 2018
//Purpose:	Header file for NameClass.cpp
//			Derived from IDClass, this is the Class Header
//

#pragma once
#include "IDClass.h"
class NameClass :
	public IDClass
{
public:
	NameClass();
	~NameClass();

	void Proof(int);
	
	void SetFirst(TCHAR*);			//sets szFirst
	void SetLast(TCHAR*);			//sets szLast
	TCHAR*GetFirst();				//returns szFirst
	TCHAR*GetLast();				//returns szLast

private:
	TCHAR szFirst[100];				//student first name
	TCHAR szLast[100];				//student last name

};

