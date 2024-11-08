//Module:	BookClass.cpp
//Project:	CIS023_S2018_Lab5B Allen Myers
//Author:	Allen Myers
//Date:		February 14th 2018
//Purpose:	Implementation file for bookclass
//			Data storage and abstraction for pointer to object
//
#include "stdafx.h"
#include "BookClass.h"


BookClass::BookClass()
{
}


BookClass::~BookClass()
{
}

void BookClass::SetName(string strIn)
{
	strName = strIn;
}

void BookClass::SetCover(string strIn)
{
	strCover = strIn;
}

void BookClass::SetCategory(string strIn)
{
	strCategory = strIn;
}

void BookClass::SetGenres(string strIn)
{
	strGenres = strIn;
}

string BookClass::GetName()
{
	return strName;
}

string BookClass::GetCover()
{
	return strCover;
}

string BookClass::GetCategory()
{
	return strCategory;
}

string BookClass::GetGenres()
{
	return strGenres;
}
