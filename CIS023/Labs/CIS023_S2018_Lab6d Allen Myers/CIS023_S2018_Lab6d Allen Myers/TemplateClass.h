//Module:	TemplateClass.h
//Project:	CIS023_S2018_Lab6d Allen Myers
//Author:	Allen Myers
//Date:		March 7th 2018
//Purpose:	Template Functions
//

#pragma once

#include<sstream>
#include<string>
using namespace std;


#define TCHAR_SIZE 128					//size of TCHAR Arrays

//compare two items of similiar basic data type
//returns -1 if first<second
//returns 0 if first=second
//returns 1 if first>second
template <class Type>					
Type CompareSize(Type x, Type y)
{
	if (x < y)					//is first value less than second?
		return -1;				
	else if (x == y)			//is first value equal to second?
		return 0;
	else return 1;				//default: first is less than seocnd


}
//convert specfied TCHAR to an integer, using specified base
//returns integer
//uses STOI, so invalud TCHAR returns 0 integer
template<class Type>
int TCHARtoInt(TCHAR*szIn,Type iBase)
{
	int iReturn = 0;				//return inetger

	if ((lstrlen(szIn) > 0) &&					//length of TCHAr must be greater than 0
		(lstrlen(szIn) < 10))					//and less than 10
	{
		wstring temp(szIn);						//convert TCHAR to stream
		string str(temp.begin(), temp.end());	//convert stream to string

		iReturn = stoi(str, NULL, iBase);		//convert string to INT, using specific base
	}





	return iReturn;					//return value



}

//CONVERTS INTEGER INTO A TCHAR
//MODIFIES PARAMETER TCHAR IN PLACE
//MAX 10 DIGIT INTEGER
template <class Type>
void IntToTCHAR(Type iIn, TCHAR*szIn)
{
	TCHAR szWork[10];				//temp TCHAR, limit of 10

	//clear
	memset(szIn, 0, sizeof(szIn));	//clear input TCHAR

	_stprintf_s(					//printf
		szWork,						//destination string
		TEXT("%i"),					//pattern
		iIn							//value
	);
	_tcscpy_s(						//copy TCHAR to TCHAR
		szIn,						//destination
		10,							//max # of chars to copy
		szWork						//source
	);


}

