//Module:	StateInfo.cpp
//Project:	CIS023_S2018_HW8 Allen Myers
//Author:	Allen Myers
//Date:		March 28th, 2018
//Purpose:	Load a file into a linked list.
//			Traverse the linked list in both directions.
//
#include "stdafx.h"
#include "StateInfo.h"


StateInfo::StateInfo()
{
}


StateInfo::~StateInfo()
{
}
StateInfo::StateInfo(string str1, string str2, string str3, string str4, string str5, string str6)
{
	size_t pRetVal;					///return value from mbstowcs_s

	mbstowcs_s(						//copy string into tchar
		&pRetVal,					//return values
		szState,					//destination TCHAR
		TCHAR_SIZE,					//size of TCHAR
		str1.c_str(),				//source of string
		TCHAR_SIZE					//max number of chars to copy
	);
	mbstowcs_s(						//copy string into tchar
		&pRetVal,					//return values
		szCapitol,					//destination TCHAR
		TCHAR_SIZE,					//size of TCHAR
		str2.c_str(),				//source of string
		TCHAR_SIZE					//max number of chars to copy
	);
	mbstowcs_s(						//copy string into tchar
		&pRetVal,					//return values
		szNickname,					//destination TCHAR
		TCHAR_SIZE,					//size of TCHAR
		str3.c_str(),				//source of string
		TCHAR_SIZE					//max number of chars to copy
	);
	mbstowcs_s(						//copy string into tchar
		&pRetVal,					//return values
		szBird,					//destination TCHAR
		TCHAR_SIZE,					//size of TCHAR
		str4.c_str(),				//source of string
		TCHAR_SIZE					//max number of chars to copy
	);
	mbstowcs_s(						//copy string into tchar
		&pRetVal,					//return values
		szFlower,					//destination TCHAR
		TCHAR_SIZE,					//size of TCHAR
		str5.c_str(),				//source of string
		TCHAR_SIZE					//max number of chars to copy
	);
	mbstowcs_s(						//copy string into tchar
		&pRetVal,					//return values
		szTree,					//destination TCHAR
		TCHAR_SIZE,					//size of TCHAR
		str6.c_str(),				//source of string
		TCHAR_SIZE					//max number of chars to copy
	);

	prevNode = nullptr;				//clear next and prev pointers
	nextNode = nullptr;


}

TCHAR * StateInfo::GetState()
{
	return szState;
}

TCHAR * StateInfo::GetCapitol()
{
	return szCapitol;
}

TCHAR * StateInfo::GetNickname()
{
	return szNickname;
}

TCHAR * StateInfo::GetBird()
{
	return szBird;
}

TCHAR * StateInfo::GetFlower()
{
	return szFlower;
}

TCHAR * StateInfo::GetTree()
{
	return szTree;
}

void StateInfo::SetPrev(StateInfo * node)
{
	prevNode = node;
}

void StateInfo::SetNext(StateInfo * node)
{
	nextNode = node;
}

StateInfo * StateInfo::GetPrev()
{
	return prevNode;
}

StateInfo * StateInfo::GetNext()
{
	return nextNode;
}