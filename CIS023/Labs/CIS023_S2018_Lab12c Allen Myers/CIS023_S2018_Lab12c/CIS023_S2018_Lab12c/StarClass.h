//Module:	StarClass.h
//Project:	CIS023_S2018_Lab12c
//Author:	Allen Myers
//Date:		May 7th, 2018
//Purpose:	Header File for Star Class.
//			Draw the Star
#pragma once
class StarClass
{
public:
	StarClass();
	StarClass(HWND);				// override constructor
	~StarClass();

	StarClass* GetNextStar();		// movement along linked list
	StarClass* GetPrevStar();		
	void SetNextStar(StarClass*);
	void SetPrevStar(StarClass*);
	void Draw(HDC);					//draw the stars on the screen, answers WM_PAINT
	bool Move(HWND);				//change rDim, location of star
	RECT GetInvalidateRect();		//

private:

	StarClass* nextStar;			// pointer to next node in list
	StarClass* prevStar;			// pointer to previous node in list
	LONG GetRandom(LONG, LONG);		//return a random number between the min and max limits

	RECT rDim;						//dimensions of star
	RECT rReturn;					//rectangle return value

	LONG r, g, b;					//colors
	POINT pSpeed;					//speed/direction
	POINT pCenter;					//center of window

	int iFrame;						//frame count


};

