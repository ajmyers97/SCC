//Module:	CIS023_S2018_Lab12e.cpp
//Project:	CIS023_S2018_Lab12e
//Author:	Allen Myers
//Date:		May 14th, 2018
//Purpose:	Review GCI graphics.
//			Capture keystrokes.
//			Review motion of graphic objects.

#include "stdafx.h"
#include "CIS023_S2018_Lab12e.h"

#define MAX_LOADSTRING 100
#define WM_TIMER_CREATE 2000
#define WM_TIMER_MOVE 2001

// Global Variables:
HINSTANCE hInst;                                // current instance
WCHAR szTitle[MAX_LOADSTRING];                  // The title bar text
WCHAR szWindowClass[MAX_LOADSTRING];            // the main window class name

LinkedListClass* list;							// list of ball objects
CrossHairClass*crossHair;						//cross hair

												
// Forward declarations of functions included in this code module:
ATOM                MyRegisterClass(HINSTANCE hInstance);
BOOL                InitInstance(HINSTANCE, int);
LRESULT CALLBACK    WndProc(HWND, UINT, WPARAM, LPARAM);
INT_PTR CALLBACK    About(HWND, UINT, WPARAM, LPARAM);

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
    LoadStringW(hInstance, IDC_CIS023_S2018_LAB12E, szWindowClass, MAX_LOADSTRING);
    MyRegisterClass(hInstance);

    // Perform application initialization:
    if (!InitInstance (hInstance, nCmdShow))
    {
        return FALSE;
    }

    HACCEL hAccelTable = LoadAccelerators(hInstance, MAKEINTRESOURCE(IDC_CIS023_S2018_LAB12E));

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
    wcex.hIcon          = LoadIcon(hInstance, MAKEINTRESOURCE(IDI_CIS023_S2018_LAB12E));
    wcex.hCursor        = LoadCursor(nullptr, IDC_ARROW);
    wcex.hbrBackground  = (HBRUSH)(COLOR_WINDOW+1);
    wcex.lpszMenuName   = MAKEINTRESOURCEW(IDC_CIS023_S2018_LAB12E);
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
      CW_USEDEFAULT, 0, CW_USEDEFAULT, 0, nullptr, nullptr, hInstance, nullptr);

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

	case WM_KEYDOWN:					//key pressed
		POINT pShot=crossHair->KeyPressed(wParam);	//send the key that was pressed to the function and move the crosshair
		list->First();						//start at the top of the list

		while (list->GetCurrentBall() != nullptr)	//roll through the list until nullptr
		{
			if (list->GetCurrentBall()->Hit(pShot))
				list->Delete();
			else
				list->Next();

		}
	

		InvalidateRect(hWnd,
			&crossHair->GetInvalidateRect(), TRUE);

		break;
	case WM_TIMER:
		if (wParam == WM_TIMER_CREATE)		//add a ball
			list->Add();
		else if (wParam == WM_TIMER_MOVE)		//move all of the bvall obejcts
		{
			list->First();						//start at the top of the list

			while (list->GetCurrentBall() != nullptr)	//roll through the list until nullptr
			{
				InvalidateRect(hWnd, &list->GetCurrentBall()->GetInvalidateRect(), TRUE);	//force WM_PAINT to refresh
				list->GetCurrentBall()->Move(hWnd);

				list->Next();		//next object in list
				
			}

		}

		break;
    case WM_PAINT:
        {
            PAINTSTRUCT ps;
            HDC hdc = BeginPaint(hWnd, &ps);
            // TODO: Add any drawing code that uses hdc here...


			//draw the cross hair
			list->First();				//start athe top of list
			while (list->GetCurrentBall() != nullptr)
			{
				list->GetCurrentBall()->Draw(hdc);	//draw the obejct
				list->Next();						//next object
			}
			crossHair->Draw(hdc);

            EndPaint(hWnd, &ps);
        }
        break;
	case WM_CREATE:

		crossHair = new CrossHairClass(hWnd);			//create the crosshair
		list = new LinkedListClass;						//create linked list

		//start the timers
		SetTimer(hWnd, WM_TIMER_CREATE,1000,NULL);
		SetTimer(hWnd, WM_TIMER_MOVE, 100, NULL);


		break;
    case WM_DESTROY:

		if (crossHair)							//if there is a crosshair, delete it
			delete crossHair;		
		if (list)								//if there is a list, delete it
			delete list;				
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
