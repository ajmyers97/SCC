//Project:		CIS021_S2019_Lab4d Allen Myers
//Module:		MergeSortRecursive.cpp
//Author:		Allen Myers
//Date:			March 7th, 2019
//Purpose:		Implementation file for MergeSortRecursive.h
//				Perform merge sort using recursion
#include "stdafx.h"
#include "MergeSortRecursive.h"


MergeSortRecursive::MergeSortRecursive()
{
}


MergeSortRecursive::~MergeSortRecursive()
{
}

void MergeSortRecursive::MergeSort(int A[], int iLeft, int iRight)
{
	int iMid;

	if (iRight > iLeft)										//wind up end ends when list split in two's
	{
		iMid = (iRight + iLeft) / 2;						//find middle of current list
			
		MergeSort(A, iLeft, iMid);							//wind-split list, unwind-feed split
		MergeSort(A, (iMid + 1), iRight);					//wind-split list, unwind-feed split

		DoMerge(A, iLeft, (iMid + 1), iRight);				//sort, put the list back together
	}

}

void MergeSortRecursive::DoMerge(int A[], int iLeft, int iMid, int iRight)
{
	int temp[ARRAY_SIZE];									//temp array to hold martially merged list

	int left_end, num_elements, tmp_pos;					//indices of temp array

	left_end = (iMid - 1);									//set initial values
	tmp_pos = iLeft;										//
	num_elements = (iRight - iLeft + 1);					//

	while ((iLeft <= left_end) && (iMid <= iRight))
	{
		if (A[iLeft] <= A[iMid])							//sort values
			temp[tmp_pos++] = A[iLeft++];
		else
			temp[tmp_pos++] = A[iMid++];
	}
	while (iLeft <= left_end)								//merge left side values into temp array
		temp[tmp_pos++] = A[iLeft++];

	while (iMid <= iRight)									//merge right side values into temp array
		temp[tmp_pos++] = A[iMid++];

	for (int i = 0;i < num_elements;i++)					//insert merged list back into original array
		A[iRight--] = temp[iRight];

}
