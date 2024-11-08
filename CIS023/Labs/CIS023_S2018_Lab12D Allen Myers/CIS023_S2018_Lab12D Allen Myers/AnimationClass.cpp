//Module:	AnimationClass.cpp
//Project:	CIS023_S2018_Lab12D Allen Myers
//Author:	Allen Myers
//Date:		May 9th, 2018
//Purpose:	Implementation file for animation class
//			animate a resource
//
#include "stdafx.h"
#include "AnimationClass.h"


AnimationClass::AnimationClass()
{

}

AnimationClass::AnimationClass(int idb)
{
	iResourceID = idb;		//store id of 1st framr
	iFrame = 0;				//initialize current frame
	pLocation.x = -214;		//start location
	pLocation.y = 0;		//

	pSize.x = 53;			//origination size of runner
	pSize.y = 90;			//

}


AnimationClass::~AnimationClass()
{
}

void AnimationClass::Draw(HDC hdc, HINSTANCE hInst)
{
	HBITMAP bmpRunner =
		LoadBitmap(hInst, MAKEINTRESOURCE(iResourceID));
	//create a memory device compatible with the above dc variable
	HDC hmemdc = CreateCompatibleDC(hdc);

	//select the new bitmpa
	HDC oldbmp =
		(HDC)SelectObject(hmemdc, bmpRunner);

	//copy this bits from the memory dc into the current dc
	//BitBlt(
	//	hdc,
	//	pLocation.x,				//location to start at
	//	pLocation.y,				//
	//	214,
	//	359,
	//	hmemdc,
	//	0,
	//	0,
	//	SRCCOPY);
	//copy this bits from the memory dc into the current dc and stretch the runner
	StretchBlt(
		hdc,	
		pLocation.x,				//destination location
		pLocation.y,
		pSize.x,					//destination size
		pSize.y,
		hmemdc,
		0,
		0,
		214,
		359,
		SRCCOPY
		);

	//restore the old bitmap
	SelectObject(hmemdc, oldbmp);
	DeleteDC(hmemdc);
	DeleteObject(bmpRunner);

}

void AnimationClass::NextFrame(HWND hWnd)
{
	iFrame++;			//next frame
	if (iFrame > 10)	//loop back to beginning
		iFrame = 1;

	//get resource ID
	switch (iFrame)
	{
	case 1:
		iResourceID = IDB_BITMAP1;
		break;
	case 2:
		iResourceID = IDB_BITMAP2;
		break;
	case 3:
		iResourceID = IDB_BITMAP3;
		break;
	case 4:
		iResourceID = IDB_BITMAP4;
		break;
	case 5:
		iResourceID = IDB_BITMAP5;
		break;
	case 6:
		iResourceID = IDB_BITMAP6;
		break;
	case 7:
		iResourceID = IDB_BITMAP7;
		break;
	case 8:
		iResourceID = IDB_BITMAP8;
		break;
	case 9:
		iResourceID = IDB_BITMAP9;
		break;
	case 10:
		iResourceID = IDB_BITMAP10;
		break;
	default:
		iResourceID = IDB_BITMAP1;
		break;

	}
	//advance location
	pLocation.x += 6;
	pLocation.y += 2;

	//if off screen, start over again
	RECT rClient;
	GetClientRect(hWnd, &rClient);

	if (pLocation.x > rClient.right || pLocation.y > rClient.bottom)	//if ran off the right or bottom of screen
	{
		//go back to original start point
		pLocation.x = -pSize.x;
		pLocation.y = 0;
	}

	//grow!!
	pSize.x++;
	pSize.y++;






}
