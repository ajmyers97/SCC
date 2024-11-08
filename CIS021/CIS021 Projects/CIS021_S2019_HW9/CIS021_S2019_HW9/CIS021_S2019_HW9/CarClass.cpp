//Module:	CarClass.cpp
//Project:	CIS021_S2019_HW9
//Author:	Allen Myers
//Date:		May 18th, 2019
//Purpose:	Implementation file for CarClass.h
//			controls the cars

#include "stdafx.h"
#include "CarClass.h"



CarClass::CarClass()
{

	// car size (depends on direction car is facing)
	rDim.left = 10;
	rDim.right = rDim.left + 20;
	rDim.top = 10;
	rDim.bottom = rDim.top + 50;

	// pick a color
	r = GetRandomInt(0, 255);						// red
	g = GetRandomInt(0, 255);						// green
	b = GetRandomInt(0, 255);						// blue


}


CarClass::~CarClass()
{
}

void CarClass::Draw(HDC hdc)
{
	HBRUSH brush = CreateSolidBrush(RGB(r, g, b));
	HBRUSH oldBrush = (HBRUSH)SelectObject(hdc, brush);

	// draw the car
	FillRect(hdc, &rDim, brush);

	SelectObject(hdc, oldBrush);
	DeleteObject(brush);

}

void CarClass::Move()
{
	//move the car ahead one space per second
	//do not cause a collision
}


int CarClass::GetRandomInt(int iMin, int iMax)
{
	random_device rd;								// non-deterministic generator
	mt19937 gen(rd());								// to seed mersenne twister.
	uniform_int_distribution<> dist(iMin, iMax);	// distribute results inside center rect

	return dist(gen);								// return random # between iMin and iMax
}