//Module:	GradeClass.h
//Project:	CIS023_S2018_Lab4a Allen Myers
//Author:	Allen Myers
//Date:		February 5th, 2018
//Purpose:	Header file for GradeClass.cpp
//			Derived from IDClass, this is the Class Header
//
#pragma once
#include "IDClass.h"
class GradeClass :
	public IDClass
{
public:
	GradeClass();
	~GradeClass();

	void SetGrade(TCHAR*);			//sets grade a
	TCHAR*GetGrade();				//returns grade a


private:
	TCHAR szGrade[100];			//students first grade

};

