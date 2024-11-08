//Module:	LinearDiagram.h
//Project:	CIS021_S2019_Lab8b 
//Author:	Allen Myers
//Purpose:	Header file to LinearDiagram
//
#pragma once
class LinearDiagram
{
public:
	LinearDiagram();
	~LinearDiagram();
	LinearDiagram(HWND);							// overload constructor

	void Draw(HDC);									// draw the background and line
	void Size();									// answer WM_SIZE message
	void CalcLine();								// calculate the line

private:
	HWND hWnd;										// handle to main window

	struct DPOINT										// struct to hold (x,y);
	{
		double x;
		double y;
	};


	// formula input controls
	HWND hWnd_Gray_Box;									// box around controls
	HWND hWnd_lbl_Formula;								// label
	HWND hWnd_cbo_1stSign;								// combo, +/-
	HWND hWnd_txt_x2;									// edit box, input leading coefficient x squared
	HWND hWnd_lbl_x2;									// label, x 
	HWND hWnd_lbl_2;									// label, squared
	HWND hWnd_cbo_2ndSign;								// combo, +/-
	HWND hWnd_txt_x;									// edit box, input coefficient x
	HWND hWnd_lbl_x;									// label, x
	HWND hWnd_cbo_3rdSign;								// combo, +/-
	HWND hWnd_txt_Const;								// edit box, constant
	HWND hWnd_lbl_EquY;									// label, = y

														// polynomial terms
	int iLeadingCoefficient;							// signed leading coefficent (of x squared)
	double A;
	int iCoefficient;									// signed coefficent (of x)
	double B;
	int iConstant;										// signed constant
	double C;

	DPOINT YintPt[20];									// y intercepts
	DPOINT Vertex;										// vertex of parabola

	void GetTerms();									// capture user input
	void ShowIntercepts(HDC);							// display y intercepts on main window
};

