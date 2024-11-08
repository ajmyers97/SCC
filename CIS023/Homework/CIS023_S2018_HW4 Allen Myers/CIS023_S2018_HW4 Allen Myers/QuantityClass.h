//Module:	QuantityClass.h
//Project:	CIS023_S2018_HW4 Allen Myers
//Author:	Allen Myers
//Date:		February 10th,2018
//Purpose:	Derived Class for Quantity
//			Stores input from DataInput-PartNumber Control
//
#pragma once
#include "PartNoClass.h"
class QuantityClass :
	public PartNoClass
{
public:
	QuantityClass();
	~QuantityClass();

	void SetQuantity(TCHAR*);
	TCHAR* GetQuantity();
private:
	TCHAR szQty[100];
};

