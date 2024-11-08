//Module:	CIS023_S2018_Lab6d Allen Myers.cpp
//Project:	CIS023_S2018_Lab6d Allen Myers
//Author:	Allen Myers
//Date:		March 7th 2018
//Purpose:	Learn how to code a template module.
//			Code template functions.
//			Learn how to call template functions, passing and returning values.
//

#include "stdafx.h"
#include "CIS023_S2018_Lab6d Allen Myers.h"

#define MAX_LOADSTRING 100
#define TCHAR_SIZE 128							//size of TCHAR arrays

// Global Variables:
HINSTANCE hInst;                                // current instance
WCHAR szTitle[MAX_LOADSTRING];                  // The title bar text
WCHAR szWindowClass[MAX_LOADSTRING];            // the main window class name

HWND hWnd_Input_Num_1;							//user input 1
HWND hWnd_Input_Num_2;							//user input 2
HWND hWnd_LT;									//  < static display
HWND hWnd_EQ;									//	= static desplay
HWND hWnd_GT;									//	> static display

HWND hWnd_Output_1;								//output static control
HWND hWnd_Output_2;								//output static control
HWND hWnd_Output_3;								//output static control
HWND hWnd_Output_4;								//output static control

// Forward declarations of functions included in this code module:
ATOM                MyRegisterClass(HINSTANCE hInstance);
BOOL                InitInstance(HINSTANCE, int);
LRESULT CALLBACK    WndProc(HWND, UINT, WPARAM, LPARAM);
INT_PTR CALLBACK    About(HWND, UINT, WPARAM, LPARAM);

void PerformConversions();						//calls templates
int iConvert(TCHAR*);							//convert TCHAR to int, standard function


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
    LoadStringW(hInstance, IDC_CIS023_S2018_LAB6DALLENMYERS, szWindowClass, MAX_LOADSTRING);
    MyRegisterClass(hInstance);

    // Perform application initialization:
    if (!InitInstance (hInstance, nCmdShow))
    {
        return FALSE;
    }

    HACCEL hAccelTable = LoadAccelerators(hInstance, MAKEINTRESOURCE(IDC_CIS023_S2018_LAB6DALLENMYERS));

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
    wcex.hIcon          = LoadIcon(hInstance, MAKEINTRESOURCE(IDI_CIS023_S2018_LAB6DALLENMYERS));
    wcex.hCursor        = LoadCursor(nullptr, IDC_ARROW);
    wcex.hbrBackground  = (HBRUSH)(COLOR_WINDOW+1);
    wcex.lpszMenuName   = MAKEINTRESOURCEW(IDC_CIS023_S2018_LAB6DALLENMYERS);
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
      CW_USEDEFAULT, 0, 300, 250, nullptr, nullptr, hInstance, nullptr);

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
		if (HIWORD(wParam) == EN_CHANGE)						//is hiword edit change?
			if ((LOWORD(lParam) == (WORD)hWnd_Input_Num_1) ||	//is input 1
				(LOWORD(lParam) == (WORD)hWnd_Input_Num_2))		//is input 2
			{
				PerformConversions();							//interact with template
			}

            int wmId = LOWORD(wParam);
            // Parse the menu selections:
            switch (wmId)
            {
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
			//grey background

			CreateWindow(TEXT("STATIC"), TEXT(""),
				WS_VISIBLE | WS_CHILD,
				0, 0, 300, 200,
				hWnd, NULL, NULL, NULL);
			CreateWindow(
				TEXT("STATIC"),
				TEXT("1ST INTEGER"),
				WS_VISIBLE | WS_CHILD,
				10, 15, 100, 20,
				hWnd, NULL, NULL, NULL);
			CreateWindow(
				TEXT("STATIC"),
				TEXT("2ND INTEGER"),
				WS_VISIBLE | WS_CHILD,
				160, 15, 100, 20,
				hWnd, NULL, NULL, NULL);
			hWnd_LT = CreateWindow(
				TEXT("STATIC"),
				TEXT("<"),
				!WS_VISIBLE | WS_CHILD,
				110, 55, 10, 20,
				hWnd, NULL, NULL, NULL);
			hWnd_GT = CreateWindow(
				TEXT("STATIC"),
				TEXT(">"),
				!WS_VISIBLE | WS_CHILD,
				110, 55, 10, 20,
				hWnd, NULL, NULL, NULL);
			hWnd_EQ = CreateWindow(
				TEXT("STATIC"),
				TEXT("="),
				WS_VISIBLE | WS_CHILD,
				110, 55, 10, 20,
				hWnd, NULL, NULL, NULL);
			hWnd_Input_Num_1 = CreateWindow(
				TEXT("EDIT"),
				TEXT(""),
				WS_CHILD | WS_VISIBLE | WS_BORDER | ES_AUTOHSCROLL | ES_NUMBER,
				10, 55, 60, 20,
				hWnd, NULL, NULL, NULL);
			hWnd_Input_Num_2 = CreateWindow(
				TEXT("EDIT"),
				TEXT(""),
				WS_CHILD | WS_VISIBLE | WS_BORDER | ES_AUTOHSCROLL | ES_NUMBER,
				160, 55, 60, 20,
				hWnd, NULL, NULL, NULL);
			hWnd_Output_1 = CreateWindow(				//output static control
				TEXT("STATIC"),
				TEXT(""),
				WS_VISIBLE| WS_CHILD|WS_BORDER,
				10,100,60,20,
				hWnd, NULL, NULL, NULL);
			hWnd_Output_2 = CreateWindow(				//output static control
				TEXT("STATIC"),
				TEXT(""),
				WS_VISIBLE | WS_CHILD | WS_BORDER,
				160, 100, 60, 20,
				hWnd, NULL, NULL, NULL);
			hWnd_Output_3 = CreateWindow(				//output static control
				TEXT("STATIC"),
				TEXT(""),
				WS_VISIBLE | WS_CHILD | WS_BORDER,
				10, 145, 60, 20,
				hWnd, NULL, NULL, NULL);
			hWnd_Output_4 = CreateWindow(				//output static control
				TEXT("STATIC"),
				TEXT(""),
				WS_VISIBLE | WS_CHILD | WS_BORDER,
				160, 145, 60, 20,
				hWnd, NULL, NULL, NULL);


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
//convert TCHAr to int, standard function
int iConvert(TCHAR*szIn)
{
	int iReturn = 0;							//return value

	if (lstrlen(szIn) != 0)
	{
		wstring temp(szIn);						//conver TCHAr to stream
		string str(temp.begin(), temp.end());	//convert stream to string
		iReturn = stoi(str, NULL, 10);			//convert string to int, base of 10

	}
	
	return iReturn;								//return the converted inteegr
}
//calls templates
void PerformConversions()
{
	TCHAR szInput1[TCHAR_SIZE];				//user input left
	TCHAR szInput2[TCHAR_SIZE];				//user input right
	int iInput1, iInput2;					//user inputs converted to integers.
	TCHAR szOutput_1[TCHAR_SIZE];			//output strings
	TCHAR szOutput_2[TCHAR_SIZE];			//output strings


	//get user input values
	GetWindowText(							//get user input
		hWnd_Input_Num_1,					//from 1st edit control box
		szInput1,							//place into 1st TCHAR
		TCHAR_SIZE							//size of TCHAR array
	);
	GetWindowText(							//get user input
		hWnd_Input_Num_2,					//from 2nd edit control box
		szInput2,							//place into 2nd TCHAR
		TCHAR_SIZE							//size of TCHAR array
	);

	////convert user input to integers
	//iInput1 = iConvert(szInput1);			//convert 1st user input to an integer
	//iInput2 = iConvert(szInput2);			//convert 2nd user input to an integer
	
	/////////
	//using templates
	iInput1 = TCHARtoInt(szInput1,10);		//template, convert TCHAR to int, base 10
	iInput2 = TCHARtoInt(szInput2, 10);		//template, convert TCHAR to int, base 10



	//hide all three compare statics
	ShowWindow(hWnd_LT,FALSE);					//hide the < output
	ShowWindow(hWnd_GT,FALSE);					//hide the > output
	ShowWindow(hWnd_EQ,FALSE);					//hide the = output


	//standard < = > comparisons 
	//if(iInput1<iInput2)
	//	ShowWindow(hWnd_LT, TRUE);

	//else if (iInput1==iInput2)
	//	ShowWindow(hWnd_EQ, TRUE);

	//else ShowWindow(hWnd_GT, TRUE);

	/////////////////////////////
	//using templates comparisons
	int iCompare = CompareSize(iInput1, iInput2);		//templatem return -1,0,1
	switch (iCompare)
	{
	case -1: ShowWindow(hWnd_LT, TRUE);					//<
		break;
	case 0: ShowWindow(hWnd_EQ, TRUE);					//=
		break;		
	case 1: ShowWindow(hWnd_GT, TRUE);					//>
		break;
	default:											//nothing shows
		break;


	}
	/////////////////////////////////////////////////////////////////
	//RE-DISPLAY THE INPUT INTO THE OUTPUT, FROM THE CONVERTED NUMBERS
	memset(szOutput_1, 0, sizeof(szOutput_1));		//clear output strings
	memset(szOutput_2, 0, sizeof(szOutput_2));		//clear output strings

	IntToTCHAR(iInput1, szOutput_1);					//convert integer to TCHAR
	IntToTCHAR(iInput2, szOutput_2);					

	SetWindowText(									//text to static control
		hWnd_Output_1,								//handle of control
		szOutput_1									//text
	);
	SetWindowText(									//text to static control
		hWnd_Output_2,								//handle of control
		szOutput_2									//text
	);

}

