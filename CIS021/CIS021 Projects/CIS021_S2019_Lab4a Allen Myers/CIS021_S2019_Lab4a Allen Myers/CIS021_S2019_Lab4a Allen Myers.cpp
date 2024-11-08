//Module:	CIS021_S2019_Lab4a Allen Myers.cpp
//Project:	CIS021_S2019_Lab4a Allen Myers
//Author:	Allen Myers
//Date:		Feb 26th, 2019
//Purpose:	Learn how to find a square root arithmetically.
//			Produce a computer program that finds a square root.

#include "stdafx.h"


int main()
{
	UINT uSquare;							//user input
	int iFac1, iFac2;						//integer factors
	SquareRoot SR;							//sqaure root solver
//////////
	printf("Finding a square root using factorization\n\n");	
	printf("Enter a positive integer(16 or above): ");			//ask for user input
	cin >> uSquare;
	if (uSquare < 16)
		return 0;
	if (SR.isPerfectSquare(uSquare, iFac1))						//is user input a perfect square
	{
		printf("%d is a perfect square\n", uSquare);
		printf("The square root of %d is %d\n", uSquare, iFac1);

		if (SR.FindSquareRootsOfPerfectSquareFactors(uSquare, iFac1, iFac2))
		{
			printf("The square factors are %d and %d \n", iFac1, iFac2);
			printf("The square root of %d is sqrt(%d) x sqrt(%d)= %d x %d =%d\n",
				uSquare, iFac1 * iFac1, iFac2*iFac2,iFac1, iFac2, iFac1*iFac2);
		}
		else
			printf("%d is not a perfect square", uSquare);
	}
	else
		printf("%d is not a perfect square", uSquare);
///////////

	////list perfect squares from 16 to 1 million
	//	for (uSquare = 16; uSquare <= 1000000, uSquare++)
	//	{
	//		if (SR.isPerfectSquare(uSquare, iFac1))			//found one?
	//		//	if (SR.FindSquareRootsOfPerfectSquareFactors(
	//		//		uSquare, iFac1, iFac2))
	//		//		printf("Sqrt(%d)=%d\n", uSquare, iFac1*iFac2);
	//			printf("Sqrt(%d)=%d\n", uSquare, iFac1);
	//	}

	if (!SR.isPerfectSquare(uSquare, iFac1))					//here is the else
	{
		if (SR.FindRoots(uSquare, iFac1, iFac2))
		{
			printf("The square root of %d is %d x sqrt(%d) \n",
			uSquare, iFac1, iFac2);
		}
		else
		{
			printf("Cannot reduce %d \n", uSquare);
		
			SR.Estimate(uSquare, iFac1, iFac2);					//last ditch effort
			printf("The square of %d is greaterthan %d and less than %d\n", iFac1, iFac2);
		}
	}
	double dSquare;
	double dRoot = 0.0;
	printf("\n Finding a square root using Long Division\n\n");
	printf("Enter a positive decimal value: ");					//get user input
	cin >> dSquare;

	printf("The squre root of %.4f is %.4f",
		dSquare, SR.LongDivision(dSquare));

	cout << endl << endl;					//blank line
	system("Pause");						//pause before closing
    return 0;
}

