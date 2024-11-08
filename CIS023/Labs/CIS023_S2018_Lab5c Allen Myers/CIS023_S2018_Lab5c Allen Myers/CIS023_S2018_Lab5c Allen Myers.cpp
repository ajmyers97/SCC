//Module:	CIS023_S2018_Lab5c Allen Myers.cpp
//Project:	CIS023_S2018_Lab5c Allen Myers.cpp
//Author:	Allen Myers
//Date:		February 21st, 2018
//Puprose:	Work with a template class.
//			Review reading data from a text file.
//			Perform operations on a template class.
//			Learn how to convert algorithms into virtual functions.
//			Review listbox interaction.
#include "stdafx.h"
#include "CIS023_S2018_Lab5c Allen Myers.h"

#define MAX_LOADSTRING 100
#define SIZE_ARRAY 9999			//there are 9999 line in the file

// Global Variables:
HINSTANCE hInst;                                // current instance
WCHAR szTitle[MAX_LOADSTRING];                  // The title bar text
WCHAR szWindowClass[MAX_LOADSTRING];            // the main window class name

														
HWND hWnd_ListBox;								//Handle To list box
HWND hWnd_Largest;								//Handle To button
HWND hWnd_Search;								//Handle Tobutton
HWND hWnd_Largest_Out;							//Handle Toedit control
HWND hWnd_Input;								//Handle Toedit control
HWND hWnd_Found;								//Handle To static control

int NumberList[SIZE_ARRAY];					//array to hold file data


// Forward declarations of functions included in this code module:
ATOM                MyRegisterClass(HINSTANCE hInstance);
BOOL                InitInstance(HINSTANCE, int);
LRESULT CALLBACK    WndProc(HWND, UINT, WPARAM, LPARAM);
INT_PTR CALLBACK    About(HWND, UINT, WPARAM, LPARAM);

bool LoadFile();			//load numbers into listbox



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
    LoadStringW(hInstance, IDC_CIS023_S2018_LAB5CALLENMYERS, szWindowClass, MAX_LOADSTRING);
    MyRegisterClass(hInstance);

    // Perform application initialization:
    if (!InitInstance (hInstance, nCmdShow))
    {
        return FALSE;
    }

    HACCEL hAccelTable = LoadAccelerators(hInstance, MAKEINTRESOURCE(IDC_CIS023_S2018_LAB5CALLENMYERS));

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
    wcex.hIcon          = LoadIcon(hInstance, MAKEINTRESOURCE(IDI_CIS023_S2018_LAB5CALLENMYERS));
    wcex.hCursor        = LoadCursor(nullptr, IDC_ARROW);
    wcex.hbrBackground  = (HBRUSH)(COLOR_WINDOW+1);
    wcex.lpszMenuName   = MAKEINTRESOURCEW(IDC_CIS023_S2018_LAB5CALLENMYERS);
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
      CW_USEDEFAULT, 0, 400, 300, nullptr, nullptr, hInstance, nullptr);

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
			case BN_CLICKED:					//button clicked
				if (LOWORD(lParam) == (WORD)hWnd_Largest)//largest button
				{
					TCHAR szBuffer[100];		//converted integer for display
					int iLargest = 0;		//karges number found in array
					int iPosition;			//index of number found

					iPosition =				//where found
						Functions::Largest(//call virtual functions
							NumberList,		//array of numbers
							SIZE_ARRAY,		//size of the array
							iLargest		//largest number found, returned from fucntions
							);

					_itot_s(			//convert int to tchar
						iLargest,		//numebr to conver
						szBuffer,		//target buffer
						100,			//max chars
						10				//radix
					);
					SetWindowText(			//setwindow text
						hWnd_Largest_Out,	//handel to windows
						szBuffer);			//buffer

					ShowWindow(hWnd_Largest_Out, TRUE);	//display window

					SendMessage(			//send a message 
						hWnd_ListBox,		//handle to the list box
						LB_SETCURSEL,		//set the current selection
						iPosition,			//to the position returned from  largest
						NULL				//lparam not used
					);

				}
				if (LOWORD(lParam) == (WORD)hWnd_Search)//search button
				{
					TCHAR szBuffer[100];		//output buffer
					int iSearchValue = 0;		//user input
					int iPosition = -1;			//where in array the number was found

					GetWindowText(				//get user inputted values
						hWnd_Input,					//handle to input edit control
						szBuffer,					//destination buffer
						100						//max chars to get
						);

					iSearchValue = _tstoi(			//convert TCHAR to INT
						szBuffer
					);
					iPosition =						//where found
						Functions::Search(						//virtual function, search for member
							NumberList,				//array
							SIZE_ARRAY,				//size of array
							iSearchValue			//number to search for
						);
					SendMessage(					//set listbox current selection
						hWnd_ListBox,				//hanbdle to listbox
						LB_SETCURSEL,				//set selection
						iPosition,					//selection to set
						NULL						//LPARAM not used
					);

					if (iPosition == -1)			//value not found
						SendMessage(				//set the Found windows text
							hWnd_Found,				//handle to found window
							WM_SETTEXT,				//set text
							NULL,					//WPARAM not used
							(LPARAM)TEXT("Not Found")	///text to display
						);
					else
						SendMessage(				//set the Found windows text
							hWnd_Found,				//handle to found window
							WM_SETTEXT,				//set text
							NULL,					//WPARAM not used
							(LPARAM)TEXT("Found")	///text to display
						);
					ShowWindow(hWnd_Found, TRUE);	//show window
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
    case WM_DESTROY:
        PostQuitMessage(0);
        break;
	case WM_CREATE:
	{
		// grey background
		CreateWindow(TEXT("STATIC"), TEXT(""),
			WS_VISIBLE | WS_CHILD, 0, 0, 400, 300, hWnd, NULL, NULL, NULL);

		// create list box
		hWnd_ListBox = CreateWindow(
			TEXT("LISTBOX"),								// type of object
			TEXT(""),										// starts blank (filled later)
			WS_VISIBLE | WS_CHILD |							// attributes
			WS_VSCROLL | WS_BORDER,							// NOT SORTED!
			20, 50, 75, 175,								// location and size
			hWnd, NULL, NULL, NULL);						// parent window, the rest are not used here

															// buttons
		hWnd_Largest = CreateWindow(TEXT("BUTTON"),
			TEXT("Largest"),
			WS_VISIBLE | WS_CHILD | BS_DEFPUSHBUTTON,
			120, 50, 90, 30, hWnd, NULL, NULL, NULL);

		hWnd_Search = CreateWindow(TEXT("BUTTON"),
			TEXT("Search"),
			WS_VISIBLE | WS_CHILD | BS_DEFPUSHBUTTON,
			120, 100, 90, 30, hWnd, NULL, NULL, NULL);

		// labels
		CreateWindow(TEXT("STATIC"),
			TEXT("Numbers"),
			WS_VISIBLE | WS_CHILD,
			20, 20, 75, 30, hWnd, NULL, NULL, NULL);

		// output
		hWnd_Largest_Out = CreateWindow(TEXT("STATIC"),
			TEXT("(largest)"),
			!WS_VISIBLE | WS_CHILD,							// not visible
			250, 55, 60, 30, hWnd, NULL, NULL, NULL);

		// input
		hWnd_Input = CreateWindow(TEXT("EDIT"),
			TEXT(""),
			WS_CHILD | WS_VISIBLE | WS_BORDER | ES_AUTOHSCROLL | ES_NUMBER, // number only
			250, 105, 60, 20, hWnd, NULL, NULL, NULL);

		// result
		hWnd_Found = CreateWindow(TEXT("STATIC"),
			TEXT("Not Found"),
			!WS_VISIBLE | WS_CHILD,							// not visible
			250, 150, 100, 20, hWnd, NULL, NULL, NULL);

		LoadFile();


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
bool LoadFile()
{
	ifstream inFile;				//handle to file

	inFile.open(
		"CIS023_S2018_Lab5c_data.txt"
	);
	if (inFile.is_open())			//did the file open
	{
		string strFileIn;			//line fromt the file

		for (int i = 0;i < SIZE_ARRAY ;i++)		//loop through file
		{
			getline(inFile, strFileIn, '\n');	//read a line from the file

			NumberList[i] =						//convert string to integer
				atoi(strFileIn.c_str());		//store in array
		}


		inFile.close();				//close the file

		TCHAR szBuffer[100];					//buffer to hold converted integer
		for (int i = 0;i < SIZE_ARRAY;i++)		//loop throught the array
		{

			_itot_s(NumberList[i], szBuffer, 100, 10);		//convert integer to TCHAR

			SendMessage(						//add string to listbox
				hWnd_ListBox,					//handle of listbox
				LB_ADDSTRING,					//add string
				NULL, 							//WPARAM not used
				(LPARAM)szBuffer				//buffet to add to listbox
			);



		}


	}




	return false;					//did not load
}