//Project:	CIS021_S2019_Lab3a Alen Myers
//Module:	Functions.h
//Author:	Allen Myers
//Date:		Feb 5th, 2019
//Purpose:	Implementation file for Functions.cpp
//			Contains useful functions
//			Find the largest element of an array
//			Bubble sort an array
//			Find an item in an arry
//
#pragma once
class Functions
{
public:
	Functions();
	~Functions();

	static int Largest(int A[], int);		//find the largest item in the array
	static void Sort(int A[], int);			//perform a bubble sort on array
	static bool Search(int A[], int, int);		//find an item in the arry

};

