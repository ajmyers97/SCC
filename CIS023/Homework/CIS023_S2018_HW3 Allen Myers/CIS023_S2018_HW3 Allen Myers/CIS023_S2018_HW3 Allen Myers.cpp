//Module: CIS023_S2018_HW3 Allen Myers.cpp
//Program:		CIS023_S2018_HW3 Allen Myers.
//Author:		Allen Myers
//Date:			February 3rd, 2018
//Purpose:		Create a class definition.
//				Create a pointer to an object from the class definition.
//				Destroy the object pointer when the program closes.
//				Call an object method.

#include "stdafx.h"
#include "CIS023_S2018_HW3 Allen Myers.h"

#define MAX_LOADSTRING 100

// Global Variables:
HINSTANCE hInst;                                // current instance
WCHAR szTitle[MAX_LOADSTRING];                  // The title bar text
WCHAR szWindowClass[MAX_LOADSTRING];            // the main window class name

//new functions added
HWND hWnd_Show;									//show button
HWND hWnd_Input_1;								//input edit box 1
HWND hWnd_Input_2;
HWND hWnd_Output;								//output edit box
HWND hWnd_Output2;

StringConversionClass* StringConversionObject;								//pointer to an object



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
    LoadStringW(hInstance, IDC_CIS023_S2018_HW3ALLENMYERS, szWindowClass, MAX_LOADSTRING);
    MyRegisterClass(hInstance);

    // Perform application initialization:
    if (!InitInstance (hInstance, nCmdShow))
    {
        return FALSE;
    }

    HACCEL hAccelTable = LoadAccelerators(hInstance, MAKEINTRESOURCE(IDC_CIS023_S2018_HW3ALLENMYERS));

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
    wcex.hIcon          = LoadIcon(hInstance, MAKEINTRESOURCE(IDI_CIS023_S2018_HW3ALLENMYERS));
    wcex.hCursor        = LoadCursor(nullptr, IDC_ARROW);
    wcex.hbrBackground  = (HBRUSH)(COLOR_WINDOW+1);
    wcex.lpszMenuName   = MAKEINTRESOURCEW(IDC_CIS023_S2018_HW3ALLENMYERS);
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
      CW_USEDEFAULT, 0, 300, 400, nullptr, nullptr, hInstance, nullptr);

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
				if (LOWORD(lParam) == (WORD)hWnd_Show)
				{
					TCHAR szInput_1[100];		//input 1
					TCHAR szInput_2[100];		//input 2
					TCHAR* szOutput;		//pointer to the output
					TCHAR* szOutput2;

											//get input strings
					SendMessage(hWnd_Input_1,	//handel to the window
						WM_GETTEXT,				//window message get text
						100,					//number of characters
						LPARAM(szInput_1));	//place to store the text

					SendMessage(hWnd_Input_2,	//handel to the window
						WM_GETTEXT,				//window message get text
						100,					//number of characters
						LPARAM(szInput_2));	//place to store the text


											//send strings to object
					szOutput = StringConversionObject->ConvertTCHARtoString(szInput_1);
					szOutput2 = StringConversionObject->ConvertStringtoTCHAR(szInput_2);



					//display return value(output)
					SetWindowText(hWnd_Output, szOutput);
					SetWindowText(hWnd_Output2, szOutput2);

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

		//grey background
		hWnd_Show = CreateWindow(
			TEXT("STATIC"),
			TEXT(""),
			WS_VISIBLE | WS_CHILD,
			0, 0, 300, 400,
			hWnd, NULL, NULL, NULL);

		//prompts
		hWnd_Show = CreateWindow(
			TEXT("STATIC"),
			TEXT("Enter Text"),
			WS_VISIBLE | WS_CHILD,
			10, 10, 75, 20,
			hWnd, NULL, NULL, NULL);

		hWnd_Show = CreateWindow(
			TEXT("STATIC"),
			TEXT("Enter Text"),
			WS_VISIBLE | WS_CHILD,
			10, 50, 75, 20,
			hWnd, NULL, NULL, NULL);

		//user input
		hWnd_Input_1 = CreateWindow(
			TEXT("EDIT"),
			TEXT(""),
			WS_VISIBLE | WS_CHILD | WS_BORDER | ES_AUTOHSCROLL,
			110, 10, 100, 20,
			hWnd, NULL, NULL, NULL);
		hWnd_Input_2 = CreateWindow(
			TEXT("EDIT"),
			TEXT(""),
			WS_VISIBLE | WS_CHILD | WS_BORDER | ES_AUTOHSCROLL,
			110, 50, 100, 20,
			hWnd, NULL, NULL, NULL);
		//button
		hWnd_Show = CreateWindow(
			TEXT("BUTTON"),
			TEXT("START"),
			WS_VISIBLE | WS_CHILD | BS_DEFPUSHBUTTON,
			90, 100, 90, 30,
			hWnd, NULL, NULL, NULL);

		//text output
		hWnd_Output = CreateWindow(
			TEXT("STATIC"),
			TEXT(""),
			WS_VISIBLE | WS_CHILD | WS_BORDER,
			10, 150, 250, 20,
			hWnd, NULL, NULL, NULL);
		hWnd_Output2= CreateWindow(
			TEXT("STATIC"),
			TEXT(""),
			WS_VISIBLE | WS_CHILD | WS_BORDER,
			10, 250, 250, 20,
			hWnd, NULL, NULL, NULL);

		//create the new object
		StringConversionObject = new StringConversionClass;			//create object of type MyClass

		break;


    case WM_DESTROY:
		//destroy the object
		delete StringConversionObject;

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
