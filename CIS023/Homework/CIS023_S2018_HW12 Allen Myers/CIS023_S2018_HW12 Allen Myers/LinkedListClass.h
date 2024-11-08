//Module:	LinkedListClass.h
//Project:	CIS023_S2018_HW12 ALlen Myers
//Author:	Allen Myers
//Date:		May 10th, 2018
//Purpose:	List of stars.
//
#pragma once
class LinkedListClass
{
public:
	LinkedListClass();
	~LinkedListClass();

	void Add(HWND);						// append a start to the list
	void Delete();						// delete the currentStar
	void First();						// make currentStar the 1st star in the list
	void Next();						// advance currentStar to next star in list

	EllipseClass* GetFirstStar();			//return pointer to first star object
	EllipseClass* GetCurrentStar();		//return pointer to current star
	void SetCurrentStar(EllipseClass*);	//set current star pointer

private:
	EllipseClass* firstStar;				// first node in list
	EllipseClass* lastStar;				// last node in list
	EllipseClass* currentStar;				// current node

};