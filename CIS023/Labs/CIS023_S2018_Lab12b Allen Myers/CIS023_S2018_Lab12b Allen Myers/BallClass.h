//Module:	BallClass.h
//Project:	CIS023_S2018_Lab12b Allen Myers
//Author:	Allen Myers
//Date:		May 2nd, 2018
//Purpose:	Header file for BallClass
//			Draw Circles
#pragma once
class BallClass
{
public:
	BallClass();
	~BallClass();

	void Draw(HDC);			//HDC=handle to main window, draw the ellipse 
	void Move(HWND);			//
private:
	int iSpeed;				//how many pixels to move per tick on the clock

	RECT rLocation;			//rectangle of drawing object
};

