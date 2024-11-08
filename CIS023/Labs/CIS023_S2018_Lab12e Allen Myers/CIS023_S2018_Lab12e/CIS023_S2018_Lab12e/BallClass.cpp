// Module:		BallClass.cpp
// Project:		CIS023_S2018_Lab12e
// Author:		Allen Myers
// Date:		May 14, 2018
// Purpose:		Implimentation file for BallClass
//

#include "stdafx.h"
#include "BallClass.h"


BallClass::BallClass()
{
	//start location
	rDim.left = 0;
	rDim.top = 0;

	//start size
	rDim.right = rDim.bottom = GetRandom(10, 30);

	//start direction and speed
	pDir.x = GetRandom(1, 15);
	pDir.y = GetRandom(1, 15);

	//set color
	r = GetRandom(0, 255);
	g= GetRandom(0, 255);
	b= GetRandom(0, 255);
}

BallClass::~BallClass()
{
}

void BallClass::Draw(HDC hdc)
{
	HPEN pen, oldPen;			//drawing pens

	pen = CreatePen(PS_SOLID, 2, RGB(r, g, b));	//black pen
	oldPen = (HPEN)SelectObject(hdc, pen);		//handle to old pen

	//do stuff here
	//draw circles
	Ellipse(hdc, rDim.left, rDim.top,rDim.right,rDim.bottom);


	//release the line pen
	SelectObject(hdc, oldPen);
	DeleteObject(pen);

}

void BallClass::Move(HWND hWnd)
{
	RECT clientRect;					//get client rectange
	GetClientRect(hWnd, &clientRect);

	rDim.left += pDir.x;				//move x
	rDim.right += pDir.x;
	rDim.top += pDir.y;					//move y
	rDim.bottom += pDir.y;

	//check bounce
	if (rDim.right > clientRect.right || rDim.left < 0)
		pDir.x *= -1;					//bounces backwards

	if (rDim.bottom > clientRect.bottom || rDim.top < 0)
		pDir.y = -1;					//bounces opposite


}

bool BallClass::Hit(POINT pShot)
{

	if (pShot.x >= rDim.left &&
		pShot.x <= rDim.right &&
		pShot.y >= rDim.top &&
		pShot.y <= rDim.bottom)
		return true;

	return false;
}

RECT BallClass::GetInvalidateRect()
{
	rReturn = rDim;				//initial location
	//expand rectangle
	rReturn.left -= abs(pDir.x + 0);
	rReturn.right += abs(pDir.x + 0);
	rReturn.top -= abs(pDir.y + 0);
	rReturn.bottom += abs(pDir.y+ 0);


	return rReturn;
}

void BallClass::SetPrevBall(BallClass * ball)
{
	prevBall = ball;
}

void BallClass::SetNextBall(BallClass * ball)
{
	nextBall = ball;
}

BallClass * BallClass::GetPrevBall()
{
	return prevBall;
}

BallClass * BallClass::GetNextBall()
{
	return nextBall;
}

LONG BallClass::GetRandom(LONG lMin, LONG lMax)
{
	random_device rd;								// non-deterministic generator
	mt19937 gen(rd());								// to seed mersenne twister.
	uniform_int_distribution<> dist(lMin, lMax);	// distribute results inside center rect

	return dist(gen);								// return random # between lMin and lMax inclusive

}
