//Module:	CIS023_S2018_Lab10a.cpp
//Project:	CIS023_S2018_Lab10a
//Author:	Allen Myers
//Date:		April 16th, 2018
//Prupose:	Write a linear search routine on a sorted linked list.
//			Write a binary search on a sorted linked list.
//			Compare the speed, and number of searches performed by both searches.
//
#include "stdafx.h"
#include "CIS023_S2018_Lab10a.h"

#define MAX_LOADSTRING 100

// Global Variables:
HINSTANCE hInst;                                // current instance
WCHAR szTitle[MAX_LOADSTRING];                  // The title bar text
WCHAR szWindowClass[MAX_LOADSTRING];            // the main window class name

TCHAR szNamesFile[] = TEXT("sorted_names.txt"); // file name 
string strSearchString;							// input from user
HWND hWnd_BTN_Load;								// Load button
HWND hWnd_BTN_String;							// Search String button
HWND hWnd_BTN_Linear;							// Linear Search button
HWND hWnd_BTN_Binary;							// Binary Search button
HWND hWnd_Input;								// search string input edit control
HWND hWnd_Filename;								// filename load message static
HWND hWnd_StringFound;							// search result message  static
HWND hWnd_LinStart;								// linear search start time message static
HWND hWnd_LinEnd;								// linear search end time message static
HWND hWnd_BinStart;								// binary search start time message static
HWND hWnd_BinEnd;								// binary search end time message static
HWND hWnd_Linear_Comps;							// # of linear comparisons message static
HWND hWnd_Binary_Comps;							// # of binary comparisons message static


LinkedListClass*list;							//linked list with contendts of ordered file
// Forward declarations of functions included in this code module:
ATOM                MyRegisterClass(HINSTANCE hInstance);
BOOL                InitInstance(HINSTANCE, int);
LRESULT CALLBACK    WndProc(HWND, UINT, WPARAM, LPARAM);
INT_PTR CALLBACK    About(HWND, UINT, WPARAM, LPARAM);

void				CreateMainWindowLayout(HWND);// WM_CREATE
BOOL				LoadList();					// load sorted file into linked list
int					LinearSearch();				// perform linear search on linked list
int					BinarySearch();				// perform binary search on linked list

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
    LoadStringW(hInstance, IDC_CIS023_S2018_LAB10A, szWindowClass, MAX_LOADSTRING);
    MyRegisterClass(hInstance);

    // Perform application initialization:
    if (!InitInstance (hInstance, nCmdShow))
    {
        return FALSE;
    }

    HACCEL hAccelTable = LoadAccelerators(hInstance, MAKEINTRESOURCE(IDC_CIS023_S2018_LAB10A));

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
    wcex.hIcon          = LoadIcon(hInstance, MAKEINTRESOURCE(IDI_CIS023_S2018_LAB10A));
    wcex.hCursor        = LoadCursor(nullptr, IDC_ARROW);
    wcex.hbrBackground  = (HBRUSH)(COLOR_WINDOW+1);
    wcex.lpszMenuName   = MAKEINTRESOURCEW(IDC_CIS023_S2018_LAB10A);
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
      CW_USEDEFAULT, 0, 450, 400, nullptr, nullptr, hInstance, nullptr);

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
		case BN_CLICKED:	// capture button click
			if (LOWORD(lParam) == (WORD)hWnd_BTN_Load)
			{
				SetWindowText(hWnd_Filename, TEXT("File loading..."));
				if (LoadList())
				{
					TCHAR szStr[TCHAR_MAX];
					wsprintf(szStr, TEXT("File loaded: %s"), szNamesFile);
					SetWindowText(hWnd_Filename, szStr);

					EnableWindow(hWnd_Filename, true);		// Loaded from file static control
					EnableWindow(hWnd_Input, true);			// Search String input edit control
					EnableWindow(hWnd_BTN_String, true);	// Search String button 
				}
				else
					SetWindowText(hWnd_Filename, TEXT("Unable to read input file."));
			}

			else if (LOWORD(lParam) == (WORD)hWnd_BTN_String)
			{
				TCHAR szSearchString[TCHAR_MAX];
				SendMessage(hWnd_Input, WM_GETTEXT,
					MAX_LOADSTRING,
					LPARAM(szSearchString));

				if (lstrlen(szSearchString) != 0)			// do nothing if nothing entered
				{
					wstring temp(&szSearchString[0]);		// convert TCHAR to string
					string str(temp.begin(), temp.end());
					strSearchString = str;

					EnableWindow(hWnd_BTN_Linear, true);	// Search String button 
				}

			}
			else if (LOWORD(lParam) == (WORD)hWnd_BTN_Linear)
			{
				SYSTEMTIME sysTime;
				int iFoundLine = -1;
				TCHAR szOutput[MAX_LOADSTRING];

				// get and display start time
				GetSystemTime(&sysTime);
				_stprintf_s(szOutput, TEXT("%02d:%02d.%03d"), sysTime.wMinute, sysTime.wSecond, sysTime.wMilliseconds);
				SetWindowText(hWnd_LinStart, szOutput);
				EnableWindow(hWnd_LinStart, true);				// Linear search start time static control

				iFoundLine = LinearSearch();					// perform the linear search
				if (iFoundLine > -1)							// if found
				{
					_stprintf_s(szOutput, TEXT("String found on line %i."), iFoundLine);
					SetWindowText(hWnd_StringFound, szOutput);

					// message, how many comparisons
					_stprintf_s(szOutput, TEXT("Number of comparisons: %i"), iFoundLine);
					SetWindowText(hWnd_Linear_Comps, szOutput);

					EnableWindow(hWnd_BTN_Binary, true);		// Search String button 
				}
				else
				{
					_stprintf_s(szOutput, TEXT("String not found."));
					SetWindowText(hWnd_StringFound, szOutput);
				}

				EnableWindow(hWnd_StringFound, true);		// search result static control
				EnableWindow(hWnd_LinEnd, true);			// Linear search end time static control
				EnableWindow(hWnd_Linear_Comps, true);		// # of comparisons message static control

				// get and display end time
				GetSystemTime(&sysTime);
				_stprintf_s(szOutput, TEXT("%02d:%02d.%03d"), sysTime.wMinute, sysTime.wSecond, sysTime.wMilliseconds);
				SetWindowText(hWnd_LinEnd, szOutput);

			}
			else if (LOWORD(lParam) == (WORD)hWnd_BTN_Binary)
			{
				SYSTEMTIME sysTime;
				TCHAR szOutput[MAX_LOADSTRING];
				int iFoundLine = -1;

				// get and display start time
				GetSystemTime(&sysTime);
				_stprintf_s(szOutput, TEXT("%02d:%02d.%03d"), sysTime.wMinute, sysTime.wSecond, sysTime.wMilliseconds);
				SetWindowText(hWnd_BinStart, szOutput);
				EnableWindow(hWnd_BinStart, true);			// Binary search start time static control

				iFoundLine = BinarySearch();				// perform the binary search

				_stprintf_s(szOutput, TEXT("Number of comparisons: %i."), iFoundLine);
				SetWindowText(hWnd_Binary_Comps, szOutput);
				EnableWindow(hWnd_Binary_Comps, true);

				// get and display end time
				GetSystemTime(&sysTime);
				_stprintf_s(szOutput, TEXT("%02d:%02d.%03d"), sysTime.wMinute, sysTime.wSecond, sysTime.wMilliseconds);
				SetWindowText(hWnd_BinEnd, szOutput);
				EnableWindow(hWnd_BinEnd, true);			// Binary search end time static control

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
		CreateMainWindowLayout(hWnd);
		break;

	case WM_DESTROY:
		if (list)								//delete the linked list
			delete list;



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

// layout the controls on the main window
void CreateMainWindowLayout(HWND hWnd)
{
	CreateWindow(TEXT("STATIC"), TEXT(""),	// grey background
		WS_VISIBLE | WS_CHILD, 0, 0, 450, 350, hWnd, NULL, NULL, NULL);

	// buttons
	hWnd_BTN_Load = CreateWindow(TEXT("BUTTON"), TEXT("Load File"),
		WS_VISIBLE | WS_CHILD | BS_DEFPUSHBUTTON,
		20, 70, 110, 30, hWnd, NULL, NULL, NULL);

	hWnd_BTN_String = CreateWindow(TEXT("BUTTON"), TEXT("Search String"),
		WS_VISIBLE | WS_CHILD | BS_DEFPUSHBUTTON,
		20, 120, 110, 30, hWnd, NULL, NULL, NULL);

	hWnd_BTN_Linear = CreateWindow(TEXT("BUTTON"), TEXT("Linear Search"),
		WS_VISIBLE | WS_CHILD | BS_DEFPUSHBUTTON,
		20, 170, 110, 30, hWnd, NULL, NULL, NULL);

	hWnd_BTN_Binary = CreateWindow(TEXT("BUTTON"), TEXT("Binary Search"),
		WS_VISIBLE | WS_CHILD | BS_DEFPUSHBUTTON,
		20, 220, 110, 30, hWnd, NULL, NULL, NULL);

	// input
	hWnd_Input = CreateWindow(TEXT("EDIT"), NULL,
		WS_CHILD | WS_VISIBLE | WS_BORDER | ES_AUTOHSCROLL | WS_CHILD,
		160, 125, 250, 20, hWnd, NULL, NULL, NULL);

	// outputs - static controls
	hWnd_Filename = CreateWindow(TEXT("STATIC"),
		TEXT(""), // will be filled after file loaded
		WS_VISIBLE | WS_CHILD, 160, 75, 250, 20, hWnd, NULL, NULL, NULL);

	hWnd_StringFound = CreateWindow(TEXT("STATIC"),
		TEXT(""), // will be filled after searches
		WS_VISIBLE | WS_CHILD, 160, 150, 250, 20, hWnd, NULL, NULL, NULL);

	hWnd_LinStart = CreateWindow(TEXT("STATIC"),
		TEXT("88:88.888"),
		WS_VISIBLE | WS_CHILD, 210, 175, 80, 20, hWnd, NULL, NULL, NULL);

	hWnd_LinEnd = CreateWindow(TEXT("STATIC"),
		TEXT("88:88.888"),
		WS_VISIBLE | WS_CHILD, 345, 175, 80, 20, hWnd, NULL, NULL, NULL);

	hWnd_Linear_Comps = CreateWindow(TEXT("STATIC"),
		TEXT(""),
		WS_VISIBLE | WS_CHILD, 160, 195, 300, 20, hWnd, NULL, NULL, NULL);

	hWnd_BinStart = CreateWindow(TEXT("STATIC"),
		TEXT("88:88.888"),
		WS_VISIBLE | WS_CHILD, 210, 225, 80, 20, hWnd, NULL, NULL, NULL);

	hWnd_BinEnd = CreateWindow(TEXT("STATIC"),
		TEXT("88:88.888"),
		WS_VISIBLE | WS_CHILD, 345, 225, 80, 20, hWnd, NULL, NULL, NULL);

	hWnd_Binary_Comps = CreateWindow(TEXT("STATIC"),
		TEXT(""),
		WS_VISIBLE | WS_CHILD, 160, 245, 300, 20, hWnd, NULL, NULL, NULL);

	// static text - labels
	CreateWindow(TEXT("STATIC"),
		TEXT("LINEAR/BINARY SEARCH COMPARISON"),
		WS_VISIBLE | WS_CHILD, 100, 20, 260, 20, hWnd, NULL, NULL, NULL);

	CreateWindow(TEXT("STATIC"),
		TEXT("Start:"),
		WS_VISIBLE | WS_CHILD, 160, 175, 40, 20, hWnd, NULL, NULL, NULL);

	CreateWindow(TEXT("STATIC"),
		TEXT("End:"),
		WS_VISIBLE | WS_CHILD, 300, 175, 40, 20, hWnd, NULL, NULL, NULL);

	CreateWindow(TEXT("STATIC"),
		TEXT("Start:"),
		WS_VISIBLE | WS_CHILD, 160, 225, 40, 20, hWnd, NULL, NULL, NULL);

	CreateWindow(TEXT("STATIC"),
		TEXT("End:"),
		WS_VISIBLE | WS_CHILD, 300, 225, 40, 20, hWnd, NULL, NULL, NULL);


	EnableWindow(hWnd_Input, false);			// Search String input edit control
	EnableWindow(hWnd_BTN_String, false);		// Search String button disabled until file selected
	EnableWindow(hWnd_BTN_Linear, false);		// Linear Search button disabled until search string entered
	EnableWindow(hWnd_BTN_Binary, false);		// Binary Search button disabled until search string entered

	EnableWindow(hWnd_Filename, false);			// Loaded from file static control
	EnableWindow(hWnd_StringFound, false);		// search string found static control
	EnableWindow(hWnd_LinStart, false);			// Linear search start time static control
	EnableWindow(hWnd_LinEnd, false);			// Linear search end time static control
	EnableWindow(hWnd_BinStart, false);			// Binary search start time static control
	EnableWindow(hWnd_BinEnd, false);			// Binary search end time static control
	EnableWindow(hWnd_Linear_Comps, false);		// # of comparisons message static
	EnableWindow(hWnd_Binary_Comps, false);		// # of comparisons message static
}

// load linked list from file
BOOL LoadList()
{
	ifstream inFile;							// file handle
	string strLine;								// a line in the file

	inFile.open(szNamesFile);					// open the file

	if (inFile.is_open())						// did the file open?
	{
		list = new LinkedListClass;				//create linked list

		getline(inFile, strLine);				//read 1st line in file
		while (inFile.good())					// if more to read
		{
			list->Add(strLine);					//add node to the list
			getline(inFile, strLine);			// read next line from file
		}

		inFile.close();							// close the file

		return true;							// file okay
	}

	return false;								// file not found
}

// performs a linears search of list
//		returns item # if found, -1 if not
int LinearSearch()
{
	string strNodeData;										//string from node
	int iLineNum=0;											//line number return value



	list->SetCurrentNode(list->GetFirstNode());				//start at the top of the lst


	while (list->GetCurrentNode() != nullptr)
	{
		strNodeData = list->GetCurrentNode()->GetString();		//get first node's data

		iLineNum++;												//increment counter, makes incrementer start at 0'th line

		if (strNodeData == strSearchString)						//if found
			return iLineNum;												//then doen with the loop

		list->SetCurrentNode(list->GetCurrentNode()->GetNextNode());		//next node in list(set current node to the current nodes node's pointer to next node)
		
	}
	return -1;
}

// Performs a binary search of list
//		Returns # of searches if found, -1 if not
int BinarySearch()
{
	int first = 0;										//top of portion of list to search
	int last = 0;										//bottom of portion of list to search
	int middle = 0;										//middle point of portion fo list to search
	int iCompNum = 0;									//count # of comparisons
	string strNodeData;									//string from current node
	bool found = false;									//true if search string is found

	 //count the number of node
	list->SetCurrentNode(list->GetFirstNode());			//start at the top of the list
	while (list->GetCurrentNode() != nullptr)			//continue to the end of the list
	{
		last++;											//count the node
		list->SetCurrentNode(list->GetCurrentNode()->GetNextNode());		//next node

	}

	while (!found && first <= last)
	{
		middle = (first + last) / 2;							//middle if halfway marker between first and last node
			//run to middle node
			list->SetCurrentNode(list->GetFirstNode());			//start at the top of the list
			for (int i = 1;i <= middle;i++)							//run to current middle node
				list->SetCurrentNode(list->GetCurrentNode()->GetNextNode());		//next node


			strNodeData = list->GetCurrentNode()->GetString();		//get middle node's data

			int iCompare = strSearchString.compare(strNodeData);	//-1 if <; 0 if 0; 1 if >

			if (iCompare == 0)										//strings are equal
				found = true;
			else if (iCompare < 0)									//if search string is < node string
				last = middle;
			else if (iCompare > 0)									//if search string is > node string
				first = middle;
			iCompNum++;												//count comparisons
																	
																	
		//found = true;	//comment to test

	}


	return iCompNum;												//return the number of comparisons
}
