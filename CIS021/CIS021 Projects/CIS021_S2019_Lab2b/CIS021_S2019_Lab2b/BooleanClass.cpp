// Project:    CIS021_S2019_Lab2b
// Module:     BooleanClass.cpp
// Author:     Elli Aylor
// Date:       January 24, 2019
// Purpose:    Implementation file for BooleanClass

#include "stdafx.h"
#include "BooleanClass.h"


BooleanClass::BooleanClass()
{
}


BooleanClass::~BooleanClass()
{
}

TCHAR * BooleanClass::CalcResult(UINT uA, UINT uB, int iOper)
{
	UINT uResult = 0;               // return value

	switch (iOper)                  // iOper is the operation selected
	{
	case 0: // NOT
		uResult = NOT(uA);          // NOT (inverse the bits) uA
		break;
	case 1: // AND
		uResult = uA & uB;          // AND (&) the values
		break;
	case 2: // OR
		uResult = uA | uB;          // OR (|) the values
		break;
	case 3: // NAND
		uResult = NOT(uA & uB);     // AND with a NOT
		break;
	case 4: // NOR
		uResult = NOT(uA | uB);     // OR with a NOT
		break;
	case 5: // XOR
		uResult = uA ^ uB;          // XOR the values
		break;
	case 6: // XNOR
		uResult = NOT(uA ^ uB);     // XOR with a NOT
		break;
	default:
		break;
	}


	UintToBin(uResult);             // convert UINT to TCHAR, store in szReturn
	return szReturn;                // return result 
}

// determine which Boolean operation generate give results
void BooleanClass::FindOperation(UINT uA, UINT uB, UINT uResult, bool bResults[])
{
	for (int i = 0; i < 7; i++)     // blank results
	{
		bResults[i] = false;
	}
	
    // test for operations
	bResults[0] = (NOT(uA) == uResult);        // NOT
	bResults[1] = (uA & uB == uResult);        // AND
	bResults[2] = (uA | uB == uResult);        // OR
	bResults[3] = (NOT(uA & uB) == uResult);   // NAND
	bResults[4] = (NOT(uA | uB) == uResult);   // NOR
	bResults[5] = (uA ^ uB == uResult);        // XOR
	bResults[6] = (NOT(uA ^ uB) == uResult);   // NXOR


}

// inverse the bits of an unsigned integer
UINT BooleanClass::NOT(UINT uValue)
{
	UINT uReturn = 0;               // return value
	TCHAR szTemp[TCHAR_SIZE];       // display UINT as array of chars
	string strTemp;                 // character manipulation

	_itot_s(                        // convert UINT to TCHAR
		uValue,                     // unsigned integer
		szTemp,                     // destTCHAR
		2);                         // base 2 (binary)

	// loop from right to left, reversing the bits
	for (int i = _tcslen(szTemp) - 1; i >= 0; i--)
	{
		strTemp += szTemp[i];
	}

	// append zeros to make 8-bits
	strTemp.append(8 - _tcslen(szTemp), '0');

	// invert the bits
	for (int i = 0; i < 8; i++)
	{
		(strTemp[i] == '0') ?       // if the bit is 0    
			strTemp[i] = '1' :      //       make it a 1  
			strTemp[i] = '0';       //       else make it a 0

	}

	// convert to UINT
	for (int i = 7; i >= 0; i--)    // loop right to left
	{
		if (strTemp[i] == '1')      // if this bit is set
		{ 
			uReturn += pow(2.0, i); // 2 to the bit'th power
		}
	}

	// loop from right to left, reversing the bits
	for (int i = _tcslen(szTemp) - 1; i >= 0; i--)
	{
		strTemp += szTemp[i];
	}

	return uReturn;                 // return result
}

// convert UINT to TCHAR, store in szReturn
void BooleanClass::UintToBin(UINT uValue)
{
	TCHAR szTemp[TCHAR_SIZE];       // work TCHAR
	string strTemp;                 // work string

	_itot_s(uValue, szTemp, 2);     // convert UINT to TCHAR in binary

	TCHARtoString(szTemp, &strTemp);// convert TCHAR to string (utilities.h)

	strTemp.insert(0,               // insert leading 0's
		8 - strTemp.length(),       // up to 8 
		'0');                       // zeros

	strTemp.insert(4, " ");         // insert a space at the nibble

	StringtoTCHAR(&strTemp,         // store the string in szReturn 
		szReturn);
}
