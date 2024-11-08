//Module:	CIS023_S2018_HW9 Allen Myers.cpp
//Project:	CIS023_S2018_HW9 Allen Myers
//Author:	Allen Myers
//Date:		April 12th, 2018
//Purpose:	Learn how to create a queue as a linked list.
//			Initialize, push, pop, and delete a queue.
//

#include "stdafx.h"
#include "CIS023_S2018_HW9 Allen Myers.h"

#define MAX_LOADSTRING 100

// Global Variables:
HINSTANCE hInst;                                // current instance
WCHAR szTitle[MAX_LOADSTRING];                  // The title bar text
WCHAR szWindowClass[MAX_LOADSTRING];            // the main window class name
HWND hWnd_InFile;				//handle to file input
HWND hWnd_Search;				//handle to search query
HWND hWnd_btnInfile;			//handle to file
HWND hWnd_btnCount;				//button to count
HWND hWnd_ReturnValue;			//return value for number of instances.
char fFilePath[MAX_PATH];		//file name, selected by user
QueueClass*queue;				//pointer to queue

// Forward declarations of functions included in this code module:
ATOM                MyRegisterClass(HINSTANCE hInstance);
BOOL                InitInstance(HINSTANCE, int);
LRESULT CALLBACK    WndProc(HWND, UINT, WPARAM, LPARAM);
INT_PTR CALLBACK    About(HWND, UINT, WPARAM, LPARAM);

bool GetFileName();
bool LoadFile();
void SearchFile();

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
    LoadStringW(hInstance, IDC_CIS023_S2018_HW9ALLENMYERS, szWindowClass, MAX_LOADSTRING);
    MyRegisterClass(hInstance);

    // Perform application initialization:
    if (!InitInstance (hInstance, nCmdShow))
    {
        return FALSE;
    }

    HACCEL hAccelTable = LoadAccelerators(hInstance, MAKEINTRESOURCE(IDC_CIS023_S2018_HW9ALLENMYERS));

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
    wcex.hIcon          = LoadIcon(hInstance, MAKEINTRESOURCE(IDI_CIS023_S2018_HW9ALLENMYERS));
    wcex.hCursor        = LoadCursor(nullptr, IDC_ARROW);
    wcex.hbrBackground  = (HBRUSH)(COLOR_WINDOW+1);
    wcex.lpszMenuName   = MAKEINTRESOURCEW(IDC_CIS023_S2018_HW9ALLENMYERS);
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
	   CW_USEDEFAULT, 0, 500, 200, nullptr, nullptr, hInstance, nullptr);

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
				if (LOWORD(lParam) == (WORD)hWnd_btnInfile)	// launch standard file open dialog
				{
					if (GetFileName())
					{
						if (LoadFile())
							EnableWindow(hWnd_btnCount, true);
					}
				}
				else if (LOWORD(lParam) == (WORD)hWnd_Search)
				{
					TCHAR szInput[100];		//user input
					GetWindowText(							//get user input
						hWnd_Search,						//top input edit control
						szInput,							//target TCHAR
						100								//size of TCHAR
					);
					//QueueClass searchQueryObj(szInput);		//create class and send to user input

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
		CreateWindow(TEXT("STATIC"), TEXT(""),
			WS_VISIBLE | WS_CHILD, 0, 0, 500, 200, hWnd, NULL, NULL, NULL);
		CreateWindow(TEXT("STATIC"),
			TEXT("File:"),
			WS_VISIBLE | WS_CHILD,
			10, 10, 40, 20, hWnd, NULL, NULL, NULL);
		hWnd_InFile= CreateWindow(TEXT("STATIC"),
			TEXT(""),
			WS_VISIBLE | WS_CHILD, 100, 10, 250, 20, hWnd, NULL, NULL, NULL);
		hWnd_btnInfile= CreateWindow(TEXT("BUTTON"),
			TEXT("File Open"),
			WS_VISIBLE | WS_CHILD | BS_DEFPUSHBUTTON,
			400, 10, 70, 30, hWnd, NULL, NULL, NULL);
		CreateWindow(TEXT("STATIC"),
			TEXT("Search:"),
			WS_VISIBLE | WS_CHILD,
			10, 40, 50, 20, hWnd, NULL, NULL, NULL);
		hWnd_Search= CreateWindow(TEXT("EDIT"),
			TEXT(""),
			WS_VISIBLE | WS_CHILD, 100, 40, 50, 20, hWnd, NULL, NULL, NULL);
		hWnd_btnCount= CreateWindow(TEXT("BUTTON"),
			TEXT("Count"),
			WS_VISIBLE | WS_CHILD | BS_DEFPUSHBUTTON,
			10, 70, 70, 30, hWnd, NULL, NULL, NULL);
		hWnd_ReturnValue=CreateWindow(TEXT("STATIC"),
				TEXT(""),
				WS_VISIBLE | WS_CHILD, 40, 100, 25, 20, hWnd, NULL, NULL, NULL);
		EnableWindow(hWnd_btnCount, false);		// buttons disabled, enabled in order

	}
	break;
    case WM_DESTROY:
		//delete the queues
		if (queue)
			delete queue;
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

bool GetFileName()
{
	char szFileNameIN[MAX_PATH];

	// get the input file name
	OPENFILENAME ofn;
	ZeroMemory(&fFilePath, sizeof(fFilePath));
	ZeroMemory(&ofn, sizeof(ofn));
	ofn.lStructSize = sizeof(ofn);
	ofn.hwndOwner = NULL;
	ofn.lpstrFilter = LPWSTR("Any File\0*.*\0");
	ofn.lpstrFile = LPWSTR(fFilePath);
	ofn.nMaxFile = MAX_PATH;
	ofn.lpstrFileTitle = LPWSTR(szFileNameIN);
	ofn.nMaxFileTitle = MAX_PATH;
	ofn.lpstrTitle = LPWSTR("Select an input File");
	ofn.Flags = OFN_DONTADDTORECENT | OFN_FILEMUSTEXIST;

	if (GetOpenFileNameA(LPOPENFILENAMEA(&ofn))) // user selected an input file
	{
		// display input file name on window
		size_t pReturnValue;
		wchar_t wcstr[MAX_LOADSTRING];
		mbstowcs_s(&pReturnValue, wcstr, MAX_LOADSTRING, szFileNameIN, MAX_LOADSTRING);
		SendMessage(hWnd_InFile, WM_SETTEXT, NULL, LPARAM(wcstr));

		return true;
	}
	else
		return false;
}

bool LoadFile()
{
	ifstream inFile;			//file handle
	char c;						//char read from file
	try
	{
		inFile.open(fFilePath);	//open the first file
		if (inFile.bad())			//did the file open?
			throw 1;				//throw error message if it didnt

		delete queue;			//delete the previous queue(if tehre is one)
		queue = new QueueClass;//create a new queue

		queue->initializeQueue();	//initialize the 1st queue

		inFile.get(c);				//get a line from file
		while (inFile.good())
		{
			queue->addQueue(c);	//add a new node to the bottom fo the first node
			inFile.get(c);			//get next char
		}
		inFile.close();				//close the file
	}
	catch (int)
	{
		MessageBox(NULL,		//error message
			TEXT("Unable to Load First Input File"),
			TEXT("File Open Error"),
			MB_ICONERROR);
		return false;
	}
	return true;
}


void SearchFile()
{
}
