//Module:	CIS023_S2018_Lab8d Allen Myers.cpp
//Project:	CIS023_S2018_Lab8d Allen Myers
//Author:	Allen Myers
//Date:		March 28th, 2018
//Purpose:	Practice traversing through a linked list.
//			Code string matching searches.
//			Interact with combo boxes.
//
//

#include "stdafx.h"
#include "CIS023_S2018_Lab8d Allen Myers.h"

#define MAX_LOADSTRING 100
#define LAST_NAME  0
#define FIRST_NAME  1
#define CITY  2
#define AGE  3
#define LICENSE  4

// Global Variables:
HINSTANCE hInst;                                // current instance
WCHAR szTitle[MAX_LOADSTRING];                  // The title bar text
WCHAR szWindowClass[MAX_LOADSTRING];            // the main window class name

HWND hWnd_cboLName;								// output fields
HWND hWnd_cboFName;								// .
HWND hWnd_cboCity;								// .
HWND hWnd_cboAge;								// .
HWND hWnd_cboLicense;							// .

NodeClass*firstNode = nullptr,			// objects for linked list
*lastNode = nullptr,
*newNode = nullptr,
*currentNode = nullptr;


// Forward declarations of functions included in this code module:
ATOM                MyRegisterClass(HINSTANCE hInstance);
BOOL                InitInstance(HINSTANCE, int);
LRESULT CALLBACK    WndProc(HWND, UINT, WPARAM, LPARAM);
INT_PTR CALLBACK    About(HWND, UINT, WPARAM, LPARAM);

void LoadFile();								// load file into linked list
void Display(NodeClass*);						// display current node on main window
void Find(TCHAR*, int);							// find a node based on a search string


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
    LoadStringW(hInstance, IDC_CIS023_S2018_LAB8DALLENMYERS, szWindowClass, MAX_LOADSTRING);
    MyRegisterClass(hInstance);

    // Perform application initialization:
    if (!InitInstance (hInstance, nCmdShow))
    {
        return FALSE;
    }

    HACCEL hAccelTable = LoadAccelerators(hInstance, MAKEINTRESOURCE(IDC_CIS023_S2018_LAB8DALLENMYERS));

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
    wcex.hIcon          = LoadIcon(hInstance, MAKEINTRESOURCE(IDI_CIS023_S2018_LAB8DALLENMYERS));
    wcex.hCursor        = LoadCursor(nullptr, IDC_ARROW);
    wcex.hbrBackground  = (HBRUSH)(COLOR_WINDOW+1);
    wcex.lpszMenuName   = MAKEINTRESOURCEW(IDC_CIS023_S2018_LAB8DALLENMYERS);
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
	   CW_USEDEFAULT, 0, 375, 350, nullptr, nullptr, hInstance, nullptr);
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
			case BN_CLICKED:			//something in combo box was clicked
				if (HIWORD(wParam) == CBN_SELCHANGE)			//if combo box selection was changed
				{
					TCHAR szIndex[TCHAR_SIZE];				//selected text


					if (LOWORD(lParam) == (WORD)hWnd_cboLName)
					{
						//get item number of new selection(0 based list)
						int ItemIndex = SendMessage(hWnd_cboLName, CB_GETCURSEL, NULL, NULL);

						//get the text from the listbox of the combo box
						SendMessage(hWnd_cboLName, CB_GETLBTEXT, ItemIndex, (LPARAM)szIndex);
						//find and display the recond
						Find(szIndex, LAST_NAME);

					}
					if (LOWORD(lParam) == (WORD)hWnd_cboFName)
					{
						//get item number of new selection(0 based list)
						int ItemIndex = SendMessage(hWnd_cboFName, CB_GETCURSEL, NULL, NULL);

						//get the text from the listbox of the combo box
						SendMessage(hWnd_cboFName, CB_GETLBTEXT, ItemIndex, (LPARAM)szIndex);
						//find and display the recond
						Find(szIndex, FIRST_NAME);

					}
					if (LOWORD(lParam) == (WORD)hWnd_cboCity)
					{
						//get item number of new selection(0 based list)
						int ItemIndex = SendMessage(hWnd_cboCity, CB_GETCURSEL, NULL, NULL);

						//get the text from the listbox of the combo box
						SendMessage(hWnd_cboCity, CB_GETLBTEXT, ItemIndex, (LPARAM)szIndex);
						//find and display the recond
						Find(szIndex, CITY);

					}
					if (LOWORD(lParam) == (WORD)hWnd_cboAge)
					{
						//get item number of new selection(0 based list)
						int ItemIndex = SendMessage(hWnd_cboAge, CB_GETCURSEL, NULL, NULL);

						//get the text from the listbox of the combo box
						SendMessage(hWnd_cboAge, CB_GETLBTEXT, ItemIndex, (LPARAM)szIndex);
						//find and display the recond
						Find(szIndex, AGE);

					}
					if (LOWORD(lParam) == (WORD)hWnd_cboLicense)
					{
						//get item number of new selection(0 based list)
						int ItemIndex = SendMessage(hWnd_cboLicense, CB_GETCURSEL, NULL, NULL);

						//get the text from the listbox of the combo box
						SendMessage(hWnd_cboLicense, CB_GETLBTEXT, ItemIndex, (LPARAM)szIndex);
						//find and display the recond
						Find(szIndex, LICENSE);

					}
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

		// combo boxes
		hWnd_cboLName = CreateWindow(TEXT("COMBOBOX"),
			TEXT(""),
			CBS_DROPDOWN | CBS_HASSTRINGS |
			//	CBS_SORT |										// items are soted in the listbox
			WS_CHILD | WS_OVERLAPPED | WS_VISIBLE | WS_VSCROLL,
			100, 20, 240, 200, hWnd, NULL, NULL, NULL);

		hWnd_cboFName = CreateWindow(TEXT("COMBOBOX"),
			TEXT(""),
			CBS_DROPDOWN | CBS_HASSTRINGS |
			CBS_SORT |										// items are soted in the listbox
			WS_CHILD | WS_OVERLAPPED | WS_VISIBLE | WS_VSCROLL,
			100, 50, 240, 200, hWnd, NULL, NULL, NULL);

		hWnd_cboCity = CreateWindow(TEXT("COMBOBOX"),
			TEXT(""),
			CBS_DROPDOWN | CBS_HASSTRINGS |
			CBS_SORT |										// items are soted in the listbox
			WS_CHILD | WS_OVERLAPPED | WS_VISIBLE | WS_VSCROLL,
			100, 80, 240, 200, hWnd, NULL, NULL, NULL);

		hWnd_cboAge = CreateWindow(TEXT("COMBOBOX"),
			TEXT(""),
			CBS_DROPDOWN | CBS_HASSTRINGS |
			CBS_SORT |										// items are soted in the listbox
			WS_CHILD | WS_OVERLAPPED | WS_VISIBLE | WS_VSCROLL,
			100, 110, 240, 200, hWnd, NULL, NULL, NULL);

		hWnd_cboLicense = CreateWindow(TEXT("COMBOBOX"),
			TEXT(""),
			CBS_DROPDOWN | CBS_HASSTRINGS |
			CBS_SORT |										// items are soted in the listbox
			WS_CHILD | WS_OVERLAPPED | WS_VISIBLE | WS_VSCROLL,
			100, 140, 240, 200, hWnd, NULL, NULL, NULL);

		// load file into linked list
		LoadFile();

	}
	break;

    case WM_DESTROY:
	{
		//delete linked list
		if (lastNode != nullptr)
			lastNode->SetNext(nullptr);					//set last node to nullptr to prevent running of the end

		NodeClass*tempNode = nullptr;				//temp node to hold next value
		currentNode = firstNode;					//starts at the top fo the list
		while (currentNode != nullptr)
		{
			tempNode = currentNode->GetNext();		//save pointer to next
			delete currentNode;						//delete current node
			currentNode = tempNode;					//advance to next node
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

// load the data file and create the linked list
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
		fInput.open("CIS023_S2018_Lab8d_Data.txt");		// open file

		if (!fInput)									// if file did not open
			throw 1;

		while (fInput.good())
		{

			fInput >> strLName							// Read the file
				>> strFName
				>> strCity
				>> strAge
				>> strLic;

			//create new node of type NodeClass and set the node's data
			newNode = new NodeClass(
				strLName, 
				strFName, 
				strCity, 
				strAge, 
				strLic
			);
			newNode->SetNext(newNode);					//initialize list pointers
			newNode->SetPrev(newNode);					//to point to itself

			if (firstNode == nullptr)						//if this is the first node
				firstNode = newNode;						//then store it is first node
			else											//else append new node to end of list
			{
				lastNode->SetNext(newNode);					//the current last node points to this new node
				newNode->SetPrev(lastNode);					//new node is now at the end of the list
				newNode->SetNext(firstNode);				//new node's next points to the beginning fo the list
			}
			lastNode = newNode;							//if this new node is nwo the last node in the list
			firstNode->SetPrev(lastNode);				//set rollaround for first node

		}

		fInput.close();									// ALWAYS remember to close the file
		currentNode = firstNode;						//set current node to first node

		do
		{
			//add current node data to the list boxes
			SendMessage(hWnd_cboLName, CB_ADDSTRING, NULL, (LPARAM)currentNode->GetLName());
			SendMessage(hWnd_cboFName, CB_ADDSTRING, NULL, (LPARAM)currentNode->GetFName());
			SendMessage(hWnd_cboAge, CB_ADDSTRING, NULL, (LPARAM)currentNode->GetAge());
			SendMessage(hWnd_cboCity, CB_ADDSTRING, NULL, (LPARAM)currentNode->GetCity());
			SendMessage(hWnd_cboLicense, CB_ADDSTRING, NULL, (LPARAM)currentNode->GetLicense());

			currentNode = currentNode->GetNext();		//advance to next node

		} while (currentNode != firstNode);				//quit when at last node

		currentNode = firstNode;						//set current node to first node

		Display(currentNode);							//display 1st node


	}
	catch (int)
	{

		MessageBox(NULL,
			TEXT("Failed to load file"),
			TEXT("File Error"),
			MB_ICONERROR);


	}
}


// display contents of node on window
void Display(NodeClass * Node)
{
	if (Node != nullptr)					//if this is not an empty node
	{
		SetWindowText(
			hWnd_cboLName,
			Node->GetLName());					//display node's data
		SetWindowText(
			hWnd_cboFName,
			Node->GetFName());					//display node's data
		SetWindowText(
			hWnd_cboAge,
			Node->GetAge());					//display node's data
		SetWindowText(
			hWnd_cboCity,
			Node->GetCity());					//display node's data
		SetWindowText(
			hWnd_cboLicense,
			Node->GetLicense());					//display node's data

	}
	else									//else this is an empty node
	{
		SetWindowText(
			hWnd_cboLName,
			NULL);					//display nothing
		SetWindowText(
			hWnd_cboFName,
			NULL);					//display nothing
		SetWindowText(
			hWnd_cboAge,
			NULL);					//display nothing
		SetWindowText(
			hWnd_cboCity,
			NULL);					//display nothing
		SetWindowText(
			hWnd_cboLicense,
			NULL);					//display nothing
	}

}


// find and display node
void Find(TCHAR* szSearch, int iItem)
{
	NodeClass*foundNode = nullptr;		//will point to the matching node when we find it
	currentNode = firstNode;			//start at the top of the lsit
	do
	{
		switch (iItem)					//which datat item are we searching on
		{
		case LAST_NAME:
			if (_tcscmp(szSearch, currentNode->GetLName()) == 0)
				foundNode = currentNode;
			break;
		case FIRST_NAME:
			if (_tcscmp(szSearch, currentNode->GetFName()) == 0)
				foundNode = currentNode;
			break;
		case CITY:
			if (_tcscmp(szSearch, currentNode->GetCity()) == 0)
				foundNode = currentNode;
			break;
		case AGE:
			if (_tcscmp(szSearch, currentNode->GetAge()) == 0)
				foundNode = currentNode;
			break;
		case LICENSE:
			if (_tcscmp(szSearch, currentNode->GetLicense()) == 0)
				foundNode = currentNode;
			break;
		default:
			foundNode = nullptr;		//incorrect search, cannot find node
			break;

		}



		currentNode = currentNode->GetNext();		//advance to the next node

	} while (currentNode !=firstNode);	//until at end of linekd list
	Display(foundNode);					//display found, or nothing if not found
}


