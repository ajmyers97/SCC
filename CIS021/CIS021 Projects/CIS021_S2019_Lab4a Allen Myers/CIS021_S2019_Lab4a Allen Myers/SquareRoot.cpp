//Module:	CIS021_S2019_Lab4a Allen Myers.cpp
//Project:	CIS021_S2019_Lab4a Allen Myers
//Author:	Allen Myers
//Date:		Feb 26th, 2019
//Purpose:	
#include "stdafx.h"
#include "SquareRoot.h"


SquareRoot::SquareRoot()
{
}


SquareRoot::~SquareRoot()
{
}

bool::SquareRoot::isPerfectSquare(int iTarget, int& iFac)
{
	bool bReturn = false;				//default return value

	iFac = 2;							//testing integer
	do
	{
		if (iTarget == iFac*iFac)		//yes, input is a perfect square
			return true;
		iFac++;							//try next number
	} while (iFac<iTarget);				//contue search until found of too large
			
		return bReturn;
}

bool SquareRoot::FindSquareRootsOfPerfectSquareFactors(int iTarget, int &iFac1, int &iFac2)
{
	bReturn = false;					//default return
	iFac1 = 2; iFac2 = 2;				//set start values

	while (iFac1*iFac2 < iTarget)			//looping the first factor
	{
		while (iTarget >= ((iFac1*iFac1)*(iFac2*iFac2)))
		{
			if (iTarget == ((iFac1*iFac1)*(iFac2*iFac2)))
				return true;
			iFac2++;						//next 2nd factor
		}
		iFac1++;							//next first factor
		iFac2 = 2;							//reset factor 2
	}
	return bReturn;
}

bool SquareRoot::FindRoots(int uTargete, int & iSqrFac, int & iFac)
{
	bReturn = false;
	iSqrFac = 2;
	iFac = 1;

	while (iSqrFac*iSqrFac < uTargete)
	{
		while (((iSqrFac*iSqrFac)*iFac) <= uTargete)	//loop until factors are found
		{
			if ((iSqrFac*iSqrFac)*iFac == uTargete)
				return true;
			iFac++;										//next
		}
		iSqrFac++;										//next
		iFac = 1;										//next
	}


	return bReturn;
}

void SquareRoot::Estimate(int uTargete, int & iLower, int & iHigher)
{
	iLower = 1;
	iHigher = 2;
	while (uTargete > (iHigher*iLower))					//run till past answer
	{
		iLower++;										//next
		iHigher++;										//next
	}
}

double SquareRoot::LongDivision(double dIn)
{
	dReturn = 0.0;	//set return value

	int iPair;
	int iPairRoot;
	int iRemainder;
	int iFactor=0;
	int iSolution = 0;
	int iIndex = 0;

	iPair = SplitDouble(dIn, iIndex++);					//split the original value


	iPairRoot = FindHighestRoot(iPair, iFactor);		//find 1st divisor
	AppendDigits(iSolution, iPairRoot);					//save to solution

	iRemainder = iPair - (iPairRoot*iPairRoot);			//1st remainder
	AppendDigits(iRemainder, SplitDouble(dIn, iIndex++));	//pull down next pair

	iFactor = iSolution * 2;							//next factor
	iPairRoot = FindHighestRoot(iRemainder, iFactor);	//next division
	AppendDigits(iSolution, iPairRoot);					//save to soltuion

	while (iSolution / 1000.0 < dIn)
	{
		AppendDigits(iFactor, iPairRoot);
		iRemainder = iRemainder - (iFactor*iPairRoot);
		int iPullDown = SplitDouble(dIn, iIndex++);
		AppendDigits(iRemainder, iPullDown);
		if(iPullDown==0)
			AppendDigits(iRemainder, iPullDown);		//repeat
		iFactor = iSolution * 2;
		iPairRoot = FindHighestRoot(iRemainder, iFactor);
		AppendDigits(iSolution, iPairRoot);


	}
	dReturn = iSolution / 100000.0;


	return dReturn;
}

int SquareRoot::SplitDouble(double dIn, int iPos)
{
	int iReturn = 0;
	int aPairs[10];
	int iIndex = 0;
	TCHAR szIn[100];
	string strIn;

	memset(aPairs, 0, sizeof(aPairs));					//clear array

	//convert dIn to string ready to parse

	_stprintf_s(szIn, TEXT("%.4f"), dIn);				//double to TCHAR(even # of decimals a must)
	wstring temp(szIn);									//TCHAR to stream
	string str(temp.begin(), temp.end());				//stream to string
	strIn = str;										//save local copy

	int iStrIndex = 0;
	int iDot = strIn.find('.');
	
	if (iDot % 2 != 0)									//this is an odd number
	{
		char c = strIn[0];								//1st char
		aPairs[0] = c - 0x30;							//convert to number
		iStrIndex++;									//advance string
		iIndex++;										//advance array index
	}

	while (iStrIndex < iDot)							//et values left of decimal point
	{
		char c = strIn[iStrIndex++];					//1st char
		aPairs[iIndex] = (c - 0x30) * 10;				//convert to number, 10's place
		 c = strIn[iStrIndex++];						//2nd char
		aPairs[iIndex] += c - 0x30;						//append to number
		iIndex++;										//advance array index
	}

	iStrIndex = iDot + 1;								//advance past the dot

	while (iStrIndex < strIn.length())
	{
		char c = strIn[iStrIndex++];					//1st char
		aPairs[iIndex] = (c - 0x30) * 10;				//convert to number, 10's place
		c = strIn[iStrIndex++];							//2nd char
		aPairs[iIndex] += c - 0x30;						//append to number
		iIndex++;										//advance array index

	}

	return aPairs[iPos];								//return the requested pair
}
//if work = 123 and appent = 456, then work=123456
void SquareRoot::AppendDigits(int & iWork , int iAppend)
{
	int iMove = iAppend;								//iMove has the number of digits that must be moved

	do {
		iWork *= 10;									//move work decimal over 1 place
		iMove /= 10;									//reduce the mover one place

	} while (iMove > 0);								//do until no more moved needed
	iWork += iAppend;									//append the digits to the decimal
}

int SquareRoot::FindHighestRoot(int iTarget, int iFactor)
{
	int iReturn = 0;
	int iRoot = 0;
	int iBase = iFactor*iRoot;							//incrementer

	while (iTarget > iBase*iRoot)						//loop until highest root found
	{
		iReturn = iRoot++;								//set highest
		iBase = iFactor;
		AppendDigits(iBase, iRoot);				
	}
	return iReturn;
}
