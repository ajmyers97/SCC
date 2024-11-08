//Module:	CIS021_S2019_Lab9a.cpp
//Project:	CIS021_S2019_Lab9a
//Author:	Allen Myers
//Date:		May 14th, 2019
//Purpose:	Understand modeling software.
//			Interpret an established formula into software.
//			Demonstrate the effect of formulaic modification on programmatic output.

#include "stdafx.h"
#include "CIS021_S2019_Lab9a.h"

#define MAX_LOADSTRING 100

// Global Variables:
HINSTANCE hInst;                                // current instance
WCHAR szTitle[MAX_LOADSTRING];                  // The title bar text
WCHAR szWindowClass[MAX_LOADSTRING];            // the main window class name

HWND hWnd_Input[2][4][4];						// input edit fields, [port/starboard][position][top-bottom]
HWND hWnd_InputTotals[2][4];					// totals of input, [port/starboard][position]
HWND hWnd_SideTotals[2];						// total weight on [port/starboard] side
HWND hWnd_WandB[6][6];							// Weight and Balance table, [tare..position3][weight/arm/moment]
HWND hWnd_WandBTotals[3];						// Weight and Balance table totals, [tare..position3]

int Cargo[2][4][4];								// user input, [port/starboard][position][top-bottom]

const int TareWeight = 1005;					// set values, for weight and balance
const int TareArm = 91;
const int FuelWeight = 160;
const int FuelArm = 87;
const int ZeroArm = 50;
const int OneArm = 75;
const int TwoArm = 100;
const int ThreeArm = 125;

// Forward declarations of functions included in this code module:
ATOM                MyRegisterClass(HINSTANCE hInstance);
BOOL                InitInstance(HINSTANCE, int);
LRESULT CALLBACK    WndProc(HWND, UINT, WPARAM, LPARAM);
INT_PTR CALLBACK    About(HWND, UINT, WPARAM, LPARAM);

void DrawShips(HDC);							// answer WM_DRAW
void DisplayForm(HWND);							// at WM_CREATE
void CollectInputs();							// load input array from user input
void TotalInputs();								// calc input totals and display
void CalculateWandB();							// calc weight and balance, display

int APIENTRY wWinMain(_In_ HINSTANCE hInstance,
                     _In_opt_ HINSTANCE hPrevInstance,
                     _In_ LPWSTR    lpCmdLine,
                     _In_ int       nCmdShow)
{
    UNREFERENCED_PARAMETER(hPrevInstance);
    UNREFERENCED_PARAMETER(lpCmdLine);

    // TODO: Place code here.

    // Initialize global strings
    LoadStringW(hInstance, IDS_APP_TITLE, szTitle, MAX_LOADSTRING);
    LoadStringW(hInstance, IDC_CIS021_S2019_LAB9A, szWindowClass, MAX_LOADSTRING);
    MyRegisterClass(hInstance);

    // Perform application initialization:
    if (!InitInstance (hInstance, nCmdShow))
    {
        return FALSE;
    }

    HACCEL hAccelTable = LoadAccelerators(hInstance, MAKEINTRESOURCE(IDC_CIS021_S2019_LAB9A));

    MSG msg;

    // Main message loop:
    while (GetMessage(&msg, nullptr, 0, 0))
    {
        if (!TranslateAccelerator(msg.hwnd, hAccelTable, &msg))
        {
            TranslateMessage(&msg);
            DispatchMessage(&msg);
        }
    }

    return (int) msg.wParam;
}



//
//  FUNCTION: MyRegisterClass()
//
//  PURPOSE: Registers the window class.
//
ATOM MyRegisterClass(HINSTANCE hInstance)
{
    WNDCLASSEXW wcex;

    wcex.cbSize = sizeof(WNDCLASSEX);

    wcex.style          = CS_HREDRAW | CS_VREDRAW;
    wcex.lpfnWndProc    = WndProc;
    wcex.cbClsExtra     = 0;
    wcex.cbWndExtra     = 0;
    wcex.hInstance      = hInstance;
    wcex.hIcon          = LoadIcon(hInstance, MAKEINTRESOURCE(IDI_CIS021_S2019_LAB9A));
    wcex.hCursor        = LoadCursor(nullptr, IDC_ARROW);
    wcex.hbrBackground  = (HBRUSH)(COLOR_WINDOW+1);
    wcex.lpszMenuName   = MAKEINTRESOURCEW(IDC_CIS021_S2019_LAB9A);
    wcex.lpszClassName  = szWindowClass;
    wcex.hIconSm        = LoadIcon(wcex.hInstance, MAKEINTRESOURCE(IDI_SMALL));

    return RegisterClassExW(&wcex);
}

//
//   FUNCTION: InitInstance(HINSTANCE, int)
//
//   PURPOSE: Saves instance handle and creates main window
//
//   COMMENTS:
//
//        In this function, we save the instance handle in a global variable and
//        create and display the main program window.
//
BOOL InitInstance(HINSTANCE hInstance, int nCmdShow)
{
   hInst = hInstance; // Store instance handle in our global variable

   HWND hWnd = CreateWindowW(szWindowClass, szTitle, WS_OVERLAPPEDWINDOW,
      CW_USEDEFAULT, 0, 850, 650, nullptr, nullptr, hInstance, nullptr);

   if (!hWnd)
   {
      return FALSE;
   }

   ShowWindow(hWnd, nCmdShow);
   UpdateWindow(hWnd);

   return TRUE;
}

//
//  FUNCTION: WndProc(HWND, UINT, WPARAM, LPARAM)
//
//  PURPOSE:  Processes messages for the main window.
//
//  WM_COMMAND  - process the application menu
//  WM_PAINT    - Paint the main window
//  WM_DESTROY  - post a quit message and return
//
//
LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
    switch (message)
    {
    case WM_COMMAND:
        {
            int wmId = LOWORD(wParam);
            // Parse the menu selections:
            switch (wmId)
            {
			case BN_CLICKED:
				if (HIWORD(wParam) == EN_CHANGE)	// an input field has changed
				{
					CollectInputs();				// load array with user inputs
					TotalInputs();					// total user inputs and display
					CalculateWandB();				// calc W & B, display
				}

				break;
			case IDM_ABOUT:
                DialogBox(hInst, MAKEINTRESOURCE(IDD_ABOUTBOX), hWnd, About);
                break;
            case IDM_EXIT:
                DestroyWindow(hWnd);
                break;
            default:
                return DefWindowProc(hWnd, message, wParam, lParam);
            }
        }
        break;
    case WM_PAINT:
        {
            PAINTSTRUCT ps;
            HDC hdc = BeginPaint(hWnd, &ps);

			DrawShips(hdc);							// 

            EndPaint(hWnd, &ps);
        }
        break;
	case WM_CREATE:
		DisplayForm(hWnd);
		break;
	case WM_DESTROY:
        PostQuitMessage(0);
        break;
    default:
        return DefWindowProc(hWnd, message, wParam, lParam);
    }
    return 0;
}

// Message handler for about box.
INT_PTR CALLBACK About(HWND hDlg, UINT message, WPARAM wParam, LPARAM lParam)
{
    UNREFERENCED_PARAMETER(lParam);
    switch (message)
    {
    case WM_INITDIALOG:
        return (INT_PTR)TRUE;

    case WM_COMMAND:
        if (LOWORD(wParam) == IDOK || LOWORD(wParam) == IDCANCEL)
        {
            EndDialog(hDlg, LOWORD(wParam));
            return (INT_PTR)TRUE;
        }
        break;
    }
    return (INT_PTR)FALSE;
}


void DrawShips(HDC hdc)
{
	HPEN penBlack, penGrey, penRed, penBlue, oldPen;
	TCHAR sz_DisplayA[32] = { 0 };

	penBlack = CreatePen(PS_SOLID, 2, RGB(0, 0, 0)); // black
	penGrey = CreatePen(PS_SOLID, 1, RGB(0x7F, 0x7F, 0x7F)); // grey
	penRed = CreatePen(PS_SOLID, 2, RGB(0xFF, 0, 0)); // red
	penBlue = CreatePen(PS_SOLID, 1, RGB(0, 0, 0xFF)); // blue
	oldPen = (HPEN)SelectObject(hdc, penBlack);

	// title
	TextOut(hdc, 300, 10,
		_T("All Weights in (x1000) Tonnes"), 29);
	TextOut(hdc, 350, 30,
		_T("All Arms in Meters"), 18);

	// plot view

	// ship outline
	MoveToEx(hdc, 70, 50, NULL);
	LineTo(hdc, 40, 100);
	LineTo(hdc, 40, 310);
	LineTo(hdc, 100, 310);
	LineTo(hdc, 100, 100);
	LineTo(hdc, 70, 50);

	// mast
	Rectangle(hdc, 45, 265, 95, 305);

	// centerline
	SelectObject(hdc, penGrey);
	MoveToEx(hdc, 70, 25, NULL);
	LineTo(hdc, 70, 330);

	// datum
	SelectObject(hdc, penBlue);
	MoveToEx(hdc, 20, 50, NULL);
	LineTo(hdc, 130, 50);

	// cargo
	SelectObject(hdc, penRed);
	Rectangle(hdc, 45, 105, 65, 140);
	Rectangle(hdc, 45, 145, 65, 180);
	Rectangle(hdc, 45, 185, 65, 220);
	Rectangle(hdc, 45, 225, 65, 260);

	Rectangle(hdc, 75, 105, 95, 140);
	Rectangle(hdc, 75, 145, 95, 180);
	Rectangle(hdc, 75, 185, 95, 220);
	Rectangle(hdc, 75, 225, 95, 260);

	// labels
	TextOut(hdc, 66, 10, _T("C"), 1);	// water
	TextOut(hdc, 136, 42, _T("Datum"), 5);

	TextOut(hdc, 25, 115, _T("0"), 1);
	TextOut(hdc, 25, 155, _T("1"), 1);
	TextOut(hdc, 25, 195, _T("2"), 1);
	TextOut(hdc, 25, 235, _T("3"), 1);

	// transverse view

	// ship outline
	SelectObject(hdc, penBlack);
	Rectangle(hdc, 200, 200, 460, 250);

	// mast
	MoveToEx(hdc, 455, 200, NULL);
	LineTo(hdc, 455, 80);
	LineTo(hdc, 430, 80);
	LineTo(hdc, 415, 100);
	LineTo(hdc, 415, 200);

	// centerline
	SelectObject(hdc, penGrey);
	MoveToEx(hdc, 180, 225, NULL);
	LineTo(hdc, 475, 225);

	// datum
	SelectObject(hdc, penBlue);
	MoveToEx(hdc, 200, 150, NULL);
	LineTo(hdc, 200, 300);

	// cargo
	SelectObject(hdc, penRed);
	Rectangle(hdc, 255, 175, 290, 200);
	Rectangle(hdc, 295, 175, 330, 200);
	Rectangle(hdc, 335, 175, 370, 200);
	Rectangle(hdc, 375, 175, 410, 200);

	Rectangle(hdc, 255, 150, 290, 175);
	Rectangle(hdc, 295, 150, 330, 175);
	Rectangle(hdc, 335, 150, 370, 175);
	Rectangle(hdc, 375, 150, 410, 175);

	Rectangle(hdc, 255, 125, 290, 150);
	Rectangle(hdc, 295, 125, 330, 150);
	Rectangle(hdc, 335, 125, 370, 150);
	Rectangle(hdc, 375, 125, 410, 150);

	Rectangle(hdc, 255, 100, 290, 125);
	Rectangle(hdc, 295, 100, 330, 125);
	Rectangle(hdc, 335, 100, 370, 125);
	Rectangle(hdc, 375, 100, 410, 125);

	// labels
	TextOut(hdc, 160, 218, _T("W"), 1);	// water
	TextOut(hdc, 180, 130, _T("Datum"), 5);

	TextOut(hdc, 270, 80, _T("0"), 1);
	TextOut(hdc, 310, 80, _T("1"), 1);
	TextOut(hdc, 350, 80, _T("2"), 1);
	TextOut(hdc, 390, 80, _T("3"), 1);


	// release the line pen
	SelectObject(hdc, oldPen);
	DeleteObject(penBlack);
	DeleteObject(penGrey);
	DeleteObject(penRed);
	DeleteObject(penBlue);

}

void DisplayForm(HWND hWnd)
{
	CreateWindow(TEXT("STATIC"), TEXT(""),	// grey background
		WS_VISIBLE | WS_CHILD, 0, 350, 650, 225, hWnd, NULL, NULL, NULL);

	CreateWindow(TEXT("STATIC"), TEXT(""),	// grey background
		WS_VISIBLE | WS_CHILD, 530, 70, 280, 260, hWnd, NULL, NULL, NULL);

	CreateWindow(TEXT("STATIC"),
		TEXT("Port"),
		WS_VISIBLE | WS_CHILD,
		60, 360, 40, 20, hWnd, NULL, NULL, NULL);

	CreateWindow(TEXT("STATIC"),
		TEXT("Starboard"),
		WS_VISIBLE | WS_CHILD,
		360, 360, 70, 20, hWnd, NULL, NULL, NULL);

	CreateWindow(TEXT("STATIC"),
		TEXT("0"),
		WS_VISIBLE | WS_CHILD,
		80, 390, 10, 20, hWnd, NULL, NULL, NULL);

	CreateWindow(TEXT("STATIC"),
		TEXT("1"),
		WS_VISIBLE | WS_CHILD,
		150, 390, 10, 20, hWnd, NULL, NULL, NULL);

	CreateWindow(TEXT("STATIC"),
		TEXT("2"),
		WS_VISIBLE | WS_CHILD,
		220, 390, 10, 20, hWnd, NULL, NULL, NULL);

	CreateWindow(TEXT("STATIC"),
		TEXT("3"),
		WS_VISIBLE | WS_CHILD,
		290, 390, 10, 20, hWnd, NULL, NULL, NULL);

	CreateWindow(TEXT("STATIC"),
		TEXT("0"),
		WS_VISIBLE | WS_CHILD,
		380, 390, 10, 20, hWnd, NULL, NULL, NULL);

	CreateWindow(TEXT("STATIC"),
		TEXT("1"),
		WS_VISIBLE | WS_CHILD,
		450, 390, 10, 20, hWnd, NULL, NULL, NULL);

	CreateWindow(TEXT("STATIC"),
		TEXT("2"),
		WS_VISIBLE | WS_CHILD,
		520, 390, 10, 20, hWnd, NULL, NULL, NULL);

	CreateWindow(TEXT("STATIC"),
		TEXT("3"),
		WS_VISIBLE | WS_CHILD,
		590, 390, 10, 20, hWnd, NULL, NULL, NULL);

	CreateWindow(TEXT("STATIC"),
		TEXT("_________________________________________________________________________"),
		WS_VISIBLE | WS_CHILD,
		50, 510, 585, 20, hWnd, NULL, NULL, NULL);

	CreateWindow(TEXT("STATIC"),
		TEXT("Totals"),
		WS_VISIBLE | WS_CHILD,
		10, 530, 45, 20, hWnd, NULL, NULL, NULL);

	hWnd_SideTotals[0] = CreateWindow(TEXT("STATIC"),
		TEXT("88888"),
		WS_VISIBLE | WS_CHILD,
		15, 320, 45, 20, hWnd, NULL, NULL, NULL);

	hWnd_SideTotals[1] = CreateWindow(TEXT("STATIC"),
		TEXT("88888"),
		WS_VISIBLE | WS_CHILD,
		80, 320, 45, 20, hWnd, NULL, NULL, NULL);

	// port 
	hWnd_Input[0][0][0] = CreateWindow(TEXT("EDIT"), NULL,
		WS_CHILD | WS_VISIBLE | WS_BORDER | ES_AUTOHSCROLL | WS_CHILD | ES_NUMBER,
		60, 410, 50, 20,
		hWnd, NULL, NULL, NULL);
	hWnd_Input[0][0][1] = CreateWindow(TEXT("EDIT"), NULL,
		WS_CHILD | WS_VISIBLE | WS_BORDER | ES_AUTOHSCROLL | WS_CHILD | ES_NUMBER,
		60, 440, 50, 20,
		hWnd, NULL, NULL, NULL);
	hWnd_Input[0][0][2] = CreateWindow(TEXT("EDIT"), NULL,
		WS_CHILD | WS_VISIBLE | WS_BORDER | ES_AUTOHSCROLL | WS_CHILD | ES_NUMBER,
		60, 470, 50, 20,
		hWnd, NULL, NULL, NULL);
	hWnd_Input[0][0][3] = CreateWindow(TEXT("EDIT"), NULL,
		WS_CHILD | WS_VISIBLE | WS_BORDER | ES_AUTOHSCROLL | WS_CHILD | ES_NUMBER,
		60, 500, 50, 20,
		hWnd, NULL, NULL, NULL);

	hWnd_Input[0][1][0] = CreateWindow(TEXT("EDIT"), NULL,
		WS_CHILD | WS_VISIBLE | WS_BORDER | ES_AUTOHSCROLL | WS_CHILD | ES_NUMBER,
		130, 410, 50, 20,
		hWnd, NULL, NULL, NULL);
	hWnd_Input[0][1][1] = CreateWindow(TEXT("EDIT"), NULL,
		WS_CHILD | WS_VISIBLE | WS_BORDER | ES_AUTOHSCROLL | WS_CHILD | ES_NUMBER,
		130, 440, 50, 20,
		hWnd, NULL, NULL, NULL);
	hWnd_Input[0][1][2] = CreateWindow(TEXT("EDIT"), NULL,
		WS_CHILD | WS_VISIBLE | WS_BORDER | ES_AUTOHSCROLL | WS_CHILD | ES_NUMBER,
		130, 470, 50, 20,
		hWnd, NULL, NULL, NULL);
	hWnd_Input[0][1][3] = CreateWindow(TEXT("EDIT"), NULL,
		WS_CHILD | WS_VISIBLE | WS_BORDER | ES_AUTOHSCROLL | WS_CHILD | ES_NUMBER,
		130, 500, 50, 20,
		hWnd, NULL, NULL, NULL);

	hWnd_Input[0][2][0] = CreateWindow(TEXT("EDIT"), NULL,
		WS_CHILD | WS_VISIBLE | WS_BORDER | ES_AUTOHSCROLL | WS_CHILD | ES_NUMBER,
		200, 410, 50, 20,
		hWnd, NULL, NULL, NULL);
	hWnd_Input[0][2][1] = CreateWindow(TEXT("EDIT"), NULL,
		WS_CHILD | WS_VISIBLE | WS_BORDER | ES_AUTOHSCROLL | WS_CHILD | ES_NUMBER,
		200, 440, 50, 20,
		hWnd, NULL, NULL, NULL);
	hWnd_Input[0][2][2] = CreateWindow(TEXT("EDIT"), NULL,
		WS_CHILD | WS_VISIBLE | WS_BORDER | ES_AUTOHSCROLL | WS_CHILD | ES_NUMBER,
		200, 470, 50, 20,
		hWnd, NULL, NULL, NULL);
	hWnd_Input[0][2][3] = CreateWindow(TEXT("EDIT"), NULL,
		WS_CHILD | WS_VISIBLE | WS_BORDER | ES_AUTOHSCROLL | WS_CHILD | ES_NUMBER,
		200, 500, 50, 20,
		hWnd, NULL, NULL, NULL);

	hWnd_Input[0][3][0] = CreateWindow(TEXT("EDIT"), NULL,
		WS_CHILD | WS_VISIBLE | WS_BORDER | ES_AUTOHSCROLL | WS_CHILD | ES_NUMBER,
		270, 410, 50, 20,
		hWnd, NULL, NULL, NULL);
	hWnd_Input[0][3][1] = CreateWindow(TEXT("EDIT"), NULL,
		WS_CHILD | WS_VISIBLE | WS_BORDER | ES_AUTOHSCROLL | WS_CHILD | ES_NUMBER,
		270, 440, 50, 20,
		hWnd, NULL, NULL, NULL);
	hWnd_Input[0][3][2] = CreateWindow(TEXT("EDIT"), NULL,
		WS_CHILD | WS_VISIBLE | WS_BORDER | ES_AUTOHSCROLL | WS_CHILD | ES_NUMBER,
		270, 470, 50, 20,
		hWnd, NULL, NULL, NULL);
	hWnd_Input[0][3][3] = CreateWindow(TEXT("EDIT"), NULL,
		WS_CHILD | WS_VISIBLE | WS_BORDER | ES_AUTOHSCROLL | WS_CHILD | ES_NUMBER,
		270, 500, 50, 20,
		hWnd, NULL, NULL, NULL);

	// starboard 
	hWnd_Input[1][0][0] = CreateWindow(TEXT("EDIT"), NULL,
		WS_CHILD | WS_VISIBLE | WS_BORDER | ES_AUTOHSCROLL | WS_CHILD | ES_NUMBER,
		360, 410, 50, 20,
		hWnd, NULL, NULL, NULL);
	hWnd_Input[1][0][1] = CreateWindow(TEXT("EDIT"), NULL,
		WS_CHILD | WS_VISIBLE | WS_BORDER | ES_AUTOHSCROLL | WS_CHILD | ES_NUMBER,
		360, 440, 50, 20,
		hWnd, NULL, NULL, NULL);
	hWnd_Input[1][0][2] = CreateWindow(TEXT("EDIT"), NULL,
		WS_CHILD | WS_VISIBLE | WS_BORDER | ES_AUTOHSCROLL | WS_CHILD | ES_NUMBER,
		360, 470, 50, 20,
		hWnd, NULL, NULL, NULL);
	hWnd_Input[1][0][3] = CreateWindow(TEXT("EDIT"), NULL,
		WS_CHILD | WS_VISIBLE | WS_BORDER | ES_AUTOHSCROLL | WS_CHILD | ES_NUMBER,
		360, 500, 50, 20,
		hWnd, NULL, NULL, NULL);

	hWnd_Input[1][1][0] = CreateWindow(TEXT("EDIT"), NULL,
		WS_CHILD | WS_VISIBLE | WS_BORDER | ES_AUTOHSCROLL | WS_CHILD | ES_NUMBER,
		430, 410, 50, 20,
		hWnd, NULL, NULL, NULL);
	hWnd_Input[1][1][1] = CreateWindow(TEXT("EDIT"), NULL,
		WS_CHILD | WS_VISIBLE | WS_BORDER | ES_AUTOHSCROLL | WS_CHILD | ES_NUMBER,
		430, 440, 50, 20,
		hWnd, NULL, NULL, NULL);
	hWnd_Input[1][1][2] = CreateWindow(TEXT("EDIT"), NULL,
		WS_CHILD | WS_VISIBLE | WS_BORDER | ES_AUTOHSCROLL | WS_CHILD | ES_NUMBER,
		430, 470, 50, 20,
		hWnd, NULL, NULL, NULL);
	hWnd_Input[1][1][3] = CreateWindow(TEXT("EDIT"), NULL,
		WS_CHILD | WS_VISIBLE | WS_BORDER | ES_AUTOHSCROLL | WS_CHILD | ES_NUMBER,
		430, 500, 50, 20,
		hWnd, NULL, NULL, NULL);

	hWnd_Input[1][2][0] = CreateWindow(TEXT("EDIT"), NULL,
		WS_CHILD | WS_VISIBLE | WS_BORDER | ES_AUTOHSCROLL | WS_CHILD | ES_NUMBER,
		500, 410, 50, 20,
		hWnd, NULL, NULL, NULL);
	hWnd_Input[1][2][1] = CreateWindow(TEXT("EDIT"), NULL,
		WS_CHILD | WS_VISIBLE | WS_BORDER | ES_AUTOHSCROLL | WS_CHILD | ES_NUMBER,
		500, 440, 50, 20,
		hWnd, NULL, NULL, NULL);
	hWnd_Input[1][2][2] = CreateWindow(TEXT("EDIT"), NULL,
		WS_CHILD | WS_VISIBLE | WS_BORDER | ES_AUTOHSCROLL | WS_CHILD | ES_NUMBER,
		500, 470, 50, 20,
		hWnd, NULL, NULL, NULL);
	hWnd_Input[1][2][3] = CreateWindow(TEXT("EDIT"), NULL,
		WS_CHILD | WS_VISIBLE | WS_BORDER | ES_AUTOHSCROLL | WS_CHILD | ES_NUMBER,
		500, 500, 50, 20,
		hWnd, NULL, NULL, NULL);

	hWnd_Input[1][3][0] = CreateWindow(TEXT("EDIT"), NULL,
		WS_CHILD | WS_VISIBLE | WS_BORDER | ES_AUTOHSCROLL | WS_CHILD | ES_NUMBER,
		570, 410, 50, 20,
		hWnd, NULL, NULL, NULL);
	hWnd_Input[1][3][1] = CreateWindow(TEXT("EDIT"), NULL,
		WS_CHILD | WS_VISIBLE | WS_BORDER | ES_AUTOHSCROLL | WS_CHILD | ES_NUMBER,
		570, 440, 50, 20,
		hWnd, NULL, NULL, NULL);
	hWnd_Input[1][3][2] = CreateWindow(TEXT("EDIT"), NULL,
		WS_CHILD | WS_VISIBLE | WS_BORDER | ES_AUTOHSCROLL | WS_CHILD | ES_NUMBER,
		570, 470, 50, 20,
		hWnd, NULL, NULL, NULL);
	hWnd_Input[1][3][3] = CreateWindow(TEXT("EDIT"), NULL,
		WS_CHILD | WS_VISIBLE | WS_BORDER | ES_AUTOHSCROLL | WS_CHILD | ES_NUMBER,
		570, 500, 50, 20,
		hWnd, NULL, NULL, NULL);

	// input totals
	hWnd_InputTotals[0][0] = CreateWindow(TEXT("STATIC"),
		TEXT(""),
		WS_VISIBLE | WS_CHILD,
		60, 530, 50, 20, hWnd, NULL, NULL, NULL);
	hWnd_InputTotals[0][1] = CreateWindow(TEXT("STATIC"),
		TEXT(""),
		WS_VISIBLE | WS_CHILD,
		130, 530, 50, 20, hWnd, NULL, NULL, NULL);
	hWnd_InputTotals[0][2] = CreateWindow(TEXT("STATIC"),
		TEXT(""),
		WS_VISIBLE | WS_CHILD,
		200, 530, 50, 20, hWnd, NULL, NULL, NULL);
	hWnd_InputTotals[0][3] = CreateWindow(TEXT("STATIC"),
		TEXT(""),
		WS_VISIBLE | WS_CHILD,
		270, 530, 50, 20, hWnd, NULL, NULL, NULL);
	hWnd_InputTotals[1][0] = CreateWindow(TEXT("STATIC"),
		TEXT(""),
		WS_VISIBLE | WS_CHILD,
		360, 530, 50, 20, hWnd, NULL, NULL, NULL);
	hWnd_InputTotals[1][1] = CreateWindow(TEXT("STATIC"),
		TEXT(""),
		WS_VISIBLE | WS_CHILD,
		430, 530, 50, 20, hWnd, NULL, NULL, NULL);
	hWnd_InputTotals[1][2] = CreateWindow(TEXT("STATIC"),
		TEXT(""),
		WS_VISIBLE | WS_CHILD,
		490, 530, 50, 20, hWnd, NULL, NULL, NULL);
	hWnd_InputTotals[1][3] = CreateWindow(TEXT("STATIC"),
		TEXT(""),
		WS_VISIBLE | WS_CHILD,
		570, 530, 50, 20, hWnd, NULL, NULL, NULL);

	// weight and balance
	CreateWindow(TEXT("STATIC"),
		TEXT("Station    Weight    Arm        Moment"),
		WS_VISIBLE | WS_CHILD,
		550, 80, 250, 20, hWnd, NULL, NULL, NULL);

	CreateWindow(TEXT("STATIC"),
		TEXT("Tare"),
		WS_VISIBLE | WS_CHILD,
		550, 110, 50, 20, hWnd, NULL, NULL, NULL);

	CreateWindow(TEXT("STATIC"),
		TEXT("Fuel"),
		WS_VISIBLE | WS_CHILD,
		550, 140, 50, 20, hWnd, NULL, NULL, NULL);

	CreateWindow(TEXT("STATIC"),
		TEXT("0"),
		WS_VISIBLE | WS_CHILD,
		550, 170, 50, 20, hWnd, NULL, NULL, NULL);

	CreateWindow(TEXT("STATIC"),
		TEXT("1"),
		WS_VISIBLE | WS_CHILD,
		550, 200, 50, 20, hWnd, NULL, NULL, NULL);

	CreateWindow(TEXT("STATIC"),
		TEXT("2"),
		WS_VISIBLE | WS_CHILD,
		550, 230, 50, 20, hWnd, NULL, NULL, NULL);

	CreateWindow(TEXT("STATIC"),
		TEXT("3"),
		WS_VISIBLE | WS_CHILD,
		550, 260, 50, 20, hWnd, NULL, NULL, NULL);

	CreateWindow(TEXT("STATIC"),
		TEXT("________________________________________"),
		WS_VISIBLE | WS_CHILD,
		600, 270, 200, 20, hWnd, NULL, NULL, NULL);

	CreateWindow(TEXT("STATIC"),
		TEXT("Totals"),
		WS_VISIBLE | WS_CHILD,
		550, 290, 50, 20, hWnd, NULL, NULL, NULL);

	// tare
	hWnd_WandB[0][0] = CreateWindow(TEXT("STATIC"),
		TEXT("88888"),
		WS_VISIBLE | WS_CHILD,
		610, 110, 50, 20, hWnd, NULL, NULL, NULL);
	hWnd_WandB[0][1] = CreateWindow(TEXT("STATIC"),
		TEXT("88888"),
		WS_VISIBLE | WS_CHILD,
		670, 110, 50, 20, hWnd, NULL, NULL, NULL);
	hWnd_WandB[0][2] = CreateWindow(TEXT("STATIC"),
		TEXT("88888"),
		WS_VISIBLE | WS_CHILD,
		730, 110, 50, 20, hWnd, NULL, NULL, NULL);
	// fuel
	hWnd_WandB[1][0] = CreateWindow(TEXT("STATIC"),
		TEXT("88888"),
		WS_VISIBLE | WS_CHILD,
		610, 140, 50, 20, hWnd, NULL, NULL, NULL);
	hWnd_WandB[1][1] = CreateWindow(TEXT("STATIC"),
		TEXT("88888"),
		WS_VISIBLE | WS_CHILD,
		670, 140, 50, 20, hWnd, NULL, NULL, NULL);
	hWnd_WandB[1][2] = CreateWindow(TEXT("STATIC"),
		TEXT("88888"),
		WS_VISIBLE | WS_CHILD,
		730, 140, 50, 20, hWnd, NULL, NULL, NULL);
	// 0
	hWnd_WandB[2][0] = CreateWindow(TEXT("STATIC"),
		TEXT("88888"),
		WS_VISIBLE | WS_CHILD,
		610, 170, 50, 20, hWnd, NULL, NULL, NULL);
	hWnd_WandB[2][1] = CreateWindow(TEXT("STATIC"),
		TEXT("88888"),
		WS_VISIBLE | WS_CHILD,
		670, 170, 50, 20, hWnd, NULL, NULL, NULL);
	hWnd_WandB[2][2] = CreateWindow(TEXT("STATIC"),
		TEXT("88888"),
		WS_VISIBLE | WS_CHILD,
		730, 170, 50, 20, hWnd, NULL, NULL, NULL);
	// 1
	hWnd_WandB[3][0] = CreateWindow(TEXT("STATIC"),
		TEXT("88888"),
		WS_VISIBLE | WS_CHILD,
		610, 200, 50, 20, hWnd, NULL, NULL, NULL);
	hWnd_WandB[3][1] = CreateWindow(TEXT("STATIC"),
		TEXT("88888"),
		WS_VISIBLE | WS_CHILD,
		670, 200, 50, 20, hWnd, NULL, NULL, NULL);
	hWnd_WandB[3][2] = CreateWindow(TEXT("STATIC"),
		TEXT("88888"),
		WS_VISIBLE | WS_CHILD,
		730, 200, 50, 20, hWnd, NULL, NULL, NULL);
	// 2
	hWnd_WandB[4][0] = CreateWindow(TEXT("STATIC"),
		TEXT("88888"),
		WS_VISIBLE | WS_CHILD,
		610, 230, 50, 20, hWnd, NULL, NULL, NULL);
	hWnd_WandB[4][1] = CreateWindow(TEXT("STATIC"),
		TEXT("88888"),
		WS_VISIBLE | WS_CHILD,
		670, 230, 50, 20, hWnd, NULL, NULL, NULL);
	hWnd_WandB[4][2] = CreateWindow(TEXT("STATIC"),
		TEXT("88888"),
		WS_VISIBLE | WS_CHILD,
		730, 230, 50, 20, hWnd, NULL, NULL, NULL);
	// 3
	hWnd_WandB[5][0] = CreateWindow(TEXT("STATIC"),
		TEXT("88888"),
		WS_VISIBLE | WS_CHILD,
		610, 260, 50, 20, hWnd, NULL, NULL, NULL);
	hWnd_WandB[5][1] = CreateWindow(TEXT("STATIC"),
		TEXT("88888"),
		WS_VISIBLE | WS_CHILD,
		670, 260, 50, 20, hWnd, NULL, NULL, NULL);
	hWnd_WandB[5][2] = CreateWindow(TEXT("STATIC"),
		TEXT("88888"),
		WS_VISIBLE | WS_CHILD,
		730, 260, 50, 20, hWnd, NULL, NULL, NULL);

	// weight and balance totals
	hWnd_WandBTotals[0] = CreateWindow(TEXT("STATIC"),
		TEXT("88888"),
		WS_VISIBLE | WS_CHILD,
		610, 290, 50, 20, hWnd, NULL, NULL, NULL);
	hWnd_WandBTotals[1] = CreateWindow(TEXT("STATIC"),
		TEXT("88888"),
		WS_VISIBLE | WS_CHILD,
		670, 290, 50, 20, hWnd, NULL, NULL, NULL);
	hWnd_WandBTotals[2] = CreateWindow(TEXT("STATIC"),
		TEXT("88888"),
		WS_VISIBLE | WS_CHILD,
		730, 290, 50, 20, hWnd, NULL, NULL, NULL);

}

// load array from user input
void CollectInputs()
{
	TCHAR szInput[TCHAR_SIZE];								//text from edit controls

	for (int iSide = 0;iSide < 2;iSide++)					//port/starboard
		for (int iPosition = 0;iPosition < 4;iPosition++)	//position
			for (int iHeight = 0;iHeight < 4;iHeight++)		//height or level
			{
				GetWindowText(								//get user input
					hWnd_Input[iSide][iPosition][iHeight],	//input field
					szInput,								//target string
					TCHAR_SIZE								//max chars to read
				);

				//save user input(convert to integer,store in array)
				Cargo[iSide][iPosition][iHeight] =			//storage array
					_tstoi(szInput);						//convert to integer

			}


}

// total user inputs and display
void TotalInputs()
{
	TCHAR szOutput[TCHAR_SIZE];								//output TCHAR
	int iSubTotal = 0;										//column total
	int iSideTotal = 0;										//port/starboard total

	for (int iSide = 0;iSide < 2;iSide++)					//port/starboard
	{
		for (int iPosition = 0;iPosition < 4;iPosition++)
		{
			for (int iHeight = 0;iHeight < 4;iHeight++)
			{
				iSubTotal += Cargo[iSide][iPosition][iHeight];
			}

			InttoTCHAR(iSubTotal, szOutput);				//convert subtotal to TCHAR

			SetWindowText(									//set side total text
				hWnd_SideTotals[iSide],
				szOutput
			);

			iSideTotal += iSubTotal;						//accumulate
			iSubTotal = 0;									//reset
		}

		InttoTCHAR(iSideTotal, szOutput);					//convert side sub total to TCHAR
		SetWindowText(hWnd_SideTotals[iSide], szOutput);	//display side total
		iSideTotal = 0;										//reset
	}
}

// calculate weight and balance
// and display results
void CalculateWandB()
{
	TCHAR szInput[TCHAR_SIZE];								//text from edit controls
	TCHAR szOutput[TCHAR_SIZE];								//output TCHAR

	int iWeight = 0;										//accumulators
	int iArm = 0;
	int iMoment = 0;
	int iSubTotal = 0;

	//display fixed values
	InttoTCHAR(TareWeight, szOutput);						// set values, for weight and balance
	SetWindowText(hWnd_WandB[0][0], szOutput);

	InttoTCHAR(TareArm, szOutput);
	SetWindowText(hWnd_WandB[0][1], szOutput);

	InttoTCHAR(FuelWeight, szOutput);
	SetWindowText(hWnd_WandB[1][0], szOutput);

	InttoTCHAR(FuelArm, szOutput);
	SetWindowText(hWnd_WandB[1][1], szOutput);

	InttoTCHAR(ZeroArm, szOutput);
	SetWindowText(hWnd_WandB[2][1], szOutput);

	InttoTCHAR(OneArm, szOutput);
	SetWindowText(hWnd_WandB[3][1], szOutput);

	InttoTCHAR(TwoArm, szOutput);
	SetWindowText(hWnd_WandB[4][1], szOutput);

	InttoTCHAR(ThreeArm, szOutput);
	SetWindowText(hWnd_WandB[5][1], szOutput);

	//calc/display user input values
	for (int iPosition = 0;iPosition < 4;iPosition++)			//position
	{
		for (int iHeight = 0;iHeight < 4;iHeight++)				//levels
		{
			iSubTotal += Cargo[0][iPosition][iHeight] +			//cargo 1
				Cargo[1][iPosition][iHeight];					//cargo 2
		}
		//have position total, display it
		InttoTCHAR(iSubTotal, szOutput);						//convert to TCHAR
		SetWindowText(hWnd_WandB[iPosition + 2][0], szOutput);	//output to window
		iSubTotal = 0;											//reset
	}
	//calculate and display totals
	iWeight = iArm = iMoment = 0;								//clear subtotals

	//calc moments
	for (int i = 0;i < 6;i++)
	{
		GetWindowText(hWnd_WandB[i][0], szInput, TCHAR_SIZE);	//get tar weight
		iWeight = _tstoi(szInput);
		GetWindowText(hWnd_WandB[i][1], szInput, TCHAR_SIZE);	//get tar arm
		iArm = _tstoi(szInput);
		iMoment = iWeight*iArm;									//the moment
		InttoTCHAR(iMoment, szOutput);
		SetWindowText(hWnd_WandB[i][2], szOutput);				//display

	}


	//calc total weight
	for (int i = 0;i < 6;i++)
	{
		GetWindowText(hWnd_WandB[i][0],szInput,TCHAR_SIZE);
		iWeight += _tstoi(szInput);
	}

	InttoTCHAR(iWeight, szOutput);								//total to TCHAR
	SetWindowText(hWnd_WandBTotals[0], szOutput);				//display

	iWeight = iArm = iMoment = 0;								//clear subtotals

	//calc total moment
	for (int i = 0;i < 6;i++)
	{
		GetWindowText(hWnd_WandB[i][2], szInput, TCHAR_SIZE);
		iMoment += _tstoi(szInput);
	}

	InttoTCHAR(iMoment, szOutput);								//total to TCHAR
	SetWindowText(hWnd_WandBTotals[2], szOutput);				//display

//	iWeight = iArm = iMoment = 0;								//clear subtotals


	//calc total arm
	GetWindowText(hWnd_WandBTotals[0], szInput,TCHAR_SIZE);		
	iWeight = _tstoi(szInput);
	GetWindowText(hWnd_WandBTotals[2], szInput, TCHAR_SIZE);
	iMoment= _tstoi(szInput);
	iArm = iMoment / iWeight;									//calc arm
	InttoTCHAR(iArm, szOutput);
	SetWindowText(hWnd_WandBTotals[1], szOutput);				//display

}