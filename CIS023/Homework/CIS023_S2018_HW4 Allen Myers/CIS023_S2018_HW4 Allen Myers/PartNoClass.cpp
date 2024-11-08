//Module:	PartsNoClass.cpp
//Project:	CIS023_S2018_HW4 Allen Myers
//Author:	Allen Myers
//Date:		February 10th,2018
//Purpose:	Implementation of the Base Class for DescriptionClass and QuantityClass
//			Stores input from DataInput-PartNumber Control
//
#include "stdafx.h"
#include "PartNoClass.h"


PartNoClass::PartNoClass()
{
}


PartNoClass::~PartNoClass()
{
}

void PartNoClass::SetPartNum(TCHAR *szIn)
{
	_tcscpy_s(szPartNum, szIn);
}

TCHAR * PartNoClass::GetPartNum()
{
	return szPartNum;
}
