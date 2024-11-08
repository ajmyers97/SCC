//Project:	CIS021_S2019_Lab5c Allen Myers.cpp
//Module:	CIS021_S2019_Lab5c Allen Myers.cpp
//Author:	Allen Myers
//Date:		March 21st, 2019
//Purpose:	Discrete Probability
//			Learn how to code probability formulas.
//			Predict outcomes based on probability formulas.
//			Discover limitations of computer pseudorandom number generation.
//

#include "stdafx.h"
#include <iomanip>							//formatting
#include<iostream>							//console i/o
#include<string>							//string library
#include<random>							//random number gen
#include <fstream>							//file i/o

using namespace std;						//standard namespaces

//random number generator
int GetRandomNumber(int iMin, int iMax)
{
	random_device rd;						//non-deterministic generator
	mt19937 gen(rd());						//to seed mersenne twister

											//to distribute min to max
	uniform_int_distribution<>dist(iMin, iMax);

	return dist(gen);						//return random number
}

int main()
{
	//test the random number generator
	//printf("%d", GetRandomNumber(1, 10));
	//End test the random number generator

/*
	//Coin Flip Probability
	int iHeads = 0;							//count of how mnay heads
	int iTails = 0;							//count of how many tails
	int iFlips = 1000000;						//number of times to flip

	for (int i = 0;i < iFlips;i++)
	{
		//count heads or tails if results are 50/50
		//(GetRandomNumber(0, 1) == 0) ? iHeads++ : iTails++;

		//show bias where heads has higher likelihood
		//(GetRandomNumber(0, 2)<2) ? iHeads++ : iTails++;
	}
	//display results
	printf("The coin was flipped %d times.\n", iFlips);
	printf("Number of Heads: %d\n", iHeads);
	printf("Number of Tails: %d\n", iTails);

	//End Coin Flip Probability

	//Begin Probability of a pair of dice(standard, 1-6)
	printf("How many times does a pair of dice roll a value of 7?\n\n");
	for (int i = 0;i < 10;i++)				//roll the dice 10 times and see what happens
	{
		printf("Die 1 = %d,Die 1 = %d\n", GetRandomNumber(1, 6), GetRandomNumber(1, 6));
	}
	cout << endl << endl;					//blank line

		int iRolls = 1000;					//how many times to roll
		int iSuccessful = 0;				//how mnay rolls =7

		for (int i = 0;i < iRolls; i++)
		{
			int iDie1 = GetRandomNumber(1, 6);
			int iDie2 = GetRandomNumber(1, 6);
			if (iDie1 + iDie2 == 7)
				iSuccessful++;
		}
		printf("Total rolls: %d\n", iRolls);
		printf("Total 7's:   %d\n", iSuccessful);
		printf("Ratio of success: %.4f\n",
			iSuccessful / (iRolls*1.0));
	//End Probability of a pair of dice(standard, 1-6)
*/
		cout << endl << endl;					//blank line
		cout << endl << endl;					//blank line

/*	
	//Begin Lottery Winner! (Pick 6 Lottery)
		int iSelect[6];							//pick 6 lottery
		int iLottery[6];						//lottery numbers
		int iRounds = 100000;						//games played
		int iWins = 0;							//number of winning tickets
		int iMatches = 0;						//0 to 6, how many correct picks
		int iBestGame = 0;						//best # of matches ever

		printf("Select 6 unique lottery number between 1 and 60, enter a space between numbers: ");
		for (int i = 0;i < 6;i++)
			cin >> iSelect[i];
		for (int iGames = 0;iGames < iRounds;iGames++)//play games
		{
			memset(iLottery, sizeof(iLottery), 0);//clear winning numbers
			for (int i = 0;i < 6;i++)			  //generate winning numbers
			{
				bool bUnique;
				do {
					iLottery[i] = GetRandomNumber(1, 60);	//get a number
					bUnique = true;
					for (int j = 0;j < i;j++)				//look for a matching number
						if (iLottery[i] == iLottery[j])
						{
							bUnique = false;
							break;
						}
				} while (!bUnique);

			}
			iMatches = 0;								//no matches so far
			for (int i = 0;i < 6;i++)					//look for matches
				for (int j = 0;j < 6;j++)				//i through user picks, j through #'s
					if (iSelect[i] == iLottery[j])
						iMatches++;
			if (iMatches > iBestGame)					//save best game
				iBestGame = iMatches;

			if (iMatches == 6)							//save winners
				iWins++;


		}
		printf("Number of games:      %d\n", iRounds);
		printf("Number of wins:       %d\n", iWins);
		printf("Best Game:            %d\n", iBestGame);
		printf("Ratio of wins:        %.4f\n", iWins / (iRounds*1.0));
		//END Lottery Winner! (Pick 6 Lottery)
*/
		cout << endl << endl;					//blank line
		cout << endl << endl;					//blank line

		//demonstrating the Monte Carlo Algorithm
		printf("Demonstrating the Monte Carlo Algorithm\n\n");

		const int SAMPLE_SIZE = 1000;					//size of test array
		const int LOW = 0;								//iMin
		const int HIGH = 10000;							//iMax
		const int NUM_TESTS = 132;						//number of times to test
		const int THRESHOLD = 10;						//fail if value below threshold

		int iTestArr[SAMPLE_SIZE];						//fill with random numbers
		bool bPass = true;								//did Monte Carlo pass/fail?
		int iFailureCount = 0;							//items in array below THRESHOLD

		//fill array with random numbers
		for (int i = 0;i < SAMPLE_SIZE;i++)
		{
			iTestArr[i] = GetRandomNumber(LOW, HIGH);
			if (iTestArr[i] < THRESHOLD)				//100% failure testing
				iFailureCount++;
		}
//		printf("%d", iFailureCount);

		//perform Monte Carlo Test
		for (int i = 0; i < NUM_TESTS;i++)
		{
			int iIndex = GetRandomNumber(0, SAMPLE_SIZE);
			int iTest = iTestArr[iIndex];
			if (iTest < THRESHOLD)
			{
				bPass = false;
//				iFailureCount++;
			}
		}

		//display results
		printf("Threshold testing\n");
		printf("Pass/Fail: ");
		bPass ? cout << "Pass\n" : cout << "Fail\n";
		printf("Failure Count: %d", iFailureCount);




	cout << endl << endl;					//blank line
	system("Pause");						//pause
    return 0;
}

