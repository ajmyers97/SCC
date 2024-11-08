//Project:		CIS021_S2019_HW6 Allen Myers
//Module:		CIS021_S2019_HW6 Allen Myers.cpp
//Author:		Allen Myers
//Date:			April 12th, 2019
//Purpose:		Interpret a sequence.
//				Produce computer code that loops through a sequence to find a solution.

#include "stdafx.h"
#include "iomanip"
#include "string.h"
#include "iostream"					//output to console
#include "math.h"					//math functions

using namespace std;				//standard namespaces


//loop to find the value for the sum from the
//lower bound to the upper bound
//start loop at "0" and increment until 
//hitting the upper bound.
int jLoop(int lowerBound, int upperBound)
{
	int jRetVal = 0;
		for (int i = lowerBound - 1; i <= upperBound; i++)
		{
			jRetVal += pow(i, 2);
		}
	return jRetVal;

}

int main()
{
	int lower = 1;					//lower limit
	int upper = 5;					//upper limit

	cout << "---Express the sum from J=1 to J=5 for the expression J^2---\n";
	cout << "The Value for the sum from J=1 to J=5 for the expression J^2 is: "<< jLoop(lower, upper);
	cout << endl;
	cout << "The steps are as follows:\n";
	int retVal = 0;					//increment value

	//loop through to find the values
	//sum of the incremented values is output
	for (int i = lower; i <= upper; i++)
	{
		retVal += pow(i, 2);		//add the values togethers
		cout << "if j= "<<i<<", the value is "<<retVal<<"\n";
	}

	cout << endl << endl;			//output lines
	system("Pause");				//pause before closing
    return 0;
}

