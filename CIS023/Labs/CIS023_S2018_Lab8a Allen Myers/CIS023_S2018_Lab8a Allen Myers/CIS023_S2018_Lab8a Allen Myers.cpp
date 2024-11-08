//Module:	CIS023_S2018_Lab8a Allen Myers.cpp
//Project:	CIS023_S2018_Lab8a Allen Myers
//Author:	Allen Myers
//Date:		March 19th, 2018
//Purpose:	Learn how to create a linked list using class code.
//			Create object nodes and fill them with data.
//			Scroll through an object - based linked list to find a specific node.
//
//

#include "stdafx.h"
#include "CIS023_S2018_Lab8a Allen Myers.h"

#define MAX_LOADSTRING 100

// Global Variables:
HINSTANCE hInst;                                // current instance
WCHAR szTitle[MAX_LOADSTRING];                  // The title bar text
WCHAR szWindowClass[MAX_LOADSTRING];            // the main window class name

HWND hWnd_Input;								// input field
HWND hWnd_LName;								// output fields
HWND hWnd_FName;								// .
HWND hWnd_City;									// .
HWND hWnd_Age;									// .
HWND hWnd_License;								// .
HWND hWnd_Find;									// Button

DriversLicense*firstNode,					//1st node in linked list	
*lastNode,									//last node
*newNode,								//create/append a node to the list
*currentNode;									//points to current node


// Forward declarations of functions included in this code module:
ATOM                MyRegisterClass(HINSTANCE hInstance);
BOOL                InitInstance(HINSTANCE, int);
LRESULT CALLBACK    WndProc(HWND, UINT, WPARAM, LPARAM);
INT_PTR CALLBACK    About(HWND, UINT, WPARAM, LPARAM);

void LoadFile();								// load file into linked list

void DisplayData(DriversLicense*);				//display all node data into main window

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
    LoadStringW(hInstance, IDC_CIS023_S2018_LAB8AALLENMYERS, szWindowClass, MAX_LOADSTRING);
    MyRegisterClass(hInstance);

    // Perform application initialization:
    if (!InitInstance (hInstance, nCmdShow))
    {
        return FALSE;
    }

    HACCEL hAccelTable = LoadAccelerators(hInstance, MAKEINTRESOURCE(IDC_CIS023_S2018_LAB8AALLENMYERS));

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
    wcex.hIcon          = LoadIcon(hInstance, MAKEINTRESOURCE(IDI_CIS023_S2018_LAB8AALLENMYERS));
    wcex.hCursor        = LoadCursor(nullptr, IDC_ARROW);
    wcex.hbrBackground  = (HBRUSH)(COLOR_WINDOW+1);
    wcex.lpszMenuName   = MAKEINTRESOURCEW(IDC_CIS023_S2018_LAB8AALLENMYERS);
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
      CW_USEDEFAULT, 0, 375, 300, nullptr, nullptr, hInstance, nullptr);

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
			case BN_CLICKED:	//capture button click
				if (LOWORD(lParam) == (WORD)hWnd_Find)
				{
					TCHAR szInput[TCHAR_SIZE];				//user input
					int iInput = 0;

					SendMessage(							//send a message
						hWnd_Input,//to the input edit control
						WM_GETTEXT,							//get its text
						TCHAR_SIZE,							//max num of chars
						LPARAM(szInput)						//store in szInput
					);
					iInput = _tstoi(szInput);				//convert user input to integer
					if (iInput > 0 && iInput <= 100)				//in range
					{
						//roll through linked list for node number user asked for
						for (int i = 1;i <= iInput;i++)
						{
							if (i == 1)					//if this is the first i in the for loop
								currentNode = firstNode;//start at the top of list
							else
								currentNode =			//else move to the next node
								currentNode->GetNext();
						}

						DisplayData(currentNode);		//display the found node

					}
					else
						DisplayData(nullptr);			//if outside the range, blank the display


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
			WS_VISIBLE | WS_CHILD, 0, 0, 400, 300, hWnd, NULL, NULL, NULL);

		// prompt
		CreateWindow(TEXT("STATIC"),
			TEXT("Please enter a number between 1 and 100"),
			WS_VISIBLE | WS_CHILD,
			10, 10, 340, 20, hWnd, NULL, NULL, NULL);

		// labels
		CreateWindow(TEXT("STATIC"),
			TEXT("Last Name:"),
			WS_VISIBLE | WS_CHILD,
			10, 50, 340, 20, hWnd, NULL, NULL, NULL);
		CreateWindow(TEXT("STATIC"),
			TEXT("First Name:"),
			WS_VISIBLE | WS_CHILD,
			10, 80, 340, 20, hWnd, NULL, NULL, NULL);
		CreateWindow(TEXT("STATIC"),
			TEXT("City:"),
			WS_VISIBLE | WS_CHILD,
			10, 110, 340, 20, hWnd, NULL, NULL, NULL);
		CreateWindow(TEXT("STATIC"),
			TEXT("Age:"),
			WS_VISIBLE | WS_CHILD,
			10, 140, 340, 20, hWnd, NULL, NULL, NULL);
		CreateWindow(TEXT("STATIC"),
			TEXT("License #:"),
			WS_VISIBLE | WS_CHILD,
			10, 170, 340, 20, hWnd, NULL, NULL, NULL);

		// create edit control for user input
		hWnd_Input = CreateWindow(TEXT("EDIT"),
			NULL,
			WS_CHILD | WS_VISIBLE | WS_BORDER |
			ES_AUTOHSCROLL | WS_CHILD | ES_NUMBER,
			300, 10, 35, 20, hWnd, NULL, NULL, NULL);

		// output static controls
		hWnd_LName = CreateWindow(TEXT("STATIC"),
			TEXT(""),
			WS_VISIBLE | WS_CHILD,
			100, 50, 340, 20, hWnd, NULL, NULL, NULL);
		hWnd_FName = CreateWindow(TEXT("STATIC"),
			TEXT(""),
			WS_VISIBLE | WS_CHILD,
			100, 80, 340, 20, hWnd, NULL, NULL, NULL);
		hWnd_City = CreateWindow(TEXT("STATIC"),
			TEXT(""),
			WS_VISIBLE | WS_CHILD,
			100, 110, 340, 20, hWnd, NULL, NULL, NULL);
		hWnd_Age = CreateWindow(TEXT("STATIC"),
			TEXT(""),
			WS_VISIBLE | WS_CHILD,
			100, 140, 340, 20, hWnd, NULL, NULL, NULL);
		hWnd_License = CreateWindow(TEXT("STATIC"),
			TEXT(""),
			WS_VISIBLE | WS_CHILD,
			100, 170, 340, 20, hWnd, NULL, NULL, NULL);

		// find button
		hWnd_Find = CreateWindow(TEXT("BUTTON"),
			TEXT("Find"),
			WS_VISIBLE | WS_CHILD | BS_DEFPUSHBUTTON,
			150, 200, 70, 30, hWnd, NULL, NULL, NULL);

		//initiale linked list pointers
		firstNode = nullptr;
		lastNode = nullptr;
		newNode = nullptr;
		currentNode = nullptr;


		// load file into linked list
		LoadFile();

	}
	break;

    case WM_DESTROY:
	{
		//delete linked list
		DriversLicense*tempNode = nullptr;		//temp node pointer
		currentNode = firstNode;				//start at the top of the list
		while (currentNode != nullptr)				//loop until entire list delelte
		{
			tempNode = currentNode->GetNext();		//save pointer to next node
			delete currentNode;						//delete the current node
			currentNode = tempNode;					//set current to the next one

		}


		PostQuitMessage(0);
	}
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
// load the file into the linked list
void LoadFile()
{
	string strLName = "";								// temps to hold file data
	string strFName = "";
	string strCity = "";
	string strAge = "";
	string strLic = "";

	ifstream fInput;									// file pointer

	try
	{
		fInput.open("CIS023_S2018_Lab8_Data.txt");		// open file

		if (!fInput)
			throw 1;

		while (fInput.good())
		{
			newNode = new DriversLicense();				//creates new node
			

			fInput >> strLName							// Read the file
				>> strFName
				>> strCity
				>> strAge
				>> strLic;
			newNode ->SetData(							//store the data in node object
				strLName,strFName, strCity, strAge, strLic);

			if (firstNode == nullptr)						//is this a new list
				firstNode = newNode;						//then this is the only node
			else
				lastNode->SetNext(newNode);					//else set pointer of the last node to this new node
			
			lastNode = newNode;								//this new node becomes the last node

			EnableWindow(hWnd_Find, true);					//enable search button
		}

		fInput.close();										// ALWAYS remember to close the file

		DisplayData(firstNode);								//display the first node
		EnableWindow(hWnd_Find, true);						// enable search button
	}
	catch (int)
	{
		MessageBox(NULL,
			TEXT("Failed to load file"),
			TEXT("File Error"),
			MB_ICONERROR);

		EnableWindow(hWnd_Find, false);						// disable search

	}
}
void DisplayData(DriversLicense*Node)//display all node data into main window
{
	if (Node != nullptr)							//don't try to display a null node
	{
		//display data in main window
		SetWindowText(hWnd_LName, Node->GetLName());
		SetWindowText(hWnd_FName, Node->GetFName());
		SetWindowText(hWnd_City, Node->GetCity());
		SetWindowText(hWnd_Age, Node->GetAge());
		SetWindowText(hWnd_License, Node->GetDLNum());

		}
	else
	{
			//if null pointer
		SetWindowText(hWnd_LName, NULL);
		SetWindowText(hWnd_FName, NULL);
		SetWindowText(hWnd_City, NULL);
		SetWindowText(hWnd_Age, NULL);
		SetWindowText(hWnd_License, NULL);
	}
}