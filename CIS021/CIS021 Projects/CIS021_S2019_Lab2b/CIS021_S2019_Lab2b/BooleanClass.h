// Project:    CIS021_S2019_Lab2b
// Module:     BooleanClass.h
// Author:     Elli Aylor
// Date:       January 24, 2019
// Purpose:    Header file for BooleanClass.cpp
//             Perform boolean operations on binary values
//             Find Boolean functions
//

#pragma once
class BooleanClass
{
public:
	BooleanClass();
	~BooleanClass();

	TCHAR* CalcResult(UINT, UINT, int);    // perform boolean operation on 2 nums
	void FindOperation(                    // given A, B and output
		UINT, UINT, UINT, bool[]);         // which operations could be used

private:
	TCHAR szReturn[TCHAR_SIZE];           // return TCHAR for display

	UINT NOT(UINT);                       // invert bits
	void UintToBin(UINT);                 // convert to TCHAR, store in szReturn
};

