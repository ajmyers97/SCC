//Module:	CIS023_S2018_HW9 Allen Myers.cpp
//Project:	CIS023_S2018_HW9 Allen Myers
//Author:	Allen Myers
//Date:		April 12th, 2018
//Purpose:	Learn how to create a queue as a linked list.
//			Initialize, push, pop, and delete a queue.
//


#include "stdafx.h"
#include "CIS023_S2018 HW 9 Allen Myers.h"

#define MAX_LOADSTRING 100

// Global Variables:
HINSTANCE hInst;                                // current instance
WCHAR szTitle[MAX_LOADSTRING];                  // The title bar text
WCHAR szWindowClass[MAX_LOADSTRING];            // the main window class name

HWND hWnd_InFile1;								//handle for file
HWND hWnd_btnFile1;								//handle to file button
HWND hWnd_btnCompare;							//search button
HWND hWnd_Search;								//search query value
HWND hWnd_ReturnValue;							//return value display output
char fFile1Path[MAX_PATH];						//first file name selected by user

QueueClass*queue1;								//pointer to 1st file queue object


// Forward declarations of functions included in this code module:
ATOM                MyRegisterClass(HINSTANCE hInstance);
BOOL                InitInstance(HINSTANCE, int);
LRESULT CALLBACK    WndProc(HWND, UINT, WPARAM, LPARAM);
INT_PTR CALLBACK    About(HWND, UINT, WPARAM, LPARAM);

bool GetFileName1();
bool LoadFiles();
int SearchFile();

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
    LoadStringW(hInstance, IDC_CIS023_S2018HW9ALLENMYERS, szWindowClass, MAX_LOADSTRING);
    MyRegisterClass(hInstance);

    // Perform application initialization:
    if (!InitInstance (hInstance, nCmdShow))
    {
        return FALSE;
    }

    HACCEL hAccelTable = LoadAccelerators(hInstance, MAKEINTRESOURCE(IDC_CIS023_S2018HW9ALLENMYERS));

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
    wcex.hIcon          = LoadIcon(hInstance, MAKEINTRESOURCE(IDI_CIS023_S2018HW9ALLENMYERS));
    wcex.hCursor        = LoadCursor(nullptr, IDC_ARROW);
    wcex.hbrBackground  = (HBRUSH)(COLOR_WINDOW+1);
    wcex.lpszMenuName   = MAKEINTRESOURCEW(IDC_CIS023_S2018HW9ALLENMYERS);
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
				if (LOWORD(lParam) == (WORD)hWnd_btnFile1)	// launch standard file open dialog
				{
					if (GetFileName1())
					{
						if (LoadFiles())
							EnableWindow(hWnd_btnCompare, true);
					}
				}
				else if (LOWORD(lParam) == (WORD)hWnd_btnCompare) // compare files
				{
						SearchFile();
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
		//grey background
		CreateWindow(TEXT("STATIC"), TEXT(""),
			WS_VISIBLE | WS_CHILD, 0, 0, 500, 200, hWnd, NULL, NULL, NULL);
		//static label for file name
		CreateWindow(TEXT("STATIC"),
			TEXT("File:"),
			WS_VISIBLE | WS_CHILD,
			10, 10, 40, 20, hWnd, NULL, NULL, NULL);

		hWnd_InFile1 = CreateWindow(TEXT("STATIC"),
			TEXT(""),
			WS_VISIBLE | WS_CHILD, 100, 10, 250, 20, hWnd, NULL, NULL, NULL);
		hWnd_btnFile1 = CreateWindow(TEXT("BUTTON"),
			TEXT("File Open"),
			WS_VISIBLE | WS_CHILD | BS_DEFPUSHBUTTON,
			400, 10, 70, 30, hWnd, NULL, NULL, NULL);
		CreateWindow(TEXT("STATIC"),
			TEXT("Search:"),
			WS_VISIBLE | WS_CHILD,
			10, 40, 50, 20, hWnd, NULL, NULL, NULL);
		hWnd_Search = CreateWindow(TEXT("EDIT"),
			TEXT(""),
			WS_VISIBLE | WS_CHILD, 100, 40, 50, 20, hWnd, NULL, NULL, NULL);
		hWnd_btnCompare = CreateWindow(TEXT("BUTTON"),
			TEXT("Count"),
			WS_VISIBLE | WS_CHILD | BS_DEFPUSHBUTTON,
			10, 70, 70, 30, hWnd, NULL, NULL, NULL);
		hWnd_ReturnValue = CreateWindow(TEXT("STATIC"),
			TEXT(""),
			WS_VISIBLE | WS_CHILD, 40, 100, 25, 20, hWnd, NULL, NULL, NULL);
		EnableWindow(hWnd_btnCompare, false);		// buttons disabled, enabled in order

	}
	break;
    case WM_DESTROY:
		//delete the queues
		if (queue1)
			delete queue1;
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
bool GetFileName1()
{
	char szFileNameIN[MAX_PATH];

	// get the input file name
	OPENFILENAME ofn;
	ZeroMemory(&fFile1Path, sizeof(fFile1Path));
	ZeroMemory(&ofn, sizeof(ofn));
	ofn.lStructSize = sizeof(ofn);
	ofn.hwndOwner = NULL;
	ofn.lpstrFilter = LPWSTR("Any File\0*.*\0");
	ofn.lpstrFile = LPWSTR(fFile1Path);
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
		SendMessage(hWnd_InFile1, WM_SETTEXT, NULL, LPARAM(wcstr));

		return true;
	}
	else
		return false;
}
bool LoadFiles()
{
	ifstream inFile;			//file handle
	char c;						//char read from file
	try
	{
		inFile.open(fFile1Path);	//open the first file
		if (inFile.bad())			//did the file open?
			throw 1;				//throw error message if it didnt
		
		delete queue1;			//delete the previous queue(if tehre is one)
		queue1 = new QueueClass;//create a new queue

		queue1->initializeQueue();	//initialize the 1st queue

		inFile.get(c);				//get a line from file
		while (inFile.good())
		{
			queue1->addQueue(c);	//add a new node to the bottom fo the first node
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

int SearchFile() 
{
	int counter = 0;
	TCHAR SearchValue[100];		//search value
	GetWindowText(				//get the search value
		hWnd_Search,
		SearchValue,
		100
	);
	wstring temp(SearchValue);						//convert TCHAR to stream
	string strSearch(temp.begin(), temp.end());	//convert stream to string

	TCHAR FileValue = queue1->getQueue();	//get data from the queue
	wstring temp1(SearchValue);						//convert TCHAR to stream
	string strFileValues(temp1.begin(), temp1.end());	//convert stream to string

	//now need to check the file that was accessed to search for the char that was
	//obtained into SearchValue above.

	while (FileValue != NULL)
	{
		if (strFileValues == strSearch)
			counter++;
	}
	return counter;
}
