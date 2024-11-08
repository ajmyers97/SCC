//Module:	BookClass.h
//Project:	CIS023_S2018_Lab5B Allen Myers
//Author:	Allen Myers
//Date:		February 14th 2018
//Purpose:	Header file for bookclass
//
#pragma once
class BookClass
{
public:
	BookClass();
	~BookClass();

	void SetName(string);						//store strname
	void SetCover(string);						//store strcover
	void SetCategory(string);					//store strcategory
	void SetGenres(string);						//store strgenre

	string GetName();							//return strname
	string GetCover();							//return strcover
	string GetCategory();						//return strcategory
	string GetGenres();							//return strgenres

private:
	string strName;								//hold file data
	string strCover;
	string strCategory;
	string strGenres;

};

