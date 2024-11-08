//Project:	CIS021_S2019_HW8 Allen Myers
//Module:	CIS021_S2019_HW8 Allen Myers.cpp
//Author:	Allen Myers
//Date:		May 11th, 2019
//Purpose:	Review reading a comma - delimited file.
//			Create a list using vectors.
//			Perform a complex sort on a list.
//			Write data to a comma - limited file.
//
#include "stdafx.h"
#include "CIS021_S2019_HW8 Allen Myers.h"

#define MAX_LOADSTRING 100

// Global Variables:
HINSTANCE hInst;                                // current instance
WCHAR szTitle[MAX_LOADSTRING];                  // The title bar text
WCHAR szWindowClass[MAX_LOADSTRING];            // the main window class name

HWND hWnd_Load;									// handle to load button
HWND hWnd_List;									// handle to list button
HWND hWnd_Sort;									// handle to search button
HWND hWnd_Empty;								// handle to empty button

HWND hWnd_Listbox;								// handle to listbox

HWND hWnd_LoadLabel;							// handle to label to show status of file load
HWND hWnd_ListLabel;							// handle to label to show status of listbox load
HWND hWnd_SortLabel;							// handle to label to show status of search
HWND hWnd_EmptyLabel;							// handle to leable to show status of empty list

vector<NodeClass>vNode;							//vector of type NodeClass



												// Forward declarations of functions included in this code module:
ATOM                MyRegisterClass(HINSTANCE hInstance);
BOOL                InitInstance(HINSTANCE, int);
LRESULT CALLBACK    WndProc(HWND, UINT, WPARAM, LPARAM);
INT_PTR CALLBACK    About(HWND, UINT, WPARAM, LPARAM);

bool LoadFile();								// load data file into list
void LoadListbox();								// load data from vector to listbox
bool Sort();									// sort the list
void Clear();									// empty vector list and listbox

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
	LoadStringW(hInstance, IDC_CIS021_S2019_HW8ALLENMYERS, szWindowClass, MAX_LOADSTRING);
	MyRegisterClass(hInstance);

	// Perform application initialization:
	if (!InitInstance(hInstance, nCmdShow))
	{
		return FALSE;
	}

	HACCEL hAccelTable = LoadAccelerators(hInstance, MAKEINTRESOURCE(IDC_CIS021_S2019_HW8ALLENMYERS));

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

	return (int)msg.wParam;
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

	wcex.style = CS_HREDRAW | CS_VREDRAW;
	wcex.lpfnWndProc = WndProc;
	wcex.cbClsExtra = 0;
	wcex.cbWndExtra = 0;
	wcex.hInstance = hInstance;
	wcex.hIcon = LoadIcon(hInstance, MAKEINTRESOURCE(IDC_CIS021_S2019_HW8ALLENMYERS));
	wcex.hCursor = LoadCursor(nullptr, IDC_ARROW);
	wcex.hbrBackground = (HBRUSH)(COLOR_WINDOW + 0);
	wcex.lpszMenuName = MAKEINTRESOURCEW(IDC_CIS021_S2019_HW8ALLENMYERS);
	wcex.lpszClassName = szWindowClass;
	wcex.hIconSm = LoadIcon(wcex.hInstance, MAKEINTRESOURCE(IDI_SMALL));

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
		CW_USEDEFAULT, 0, 500, 300, nullptr, nullptr, hInstance, nullptr);

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
		case BN_CLICKED:
			if (LOWORD(lParam) == (WORD)hWnd_Load)
			{
				if (LoadFile())
				{
					EnableWindow(hWnd_Load, false);						// disable load button
					EnableWindow(hWnd_List, true);						// enable list button
					EnableWindow(hWnd_Empty, true);						// enable empty button

																		// set status'
					SetWindowText(hWnd_LoadLabel, TEXT("File loaded"));
					SetWindowText(hWnd_ListLabel, TEXT("Ready"));
					SetWindowText(hWnd_EmptyLabel, TEXT("List loaded"));

					// set focus
					SetFocus(hWnd_List);
				}
				else
					SetWindowText(hWnd_LoadLabel, TEXT("File not found"));// set status

			}
			if (LOWORD(lParam) == (WORD)hWnd_List)
			{
				// load the list box from the list
				LoadListbox();

				EnableWindow(hWnd_List, false);					// disable list button
				EnableWindow(hWnd_Sort, true);					// enable search button

				SetWindowText(hWnd_ListLabel, TEXT("Loaded"));		// set status
			}
			if (LOWORD(lParam) == (WORD)hWnd_Sort)
			{
				//sort the loaded listbox
				Sort();
				SetWindowText(hWnd_SortLabel, TEXT("Sorted"));			// set status
				//ExportOutFile();
			}
			if (LOWORD(lParam) == (WORD)hWnd_Empty)
			{
				// empty the list and the listbox
				Clear();

				EnableWindow(hWnd_Load, true);						// enable load button
				EnableWindow(hWnd_List, false);						// disable list button
				EnableWindow(hWnd_Sort, false);						// disable sort button
				EnableWindow(hWnd_Empty, false);					// disable empty button

																	// set status texts
				SetWindowText(hWnd_LoadLabel, TEXT("File not loaded"));
				SetWindowText(hWnd_ListLabel, TEXT(""));
				SetWindowText(hWnd_SortLabel, TEXT(""));
				SetWindowText(hWnd_EmptyLabel, TEXT("List empty"));

				// set focus to 1st button
				SetFocus(hWnd_Load);

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

		// create labels
		hWnd_LoadLabel = CreateWindow(TEXT("STATIC"),
			TEXT("File not loaded"),
			WS_VISIBLE | WS_CHILD,
			100, 30, 150, 20, hWnd, NULL, NULL, NULL);

		hWnd_ListLabel = CreateWindow(TEXT("STATIC"),
			TEXT(""),
			WS_VISIBLE | WS_CHILD,
			100, 70, 150, 20, hWnd, NULL, NULL, NULL);

		hWnd_SortLabel = CreateWindow(TEXT("STATIC"),
			TEXT(""),
			WS_VISIBLE | WS_CHILD,
			100, 110, 150, 20, hWnd, NULL, NULL, NULL);

		hWnd_EmptyLabel = CreateWindow(TEXT("STATIC"),
			TEXT(""),
			WS_VISIBLE | WS_CHILD,
			100, 180, 150, 20, hWnd, NULL, NULL, NULL);


		// create buttons
		hWnd_Load = CreateWindow(TEXT("BUTTON"),
			TEXT("Load"),
			WS_VISIBLE | WS_CHILD | BS_DEFPUSHBUTTON,
			20, 20, 70, 30, hWnd, NULL, NULL, NULL);

		hWnd_List = CreateWindow(TEXT("BUTTON"),
			TEXT("Listbox"),
			WS_VISIBLE | WS_CHILD | BS_DEFPUSHBUTTON,
			20, 60, 70, 30, hWnd, NULL, NULL, NULL);

		hWnd_Sort = CreateWindow(TEXT("BUTTON"),
			TEXT("Sort"),
			WS_VISIBLE | WS_CHILD | BS_DEFPUSHBUTTON,
			20, 100, 70, 30, hWnd, NULL, NULL, NULL);

		hWnd_Empty = CreateWindow(TEXT("BUTTON"),
			TEXT("Empty"),
			WS_VISIBLE | WS_CHILD | BS_DEFPUSHBUTTON,
			20, 170, 70, 30, hWnd, NULL, NULL, NULL);

		// create listbox
		hWnd_Listbox = CreateWindow(TEXT("LISTBOX"), NULL,
			WS_VISIBLE | WS_CHILD | LBS_NOTIFY |
			WS_VSCROLL | WS_BORDER | LBS_HASSTRINGS,
			250, 20, 205, 200, hWnd, NULL, NULL, NULL);



		// disable buttons
		EnableWindow(hWnd_List, false);
		EnableWindow(hWnd_Sort, false);
		EnableWindow(hWnd_Empty, false);

		// set focus to 1st button
		SetFocus(hWnd_Load);

		break;

	case WM_DESTROY:

		//empty vector
		vNode.clear();

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
//load data file into vector "list"
bool LoadFile()
{
	ifstream fInput;			//file handle
	string strFileName =			//filespec
		"CIS021_S2019_HW8_data.csv";
	string strLName = "";			//temps to hold file data
	string strFName = "";			//
	string strCity = "";			//
	string strState = "";			//
	string strPhoneNumber = "";		//
	fInput.open(strFileName);		//open the file

	if (fInput.is_open())			//did file open?
	{
		//		for (int i = 0;i < 5;i++)
		while (fInput.good())
		{
			//read data from file
			getline(fInput, strLName, ',');
			getline(fInput, strFName, ',');
			getline(fInput, strCity, ',');
			getline(fInput, strState, ',');
			getline(fInput, strPhoneNumber, '\n');

			//create new node
			NodeClass newNode(strLName, strFName, strCity, strState, strPhoneNumber);

			//append node to the end of the list
			vNode.push_back(newNode);

		}


		fInput.close();				//close the file
		return true;				//file loaded okay
	}
	else							//error message
		MessageBox(NULL,
			TEXT("File not found!"),
			TEXT("File Error"),
			MB_ICONERROR);
	return false;
}
//export data to CSV file
bool ExportOutFile(string strLName,string strFName,string strCity,string strState,string strPhoneNumber)
{
	//ofstream fOutput;
	//string strFileName =			//filespec
	//	"out.csv";

	//fOutput.open(strFileName);		//open the file

	//if (fOutput.is_open())			//did file open?
	//{
	//	//output the data here

	//	fOutput.close();			//close the file
	//	return true;				//file loaded okay
	//}
	//else							//error message
	//	MessageBox(NULL,
	//		TEXT("File not found!"),
	//		TEXT("File Error"),
	//		MB_ICONERROR);
	return false;
}


//load the listbox from the vector "list"
void LoadListbox()
{
	//roll trough list
	for (auto& v : vNode)
	{
		SendMessage(hWnd_Listbox,					//send to listbox
			LB_ADDSTRING,							//add a string
			0,										//WPARAM is not used
			LPARAM(v.GetszName()));					//get combined name from object
	}


}
//sort the data by first and last name

bool Sort()
{
	return false;
}

void Clear()
{
	//clear vector "list"
	vNode.clear();

	//empty listbox
	SendMessage(hWnd_Listbox,		//message to listbox
		LB_RESETCONTENT,			//clear
		0, 0);						//wParam and lParam not used
}
