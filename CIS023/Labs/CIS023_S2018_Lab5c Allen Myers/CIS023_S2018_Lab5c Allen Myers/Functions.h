//Module:	Functions.h
//Project:	CIS023_S2018_Lab5c Allen Myers.cpp
//Author:	Allen Myers
//Date:		February 21st, 2018
//Puprose:	Header file for functions
//			Virtual Functions
//


#pragma once
class Functions
{
public:
	Functions();
	~Functions();

	static int Largest(int[], int, int&);	//find the max element in a finite sequence

	static int Search(int[], int, int);		//search for int in the array , returns -1 if not found
};

