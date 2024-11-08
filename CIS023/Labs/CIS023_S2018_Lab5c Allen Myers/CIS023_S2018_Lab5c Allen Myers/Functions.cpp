//Module:	Functions.cpp
//Project:	CIS023_S2018_Lab5c Allen Myers.cpp
//Author:	Allen Myers
//Date:		February 21st, 2018
//Puprose:	Implementation file for functions
//			Virtual Functions
//

#include "stdafx.h"
#include "Functions.h"


Functions::Functions()
{
}


Functions::~Functions()
{
}

int Functions::Largest(int A[], int iSize, int &iLargest)
{
	int iPos = -1;			//0 is the first position in a listbox
	iLargest = -1;			//assumes array only contains positive int's

	for (int i = 0;i < iSize;i++)	//loop through array
	{
		if (A[i] > iLargest)		//is current # greater than stored largest?
		{
			iLargest = A[i];		//save this new largest numbers
			iPos = i;				//remeber where we found it
		}
	}


	return iPos;					//return the position of the largest number
}

int Functions::Search(int A[], int iSize, int iSearch)
{
	for (int i = 0;i < iSize;i++)			//look through the list
		if (A[i] == iSearch)					//foudn it?
			return i;						//return the index of the value

	return -1;				//value not found
}
