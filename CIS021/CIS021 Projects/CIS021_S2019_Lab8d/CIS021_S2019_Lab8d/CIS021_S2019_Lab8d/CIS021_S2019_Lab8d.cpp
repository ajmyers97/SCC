//Module:	CIS021_S2019_Lab8d.cpp : Defines the entry point for the application.
//Project:	CIS021_S2019_Lab8d
//Author:	Allen Myers
//Date:		5/9/2019
//Purpose:	Understand how binary trees store and retrieve data.
//			Demonstrate loading a disjoint binary pair.
//			Perform programmed data searches in a B - Tree.

#include "stdafx.h"
#include "CIS021_S2019_Lab8d.h"

#define MAX_LOADSTRING 100

// Global Variables:
HINSTANCE hInst;                                // current instance
WCHAR szTitle[MAX_LOADSTRING];                  // The title bar text
WCHAR szWindowClass[MAX_LOADSTRING];            // the main window class name

HWND hWnd_Input;								// user input edit control
HWND hWnd_Output;								// output static control

bTreeClass * bTree;								//bTree object

// Forward declarations of functions included in this code module:
ATOM                MyRegisterClass(HINSTANCE hInstance);
BOOL                InitInstance(HINSTANCE, int);
LRESULT CALLBACK    WndProc(HWND, UINT, WPARAM, LPARAM);
INT_PTR CALLBACK    About(HWND, UINT, WPARAM, LPARAM);

void LoadBTree();								// place alphabet in bTree
string Parse(string);							// parse user input, return converted text

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
    LoadStringW(hInstance, IDC_CIS021_S2019_LAB8D, szWindowClass, MAX_LOADSTRING);
    MyRegisterClass(hInstance);

    // Perform application initialization:
    if (!InitInstance (hInstance, nCmdShow))
    {
        return FALSE;
    }

    HACCEL hAccelTable = LoadAccelerators(hInstance, MAKEINTRESOURCE(IDC_CIS021_S2019_LAB8D));

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
    wcex.hIcon          = LoadIcon(hInstance, MAKEINTRESOURCE(IDI_CIS021_S2019_LAB8D));
    wcex.hCursor        = LoadCursor(nullptr, IDC_ARROW);
    wcex.hbrBackground  = (HBRUSH)(COLOR_WINDOW+0);
    wcex.lpszMenuName   = MAKEINTRESOURCEW(IDC_CIS021_S2019_LAB8D);
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
      CW_USEDEFAULT, 0, 550, 200, nullptr, nullptr, hInstance, nullptr);

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

		//capture
		if (HIWORD(wParam) == EN_CHANGE)			//key pressed
		{
			TCHAR szInput[TCHAR_SIZE];				//user input
			TCHAR szOuput[TCHAR_SIZE];				//window output
			string strInput;						//user input converted to string
			string strOutput;						//user input converted to text

			GetWindowText(hWnd_Input,				//get the user input
				szInput, TCHAR_SIZE);
			TCHARtoString(szInput, &strInput);		//convert user input to string

			strOutput = Parse(strInput);				//convert input to text

			StringtoTCHAR(&strOutput, szOuput);		//convert text to TCHAR

			SetWindowText(hWnd_Output,				//show interpretted text
				szOuput);	
		}


		
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

		// prompt
		CreateWindow(TEXT("STATIC"),
			TEXT("Enter Morse Code Sequence:"),
			WS_VISIBLE | WS_CHILD,
			10, 20, 220, 20, hWnd, NULL, NULL, NULL);

		// edit control for user input
		hWnd_Input = CreateWindow(TEXT("EDIT"),
			NULL,
			WS_CHILD | WS_VISIBLE | WS_BORDER |
			ES_AUTOHSCROLL | WS_CHILD,
			10, 80, 500, 20, hWnd, NULL, NULL, NULL);

		// static control for output
		hWnd_Output = CreateWindow(TEXT("STATIC"),
			TEXT(""),
			WS_VISIBLE | WS_CHILD,
			230, 20, 280, 50, hWnd, NULL, NULL, NULL);


		LoadBTree();						// load the tree with Morse code

		SetFocus(hWnd_Input);				// set focus on user input

	}
	break;

	case WM_DESTROY:
		if (bTree)							//delete the bTree
			delete bTree;

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

void LoadBTree()
{
	struct MorseTable
	{
		char cChar;						//alpa char
		string strCode;					//da dit
	};
	MorseTable table[] =
	{
		//root node, no code, needs to be unique
		{ ' '," " },
		{ 'T',"-" },
		{ 'E',"." },
		{ 'M',"--" },
		{ 'N',"-." },
		{ 'A',".-" },
		{ 'I',".." },
		{ 'O',"---" },
		{ 'G',"--." },
		{ 'K',"-.-" },
		{ 'D',"-.." },
		{ 'W',".--" },
		{ 'R',".-." },
		{ 'U',"..-" },
		{ 'S',"..." },
		{ '?',"----" },		//no morse for this char
		{ '.',"---." },		//no morse for this char
		{ 'Q',"--.-" },
		{ 'Z',"--.." },
		{ 'Y',"-.--" },
		{ 'C',"-.-." },
		{ 'X',"-..-" },
		{ 'B',"-..." },
		{ 'J',".---" },
		{ 'P',".--." },
		{ 'L',".-.." },
		{ '-',"..--" },		//no morse for this char
		{ 'F',"..-." },
		{ 'V',"...-" },
		{ 'H',"...." },
		{ '0',"-----" },
		{ '9',"----." },
		{ '8',"---.." },
		{ '7',"--..." },
		{ '6',"-...." },
		{ '1',".----" },
		{ '2',"..---" },
		{ '3',"...--" },
		{ '4',"....-" },
		{ '5',"....." }
	};
	bTree= new bTreeClass;		//creat bTree object

	for (int i = 0;i < 40;i++)
		bTree->Insert(table[i].cChar, table[i].strCode);
}

// parse user input, return interpretted text
string Parse(string strIn)
{
	string strReturn;			//return text
	string strWork;				//work string during parsing process
	char c, lastc;				//char returned from bTree search

	for (int i = 0;i < strIn.length();i++)
	{
		//only process legal input
		if (strIn[i] == '.' ||
			strIn[i] == '-' ||
			strIn[i] == '_' ||
			strIn[i] == ' ')
		{

			strWork += strIn[i];	//append current char to work string

			c = bTree->Search(strWork);	//find char from work string

			if (c == ' ')				//if space returned, end of letter
			{
				strReturn += lastc;		//add saved char to ouput
				strWork = "";			//empty work string
				lastc = ' ';			//clear hold char
			}
			else						//usable char returned
				lastc = c;				//save good char
		}
	}
		if (lastc != ' ')				//is there a leftover char
			strReturn += lastc;			//append it to the return string
	
	return strReturn;			//returned parsed text
}