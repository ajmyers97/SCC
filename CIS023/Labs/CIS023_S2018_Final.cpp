//Module:	CIS023_S2018_Final Allen Myers.cpp : Defines the entry point for the application.
//Project:	CIS023_S2018_Final Allen Myers
//Date:		May 21st, 2018
//Purpose:	Demonstrate the ability to complete a Visual C++ Win32 project.
//			Demonstrate the ability to load a linked list.
//			Demonstrate the ability to search a linked list for data that matches a defined criteria.
//			Demonstrate the ability to write to a file.
//

#include "stdafx.h"
#include "CIS023_S2018_Final.h"

#define MAX_LOADSTRING 100

// Global Variables:
HINSTANCE hInst;                                // current instance
WCHAR szTitle[MAX_LOADSTRING];                  // The title bar text
WCHAR szWindowClass[MAX_LOADSTRING];            // the main window class name

HWND hWnd_Open;									// file open button
HWND hWnd_Save;									// file save button
HWND hWnd_inFileName;							// input file name label
HWND hWnd_outFileName;							// output file name label

char fInputPath[MAX_PATH];						// input file name, selected by user
char fOutputPath[MAX_PATH];						// output file name, selected by user

LinkedList * list;								// pointer to linked list object

// Forward declarations of functions included in this code module:
ATOM                MyRegisterClass(HINSTANCE hInstance);
BOOL                InitInstance(HINSTANCE, int);
LRESULT CALLBACK    WndProc(HWND, UINT, WPARAM, LPARAM);
INT_PTR CALLBACK    About(HWND, UINT, WPARAM, LPARAM);

bool GetOpenFileName();							// standard open file dialog
bool GetSaveFileName();							// standard save file dialog
bool LoadFile();								// open, read, close
bool SaveFile();								// open, write, close


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
    LoadStringW(hInstance, IDC_CIS023_S2018_FINAL, szWindowClass, MAX_LOADSTRING);
    MyRegisterClass(hInstance);

    // Perform application initialization:
    if (!InitInstance (hInstance, nCmdShow))
    {
        return FALSE;
    }

    HACCEL hAccelTable = LoadAccelerators(hInstance, MAKEINTRESOURCE(IDC_CIS023_S2018_FINAL));

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
    wcex.hIcon          = LoadIcon(hInstance, MAKEINTRESOURCE(IDI_CIS023_S2018_FINAL));
    wcex.hCursor        = LoadCursor(nullptr, IDC_ARROW);
    wcex.hbrBackground  = (HBRUSH)(COLOR_WINDOW+1);
    wcex.lpszMenuName   = MAKEINTRESOURCEW(IDC_CIS023_S2018_FINAL);
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
      CW_USEDEFAULT, 0, 500, 250, nullptr, nullptr, hInstance, nullptr);

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
			if (LOWORD(lParam) == (WORD)hWnd_Open)	// launch standard file open dialog
			{
				if (GetOpenFileName())
				{
					if (LoadFile())
						EnableWindow(hWnd_Save, true);
				}

			}

			else if (LOWORD(lParam) == (WORD)hWnd_Save) // launch standard file save dialog
			{
				if (GetSaveFileName())
					if (!SaveFile())
						EnableWindow(hWnd_Save, false);

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
		CreateWindow(TEXT("STATIC"),	// background
			TEXT(""),
			WS_VISIBLE | WS_CHILD, 0, 0, 500, 250, hWnd, NULL, NULL, NULL);

		CreateWindow(TEXT("STATIC"),
			TEXT("FILE SORT"),
			WS_VISIBLE | WS_CHILD,
			100, 20, 250, 20, hWnd, NULL, NULL, NULL);

		hWnd_Open = CreateWindow(TEXT("BUTTON"),
			TEXT("Open"),
			WS_VISIBLE | WS_CHILD | BS_DEFPUSHBUTTON,
			20, 60, 50, 30, hWnd, NULL, NULL, NULL);

		hWnd_Save = CreateWindow(TEXT("BUTTON"),
			TEXT("Save"),
			WS_VISIBLE | WS_CHILD | BS_DEFPUSHBUTTON,
			20, 110, 50, 30, hWnd, NULL, NULL, NULL);

		hWnd_inFileName = CreateWindow(TEXT("STATIC"),
			TEXT(""),
			WS_VISIBLE | WS_CHILD,
			100, 65, 400, 20, hWnd, NULL, NULL, NULL);

		hWnd_outFileName = CreateWindow(TEXT("STATIC"),
			TEXT(""),
			WS_VISIBLE | WS_CHILD,
			100, 115, 400, 20, hWnd, NULL, NULL, NULL);

		EnableWindow(hWnd_Save, false); // Save button disabled until file successfully loaded

		
		break;

	case WM_DESTROY:
		
		if (list)			//if there is a linked list, delete it
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
		SendMessage(hWnd_inFileName, WM_SETTEXT, NULL, LPARAM(wcstr));

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
		SendMessage(hWnd_outFileName, WM_SETTEXT, NULL, LPARAM(wcstr));

		return true;
	}
	else
		return false;

}

bool LoadFile()
{
	ifstream inFile;										// file handle
	string strLine;											// line of text
	wchar_t wcOuput[100];									// output to form

	try
	{
		inFile.open(fInputPath);							// open the tile

		if (inFile.bad())									// did file opwn?
			throw 1;

		getline(inFile, strLine);							// read the 1st line in the file

		while (inFile.good())								// read to end of file
		{
			ListNode* newNode = new ListNode;				//new list node

			newNode->SetData(strLine);		
			list->Append(strLine).GetNext();							//this should append the linked list, but it doesnt for me...
			

			getline(inFile, strLine);						// get next line


		}

		inFile.close();										// close the file

		EnableWindow(hWnd_Save, true);						// Enable Save button

	}
	catch (int)
	{
		MessageBox(NULL, TEXT("Unable to open input file."), TEXT("File Open Error"), MB_ICONEXCLAMATION);
		return false;
	}

	return true;
}

bool SaveFile()
{
	ofstream outFile;					// file handle
	try
	{
		// make sure the file will open before creating the stack
		outFile.open(fOutputPath);
		if (outFile.bad())
			throw 1;

		string strLineOut;

		// output contents of linked list in sorted order
		while (list->GetCurrentNode() >= list->GetLastNode())		//while noth the last node
		{
			if (list->GetCurrentNode() < list->GetCurrentNode()->GetNext())	//the current node is less than next node
			{
				//strLineOut = list->GetCurrentNode();	//the output string is this node
			}
			else
			{
				//strLineOut = list->GetCurrentNode()->GetNext();	//otherwise the output string is the next line

			}
		}

		cout << strLineOut << endl;						//output string


		outFile.close();				// done with the output file
	}
	catch (int)
	{
		MessageBox(NULL,
			TEXT("Unable to open ouput file."),
			TEXT("File Write Error"),
			MB_ICONEXCLAMATION);


		return false;					// failed to save file
	}

	return true;						// file saved
}
