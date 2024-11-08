//Module:	CIS023_S2018_Lab8C Allen Myers.cpp
//Project:	CIS023_S2018_Lab8C Allen Myers
//Author:	Allen Myers
//Date:		March 26th, 2018
//Purpose:	Practice traversing through a linked list.
//			Copy a node in a list.
//			Cut a node in a list.
//			Insert a node into a list.
//

#include "stdafx.h"
#include "CIS023_S2018_Lab8C Allen Myers.h"

#define MAX_LOADSTRING 100

#define MOVE_FIRST -2							// movements
#define MOVE_PREV -1
#define MOVE_NEXT 1
#define MOVE_LAST 2

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
HWND hWnd_btnCopy;								// .
HWND hWnd_btnCut;								// .
HWND hWnd_btnPaste;								// .
NodeClass		*firstNode = nullptr,			// objects for linked list
				*lastNode = nullptr,
				*newNode = nullptr,
				*currentNode = nullptr;

NodeClass		*copyNode = nullptr;			// copy of currentNode, when copy or cut button clicked

// Forward declarations of functions included in this code module:
ATOM                MyRegisterClass(HINSTANCE hInstance);
BOOL                InitInstance(HINSTANCE, int);
LRESULT CALLBACK    WndProc(HWND, UINT, WPARAM, LPARAM);
INT_PTR CALLBACK    About(HWND, UINT, WPARAM, LPARAM);

void LoadFile();								// load file into linked list
void Move(int);									// Move(direction)
void Copy();									// copy the current node
void Cut();										// delete the current node
void Paste();									// paste copied node into current location
void Display(NodeClass*);						// display node data

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
    LoadStringW(hInstance, IDC_CIS023_S2018_LAB8CALLENMYERS, szWindowClass, MAX_LOADSTRING);
    MyRegisterClass(hInstance);

    // Perform application initialization:
    if (!InitInstance (hInstance, nCmdShow))
    {
        return FALSE;
    }

    HACCEL hAccelTable = LoadAccelerators(hInstance, MAKEINTRESOURCE(IDC_CIS023_S2018_LAB8CALLENMYERS));

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
    wcex.hIcon          = LoadIcon(hInstance, MAKEINTRESOURCE(IDI_CIS023_S2018_LAB8CALLENMYERS));
    wcex.hCursor        = LoadCursor(nullptr, IDC_ARROW);
    wcex.hbrBackground  = (HBRUSH)(COLOR_WINDOW+1);
    wcex.lpszMenuName   = MAKEINTRESOURCEW(IDC_CIS023_S2018_LAB8CALLENMYERS);
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
		case BN_CLICKED:										// capture button click
			if (LOWORD(lParam) == (WORD)hWnd_btnFirst)
				Move(MOVE_FIRST);								// jump to first node
			if (LOWORD(lParam) == (WORD)hWnd_btnPrev)
				Move(MOVE_PREV);								// roll to previous node
			if (LOWORD(lParam) == (WORD)hWnd_btnNext)
				Move(MOVE_NEXT);								// roll to next node
			if (LOWORD(lParam) == (WORD)hWnd_btnLast)
				Move(MOVE_LAST);								// roll to last node
			if (LOWORD(lParam) == (WORD)hWnd_btnCopy)
				Copy();											// make a copy of the currentNode
			if (LOWORD(lParam) == (WORD)hWnd_btnCut)
				Cut();											// copy and delete the current node
			if (LOWORD(lParam) == (WORD)hWnd_btnPaste)
				Paste();										// insert the copied node
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

		hWnd_btnCopy = CreateWindow(TEXT("BUTTON"),
			TEXT("Copy"),
			WS_VISIBLE | WS_CHILD | BS_DEFPUSHBUTTON,
			50, 230, 70, 30, hWnd, NULL, NULL, NULL);

		hWnd_btnCut = CreateWindow(TEXT("BUTTON"),
			TEXT("Cut"),
			WS_VISIBLE | WS_CHILD | BS_DEFPUSHBUTTON,
			150, 230, 70, 30, hWnd, NULL, NULL, NULL);

		hWnd_btnPaste = CreateWindow(TEXT("BUTTON"),
			TEXT("Paste"),
			WS_VISIBLE | WS_CHILD | BS_DEFPUSHBUTTON,
			250, 230, 70, 30, hWnd, NULL, NULL, NULL);

		// load file into linked list
		LoadFile();
	}
	break;

	case WM_DESTROY:
	{
		//delete linked list
		if (lastNode != nullptr)
			lastNode->SetNext(nullptr);			//prevent endless loop

		NodeClass*tempNode = nullptr;			//for deleting
		currentNode = firstNode;				//start at first node
		while (currentNode != nullptr)			//loop until last node deleted
		{
			tempNode = currentNode->GetNext();	//get pointer to next node
			delete currentNode;					//delete currentnode
			currentNode = tempNode;				//advance to next node

		}
		if (copyNode != nullptr)				//if there is a node in the copy buffer
			delete copyNode;					//delete it



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
		fInput.open("CIS023_S2018_Lab8_Data.txt");		// open file

		if (!fInput)									// if file did not open
			throw 1;

		while (fInput.good())
		{

			fInput >> strLName							// Read the file
				>> strFName
				>> strCity
				>> strAge
				>> strLic;



			newNode = new NodeClass(					//create a new node
				strLName,								//and fill it with the file data
				strFName,
				strCity,
				strAge,
				strLic
			);					

			newNode->SetNext(newNode);				//initialize piinters
			newNode->SetPrev(newNode);				

			if (firstNode == nullptr)				//if this is the first node
				firstNode = newNode;				//then set first node
			else
			{
				lastNode->SetNext(newNode);			//the current last node points to this new node
				newNode->SetPrev(lastNode);			//new node is not at the end of the list
				newNode->SetNext(firstNode);		//new node's next point to the 1st node


			}
			lastNode = newNode;						//the new node is not the last node
			firstNode->SetPrev(lastNode);			//set rollaround for 1st node


		}

		fInput.close();									// ALWAYS remember to close the file

		currentNode = firstNode;						//set to first node
		Display(currentNode);							//display first node

		EnableWindow(hWnd_btnFirst, true);				// endable buttons
		EnableWindow(hWnd_btnPrev, true);
		EnableWindow(hWnd_btnNext, true);
		EnableWindow(hWnd_btnLast, true);
		EnableWindow(hWnd_btnCopy, true);
		EnableWindow(hWnd_btnCut, true);
		EnableWindow(hWnd_btnPaste, false);				// paste only enabled after copy or cut clicked

	}
	catch (int)
	{

		MessageBox(NULL,
			TEXT("Failed to load file"),
			TEXT("File Error"),
			MB_ICONERROR);

		EnableWindow(hWnd_btnFirst, false);				// disable buttons
		EnableWindow(hWnd_btnPrev, false);
		EnableWindow(hWnd_btnNext, false);
		EnableWindow(hWnd_btnLast, false);
		EnableWindow(hWnd_btnCopy, false);
		EnableWindow(hWnd_btnCut, false);
		EnableWindow(hWnd_btnPaste, false);

	}
}

// answer the VCR buttons (iDirection = MOVE_FIRST, MOVE_PREV, MOVE_NEXT, MOVE_LAST)
void Move(int iDirection)
{
	try
	{
		switch (iDirection)			//which direction to move
		{
		case MOVE_FIRST:			//<<
			currentNode = firstNode;
			break;

		case MOVE_PREV:				//<
			if (currentNode == nullptr)	//if this si the first time a button hgas been pressed
				currentNode = lastNode;	//then jump to the end of the list
			else
				currentNode = currentNode->GetPrev();	//move to the previous node
			break;


		case MOVE_NEXT:				//>
			if (currentNode == nullptr)	//if this si the first time a button hgas been pressed
				currentNode = firstNode;	//then jump to the beginning of the list
			else
				currentNode = currentNode->GetNext();	//move to the next node
			break;


		case MOVE_LAST:				//>>
			currentNode = lastNode;	//jump to the last node
			break;

		default:
			throw 1;				//empty node
			break;
		}
		if (currentNode == nullptr)
			throw 1;

		Display(currentNode);

	}
	catch(int)
	{
		Display(nullptr);			//empty window
		MessageBox(
			NULL,
			TEXT("Node is empty."),
			TEXT("List Error"),
			MB_ICONERROR
		);
	}

}

// make a copy of the currentNode for later insertion
void Copy()
{


	if (copyNode != nullptr)		//if there is already a copynode in the buffer
		delete copyNode;			//delete it
	if (currentNode == nullptr)		//dont copy if this is an empty lisit
		return;


	copyNode = new NodeClass;		//create a new node for the copy
	copyNode->Copy(currentNode);			//deep copy of current node

	EnableWindow(hWnd_btnPaste, true);		//have something to copy, enable paste button

}

// copy current node and then delete it from list
void Cut()
{
	Copy();							///makes a copy of the current node
	if (currentNode == nullptr)		//nothing to cut
		return;
	//save address of next node, it will become the new current node
	newNode = currentNode->GetNext();
	if (currentNode != newNode)		//if this is not the last node in the list
	{
		if (currentNode == firstNode)	//special case if deleting 1st node
			firstNode = newNode;		//next node will become first node
		if (currentNode == lastNode)		//spaecial case of deleting last node
			lastNode = currentNode->GetPrev();	//previous node will become last node
		//previous node connected to next node
		currentNode->GetPrev()->SetNext(currentNode->GetNext());
		//next node connected back to previous node
		currentNode->GetNext()->SetPrev(currentNode->GetPrev());
		delete currentNode;				//delete the node
		currentNode = newNode;				//new curent node is now the next node
		Display(currentNode);
	}
	else								//this is the last node in the list
	{
		delete currentNode;				//delete this node
		currentNode = nullptr;			//set to null so that display and delete work in the future
		firstNode = nullptr;
		lastNode = nullptr;				
		Display(nullptr);				//blank the output
				
	}
	EnableWindow(hWnd_btnPaste, true);		//we have a copyNode to paste



}

// insert copyNode into the linked list at this point
void Paste()
{
	newNode = new NodeClass();				//create new node
	newNode->Copy(copyNode);				//deep copy of copy node into new node

	newNode->SetPrev(newNode);				//initialize pointers
	newNode->SetNext(newNode);

	if (firstNode == nullptr)				//if the list is empty
	{
		firstNode = newNode;				//then store this new node as the first and last 
		lastNode = newNode;
	}
	else								//list is not empty
	{
		newNode->SetPrev(currentNode);				//new node points back to current node
		newNode->SetNext(currentNode->GetNext());	//new node points to current nodes next node
		currentNode->SetNext(newNode);				//currentNode points to new node
		newNode->GetNext()->SetPrev(newNode);		//next node points back to new node

		if (currentNode == lastNode)					//special case if inserting past the last node
			lastNode = newNode;							//this new node becomes the new last node
		
	}
	currentNode = newNode;								//set new node as the current node
	Display(currentNode);								//display the data

	EnableWindow(hWnd_btnFirst, true);				// endable buttons
	EnableWindow(hWnd_btnPrev, true);
	EnableWindow(hWnd_btnNext, true);
	EnableWindow(hWnd_btnLast, true);
	EnableWindow(hWnd_btnCopy, true);
	EnableWindow(hWnd_btnCut, true);
	EnableWindow(hWnd_btnPaste, false);

}

// display node values on main window
void Display(NodeClass* Node)
{
	if (Node != nullptr)					//this is not an empty node
	{
		//display data
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
	else									//this is an empty node
	{
		//clears window
		SetWindowText(
			hWnd_LName,
			NULL
		);
		SetWindowText(
			hWnd_FName,
			NULL
		);
		SetWindowText(
			hWnd_City,
			NULL
		);
		SetWindowText(
			hWnd_Age,
			NULL
		);
		SetWindowText(
			hWnd_License,
			NULL
		);

		EnableWindow(hWnd_btnFirst, false);				// disable buttons
		EnableWindow(hWnd_btnPrev, false);
		EnableWindow(hWnd_btnNext, false);
		EnableWindow(hWnd_btnLast, false);
		EnableWindow(hWnd_btnCopy, false);
		EnableWindow(hWnd_btnCut, false);
		EnableWindow(hWnd_btnPaste, false);
	}
}


