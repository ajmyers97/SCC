//Module:	IDClass.cpp
//Project:	CIS023_S2018_Lab4a Allen Myers
//Author:	Allen Myers
//Date:		February 5th, 2018
//Purpose:	Implementation file for IDClass
//			Base Class Header
//

#include "stdafx.h"
#include "IDClass.h"


IDClass::IDClass()
{
}


IDClass::~IDClass()
{
}

void IDClass::Proof(int iInput)
{
	int i = iInput;
}

void IDClass::SetID(TCHAR *szIn)
{

	_tcscpy_s(szID, szIn);		//copy of a TCHAR pointer into TCHAR array


}

TCHAR * IDClass::GetID()
{
	return szID;				//return the private value
}
