// Project:		CIS021_S2019_Lab6c
// Module:		CIS021_S2019_Lab6c.cpp
// Author:		Mark Berrett
// Date:		March 26, 2019
// Purpose:		Understand how Venn diagrams present data.
//				Learn how to code a 1, 2, and 3 - circle Venn diagram.
//
// Update		2
// Author:		Allen Myers
// Date:		April 9th, 2019
// Modification: Completed 3rd Circle
// 
//

#include "stdafx.h"
#include "CIS021_S2019_Lab6c.h"

#define MAX_LOADSTRING 100

// Global Variables:
HINSTANCE hInst;                                // current instance
WCHAR szTitle[MAX_LOADSTRING];                  // The title bar text
WCHAR szWindowClass[MAX_LOADSTRING];            // the main window class name

VennDiagram* Venn;								// VennDiagram object

// Forward declarations of functions included in this code module:
ATOM                MyRegisterClass(HINSTANCE hInstance);
BOOL                InitInstance(HINSTANCE, int);
LRESULT CALLBACK    WndProc(HWND, UINT, WPARAM, LPARAM);
INT_PTR CALLBACK    About(HWND, UINT, WPARAM, LPARAM);
INT_PTR CALLBACK    VennDlg(HWND, UINT, WPARAM, LPARAM);

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
    LoadStringW(hInstance, IDC_CIS021_S2019_LAB6C, szWindowClass, MAX_LOADSTRING);
    MyRegisterClass(hInstance);

    // Perform application initialization:
    if (!InitInstance (hInstance, nCmdShow))
    {
        return FALSE;
    }

    HACCEL hAccelTable = LoadAccelerators(hInstance, MAKEINTRESOURCE(IDC_CIS021_S2019_LAB6C));

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
    wcex.hIcon          = LoadIcon(hInstance, MAKEINTRESOURCE(IDI_CIS021_S2019_LAB6C));
    wcex.hCursor        = LoadCursor(nullptr, IDC_ARROW);
    wcex.hbrBackground  = (HBRUSH)(COLOR_WINDOW+1);
    wcex.lpszMenuName   = MAKEINTRESOURCEW(IDC_CIS021_S2019_LAB6C);
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
			case ID_FILE_VENN:
				DialogBox(hInst, MAKEINTRESOURCE(IDD_DLG_SELECT), hWnd, VennDlg);
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

		Venn->Draw(hdc);							// draw diagram on main window

		EndPaint(hWnd, &ps);
	}
	break;
	case WM_CREATE:
		Venn = new VennDiagram(hWnd);					// create Venn object
		break;
	
	case WM_DESTROY:

		if (Venn)
			delete Venn;								// delete venn object
		
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

// Message handler for venn box.
INT_PTR CALLBACK VennDlg(HWND hDlg, UINT message, WPARAM wParam, LPARAM lParam)
{
	UNREFERENCED_PARAMETER(lParam);
	switch (message)
	{
	case WM_INITDIALOG:								// pre-set dialog box to current Venn configurations

													// which radio button is set
		if (Venn->GetNumCircles() == 2)
			SendDlgItemMessage(hDlg, IDC_RDO_2, BM_SETCHECK, true, NULL);
		else if (Venn->GetNumCircles() == 3)
			SendDlgItemMessage(hDlg, IDC_RDO_3, BM_SETCHECK, true, NULL);
		else // default: turn on default 1-circle radio button
			SendDlgItemMessage(hDlg, IDC_RDO_1, BM_SETCHECK, true, NULL);

		// is overlap checkbox checked
		if (Venn->GetOverlap())
			SendDlgItemMessage(hDlg, IDC_CHK_OVERLAP, BM_SETCHECK, true, NULL);
		else
			SendDlgItemMessage(hDlg, IDC_CHK_OVERLAP, BM_SETCHECK, false, NULL);

		// set title text
		SetDlgItemText(hDlg, IDC_TITLE, (LPCWSTR)Venn->GetTitles(0));
		SetDlgItemText(hDlg, IDC_SUBTITLE, (LPCWSTR)Venn->GetTitles(1));

		// set label text
		SetDlgItemText(hDlg, IDC_LABEL_1, (LPCWSTR)Venn->GetLabels(0));
		SetDlgItemText(hDlg, IDC_LABEL_2, (LPCWSTR)Venn->GetLabels(1));
		SetDlgItemText(hDlg, IDC_LABEL_3, (LPCWSTR)Venn->GetLabels(2));
		SetDlgItemText(hDlg, IDC_LABEL_4, (LPCWSTR)Venn->GetLabels(3));
		SetDlgItemText(hDlg, IDC_LABEL_5, (LPCWSTR)Venn->GetLabels(4));
		SetDlgItemText(hDlg, IDC_LABEL_6, (LPCWSTR)Venn->GetLabels(5));
		SetDlgItemText(hDlg, IDC_LABEL_7, (LPCWSTR)Venn->GetLabels(6));

		return (INT_PTR)TRUE;

	case WM_COMMAND:
		if (LOWORD(wParam) == IDOK)
		{
			TCHAR szTitle[TCHAR_SIZE];
			TCHAR szSubTitle[TCHAR_SIZE];
			TCHAR szLabel[TCHAR_SIZE];
			bool bOverlap =							// true if overlap checkbox checked
				SendDlgItemMessage(hDlg, IDC_CHK_OVERLAP, BM_GETCHECK, NULL, NULL);

			GetDlgItemText(hDlg, IDC_TITLE, szTitle, TCHAR_SIZE);
			GetDlgItemText(hDlg, IDC_SUBTITLE, szSubTitle, TCHAR_SIZE);

			// how many circles
			if (SendDlgItemMessage(hDlg, IDC_RDO_1, BM_GETCHECK, NULL, NULL))
				Venn->SetNumCircles(1);				// 1-circle
			else if (SendDlgItemMessage(hDlg, IDC_RDO_2, BM_GETCHECK, NULL, NULL))
				Venn->SetNumCircles(2);				// 2-circles
			else if (SendDlgItemMessage(hDlg, IDC_RDO_3, BM_GETCHECK, NULL, NULL))
				Venn->SetNumCircles(3);				// 3-circles

			Venn->SetOverlap(bOverlap);				// true if overlap checkbox checked
			Venn->SetTitles(0, szTitle);			// save titles
			Venn->SetTitles(1, szSubTitle);			// save titles

													// save label text
			GetDlgItemText(hDlg, IDC_LABEL_1, szLabel, TCHAR_SIZE);
			Venn->SetLabels(0, szLabel);
			GetDlgItemText(hDlg, IDC_LABEL_2, szLabel, TCHAR_SIZE);
			Venn->SetLabels(1, szLabel);
			GetDlgItemText(hDlg, IDC_LABEL_3, szLabel, TCHAR_SIZE);
			Venn->SetLabels(2, szLabel);
			GetDlgItemText(hDlg, IDC_LABEL_4, szLabel, TCHAR_SIZE);
			Venn->SetLabels(3, szLabel);
			GetDlgItemText(hDlg, IDC_LABEL_5, szLabel, TCHAR_SIZE);
			Venn->SetLabels(4, szLabel);
			GetDlgItemText(hDlg, IDC_LABEL_6, szLabel, TCHAR_SIZE);
			Venn->SetLabels(5, szLabel);
			GetDlgItemText(hDlg, IDC_LABEL_7, szLabel, TCHAR_SIZE);
			Venn->SetLabels(6, szLabel);

			// force the main window to paint to show new diagram
			Venn->NewDiagram();


			EndDialog(hDlg, LOWORD(wParam));
			return (INT_PTR)TRUE;
		}
		if (LOWORD(wParam) == IDCANCEL)
		{
			EndDialog(hDlg, LOWORD(wParam));
			return (INT_PTR)TRUE;
		}
		break;
	}
	return (INT_PTR)FALSE;
}
