//Module:	CrossHairClass.cpp
//Project:	CIS023_S2018_Lab12e
//Author:	Allen Myers
//Date:		May 14th, 2018
//Purpose:	Implementation File for CrossHairClass
//			Controls screen sight(cross hairs)
//


#include "stdafx.h"
#include "CrossHairClass.h"


CrossHairClass::CrossHairClass()
{
}

CrossHairClass::CrossHairClass(HWND hWnd)
{
	RECT clientRect;					//get client rectange
	GetClientRect(hWnd, &clientRect);


	iSize = 10;
	pLocation.x = clientRect.right / 2;	//middle of window
	pLocation.y = clientRect.bottom / 2;

	pReturn = {-1, -1};						//blank return


}


CrossHairClass::~CrossHairClass()
{
}

void CrossHairClass::Draw(HDC hdc)
{

	HPEN pen, oldPen;			//drawing pens

	pen = CreatePen(PS_SOLID, 2, RGB(0, 0, 0));	//black pen
	oldPen = (HPEN)SelectObject(hdc, pen);		//handle to old pen

	//do stuff here
	//circle around the crosshair
	Ellipse(hdc, pLocation.x - iSize,
		pLocation.y - iSize,
		pLocation.x + iSize,
		pLocation.y + iSize);
	//draw verticle line
	MoveToEx(hdc, pLocation.x, pLocation.y-iSize, NULL);
	LineTo(hdc, pLocation.x, pLocation.y + iSize);

	//draw horizontal line
	MoveToEx(hdc, pLocation.x - iSize, pLocation.y, NULL);
	LineTo(hdc, pLocation.x + iSize, pLocation.y);


	//release the line pen
	SelectObject(hdc, oldPen);
	DeleteObject(pen);


}

POINT CrossHairClass::KeyPressed(LONG lKey)
{
	switch (lKey)
	{
	case VK_LEFT: pLocation.x--;break;		//move left
	case VK_RIGHT: pLocation.x++;break;		//move right
	case VK_UP: pLocation.y--;break;		//move upd
	case VK_DOWN: pLocation.y++;break;		//move down
	case VK_SPACE: return pLocation;break;	//"fire, return position
	}


	return pReturn;			//return blank
}

RECT CrossHairClass::GetInvalidateRect()
{
	rReturn.left = pLocation.x - (iSize + 2);
	rReturn.right = pLocation.x + (iSize + 2);
	rReturn.top = pLocation.y - (iSize + 2);
	rReturn.bottom = pLocation.y + (iSize + 2);



	return rReturn;
}
