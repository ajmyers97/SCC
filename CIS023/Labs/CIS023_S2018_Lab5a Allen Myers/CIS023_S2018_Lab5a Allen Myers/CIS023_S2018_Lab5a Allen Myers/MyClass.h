//Module:	MyClass.h
//Program:	CIS023_S2018_Lab5a Allen Myers
//Author:	Allen Myers
//Date:		February 12th, 2018
//Purpose:	Header file for MyClass.cpp


#pragma once
class MyClass
{
public:
	MyClass();
	~MyClass();

	void SetValue(int);			//sets iValue
	int GetValue();				//returns iValue

	void SetString(TCHAR*);		//sets szValue
	TCHAR*GetString();			//returns szValue

private:
	int iValue;					//local member
	TCHAR szValue[100];			//local string


};

