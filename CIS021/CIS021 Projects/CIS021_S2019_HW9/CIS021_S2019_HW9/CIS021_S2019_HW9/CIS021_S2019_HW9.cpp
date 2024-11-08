//Module:	CIS021_S2019_HW9.cpp
//Project:	CIS021_S2019_HW9
//Author:	Allen Myers
//Date:		May 18th, 2019
//Purpose:	Understand modeling software.
//			Understand actions that occur in a simulator.
//			Demonstrate the effect of formulaic modification on programmatic output.

#include "stdafx.h"
#include "CIS021_S2019_HW9.h"

#define MAX_LOADSTRING 100
#define WM_TIMER_LIGHT 2000
#define WM_TIMER_TRAFFIC 2001

// Global Variables:
HINSTANCE hInst;                                // current instance
WCHAR szTitle[MAX_LOADSTRING];                  // The title bar text
WCHAR szWindowClass[MAX_LOADSTRING];            // the main window class name

LightsClass* Lights[4];							// traffic control stop lights

CarClass car;		// sample object - replace with list

// Forward declarations of functions included in this code module:
ATOM                MyRegisterClass(HINSTANCE hInstance);
BOOL                InitInstance(HINSTANCE, int);
LRESULT CALLBACK    WndProc(HWND, UINT, WPARAM, LPARAM);
INT_PTR CALLBACK    About(HWND, UINT, WPARAM, LPARAM);

void DrawStreets(HDC);						// draw the background

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
    LoadStringW(hInstance, IDC_CIS021_S2019_HW9, szWindowClass, MAX_LOADSTRING);
    MyRegisterClass(hInstance);

    // Perform application initialization:
    if (!InitInstance (hInstance, nCmdShow))
    {
        return FALSE;
    }

    HACCEL hAccelTable = LoadAccelerators(hInstance, MAKEINTRESOURCE(IDC_CIS021_S2019_HW9));

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
    wcex.hIcon          = LoadIcon(hInstance, MAKEINTRESOURCE(IDI_CIS021_S2019_HW9));
    wcex.hCursor        = LoadCursor(nullptr, IDC_ARROW);
    wcex.hbrBackground  = (HBRUSH)(COLOR_WINDOW+1);
    wcex.lpszMenuName   = MAKEINTRESOURCEW(IDC_CIS021_S2019_HW9);
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
      CW_USEDEFAULT, 0, 900, 700, nullptr, nullptr, hInstance, nullptr);

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

	case WM_KEYDOWN:								// capture key press

		switch (wParam)
		{
			//1: A new car object should be created with every arrow key press. 
			//2: When the up array is pressed, a new car should appear on the 
			//   street at the top of the screen and begin moving down toward
			//   the intersection.
			//3: Left, right, and bottom arrows should create cars on the 
			//   appropriate streets.
			//4: Do not create a new car if an existing car has not moved out of the way.



			case VK_UP:								// up arrow pressed
			{
				//check to see if there is a car on the road
				//create a new car, the car should move
				//check to see if there is a car ahead of it
				//if car ahead, stop and set location
									

		}
			break;
			case VK_RIGHT:							// right arrow pressed
			{	
				//check to see if there is a car on the road
				//create a new car, the car should move
				//check to see if there is a car ahead of it
				//if car ahead, stop and set location
			
			}
			break;
			case VK_DOWN:							// down arrow pressed
			{	
				//check to see if there is a car on the road
				//create a new car, the car should move
				//check to see if there is a car ahead of it
				//if car ahead, stop and set location
			
			}
			break;
			case VK_LEFT:							// left arrow pressed
			{	
				//check to see if there is a car on the road
				//create a new car, the car should then move
				//check to see if there is a car ahead of it
				//if car ahead, stop and set location
			
			}
			break;
		}

		break;

	case WM_TIMER:

		if (wParam == WM_TIMER_TRAFFIC)					// move cars
		{
			//1:there are two possible intersections for lights
			//  one north/south and one east/west
			//2:if the light is green, the car should move from here.
			//3:if the car reaches end of screen, delete

			for (int j = 0; j < 2;j++)					//loop through the number of sections
				if (Lights[j]->GetState() == GREEN)		//check if the light is green
					car.Move();							//if green, move the car at the light

			
			InvalidateRect(hWnd, NULL, TRUE);
		}

		if (wParam == WM_TIMER_LIGHT)					// control traffic lights
		{
			for (int i = 0; i < 4; i++)
				Lights[i]->Set();						// tell lights 1 second has expired
		}


		break;

    case WM_PAINT:
        {
            PAINTSTRUCT ps;
            HDC hdc = BeginPaint(hWnd, &ps);
            

			DrawStreets(hdc);									// draw background
			for (int i = 0; i < 4; i++)							// draw traffic lights
				Lights[i]->Draw(hdc);


			// draw sample car
			//car.Draw(hdc);					// replace



            EndPaint(hWnd, &ps);
        }
        break;

	case WM_CREATE:

		SetTimer(hWnd, WM_TIMER_TRAFFIC, 33, NULL);					// move cars
		SetTimer(hWnd, WM_TIMER_LIGHT, 1000, NULL);					// control traffic lights

		// create traffic lights
		for (int i = 0; i < 4; i++)								
			Lights[i] = new LightsClass(i);


		break;

    case WM_DESTROY:

		// stop timers
		KillTimer(hWnd, WM_TIMER_TRAFFIC);
		KillTimer(hWnd, WM_TIMER_LIGHT);

		for (int i = 0; i < 4; i++)								// destroy traffic lights
			if (Lights[i])
				delete Lights[i];


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

// draw the background
void DrawStreets(HDC hdc)
{
	HPEN penCurb, penDash, oldPen;
	TCHAR sz_DisplayA[32] = { 0 };

	penCurb = CreatePen(PS_SOLID, 2, RGB(0, 0, 0));	 // black
	penDash = CreatePen(PS_DASH, 1, RGB(0, 0, 0));	 // dash
	oldPen = (HPEN)SelectObject(hdc, penCurb);

	// main street
	MoveToEx(hdc, 100, 300, NULL);
	LineTo(hdc, 400, 300);

	MoveToEx(hdc, 100, 360, NULL);
	LineTo(hdc, 400, 360);

	MoveToEx(hdc, 460, 300, NULL);
	LineTo(hdc, 760, 300);

	MoveToEx(hdc, 460, 360, NULL);
	LineTo(hdc, 760, 360);

	SelectObject(hdc, penDash);
	MoveToEx(hdc, 100, 330, NULL);
	LineTo(hdc, 400, 330);

	MoveToEx(hdc, 460, 330, NULL);
	LineTo(hdc, 760, 330);

	// 1st street
	SelectObject(hdc, penCurb);
	MoveToEx(hdc, 400, 100, NULL);
	LineTo(hdc, 400, 300);

	MoveToEx(hdc, 400, 360, NULL);
	LineTo(hdc, 400, 560);

	MoveToEx(hdc, 460, 100, NULL);
	LineTo(hdc, 460, 300);

	MoveToEx(hdc, 460, 360, NULL);
	LineTo(hdc, 460, 560);

	SelectObject(hdc, penDash);
	MoveToEx(hdc, 430, 100, NULL);
	LineTo(hdc, 430, 300);

	MoveToEx(hdc, 430, 360, NULL);
	LineTo(hdc, 430, 560);

	SelectObject(hdc, penCurb);

	// labels
	TextOut(hdc, 30, 322, _T("Main St."), 8);
	TextOut(hdc, 407, 72, _T("1st St."), 7);

	// release the line pen
	SelectObject(hdc, oldPen);
	DeleteObject(penDash);
	DeleteObject(penCurb);
}
