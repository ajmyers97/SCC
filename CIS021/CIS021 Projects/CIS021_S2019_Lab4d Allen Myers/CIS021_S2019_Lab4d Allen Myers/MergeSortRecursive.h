//Project:		CIS021_S2019_Lab4d Allen Myers
//Module:		MergeSortRecursive.h
//Author:		Allen Myers
//Date:			March 7th, 2019
//Purpose:		Header file for MergeSortRecursive.h
//				Perform merge sort using recursion
//
#pragma once
class MergeSortRecursive
{
public:
	MergeSortRecursive();
	~MergeSortRecursive();
	void MergeSort(int[], int, int);						//

private:
	void DoMerge(int[], int, int, int);							//
};

