//Module:	CIS021_S2019_Lab9b Allen Myers.cpp
//Project:	CIS021_S2019_Lab9b Allen Myers.cpp
//Author:	Allen Myers
//Date:		May 16th, 2019
//Purpose:	Understand modeling software.
//			Interpret an established formula into software.
//			Demonstrate the effect of formulaic modification on programmatic output.

#include "stdafx.h"
#include "CIS021_S2019_Lab9b Allen Myers.h"

#define MAX_LOADSTRING 100

// Global Variables:
HINSTANCE hInst;                                // current instance
WCHAR szTitle[MAX_LOADSTRING];                  // The title bar text
WCHAR szWindowClass[MAX_LOADSTRING];            // the main window class name

vector<GravitySim> vList;						//list of graphic objects

// Forward declarations of functions included in this code module:
ATOM                MyRegisterClass(HINSTANCE hInstance);
BOOL                InitInstance(HINSTANCE, int);
LRESULT CALLBACK    WndProc(HWND, UINT, WPARAM, LPARAM);
INT_PTR CALLBACK    About(HWND, UINT, WPARAM, LPARAM);

void DrawGrid(HWND, HDC);

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
    LoadStringW(hInstance, IDC_CIS021_S2019_LAB9BALLENMYERS, szWindowClass, MAX_LOADSTRING);
    MyRegisterClass(hInstance);

    // Perform application initialization:
    if (!InitInstance (hInstance, nCmdShow))
    {
        return FALSE;
    }

    HACCEL hAccelTable = LoadAccelerators(hInstance, MAKEINTRESOURCE(IDC_CIS021_S2019_LAB9BALLENMYERS));

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
    wcex.hIcon          = LoadIcon(hInstance, MAKEINTRESOURCE(IDI_CIS021_S2019_LAB9BALLENMYERS));
    wcex.hCursor        = LoadCursor(nullptr, IDC_ARROW);
    wcex.hbrBackground  = (HBRUSH)(COLOR_WINDOW+1);
    wcex.lpszMenuName   = MAKEINTRESOURCEW(IDC_CIS021_S2019_LAB9BALLENMYERS);
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


			//draw to a memory dc for flicker control

			//get window rect
			RECT rClient;
			GetClientRect(hWnd, &rClient);

			//create memory dc handle
			HDC memdc = CreateCompatibleDC(hdc);
			unsigned bpp = GetDeviceCaps(hdc, BITSPIXEL);
			HBITMAP hBmp = CreateBitmap(rClient.right,rClient.bottom,1,bpp,NULL);
			HBITMAP hTmpBmp = (HBITMAP)SelectObject(memdc, (HGDIOBJ)hBmp);
						
			DrawGrid(hWnd, memdc);						//call the DrawGrid Function

			for (auto sim : vList)
				sim.Draw(memdc);

			//blit emory dc to device dc
			BitBlt(hdc, 0, 0, rClient.right, rClient.bottom, memdc, 0, 0, SRCCOPY);


			//garbage collection
		//	SelectObject(hdc,hTmpBmp);
			DeleteObject(hBmp);
			DeleteDC(memdc);
						
			EndPaint(hWnd, &ps);
        }
        break;
	case WM_KEYDOWN:
	{
		GravitySim sim(hWnd);							//create a graphic object
		vList.push_back(sim);							//add to the vector
	}
		break;
	case WM_TIMER:

		for (vector<GravitySim>::size_type i = 0;i < vList.size();i++)
		{
			if (vList[i].Move(hWnd))						//move the graphic object
			{
				//InvalidateRect(hWnd, NULL, FALSE);

			}
			else
			{
			//	InvalidateRect(hWnd, NULL, TRUE);
			//	vList.erase(vList.begin() + i);			//delete object
			}
			InvalidateRect(hWnd, NULL, FALSE);

		}

		break;
	case WM_CREATE:
		SetTimer(hWnd, WM_TIMER,16, NULL);				//start move timer

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

//draw background grid
void DrawGrid(HWND hWnd, HDC hdc)
{
	//get client rect
	RECT rClient;
	GetClientRect(hWnd, &rClient);

	//background array
	CONST POINT pClient[] =								//array for background
	{	{rClient.left,rClient.top},
		{rClient.right,rClient.top },
		{rClient.right,rClient.bottom },
		{rClient.left,rClient.bottom },
		{rClient.left,rClient.top } };

	Polygon(hdc, pClient, 5);						//background in default white


	//vertical lines
	for (int i = 100;i <= rClient.right + 100;i += 100)
	{
		MoveToEx(hdc, i, 0, NULL);					//line start location
		LineTo(hdc, i, rClient.bottom + 100);		//draw line
	}
	//horizontal lines
	for (int i = 100;i <= rClient.bottom + 100;i += 100)
	{
		MoveToEx(hdc, 0,i, NULL);					//line start location
		LineTo(hdc, rClient.right + 100, i);		//draw line
	}

}