//Project:		CIS021_S2019_Lab5d Allen Myers
//Module:		CIS021_S2019_Lab5d Allen Myers.cpp
//Author:		Allen Myers
//Date:			March 26th, 2019
//Purpose:		Discrete Probability
//				Learn how to code multi-level probabilistic.
//				Understand the formulas used to prove Baye's Theorem.

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

	const int GREEN = 0;								//index
	const int RED = 1;
	int Box1[9];										//box1
	int Box2[7];										//box2

	int iSelectionBox;									//bob's box selection
	int iSelectionItem;									//bob's ball selection

	int iCountSelections = 0;							//count of selections made by bob
	int iRedSelections = 0;								//count of red ball instances
	int iRedBoxes[2] = { 0,0 };							//how many reds for box1, box2

	//load the arrays
	Box1[GetRandomInt(0, 8)] = GREEN;					//load the 1st green ball
	do {
		iSelectionItem = GetRandomInt(0, 8);			//look for another location
	} while (Box1[iSelectionItem]==GREEN);
	Box1[iSelectionItem] = GREEN;						//load a green ball into that location

	for (int i = 0;i < 9;i++)							//load the rest of the box with red balls
		if (Box1[i] != GREEN)							//if not already loaded with a green ball
			Box1[i] = RED;								//load it with a red ball

	//load 2nd box
	Box2[GetRandomInt(0, 6)] = RED;						//load a red bal into a random location
	for (int i = 0;i < 2;i++)							//find 2 more locations for red balls
	{
		do {
			iSelectionItem = GetRandomInt(0, 6);		//look for an unassigned spot	
		} while (Box2[iSelectionItem]==RED);			//
		Box2[iSelectionItem] = RED;						//fill the spots
	}
	for (int i = 0;i < 7;i++)							//load the rest of the box with green balls
		if (Box2[i] != RED)								//if not already loaded with a red ball
			Box2[i] = GREEN;							//load it with a green ball

	//check boxes to make sure they loaded okay
	for (int i = 0;i < 9;i++)
		printf("Box1, Pos: %d, ID:%d, Ball: %s\n",
			i,
			Box1[i],
			Box1[i]==RED?"RED": "GREEN");				//
	cout << endl;										//output a blank line
	for (int i = 0;i < 7;i++)
		printf("Box2, Pos: %d, ID:%d, Ball: %s\n", 
			i, 
			Box2[i],
			Box2[i] == GREEN ? "GREEN" : "RED");		//
	cout << endl << endl;								//output a blank line
	//tell bob to make a bunch of selections, go bob go
	for (int j = 0;j < 10;j++)
	{
		iCountSelections = 0;							//count of selections made by bob
		iRedSelections = 0;								//count of red ball instances
		iRedBoxes[0] =iRedBoxes[1]=0;					//how many reds for box1, box2

		for (int i = 0;i < 100000;i++)
		{
			//select a box, bob
			iSelectionBox = GetRandomInt(0, 1);				//random box
			//printf("Bob randomly selects the %s box. \n",
			//	iSelectionBox == 0 ? "First" : "Second");
			//select a ball, bob
			if (iSelectionBox == 0)							//if first box was selected
				iSelectionItem = GetRandomInt(0, 8);		//select from 1st box
			else
				iSelectionItem = GetRandomInt(0, 6);		//select from 2nd box
		/*	printf("Bob randomly selects the ball from position %d in the %s box. \n\n",
				iSelectionItem,
				iSelectionItem == 0 ? "first":"second");*/

				//count
			iCountSelections++;								//total selections
			if (iSelectionBox == 0)
			{
				if (Box1[iSelectionItem] == RED)
				{
					iRedSelections++;
					iRedBoxes[0]++;
				}
			}
			else {
				if (Box2[iSelectionItem] == RED)
				{
					iRedSelections++;
					iRedBoxes[1]++;
				}
			}
		}
		//display bob's counts
		printf("It looks like Bob made %d selections. \n", iCountSelections);
		printf("Red Balls:		%d\n", iRedSelections);
		printf("Red, Box1:		%d\n", iRedBoxes[0]);
		printf("Red, Box2:		%d\n", iRedBoxes[1]);
		cout << endl << endl;								//output a blank line

	}


	cout << endl << endl;								//output a blank line
	system("Pause");									//pause before closing
    return 0;
}

