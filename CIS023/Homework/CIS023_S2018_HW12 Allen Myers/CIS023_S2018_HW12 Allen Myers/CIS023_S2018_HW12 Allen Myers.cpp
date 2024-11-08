//Module:	CIS023_S2018_HW12 Allen Myers.cpp
//Project:	CIS023_S2018_HW12 Allen Myers
//Author:	Allen Myers
//Date:		May 10th, 2018
//Purpose:	Review drawing shapes.
//			Set random values.
//			Create and use a timer.
//			Create moving figures.

#include "stdafx.h"
#include "CIS023_S2018_HW12 Allen Myers.h"

#define MAX_LOADSTRING 100
#define WM_TIMER_CREATE 2001					//
#define WM_TIMER_MOVE 2010						//
#define MaxEliipses 100

int iMaxEllipses;

// Global Variables:
HINSTANCE hInst;                                // current instance
WCHAR szTitle[MAX_LOADSTRING];                  // The title bar text
WCHAR szWindowClass[MAX_LOADSTRING];            // the main window class name

//LinkedListClass* list[MaxEliipses];				//linked list[iMaxEllipses]full of ellipses
LinkedListClass*list;

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
    LoadStringW(hInstance, IDC_CIS023_S2018_HW12ALLENMYERS, szWindowClass, MAX_LOADSTRING);
    MyRegisterClass(hInstance);

    // Perform application initialization:
    if (!InitInstance (hInstance, nCmdShow))
    {
        return FALSE;
    }

    HACCEL hAccelTable = LoadAccelerators(hInstance, MAKEINTRESOURCE(IDC_CIS023_S2018_HW12ALLENMYERS));

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
    wcex.hIcon          = LoadIcon(hInstance, MAKEINTRESOURCE(IDI_CIS023_S2018_HW12ALLENMYERS));
    wcex.hCursor        = LoadCursor(nullptr, IDC_ARROW);
    wcex.hbrBackground  = (HBRUSH)(COLOR_WINDOW+1);
    wcex.lpszMenuName   = MAKEINTRESOURCEW(IDC_CIS023_S2018_HW12ALLENMYERS);
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
			case ID_FILE_GO:
				//if (iMaxEllipses < MaxEliipses)
				//	list[++iMaxEllipses] = new LinkedListClass;
				//if (iMaxEllipses== 0)
				//	SetTimer(hWnd, WM_TIMER, 100, NULL);


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
	case WM_TIMER:

		if (wParam == WM_TIMER_CREATE)				//create a star
		{
	//list[iMaxEllipses]->Add(hWnd);						//
			list->Add(hWnd);

		}
		else										//move the stars
		{
	//list[iMaxEllipses]->First();							//start at top of list
			list->First();									//get first ellipse

			while (list->GetCurrentStar() != nullptr)	//scroll through list
			{
				InvalidateRect(hWnd,					//invalidate rectangle
					//&list->GetCurrentStar()->GetInvalidateRect(),
					NULL,
					TRUE
				);
				if (list->GetCurrentStar()->Move(hWnd))		//if good move
					list->Next();						//then next object
				else									//elsestar hit a wall
					list->Delete();						//delete it

			}

		}

		break;

	case WM_PAINT:
	{
		PAINTSTRUCT ps;
		HDC hdc = BeginPaint(hWnd, &ps);
		// TODO: Add any drawing code that uses hdc here...

		list->First();						//start at top of linked list

		while (list->GetCurrentStar() != nullptr)		//loop through list
		{
			list->GetCurrentStar()->Draw(hdc);			//draw a star
			list->Next();								//next star in list

		}


		EndPaint(hWnd, &ps);
	}
	break;
	case WM_CREATE:
		list= new LinkedListClass;				///create linked list

		SetTimer(hWnd, WM_TIMER_CREATE, 500, NULL);		//timer to create stars
		SetTimer(hWnd, WM_TIMER_MOVE, 100, NULL);		//timer to move stars
		break;
    case WM_DESTROY:

		if (list)
			delete list;							//destroy linked list

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
