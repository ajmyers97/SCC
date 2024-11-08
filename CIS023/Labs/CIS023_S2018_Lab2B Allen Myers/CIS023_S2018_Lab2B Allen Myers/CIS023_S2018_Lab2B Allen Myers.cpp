//Module:	 CIS023_S2018_Lab2B Allen Myers.cpp
//Project:	 CIS023_S2018_Lab2B Allen Myers
//Author:	 Allen Myers
//Date:		 January 24th, 2018
//Purpose:	 Learn the steps necessary to create a working listbox.
//			 Add text items to a listbox.
//			 Review file I / O.
//

#include "stdafx.h"
#include "CIS023_S2018_Lab2B Allen Myers.h"

#define MAX_LOADSTRING 100

// Global Variables:
HINSTANCE hInst;                                // current instance
WCHAR szTitle[MAX_LOADSTRING];                  // The title bar text
WCHAR szWindowClass[MAX_LOADSTRING];            // the main window class name

HWND hWnd_Load;									//load button
HWND hWnd_ListBox;								//list box

struct StatesStruct								//defined structure
{
	string strState;
};
StatesStruct States[50];						//array of 50 structs for 50 states


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
    LoadStringW(hInstance, IDC_CIS023_S2018_LAB2BALLENMYERS, szWindowClass, MAX_LOADSTRING);
    MyRegisterClass(hInstance);

    // Perform application initialization:
    if (!InitInstance (hInstance, nCmdShow))
    {
        return FALSE;
    }

    HACCEL hAccelTable = LoadAccelerators(hInstance, MAKEINTRESOURCE(IDC_CIS023_S2018_LAB2BALLENMYERS));

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
    wcex.hIcon          = LoadIcon(hInstance, MAKEINTRESOURCE(IDI_CIS023_S2018_LAB2BALLENMYERS));
    wcex.hCursor        = LoadCursor(nullptr, IDC_ARROW);
    wcex.hbrBackground  = (HBRUSH)(COLOR_WINDOW+1);
    wcex.lpszMenuName   = MAKEINTRESOURCEW(IDC_CIS023_S2018_LAB2BALLENMYERS);
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
//      CW_USEDEFAULT, 0, CW_USEDEFAULT, 0, nullptr, nullptr, hInstance, nullptr);
		CW_USEDEFAULT, 0, 200, 300, nullptr, nullptr, hInstance, nullptr);

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
			case BN_CLICKED:			//button clicked
				if (LOWORD(lParam) == (WORD)hWnd_Load)
				{
					fstream fInput;		//file handle
					string strLine;		//a line from the file
					TCHAR szOuput[100]; //output string

					fInput.open("CIS023_S2018_Lab2b_data.txt"); //open the file
					if (fInput.is_open())	//did the file open?
					{
						int iIndex = 0;			//file line number
						getline(fInput, strLine);	//read the first line of the file
						while (fInput.good())		//if latest read got a line
						{
							//load line from file into struct array
							States[iIndex++].strState = strLine;

							getline(fInput, strLine);	//read next line

						}

						fInput.close();		//close the file

						//load the list box from the array of the struct
						for (iIndex = 0; iIndex < 50; iIndex++)
						{

							size_t pRet;	//return value for mbstowcs_s

							mbstowcs_s(		//covert input string to TCHAR
								&pRet,
								szOuput,	//output TCHAR
								100,		//size of output
								States[iIndex].strState.c_str(),	//source string
								100);			//max # of chars to copy

							//send text to list box
							SendMessage(	//send output string to listbox
								hWnd_ListBox,	//LISTBOX
								LB_ADDSTRING,	//APPEND STRING TO LIST
								NULL,			//PARAMETER NOT USED
								LPARAM(szOuput));	//string
						}

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

		//CREATE THE LISTBOX
		hWnd_ListBox = CreateWindow(
			TEXT("LISTBOX"),
			TEXT(""),
			WS_VISIBLE | WS_CHILD | WS_VSCROLL | WS_BORDER,
			20, 20, 150, 140,
			hWnd, NULL, NULL, NULL);

		//create the button
		hWnd_Load=CreateWindow(
			TEXT("BUTTON"),
			TEXT("LOAD"),
			WS_VISIBLE | WS_CHILD | BS_DEFPUSHBUTTON,
			50 ,180 ,90 ,30 ,
			hWnd, NULL, NULL, NULL);




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
