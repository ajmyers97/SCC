//Module:	LightsClass.h
//Project:	CIS021_S2019_HW9
//Author:	Allen Myers
//Date:		May 18th, 2019
//Purpose:	Header file for LightsClass.h
//			controls the lights
#pragma once

enum LIGHT_POS { GREEN, YELLOW, RED };

class LightsClass
{
public:
	LightsClass();
	LightsClass(int);
	~LightsClass();

	void Draw(HDC);							// answer WM_PAINT
	LIGHT_POS GetState();					// return state
	void Set();								// set color

private:

	RECT rDim;								// location (and size, shape)
	RECT rBulb[3];							// green, yellow, and red light bulbs
	LIGHT_POS state;						// GREEN, YELLOW, RED
	int iTiming;							// number of seconds since last light change

};

