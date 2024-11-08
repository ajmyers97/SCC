//Project:		CIS021_S2019_Lab4d Allen Myers
//Module:		MergeSortIterative.cpp
//Author:		Allen Myers
//Date:			March 7th, 2019
//Purpose:		Implementation file for MergeSortIterative.h
//				Perform merge sort using loop
#include "stdafx.h"
#include "MergeSortIterative.h"


MergeSortIterative::MergeSortIterative()
{
}


MergeSortIterative::~MergeSortIterative()
{
}

void MergeSortIterative::MergeSort(int A[], int iLeft, int iRight)
{
	int iMid;										//between left and right

	if (iRight <= iLeft)							//check for bad comparisons
		return;

	vector<pair<int, int>>list;						//create vector pair
	vector<MergePosInfo> mlist;						//define with struct

	list.push_back(pair<int, int>(iLeft, iRight));	//create the list

	MergePosInfo info;								//create struct variable

	while (1)										//endless loop
	{
		if (list.size() == 0)						//is done?
			break;
		iLeft = list.back().first;					//set new left
		iRight = list.back().second;				//set new right
		list.pop_back();							//retrieve and pop
		iMid = (iRight + iLeft) / 2;				//calc new midpoint

		if (iLeft < iRight)							//if list is still bigger than 1 item
		{
			info.iLeft = iLeft;						//get left
			info.iRight = iRight;					//get right
			info.iMid = iMid + 1;					//advance mid

			mlist.push_back(info);					//save left, right, and mid

													//save bottom half of array
			list.push_back(pair<int, int>(iLeft, iMid));	

													//save top half of array
			list.push_back(pair<int, int>((iMid + 1), iRight));

		}

	}
	for (int i = mlist.size() - 1;i >= 0;i--)				//merge this part of the list
		//load values from mutable list into array
		DoMerge(A, mlist[i].iLeft, mlist[i].iMid, mlist[i].iRight);

}

void MergeSortIterative::DoMerge(int A[], int iLeft, int iMid, int iRight)
{
	int temp[ARRAY_SIZE];											//temp array to hold martially merged list

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
