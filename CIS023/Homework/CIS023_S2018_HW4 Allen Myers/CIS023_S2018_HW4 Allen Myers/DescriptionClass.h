//Module:	DesciptionClass.h
//Project:	CIS023_S2018_HW4 Allen Myers
//Author:	Allen Myers
//Date:		February 10th,2018
//Purpose:	Derived Class for Description
//			Stores input from DataInput-PartNumber Control
//
#pragma once
#include "PartNoClass.h"
class DescriptionClass :
	public PartNoClass
{
public:
	DescriptionClass();
	~DescriptionClass();

	void SetDescription(TCHAR*);	//sets szPartNum
	TCHAR*GetDescription();			//returns szDesc

private:
	TCHAR szDescription[100];		//part description
};

