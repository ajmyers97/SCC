//Project:	CIS021_S2019_Lab3a Alen Myers
//Module:	Functions.cpp
//Author:	Allen Myers
//Date:		Feb 5th, 2019
//Purpose:	Header file for Functions.cpp
//			Contains useful functions
//			Find the largest element of an array
//			Bubble sort an array
//			Find an item in an arry
//
#include "stdafx.h"
#include "Functions.h"


Functions::Functions()
{
}


Functions::~Functions()
{
}

int Functions::Largest(int A[], int iSize)
{
	int iMax = 0;			//previously largest value found
	//loop through the array
	for (int i = 0; i < iSize; i++)
		if (A[i] > iMax)		//is this value the largest so far??
			iMax = A[i];		//store the new largest value
	return iMax;				//return the largest value found
	return 0;
}

void Functions::Sort(int A[], int iSize)
{
	bool bMovement = true;		//true if an element moved in this loop
	while (bMovement)			//continue until nothing is beng swapped
	{
		bMovement = false;		//no movement has occured(yet)
		for (int i = 1; i < iSize; i++)	//loop through array
		{
			if (A[i] < A[i - 1])			//move?
			{
				int iTemp = A[i];			//hold the value during the swap
				A[i] = A[i - 1];			//move previous to current
				A[i - 1] = iTemp;			//move current to prevous
				bMovement = true;			//keep looping
			}
		}
	}





}

bool Functions::Search(int A[], int iSize, int iSearch)	//using a binary search
{
	int iIndex;								//index of array
	int iMin = 0, iMax = iSize - 1;			//limits

	iIndex = iSize / 2;						//start in the middle
	do										//forever
	{
		if (A[iIndex] < iSearch)			//move up
		{
			int iTemp = iIndex;				//min will be current index
			iIndex += (iMax - iIndex) / 2;	//set new index
			if (iMin == iTemp)					//check for no movement
				break;							//value not found
			else
				iMin = iTemp;				//old index is now min value

		}
		else if (A[iIndex] > iSearch)		//move up
		{
			int iTemp = iIndex;				//max will be current index
			iIndex -= (iIndex+iMin) / 2;	//set new index
			if (iMax == iTemp)					//check for no movement
				break;							//value not found
			else
				iMax = iTemp;				//old index is now max value

		}
		if (A[iIndex] == iSearch)			//found it!!
			return true;

	} while (true);							//next loop


	return false;
}
