//Module:	CIS023_S2018_Lab9a Allen Myers.cpp
//Project:	CIS023_S2018_Lab9a Allen Myers
//Author:	Allen Myers
//Date:		March 9th, 2018
//Purpose:	Learn how to create linked list stacks.
//			Initialize, push, pop, and delete stacks.
//			Use the standard file open and standard file save dialog boxes.
//
//
#include "stdafx.h"
#include "CIS023_S2018_Lab9a.h"

#define MAX_LOADSTRING 100

// Global Variables:
HINSTANCE hInst;                                // current instance
WCHAR szTitle[MAX_LOADSTRING];                  // The title bar text
WCHAR szWindowClass[MAX_LOADSTRING];            // the main window class name

HWND hWnd_InFile;								// handle to file input edit box
HWND hWnd_OutFile;								// handle to file output edit box
HWND hWnd_btnOpen;								// butten, standard file open dialog
HWND hWnd_btnSave;								// button, standard file save as dialog

char fInputPath[MAX_PATH];						// input file name, selected by user
char fOutputPath[MAX_PATH];						// output file name, selected by user


StackClass*stack;								//pointer to the stack


// Forward declarations of functions included in this code module:
ATOM                MyRegisterClass(HINSTANCE hInstance);
BOOL                InitInstance(HINSTANCE, int);
LRESULT CALLBACK    WndProc(HWND, UINT, WPARAM, LPARAM);
INT_PTR CALLBACK    About(HWND, UINT, WPARAM, LPARAM);

bool				GetOpenFileName();
bool				GetSaveFileName();
bool				LoadFile();
void				SaveFile();

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
    LoadStringW(hInstance, IDC_CIS023_S2018_LAB9A, szWindowClass, MAX_LOADSTRING);
    MyRegisterClass(hInstance);

    // Perform application initialization:
    if (!InitInstance (hInstance, nCmdShow))
    {
        return FALSE;
    }

    HACCEL hAccelTable = LoadAccelerators(hInstance, MAKEINTRESOURCE(IDC_CIS023_S2018_LAB9A));

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
    wcex.hIcon          = LoadIcon(hInstance, MAKEINTRESOURCE(IDI_CIS023_S2018_LAB9A));
    wcex.hCursor        = LoadCursor(nullptr, IDC_ARROW);
    wcex.hbrBackground  = (HBRUSH)(COLOR_WINDOW+1);
    wcex.lpszMenuName   = MAKEINTRESOURCEW(IDC_CIS023_S2018_LAB9A);
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
      CW_USEDEFAULT, 0, 410, 200, nullptr, nullptr, hInstance, nullptr);

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
				if (LOWORD(lParam) == (WORD)hWnd_btnOpen)	// launch standard file open dialog
				{
					if (GetOpenFileName())
					{
						if (LoadFile())
							EnableWindow(hWnd_btnSave, true);
					}

				}

				else if (LOWORD(lParam) == (WORD)hWnd_btnSave) // launch standard file save dialog
				{
					if (GetSaveFileName())
						SaveFile();
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
		// grey background
		CreateWindow(TEXT("STATIC"), TEXT(""),
			WS_VISIBLE | WS_CHILD, 0, 0, 400, 200, hWnd, NULL, NULL, NULL);

		CreateWindow(TEXT("STATIC"),
			TEXT("     Input file name:   "),
			WS_VISIBLE | WS_CHILD, 0, 10, 400, 20, hWnd, NULL, NULL, NULL);

		CreateWindow(TEXT("STATIC"),
			TEXT("     Output file name:   "),
			WS_VISIBLE | WS_CHILD, 0, 40, 400, 20, hWnd, NULL, NULL, NULL);

		hWnd_InFile = CreateWindow(TEXT("STATIC"),
			TEXT(""),
			WS_VISIBLE | WS_CHILD, 150, 10, 250, 20, hWnd, NULL, NULL, NULL);

		hWnd_OutFile = CreateWindow(TEXT("STATIC"),
			TEXT(""),
			WS_VISIBLE | WS_CHILD, 150, 40, 250, 20, hWnd, NULL, NULL, NULL);

		hWnd_btnOpen = CreateWindow(TEXT("BUTTON"),
			TEXT("Open"),
			WS_VISIBLE | WS_CHILD | BS_DEFPUSHBUTTON,
			160, 100, 70, 30, hWnd, NULL, NULL, NULL);

		hWnd_btnSave = CreateWindow(TEXT("BUTTON"),
			TEXT("Save"),
			WS_VISIBLE | WS_CHILD | BS_DEFPUSHBUTTON,
			250, 100, 70, 30, hWnd, NULL, NULL, NULL);

		EnableWindow(hWnd_btnSave, false); // Save button disabled until file successfully loaded

	}
	break;

	case WM_DESTROY:

		if (stack)
			delete stack;			//delete the stack

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

bool GetOpenFileName()
{
	char szFileNameIN[MAX_PATH];

	// get the input file name
	OPENFILENAME ofn;
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

bool GetSaveFileName()
{
	char szFileNameOUT[MAX_PATH];

	// get the output file name
	OPENFILENAME ofn;
	ZeroMemory(&fOutputPath, sizeof(fOutputPath));
	ZeroMemory(&ofn, sizeof(ofn));
	ofn.lStructSize = sizeof(ofn);
	ofn.hwndOwner = NULL;
	ofn.lpstrFilter = LPWSTR("Any File\0*.*\0");
	ofn.lpstrFile = LPWSTR(fOutputPath);
	ofn.nMaxFile = MAX_PATH;
	ofn.lpstrFileTitle = LPWSTR(szFileNameOUT);
	ofn.nMaxFileTitle = MAX_PATH;
	ofn.lpstrTitle = LPWSTR("Select an output File");
	ofn.Flags = OFN_DONTADDTORECENT | OFN_OVERWRITEPROMPT;

	if (GetSaveFileNameA(LPOPENFILENAMEA(&ofn))) // user selected an output file
	{
		// copy the string into a char*
		size_t pReturnValue;
		wchar_t wcstr[MAX_LOADSTRING];
		mbstowcs_s(&pReturnValue, wcstr, MAX_LOADSTRING, szFileNameOUT, MAX_LOADSTRING);
		SendMessage(hWnd_OutFile, WM_SETTEXT, NULL, LPARAM(wcstr));

		return true;
	}
	else
		return false;

}

bool LoadFile()
{
	ifstream inFile;			//file handle
	char c;						//a char from the file

	try
	{
		//make sure the file will open before creating the stack
		inFile.open(fInputPath);	//open the file
		if (inFile.bad())			//if not open
			throw 1;

		if (stack)					//if already loaded
			delete stack;			//delete previous load

		stack = new StackClass;	//create the stack

		inFile.get(c);				//get the first char from the file

		while (inFile.good())		//red the entire file into the stack
		{
			//push char into stack
			stack->push(c);
			inFile.get(c);			//read a characther

		}

		inFile.close();				//close the file

	}
	catch (int)
	{
		MessageBox(NULL,					//ERROR MESSAGE IF FILE IS NOT OPEN
			TEXT("UNABLE TO OPEN THE FILE"),
			TEXT("FILE OPEN ERROR"),
			MB_ICONEXCLAMATION);

		return	false;

	}

	return true;

}

void SaveFile()
{
	ofstream outFile;				//handle to output file
	char c;							//char to write to file

	try
	{
		outFile.open(fOutputPath);		//open the file

		if (outFile.bad())				//did it open okay?
			throw 1;					//if it didnt throw exception

		while (!stack->isEmptyStack())	//write until stack is empty
		{
			c = stack->pop();			//get data
			outFile << c;				//write data to output file
		}
		delete stack;					//delete the stack becasue it is empty
		stack = nullptr;				//and throw away it's addresses

		outFile.close();				//close the file
	

	}
	catch(int)
	{
		MessageBox(NULL,						//ERROR MESSAGE
			TEXT("UNABLE TO OPEN OUTPUT FILE "),
			TEXT("FILE WRITE ERROR"),
			MB_ICONERROR);
	}
	if (stack)					//if there is a stack
		delete stack;			//delete it



}
