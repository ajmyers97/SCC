//Module:	MyClass.cpp
//Program:	CIS023_S2018_Lab5a Allen Myers
//Author:	Allen Myers
//Date:		February 12th, 2018
//Purpose:	Implementation file for MyClass

#include "stdafx.h"
#include "MyClass.h"


MyClass::MyClass()
{
}


MyClass::~MyClass()
{
}

void MyClass::SetValue(int iIn)
{
	iValue = iIn;

}

int MyClass::GetValue()
{
	return iValue;
}

void MyClass::SetString(TCHAR *szIn)
{
	_tcscpy_s(szValue,szIn);		//copy input TCHAR to local member
}

TCHAR * MyClass::GetString()
{
	return szValue;
}
