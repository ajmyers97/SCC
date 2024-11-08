//Module:	GradeClass.cpp
//Project:	CIS023_S2018_Lab4a Allen Myers
//Author:	Allen Myers
//Date:		February 5th, 2018
//Purpose:	Implementation file for GradeClass.cpp
//			Derived from IDClass
//
#include "stdafx.h"
#include "GradeClass.h"


GradeClass::GradeClass()
{
}


GradeClass::~GradeClass()
{
}

void GradeClass::SetGrade(TCHAR *szIn)
{
	_tcscpy_s(szGrade, szIn);			//copy input to szGrade
}



TCHAR * GradeClass::GetGrade()
{
	return szGrade;
}

