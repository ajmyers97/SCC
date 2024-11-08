//Project:		CIS021_S2019_Lab5e Allen Myers
//Module:		CIS021_S2019_Lab5e Allen Myers.cpp
//Author:		Allen Myers
//Date:			March 28th, 2019
//Purpose:		Generate random variables.
//				Demonstrate variable independence.
//				Show the probability of like vs.unlike values in independent random variables.

#include "stdafx.h"
#include <iostream>										// i/o
#include<iomanip>										//formatting
#include<string>										//string library
#include<random>										//random number gen

using namespace std;

//return random number between iMin and iMax
int GetRandomInt(int iMin, int iMax)
{
	random_device rd;
	mt19937 gen(rd());
	uniform_int_distribution<>dist(iMin, iMax);

	return dist(gen);
}

int main()
{
	int w, x, y, z;										//elements of the set W
	int NumTries = 1000000;								//1,000,000 runs
	int iMatches = 0;									//number of matches

	printf("Generating random values for X and Y 100,000 times\n\n");

	printf("W	X	Y	Z	Matches\n");						//roller header

	for (int i = 0;i < NumTries;i++)					//loop
	{
		cout << "\x0d";									//format roller
		w = GetRandomInt(0, 99);						//random value
		x = GetRandomInt(0, 99);						//random value
		y = GetRandomInt(0, 99);						//random value
		z = GetRandomInt(0, 99);						//random value

		if (w==x && x == y && x==z)										//do they match?
			iMatches++;

//		cout << w << "	" << x << "	" << y << "	" << z << "	" << iMatches;		//roller
	}
	//display results
	printf("\nResults: \n");
	printf("	Number of matches:	%d\n", iMatches);
	printf("	Number of tries:	%d\n", NumTries);
	
	printf("	Success Rate:		%.2f%%\n", (iMatches*1.0/NumTries*1.0)*100.00);








	cout << endl << endl;								//output blank line
	system("Pause");									//pause before closing
    return 0;
}

