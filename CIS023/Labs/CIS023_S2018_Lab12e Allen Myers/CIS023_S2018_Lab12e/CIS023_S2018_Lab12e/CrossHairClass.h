//Module:	CrossHairClass.h
//Project:	CIS023_S2018_Lab12e
//Author:	Allen Myers
//Date:		May 14th, 2018
//Purpose:	Header File for CrossHairClass.cpp
//			Controls screen sight(cross hairs)
//


#pragma once
class CrossHairClass
{
public:
	CrossHairClass();
	CrossHairClass(HWND);		//overloaded constructor
	~CrossHairClass();

	void Draw(HDC);				//answer to WM_PAINT
	POINT KeyPressed(LONG);		//answer to WM_KEYDOWN
	RECT GetInvalidateRect();	//return rReturn


private:
	int iSize;					//size of graphic
	POINT pLocation;			//(x,y)
	POINT pReturn;				//blank return,KeyPressed()
	RECT rReturn;				//invalidate rect
};

