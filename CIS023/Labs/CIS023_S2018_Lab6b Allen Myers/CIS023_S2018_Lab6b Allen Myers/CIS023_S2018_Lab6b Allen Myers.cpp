//Module:	CIS023_S2018_Lab6b Allen Myers.cpp
//Project:	CIS023_S2018_Lab6b Allen Myers
//Author:	Allen Myers
//Date:		Feb 28th, 2018
//Purpose:	Create a class with operator overloaded.
//			Overload the class constructor.
//			Learn how to interact with operator overloads.
//			Interact with a main window based combo - box.
//
//

#include "stdafx.h"
#include "CIS023_S2018_Lab6b Allen Myers.h"

#define MAX_LOADSTRING 100

// Global Variables:
HINSTANCE hInst;                                // current instance
WCHAR szTitle[MAX_LOADSTRING];                  // The title bar text
WCHAR szWindowClass[MAX_LOADSTRING];            // the main window class name

HWND hWnd_Input_1;								// 1st input
HWND hWnd_Input_2;								// 2nd input
HWND hWnd_cboSelection;							// combo box
HWND hWnd_Output;								// output label

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
    LoadStringW(hInstance, IDC_CIS023_S2018_LAB6BALLENMYERS, szWindowClass, MAX_LOADSTRING);
    MyRegisterClass(hInstance);

    // Perform application initialization:
    if (!InitInstance (hInstance, nCmdShow))
    {
        return FALSE;
    }

    HACCEL hAccelTable = LoadAccelerators(hInstance, MAKEINTRESOURCE(IDC_CIS023_S2018_LAB6BALLENMYERS));

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
    wcex.hIcon          = LoadIcon(hInstance, MAKEINTRESOURCE(IDI_CIS023_S2018_LAB6BALLENMYERS));
    wcex.hCursor        = LoadCursor(nullptr, IDC_ARROW);
    wcex.hbrBackground  = (HBRUSH)(COLOR_WINDOW+1);
    wcex.lpszMenuName   = MAKEINTRESOURCEW(IDC_CIS023_S2018_LAB6BALLENMYERS);
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

   //HWND hWnd = CreateWindowW(szWindowClass, szTitle, WS_OVERLAPPEDWINDOW,
   //   CW_USEDEFAULT, 0, CW_USEDEFAULT, 0, nullptr, nullptr, hInstance, nullptr);
   HWND hWnd = CreateWindowW(szWindowClass, szTitle, WS_OVERLAPPEDWINDOW,
	   CW_USEDEFAULT, 0, 300, 250, nullptr, nullptr, hInstance, nullptr);

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
			case BN_CLICKED:											//button clicked
				if (LOWORD(lParam) == (WORD)hWnd_cboSelection &&		//combo box
					HIWORD(wParam) == CBN_SELCHANGE)					//selection changed
				{
					TCHAR szInLeft[100];								//user input, left edit control
					TCHAR szInRight[100];								//user input, right edit control
					GetWindowText(										//get text from edit control
						hWnd_Input_1,									//left edit control
						szInLeft,										//target TCHAR
						100												//max num of chars
					);
					GetWindowText(										//get text from edit control
						hWnd_Input_2,									//right edit control
						szInRight,										//target TCHAR
						100												//max num of chars
					);
					NumberClass numObjLeft(szInLeft);					//create object for left input
					NumberClass numObjRight(szInRight);					//create object for right input
				//for testing purposes
					//SetWindowText(										//set the output control text
					//	hWnd_Output,									//handle to output static control
					//	numObjLeft.GetNum()								//get stored integer(in TCHAR format)
					//);

					//SetWindowText(
					//	hWnd_Output,
					//	numObjLeft+numObjRight
					//);

					switch (SendMessage(hWnd_cboSelection, CB_GETCURSEL, NULL, NULL))
					{
					case 0:				//+
						SetWindowText(
							hWnd_Output,
							numObjLeft+numObjRight
						);
						break;
					case 1:				//-
						SetWindowText(
							hWnd_Output,
							numObjLeft - numObjRight
						);
						break;
					case 2:				//*
						SetWindowText(
							hWnd_Output,
							numObjLeft * numObjRight
						);
						break;
					case 3:				//"
						SetWindowText(
							hWnd_Output,
							numObjLeft / numObjRight
						);
						break;
					case 4:				//++ to the left object
						SetWindowText(
							hWnd_Output,
							++numObjLeft 
						);
						break;
					case 5:				//-- to the left object
						SetWindowText(
							hWnd_Output,
							--numObjLeft
						);
						break;
					default:
						break;


					}

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
	{

		// grey background
		CreateWindow(TEXT("STATIC"), TEXT(""),
			WS_VISIBLE | WS_CHILD, 0, 0, 300, 200, hWnd, NULL, NULL, NULL);

		// create prompts
		CreateWindow(TEXT("STATIC"),
			TEXT("Enter a Digit"),
			WS_VISIBLE | WS_CHILD,
			10, 10, 70, 40, hWnd, NULL, NULL, NULL);

		CreateWindow(TEXT("STATIC"),
			TEXT("Select Operation"),
			WS_VISIBLE | WS_CHILD,
			100, 10, 75, 40, hWnd, NULL, NULL, NULL);

		CreateWindow(TEXT("STATIC"),
			TEXT("Enter a Digit"),
			WS_VISIBLE | WS_CHILD,
			200, 10, 70, 40, hWnd, NULL, NULL, NULL);

		CreateWindow(TEXT("STATIC"),
			TEXT("Result:"),
			WS_VISIBLE | WS_CHILD,
			10, 140, 50, 20, hWnd, NULL, NULL, NULL);

		// create edit control for user input
		hWnd_Input_1 = CreateWindow(TEXT("EDIT"),
			NULL,
			WS_CHILD | WS_VISIBLE | WS_BORDER | ES_AUTOHSCROLL,//|ES_NUMBER,//can use ES_NUMBER to only allow numbers
			10, 50, 60, 20, hWnd, NULL, NULL, NULL);

		// create edit control for user input
		hWnd_Input_2 = CreateWindow(TEXT("EDIT"),
			NULL,
			WS_CHILD | WS_VISIBLE | WS_BORDER | ES_AUTOHSCROLL,//|ES_NUMBER,//can use ES_NUMBER to only allow numbers
			200, 50, 60, 20, hWnd, NULL, NULL, NULL);

		// create combo box
		hWnd_cboSelection = CreateWindow(
			TEXT("COMBOBOX"),								// type of object
			TEXT(""),										// default empty edit box
			CBS_DROPDOWN | CBS_HASSTRINGS |					// act like a typical combo box
			//	CBS_SORT |									// items are sorted in the listbox
			WS_CHILD | WS_OVERLAPPED | WS_VISIBLE | 		// attributesached to the main window
			WS_VSCROLL,										// scroll bar in list
			100, 50, 75, 200,								// location and size
			hWnd, NULL, NULL, NULL);						// parent window, the rest are not used here

															// create output lines
		hWnd_Output = CreateWindow(TEXT("STATIC"),
			TEXT(""),
			WS_VISIBLE | WS_CHILD | WS_BORDER,
			70, 140, 100, 20, hWnd, NULL, NULL, NULL);


		TCHAR Operations[6][4] =				// array of items that will be loaded into combo box
		{
			TEXT("+"),
			TEXT("-"),
			TEXT("*"),
			TEXT("/"),
			TEXT("++"),
			TEXT("- -"),
		};
		// load the array into the combo box
		for (int i = 0; i < 6; i++)
			SendMessage(hWnd_cboSelection, CB_ADDSTRING, NULL, (LPARAM)Operations[i]);


	}
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
