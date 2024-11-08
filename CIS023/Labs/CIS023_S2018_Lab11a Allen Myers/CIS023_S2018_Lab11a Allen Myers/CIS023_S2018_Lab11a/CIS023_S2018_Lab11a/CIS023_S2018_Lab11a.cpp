//Module:	CIS023_S2018_Lab11a.cpp
//Project:	CIS023_S2018_Lab11a
//Author:	Allen Myers	
//Date:		April 23rd, 2018
//Purpose:	Create the node class for binary tree data.
//			Create the binary tree class that controls the tree.
//			Load data from a file into a binary tree.
//			Delete a binary tree to prevent memory leaks.

#include "stdafx.h"
#include "CIS023_S2018_Lab11a.h"

#define MAX_LOADSTRING 100

// Global Variables:
HINSTANCE hInst;                                // current instance
WCHAR szTitle[MAX_LOADSTRING];                  // The title bar text
WCHAR szWindowClass[MAX_LOADSTRING];            // the main window class name

HWND hWnd_Input;								// edit control
HWND hWnd_Output;								// static control
HWND hWnd_Search;								// button
HWND hWnd_Close;								// button

char szFileName[] = "CIS023_S2018_Lab11a_Data.txt";			// file that contains data for binary tree

bTreeClass*tree;				//binary tree




// Forward declarations of functions included in this code module:
ATOM                MyRegisterClass(HINSTANCE hInstance);
BOOL                InitInstance(HINSTANCE, int);
LRESULT CALLBACK    WndProc(HWND, UINT, WPARAM, LPARAM);
INT_PTR CALLBACK    About(HWND, UINT, WPARAM, LPARAM);

BOOL LoadTree();								// file read, bTree load

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
    LoadStringW(hInstance, IDC_CIS023_S2018_LAB11A, szWindowClass, MAX_LOADSTRING);
    MyRegisterClass(hInstance);

    // Perform application initialization:
    if (!InitInstance (hInstance, nCmdShow))
    {
        return FALSE;
    }

    HACCEL hAccelTable = LoadAccelerators(hInstance, MAKEINTRESOURCE(IDC_CIS023_S2018_LAB11A));

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
    wcex.hIcon          = LoadIcon(hInstance, MAKEINTRESOURCE(IDI_CIS023_S2018_LAB11A));
    wcex.hCursor        = LoadCursor(nullptr, IDC_ARROW);
    wcex.hbrBackground  = (HBRUSH)(COLOR_WINDOW+1);
    wcex.lpszMenuName   = MAKEINTRESOURCEW(IDC_CIS023_S2018_LAB11A);
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
      CW_USEDEFAULT, 0, 325, 250, nullptr, nullptr, hInstance, nullptr);

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
		CreateWindow(TEXT("STATIC"),	// background
			TEXT(""),
			WS_VISIBLE | WS_CHILD, 0, 0, 350, 225, hWnd, NULL, NULL, NULL);

		CreateWindow(TEXT("STATIC"),
			TEXT("Binary Tree Search"),
			WS_VISIBLE | WS_CHILD, 80, 10, 150, 20, hWnd, NULL, NULL, NULL);

		CreateWindow(TEXT("STATIC"),
			TEXT("Search text:"),
			WS_VISIBLE | WS_CHILD, 20, 50, 100, 20, hWnd, NULL, NULL, NULL);

		hWnd_Input = CreateWindow(TEXT("EDIT"),
			NULL, WS_CHILD | WS_VISIBLE | WS_BORDER | ES_AUTOHSCROLL | WS_CHILD,
			140, 50, 150, 20, hWnd, NULL, NULL, NULL);

		CreateWindow(TEXT("STATIC"),
			TEXT("String found:"),
			WS_VISIBLE | WS_CHILD, 20, 90, 100, 20, hWnd, NULL, NULL, NULL);

		hWnd_Output = CreateWindow(TEXT("STATIC"),
			TEXT(""),
			WS_VISIBLE | WS_CHILD, 140, 90, 150, 20, hWnd, NULL, NULL, NULL);

		hWnd_Search = CreateWindow(TEXT("BUTTON"), TEXT("Search"),
			WS_VISIBLE | WS_CHILD | BS_DEFPUSHBUTTON,
			60, 130, 70, 30, hWnd, NULL, NULL, NULL);

		hWnd_Close = CreateWindow(TEXT("BUTTON"), TEXT("Close"),
			WS_VISIBLE | WS_CHILD | BS_DEFPUSHBUTTON,
			150, 130, 70, 30, hWnd, NULL, NULL, NULL);

		EnableWindow(hWnd_Search, false);		// disable search button

		if (LoadTree())
			EnableWindow(hWnd_Search, true);	// enable search button if tree loaded
	}
	break;

	case WM_DESTROY:
		if (tree)			//if there is a binary tree, delete it
			delete tree;

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

// read the file and load the binary tree
BOOL LoadTree()
{
	ifstream inFile;						// file handle
	string strLine;							// a line in the file

	try
	{
		inFile.open(szFileName);			// open the file

		if (!inFile.is_open())
			throw 0;
		tree = new bTreeClass;				//create the binary tree

		getline(inFile, strLine);
		while (inFile.good())				// if more to read
		{
			tree->Insert(strLine);			//append new leaf to binary tree


			getline(inFile, strLine);		// get the next line from the file
		}

		inFile.close();						// close the file
	}
	catch (int)
	{
		MessageBox(NULL, TEXT("Failed to open data file"), TEXT("File I/O Error"), MB_ICONERROR);
		return false;
	}

	return true;
}
