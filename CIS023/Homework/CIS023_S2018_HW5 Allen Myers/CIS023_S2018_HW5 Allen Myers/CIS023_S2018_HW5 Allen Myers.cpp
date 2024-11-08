//Module:	CIS023_S2018_HW5 Allen Myers.cpp
//Project:	CIS023_S2018_HW5 Allen Myers
//Author:	Allen Myers
//Date:		February 24th, 2018
//Purpose:	Load and use data in an array of objects
//			Use a virtual function
//			Review Menu Operation
//
//

#include "stdafx.h"
#include "CIS023_S2018_HW5 Allen Myers.h"

#define MAX_LOADSTRING 100
#define SIZE_ARRAY 9


// Global Variables:
HINSTANCE hInst;                                // current instance
WCHAR szTitle[MAX_LOADSTRING];                  // The title bar text
WCHAR szWindowClass[MAX_LOADSTRING];            // the main window class name

HWND hWnd_ListBox;								//handle to list box

int NumberList[SIZE_ARRAY];						//array to hold vehicle data

VehicleClass*VehicleObject[SIZE_ARRAY];					//array the vehicles


// Forward declarations of functions included in this code module:
ATOM                MyRegisterClass(HINSTANCE hInstance);
BOOL                InitInstance(HINSTANCE, int);
LRESULT CALLBACK    WndProc(HWND, UINT, WPARAM, LPARAM);
INT_PTR CALLBACK    About(HWND, UINT, WPARAM, LPARAM);

bool LoadFile();			//loads the file into object
void LoadListBox();			//load listbox with file contents

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
    LoadStringW(hInstance, IDC_CIS023_S2018_HW5ALLENMYERS, szWindowClass, MAX_LOADSTRING);
    MyRegisterClass(hInstance);

    // Perform application initialization:
    if (!InitInstance (hInstance, nCmdShow))
    {
        return FALSE;
    }

    HACCEL hAccelTable = LoadAccelerators(hInstance, MAKEINTRESOURCE(IDC_CIS023_S2018_HW5ALLENMYERS));

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
    wcex.hIcon          = LoadIcon(hInstance, MAKEINTRESOURCE(IDI_CIS023_S2018_HW5ALLENMYERS));
    wcex.hCursor        = LoadCursor(nullptr, IDC_ARROW);
    wcex.hbrBackground  = (HBRUSH)(COLOR_WINDOW+1);
    wcex.lpszMenuName   = MAKEINTRESOURCEW(IDC_CIS023_S2018_HW5ALLENMYERS);
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
      CW_USEDEFAULT, 0, 665, 289, nullptr, nullptr, hInstance, nullptr);

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
			case ID_FILE_LOAD:
			{
				if (!VehicleObject[0])				//dont load more than once
					if (LoadFile())				//if the file loaded into objects okay
						LoadListBox();


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
			WS_VISIBLE | WS_CHILD, 0, 0, 650, 230, hWnd, NULL, NULL, NULL);

		//create list box
		hWnd_ListBox = CreateWindow(
			TEXT("LISTBOX"),				//type of object
			TEXT(""),					//starts blank
			WS_VISIBLE | WS_CHILD |		//attributes(Shows,goes with window,vertical scroll bar, and has a border)
			WS_VSCROLL | WS_BORDER |
			LBS_SORT,					//sorted list box
			20, 50, 600, 175,				//location and size
			hWnd, NULL, NULL, NULL		//parent window, the rest are not used here
		);

		//set listbox font to fixed wdith
		HFONT hFont = (HFONT)GetStockObject(OEM_FIXED_FONT);		//gets the font
		SendMessage(hWnd_ListBox, WM_SETFONT, WPARAM(hFont), NULL);	//sets the font


																	//labels
		CreateWindow(TEXT("STATIC"),
			TEXT("Name"),
			WS_VISIBLE | WS_CHILD,
			20, 20, 50, 30, hWnd, NULL, NULL, NULL
		);
		CreateWindow(TEXT("STATIC"),
			TEXT("Engine Type"),
			WS_VISIBLE | WS_CHILD,
			215, 20, 50, 30, hWnd, NULL, NULL, NULL
		);
		CreateWindow(TEXT("STATIC"),
			TEXT("Style"),
			WS_VISIBLE | WS_CHILD,
			310, 20, 60, 30, hWnd, NULL, NULL, NULL
		);
		CreateWindow(TEXT("STATIC"),
			TEXT("Occupant Limit"),
			WS_VISIBLE | WS_CHILD,
			415, 20, 60, 30, hWnd, NULL, NULL, NULL
		);
		CreateWindow(TEXT("STATIC"),
			TEXT("Tax"),
			WS_VISIBLE | WS_CHILD,
			520, 20, 50, 30, hWnd, NULL, NULL, NULL
		);

	}

		break;
    case WM_DESTROY:
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

bool LoadFile()
{
	ifstream	inFile;								//HANDLE TO TEXT FILE
	inFile.open("CIS023_S2018_HW5_DATA.TXT");		//OPEN THE FILE


	if (inFile.is_open())							//if the file opened
	{


		string strName;								//hold file data
		string strEngine;
		string strStyle;
		string strOccupants;

		for (int i = 0; i < SIZE_ARRAY; i++)						//read 12 lines from file
		{
			getline(inFile, strName, ',');				//read name
			getline(inFile, strEngine, ',');				//read cover
			getline(inFile, strStyle, ',');			//read category
			getline(inFile, strOccupants, '\n');			//read genres


			VehicleObject[i] = new VehicleClass;				//create an object int he array

			VehicleObject[i]->SetName(strName);			//store the name
			VehicleObject[i]->SetEngine(strEngine);			//store the cover
			VehicleObject[i]->SetStyle(strStyle);	//store the category
			VehicleObject[i]->SetOccupants(strOccupants);		//store the genre

		}

		inFile.close();								//close the file
		return true;								//good file
	}
	return false;
}
void LoadListBox()
{
	TCHAR szOutput[1000];					//string into listbox
	string strOutput;						//build string, convert it to szOutput
	size_t pRet;							//return value for mbstowcs_s()

	for (int i = 0; i < SIZE_ARRAY; i++)					//9 objects and looping
	{
		strOutput = VehicleObject[i]->GetName();	//get the names of the books

		strOutput.insert(				//insert spaces for column alighnemtn
			strOutput.length(),			//to the output string
			24 - strOutput.length(),		//length of the book name
			' ');						//char to enter a space

		strOutput += VehicleObject[i]->GetEngine();	//get the engine type

		strOutput.insert(				//insert spaces for column alighnemtn
			strOutput.length(),			//to the output string
			12 - VehicleObject[i]->GetEngine().length(),		//length of the book name
			' ');						//char to enter a space

		strOutput += VehicleObject[i]->GetStyle();	//get the categor of the books

		strOutput.insert(				//insert spaces for column alighnemtn
			strOutput.length(),			//to the output string
			13 - VehicleObject[i]->GetStyle().length(),		//length of the book name
			' ');						//char to enter a space

		strOutput += VehicleObject[i]->GetOccupants();	//get the genres of the books

		strOutput.insert(				//insert spaces for column alighnemtn
			strOutput.length(),			//to the output string
			13 - VehicleObject[i]->GetOccupants().length(),		//length of the book name
			' ');						//char to enter a space
		strOutput += VehicleObject[i]->GetVehicleTax();	//get the genres of the books



		mbstowcs_s(								//convert string to TCHAR
			&pRet,								//return code
			szOutput,							//destination TCHAR
			1000,								//size of TCHAR
			strOutput.c_str(),					//source string
			1000);								//max # of chars

		SendMessage(							//add TCHAR to listbox
			hWnd_ListBox,						//handle to listbox
			LB_ADDSTRING,						//add strign command
			NULL,								//wParam not used
			LPARAM(szOutput));					//TCHAR to add
	}
}