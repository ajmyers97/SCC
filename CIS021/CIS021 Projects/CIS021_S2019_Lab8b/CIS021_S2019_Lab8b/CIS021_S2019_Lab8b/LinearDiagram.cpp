//Module:	LinearDiagram.cpp
//Project:	CIS021_S2019_Lab8b 
//Author:	Allen Myers
//Purpose:	CPP file to LinearDiagram
//
#include "stdafx.h"
#include "LinearDiagram.h"


LinearDiagram::LinearDiagram()
{
}


LinearDiagram::~LinearDiagram()
{
}

LinearDiagram::LinearDiagram(HWND h)
{
	// have handle to main window
	hWnd = h;

	// initialize user input values
	iLeadingCoefficient = A = 0;
	iCoefficient = B = 0;
	iConstant = C = 0;

	// create formula controls
	RECT clientRect;								// client rect of main window
	GetClientRect(hWnd, &clientRect);				// get client rect
	int bottom = clientRect.bottom - 70;

	// grey background
	hWnd_Gray_Box = CreateWindow(TEXT("STATIC"), TEXT(""),
		WS_VISIBLE | WS_CHILD, 0, 0, 0, 0, hWnd, NULL, NULL, NULL);

	hWnd_lbl_Formula = CreateWindow(TEXT("STATIC"), TEXT("Polynomial"),
		WS_VISIBLE | WS_CHILD, 0, 0, 0, 0, hWnd, NULL, NULL, NULL);

	hWnd_cbo_1stSign = CreateWindow(TEXT("COMBOBOX"), TEXT("+"),
		CBS_DROPDOWN | CBS_HASSTRINGS | WS_CHILD | WS_OVERLAPPED | WS_VISIBLE | WS_VSCROLL,
		0, 0, 0, 0, hWnd, NULL, NULL, NULL);

	SendMessage(hWnd_cbo_1stSign, CB_ADDSTRING, NULL, (LPARAM)"+");
	SendMessage(hWnd_cbo_1stSign, CB_ADDSTRING, NULL, (LPARAM)"-");
	SendMessage(hWnd_cbo_1stSign, WM_SETTEXT, NULL, (LPARAM)"+");

	hWnd_txt_x2 = CreateWindow(TEXT("EDIT"), NULL,
		WS_CHILD | WS_VISIBLE | WS_BORDER | ES_AUTOHSCROLL | WS_CHILD | ES_NUMBER,
		0, 0, 0, 0, hWnd, NULL, NULL, NULL);

	hWnd_lbl_x2 = CreateWindow(TEXT("STATIC"), TEXT("x"),
		WS_VISIBLE | WS_CHILD, 0, 0, 0, 0, hWnd, NULL, NULL, NULL);

	hWnd_lbl_2 = CreateWindow(TEXT("STATIC"), TEXT("2"),
		WS_VISIBLE | WS_CHILD, 0, 0, 0, 0, hWnd, NULL, NULL, NULL);

	hWnd_cbo_2ndSign = CreateWindow(TEXT("COMBOBOX"), TEXT("+"),
		CBS_DROPDOWN | CBS_HASSTRINGS | WS_CHILD | WS_OVERLAPPED | WS_VISIBLE | WS_VSCROLL,
		0, 0, 0, 0, hWnd, NULL, NULL, NULL);

	SendMessage(hWnd_cbo_2ndSign, CB_ADDSTRING, NULL, (LPARAM)"+");
	SendMessage(hWnd_cbo_2ndSign, CB_ADDSTRING, NULL, (LPARAM)"-");
	SendMessage(hWnd_cbo_2ndSign, WM_SETTEXT, NULL, (LPARAM)"+");

	hWnd_txt_x = CreateWindow(TEXT("EDIT"), NULL,
		WS_CHILD | WS_VISIBLE | WS_BORDER | ES_AUTOHSCROLL | WS_CHILD | ES_NUMBER,
		0, 0, 0, 0, hWnd, NULL, NULL, NULL);

	hWnd_lbl_x = CreateWindow(TEXT("STATIC"), TEXT("x"),
		WS_VISIBLE | WS_CHILD, 0, 0, 0, 0, hWnd, NULL, NULL, NULL);

	hWnd_cbo_3rdSign = CreateWindow(TEXT("COMBOBOX"), TEXT("+"),
		CBS_DROPDOWN | CBS_HASSTRINGS | WS_CHILD | WS_OVERLAPPED | WS_VISIBLE | WS_VSCROLL,
		0, 0, 0, 0, hWnd, NULL, NULL, NULL);

	SendMessage(hWnd_cbo_3rdSign, CB_ADDSTRING, NULL, (LPARAM)"+");
	SendMessage(hWnd_cbo_3rdSign, CB_ADDSTRING, NULL, (LPARAM)"-");
	SendMessage(hWnd_cbo_3rdSign, WM_SETTEXT, NULL, (LPARAM)"+");

	hWnd_txt_Const = CreateWindow(TEXT("EDIT"), NULL,
		WS_CHILD | WS_VISIBLE | WS_BORDER | ES_AUTOHSCROLL | WS_CHILD | ES_NUMBER,
		0, 0, 0, 0, hWnd, NULL, NULL, NULL);

	hWnd_lbl_EquY = CreateWindow(TEXT("STATIC"), TEXT("= y"),
		WS_VISIBLE | WS_CHILD, 0, 0, 0, 0, hWnd, NULL, NULL, NULL);

}

void LinearDiagram::Draw(HDC hdc)
{
	RECT clientRect;								// client rect of main window
	POINT centerPt;									// center of gthe client rect

	GetClientRect(hWnd, &clientRect);				// get client rect
	centerPt.x = clientRect.right / 2;				// find center point
	centerPt.y = clientRect.bottom / 2;

	// create pens
	HPEN penMain = CreatePen(PS_SOLID, 2, RGB(0x7F, 0x7F, 0x7F));	// center grid lines
	HPEN penGrad = CreatePen(PS_SOLID, 1, RGB(0xEF, 0xEF, 0xEF));	// secondary grid lines
	HPEN penLine = CreatePen(PS_SOLID, 2, RGB(0x00, 0x00, 0xFF));	// blue, for parabola

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
	for (int i = centerPt.y - 50; i > 0; i -= 50)		// draw y grids above center
	{
		MoveToEx(hdc, clientRect.left, i, NULL);
		LineTo(hdc, clientRect.right, i);
	}
	for (int i = centerPt.y + 50; i < clientRect.bottom; i += 50)		// draw y grids below center
	{
		MoveToEx(hdc, clientRect.left, i, NULL);
		LineTo(hdc, clientRect.right, i);
	}

	for (int i = centerPt.x - 50; i > 0; i -= 50)		// draw x grids left of center
	{
		MoveToEx(hdc, i, clientRect.top, NULL);
		LineTo(hdc, i, clientRect.bottom);
	}

	for (int i = centerPt.x + 50; i < clientRect.right; i += 50)		// draw x grids right of center
	{
		MoveToEx(hdc, i, clientRect.top, NULL);
		LineTo(hdc, i, clientRect.bottom);
	}


	// Draw line

	SelectObject(hdc, penLine);											// select pen for drawing the line

	POINT displayPT[20];												// adjusted for display

																		// draw left of y-axis
	for (int i = 0; i < 10; i++)										// adjust intercepts to match screen coords
	{
		displayPT[i].x = centerPt.x + (YintPt[i].x * 50);
		displayPT[i].y = centerPt.y - (YintPt[i].y * 50);
	}

	BOOL good = PolyBezier(hdc, displayPT, 10);							// display the curve

																		// draw right of y-axis
	for (int i = 0; i < 10; i++)										// adjust intercepts to match screen coords
	{
		displayPT[i].x = centerPt.x + (YintPt[i + 10].x * 50);
		displayPT[i].y = centerPt.y - (YintPt[i + 10].y * 50);
	}

	good = PolyBezier(hdc, displayPT, 10);								// display the curve

	// draw vertex

	displayPT[0].x = centerPt.x + (YintPt[9].x * 50);					// last point in left line
	displayPT[0].y = centerPt.y + (YintPt[9].y * 50);

	displayPT[1].x = centerPt.x + (Vertex.x * 50);
	displayPT[1].y = centerPt.y + (Vertex.y * 50);

	displayPT[2].x = centerPt.x + (YintPt[10].x * 50);					// last point in right lint
	displayPT[2].y = centerPt.y + (YintPt[10].y * 50);

	good = PolyBezier(hdc, displayPT,3);								// display the curve (vertex)


	// return old pen and delete pens
	SelectObject(hdc, oldPen);
	DeleteObject(penMain);
	DeleteObject(penGrad);
	DeleteObject(penLine);
} // Draw()

void LinearDiagram::Size()
{
	RECT clientRect;								// client rect of main window

	GetClientRect(hWnd, &clientRect);				// get client rect

	int bottom = clientRect.bottom - 70;			// controls align to bottom of window

	// Move controls to new draw locations
	MoveWindow(hWnd_Gray_Box, 0, bottom - 60, 370, 140, false);
	MoveWindow(hWnd_lbl_Formula, 20, bottom - 40, 75, 20, false);
	MoveWindow(hWnd_cbo_1stSign, 20, bottom, 35, 60, false);
	MoveWindow(hWnd_txt_x2, 60, bottom, 20, 20, false);
	MoveWindow(hWnd_lbl_x2, 90, bottom, 20, 20, false);
	MoveWindow(hWnd_lbl_2, 100, bottom - 10, 20, 20, false);
	MoveWindow(hWnd_cbo_2ndSign, 130, bottom, 35, 60, false);
	MoveWindow(hWnd_txt_x, 170, bottom, 20, 20, false);
	MoveWindow(hWnd_lbl_x, 200, bottom, 20, 20, false);
	MoveWindow(hWnd_cbo_3rdSign, 230, bottom, 35, 60, false);
	MoveWindow(hWnd_txt_Const, 270, bottom, 20, 20, false);
	MoveWindow(hWnd_lbl_EquY, 300, bottom, 20, 20, false);	// = y

} // Size()


void LinearDiagram::GetTerms()
{
	TCHAR szIn[TCHAR_SIZE];

	GetWindowText(hWnd_txt_x2, szIn, TCHAR_SIZE);			// get leading coefficient (of x squared)
	iLeadingCoefficient = _tstoi(szIn);						// convert input to integer

	int iCbo = SendMessage(hWnd_cbo_1stSign, CB_GETCURSEL, NULL, NULL);
	if (iCbo == 1)											// if negative
		iLeadingCoefficient *= -1;							//	change sign

	GetWindowText(hWnd_txt_x, szIn, TCHAR_SIZE);			// get coefficient (of x)
	iCoefficient = _tstoi(szIn);							// convert input to integer

	iCbo = SendMessage(hWnd_cbo_2ndSign, CB_GETCURSEL, NULL, NULL);
	if (iCbo == 1)											// if negative
		iLeadingCoefficient *= -1;							//	change sign

	GetWindowText(hWnd_txt_Const, szIn, TCHAR_SIZE);		// get constant
	iConstant = _tstoi(szIn);								// convert input to integer

	iCbo = SendMessage(hWnd_cbo_3rdSign, CB_GETCURSEL, NULL, NULL);
	if (iCbo == 1)											// if negative
		iLeadingCoefficient *= -1;							//	change sign

															// store them as double A, B, and C to make it easier to work with in CalcLine()
	A = iLeadingCoefficient * 1.0;
	B = iCoefficient * 1.0;
	C = iConstant * 1.0;

}

void LinearDiagram::CalcLine()
{
	GetTerms();												//get user input

	int y = 9;												//start at top of graph
	
	for (int i = 0;i < 10;i++)								//create left values
	{
		YintPt[i].y = y;									//set y value
		YintPt[i].x =										//quadratic equation(+)
		//	(((-B) + ((sqrt(pow(B, 2)) - (4 * A*(C-y))))) / (2 * A));					//CHECK HERE FOR MSITAKES!!!!!
		(-B + sqrt(pow(B, 2) - 4 * A*(C - y))) / (2 * A);								//CHECK HERE FOR MSITAKES!!!!!
		y--;												//next intercept
	}
	y++;
													//duplicate y-int
	for (int i = 10;i < 20;i++)								//create left values
	{
		YintPt[i].y = y;									//set y value
		YintPt[i].x =										//quadratic equation-other half(-)
			(-B - sqrt(pow(B, 2) - 4 * A*(C-y))) / (2 * A);								//CHECK HERE FOR MSITAKES!!!!!
		y++;												//next intercept
	}
	

	//calculate vertex
	Vertex.x = (-B / (2 * A));								//depth
	Vertex.y =												//
		(A*pow(Vertex.x, 2)) + (B*Vertex.x + C);
}

void LinearDiagram::ShowIntercepts(HDC hdc)
{

}
