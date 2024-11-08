//Module:	CIS023_S2018_Lab4a Allen Myers.cpp
//Project:	CIS023_S2018_Lab4a Allen Myers
//Author:	Allen Myers
//Date:		February 5th, 2018
//Purpose:	Create a base class with default methods and members.
//			Derive classes from the base class.
//			Interact with the derived classes.

//this project begins the intro to chapter 11-inheiritance
//deriving a class from another class

#include "stdafx.h"
#include "CIS023_S2018_Lab4a Allen Myers.h"

#define MAX_LOADSTRING 100

// Global Variables:
HINSTANCE hInst;                                // current instance
WCHAR szTitle[MAX_LOADSTRING];                  // The title bar text
WCHAR szWindowClass[MAX_LOADSTRING];            // the main window class name


//declare the data names from the WM_CREATE
//window handles
HWND hWnd_ID;
HWND hWnd_First;
HWND hWnd_Last;
HWND hWnd_Class[1];
HWND hWnd_Grade[1];
HWND hWnd_Load;
HWND hWnd_Base;
HWND hWnd_Name;
HWND hWnd_Grades;

//pointers to derived objects
NameClass*NameObject;
GradeClass*GradeObject[2];




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
    LoadStringW(hInstance, IDC_CIS023_S2018_LAB4AALLENMYERS, szWindowClass, MAX_LOADSTRING);
    MyRegisterClass(hInstance);

    // Perform application initialization:
    if (!InitInstance (hInstance, nCmdShow))
    {
        return FALSE;
    }

    HACCEL hAccelTable = LoadAccelerators(hInstance, MAKEINTRESOURCE(IDC_CIS023_S2018_LAB4AALLENMYERS));

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
    wcex.hIcon          = LoadIcon(hInstance, MAKEINTRESOURCE(IDI_CIS023_S2018_LAB4AALLENMYERS));
    wcex.hCursor        = LoadCursor(nullptr, IDC_ARROW);
    wcex.hbrBackground  = (HBRUSH)(COLOR_WINDOW+1);
    wcex.lpszMenuName   = MAKEINTRESOURCEW(IDC_CIS023_S2018_LAB4AALLENMYERS);
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
      CW_USEDEFAULT, 0, 340, 355, nullptr, nullptr, hInstance, nullptr);

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

				if (LOWORD(lParam) == (WORD)hWnd_Load)
				{
					//NameObject->Proof(37);
					NameObject->SetID(TEXT("111111111"));
					NameObject->SetFirst(TEXT("Doggy"));
					NameObject->SetLast(TEXT("Kitty"));
					GradeObject[0]->SetGrade(TEXT("A+"));
					GradeObject[1]->SetGrade(TEXT("B-"));
					
				
				}
				if (LOWORD(lParam) == (WORD)hWnd_Base)
				{
					TCHAR szID[100];

					_tcscpy_s(szID,				//destination
						NameObject->GetID()		//source
					);

					SetWindowText(hWnd_ID,		//target window
						szID					//tchar
					);
				}
				if (LOWORD(lParam) == (WORD)hWnd_Name)
				{
					TCHAR szFirst[100];
					TCHAR szLast[100];

					_tcscpy_s(szFirst, NameObject->GetFirst());
					_tcscpy_s(szLast, NameObject->GetLast());

					SetWindowText(hWnd_First, szFirst);
					SetWindowText(hWnd_Last, szLast);

				}
				if (LOWORD(lParam) == (WORD)hWnd_Grades)
				{
					TCHAR szGrade[100];

					_tcscpy_s(szGrade, GradeObject[0]->GetGrade());			//copy input to szGrade
					_tcscpy_s(szGrade, GradeObject[1]->GetGrade());			

					SetWindowText(hWnd_Grade[0], szGrade);



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
            // TODO: Add any drawing code that uses hdc here...
            EndPaint(hWnd, &ps);
        }
        break;


	case WM_CREATE:

		// grey background
		CreateWindow(TEXT("STATIC"), TEXT(""),
			WS_VISIBLE | WS_CHILD,
			0, 0, 330, 300,
			hWnd, NULL, NULL, NULL);

		// labels
		CreateWindow(
			TEXT("STATIC"),
			TEXT("ID Number:"),
			WS_VISIBLE | WS_CHILD,
			10, 10, 90, 20, hWnd, NULL, NULL, NULL);

		CreateWindow(
			TEXT("STATIC"),
			TEXT("Name:"),
			WS_VISIBLE | WS_CHILD,
			10, 50, 90, 20, hWnd, NULL, NULL, NULL);

		CreateWindow(
			TEXT("STATIC"),
			TEXT("Class"),
			WS_VISIBLE | WS_CHILD,
			10, 90, 90, 20, hWnd, NULL, NULL, NULL);

		CreateWindow(
			TEXT("STATIC"),
			TEXT("Grade"),
			WS_VISIBLE | WS_CHILD,
			200, 90, 90, 20, hWnd, NULL, NULL, NULL);

		// data
		hWnd_ID = CreateWindow(
			TEXT("STATIC"),
			TEXT("888888888"),
			WS_VISIBLE | WS_CHILD,
			100, 10, 90, 20, hWnd, NULL, NULL, NULL);

		hWnd_First = CreateWindow(
			TEXT("STATIC"),
			TEXT("BabyPuppy"),
			WS_VISIBLE | WS_CHILD,
			100, 50, 90, 20, hWnd, NULL, NULL, NULL);

		hWnd_Last = CreateWindow(
			TEXT("STATIC"),
			TEXT("Monkey"),
			WS_VISIBLE | WS_CHILD,
			200, 50, 90, 20, hWnd, NULL, NULL, NULL);

		hWnd_Class[0] = CreateWindow(
			TEXT("STATIC"),
			TEXT("CIS 001"),
			WS_VISIBLE | WS_CHILD,
			10, 120, 90, 20, hWnd, NULL, NULL, NULL);

		hWnd_Grade[0] = CreateWindow(
			TEXT("STATIC"),
			TEXT("A"),
			WS_VISIBLE | WS_CHILD,
			200, 120, 90, 20, hWnd, NULL, NULL, NULL);

		hWnd_Class[1] = CreateWindow(
			TEXT("STATIC"),
			TEXT("CIS 023"),
			WS_VISIBLE | WS_CHILD,
			10, 150, 90, 20, hWnd, NULL, NULL, NULL);

		hWnd_Grade[1] = CreateWindow(
			TEXT("STATIC"),
			TEXT("A"),
			WS_VISIBLE | WS_CHILD,
			200, 150, 90, 20, hWnd, NULL, NULL, NULL);


		// buttons
		hWnd_Load = CreateWindow(
			TEXT("BUTTON"),
			TEXT("Load"),
			WS_VISIBLE | WS_CHILD | BS_DEFPUSHBUTTON,
			120, 200, 90, 30, hWnd, NULL, NULL, NULL);

		hWnd_Base = CreateWindow(
			TEXT("BUTTON"),
			TEXT("Base"),
			WS_VISIBLE | WS_CHILD | BS_DEFPUSHBUTTON,
			20, 250, 90, 30, hWnd, NULL, NULL, NULL);

		hWnd_Name = CreateWindow(
			TEXT("BUTTON"),
			TEXT("Name"),
			WS_VISIBLE | WS_CHILD | BS_DEFPUSHBUTTON,
			120, 250, 90, 30, hWnd, NULL, NULL, NULL);

		hWnd_Grades = CreateWindow(
			TEXT("BUTTON"),
			TEXT("Grades"),
			WS_VISIBLE | WS_CHILD | BS_DEFPUSHBUTTON,
			220, 250, 90, 30, hWnd, NULL, NULL, NULL);


		//create objects
		NameObject = new NameClass;
		GradeObject[0] = new GradeClass;
		GradeObject[1] = new GradeClass;

		break;
    case WM_DESTROY:
		//destroy objects
		delete NameObject;
		delete GradeObject[0];
		delete GradeObject[1];

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
