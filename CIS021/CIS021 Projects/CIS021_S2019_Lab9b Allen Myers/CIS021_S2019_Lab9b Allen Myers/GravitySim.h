//Module:	GravitySim.cpp
//Project:	CIS021_S2019_Lab9b Allen Myers.cpp
//Author:	Allen Myers
//Date:		May 16th, 2019
//Purpose:	Header file for GravitySim.h
#pragma once
//structure to hold rectangle
struct dRECT
{
double left;
double top;;
double right;
double bottom;

};
struct dPOINT
{
	double x;
	double y;

};
class GravitySim
{
public:
	GravitySim(HWND);				//initialize
	~GravitySim();

	void Draw(HDC);					//answer WM_PAINT
	bool Move(HWND);				//update location
	RECT GetInvalidateRect();		//return RECT to paint

private:
	dRECT dDim;						//dimensions of graphic object
	dPOINT dSpeed;					//speed of object
	int r, g, b;					//color of obejct

	int GetRandomInt(int, int);		//return random int
};

