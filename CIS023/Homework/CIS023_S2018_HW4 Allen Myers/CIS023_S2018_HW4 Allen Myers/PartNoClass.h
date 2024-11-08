//Module:	PartsNoClass.h
//Project:	CIS023_S2018_HW4 Allen Myers
//Author:	Allen Myers
//Date:		February 10th,2018
//Purpose:	Base Class for DescriptionClass and QuantityClass
//			Stores input from DataInput-PartNumber Control
//
#pragma once
class PartNoClass
{
public:
	PartNoClass();
	~PartNoClass();

	void SetPartNum(TCHAR*);	//sets szPartNum
	TCHAR*GetPartNum();			//returns szPartNum
	
private:
	TCHAR szPartNum[100];		//part numbers
};

