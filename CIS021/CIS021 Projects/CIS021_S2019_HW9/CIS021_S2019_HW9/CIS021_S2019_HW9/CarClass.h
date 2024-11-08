//Module:	CarClass.h
//Project:	CIS021_S2019_HW9
//Author:	Allen Myers
//Date:		May 18th, 2019
//Purpose:	Header file for CarClass.h
//			controls the cars
#pragma once
class CarClass
{
public:
	CarClass();
	~CarClass();

	void Draw(HDC);							// draw the car
	void Move();							//move the car


private:
	RECT rDim;								// location and size rect
	int r, g, b;							// color


	int GetRandomInt(int, int);				// return random integer
};

