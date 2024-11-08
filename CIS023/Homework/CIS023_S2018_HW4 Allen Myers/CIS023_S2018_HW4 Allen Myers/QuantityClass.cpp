//Module:	QuantityClass.cpp
//Project:	CIS023_S2018_HW4 Allen Myers
//Author:	Allen Myers
//Date:		February 10th,2018
//Purpose:	Implementation of the Derived Class for Quantity
//			Stores input from DataInput-PartNumber Control
//
#include "stdafx.h"
#include "QuantityClass.h"


QuantityClass::QuantityClass()
{
}


QuantityClass::~QuantityClass()
{
}

void QuantityClass::SetQuantity(TCHAR *szIn)
{
	_tcscpy_s(szQty, szIn);
}

TCHAR * QuantityClass::GetQuantity()
{
	return szQty;
}
