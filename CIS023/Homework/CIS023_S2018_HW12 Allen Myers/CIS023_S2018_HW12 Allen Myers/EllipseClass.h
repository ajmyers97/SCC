//Module:	EllipseClass.h
//Project:	CIS023_S2018_HW12
//Author:	Allen Myers
//Date:		May 10th, 2018
//Purpose:	
#pragma once
class EllipseClass
{
public:
public:
	EllipseClass();
	EllipseClass(HWND);				// override constructor
	~EllipseClass();

	EllipseClass* GetNextStar();		// movement along linked list
	EllipseClass* GetPrevStar();
	void SetNextStar(EllipseClass*);
	void SetPrevStar(EllipseClass*);
	void Draw(HDC);					//draw the stars on the screen, answers WM_PAINT
	bool Move(HWND);				//change rDim, location of star
	RECT GetInvalidateRect();		//

private:

	EllipseClass* nextStar;			// pointer to next node in list
	EllipseClass* prevStar;			// pointer to previous node in list
	LONG GetRandom(LONG, LONG);		//return a random number between the min and max limits

	RECT rDim;						//dimensions of star
	RECT rReturn;					//rectangle return value

	LONG r, g, b;					//colors
	POINT pSpeed;					//speed/direction
	POINT pCenter;					//center of window

	int iFrame;						//frame count
};

