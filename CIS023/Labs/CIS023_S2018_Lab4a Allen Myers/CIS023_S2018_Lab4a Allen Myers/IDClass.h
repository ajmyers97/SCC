//Module:	IDClass.h
//Project:	CIS023_S2018_Lab4a Allen Myers
//Author:	Allen Myers
//Date:		February 5th, 2018
//Purpose:	Header file for IDClass.cpp
//			Base Class Header
//

#pragma once
class IDClass
{
public:
	IDClass();
	~IDClass();


	void Proof(int);

	void SetID(TCHAR*);			//sets szID
	TCHAR*GetID();				//return szID


private:	//private class functions that are only accesible inside IDClass
	TCHAR szID[100];		//student id numbers

};

