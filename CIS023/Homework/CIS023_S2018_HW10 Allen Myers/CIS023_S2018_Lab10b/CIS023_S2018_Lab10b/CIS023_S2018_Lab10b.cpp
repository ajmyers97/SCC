//Module:	CIS023_S2018_HW10.cpp
//Project:	CIS023_S2018_HW10
//Author:	Allen Myers
//Date:		April 19th, 2018
//Purpose:	Review interfacing with a linked list.
//			Perform a bubble sort.
//

#include "stdafx.h"
#include "CIS023_S2018_Lab10b.h"

#define MAX_LOADSTRING 100

// Global Variables:
HINSTANCE hInst;                                // current instance
WCHAR szTitle[MAX_LOADSTRING];                  // The title bar text
WCHAR szWindowClass[MAX_LOADSTRING];            // the main window class name

char szFileName[] = "CIS023_S2018_HW10_Data.txt";			// file that contains data for linked list
HWND hWnd_BTN_Sort;							// Sort button
HWND hWnd_BTN_Close;						// Close button
HWND hWnd_Listbox;							// List box
HWND hWnd_STC_Start;						// start time static control
HWND hWnd_STC_End;							// end time static control
HWND hWnd_STC_Comps;						// # of comparisons static control


LinkedListClass*list;						//linked list object


// Forward declarations of functions included in this code module:
ATOM                MyRegisterClass(HINSTANCE hInstance);
BOOL                InitInstance(HINSTANCE, int);
LRESULT CALLBACK    WndProc(HWND, UINT, WPARAM, LPARAM);
INT_PTR CALLBACK    About(HWND, UINT, WPARAM, LPARAM);

void CreateMainWindowLayout(HWND);			// place controls on main window
BOOL LoadList();							// read input file and create linked list
void FillListBox();							// send linked list to listbox
//int InsertionSort();						// perform insertion sort
int bubbleSort();							// perform bubble sort
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
    LoadStringW(hInstance, IDC_CIS023_S2018_LAB10B, szWindowClass, MAX_LOADSTRING);
    MyRegisterClass(hInstance);

    // Perform application initialization:
    if (!InitInstance (hInstance, nCmdShow))
    {
        return FALSE;
    }

    HACCEL hAccelTable = LoadAccelerators(hInstance, MAKEINTRESOURCE(IDC_CIS023_S2018_LAB10B));

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
    wcex.hIcon          = LoadIcon(hInstance, MAKEINTRESOURCE(IDI_CIS023_S2018_LAB10B));
    wcex.hCursor        = LoadCursor(nullptr, IDC_ARROW);
    wcex.hbrBackground  = (HBRUSH)(COLOR_WINDOW+1);
    wcex.lpszMenuName   = MAKEINTRESOURCEW(IDC_CIS023_S2018_LAB10B);
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
		case BN_CLICKED:	// capture button click
			if (LOWORD(lParam) == (WORD)hWnd_BTN_Sort)
			{
				EnableWindow(hWnd_BTN_Sort, false);	// disable sort button during sort operation

				SYSTEMTIME sysTime;
				TCHAR szOutput[MAX_LOADSTRING];

				// get and display start time
				GetSystemTime(&sysTime);
				_stprintf_s(szOutput, TEXT("%d:%d.%d"), sysTime.wMinute, sysTime.wSecond, sysTime.wMilliseconds);
				SetWindowText(hWnd_STC_Start, szOutput);
				EnableWindow(hWnd_STC_Start, true); // Search start time static control

				//int iComps = InsertionSort();		// perform the sort operation
				int iComps = bubbleSort();			//perform the sort operation

				// get and display end time
				GetSystemTime(&sysTime);
				_stprintf_s(szOutput, TEXT("%d:%d.%d"), sysTime.wMinute, sysTime.wSecond, sysTime.wMilliseconds);
				SetWindowText(hWnd_STC_End, szOutput);
				EnableWindow(hWnd_STC_End, true);	// Search end time static control

				// message, how many comparisons in sort
				_stprintf_s(szOutput, TEXT("Number of comparisons:   %i"), iComps);
				SetWindowText(hWnd_STC_Comps, szOutput);
				EnableWindow(hWnd_STC_Comps, true);	// enable static control

				FillListBox();						// reload list box with soted list
				EnableWindow(hWnd_BTN_Sort, true);	// enable sort button

				break;
			}
			else if (LOWORD(lParam) == (WORD)hWnd_BTN_Close)
			{
				DestroyWindow(hWnd);
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
		CreateMainWindowLayout(hWnd);	// layout
		if (LoadList())					// automatically load the list when the program loads
		{
			FillListBox();				// load unordered list into list box
			EnableWindow(hWnd_BTN_Sort, true);	// enable sort button
		}
		break;

	case WM_DESTROY:

		if (list)						//destroy linekd list
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
	hWnd_BTN_Sort = CreateWindow(TEXT("BUTTON"), TEXT("Sort"),
		WS_VISIBLE | WS_CHILD | BS_DEFPUSHBUTTON,
		20, 70, 80, 30, hWnd, NULL, NULL, NULL);

	hWnd_BTN_Close = CreateWindow(TEXT("BUTTON"), TEXT("Close"),
		WS_VISIBLE | WS_CHILD | BS_DEFPUSHBUTTON,
		20, 120, 80, 30, hWnd, NULL, NULL, NULL);

	hWnd_Listbox = CreateWindow(TEXT("LISTBOX"), NULL,
		WS_VISIBLE | WS_CHILD | LBS_NOTIFY |
		WS_VSCROLL | WS_BORDER | LBS_HASSTRINGS,
		140, 50, 200, 200, hWnd, NULL, NULL, NULL);

	hWnd_STC_Start = CreateWindow(TEXT("STATIC"),
		TEXT("88:88.888"),
		WS_VISIBLE | WS_CHILD, 60, 200, 70, 20, hWnd, NULL, NULL, NULL);

	hWnd_STC_End = CreateWindow(TEXT("STATIC"),
		TEXT("88:88.888"),
		WS_VISIBLE | WS_CHILD, 60, 225, 70, 20, hWnd, NULL, NULL, NULL);

	hWnd_STC_Comps = CreateWindow(TEXT("STATIC"),
		TEXT(""),
		WS_VISIBLE | WS_CHILD, 20, 250, 300, 20, hWnd, NULL, NULL, NULL);

	// static text - labels
	CreateWindow(TEXT("STATIC"),
		TEXT("INSERTION SORT"),
		WS_VISIBLE | WS_CHILD, 100, 20, 260, 20, hWnd, NULL, NULL, NULL);

	CreateWindow(TEXT("STATIC"),
		TEXT("Start:"),
		WS_VISIBLE | WS_CHILD, 20, 200, 40, 20, hWnd, NULL, NULL, NULL);

	CreateWindow(TEXT("STATIC"),
		TEXT("End:"),
		WS_VISIBLE | WS_CHILD, 20, 225, 40, 20, hWnd, NULL, NULL, NULL);


	EnableWindow(hWnd_BTN_Sort, false);		// disable sort button
	EnableWindow(hWnd_STC_Start, false);	// disable start time
	EnableWindow(hWnd_STC_End, false);		// disable end time
	EnableWindow(hWnd_STC_Comps, false);	// disable # of inserts

}

// opens the file and loads the linked list
BOOL LoadList()
{
	ifstream inFile;						// file handle
	string strLine;							// a line in the file

	try
	{
		inFile.open(szFileName);			// open the file

		if (!inFile.is_open())
			throw 0;

		list = new LinkedListClass;			//create the list

		getline(inFile, strLine);
		while (inFile.good())				// if more to read
		{
			list->Append(strLine);			//append file with new nodes at end of list
			getline(inFile, strLine);		// get the next line from the file
		}

		inFile.close();						// close the file
	}
	catch (int)
	{
		MessageBox(NULL,					//error when nothing opens
			TEXT("Unable to load file."),
			TEXT("File Error!"),
			MB_ICONERROR);
		return false;
	}

	return true;
}

// fill list box
void FillListBox()
{
	NodeClass*tempNode;											//temp node creation
	string strData;												///data in string from node
	TCHAR szData[TCHAR_SIZE];									//data from node
	size_t pRetValue;											//for mbstowcs_s(to convert string to TCHAR)

	SendMessage(hWnd_Listbox, LB_RESETCONTENT, 0, 0);			//empty the listbox

	list->SetCurrentNode(list->GetFirstNode());					//set the frist list item to the first node
	tempNode = list->GetCurrentNode();							//get current node


	while (tempNode != nullptr)									//loop through entire list
	{
		strData = tempNode->GetString();						//get data from current node
		mbstowcs_s(												//convert string to TCHAR
			&pRetValue,											//return value
			szData,												//target tchar
			TCHAR_SIZE,											//size of target
			strData.c_str(),									//source string
			TCHAR_SIZE											//max num of chars to copy
		);

		SendMessage(hWnd_Listbox,								//add string to listbox
			LB_ADDSTRING,										//add string
			0,													//WPARAM not used
			LPARAM(szData)										//TCHAR to add
		);

		list->Next();											//advance to the next node
		tempNode = list->GetCurrentNode();						//get node

	}

}

//// Perform an Insertion Sort
//int InsertionSort()
//{
//	string strData;												//data from current node
//	int iNodeCount=0;											//count of nodes in list
//	int iCompareCount = 0;										//count number of nodes passed
//	NodeClass*tempNode;											//temp node to point to current node
//	bool bMove=false;													//if a move needs to happen
//	//count nodes
//	list->SetCurrentNode(list->GetFirstNode());					//start at the top of the list
//	while (list->GetCurrentNode() != list->GetLastNode())
//	{
//		list->Next();											//move to next node
//		iNodeCount++;											//count nodes
//
//	}
//	list->SetCurrentNode(list->GetFirstNode());					//start at the top of the list
//	list->Next();												//start at the second node
//	for (int i = 0;i < iNodeCount;i++)							//single pass through entire list
//	{
//		tempNode = list->GetCurrentNode();						//save address of current node
//		strData = list->GetCurrentNode()->GetString();			//get data from temp node
//		bMove = false;											//true if node needs to be moved
//		do														//run backward til either matc or
//		{														//top of list
//			iCompareCount++;									//count the number of comparisons
//
//			//special treatment for top of the list
//			if (list->GetCurrentNode() == list->GetFirstNode())
//				bMove = true;
//			else if (strData.compare(
//				list->GetCurrentNode()->GetPrevNode()->GetString()) == 1)
//				bMove == true;
//
//			if (bMove)
//			{
//
//				list->Insert(strData);							//insert data here
//				list->SetCurrentNode(tempNode);					//reset location
//				list->Delete();									//delete the node we just moved
//				tempNode = list->GetCurrentNode();				//resave the temo location
//				break;											//end of backward crawl loop
//			}
//
//
//
//			list->Previous();									//back up one node
//
//		} while (list->GetCurrentNode() != nullptr);
//
//	//	list->SetCurrentNode(list->GetFirstNode());				//done with sort, go back to top of loop
//	}//for loop
//	list->SetCurrentNode(list->GetFirstNode());				//done with sort, go back to top of loop
//
//
//	return iCompareCount;
//}

//perform bubble sort
int bubbleSort()
 {
 	int iNodeCount=0;											//count of nodes in list
 	int iCompareCount = 0;										//count number of nodes passed
 	NodeClass*tempNode;											//temp node to point to current node
 	//count nodes
 	list->SetCurrentNode(list->GetFirstNode());					//start at the top of the list
 	while (list->GetCurrentNode() != list->GetLastNode())
 	{
 		list->Next();											//move to next node
 		iNodeCount++;											//count nodes
  	}
 	list->SetCurrentNode(list->GetFirstNode());					//start at the top of the list
 	list->Next();												//start at the second node
	for (int iteration = 1; iteration < iNodeCount; iteration++)
	{
		for (int index = 0; index < iNodeCount - iteration; index++)
		{
			if ((list->GetCurrentNode())>(list->GetCurrentNode()->GetNextNode()))
			{
				tempNode = list->GetCurrentNode()->GetNextNode();
			}
			list->SetCurrentNode(list->GetFirstNode());				//done with sort, go back to top of loop

		}
	}

	return iCompareCount;
}//end bubblesort