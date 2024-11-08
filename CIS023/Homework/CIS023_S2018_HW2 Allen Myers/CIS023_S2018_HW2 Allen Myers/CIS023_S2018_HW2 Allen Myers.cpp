//Module: CIS023_S2018_HW2 Allen Myers.cpp
//Project: CIS023_S2018_HW2 Allen Myers
//Author: Allen Myers
//Date: January 25th, 2018
//Purpose: 	Review reading data from a file.
//			Review the use of arrays and structs.
//			Review the use of list boxes in Win32.

#include "stdafx.h"
#include "CIS023_S2018_HW2 Allen Myers.h"

#define MAX_LOADSTRING 100

// Global Variables:
HINSTANCE hInst;                                // current instance
WCHAR szTitle[MAX_LOADSTRING];                  // The title bar text
WCHAR szWindowClass[MAX_LOADSTRING];            // the main window class name

HWND hWnd_Load;									//load button
HWND hWnd_MaleName;								//list box for male names
HWND hWnd_MaleNumber;							//list box for male numbers
HWND hWnd_FemaleName;							//list box for female names
HWND hWnd_FemaleNumber;							//list box for female numbers

struct NameStruct								//defined structure
{
	string maleName;
	string maleNumber;
	string femaleName;
	string femaleNumber;

};
NameStruct Names[400];						//array of 100 structs for 100 names


// Forward declarations of functions included in this code module:
ATOM                MyRegisterClass(HINSTANCE hInstance);
BOOL                InitInstance(HINSTANCE, int);
LRESULT CALLBACK    WndProc(HWND, UINT, WPARAM, LPARAM);
INT_PTR CALLBACK    About(HWND, UINT, WPARAM, LPARAM);

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
    LoadStringW(hInstance, IDC_CIS023_S2018_HW2ALLENMYERS, szWindowClass, MAX_LOADSTRING);
    MyRegisterClass(hInstance);

    // Perform application initialization:
    if (!InitInstance (hInstance, nCmdShow))
    {
        return FALSE;
    }

    HACCEL hAccelTable = LoadAccelerators(hInstance, MAKEINTRESOURCE(IDC_CIS023_S2018_HW2ALLENMYERS));

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
    wcex.hIcon          = LoadIcon(hInstance, MAKEINTRESOURCE(IDI_CIS023_S2018_HW2ALLENMYERS));
    wcex.hCursor        = LoadCursor(nullptr, IDC_ARROW);
    wcex.hbrBackground  = (HBRUSH)(COLOR_WINDOW+1);
    wcex.lpszMenuName   = MAKEINTRESOURCEW(IDC_CIS023_S2018_HW2ALLENMYERS);
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
      CW_USEDEFAULT, 0, 750, 300, nullptr, nullptr, hInstance, nullptr);

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
			case BN_CLICKED:			//button clicked
				if (LOWORD(lParam) == (WORD)hWnd_Load)
				{
					fstream fInput;		//file handle
					string strLine;		//a line from the file
					string strLine2;
					string strLine3;
					string strLine4;

					string maleName;	//a line for male names
					string maleNumber;	//a line for the number of males with name
					string femaleName;	//a line for the male names
					string femaleNumber;//a line for the number of females with name

					TCHAR szOuput1[100]; //output string for male name
					TCHAR szOuput2[100]; //output string for male number
					TCHAR szOuput3[100]; //output string for female name
					TCHAR szOuput4[100]; //output string for female number

					fInput.open("CIS023_S2018_HW2_data.txt"); //open the file
					if (fInput.is_open())	//did the file open?
					{
						int iIndex = 0;			//file line number
				//getline(fInput, strLine);	//read the first line of the file
						while (fInput.good())		//if latest read got a line
						{
							for (iIndex = 0; iIndex < 400; iIndex++)
							{
								//load line from file into struct array
								getline(fInput, strLine);
								Names[iIndex].maleName = strLine;

								getline(fInput, strLine2);//read next line
								Names[iIndex].maleNumber = strLine2;
								getline(fInput, strLine3);
								Names[iIndex].femaleName = strLine3;
								getline(fInput, strLine4);
								Names[iIndex].femaleNumber = strLine4;
							}
						}

						fInput.close();		//close the file

											//load the list box from the array of the struct
						for (iIndex = 0; iIndex < 100; iIndex++)
						{
							size_t pRet;	//return value for mbstowcs_s

							mbstowcs_s(		//covert input string to TCHAR
								&pRet,
								szOuput1,	//output TCHAR
								100,		//size of output
								Names[iIndex].maleName.c_str(),	//source string
								100);			//max # of chars to copy
						//send text to list box
							SendMessage(	//send output string to listbox
								hWnd_MaleName,	//LISTBOX
								LB_ADDSTRING,	//APPEND STRING TO LIST
								NULL,			//PARAMETER NOT USED
								LPARAM(szOuput1));	//string
							mbstowcs_s(		//covert input string to TCHAR
								&pRet,
								szOuput2,	//output TCHAR
								100,		//size of output
								Names[iIndex].maleNumber.c_str(),	//source string
								100);			//max # of chars to copy
							SendMessage(
								hWnd_MaleNumber,
								LB_ADDSTRING,
								NULL,
								LPARAM(szOuput2));
							mbstowcs_s(		//covert input string to TCHAR
								&pRet,
								szOuput3,	//output TCHAR
								100,		//size of output
								Names[iIndex].femaleName.c_str(),	//source string
								100);			//max # of chars to copy
							SendMessage(	//send output string to listbox
								hWnd_FemaleName,	//LISTBOX
								LB_ADDSTRING,	//APPEND STRING TO LIST
								NULL,			//PARAMETER NOT USED
								LPARAM(szOuput3));	//string
							mbstowcs_s(		//covert input string to TCHAR
								&pRet,
								szOuput4,	//output TCHAR
								100,		//size of output
								Names[iIndex].femaleNumber.c_str(),	//source string
								100);			//max # of chars to copy
							SendMessage(
								hWnd_FemaleNumber,
								LB_ADDSTRING,
								NULL,
								LPARAM(szOuput4));
							
						}

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
		//CREATE THE LISTBOXES
		hWnd_MaleName = CreateWindow(
			TEXT("LISTBOX"),
			TEXT(""),
			WS_VISIBLE | WS_CHILD | WS_VSCROLL | WS_BORDER,
			20, 20, 150, 140,
			hWnd, NULL, NULL, NULL);

		hWnd_MaleNumber = CreateWindow(
			TEXT("LISTBOX"),
			TEXT(""),
			WS_VISIBLE | WS_CHILD | WS_VSCROLL | WS_BORDER,
			200, 20, 150, 140,
			hWnd, NULL, NULL, NULL);

		hWnd_FemaleName = CreateWindow(
			TEXT("LISTBOX"),
			TEXT(""),
			WS_VISIBLE | WS_CHILD | WS_VSCROLL | WS_BORDER,
			380, 20, 150, 140,
			hWnd, NULL, NULL, NULL);

		hWnd_FemaleNumber = CreateWindow(
			TEXT("LISTBOX"),
			TEXT(""),
			WS_VISIBLE | WS_CHILD | WS_VSCROLL | WS_BORDER,
			560, 20, 150, 140,
			hWnd, NULL, NULL, NULL);


		//create the button
		hWnd_Load = CreateWindow(
			TEXT("BUTTON"),
			TEXT("LOAD"),
			WS_VISIBLE | WS_CHILD | BS_DEFPUSHBUTTON,
			325, 180, 90, 30,
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
