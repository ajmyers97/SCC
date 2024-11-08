//Module:	GravitySim.cpp
//Project:	CIS021_S2019_Lab9b Allen Myers.cpp
//Author:	Allen Myers
//Date:		May 16th, 2019
//Purpose:	Implementation file for GravitySim.h
#include "stdafx.h"
#include "GravitySim.h"


GravitySim::GravitySim(HWND)
{
	//set location and size
	dDim.left = 0;
	dDim.top = 0;

	int size = GetRandomInt(10, 25);//size of graphic obejct

	dDim.right = size;
	dDim.bottom = size;

	//set speed
	dSpeed.x = GetRandomInt(1, 20);	//spit'em out(no vertical)
	dSpeed.y = GetRandomInt(0, 10);

	//set color
	r = GetRandomInt(0, 255);		//red
	g = GetRandomInt(0, 255);		//green
	b = GetRandomInt(0, 255);		//blue
}


GravitySim::~GravitySim()
{
}

void GravitySim::Draw(HDC hdc)
{
	//create brushes
	HBRUSH brush = CreateSolidBrush(RGB(r, g, b));
	HBRUSH oldBrush = (HBRUSH)SelectObject(hdc, brush);

	//copy dimension rectange into integer for drawing commands
	int lf = trunc(dDim.left);
	int tp = trunc(dDim.top);
	int rt = trunc(dDim.right);
	int bm = trunc(dDim.bottom);

	//draw an ellipse
	Ellipse(hdc, lf, tp, rt, bm);



	//release brushes
	SelectObject(hdc, oldBrush);
	DeleteObject(brush);

}

bool GravitySim::Move(HWND hWnd)
{

	//get window rect
	RECT rClient;
	GetClientRect(hWnd, &rClient);

	//check for finished movement
	if (dDim.left > rClient.right)				//past the right wall
		return false;

	//check for bounce
	if (dDim.top <= 0.0)						//if abve top
		dSpeed.y = abs(dSpeed.y);
	if (dDim.bottom >= rClient.bottom)				//bounce off the bottom
		dSpeed.y = abs(dSpeed.y)*-1.0;

	//gravity/friction calculations
	if (dSpeed.y < 0.0)							//if moving upwards
	{
		dSpeed.y += 0.1;
		dSpeed.y *= 0.9995;
	}
	if (dSpeed.y > 0.0)							//if moving down
	{
		dSpeed.y += 0.5;
		dSpeed.y *= 0.9995;
	}
	if (dSpeed.y > -0.5 && dSpeed.y<0.5)		//if at apogee
		dSpeed.y = 1.0;							//start it back down

	///friction
	dSpeed.x *= 0.9995;							//slow it down at horiz speed
	


	//move according to speed
	dDim.left += dSpeed.x;
	dDim.top += dSpeed.y;
	dDim.right += dSpeed.x;
	dDim.bottom += dSpeed.y;

	return false;
}

RECT GravitySim::GetInvalidateRect()
{
	return RECT();
}

int GravitySim::GetRandomInt(int iMin, int iMax)
{
	random_device rd;
	mt19937 gen(rd());
	uniform_int_distribution<>dist(iMin, iMax);
	return dist(gen);
}
