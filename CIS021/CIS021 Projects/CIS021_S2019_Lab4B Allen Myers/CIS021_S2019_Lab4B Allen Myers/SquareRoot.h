//Project:	CIS021_S2019_Lab4B Allen Myers
//Module:	SquareRoot.h
//Author:	Allen Myers
//Date:		February 28th, 2019
//Purpose:	Finding a square root with "long division"
//			Calculates square root using "long division"
#pragma once

#define NUM_PAIRS 20

class SquareRoot
{
public:
	SquareRoot();
	~SquareRoot();

	double LongDivision(double);			//calc the square root

private:
	double dReturn;							//return value from LongDivision()

	int SplitDouble(double, int[], int&);	//split double into pairs
	int DoubleToString(double, string&);	//convert # to string, return pos of "."
	int FindHighestRoot(int, int);			//highest # less than root of value
	void AppendDigits(int&, int);			//append second # to first #(like a string)


};

