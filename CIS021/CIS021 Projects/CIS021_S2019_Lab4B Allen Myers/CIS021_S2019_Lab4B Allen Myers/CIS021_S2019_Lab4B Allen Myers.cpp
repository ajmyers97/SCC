//Project:	CIS021_S2019_Lab4B Allen Myers
//Module:	CIS021_S2019_Lab4B Allen Myers.cpp
//Author:	Allen Myers
//Date:		February 28th, 2019
//Purpose:	Finding a square root with "long division"
//
#include "stdafx.h"


int main()
{
	double dSquare;					//user input
	SquareRoot SR;					//calc object

	//user input value
	printf("Finding the Square Root using Long Division\n\n");				//prompt for user input
	printf("Enter a positive decimal value: ");								//ask for input
	cin >> dSquare;															//get user input	

	if (dSquare <= 0.0)
		return 0;
	if (dSquare >= MAXINT)
	{
		printf("Input out of range.\n\n");
			system("Pause");
		return 0;
	}
	//calc
	printf("The square root of %2f is %2f\n", dSquare, SR.LongDivision(dSquare));
	cout << endl << endl;
	system("Pause");
	return 0;




    return 0;
}

