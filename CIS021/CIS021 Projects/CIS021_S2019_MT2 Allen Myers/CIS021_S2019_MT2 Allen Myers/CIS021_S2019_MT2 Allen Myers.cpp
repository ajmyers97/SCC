//Project:		CIS021_S2019_MT2 Allen Myers
//Module:		CIS021_S2019_MT2 Allen Myers.cpp
//Author:		Allen Myers
//Date:			April 11th, 2019
//Purpose:		Demonstrate a Theorem.
//				Produce computer code that produces Pascal's Triangle.
//

//headers
#include "stdafx.h"
#include "iomanip"					//name
#include "iostream"					//output to console

using namespace std;				//standard namespaces

//needs to return the r-values from 0 to 10
void getRValues(int lower, int upper)
{
	for (int i = lower;i < upper;i++)
	{
		cout << "	r=" << i;
	}
}

//needs to return the n-values from 0 to 10
//output the n values to console
//display the values of the pascal triangle(zVal)
void getNValues(int lower, int upper)
{
	int zVal = 1;
	for (int i = lower; i < upper;i++)
	{
		cout << "n=" << i << "	"						//math is  working here
			<< zVal			<<"	"
			<< (zVal * i) << "	"
			<< (zVal * i)	<< "	"					//math is not working here...
			<< (zVal * i) << "	"
			<< (zVal * i) << "	"
			<< (zVal * i) << "	"
			<< (zVal * i) << "	"
			<< (zVal * i) << "	"
			<< (zVal * i) << "	"
			<< (zVal * i) << "	"
			<< (zVal * i) << "	"
			<< endl;
	}
	zVal++;
}


int main()
{
	cout << "----Pascals Triangle----\n";

	//call the functions
	getRValues(0,11);						//return the r values
	cout << endl;
	getNValues(0,11);						//return the n and z values


	cout << endl << endl;			//output blank line
	system("Pause");				//pause before closing
    return 0;
}

