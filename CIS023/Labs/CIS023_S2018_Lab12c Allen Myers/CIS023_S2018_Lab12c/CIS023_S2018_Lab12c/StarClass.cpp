//Module:	StarClass.cpp
//Project:	CIS023_S2018_Lab12c
//Author:	Allen Myers
//Date:		May 7th, 2018
//Purpose:	Imp file for StarClass.
//
#include "stdafx.h"
#include "StarClass.h"


StarClass::StarClass()
{
}

StarClass::StarClass(HWND hWnd)
{
	//get client window dimensions
	RECT rClient;
	GetClientRect(hWnd, &rClient);
	
	POINT pCenter;
	pCenter.x = rClient.right / 2;			//find the center of window
	pCenter.y = rClient.bottom / 2;			//





	rDim.left = pCenter.x;						//set start location
	rDim.top = pCenter.y;						
	//rDim.right = rDim.left + GetRandom(1, 16);	//set size
	//rDim.bottom = rDim.top + GetRandom(1,16);

	rDim.right = rDim.left+10;								//tiny starts
	rDim.bottom = rDim.top+10;

	pSpeed.x = GetRandom(-6, 6);				//set the speed
	pSpeed.y = GetRandom(-6, 6);				

	r = GetRandom(0, 255);						//set color
	g = GetRandom(0, 255);
	b = GetRandom(0, 255);	

	iFrame = 0;									//initialize frame


}

StarClass::~StarClass()
{
}

StarClass * StarClass::GetNextStar()
{
	return nextStar;
}

StarClass * StarClass::GetPrevStar()
{
	return prevStar;
}

void StarClass::SetNextStar(StarClass* star)
{
	nextStar = star;
}

void StarClass::SetPrevStar(StarClass * star)
{
	prevStar = star;
}

void StarClass::Draw(HDC hdc)
{
	HBRUSH brush = CreateSolidBrush(RGB(r,g,b));	//create a sold brush
	HBRUSH oldBrush;								//old brush for return
	oldBrush = (HBRUSH)SelectObject(hdc, brush);	//set brush

	//draw a filled object
	//FillRect(hdc, &rDim, brush);
	Ellipse(hdc, rDim.left, rDim.top, rDim.right, rDim.bottom);



	//delete object and retuern to old color
	SelectObject(hdc, oldBrush);
	DeleteObject(brush);
}

bool StarClass::Move(HWND hWnd)
{
	//get client window dimensions
	RECT rClient;
	GetClientRect(hWnd, &rClient);

	rDim.right++;
	rDim.bottom++;

	//move according to speed
	rDim.top += pSpeed.y;
	rDim.left += pSpeed.x;
	rDim.bottom += pSpeed.y;
	rDim.right += pSpeed.x;

	//if start hit an edge then tell main module to delete it
	if (rDim.right< 0 || rDim.bottom<0 || rDim.left>rClient.right || rDim.top>rClient.bottom)
		return false;



	return true;				//good move, keep going
}

RECT StarClass::GetInvalidateRect()
{
	rReturn = rDim;				//set default return value

	if (pSpeed.x < 0)
		rReturn.right -=pSpeed.x;
	if (pSpeed.x > 0)
		rReturn.left -= pSpeed.x;
	if (pSpeed.y < 0)
		rReturn.bottom -= pSpeed.y;
	if (pSpeed.y > 0)
		rReturn.top -= pSpeed.y;

	return rReturn;				//return invalidate rectangle
}

LONG StarClass::GetRandom(LONG  lMin, LONG lMax)
{
	random_device rd;			//nondeterministic generator
	mt19937 gen(rd());			//seed mrseenne twister
	uniform_int_distribution<>Make(lMin, lMax);




	return Make(gen);			//return random number between lMin and lMax, inclusive.
}
