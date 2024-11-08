//Module:	NameClass.cpp
//Project:	CIS023_S2018_Lab4a Allen Myers
//Author:	Allen Myers
//Date:		February 5th, 2018
//Purpose:	Implementation file for NameClass.cpp
//			Derived from IDClass
//

#include "stdafx.h"
#include "NameClass.h"


NameClass::NameClass()
{
}


NameClass::~NameClass()
{
}

void NameClass::Proof(int iInput)
{
	int i = iInput + 100;

}

void NameClass::SetFirst(TCHAR *szIn)
{
	_tcscpy_s(szFirst, szIn);			//copy input to szFirst

}

void NameClass::SetLast(TCHAR *szIn)
{
	_tcscpy_s(szLast, szIn);		//copy input to szLast
}

TCHAR * NameClass::GetFirst()
{
	return szFirst;
}

TCHAR * NameClass::GetLast()
{
	return szLast;
}
