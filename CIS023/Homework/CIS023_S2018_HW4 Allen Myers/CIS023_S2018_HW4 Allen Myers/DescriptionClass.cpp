//Module:	DesciptionClass.cpp
//Project:	CIS023_S2018_HW4 Allen Myers
//Author:	Allen Myers
//Date:		February 10th,2018
//Purpose:	Implementation of the Derived Class for Description
//			Stores input from DataInput-PartNumber Control
//
#include "stdafx.h"
#include "DescriptionClass.h"


DescriptionClass::DescriptionClass()
{
}


DescriptionClass::~DescriptionClass()
{
}

void DescriptionClass::SetDescription(TCHAR *szIn)
{

	_tcscpy_s(szDescription, szIn);
}

TCHAR * DescriptionClass::GetDescription()
{
	return szDescription;
}
