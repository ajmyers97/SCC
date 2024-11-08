// Project:		CIS021_S2019_Lab6c
// Module:		CIS021_S2019_Lab6c.cpp
// Author:		Mark Berrett
// Date:		March 26, 2019
// Purpose:		Header file for VennDiagram.cpp
//
// Update		2
// Author:		
// Date:		
// Modification: Completed 3rd Circle
// 

#pragma once

#define CHAR_SIZE 6									// width, in pixels, of a char in ANSI_FIXED_FONT

class VennDiagram
{
public:
	VennDiagram();
	~VennDiagram();

	VennDiagram(HWND);								// overloaded constructor that stores hWnd

	void SetNumCircles(int);						// set iCircles
	void SetOverlap(bool);							// set bOverlapping
	void SetTitles(int, TCHAR*);					// set szTitle[0] and szTitle[1]
	void SetLabels(int, TCHAR*);					// set szLabels[0] through szLabels[6]

	int GetNumCircles();							// return iCircles
	bool GetOverlap();								// return bOverlapping
	TCHAR* GetTitles(int);							// return szTitle[0] or szTitle[1]
	TCHAR* GetLabels(int);							// return szLabels[0] through szLabels[6]

	void Draw(HDC);									// called by WM_PAINT
	void NewDiagram();								// new values set, tell main window to paint

private:
	HWND hWnd;										// handle to main window
	int iCircles;									// number of circles in diagram (up to 3)
	bool bOverlapping;								// do the circles overlap
	TCHAR szTitle[2][TCHAR_SIZE];					// top-most title and sub-title in main window
	TCHAR szLabels[7][TCHAR_SIZE];					// labels

	RECT locationRECT[3];							// (x,y,x1,y1) of up to 3 circles
	COLORREF colors[3];								// RGB of up to 3 circles
	RECT leadLinesRECT[7];							// lead lines to text
	POINT headingsPT[2];							// locations of 2 heading lines of text
	POINT labelsPT[7];								// locations of up to 7 text lines at end of leadlines

	void SetDimensions();							// set sizes and location, called from Draw()
};

