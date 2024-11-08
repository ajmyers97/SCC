// Module: CIS023_S2018_Lab2a Allen Myers.cpp 
// Project: CIS023_S2018_Lab2a Allen Myers
//Author: Allen Myers
//Date: January 22nd, 2018
//Purpose: Learn the steps necessary to interact with a file.
//			Add controls to a window.
//			Interact with a button and edit controls on a window.
//			Review the declaration and interaction with a struct.
//


#include "stdafx.h"
#include "CIS023_S2018_Lab2a Allen Myers.h"

#define MAX_LOADSTRING 100

// Global Variables:
HINSTANCE hInst;                                // current instance
WCHAR szTitle[MAX_LOADSTRING];                  // The title bar text
WCHAR szWindowClass[MAX_LOADSTRING];            // the main window class name

HWND hWnd_Input;								// input edit box
HWND hWnd_Open;									// button
HWND hWnd_Out[5];									//text ouput array

struct  FILESTRUCTTYPE
{
	string strLine[5];
}fStruct;

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
    LoadStringW(hInstance, IDC_CIS023_S2018_LAB2AALLENMYERS, szWindowClass, MAX_LOADSTRING);
    MyRegisterClass(hInstance);

    // Perform application initialization:
    if (!InitInstance (hInstance, nCmdShow))
    {
        return FALSE;
    }

    HACCEL hAccelTable = LoadAccelerators(hInstance, MAKEINTRESOURCE(IDC_CIS023_S2018_LAB2AALLENMYERS));

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
    wcex.hIcon          = LoadIcon(hInstance, MAKEINTRESOURCE(IDI_CIS023_S2018_LAB2AALLENMYERS));
    wcex.hCursor        = LoadCursor(nullptr, IDC_ARROW);
    wcex.hbrBackground  = (HBRUSH)(COLOR_WINDOW+1);
    wcex.lpszMenuName   = MAKEINTRESOURCEW(IDC_CIS023_S2018_LAB2AALLENMYERS);
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
      CW_USEDEFAULT, 0, 300, 400, nullptr, nullptr, hInstance, nullptr); //this tells the dimensions of the window.

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
			case BN_CLICKED:  //button clicked
				if (LOWORD(lParam) == (WORD)hWnd_Open)
				{
					//user input and output
					TCHAR szInput[100];  //user input file name
					ifstream fInput;	//file handle
					string strInput;	//file input
					int iIndex = 0;		//index of struct array
					TCHAR szOutput[100];	//text to be written to window

					//get the text from the input box
					SendMessage(hWnd_Input, //handle to edit box
						WM_GETTEXT,			//GET TEXT
						100,				//max chars to get
						LPARAM(szInput));	//destination tChar

					//open the file
					fInput.open(szInput);
					if (fInput.is_open())		//did it open okay?
					{
						getline(fInput, strInput); //read a lien from a file
						while (fInput.good())	//read until end of file
						{
							
							fStruct.strLine[iIndex++] = strInput; //copy to structure

							getline(fInput, strInput); //read a lien from a file

						}

						fInput.close();		//close the file
					}

					int j = 0;

					for (int i = 0;i < 5;i++)
					{
						size_t pRet;		//conversion return value

						mbstowcs_s(				//convert string to TCHAR
							&pRet,				//address of return value
							szOutput,			//destination
							100,				//size of destination
							fStruct.strLine[i].c_str(),	//source
							100);				//max chars to copy

						SetWindowText(			//set window text
							hWnd_Out[i],		//window to be set
							szOutput);			//source
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
		//GREY BACKGROUND
		CreateWindow(TEXT("STATIC"),
			TEXT(""),
			WS_VISIBLE | WS_CHILD,
			0, 0, 300, 400,
			hWnd, NULL, NULL, NULL);
		//INPUT PROMPT
		CreateWindow(TEXT("STATIC"),
			TEXT("Please enter a file name:"),
			WS_VISIBLE | WS_CHILD,
			10, 10, 250, 300,
			hWnd, NULL, NULL,  NULL);
		//EDIT CONTROL FOR USER INPUT
		hWnd_Input = CreateWindow(TEXT("EDIT"),
			TEXT(""),
			WS_VISIBLE | WS_CHILD | WS_BORDER | ES_AUTOHSCROLL,
			185, 10, 90, 20,
			hWnd, NULL, NULL,  NULL);
		//BUTTON
		hWnd_Open= CreateWindow(TEXT("Button"),
			TEXT("OPEN"),
			WS_VISIBLE | WS_CHILD | BS_DEFPUSHBUTTON,
			90,80,90,30,
			hWnd, NULL, NULL, NULL);

		//file ouput of text
		hWnd_Out[0]= CreateWindow(TEXT("STATIC"),
			TEXT(""),
			WS_VISIBLE | WS_CHILD,
			10, 150, 250, 20,
			hWnd, NULL, NULL, NULL);

		hWnd_Out[1] = CreateWindow(TEXT("STATIC"),
			TEXT(""),
			WS_VISIBLE | WS_CHILD,
			10, 190, 250, 20,
			hWnd, NULL, NULL, NULL);

		hWnd_Out[2] = CreateWindow(TEXT("STATIC"),
			TEXT(""),
			WS_VISIBLE | WS_CHILD,
			10, 230, 250, 20,
			hWnd, NULL, NULL, NULL);

		hWnd_Out[3] = CreateWindow(TEXT("STATIC"),
			TEXT(""),
			WS_VISIBLE | WS_CHILD,
			10, 270, 250, 20,
			hWnd, NULL, NULL, NULL);

		hWnd_Out[4] = CreateWindow(TEXT("STATIC"),
			TEXT(""),
			WS_VISIBLE | WS_CHILD,
			10, 310, 250, 20,
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
