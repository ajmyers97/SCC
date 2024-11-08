//Module:	LinkedListClass.cpp
//Project:	CIS023_S2018_HW12
//Author:	Allen Myers
//Date:		May 10th, 2018
//Purpose:	Create a linked list of graphic objects.
//

#include "stdafx.h"
#include "LinkedListClass.h"


LinkedListClass::LinkedListClass()
{
	firstStar = nullptr;
	lastStar = nullptr;
	currentStar = nullptr;
}


LinkedListClass::~LinkedListClass()
{
	while (firstStar != nullptr)
	{
		EllipseClass* tempStar = new EllipseClass;
		tempStar = firstStar;
		firstStar = firstStar->GetNextStar();
		delete tempStar;
	}
}


// add a new star to the end of the list
void LinkedListClass::Add(HWND hWnd)
{
	EllipseClass* newStar = new EllipseClass(hWnd);	// create new Star of type StarClass

	newStar->SetNextStar(nullptr);
	newStar->SetPrevStar(lastStar);

	if (firstStar == nullptr)
		firstStar = newStar;
	else
		lastStar->SetNextStar(newStar);		// old bottom Star points to new Star

	lastStar = newStar;						// append new Star to bottom of list
}

void LinkedListClass::Delete()
{
	EllipseClass* tempStar = new EllipseClass;
	tempStar = currentStar;

	if (currentStar == firstStar)			// special consideration for 1st node
	{
		firstStar = currentStar->GetNextStar();
		firstStar->SetPrevStar(nullptr);
		currentStar = firstStar;

	}
	else if (currentStar == lastStar)		// special consideration for last node
	{
		lastStar = currentStar->GetPrevStar();
		lastStar->SetNextStar(nullptr);
		currentStar = lastStar;
	}
	else									// node in the middle of the list
	{
		currentStar->GetPrevStar()->SetNextStar(currentStar->GetNextStar());
		currentStar->GetNextStar()->SetPrevStar(currentStar->GetPrevStar());

		currentStar = currentStar->GetNextStar();
	}
	delete tempStar;
}

void LinkedListClass::First()
{
	currentStar = firstStar;
}

void LinkedListClass::Next()
{
	currentStar = currentStar->GetNextStar();
}

EllipseClass * LinkedListClass::GetFirstStar()
{
	return firstStar;
}

EllipseClass * LinkedListClass::GetCurrentStar()
{
	return currentStar;
}

void LinkedListClass::SetCurrentStar(EllipseClass * inStar)
{
	currentStar = inStar;
}
