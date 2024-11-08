//Module:	CIS023_S2018_Lab8b Allen Myers.cpp
//Project:	CIS023_S2018_Lab8b Allen Myers
//Author:	Allen Myers
//Date:		March 21st, 2018
//Purpose:	Practice creating a linked list using class code.
//			Create object nodes that link forward and backward in the list.
//			Scroll both directions through a linked list.
#include "stdafx.h"
#include "CIS023_S2018_Lab8b Allen Myers.h"

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
HWND hWnd_btnFirst;								// buttons
HWND hWnd_btnPrev;								// .
HWND hWnd_btnNext;								// .
HWND hWnd_btnLast;								// .

DriversLicense*firstNode,						//objects for linekd list
				*lastNode,
				*newNode,
				*CurrentNode;

// Forward declarations of functions included in this code module:
ATOM                MyRegisterClass(HINSTANCE hInstance);
BOOL                InitInstance(HINSTANCE, int);
LRESULT CALLBACK    WndProc(HWND, UINT, WPARAM, LPARAM);
INT_PTR CALLBACK    About(HWND, UINT, WPARAM, LPARAM);

void LoadFile();								// load file into linked list
void DisplayNode(DriversLicense*);				//display node data

void First();									//move thorugh the list
void Last();
void Next();
void Prev();

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
    LoadStringW(hInstance, IDC_CIS023_S2018_LAB8BALLENMYERS, szWindowClass, MAX_LOADSTRING);
    MyRegisterClass(hInstance);

    // Perform application initialization:
    if (!InitInstance (hInstance, nCmdShow))
    {
        return FALSE;
    }

    HACCEL hAccelTable = LoadAccelerators(hInstance, MAKEINTRESOURCE(IDC_CIS023_S2018_LAB8BALLENMYERS));

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
    wcex.hIcon          = LoadIcon(hInstance, MAKEINTRESOURCE(IDI_CIS023_S2018_LAB8BALLENMYERS));
    wcex.hCursor        = LoadCursor(nullptr, IDC_ARROW);
    wcex.hbrBackground  = (HBRUSH)(COLOR_WINDOW+1);
    wcex.lpszMenuName   = MAKEINTRESOURCEW(IDC_CIS023_S2018_LAB8BALLENMYERS);
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
     // CW_USEDEFAULT, 0, CW_USEDEFAULT, 0, nullptr, nullptr, hInstance, nullptr);
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
		case BN_CLICKED:								// capture button click
		{
			if (LOWORD(lParam) == (WORD)hWnd_btnFirst)
				First();
			else if(LOWORD(lParam) == (WORD)hWnd_btnPrev)
				Prev();
			else if (LOWORD(lParam) == (WORD)hWnd_btnNext)
				Next();
			else if (LOWORD(lParam) == (WORD)hWnd_btnLast)
				Last();


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

		// labels
		CreateWindow(TEXT("STATIC"),
			TEXT("Last Name:"),
			WS_VISIBLE | WS_CHILD,
			10, 20, 340, 20, hWnd, NULL, NULL, NULL);
		CreateWindow(TEXT("STATIC"),
			TEXT("First Name:"),
			WS_VISIBLE | WS_CHILD,
			10, 50, 340, 20, hWnd, NULL, NULL, NULL);
		CreateWindow(TEXT("STATIC"),
			TEXT("City:"),
			WS_VISIBLE | WS_CHILD,
			10, 80, 340, 20, hWnd, NULL, NULL, NULL);
		CreateWindow(TEXT("STATIC"),
			TEXT("Age:"),
			WS_VISIBLE | WS_CHILD,
			10, 110, 340, 20, hWnd, NULL, NULL, NULL);
		CreateWindow(TEXT("STATIC"),
			TEXT("License #:"),
			WS_VISIBLE | WS_CHILD,
			10, 140, 340, 20, hWnd, NULL, NULL, NULL);

		// output static controls
		hWnd_LName = CreateWindow(TEXT("STATIC"),
			TEXT(""),
			WS_VISIBLE | WS_CHILD,
			100, 20, 340, 20, hWnd, NULL, NULL, NULL);
		hWnd_FName = CreateWindow(TEXT("STATIC"),
			TEXT(""),
			WS_VISIBLE | WS_CHILD,
			100, 50, 340, 20, hWnd, NULL, NULL, NULL);
		hWnd_City = CreateWindow(TEXT("STATIC"),
			TEXT(""),
			WS_VISIBLE | WS_CHILD,
			100, 80, 340, 20, hWnd, NULL, NULL, NULL);
		hWnd_Age = CreateWindow(TEXT("STATIC"),
			TEXT(""),
			WS_VISIBLE | WS_CHILD,
			100, 110, 340, 20, hWnd, NULL, NULL, NULL);
		hWnd_License = CreateWindow(TEXT("STATIC"),
			TEXT(""),
			WS_VISIBLE | WS_CHILD,
			100, 140, 340, 20, hWnd, NULL, NULL, NULL);

		// create button
		hWnd_btnFirst = CreateWindow(TEXT("BUTTON"),
			TEXT("<<"),
			WS_VISIBLE | WS_CHILD | BS_DEFPUSHBUTTON,
			10, 180, 70, 30, hWnd, NULL, NULL, NULL);

		hWnd_btnPrev = CreateWindow(TEXT("BUTTON"),
			TEXT("<"),
			WS_VISIBLE | WS_CHILD | BS_DEFPUSHBUTTON,
			100, 180, 70, 30, hWnd, NULL, NULL, NULL);

		hWnd_btnNext = CreateWindow(TEXT("BUTTON"),
			TEXT(">"),
			WS_VISIBLE | WS_CHILD | BS_DEFPUSHBUTTON,
			190, 180, 70, 30, hWnd, NULL, NULL, NULL);

		hWnd_btnLast = CreateWindow(TEXT("BUTTON"),
			TEXT(">>"),
			WS_VISIBLE | WS_CHILD | BS_DEFPUSHBUTTON,
			280, 180, 70, 30, hWnd, NULL, NULL, NULL);
		//initialize linked list pointers
		firstNode = nullptr;
		lastNode = nullptr;
		CurrentNode = nullptr;
		newNode = nullptr;



		// load file into linked list
		LoadFile();
		DisplayNode(firstNode);					//display first node's data, or blank if bad load
	}
	break;

	case WM_DESTROY:
	{
		//delete linked list
		if (firstNode)						//is the linked list populaed
		{
			lastNode->SetNext(nullptr);			//break the link from end to beginning

			DriversLicense*tempNode = nullptr;	//temp hold for moving thorugh list
			CurrentNode = firstNode;			//start at the top of list

			while (CurrentNode != nullptr)		//loop till end of list
			{
				tempNode = CurrentNode->GetNext();	//save pointer to next node
				delete CurrentNode;					//delete the current node
				CurrentNode = tempNode;				//move to the next node
			}
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

			fInput >> strLName							// Read the file
				>> strFName
				>> strCity
				>> strAge
				>> strLic;


			newNode = new DriversLicense(
				strLName,
				strFName,
				strCity,
				strAge,
				strLic);

			//add new node to the list

			if (firstNode == nullptr)						//if this is a new list
				firstNode = newNode;						//then store this new node as the first node
			else 
			{
				lastNode->SetNext(newNode);					//new node is now thr last node
				newNode->SetPrev(lastNode);					//prev node is now the 2nd to last node
				newNode->SetNext(firstNode);				//new node pointers to the beginning of the list

			}
			lastNode = newNode;								//the new node is now know as the last node
			firstNode->SetPrev(lastNode);					//1st node points back to the new node
		}

		fInput.close();									// ALWAYS remember to close the file

		EnableWindow(hWnd_btnNext, true);
	}
	catch (int)
	{
		MessageBox(NULL,
			TEXT("Failed to load file"),
			TEXT("File Error"),
			MB_ICONERROR);

		EnableWindow(hWnd_btnNext, false);

	}
}
void DisplayNode(DriversLicense*Node)
{
	if (Node != nullptr)					//if node points to data
	{
		SetWindowText(
			hWnd_LName,
			Node->GetLName()
		);
		SetWindowText(
			hWnd_FName,
			Node->GetFName()
		);
		SetWindowText(
			hWnd_City,
			Node->GetCity()
		);
		SetWindowText(
			hWnd_Age,
			Node->GetAge()
		);
		SetWindowText(
			hWnd_License,
			Node->GetLicense()
		);


	}
	else                                  //empty node, empty display
	{
		SetWindowText(
			hWnd_LName,
			TEXT("")
		);
		SetWindowText(
			hWnd_FName,
			TEXT("")
		);
		SetWindowText(
			hWnd_City,
			TEXT("")
		);
		SetWindowText(
			hWnd_Age,
			TEXT("")
		);
		SetWindowText(
			hWnd_License,
			TEXT("")
		);
	}
}

void First()
{
	try
	{
		CurrentNode = firstNode;				//set currentnode to firstnode
		if (CurrentNode == nullptr)
			throw(1);

		DisplayNode(CurrentNode);			//display the node
	}
	catch (int)
	{
		DisplayNode(nullptr);				//empty screen

		MessageBox(NULL,					//error message
			TEXT("NODE IS EMPTY"),
			TEXT("ListEror"),
			MB_ICONERROR);
	}

}

void Last()
{
	try
	{
		CurrentNode = lastNode;				//set currentnode to lastnode
		if (CurrentNode == nullptr)
			throw(1);

		DisplayNode(CurrentNode);			//display the node
	}
	catch (int)
	{
		DisplayNode(nullptr);				//empty screen

		MessageBox(NULL,					//error message
			TEXT("NODE IS EMPTY"),
			TEXT("ListEror"),
			MB_ICONERROR);
	}
}

void Next()
{
	try
	{
		if (CurrentNode == nullptr)								//if this is the first time button is clicked
			CurrentNode = firstNode;					//then start at the beginning of this list
		
		CurrentNode = CurrentNode->GetNext();				//set currentnode to previous node

		if (CurrentNode == nullptr)		//bad list
			throw(1);

		DisplayNode(CurrentNode);			//display the node
	}
	catch (int)
	{
		DisplayNode(nullptr);				//empty screen

		MessageBox(NULL,					//error message
			TEXT("NODE IS EMPTY"),
			TEXT("ListEror"),
			MB_ICONERROR);
	}

}

void Prev()
{
	try
	{
		if (CurrentNode == nullptr)								//if this is the first time button is clicked
			CurrentNode = firstNode;					//then start at the beginning of this list

		if (CurrentNode == nullptr)						//bad list
			throw(1);


		CurrentNode = CurrentNode->GetPrev();				//set currentnode to previous node

		DisplayNode(CurrentNode);			//display the node
	}
	catch (int)
	{
		DisplayNode(nullptr);				//empty screen

		MessageBox(NULL,					//error message
			TEXT("NODE IS EMPTY"),
			TEXT("ListEror"),
			MB_ICONERROR);
	}

}
