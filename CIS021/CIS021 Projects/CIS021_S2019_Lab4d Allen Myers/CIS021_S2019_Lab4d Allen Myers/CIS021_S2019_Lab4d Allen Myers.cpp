//Project:		CIS021_S2019_Lab4d Allen Myers
//Module:		CIS021_S2019_Lab4d Allen Myers.cpp
//Author:		Allen Myers
//Date:			March 7th, 2019
//Purpose:		Review creation of recursive functions.
//				Review list sorting.
//				Perform an insert sort of a randomized list.
//
#include "stdafx.h"

bool LoadFile(int A[])										//load array
{
	string strFileName =									//input file
		"CIS021_S2019_Lab4d_data.txt";
	ifstream inFile;										//file handle
	string strIn;											//line from file
	int iIndex = 0;											//array index

	inFile.open(strFileName);								//open the file

	if (inFile.is_open())									//did the file open?
	{
		getline(inFile, strIn);								//read first line

		while (inFile.good())								//read to end of file
		{
			A[iIndex++] = stoi(strIn.c_str());				//convert to int, store array
			getline(inFile, strIn);							//read next line
		}
		inFile.close();										//close the file
		return true;										//if true, load file
	}

	return false;											//file not found
}
int main()
{
	int Array[ARRAY_SIZE];										//file data
	SYSTEMTIME tLocalTimeBefore;							//for timing
	SYSTEMTIME tLocalTimeAfter;

	if (LoadFile(Array))									//load the array
	{
		int iASize = sizeof(Array) / sizeof(Array[0]);		//get # of elements

		//dump the list to the screen
		printf("Un-ordered list: \n");						//label output
		for (int i = 0;i < iASize;i++)
			printf("%d. %d\n", i, Array[i]);				//print list to screen	

		//before the sort time
		GetLocalTime(&tLocalTimeBefore);					//get start time


		//perform the loop sort////////////////////////////////////////////////
		MergeSortIterative MSI;								//iterative object
		MSI.MergeSort(Array, 0, iASize-1);					//perform the sort 


		/////////////////////////////////////////////////////////////////////

		//perform the recursive sort///////////////////////////////////////////
		MergeSortRecursive MSR;								//iterative object
		MSR.MergeSort(Array, 0, iASize - 1);				//perform the sort 


		/////////////////////////////////////////////////////////////////////

		//after the sort time
		GetLocalTime(&tLocalTimeAfter);						//get end time

		//dump the list to the screen
		printf("Ordered list: \n");							//label output
		for (int i = 0;i < iASize;i++)
			printf("%d. %d\n", i, Array[i]);				//print list to screen

		//show times
		printf("Time before sort:,%d:%d:%d\n",
			tLocalTimeBefore.wHour,
			tLocalTimeBefore.wMinute,
			tLocalTimeBefore.wSecond,
			tLocalTimeBefore.wMilliseconds
			);
		printf("Time after sort:,%d:%d:%d\n",
			tLocalTimeAfter.wHour,
			tLocalTimeAfter.wMinute,
			tLocalTimeAfter.wSecond,
			tLocalTimeAfter.wMilliseconds
		);
	}	

	
	cout << endl << endl;									//2 blank line
	system("Pause");										//pause before closing
    return 0;
}

