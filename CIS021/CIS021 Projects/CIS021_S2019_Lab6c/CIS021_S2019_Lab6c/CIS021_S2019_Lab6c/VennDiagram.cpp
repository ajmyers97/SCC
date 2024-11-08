// Project:		CIS021_S2019_Lab6c
// Module:		CIS021_S2019_Lab6c.cpp
// Author:		Mark Berrett
// Date:		March 26, 2019
// Purpose:		Implementation file for VennDiagram.cpp
//
// Update		2
// Author:		
// Date:		
// Modification: Completed 3rd Circle
// 


#include "stdafx.h"
#include "VennDiagram.h"


VennDiagram::VennDiagram()
{
	iCircles = 0;							// default, no circles in this diagram
}


VennDiagram::~VennDiagram()
{
}

VennDiagram::VennDiagram(HWND hWndIn)
{
	hWnd = hWndIn;								// store handle to main window

	iCircles = 0;								// default 0 circles
	bOverlapping = false;						// overlapping off
	for (int i = 0; i < 2; i++)					// erase titles
		memset(szTitle[1], 0, TCHAR_SIZE);
	for (int i = 0; i < 2; i++)					// erase labels
		memset(szLabels[1], 0, TCHAR_SIZE);

	// circle colors
	colors[0] = RGB(0xFF, 0x00, 0x00);			// red
	colors[1] = RGB(0x00, 0xFF, 0x00);			// green
	colors[2] = RGB(0x00, 0x00, 0xFF);			// blue

}

void VennDiagram::SetNumCircles(int iNumCircles)
{
	iCircles = iNumCircles;
}

void VennDiagram::SetOverlap(bool bOverIn)
{
	bOverlapping = bOverIn;
}

void VennDiagram::SetTitles(int iIndex, TCHAR * szTitleIn)
{

	_tcscpy_s(szTitle[iIndex], szTitleIn);
}

void VennDiagram::SetLabels(int iIndex, TCHAR* szLabelIn)
{
	_tcscpy_s(szLabels[iIndex], szLabelIn);
}

int VennDiagram::GetNumCircles()
{
	return iCircles;
}

bool VennDiagram::GetOverlap()
{
	return bOverlapping;
}

TCHAR * VennDiagram::GetTitles(int iIndex)
{
	return szTitle[iIndex];
}

TCHAR * VennDiagram::GetLabels(int iIndex)
{
	return szLabels[iIndex];
}

void VennDiagram::Draw(HDC hdc)
{
	HBRUSH brush = nullptr;					// brushes for drawing circles
	HBRUSH oldBrush;
	HPEN pen, oldPen;						// pens for drawing lead lines
	HFONT hFont, hOldFont;					// font selection for mono-spaced text

	SetDimensions();						// set location values

	switch (iCircles)
	{
	case 1:									// single circle
		/////////////////// Draw Circle
		brush = CreateSolidBrush(colors[0]);
		oldBrush = (HBRUSH)SelectObject(hdc, brush);

		Ellipse(hdc,						// draw circle
			locationRECT[0].left,
			locationRECT[0].top,
			locationRECT[0].right,
			locationRECT[0].bottom);

		SelectObject(hdc, oldBrush);		// return to original brush
		DeleteObject(brush);

		/////////////////// Draw lead lines

		// create pens to draw lead lines
		pen = CreatePen(PS_SOLID, 2, RGB(0x7F, 0x7F, 0x7F));
		oldPen = (HPEN)SelectObject(hdc, pen);

		// draw line
		MoveToEx(hdc, leadLinesRECT[0].left, leadLinesRECT[0].top, NULL);
		LineTo(hdc, leadLinesRECT[0].right, leadLinesRECT[0].bottom);

		// return to old pen
		SelectObject(hdc, oldPen);
		DeleteObject(pen);

		/////////////////// Draw Text
		hFont = (HFONT)GetStockObject(ANSI_FIXED_FONT); // get stock font handle

		hOldFont = (HFONT)SelectObject(hdc, hFont);	// set font

		TextOut(hdc,							// diplay label
			labelsPT[0].x,
			labelsPT[0].y,
			szLabels[0],
			lstrlen(szLabels[0]));

		// Restore the original font.        
		SelectObject(hdc, hOldFont);

		break;
	case 2:										// 2 circles
		/////////////////// Draw Circle
		SetBkMode(hdc, TRANSPARENT);			// set background mode to tranparent

		for (int i = 0; i < 2; i++)
		{
			// select brush, hatch if overlapping circles, solid if not
			if (bOverlapping)
				i ?
				brush = CreateHatchBrush(HS_BDIAGONAL, colors[i]) :
				brush = CreateHatchBrush(HS_FDIAGONAL, colors[i]);
			else
				brush = CreateSolidBrush(colors[i]);

			oldBrush = (HBRUSH)SelectObject(hdc, brush);

			Ellipse(hdc,						// draw circle
				locationRECT[i].left,
				locationRECT[i].top,
				locationRECT[i].right,
				locationRECT[i].bottom);

			SelectObject(hdc, oldBrush);
			DeleteObject(brush);
		}
		SetBkMode(hdc, OPAQUE);					// reset background mode

		/////////////////// Draw lead lines

		// create pens to draw lead lines
		pen = CreatePen(PS_SOLID, 2, RGB(0x7F, 0x7F, 0x7F));
		oldPen = (HPEN)SelectObject(hdc, pen);

		// draw lines
		for (int i = 0; i < 2; i++)				// draw 1st 2 lead lines
		{
			MoveToEx(hdc, leadLinesRECT[i].left, leadLinesRECT[i].top, NULL);
			LineTo(hdc, leadLinesRECT[i].right, leadLinesRECT[i].bottom);
		}
		if (bOverlapping)						// 3 leads line if they are overlapping
		{
			MoveToEx(hdc, leadLinesRECT[2].left, leadLinesRECT[2].top, NULL);
			LineTo(hdc, leadLinesRECT[2].right, leadLinesRECT[2].bottom);
		}

		// return to old pen
		SelectObject(hdc, oldPen);
		DeleteObject(pen);

		/////////////////// Draw Text
		hFont = (HFONT)GetStockObject(ANSI_FIXED_FONT); // get stock font handle

		hOldFont = (HFONT)SelectObject(hdc, hFont);	// set font

		TextOut(hdc,								// diplay first label
			labelsPT[0].x,
			labelsPT[0].y,
			szLabels[0],
			lstrlen(szLabels[0]));
		TextOut(hdc,								// diplay second label
			labelsPT[1].x,
			labelsPT[1].y,
			szLabels[1],
			lstrlen(szLabels[1]));
		if (bOverlapping)
			TextOut(hdc,							// diplay third label
				labelsPT[2].x,
				labelsPT[2].y,
				szLabels[2],
				lstrlen(szLabels[2]));

		// Restore the original font.        
		SelectObject(hdc, hOldFont);

		break;
	case 3:											// 3 circles
	/////////////////// Draw Circle
		SetBkMode(hdc, TRANSPARENT);				//set background mode to transparent
		for (int i = 0;i < 3; i++)					//3 circles
		{
			//select brush
			if (bOverlapping)						//hatch brush
			{
				switch (i)
				{
				case 0: brush = CreateHatchBrush(HS_VERTICAL, colors[i]);break;
				case 1: brush = CreateHatchBrush(HS_BDIAGONAL, colors[i]);break;
				case 2: brush = CreateHatchBrush(HS_FDIAGONAL, colors[i]);break;
				}
			}
			else									//else not overlapping, solid brush
				brush = CreateSolidBrush(colors[i]);

			oldBrush = (HBRUSH)SelectObject(hdc,brush);//select brush

			Ellipse(hdc,							//draw circle
				locationRECT[i].left,
				locationRECT[i].top,
				locationRECT[i].right,
				locationRECT[i].bottom
				);
			SelectObject(hdc, oldBrush);			//delete brush
			DeleteObject(brush);
		}
		SetBkMode(hdc, OPAQUE);						//reset background mod

	/////////////////// Draw lead lines

		//create pens to draw lead lines
		pen = CreatePen(PS_SOLID, 2, RGB(0x7F, 0x7F, 0x7F));
		oldPen = (HPEN)SelectObject(hdc, pen);

		//draw lines
		for (int i = 0;i < 3;i++)					//1st 3 lines
		{
			MoveToEx(hdc, leadLinesRECT[i].left, leadLinesRECT[i].top, NULL);
			LineTo(hdc, leadLinesRECT[i].right, leadLinesRECT[i].bottom);

		}
		if (bOverlapping)							//2nd 3 lines, if overla[ped
		{
			for (int i = 3; i < 7;i++)
			{
				MoveToEx(hdc, leadLinesRECT[i].left, leadLinesRECT[i].top, NULL);
				LineTo(hdc, leadLinesRECT[i].right, leadLinesRECT[i].bottom);
			}
		}


		//return old pen
		SelectObject(hdc, oldPen);
		DeleteObject(pen);


	/////////////////// Draw Text
		hFont = (HFONT)GetStockObject(ANSI_FIXED_FONT);	//get a fixed font
		hOldFont = (HFONT)SelectObject(hdc, hFont);		//select font

		for (int i = 0;i < 3;i++)
		{
			TextOut(hdc,
				labelsPT[i].x,
				labelsPT[i].y,
				szLabels[i],
				lstrlen(szLabels[i]));
		}

		if(bOverlapping)
			for(int i=3;i<7;i++)
					TextOut(hdc,
						labelsPT[i].x,
						labelsPT[i].y,
						szLabels[i],
						lstrlen(szLabels[i]));
				

		//restore original font
		SelectObject(hdc, hOldFont);

		break;

}

	/////////////////// Draw Title Text
	hFont = (HFONT)GetStockObject(ANSI_FIXED_FONT); // get stock font handle

	hOldFont = (HFONT)SelectObject(hdc, hFont);	// set font

	for (int i = 0; i < 2; i++)
		TextOut(hdc,							// diplay titles
			headingsPT[i].x,
			headingsPT[i].y,
			szTitle[i],
			lstrlen(szTitle[i]));

	// Restore the original font.        
	SelectObject(hdc, hOldFont);

}

void VennDiagram::NewDiagram()
{
	InvalidateRect(hWnd, NULL, TRUE);	// tell main window to paint
}

void VennDiagram::SetDimensions()
{
	RECT clientRect;								// main window rectangle
	GetClientRect(hWnd, &clientRect);				// get client rect

	POINT centerPT;									// center of the client rect
	centerPT.x = clientRect.right / 2;
	centerPT.y = clientRect.bottom / 2;

	int iCircleRadius = 0;							// size of the circles (they are all the same size)
	POINT circlePt[3];								// center point of the circles

	headingsPT[0] = {								// text location for top heading
		centerPT.x - (lstrlen(szTitle[0]) / 2) * CHAR_SIZE,
		20 };
	headingsPT[1] = {								// text location for second heading
		centerPT.x - (lstrlen(szTitle[1]) / 2) * CHAR_SIZE,
		50 };

	// clear locations
	for (int i = 0; i < 3; i++)
		locationRECT[i] = { 0,0,0,0 };				// 0-dimension circle

	// calculate visible object cordinates
	switch (iCircles)
	{
	case 1:											// single circle
	{
		// determine how big circle will be based on the size of the window
		iCircleRadius = clientRect.bottom / 4;
		circlePt[0] = centerPT;							// single circle is in the middle of the window

														// set location of lead line
		leadLinesRECT[0] = {							// line from circle to text
			circlePt[0].x - int(iCircleRadius * 0.25),
			circlePt[0].y + int(iCircleRadius * 0.25),
			circlePt[0].x - iCircleRadius,
			circlePt[0].y + int(iCircleRadius * 1.25) };

		// set location of text
		labelsPT[0] = {
			leadLinesRECT[0].right - (lstrlen(szLabels[0]) + 2) * CHAR_SIZE,
			leadLinesRECT[0].bottom - CHAR_SIZE };

	}
	break;

	case 2:											// two circles
	{
		// determine how big circles will be based on the size of the window
		iCircleRadius = clientRect.bottom / 5;

		if (bOverlapping)							// if the circles overlap (intersect)
		{
			circlePt[0] = { centerPT.x - int(iCircleRadius * 0.50), centerPT.y };
			circlePt[1] = { centerPT.x + int(iCircleRadius * 0.50), centerPT.y };
		}
		else										// else the circles are seperated
		{
			circlePt[0] = { centerPT.x - int(iCircleRadius * 1.10), centerPT.y };
			circlePt[1] = { centerPT.x + int(iCircleRadius * 1.10), centerPT.y };
		}

		// set leadline coordinates

		leadLinesRECT[0] = {							// line from first circle to text
			circlePt[0].x - int(iCircleRadius * 0.25),
			circlePt[0].y - int(iCircleRadius * 0.25),
			circlePt[0].x - iCircleRadius,
			circlePt[0].y - int(iCircleRadius * 1.25) };

		leadLinesRECT[1] = {							// line from second circle to text
			circlePt[1].x + int(iCircleRadius * 0.25),
			circlePt[1].y - int(iCircleRadius * 0.25),
			circlePt[1].x + iCircleRadius,
			circlePt[1].y - int(iCircleRadius * 1.25) };

		leadLinesRECT[2] = {							// line from intercection to text
			centerPT.x,
			centerPT.y + int(iCircleRadius * 0.25),
			centerPT.x,
			centerPT.y + int(iCircleRadius * 1.5) };

		// set text locations
		labelsPT[0] = {
			leadLinesRECT[0].right - (lstrlen(szLabels[0]) + 2) * CHAR_SIZE,
			leadLinesRECT[0].bottom - CHAR_SIZE };
		labelsPT[1] = {
			leadLinesRECT[1].right + CHAR_SIZE,
			leadLinesRECT[1].bottom - CHAR_SIZE };
		labelsPT[2] = {
			leadLinesRECT[2].right - (lstrlen(szLabels[0]) * CHAR_SIZE) / 2,
			leadLinesRECT[2].bottom + CHAR_SIZE };

	}
	break;

	case 3:											// three circles
		//determine how big(and where_ the circles will be drawn based on the size/shape of the window
		iCircleRadius = clientRect.bottom / 6;		//set size of radius

		if (bOverlapping)							//is the circles overlap
		{
			circlePt[0] = {							//red
				centerPT.x,							//center, left/right to other circles
				centerPT.y - int(iCircleRadius*0.25) };//up slightly

			circlePt[1] = {							//green
				centerPT.x - int(iCircleRadius*0.50),							//center, left/right to other circles
				centerPT.y + int(iCircleRadius*0.75) };//up slightly			
			
			circlePt[2] = {							//blue
				centerPT.x + int(iCircleRadius*0.50),							//center, left/right to other circles
				centerPT.y + int(iCircleRadius*0.75) };//up slightly
		}
		else										//if the circles do not overlap
		{
			circlePt[0] = {							//red
				centerPT.x,							//center, left/right to other circles
				centerPT.y - int(iCircleRadius) };//up slightly

			circlePt[1] = {							//green
				centerPT.x - int(iCircleRadius*1.10),							//center, left/right to other circles
				centerPT.y + int(iCircleRadius) };//up slightly			

			circlePt[2] = {							//blue
				centerPT.x + int(iCircleRadius*1.10),							//center, left/right to other circles
				centerPT.y + int(iCircleRadius) };//up slightly
		}

		//set leadline coordinates
		leadLinesRECT[0] =
		{
			circlePt[0].x - int(iCircleRadius*0.00),
			circlePt[0].y - int(iCircleRadius*0.25),
			circlePt[0].x - int(iCircleRadius*0.00),
			circlePt[0].y - int(iCircleRadius*1.5)
		};
		leadLinesRECT[1] =
		{
			circlePt[1].x - int(iCircleRadius*0.50),
			circlePt[1].y + int(iCircleRadius*0.25),
			circlePt[1].x - int(iCircleRadius*1.5),
			circlePt[1].y + int(iCircleRadius*1.0)
		};
		leadLinesRECT[2] =
		{
			circlePt[2].x + int(iCircleRadius*0.50),
			circlePt[2].y + int(iCircleRadius*0.0),
			circlePt[2].x + int(iCircleRadius*1.5),
			circlePt[2].y + int(iCircleRadius*0.5)
		};
		leadLinesRECT[3] =
		{
			centerPT.x - int(iCircleRadius*0.75),
			centerPT.y + int(iCircleRadius*0.0),
			centerPT.x - int(iCircleRadius*1.75),
			centerPT.y - int(iCircleRadius*1.25)
		};
		leadLinesRECT[4] =
		{
			centerPT.x - int(iCircleRadius*0.0),
			centerPT.y + int(iCircleRadius*1.0),
			centerPT.x - int(iCircleRadius*0.0),
			centerPT.y + int(iCircleRadius*2.0)
		};
		leadLinesRECT[5] =
		{
			centerPT.x + int(iCircleRadius*0.75),
			centerPT.y + int(iCircleRadius*0.0),
			centerPT.x + int(iCircleRadius*1.75),
			centerPT.y - int(iCircleRadius*0.25)
		};
		leadLinesRECT[6] =
		{
			centerPT.x - int(iCircleRadius*0.0),
			centerPT.y + int(iCircleRadius*0.25),
			centerPT.x + int(iCircleRadius*0.5),
			centerPT.y - int(iCircleRadius*1.5)
		};

		// set text locations
		labelsPT[0] = {
			leadLinesRECT[0].right - (lstrlen(szLabels[0]) + 3) * CHAR_SIZE,
			leadLinesRECT[0].bottom - CHAR_SIZE 
		};

		labelsPT[1] = {
			leadLinesRECT[1].right - (lstrlen(szLabels[1]) * CHAR_SIZE) /2,
			leadLinesRECT[1].bottom + CHAR_SIZE 
		};

		labelsPT[2] = {
			leadLinesRECT[2].right - (lstrlen(szLabels[2]) * CHAR_SIZE) / 2,
			leadLinesRECT[2].bottom + CHAR_SIZE 
		};

		labelsPT[3] = {
			leadLinesRECT[3].right - (lstrlen(szLabels[3]) + 5) * CHAR_SIZE,
			leadLinesRECT[3].bottom - CHAR_SIZE 
		};

		labelsPT[4] = {
			leadLinesRECT[4].right - (lstrlen(szLabels[4]) * CHAR_SIZE) /2,
			leadLinesRECT[4].bottom + CHAR_SIZE 
		};

		labelsPT[5] = {
			leadLinesRECT[5].right + CHAR_SIZE,
			leadLinesRECT[5].bottom + CHAR_SIZE 
		};

		labelsPT[6] = {
			leadLinesRECT[6].right - (lstrlen(szLabels[6]) * CHAR_SIZE)/2,
			leadLinesRECT[6].bottom - CHAR_SIZE 
		};


	break;

	default:
		break;
	}

	for (int i = 0; i < iCircles; i++)				// set dimensions of circles
	{
		locationRECT[i] = {
			circlePt[i].x - iCircleRadius,
			circlePt[i].y - iCircleRadius,
			circlePt[i].x + iCircleRadius,
			circlePt[i].y + iCircleRadius };

	}

}
