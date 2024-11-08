//Module:	CIS021_S2019_Lab4a Allen Myers.cpp
//Project:	CIS021_S2019_Lab4a Allen Myers
//Author:	Allen Myers
//Date:		Feb 26th, 2019
//Purpose:	
#pragma once
class SquareRoot
{
public:
	SquareRoot();
	~SquareRoot();

	bool isPerfectSquare(int, int&);								//true if value is a perfect square
	bool FindSquareRootsOfPerfectSquareFactors(int, int&, int&);	//find factors
	bool FindRoots(int, int&, int&);								//find roots when not a perfect square
	void Estimate(int, int&, int&);									//last chance

	double LongDivision(double);									//long division

private:
	bool bReturn;													//return value
	double dReturn;													//return  value for long division

	int SplitDouble(double, int);									//return a pair
	void AppendDigits(int&, int);									//move number left, add second number
	int FindHighestRoot(int, int);									//highest # less than root of a value


};

