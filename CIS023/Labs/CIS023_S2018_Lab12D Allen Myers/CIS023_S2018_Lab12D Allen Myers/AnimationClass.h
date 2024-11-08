//Module:	AnimationClass.h
//Project:	CIS023_S2018_Lab12D Allen Myers
//Author:	Allen Myers
//Date:		May 9th, 2018
//Purpose:	Header file for animation class
//			animate a resource
//

#pragma once
#include "Resource.h"				//include resource ID's, in this header only.
class AnimationClass
{
public:
	AnimationClass();
	AnimationClass(int);
	~AnimationClass();

	void Draw(HDC, HINSTANCE);		//answer WM_PAINT
	void NextFrame(HWND);			//next animation frame

private:
	int iResourceID;				//id of bitmap
	int iFrame;						//frame count
	
	POINT pLocation;				//(x,y)	location
	POINT pSize;					//size of the runner (x,y)


};

