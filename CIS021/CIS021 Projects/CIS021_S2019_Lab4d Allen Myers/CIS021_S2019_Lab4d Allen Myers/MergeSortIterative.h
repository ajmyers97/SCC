//Project:		CIS021_S2019_Lab4d Allen Myers
//Module:		MergeSortIterative.h
//Author:		Allen Myers
//Date:			March 7th, 2019
//Purpose:		Header file for MergeSortIterative.cpp
//				Perform merge sort using loop
#pragma once
class MergeSortIterative
{
public:
	MergeSortIterative();
	~MergeSortIterative();

	void MergeSort(int[], int, int);			//perform the sort

private:
	struct MergePosInfo							//keep track of sort
	{
		int iLeft;
		int iMid;
		int iRight;
	};
	void DoMerge(int[], int, int, int);			//loop to perform the sort
};

