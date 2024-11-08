//Module:	CIS023_S2018_LAB12A Allen Myers.cpp : Defines the entry point for the application.
//Project:	CIS023_S2018_LAB12A Allen Myers.
//Author:	Allen Myers
//Date:		April 30th, 2018
//Purpose:	Load graphic files into the project resources.
//			Load graphic resources into the program.
//			Display graphics.
//			Understand the WM_PAINT message.

#include "stdafx.h"
#include "CIS023_S2018_LAB12A Allen Myers.h"

#define MAX_LOADSTRING 100

// Global Variables:
HINSTANCE hInst;                                // current instance
WCHAR szTitle[MAX_LOADSTRING];                  // The title bar text
WCHAR szWindowClass[MAX_LOADSTRING];            // the main window class name

HBITMAP hBitmap1 = nullptr;						//handle to background bitmap
HBITMAP hBitmap2 = nullptr;						//handle to foreground bitmap

int SunLocationX = 0;							//x location of hBitmap2
int SunLocationY = 0;							//y location of hBitmap2

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
    LoadStringW(hInstance, IDC_CIS023_S2018_LAB12AALLENMYERS, szWindowClass, MAX_LOADSTRING);
    MyRegisterClass(hInstance);

    // Perform application initialization:
    if (!InitInstance (hInstance, nCmdShow))
    {
        return FALSE;
    }

    HACCEL hAccelTable = LoadAccelerators(hInstance, MAKEINTRESOURCE(IDC_CIS023_S2018_LAB12AALLENMYERS));

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
    wcex.hIcon          = LoadIcon(hInstance, MAKEINTRESOURCE(IDI_CIS023_S2018_LAB12AALLENMYERS));
    wcex.hCursor        = LoadCursor(nullptr, IDC_ARROW);
    wcex.hbrBackground  = (HBRUSH)(COLOR_WINDOW+1);
    wcex.lpszMenuName   = MAKEINTRESOURCEW(IDC_CIS023_S2018_LAB12AALLENMYERS);
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
    case WM_PAINT:
        {
            PAINTSTRUCT ps;
            HDC hdc = BeginPaint(hWnd, &ps);
			//HDC=handle to device context
			HDC hmemdc = nullptr;				//copy of device control handle
			BITMAP bitmap;						//copy of bitmap in ram

			hBitmap1 =							//load resource
				(HBITMAP)LoadImage(				//load image
					hInst,						//the program that contains the resource
					MAKEINTRESOURCE(IDB_BITMAP1),	//ID number of resource
					IMAGE_BITMAP,					//type of resource
					0,								//x coordinate
					0,								//y coordinate
					NULL							//load instance
					);

			hmemdc = CreateCompatibleDC(hdc);		//copy of device contact handle
			SelectObject(hmemdc, hBitmap1);			//select bitmap
			GetObject(hBitmap1, sizeof(BITMAP), &bitmap);	//load bitmpa into hdc copy

			RECT rClient;							//will hold bitmap dimensions
			GetClientRect(hWnd, &rClient);			//get dimensions of main window

			//stretch first bitmap into the window
			StretchBlt(								//display bitmap, adjusted by stretching
				hdc,								//handle to destination window
				0,									//x coord of upper left corner of window
				0,									//y coord
				rClient.right,						//width of window
				rClient.bottom,						//height of window
				hmemdc,								//handle to the bitmap
				0,									//x coord of upper left corner of bitmpa
				0,									//y coord
				bitmap.bmWidth,						//width of bitmap
				bitmap.bmHeight,					//height of bitmap
				SRCCOPY								//copy bitmap to window
			);

			//second bitmap 
			hBitmap2 =								//return a handle to the bitmap
				(HBITMAP)LoadImage(					//load image
					hInst,							//program that contains the resource
					MAKEINTRESOURCE(IDB_BITMAP2),	//id number of resource
					IMAGE_BITMAP,					//type of resource
					0,								//x coordinate
					0,								//y coord
					NULL							//load instructions

					);
			SelectObject(hmemdc, hBitmap2);		//select object
			GetObject(hBitmap2, sizeof(BITMAP), &bitmap);	//load second bitmap into memory

			int vert = rClient.bottom / 3.75;		//that far above the bottom 
			int horz = rClient.right - bitmap.bmWidth;	//stuck to the right

			//load second bitmap onto first bitmap
			BitBlt(								//display bitmap, no stretching
				hdc,							//handle to destination window
				SunLocationX,								//x coord of upper left of window
				SunLocationY,								//y coord of upper left of window
				bitmap.bmWidth,					//width of bitmap
				bitmap.bmHeight,				//height of bitmap
				hmemdc,							//handle to bitmap
				0,								//x coord of upper left of bitmap
				0,								//y coord of upper left of bitmap
				SRCCOPY							//copy bitmap to window
				);



            EndPaint(hWnd, &ps);
        }
        break;
	case WM_TIMER:								//timer tick

		SunLocationX+=10;
		SunLocationY++;

		InvalidateRect(							//trigger WM_PAINT
			hWnd,								//main window
			NULL,								//rectangle to paint, NULL=whole window
			FALSE);								//refresh?


		break;
	case WM_CREATE:
		SetTimer(								//turn on a timer
			hWnd,								//attached to a main window
			WM_TIMER,							//message to send at timer tick
			100,								//100 milliseconds
			NULL								//function to trigger at tick
		);

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
