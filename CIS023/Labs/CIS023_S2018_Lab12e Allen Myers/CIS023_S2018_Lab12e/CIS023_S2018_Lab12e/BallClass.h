// Module:		BallClass.h
// Project:		CIS023_S2018_Lab12e
// Author:		Allen Myers
// Date:		May 14, 2018
// Purpose:		Header file for BallClass.cpp
//				Draw and move GDI circles
//

#pragma once
class BallClass
{
public:
	BallClass();
	~BallClass();

	void Draw(HDC);					//answer WM_PAINT
	void Move(HWND);				//answer WM_TIMER_MOVE
	bool Hit(POINT);						//did crosshair hit object?
	RECT GetInvalidateRect();		//return rReturn

	void SetPrevBall(BallClass*);
	void SetNextBall(BallClass*);
	BallClass * GetPrevBall();
	BallClass * GetNextBall();

private:
	RECT rDim;						//location/size
	POINT pDir;						//direction(x,y)
	LONG r, g, b;					//colors

	RECT rReturn;					//invalidate rect

	BallClass * nextBall;
	BallClass * prevBall;

	LONG GetRandom(LONG, LONG);
};

