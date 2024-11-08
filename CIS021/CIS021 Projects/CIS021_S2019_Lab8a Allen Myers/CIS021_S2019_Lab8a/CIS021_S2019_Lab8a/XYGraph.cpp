#include "stdafx.h"
#include "XYGraph.h"


XYGraph::XYGraph()
{
}


XYGraph::~XYGraph()
{
}

XYGraph::XYGraph(HWND hWndIn)
{
	hWnd = hWndIn;									// store handle to main window
	bShowLines = false;								// don't show lines between points until user asks for them

	iPoints = 0;									//initialize index to pArray[]
	memset(pArray, 0, sizeof(pArray));				
}

void XYGraph::Draw(HDC hdc)
{
	RECT clientRect;								// client rect of main window
	POINT centerPt;									// center of the client rect

	GetClientRect(hWnd, &clientRect);				// get client rect
	centerPt.x = clientRect.right / 2;				// find center point
	centerPt.y = clientRect.bottom / 2;

	// create pens
	HPEN penMain = CreatePen(PS_SOLID, 2, RGB(0x7F, 0x7F, 0x7F));	// center grid lines
	HPEN penGrad = CreatePen(PS_SOLID, 1, RGB(0xEF, 0xEF, 0xEF));	// secondary grid lines
	HPEN penLine = CreatePen(PS_SOLID, 2, RGB(0x00, 0x00, 0xFF));	// blue pen for parabola

	// select main pen
	HPEN oldPen = (HPEN)SelectObject(hdc, penMain);

	// draw main grid lines
	MoveToEx(hdc, clientRect.left, centerPt.y, NULL);
	LineTo(hdc, clientRect.right, centerPt.y);
	MoveToEx(hdc, centerPt.x, clientRect.top, NULL);
	LineTo(hdc, centerPt.x, clientRect.bottom);

	// select gradian pen
	SelectObject(hdc, penGrad);

	// draw gradians
	for (int i = centerPt.y - 50; i > 0; i -= 50) // draw y grids above center
	{
		MoveToEx(hdc, clientRect.left, i, NULL);
		LineTo(hdc, clientRect.right, i);
	}
	for (int i = centerPt.y + 50; i < clientRect.bottom; i += 50) // draw y grids below center
	{
		MoveToEx(hdc, clientRect.left, i, NULL);
		LineTo(hdc, clientRect.right, i);
	}
	for (int i = centerPt.x - 50; i > 0; i -= 50) // draw x grids left of center
	{
		MoveToEx(hdc, i, clientRect.top, NULL);
		LineTo(hdc, i, clientRect.bottom);
	}
	for (int i = centerPt.x + 50; i < clientRect.right; i += 50) // draw x grids right of center
	{
		MoveToEx(hdc, i, clientRect.top, NULL);
		LineTo(hdc, i, clientRect.bottom);
	}

	// return to old pen and delete pens
	SelectObject(hdc, oldPen);
	DeleteObject(penMain);
	DeleteObject(penGrad);
	DeleteObject(penLine);

	DrawPoints(hdc);								// draw the datum points

	if (bShowLines)									// if user asked for lines
		DrawLines(hdc);								// draw the lines between the points

}
//load data from input file into pArray[]
void XYGraph::LoadArray(double x, double y)
{
	if (iPoints < POINTS_MAX)						//do not exceed values
		pArray[iPoints].x = x;						//store values
		pArray[iPoints].y = y;

		iPoints++;									//advance to next point in file
}

void XYGraph::ShowLines()
{
	bShowLines = true;								// next time Draw() shows the lines
	CalcPath();										//calculate shortest path
	InvalidateRect(hWnd, NULL, true);				// force paint
}

void XYGraph::DrawPoints(HDC hdc)
{
	RECT clientRect;								// client rect of main window
	POINT centerPt;									// center of the client rect
	HBRUSH brush = nullptr;							// brushes for drawing circles (points)
	HBRUSH oldBrush;
	HFONT hFont = nullptr;							// font to display text
	HFONT hOldFont;
	TCHAR szWork[TCHAR_SIZE];						// text to diaplay


	GetClientRect(hWnd, &clientRect);				// get client rect
	centerPt.x = clientRect.right / 2;				// find center point
	centerPt.y = clientRect.bottom / 2;

	brush = CreateSolidBrush(RGB(0x00, 0x00, 0x00));// black brush
	oldBrush = (HBRUSH)SelectObject(hdc, brush);

	hFont = (HFONT)GetStockObject(ANSI_FIXED_FONT);	// get stock font handle
	hOldFont = (HFONT)SelectObject(hdc, hFont);		// set font

	_stprintf_s(szWork, TEXT("Data Points"));		//column title
	TextOut(hdc, 10, 10, szWork, _tcslen(szWork));	//title

	for (int i = 0;i < iPoints;i++)
	{
		int x = centerPt.x + (pArray[i].x * 50);	//50 pt offset for gridlines
		int y = centerPt.y - (pArray[i].y * 50);	//y values are upside down

		Ellipse(hdc,								//draw a dot
			x - 3, y - 3, x + 3, y + 3);			//size of 3

		_stprintf_s(szWork, TEXT("%d"), i);			//label for each dot
		TextOut(hdc,								//label the dot
			x + 5, y + 2, szWork, _tcslen(szWork));	//
		//lists the points in the upper-left of the window for reference
		_stprintf_s(szWork,							//text to display
			TEXT("%d.(%.2f,%.2f)"),					//pattern
			i,										//point number
			pArray[i].x,							//x values
			pArray[i].y);							//y values

		TextOut(hdc,								//display
			15,30+i*20,								//column in the upper left
			szWork,_tcslen(szWork));				//	
	}






	SelectObject(hdc, hOldFont);					// Restore the original font.
	DeleteObject(hFont);
	SelectObject(hdc, oldBrush);					// return to original brush
	DeleteObject(brush);
} // DrawPoints

void XYGraph::DrawLines(HDC hdc)
{
	RECT clientRect;								// client rect of main window
	POINT centerPt;									// center of the client rect

	HPEN penLine = nullptr;							// pens for drawing lines
	HPEN oldPen;
	HFONT hFont = nullptr;							// font to display text
	HFONT hOldFont;
	TCHAR szWork[TCHAR_SIZE];						// text to diaplay

	GetClientRect(hWnd, &clientRect);				// get client rect
	centerPt.x = clientRect.right / 2;				// find center point
	centerPt.y = clientRect.bottom / 2;

	penLine = CreatePen(PS_SOLID, 2, RGB(0xFF, 0x00, 0x00));	// start with a red pen
	oldPen = (HPEN)SelectObject(hdc, penLine);
	hFont = (HFONT)GetStockObject(ANSI_FIXED_FONT);	// get stock font handle
	hOldFont = (HFONT)SelectObject(hdc, hFont);		// set font

	_stprintf_s(szWork, TEXT("Shortest Path"));		//column title
	TextOut(hdc, clientRect.right-175, 10, szWork, _tcslen(szWork));

	for (int i = 0;i < iPoints;i++)					//all filled data points in array
	{
		if (i < iPoints - 1)						//need to display text to last item
		{
			int x = centerPt.x + (pPath[i].x * 50);	//current point
			int y = centerPt.y - (pPath[i].y * 50);	//current point

			int x1 = centerPt.x + (pPath[i + 1].x * 50);	//next point
			int y1 = centerPt.y - (pPath[i + 1].y * 50);	//next point

			MoveToEx(hdc, x, y, NULL);				//draw lines
			LineTo(hdc, x1, y1);					//

		}
		//list the data points(from pPath) in a colum on the upper left of the window
		_stprintf_s(szWork,							//text
			TEXT("%d.(%.2f,%.2f)"),
			iPath[i],
			pPath[i].x,
			pPath[i].y);
		TextOut(hdc,			
			15,
			30 + i * 20,
			szWork,_tcslen(szWork));
	
	}



	// return to old pen and font
	SelectObject(hdc, oldPen);
	DeleteObject(penLine);
	SelectObject(hdc, hOldFont);
	DeleteObject(hFont);

} // DrawLines

//calulate shortest path along the array
void XYGraph::CalcPath()
{
	int iShortest;										//index to next closest point
	double dDist;										//distance to next, closest point
	double dTempDist;									//distance to another point

	memcpy(pPath, pArray, sizeof(pPath));				//deep copy array to path

	for (int i = 0;i < POINTS_MAX;i++)					//preset path
		iPath[i] = i;

	for (int i = 0;i < iPoints;i++)						//sort entire path array
	{
		dDist = DBL_MAX;								//benchmark to next point

		for (int j = i + 1;j < iPoints;j++)				//search rest of array to find shortest distance
		{
			dTempDist = GetDist(pPath[i], pPath[j]);	//measure distance between points
			if (dTempDist < dDist)						//is this shorter distance?
			{
				dDist = dTempDist;						//new shortest
				iShortest = j;
			}
		}
			if (iShortest > i + 1)						//dow we need to swap points?
			{
				DPOINT pTemp = pPath[i + 1];			//swap shortest with next point
				pPath[i + 1] = pPath[iShortest];
				pPath[iShortest] = pTemp;

				int iTemp = iPath[i + 1];				//swap shortest with next
				iPath[i + 1] = iPath[iShortest];	
				iPath[iShortest] = iTemp;			
			}
		
	}
}

//calculate the distance between 2 points
double XYGraph::GetDist(DPOINT p1, DPOINT p2)
{
	double dDistance = 0.0;								//return value
	double dLegA = 0.0;									//1st leg
	double dLegB = 0.0;									//2nd leg

	dLegA = abs(p1.x - p2.x);							//length of first leg
	dLegB = abs(p1.y - p2.y);							//length of second leg

	//pythagorean theorem
	dDistance = sqrt(pow(dLegA, 2) + (pow(dLegB, 2)));

	return dDistance;
}
