//Project:	CIS021_S2019_Lab4B Allen Myers
//Module:	SquareRoot.cpp
//Author:	Allen Myers
//Date:		February 28th, 2019
//Purpose:	Finding a square root with "long division"
//			Calculates square root using "long division"
//			Implementation file of SquareRoot
#include "stdafx.h"
#include "SquareRoot.h"


SquareRoot::SquareRoot()
{
}


SquareRoot::~SquareRoot()
{
}


double SquareRoot::LongDivision(double dIn)
{
	dReturn = 0.0;								//initialize the return value
	int Pairs[NUM_PAIRS];						//dIn split into 2-digit pairs
	int iDigits = 0;							//how many digits in dIn
	int iFirstDecimalPair = 0;					//which pair is the 1st decimal
	int iPair;									//individual digits pair from Pairs[]
	int iPairIndex = 0;							//index of Pairs[]
	int iPairRoot = 0;							//highest sqaure root of root pair
	int iRemainder;								//division remainder
	int iFactor = 0;							//offset for division
	int iSolution = 0;							//square root of dIn, stretched to an integer
	int iSolutionDec = 0;						//the decimal position of the solution


	memset(Pairs, 0, sizeof(Pairs));			//initialize array

												//split dIn into pairs
	iDigits = SplitDouble(dIn, Pairs, iFirstDecimalPair);

	iPair = Pairs[iPairIndex++];				//get first pair
	
	iPairRoot = FindHighestRoot(iPair, iFactor);//find highest root in the first pair
	AppendDigits(iSolution, iPairRoot);			//add 1st number to solution

	iRemainder = iPair - (iPairRoot*iPairRoot);	//1st pair-highest root squared

	for (int i = iPairIndex; i < iDigits; i++)	//answer same number of digits at dIn
	{
		if (iPairIndex == iFirstDecimalPair)	//are we right of the '.'
			iSolution = iPairIndex;

		int iPullDown = Pairs[iPairIndex];		//pull down next pair
		AppendDigits(iRemainder, iPullDown);	//append pull down to the remaind
		if(iPullDown==0)						//if it is a 0
			AppendDigits(iRemainder, 0);		//2nd 0

		iFactor = iSolution * 2;				//factor is solution x 2

												//find highest root
		iPairRoot = FindHighestRoot(iRemainder, iFactor);

		AppendDigits(iSolution, iPairRoot);		//append highest root to the solution
		
		AppendDigits(iFactor, iPairRoot);		//create new factor

												//calculate new remainder
		iRemainder = iRemainder - (iFactor*iPairRoot);

	}
	//move the solution to a decimal and insert the decimal in the correctlocation
	string strSolution;							//needed to find '.' in solution
	dReturn = iSolution *1.0;					//convert int to double

												//return position of decimal
	int iPos = DoubleToString(dReturn, strSolution); 

	for (; iPos > iSolutionDec; iPos--)			//move decimal one place til corectly located
		dReturn /= 10.0;	

	return dReturn;								//return the square root of dIn
}

//dIn=input decimal
//fills Pairs[] array with digits pairs around the decimal
//stores position of 1st pair after the decimal in iFirstDecPair
//return how many digits in dIn
int SquareRoot::SplitDouble(double dIn, int Pairs[], int&iFirstDecPair)
{
	int iReturn = 0;							//#of digits in dIn
	int iIndex = 0;								//index of pairs array
	int iDecimalPosition = 0;					//location of "." in dIn
	string strIn;								//dIn converted to string
	int iStrIndex = 0;							//loop location in strIn

												//convert dIn to string, find decimal position
	iDecimalPosition = DoubleToString(dIn, strIn);
	iReturn = strIn.length();					//how many digits, for precision

												//parse strIn for number pairs
	if (iDecimalPosition % 2 != 0)				//if 1st pair is an odd # of digits
	{
		char c = strIn[0];						//get 1st char in string
		Pairs[0] = c - 0x30;					//convert ascii to decimal
		iStrIndex++;							//advance string index
		iIndex++;								//advance array index
	}
	while (iStrIndex < iDecimalPosition)		//get value left of decimal point
	{
		char c = strIn[iStrIndex++];			//1st char
		Pairs[iIndex] = (c - 0x30) * 10;		//convert to number, x 10
		c = strIn[iStrIndex++];					//2nd char
		Pairs[iIndex] += (c - 0x30);			//convert to number, units places
		iIndex++;								//advance array index
	}
	iStrIndex = iDecimalPosition + 1;			//advance past the '.'
	iFirstDecPair = iIndex;						//hold where the decimal digits start

	while (iStrIndex < strIn.length())			//get value right of decimal point
	{
		char c = strIn[iStrIndex++];			//1st char
		Pairs[iIndex] = (c - 0x30) * 10;		//convert to number, x 10
		c = strIn[iStrIndex++];					//2nd char
		Pairs[iIndex] += (c - 0x30);			//convert to number, units places
		iIndex++;								//advance array index
	}

	return iReturn;								//return number of didgits in dIn
}
int SquareRoot::DoubleToString(double dIn, string& strIn)
{
	TCHAR szIn[400];							//dIn converted to TCHAR

												//convert dIn to string read to parse
	_stprintf_s(szIn, TEXT("%.4f"), dIn);		//convert dIn to TCHAR
	wstring temp(szIn);							//TCHAR to stream
	string str(temp.begin(), temp.end());		//stream to string

	strIn = str;								//copy string to return

	return strIn.find(".");						//return location  of "."
}

int SquareRoot::FindHighestRoot(int iTarget, int iFactor)
{
	int iReturn = 0;							//return, should be less than root of iTarget
	int iRoot = 0;								//searching value

	int iBase = iFactor*iRoot;					//left multiplicand

	while (iTarget >= iBase*iRoot)				//loop until highest root found(may be =)
	{
		iReturn = iRoot++;						//set highest, inc search
		iBase = iFactor;						//reset base
		AppendDigits(iBase, iRoot);				//iBase=iBase+iRoot
	}
	return iReturn;
}

//if work =123 and append =456, then work =123456
void SquareRoot::AppendDigits(int & iWork, int iAppend)
{
	int iMove = iAppend;						//iMove has the # of digits that must be appended

	do {
		iWork *= 10;							//move work decimal over 1 place
		iMove /= 10;							//reduce the mover 1 place
			
	} while (iMove > 0);						//do until no more moves needed

	iWork += iAppend;							//add the appended digits
}
