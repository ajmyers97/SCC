// Project:		CIS021_S2019_Lab2b
// Module:		CIS021_S2019_Lab2b.cpp
// Author:		Elli Aylor
// Date:		January 24, 2019
// Purpose:		Understand logic conjunctions.
//				Perform Boolean operations on numeric input.
//				Determine outcomes of Boolean operations.
//

#include "stdafx.h"
#include "CIS021_S2019_Lab2b.h"

#define MAX_LOADSTRING 100

// Global Variables:
HINSTANCE hInst;                                // current instance
WCHAR szTitle[MAX_LOADSTRING];                  // The title bar text
WCHAR szWindowClass[MAX_LOADSTRING];            // the main window class name

HWND hWnd_cboA;									// A binary combo box
HWND hWnd_cboB;									// B binary combo box
HWND hWnd_cboGate;								// NOT, AND, OR, etc.
HWND hWnd_Result;								// output binary number
HWND hWnd_cboOutcome;							// outcome combo box
HWND hWnd_Not;									// operation indicators
HWND hWnd_And;									// .
HWND hWnd_Or;									// .
HWND hWnd_Nand;									// .
HWND hWnd_Nor;									// .
HWND hWnd_Xor;									// .
HWND hWnd_Xnor;									// .
HWND hWnd_s_Outcome;							// label
HWND hWnd_s_Operations;							// label

// Forward declarations of functions included in this code module:
ATOM                MyRegisterClass(HINSTANCE hInstance);
BOOL                InitInstance(HINSTANCE, int);
LRESULT CALLBACK    WndProc(HWND, UINT, WPARAM, LPARAM);
INT_PTR CALLBACK    About(HWND, UINT, WPARAM, LPARAM);

void LoadCombos();								// complete WM_CREATE

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
    LoadStringW(hInstance, IDC_CIS021_S2019_LAB2B, szWindowClass, MAX_LOADSTRING);
    MyRegisterClass(hInstance);

    // Perform application initialization:
    if (!InitInstance (hInstance, nCmdShow))
    {
        return FALSE;
    }

    HACCEL hAccelTable = LoadAccelerators(hInstance, MAKEINTRESOURCE(IDC_CIS021_S2019_LAB2B));

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
    wcex.hIcon          = LoadIcon(hInstance, MAKEINTRESOURCE(IDI_CIS021_S2019_LAB2B));
    wcex.hCursor        = LoadCursor(nullptr, IDC_ARROW);
    wcex.hbrBackground  = (HBRUSH)(COLOR_WINDOW+0);
    wcex.lpszMenuName   = MAKEINTRESOURCEW(IDC_CIS021_S2019_LAB2B);
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
      CW_USEDEFAULT, 0, 500, 300, nullptr, nullptr, hInstance, nullptr);

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
				if (HIWORD(wParam) == CBN_SELCHANGE)
				{
					BooleanClass BoolObj;                   // calc result
					TCHAR* szOutput;                        // return value for display
					bool bOperations[7];                    // NOT through XNOR

					szOutput = BoolObj.CalcResult(          // perform operation
						SendMessage(hWnd_cboA,              // get top number
							CB_GETCURSEL,                   // get combo selection
							NULL, NULL),                    // params not used
						SendMessage(hWnd_cboB,              // get bottom number
							CB_GETCURSEL,                   // get combo selection
							NULL, NULL),                    // params not used
						SendMessage(hWnd_cboGate,           // get operation
							CB_GETCURSEL,                   // get combo selection
							NULL, NULL)                     // params not used
					);

					SetWindowText(                          // show result
						hWnd_Result,                        // result label
						szOutput);                          // display TCHAR

					BoolObj.FindOperation(                  // determine operations
						SendMessage(hWnd_cboA,              // get top number
							CB_GETCURSEL,                   // get combo selection
							NULL, NULL),                    // params not used
						SendMessage(hWnd_cboB,              // get bottom number
							CB_GETCURSEL,                   // get combo selection
							NULL, NULL),                    // params not used
						SendMessage(hWnd_cboOutcome,        // result
							CB_GETCURSEL,                   // get combo selection
							NULL, NULL),                    // params not used)
						bOperations);                       // return array

					// show results
					ShowWindow(hWnd_Not, bOperations[0]);
					ShowWindow(hWnd_And, bOperations[1]);
					ShowWindow(hWnd_Or, bOperations[2]);
					ShowWindow(hWnd_Nand, bOperations[3]);
					ShowWindow(hWnd_Nor, bOperations[4]);
					ShowWindow(hWnd_Xor, bOperations[5]);
					ShowWindow(hWnd_Xnor, bOperations[6]);

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
		// set window title
		SetWindowText(hWnd, TEXT("Digital Logic Demonstrator"));

		CreateWindow(TEXT("STATIC"),
			TEXT("A"),
			WS_VISIBLE | WS_CHILD,
			10, 10, 20, 20, hWnd, NULL, NULL, NULL);

		CreateWindow(TEXT("STATIC"),
			TEXT("B"),
			WS_VISIBLE | WS_CHILD,
			10, 40, 20, 20, hWnd, NULL, NULL, NULL);


		// create combo box
		hWnd_cboA = CreateWindow(
			TEXT("COMBOBOX"),								// type of object
			TEXT(""),										// default empty edit box
			CBS_DROPDOWN | CBS_HASSTRINGS |					// act like a typical combo box
			WS_CHILD | WS_OVERLAPPED | WS_VISIBLE | 		// attributesached to the main window
			WS_VSCROLL,										// scroll bar in list
			50, 10, 100, 200,								// location and size
			hWnd, NULL, NULL, NULL);						// parent window, the rest are not used here

		hWnd_cboB = CreateWindow(
			TEXT("COMBOBOX"),								// type of object
			TEXT(""),										// default empty edit box
			CBS_DROPDOWN | CBS_HASSTRINGS |					// act like a typical combo box
			WS_CHILD | WS_OVERLAPPED | WS_VISIBLE | 		// attributesached to the main window
			WS_VSCROLL,										// scroll bar in list
			50, 40, 100, 200,								// location and size
			hWnd, NULL, NULL, NULL);						// parent window, the rest are not used here

		hWnd_cboGate = CreateWindow(
			TEXT("COMBOBOX"),								// type of object
			TEXT(""),										// default empty edit box
			CBS_DROPDOWN | CBS_HASSTRINGS |					// act like a typical combo box
			WS_CHILD | WS_OVERLAPPED | WS_VISIBLE | 		// attributesached to the main window
			WS_VSCROLL,										// scroll bar in list
			180, 40, 75, 200,								// location and size
			hWnd, NULL, NULL, NULL);						// parent window, the rest are not used here

		hWnd_cboOutcome = CreateWindow(
			TEXT("COMBOBOX"),								// type of object
			TEXT(""),										// default empty edit box
			CBS_DROPDOWN | CBS_HASSTRINGS |					// act like a typical combo box
			WS_CHILD | WS_OVERLAPPED | WS_VISIBLE | 		// attributesached to the main window
			WS_VSCROLL,										// scroll bar in list
			50, 120, 100, 200,								// location and size
			hWnd, NULL, NULL, NULL);						// parent window, the rest are not used here

		CreateWindow(TEXT("STATIC"),
			TEXT("Operation"),
			WS_VISIBLE | WS_CHILD,
			180, 10, 70, 20, hWnd, NULL, NULL, NULL);

		CreateWindow(TEXT("STATIC"),
			TEXT("Result"),
			WS_VISIBLE | WS_CHILD,
			280, 10, 70, 20, hWnd, NULL, NULL, NULL);

		hWnd_Result = CreateWindow(TEXT("STATIC"),
			TEXT(""),
			WS_VISIBLE | WS_CHILD,
			280, 40, 70, 20, hWnd, NULL, NULL, NULL);

		hWnd_s_Outcome = CreateWindow(TEXT("STATIC"),
			TEXT("Outcome"),
			WS_VISIBLE | WS_CHILD,
			50, 90, 70, 20, hWnd, NULL, NULL, NULL);

		hWnd_s_Operations = CreateWindow(TEXT("STATIC"),
			TEXT("Operations"),
			WS_VISIBLE | WS_CHILD,
			180, 90, 70, 20, hWnd, NULL, NULL, NULL);

		hWnd_Not = CreateWindow(TEXT("STATIC"),
			TEXT("NOT (A)"),
			WS_VISIBLE | WS_CHILD,
			180, 120, 30, 50, hWnd, NULL, NULL, NULL);

		hWnd_And = CreateWindow(TEXT("STATIC"),
			TEXT("AND"),
			WS_VISIBLE | WS_CHILD,
			230, 120, 70, 20, hWnd, NULL, NULL, NULL);

		hWnd_Or = CreateWindow(TEXT("STATIC"),
			TEXT("OR"),
			WS_VISIBLE | WS_CHILD,
			280, 120, 70, 20, hWnd, NULL, NULL, NULL);

		hWnd_Nand = CreateWindow(TEXT("STATIC"),
			TEXT("NAND"),
			WS_VISIBLE | WS_CHILD,
			230, 160, 70, 20, hWnd, NULL, NULL, NULL);

		hWnd_Nor = CreateWindow(TEXT("STATIC"),
			TEXT("NOR"),
			WS_VISIBLE | WS_CHILD,
			280, 160, 70, 20, hWnd, NULL, NULL, NULL);

		hWnd_Xor = CreateWindow(TEXT("STATIC"),
			TEXT("XOR"),
			WS_VISIBLE | WS_CHILD,
			330, 120, 70, 20, hWnd, NULL, NULL, NULL);

		hWnd_Xnor = CreateWindow(TEXT("STATIC"),
			TEXT("XNOR"),
			WS_VISIBLE | WS_CHILD,
			330, 160, 70, 20, hWnd, NULL, NULL, NULL);

		LoadCombos();									// load the combo boxes
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


void LoadCombos()
{

	ifstream inFile;					// file handles
	string strLine;						// a line in the data file (contains a formmatted binary number)
	TCHAR szText[TCHAR_SIZE];			// converted from strLine

										// open the file
	inFile.open(TEXT("CIS021_S2019_Lab12b_data.txt"));

	if (inFile.is_open())				// did the file open
	{

		getline(inFile, strLine);		// read the first line in the file
		while (inFile.good())			// if more to read
		{
			// convert line from file to TCHAR and add to combo boxes
			StringtoTCHAR(&strLine, szText);
			SendMessage(hWnd_cboA, CB_ADDSTRING, NULL, (LPARAM)szText);
			SendMessage(hWnd_cboB, CB_ADDSTRING, NULL, (LPARAM)szText);
			SendMessage(hWnd_cboOutcome, CB_ADDSTRING, NULL, (LPARAM)szText);

			getline(inFile, strLine);	// read the next line in the file
		}

		inFile.close();					// done with the input file
	}

	// load gate combo box
	SendMessage(hWnd_cboGate, CB_ADDSTRING, NULL, (LPARAM)TEXT("NOT (A)"));
	SendMessage(hWnd_cboGate, CB_ADDSTRING, NULL, (LPARAM)TEXT("AND"));
	SendMessage(hWnd_cboGate, CB_ADDSTRING, NULL, (LPARAM)TEXT("OR"));
	SendMessage(hWnd_cboGate, CB_ADDSTRING, NULL, (LPARAM)TEXT("NAND"));
	SendMessage(hWnd_cboGate, CB_ADDSTRING, NULL, (LPARAM)TEXT("NOR"));
	SendMessage(hWnd_cboGate, CB_ADDSTRING, NULL, (LPARAM)TEXT("XOR"));
	SendMessage(hWnd_cboGate, CB_ADDSTRING, NULL, (LPARAM)TEXT("XNOR"));

	// set combo box selections
	SendMessage(hWnd_cboA, CB_SETCURSEL, NULL, (LPARAM)0);
	SendMessage(hWnd_cboB, CB_SETCURSEL, NULL, (LPARAM)0);
	SendMessage(hWnd_cboOutcome, CB_SETCURSEL, NULL, (LPARAM)0);

	// turn off operation indicators
	ShowWindow(hWnd_Not, FALSE);
	ShowWindow(hWnd_And, FALSE);
	ShowWindow(hWnd_Or, FALSE);
	ShowWindow(hWnd_Nand, FALSE);
	ShowWindow(hWnd_Nor, FALSE);
	ShowWindow(hWnd_Xor, FALSE);
	ShowWindow(hWnd_Xnor, FALSE);

	ShowWindow(hWnd_cboOutcome, TRUE);
	ShowWindow(hWnd_s_Outcome, TRUE);
	ShowWindow(hWnd_s_Operations, TRUE);
}
