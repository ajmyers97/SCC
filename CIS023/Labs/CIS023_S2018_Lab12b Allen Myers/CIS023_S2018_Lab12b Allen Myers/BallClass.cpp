//Module:	BallClass.cpp
//Project:	CIS023_S2018_Lab12b Allen Myers
//Author:	Allen Myers
//Date:		May 2nd, 2018
//Purpose:	Implementation file for BallClass
//			Draw Circles
#include "stdafx.h"
#include "BallClass.h"


BallClass::BallClass()
{						
	rLocation.left = 0;			//ball starts at upper left
	rLocation.top = 0;
	rLocation.right = 100;		//ball is 100*100 size
	rLocation.bottom = 100;
	iSpeed = 2;					//move pixels per tick
}


BallClass::~BallClass()
{
}

void BallClass::Draw(HDC hdc)
{
	HPEN pen, oldPen;										//handle to the pens
	
	pen = CreatePen(PS_SOLID, 2, RGB(0x00, 0x00, 0xFF));	//pen is blue and 2 pixels wide
	//pen = CreatePen(PS_DASHDOT, 0, RGB(0x00, 0x00, 0xFF));	//pen is blue and 2 pixels wide

	oldPen = (HPEN)SelectObject(hdc, pen);					//select pen and store the old pen
		
	Ellipse(hdc,											//draw an ellipse
		rLocation.left, 
		rLocation.top, 
		rLocation.right, 
		rLocation.bottom);						

	Rectangle(hdc, 400, 500, 500, 600);						//draw a rectangle

	Arc(hdc, 500,75,600,125,750,175,800,200);				//draw an arc

	//release the line pen
	SelectObject(hdc, oldPen);
	DeleteObject(pen);


}

void BallClass::Move(HWND hWnd)
{
	RECT rClient;
	GetClientRect(hWnd, &rClient);						//get main window coordinates


	if (rLocation.bottom >= rClient.bottom)				//did we hit the bottom of window?
		iSpeed *= -1;									//reverse direction



	//move ispeed number of pixels
	rLocation.left+= iSpeed;
	rLocation.top += iSpeed;
	rLocation.bottom += iSpeed;
	rLocation.right += iSpeed;
}
