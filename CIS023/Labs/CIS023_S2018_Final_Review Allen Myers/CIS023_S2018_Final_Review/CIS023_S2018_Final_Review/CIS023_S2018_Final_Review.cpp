// CIS023_S2018_Final_Review.cpp : Defines the entry point for the application.
//

#include "stdafx.h"
#include "CIS023_S2018_Final_Review.h"

#define MAX_LOADSTRING 100

// Global Variables:
HINSTANCE hInst;                                // current instance
WCHAR szTitle[MAX_LOADSTRING];                  // The title bar text
WCHAR szWindowClass[MAX_LOADSTRING];            // the main window class name

HWND hWnd_LB_Left;								// list boxes
HWND hWnd_LB_Right;								// .
HWND hWnd_PB_Right;								// buttons
HWND hWnd_PB_Right_Fill;						// .
HWND hWnd_PB_Left;								// .
HWND hWnd_PB_Left_Full;							// .
HWND hWnd_PB_File;								// .
HWND hWnd_PB_Reset;								// .
char fInputPath[MAX_LOADSTRING];				// input file path

// Forward declarations of functions included in this code module:
ATOM                MyRegisterClass(HINSTANCE hInstance);
BOOL                InitInstance(HINSTANCE, int);
LRESULT CALLBACK    WndProc(HWND, UINT, WPARAM, LPARAM);
INT_PTR CALLBACK    About(HWND, UINT, WPARAM, LPARAM);

bool GetOpenFileName();							// standard open file dialog
void LoadFile();								// open, read file
void EnableButtons(bool);						// enable/disable buttons
void MoveLine(HWND,HWND);							//move single lines
void MoveAll(HWND,HWND);								//move all lines

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
    LoadStringW(hInstance, IDC_CIS023_S2018_FINAL_REVIEW, szWindowClass, MAX_LOADSTRING);
    MyRegisterClass(hInstance);

    // Perform application initialization:
    if (!InitInstance (hInstance, nCmdShow))
    {
        return FALSE;
    }

    HACCEL hAccelTable = LoadAccelerators(hInstance, MAKEINTRESOURCE(IDC_CIS023_S2018_FINAL_REVIEW));

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
    wcex.hIcon          = LoadIcon(hInstance, MAKEINTRESOURCE(IDI_CIS023_S2018_FINAL_REVIEW));
    wcex.hCursor        = LoadCursor(nullptr, IDC_ARROW);
    wcex.hbrBackground  = (HBRUSH)(COLOR_WINDOW+1);
    wcex.lpszMenuName   = MAKEINTRESOURCEW(IDC_CIS023_S2018_FINAL_REVIEW);
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
      CW_USEDEFAULT, 0, 450, 300, nullptr, nullptr, hInstance, nullptr);

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
		{

			if (LOWORD(lParam) == (WORD)hWnd_PB_File)					// File button
			{
				if (GetOpenFileName())
					LoadFile();
			}

			if (LOWORD(lParam) == (WORD)hWnd_PB_Reset)					// reset button
			{

				//Clear listboxes
				SendMessage(hWnd_LB_Left, LB_RESETCONTENT, NULL, NULL);
				SendMessage(hWnd_LB_Right, LB_RESETCONTENT, NULL, NULL);

				EnableButtons(false);									// disable buttons
			}

			if (LOWORD(lParam) == (WORD)hWnd_PB_Left)					// < button
			{
				MoveLine(hWnd_LB_Right,hWnd_LB_Left);
			}

			if (LOWORD(lParam) == (WORD)hWnd_PB_Left_Full)				// << button
			{
				MoveAll(hWnd_LB_Right, hWnd_LB_Left);
			}

			if (LOWORD(lParam) == (WORD)hWnd_PB_Right)					// > button
			{
				MoveLine(hWnd_LB_Left, hWnd_LB_Right);

			}

			if (LOWORD(lParam) == (WORD)hWnd_PB_Right_Fill)				// >> button
			{
				MoveAll(hWnd_LB_Left, hWnd_LB_Right);

			}


			break;
		}
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
			WS_VISIBLE | WS_CHILD, 0, 0, 500, 250, hWnd, NULL, NULL, NULL);

		// create list box
		hWnd_LB_Left = CreateWindow(
			TEXT("LISTBOX"),								// type of object
			TEXT(""),										// starts blank (filled later)
			WS_VISIBLE | WS_CHILD |							// attributes
			WS_VSCROLL | WS_BORDER,
			20, 20, 150, 160,								// location and size
			hWnd, NULL, NULL, NULL);						// parent window, the rest are not used here

		hWnd_LB_Right = CreateWindow(
			TEXT("LISTBOX"),								// type of object
			TEXT(""),										// starts blank (filled later)
			WS_VISIBLE | WS_CHILD |							// attributes
			WS_VSCROLL | WS_BORDER,
			240, 20, 150, 160,								// location and size
			hWnd, NULL, NULL, NULL);						// parent window, the rest are not used here

		hWnd_PB_Right = CreateWindow(TEXT("BUTTON"),
			TEXT(">"),
			WS_VISIBLE | WS_CHILD | BS_DEFPUSHBUTTON,
			180, 20, 50, 30, hWnd, NULL, NULL, NULL);

		hWnd_PB_Right_Fill = CreateWindow(TEXT("BUTTON"),
			TEXT(">>"),
			WS_VISIBLE | WS_CHILD | BS_DEFPUSHBUTTON,
			180, 60, 50, 30, hWnd, NULL, NULL, NULL);

		hWnd_PB_Left_Full = CreateWindow(TEXT("BUTTON"),
			TEXT("<<"),
			WS_VISIBLE | WS_CHILD | BS_DEFPUSHBUTTON,
			180, 100, 50, 30, hWnd, NULL, NULL, NULL);

		hWnd_PB_Left = CreateWindow(TEXT("BUTTON"),
			TEXT("<"),
			WS_VISIBLE | WS_CHILD | BS_DEFPUSHBUTTON,
			180, 140, 50, 30, hWnd, NULL, NULL, NULL);

		hWnd_PB_File = CreateWindow(TEXT("BUTTON"),
			TEXT("File"),
			WS_VISIBLE | WS_CHILD | BS_DEFPUSHBUTTON,
			230, 180, 70, 30, hWnd, NULL, NULL, NULL);

		hWnd_PB_Reset = CreateWindow(TEXT("BUTTON"),
			TEXT("Reset"),
			WS_VISIBLE | WS_CHILD | BS_DEFPUSHBUTTON,
			320, 180, 70, 30, hWnd, NULL, NULL, NULL);


		EnableButtons(false);							// disable buttons

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

void EnableButtons(bool bEnable)
{
	EnableWindow(hWnd_PB_Right, bEnable);
	EnableWindow(hWnd_PB_Right_Fill, bEnable);
	EnableWindow(hWnd_PB_Left, bEnable);
	EnableWindow(hWnd_PB_Left_Full, bEnable);

	EnableWindow(hWnd_PB_Reset, bEnable);

}

bool GetOpenFileName()
{
	char szFileNameIN[MAX_PATH];							// user selection

	OPENFILENAME ofn;

	// open standard open file dialog box
	ZeroMemory(&fInputPath, sizeof(fInputPath));
	ZeroMemory(&ofn, sizeof(ofn));
	ofn.lStructSize = sizeof(ofn);
	ofn.hwndOwner = NULL;
	ofn.lpstrFilter = LPWSTR("Any File\0*.*\0");
	ofn.lpstrFile = LPWSTR(fInputPath);
	ofn.nMaxFile = MAX_PATH;
	ofn.lpstrFileTitle = LPWSTR(szFileNameIN);
	ofn.nMaxFileTitle = MAX_PATH;
	ofn.lpstrTitle = LPWSTR("Select an input File");
	ofn.Flags = OFN_DONTADDTORECENT | OFN_FILEMUSTEXIST;

	// if file selected
	if (GetOpenFileNameA(LPOPENFILENAMEA(&ofn)))
		return true;

	return false;
}

void LoadFile()
{
	ifstream inFile;										// file handle
	string strLine;											// line of text
	wchar_t wcOuput[100];									// output to form

	try
	{
		inFile.open(fInputPath);							// open the tile

		if (inFile.bad())									// did file open?
			throw 1;

		getline(inFile, strLine);							// read the 1st line in the file

		while (inFile.good())								// read to end of file
		{
			size_t pReturnValue;

			mbstowcs_s(
				&pReturnValue,
				wcOuput,
				MAX_LOADSTRING,
				strLine.c_str(),
				MAX_LOADSTRING);

			SendMessage(hWnd_LB_Left, LB_ADDSTRING, NULL, LPARAM(wcOuput));

			getline(inFile, strLine);

		}

		inFile.close();

		EnableButtons(true);								// enable buttons

	}
	catch (int)
	{
		MessageBox(NULL, TEXT("Unable to open input file."), TEXT("File Open Error"), MB_ICONEXCLAMATION);
	}
}
void MoveLine(HWND source, HWND destination)
{
	TCHAR szLine[1024];
	int iIndex = -1;

	//get select line
	iIndex = SendMessage(source, LB_GETCURSEL, NULL, NULL);

	//if a line is selected, if not, dont do anything
	if (iIndex != -1)
	{
		SendMessage(source,				//source line
			LB_GETTEXT,					//get the selected data
			iIndex,						//which line
			LPARAM(szLine));			//destination TCHAR

		SendMessage(source,				//delete selected line
			LB_DELETESTRING,
			iIndex, 
			NULL);	

		SendMessage(destination,		//append the text to the destination(add to end of listbox)
			LB_ADDSTRING,
			NULL,
			LPARAM(szLine));
									
	}
	//end of function to copy line to other listbox

}
void MoveAll(HWND source, HWND destination)
{
	TCHAR szLine[1024];
	int iIndex = -1;

	iIndex= SendMessage(source, LB_GETCOUNT, NULL, NULL);	//get number of lines in source list box
	for (int i=0; i < iIndex; i++)							//loop through the listbox
	{
		SendMessage(source,									//source line
			LB_GETTEXT,										//get the selected data
			0,												//which line
			LPARAM(szLine));								//destination TCHAR

		SendMessage(source,									//delete selected line
			LB_DELETESTRING,
			0,
			NULL);

		SendMessage(destination,							//append the text to the destination(add to end of listbox)
			LB_ADDSTRING,
			NULL,
			LPARAM(szLine));

	}
}